#include "gpio.h"
#include "config.h"
#include <lgpio.h>

Gpio::Gpio(QObject *parent) : QObject(parent)
{
    m_handle = lgGpiochipOpen(CHIP);
    for (auto& pin : LEDS)
        lgGpioClaimOutput(m_handle, FLAGS, pin, 0); // initial level 0
}

void Gpio::set(int pin, bool state)
{
    lgGpioWrite(m_handle, pin, state);
}
