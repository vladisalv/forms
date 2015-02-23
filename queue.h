#ifndef QUEUE_H
#define QUEUE_H

#include <QWidget>
#include <QTimer>

namespace Ui {
class Queue;
}

class Queue : public QWidget
{
    Q_OBJECT

public:
    explicit Queue(QWidget *parent = 0);
    ~Queue();
    QTimer *timer;


public slots:
    void updateStringSsh(QString strSsh);

private:
    Ui::Queue *ui;


signals:
    void finish();
};

#endif // QUEUE_H
