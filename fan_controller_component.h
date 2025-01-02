#pragma once

#include "esphome.h"

namespace esphome {
namespace fan_controller_component {

class FanController : public Component {
 public:
  FanController(
      esphome::ac_dimmer::AcDimmer *dimmer,
      esphome::dallas_temp::DallasTemperatureSensor *temperature_sensor,
      esphome::sensor::Sensor *fan_speed,
      esphome::text_sensor::TextSensor *fan_speed_level,
      esphome::text_sensor::TextSensor *fan_status)
    : dimmer_(dimmer), temperature_sensor_(temperature_sensor), fan_speed_(fan_speed), fan_speed_level_(fan_speed_level), fan_status_(fan_status) {}

  void set_speed(const std::string &speed_level);
  void update();

 private:
  esphome::ac_dimmer::AcDimmer *dimmer_;
  esphome::dallas_temp::DallasTemperatureSensor *temperature_sensor_;
  esphome::sensor::Sensor *fan_speed_;
  esphome::text_sensor::TextSensor *fan_speed_level_;
  esphome::text_sensor::TextSensor *fan_status_;
};

}  // namespace fan_controller_component
}  // namespace esphome