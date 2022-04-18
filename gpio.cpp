#include "gpio.h"
#include "config.h"
#include <lgpio.h>

Gpio::Gpio(QObject *parent) : QObject(parent)
{
    m_handle = lgGpiochipOpen(CHIP);
    int initial_level = 0;
    for (auto& pin : LEDS)
        lgGpioClaimOutput(m_handle, FLAGS, pin, initial_level);
}

void Gpio::set(int pin, bool state)
{
    lgGpioWrite(m_handle, pin, state);
}
