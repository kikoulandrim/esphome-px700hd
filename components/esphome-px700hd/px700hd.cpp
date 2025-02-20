#pragma once
#include "esphome.h"

namespace esphome {
namespace px700hd {

class px700hdSensor : public Component, public sensor::Sensor {
 public:
  void set_uart(UARTComponent *uart) { this->uart_ = uart; }
  void setup() override;
  void loop() override;

 protected:
  UARTComponent *uart_;
};

}  // namespace px700hd
}  // namespace esphome
