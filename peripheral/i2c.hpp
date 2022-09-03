#ifndef __WWDEVICE_PERIPHERAL_I2C_HPP__
#define __WWDEVICE_PERIPHERAL_I2C_HPP__

#include "peripheral.hpp"
#include "buffer.hpp"

namespace ww::peripheral
{

I2C_PER_DECL

union I2cMasterConfig {
    struct
    {
        uint8_t txDmaThreshold : 8;
        uint8_t rxDmaThreshold : 8;
        uint8_t slaveAddress : 8;
        DataWidth dataWidth : 2;
        bool useTxDma : 1;
        bool useRxDma : 1;
        uint32_t : 4;
    };
    uint32_t value;
};

class I2cMaster : public Initializable
{
  public:
    I2cMaster(I2C_CTOR_ARG);
    ~I2cMaster();
    virtual Result _init();
    virtual void _deinit();
    I2cMasterConfig &config_get();
    Result read(uint32_t address, void *data, uint32_t size, WaitHandler &waitHandler);
    Result write(uint32_t address, void *data, uint32_t size, WaitHandler &waitHandler);
    Result read(void *data, uint32_t size, WaitHandler &waitHandler);
    Result write(void *data, uint32_t size, WaitHandler &waitHandler);

  private:
    I2C_FIELD_DECL
    I2cMasterConfig _config;
    union {
        struct
        {
            bool isReadDmaEnabled : 1;
            bool isWriteDmaEnabled : 1;
        };
        uint32_t value;
    } _status;
    WaitHandler *_waitHandler;
    Buffer _txBuffer;
    Buffer _rxBuffer;
    static void _on_read_complete_callback(I2C_CALLBACK_ARG);
    static void _on_write_complete_callback(I2C_CALLBACK_ARG);
    static void _on_error_callback(I2C_CALLBACK_ARG);
};

}; // namespace ww::peripheral

#endif // __WWDEVICE_PERIPHERAL_I2C_HPP__