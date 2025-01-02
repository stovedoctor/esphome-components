#include "fan_controller_component.h"
#include "esphome/core/log.h"

namespace esphome {
namespace fan_controller_component {

static const char *TAG = "fan_controller_component";

void FanController::set_speed(const std::string &speed_level) {
  ESP_LOGD(TAG, "Setting fan speed to %s", speed_level.c_str());
  if (speed_level == "Off") {
    dimmer_->set_level(0.0);
    fan_status_->publish_state("Off");
    fan_speed_->publish_state(0);
    fan_speed_level_->publish_state("Off");
  } else if (speed_level == "Low") {
    dimmer_->set_level(0.35);
    fan_status_->publish_state("On");
    fan_speed_->publish_state(35);
    fan_speed_level_->publish_state("Low");
  } else if (speed_level == "Medium-Low") {
    dimmer_->set_level(0.4);
    fan_status_->publish_state("On");
    fan_speed_->publish_state(40);
    fan_speed_level_->publish_state("Medium-Low");
  } else if (speed_level == "Medium") {
    dimmer_->set_level(0.5);
    fan_status_->publish_state("On");
    fan_speed_->publish_state(50);
    fan_speed_level_->publish_state("Medium");
  } else if (speed_level == "Medium-High") {
    dimmer_->set_level(0.7);
    fan_status_->publish_state("On");
    fan_speed_->publish_state(70);
    fan_speed_level_->publish_state("Medium-High");
  } else if (speed_level == "High") {
    dimmer_->set_level(1.0);
    fan_status_->publish_state("On");
    fan_speed_->publish_state(100);
    fan_speed_level_->publish_state("High");
  }
}

void FanController::update() {
  float temp = temperature_sensor_->state;
  ESP_LOGD(TAG, "Updating fan speed based on temperature: %.1f", temp);
  if (temp < 35) {
    set_speed("Off");
  } else if (temp >= 35 && temp <= 40) {
    set_speed("Low");
  } else if (temp > 40 && temp <= 45) {
    set_speed("Medium-Low");
  } else if (temp > 45 && temp <= 50) {
    set_speed("Medium");
  } else if (temp > 50 && temp <= 60) {
    set_speed("Medium-High");
  } else if (temp > 60) {
    set_speed("High");
  }
}

}  // namespace fan_controller_component
}  // namespace esphome