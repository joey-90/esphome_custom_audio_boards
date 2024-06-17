import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.const import CONF_ID

esp_korvo_volume_ns = cg.esphome_ns.namespace('esp_korvo_volume')
ESPKorvoVolume = esp_korvo_volume_ns.class_('ESPKorvoVolume', cg.Component)

CONFIG_SCHEMA = cv.Schema({
    cv.GenerateID(): cv.declare_id(ESPKorvoVolume),
}).extend(cv.COMPONENT_SCHEMA)

def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])
    yield cg.register_component(var, config)
