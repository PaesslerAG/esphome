#include "version_text_sensor.h"
#include "esphome/core/log.h"
#include "esphome/core/application.h"

namespace esphome {
namespace version {

static const char *TAG = "version.text_sensor";

void VersionTextSensor::setup() { this->publish_state(ESPHOME_VERSION " " + App.get_compilation_time()); }
float VersionTextSensor::get_setup_priority() const { return setup_priority::DATA; }

std::string VersionTextSensor::unique_id() { return get_mac_address() + "-version"; }
void VersionTextSensor::dump_config() { LOG_TEXT_SENSOR("", "Version Text Sensor", this); }

}  // namespace version
}  // namespace esphome
