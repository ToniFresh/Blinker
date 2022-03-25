#ifndef GPIO_H
#define GPIO_H

#include <QObject>

class Gpio : public QObject
{
    Q_OBJECT
public:
    explicit Gpio(QObject *parent = nullptr);
    void set(int pin, bool state);
signals:

public slots:

private:
    int m_handle;
};

#endif // GPIO_H
