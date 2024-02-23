#ifndef MYODOM_H
#define MYODOM_H
#include <ros/ros.h>
#include <QObject>
#include <QThread>

class myodom : public QObject
{
    Q_OBJECT
public:
    explicit myodom(QObject *parent = nullptr);

signals:

public slots:
};

#endif // MYODOM_H
