#ifndef PROGRAM_H
#define PROGRAM_H

#include <QWidget>

#include "settings.h"

namespace Ui {
class Program;
}

struct Parametrs {
    int index;
    int X, Y, Z;
    int print, step;
    double delta, kappa, cfl;
    QString exeFile, queue, outputFile;
    int numberProc;
};

class Program : public QWidget
{
    Q_OBJECT

public:
    explicit Program(QWidget *parent = 0);
    ~Program();
    Parametrs parametrs;

public slots:
    void quit();

private:
    Ui::Program *ui;

signals:
    void finish();
};

#endif // PROGRAM_H
