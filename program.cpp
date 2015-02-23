#include "program.h"
#include "ui_program.h"

Program::Program(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Program)
{
    ui->setupUi(this);
    ui->spinBoxPrint->setMaximum(9999);
    ui->spinBoxProc->setMaximum(9999);
    ui->spinBoxStep->setMaximum(9999);

    setWindowTitle("Kovcheg");
\
    // load xml file
    parametrs.index = Settings::get(Settings::Index, Settings::Program).toInt();
    parametrs.X = Settings::get(Settings::X, Settings::Program).toInt();
    parametrs.Y = Settings::get(Settings::Y, Settings::Program).toInt();
    parametrs.Z = Settings::get(Settings::Z, Settings::Program).toInt();
    parametrs.print = Settings::get(Settings::Print, Settings::Program).toInt();
    parametrs.step = Settings::get(Settings::Step, Settings::Program).toInt();
    parametrs.delta = Settings::get(Settings::Delta, Settings::Program).toDouble();
    parametrs.kappa = Settings::get(Settings::Kappa, Settings::Program).toDouble();
    parametrs.cfl = Settings::get(Settings::Cfl, Settings::Program).toDouble();
    parametrs.exeFile = Settings::get(Settings::ExeFile, Settings::Program).toString();
    parametrs.queue = Settings::get(Settings::Queue, Settings::Program).toString();
    parametrs.numberProc = Settings::get(Settings::NumberProc, Settings::Program).toInt();
    parametrs.outputFile = Settings::get(Settings::OutputFile, Settings::Program).toString();

    ui->spinBoxIndex->setValue(parametrs.index);
    ui->spinBoxX->setValue(parametrs.X);
    ui->spinBoxY->setValue(parametrs.Y);
    ui->spinBoxZ->setValue(parametrs.Z);
    ui->spinBoxPrint->setValue(parametrs.print);
    ui->spinBoxStep->setValue(parametrs.step);
    ui->doubleSpinBoxDelta->setValue(parametrs.delta);
    ui->doubleSpinBoxKappa->setValue(parametrs.kappa);
    ui->doubleSpinBoxCFL->setValue(parametrs.cfl);
    ui->lineEditExe->insert(parametrs.exeFile);
    ui->lineEditQueue->insert(parametrs.queue);
    ui->spinBoxProc->setValue(parametrs.numberProc);
    ui->lineEditFile->insert(parametrs.outputFile);

    connect(ui->pushButtonRun, SIGNAL(clicked()), SIGNAL(finish()));
    connect(ui->pushButtonRun, SIGNAL(clicked()), SLOT(quit()));
    connect(ui->pushButtonQuit, SIGNAL(clicked()), SLOT(close()));
}

Program::~Program()
{
    delete ui;
}

void Program::quit()
{
    parametrs.index = ui->spinBoxIndex->value();
    parametrs.X = ui->spinBoxX->value();
    parametrs.Y = ui->spinBoxY->value();
    parametrs.Z = ui->spinBoxZ->value();
    parametrs.print = ui->spinBoxPrint->value();
    parametrs.step = ui->spinBoxStep->value();
    parametrs.delta = ui->doubleSpinBoxDelta->value();
    parametrs.kappa = ui->doubleSpinBoxKappa->value();
    parametrs.cfl = ui->doubleSpinBoxCFL->value();
    parametrs.exeFile = ui->lineEditExe->text();
    parametrs.queue = ui->lineEditQueue->text();
    parametrs.numberProc = ui->spinBoxProc->value();
    parametrs.outputFile = ui->lineEditFile->text();

    Settings::set(Settings::Index, Settings::Program)      = parametrs.index;
    Settings::set(Settings::X, Settings::Program)          = parametrs.X;
    Settings::set(Settings::Y, Settings::Program)          = parametrs.Y;
    Settings::set(Settings::Z, Settings::Program)          = parametrs.Z;
    Settings::set(Settings::Print, Settings::Program)      = parametrs.print;
    Settings::set(Settings::Step, Settings::Program)       = parametrs.step;
    Settings::set(Settings::Delta, Settings::Program)      = parametrs.delta;
    Settings::set(Settings::Kappa, Settings::Program)      = parametrs.kappa;
    Settings::set(Settings::Cfl, Settings::Program)        = parametrs.cfl;
    Settings::set(Settings::ExeFile, Settings::Program)    = parametrs.exeFile;
    Settings::set(Settings::Queue, Settings::Program)      = parametrs.queue;
    Settings::set(Settings::NumberProc, Settings::Program) = parametrs.numberProc;
    Settings::set(Settings::OutputFile, Settings::Program) = parametrs.outputFile;

    hide();
}
