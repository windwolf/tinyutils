#include "misc.hpp"
#include "stm32h7xx_hal.h"
namespace ww::peripheral
{
void Misc::us_delay(uint32_t us)
{
    volatile uint32_t remain = us << 1;
    if (us < 1000)
    {
        while (remain--)
        {
            __NOP();
        }
    }
    else
    {
        ms_delay(us / 1000);
        remain = (us % 1000) << 1;
        while (remain--)
        {
            __NOP();
        }
    }
}
void Misc::ms_delay(uint32_t ms)
{
    HAL_Delay(ms);
}

uint32_t Misc::get_tick()
{
    return HAL_GetTick();
};
} // namespace ww::peripheral