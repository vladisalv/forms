#include "connecting.h"
#include "ui_connecting.h"

Connecting::Connecting(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Connecting)
{
    ui->setupUi(this);

    setWindowTitle("Connect");

    // load from xml file name
    //CXml xml("a.xml");
    //machineList = xml.getList();
    //int firstElem = xml.getIndexFirstElem();
    //machine = machineList.at(firstElem);

    // foreach add Item from machineList
    //ui->comboBox->addItem(machine.name);
    //ui->comboBox->setEditable(true);

    machine.login = Settings::get(Settings::Login, Settings::Connecting).toString();
    machine.server = Settings::get(Settings::Server, Settings::Connecting).toString();
    machine.privateKey = Settings::get(Settings::PrivateKey, Settings::Connecting).toString();
    machine.publicKey = Settings::get(Settings::PublicKey, Settings::Connecting).toString();

    ui->lineEditLogin->insert(machine.login);
    ui->lineEditServer->insert(machine.server);
    ui->lineEditPrivateKey->insert(machine.privateKey);
    ui->lineEditPublicKey->insert(machine.publicKey);

    connect(ui->pushButtonConnect, SIGNAL(clicked()), SIGNAL(finish()));
    connect(ui->pushButtonConnect, SIGNAL(clicked()), SLOT(quit()));
    connect(ui->pushButtonQuit, SIGNAL(clicked()), SLOT(close()));
    connect(ui->pushButtonPrivateKey, SIGNAL(clicked()), SLOT(openPrivateKeyFile()));
    connect(ui->pushButtonPublicKey, SIGNAL(clicked()), SLOT(openPublicKeyFile()));
}

Connecting::~Connecting()
{
    delete ui;
}

void Connecting::quit()
{
    machine.login  = ui->lineEditLogin->text();
    machine.server = ui->lineEditServer->text();
    machine.privateKey    = ui->lineEditPrivateKey->text();
    machine.publicKey    = ui->lineEditPublicKey->text();

    Settings::set(Settings::Login, Settings::Connecting) = machine.login;
    Settings::set(Settings::Server, Settings::Connecting) = machine.server;
    Settings::set(Settings::PrivateKey, Settings::Connecting) = machine.privateKey;
    Settings::set(Settings::PublicKey, Settings::Connecting) = machine.publicKey;

    close();
}

void Connecting::openPrivateKeyFile()
{
    ui->lineEditPrivateKey->insert(QFileDialog::getOpenFileName(this, "Choose private key", ""));
    ui->lineEditPublicKey->insert(ui->lineEditPrivateKey->text() + ".pub");
}

void Connecting::openPublicKeyFile()
{
    ui->lineEditPublicKey->insert(QFileDialog::getOpenFileName(this, "Choose public key", ""));
}
