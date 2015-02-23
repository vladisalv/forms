#include "queue.h"
#include "ui_queue.h"

#include <QDebug>

Queue::Queue(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Queue)
{
    ui->setupUi(this);

    setWindowTitle("Queue");
    ui->labelQueue->setText("fbab");

    timer = new QTimer;

    connect(ui->pushButtonBack, SIGNAL(clicked()), SIGNAL(finish()));
    connect(ui->pushButtonBack, SIGNAL(clicked()), SLOT(hide()));
    connect(ui->pushButtonBack, SIGNAL(clicked()), timer, SLOT(stop()));

    connect(ui->pushButtonQuit, SIGNAL(clicked()), SLOT(close()));
}

Queue::~Queue()
{
    delete ui;
}

void Queue::updateStringSsh(QString strSsh)
{
    qDebug() << "call updateStringSsh";
    ui->labelQueue->setText(strSsh);
    timer->start(3000);
}
