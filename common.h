#ifndef COMMON_H
#define COMMON_H

#include <QWidget>
#include <QString>
#include <QDebug>

#include "connecting.h"
#include "program.h"
#include "queue.h"

char *ssh(const char *username, const char *server, const char *private_key,
          const char *public_key, const char *commandline);
extern char *buffer_ssh;

class Common : public QWidget
{
    Q_OBJECT

public:
    Common(QWidget *parent = 0);
    ~Common();
    void work();


signals:
    void stringReady(QString strSsh);

private:
    Connecting *connecting;
    Program *program;
    Queue *queue;

    QString login, server, privateKey, publicKey;
    char *ssh_command(QString login, QString server, QString privateKey, QString publicKey, QString command);

public slots:
    char *getSshName();
    char *runSshCommand();
    char *getSshString();
};

#endif // COMMON_H
