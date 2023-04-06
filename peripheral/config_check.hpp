//
// Created by zhouj on 2022/12/12.
//

#ifndef WWMOTOR_LIBS_WWBASE_PERIPHERAL_CONFIG_CHECK_HPP_
#define WWMOTOR_LIBS_WWBASE_PERIPHERAL_CONFIG_CHECK_HPP_

#if !(PERIPHERAL_I2C_WRITE_IT_ENABLED ^ PERIPHERAL_I2C_WRITE_DMA_ENABLED)
#error "PERIPHERAL_I2C_WRITE_IT_ENABLED PERIPHERAL_I2C_WRITE_DMA_ENABLED 此二者有且仅能启用一个"
#endif

#if !(PERIPHERAL_I2C_READ_IT_ENABLED ^ PERIPHERAL_I2C_READ_DMA_ENABLED)
#error "PERIPHERAL_I2C_READ_IT_ENABLED PERIPHERAL_I2C_READ_DMA_ENABLED 此二者有且仅能启用一个"
#endif

#if !(PERIPHERAL_SPI_WRITE_IT_ENABLED ^ PERIPHERAL_SPI_WRITE_DMA_ENABLED)
#error "PERIPHERAL_SPI_WRITE_IT_ENABLED PERIPHERAL_SPI_WRITE_DMA_ENABLED 此二者有且仅能启用一个"
#endif

#if !(PERIPHERAL_SPI_READ_IT_ENABLED ^ PERIPHERAL_SPI_READ_DMA_ENABLED)
#error "PERIPHERAL_SPI_READ_IT_ENABLED PERIPHERAL_SPI_READ_DMA_ENABLED 此二者有且仅能启用一个"
#endif

#if !(PERIPHERAL_UART_WRITE_IT_ENABLED ^ PERIPHERAL_UART_WRITE_DMA_ENABLED)
#error "PERIPHERAL_UART_WRITE_IT_ENABLED PERIPHERAL_UART_WRITE_DMA_ENABLED 此二者有且仅能启用一个"
#endif

#if !(PERIPHERAL_UART_READ_IT_ENABLED ^ PERIPHERAL_UART_READ_DMA_ENABLED)
#error "PERIPHERAL_UART_READ_IT_ENABLED PERIPHERAL_UART_READ_DMA_ENABLED 此二者有且仅能启用一个"
#endif

#endif  // WWMOTOR_LIBS_WWBASE_PERIPHERAL_CONFIG_CHECK_HPP_
