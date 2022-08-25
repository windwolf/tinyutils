#include "pin.hpp"
#include "stm32f1xx_ll_gpio.h"

namespace ww::peripheral
{
PinConfig &Pin::config_get()
{
    return _config;
};
Result Pin::init()
{
    return Result_OK;
};
Result Pin::deinit()
{
    return Result_OK;
};

Result Pin::read(Status &value)
{
    Status rst;
    rst = (Status)HAL_GPIO_ReadPin(&_port, this->_pinMask);
    value = (Status)(rst ^ this->_config.inverse);
    return Result_OK;
};

Result Pin::write(Status value)
{
    HAL_GPIO_WritePin(&_port, this->_pinMask,
                      (GPIO_PinState)(value ^ this->_config.inverse));
    return Result_OK;
};

Result Pin::toggle()
{
    HAL_GPIO_TogglePin(&_port, this->_pinMask);
    return Result_OK;
};

Result Pin::mode_set(Mode mode)
{
    LL_GPIO_SetPinMode(&_port, this->_pinMask,
                       (mode == MODE_INPUT) ? LL_GPIO_MODE_INPUT
                                            : LL_GPIO_MODE_OUTPUT);
    return Result_OK;
};
} // namespace ww::peripheral