#ifndef CONNECTING_H
#define CONNECTING_H

#include <QWidget>
#include <QString>
#include <QFileDialog>
#include <QtXml>

#include "xml.h"
#include "settings.h"

namespace Ui {
class Connecting;
}

class Connecting : public QWidget
{
    Q_OBJECT

public:
    explicit Connecting(QWidget *parent = 0);
    ~Connecting();
    Machine machine;

private:
    Ui::Connecting *ui;
    MachineList machineList;

signals:
    void finish();

public slots:
    void quit();
    void openPrivateKeyFile();
    void openPublicKeyFile();
};

#endif // CONNECTING_H
