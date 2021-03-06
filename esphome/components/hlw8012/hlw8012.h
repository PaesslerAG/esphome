#pragma once

#include "esphome/core/component.h"
#include "esphome/core/esphal.h"
#include "esphome/components/sensor/sensor.h"
#include "esphome/components/pulse_width/pulse_width.h"

namespace esphome {
namespace hlw8012 {

class HLW8012Component : public PollingComponent {
 public:
  void setup() override;
  void dump_config() override;
  float get_setup_priority() const override;
  void update() override;

  void set_change_mode_every(uint32_t change_mode_every) { change_mode_every_ = change_mode_every; }
  void set_current_resistor(float current_resistor) { current_resistor_ = current_resistor; }
  void set_voltage_divider(float voltage_divider) { voltage_divider_ = voltage_divider; }
  void set_sel_pin(GPIOPin *sel_pin) { sel_pin_ = sel_pin; }
  void set_cf_pin(GPIOPin *cf_pin) { cf_pin_ = cf_pin; }
  void set_cf1_pin(GPIOPin *cf1_pin) { cf1_pin_ = cf1_pin; }
  void set_voltage_sensor(sensor::Sensor *voltage_sensor) { voltage_sensor_ = voltage_sensor; }
  void set_current_sensor(sensor::Sensor *current_sensor) { current_sensor_ = current_sensor; }
  void set_power_sensor(sensor::Sensor *power_sensor) { power_sensor_ = power_sensor; }

 protected:
  uint32_t nth_value_{0};
  bool current_mode_{false};
  uint32_t change_mode_at_{0};
  uint32_t change_mode_every_{8};
  float current_resistor_{0.001};
  float voltage_divider_{2351};
  GPIOPin *sel_pin_;
  GPIOPin *cf_pin_;
  pulse_width::PulseWidthSensorStore cf_store_;
  GPIOPin *cf1_pin_;
  pulse_width::PulseWidthSensorStore cf1_store_;
  sensor::Sensor *voltage_sensor_{nullptr};
  sensor::Sensor *current_sensor_{nullptr};
  sensor::Sensor *power_sensor_{nullptr};
};

}  // namespace hlw8012
}  // namespace esphome
