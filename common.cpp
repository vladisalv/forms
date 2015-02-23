#include "common.h"

QString MODULEPATH="export MODULEPATH=/usr/share/Modules/modulefiles:/etc/modulefiles:/opt/modulefiles:/opt/ccoe/modulefiles;";
QString LD_LIBRARY_PATH="export LD_LIBRARY_PATH=/opt/slurm/2.5.6/lib:/mnt/data/users/dm4/vol12/vladisalv_251923/usr/lib:/opt/intel/composer_xe_2013.2.146/compiler/lib/intel64:/mnt/data/users/dm4/vol12/vladisalv_251923/usr/lib:/opt/mpi/openmpi-1.5.5-icc/lib:/mnt/data/users/dm4/vol12/vladisalv_251923/usr/lib:;";
QString LOADEDMODULES="export LOADEDMODULES=slurm/2.5.6:intel/13.1.0:openmpi/1.5.5-icc;";
QString MANPATH="export MANPATH=/opt/slurm/2.5.6/share/man:/usr/share/man:/opt/mpi/openmpi-1.5.5-icc/share/man:/usr/share/man:;";
QString PATH="export PATH=/opt/software/wrappers:/opt/slurm/2.5.6/bin:/mnt/data/users/dm4/vol12/vladisalv_251923/bin:/mnt/data/users/dm4/vol12/vladisalv_251923/usr/bin:/mnt/data/users/dm4/vol12/vladisalv_251923/usr/lib:/usr/lib64/qt-3.3/bin:/usr/local/bin:/bin:/usr/bin:/usr/local/sbin:/usr/sbin:/sbin:/mnt/data/users/dm4/vol12/vladisalv_251923/bin:/opt/intel/composer_xe_2013.2.146/bin/intel64:/mnt/data/users/dm4/vol12/vladisalv_251923/bin:/mnt/data/users/dm4/vol12/vladisalv_251923/usr/bin:/mnt/data/users/dm4/vol12/vladisalv_251923/usr/lib:/usr/lib64/qt-3.3/bin:/usr/local/bin:/bin:/usr/bin:/usr/local/sbin:/usr/sbin:/sbin:/mnt/data/users/dm4/vol12/vladisalv_251923/bin:/opt/mpi/openmpi-1.5.5-icc/bin/:/mnt/data/users/dm4/vol12/vladisalv_251923/bin:/mnt/data/users/dm4/vol12/vladisalv_251923/usr/bin:/mnt/data/users/dm4/vol12/vladisalv_251923/usr/lib:/usr/lib64/qt-3.3/bin:/usr/local/bin:/bin:/usr/bin:/usr/local/sbin:/usr/sbin:/sbin:/mnt/data/users/dm4/vol12/vladisalv_251923/bin;";
QString _LMFILES_="export _LMFILES_=/opt/modulefiles/slurm/2.5.6:/opt/modulefiles/intel/13.1.0:/opt/modulefiles/openmpi/1.5.5-icc;";
QString LIBRARY_PATH="export LIBRARY_PATH=/opt/intel/composer_xe_2013.2.146/compiler/lib/intel64;";
QString MANTPAH="export MANTPAH=/opt/intel/composer_xe_2013.2.146/man/en_US;";
QString OTHER="export INTEL_LICENSE_FILE=/opt/intel/licenses;export I_MPI_CC=icc;export I_MPI_CXX=icpc;export I_MPI_F77=ifort;export I_MPI_F90=ifort;";

QString EXPORT = MODULEPATH + LD_LIBRARY_PATH + LOADEDMODULES + MANPATH + PATH + _LMFILES_ + LIBRARY_PATH + MANTPAH + OTHER;

Common::Common(QWidget *parent)
    : QWidget(parent)
{
    connecting = new Connecting;
    program = new Program;
    queue = new Queue;
    connect(connecting, SIGNAL(finish()), program, SLOT(show()));
    connect(connecting, SIGNAL(finish()), SLOT(getSshName()));

    connect(program, SIGNAL(finish()), SLOT(runSshCommand()));
    connect(program, SIGNAL(finish()), queue, SLOT(show()));
    connect(program, SIGNAL(finish()), queue->timer, SLOT(start()));
    connect(program, SIGNAL(finish()), this, SLOT(getSshString()));


    connect(queue, SIGNAL(finish()), program, SLOT(show()));
    connect(queue->timer, SIGNAL(timeout()), this, SLOT(getSshString()));
    connect(this, SIGNAL(stringReady(QString)), queue, SLOT(updateStringSsh(QString)));
}

Common::~Common()
{

}

void Common::work()
{
    connecting->show();
}

char *Common::getSshName()
{
    login = connecting->machine.login;
    server = connecting->machine.server;
    privateKey = connecting->machine.privateKey;
    publicKey  = connecting->machine.publicKey;

    QString command = "echo HELLO!";
    return ssh_command(login, server, privateKey, publicKey, command);
}

char *Common::runSshCommand()
{
    QString path = program->parametrs.exeFile;
    QString sbatch = "sbatch -n " + QString::number(program->parametrs.numberProc) + " -p " + program->parametrs.queue + " -o " + program->parametrs.outputFile + " ompi " + path;
    QString argv = " --index-geometry " + QString::number(program->parametrs.index) + " -x " + QString::number(program->parametrs.X) + " -y " + QString::number(program->parametrs.Y) + " -z " + QString::number(program->parametrs.Z);
    argv += " --interval-print " + QString::number(program->parametrs.print) + " --number-steps " + QString::number(program->parametrs.step) + " --delta " + QString::number(program->parametrs.delta) + " --kappa " + QString::number(program->parametrs.kappa) + " --cfl " + QString::number(program->parametrs.cfl);
    QString command = EXPORT + sbatch + argv;
    return ssh_command(login, server, privateKey, publicKey, command);
}

char *Common::getSshString()
{
    qDebug() << "call getSshString";
    QString command = EXPORT + "squeue -u \$USER;";
    char *result = ssh_command(login, server, privateKey, publicKey, command);
    emit stringReady(result);
    return result;
}

char *Common::ssh_command(QString login, QString server, QString privateKey, QString publicKey, QString command)
{
    QByteArray array1 = login.toUtf8();
    const char *login_buf = array1.data();
    QByteArray array2 = server.toUtf8();
    const char *server_buf = array2.data();
    QByteArray array3 = privateKey.toUtf8();
    const char *privateKeyBuf = array3.data();
    QByteArray array4 = publicKey.toUtf8();
    const char *publicKeyBuf = array4.data();
    QByteArray array5 = command.toUtf8();
    const char *command_buf = array5.data();

    return ssh(login_buf, server_buf, privateKeyBuf, publicKeyBuf, command_buf);
}
