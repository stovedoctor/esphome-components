import esphome.codegen as cg
from esphome.components import sensor, text_sensor, output
from esphome.const import CONF_ID

fan_controller_ns = cg.esphome_ns.namespace('fan_controller_component')
FanController = fan_controller_ns.class_('FanController', cg.Component)

CONFIG_SCHEMA = cg.ComponentSchema(
    FanController
).extend({
    cg.Required(CONF_ID): cg.use_id(FanController),
}).extend(output.OUTPUT_SCHEMA).extend(sensor.SENSOR_SCHEMA).extend(text_sensor.TEXT_SENSOR_SCHEMA)

async def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])
    await cg.register_component(var, config)
    await output.register_output(var, config)
    await sensor.register_sensor(var, config)
    await text_sensor.register_text_sensor(var, config)
