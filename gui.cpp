#include "gui.h"
#include <QDebug>
#include "config.h"

Gui::Gui(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);
    m_state = 0;
    m_timer = new QTimer(this);
    m_gpio = new Gpio(this);
    connect(m_timer, &QTimer::timeout, this, &Gui::toggle);
}

void Gui::on_startButton_clicked()
{
    int time = 1000 / horizontalSlider->value();
    m_timer->start(time);
}

void Gui::on_horizontalSlider_valueChanged(int value)
{
    int time = 1000 / value; //T = 1 / f
    m_timer->setInterval(time);
}

void Gui::toggle()
{
    m_state = !m_state;
    blinklabel->setNum(m_state);
    m_gpio->set(LEDS[0], m_state);
}
