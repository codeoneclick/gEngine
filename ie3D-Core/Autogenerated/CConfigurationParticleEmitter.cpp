// autogenerated: do not add any changes
#include "CConfigurationParticleEmitter.h"
ui32 CConfigurationParticleEmitter::getNumParticles(void) const
{
const auto& iterator = m_attributes.find("/particle_emitter/num_particles");
assert(iterator != m_attributes.end());
ui32 value; iterator->second->get(&value);
return value;
}
ui32 CConfigurationParticleEmitter::getDuration(void) const
{
const auto& iterator = m_attributes.find("/particle_emitter/duration");
assert(iterator != m_attributes.end());
ui32 value; iterator->second->get(&value);
return value;
}
f32 CConfigurationParticleEmitter::getDurationRandomess(void) const
{
const auto& iterator = m_attributes.find("/particle_emitter/duration_randomness");
assert(iterator != m_attributes.end());
f32 value; iterator->second->get(&value);
return value;
}
f32 CConfigurationParticleEmitter::getVelocitySensitivity(void) const
{
const auto& iterator = m_attributes.find("/particle_emitter/velocity_sensitivity");
assert(iterator != m_attributes.end());
f32 value; iterator->second->get(&value);
return value;
}
f32 CConfigurationParticleEmitter::getMinHorizontalVelocity(void) const
{
const auto& iterator = m_attributes.find("/particle_emitter/min_horizontal_velocity");
assert(iterator != m_attributes.end());
f32 value; iterator->second->get(&value);
return value;
}
f32 CConfigurationParticleEmitter::getMaxHorizontalVelocity(void) const
{
const auto& iterator = m_attributes.find("/particle_emitter/max_horizontal_velocity");
assert(iterator != m_attributes.end());
f32 value; iterator->second->get(&value);
return value;
}
f32 CConfigurationParticleEmitter::getMinVerticalVelocity(void) const
{
const auto& iterator = m_attributes.find("/particle_emitter/min_vertical_velocity");
assert(iterator != m_attributes.end());
f32 value; iterator->second->get(&value);
return value;
}
f32 CConfigurationParticleEmitter::getMaxVerticalVelocity(void) const
{
const auto& iterator = m_attributes.find("/particle_emitter/max_vertical_velocity");
assert(iterator != m_attributes.end());
f32 value; iterator->second->get(&value);
return value;
}
f32 CConfigurationParticleEmitter::getEndVelocity(void) const
{
const auto& iterator = m_attributes.find("/particle_emitter/end_velocity");
assert(iterator != m_attributes.end());
f32 value; iterator->second->get(&value);
return value;
}
f32 CConfigurationParticleEmitter::getGravityX(void) const
{
const auto& iterator = m_attributes.find("/particle_emitter/gravity_x");
assert(iterator != m_attributes.end());
f32 value; iterator->second->get(&value);
return value;
}
f32 CConfigurationParticleEmitter::getGravityY(void) const
{
const auto& iterator = m_attributes.find("/particle_emitter/gravity_y");
assert(iterator != m_attributes.end());
f32 value; iterator->second->get(&value);
return value;
}
f32 CConfigurationParticleEmitter::getGravityZ(void) const
{
const auto& iterator = m_attributes.find("/particle_emitter/gravity_z");
assert(iterator != m_attributes.end());
f32 value; iterator->second->get(&value);
return value;
}
ui8 CConfigurationParticleEmitter::getSourceColorR(void) const
{
const auto& iterator = m_attributes.find("/particle_emitter/source_color_r");
assert(iterator != m_attributes.end());
ui8 value; iterator->second->get(&value);
return value;
}
ui8 CConfigurationParticleEmitter::getSourceColorG(void) const
{
const auto& iterator = m_attributes.find("/particle_emitter/source_color_g");
assert(iterator != m_attributes.end());
ui8 value; iterator->second->get(&value);
return value;
}
ui8 CConfigurationParticleEmitter::getSourceColorB(void) const
{
const auto& iterator = m_attributes.find("/particle_emitter/source_color_b");
assert(iterator != m_attributes.end());
ui8 value; iterator->second->get(&value);
return value;
}
ui8 CConfigurationParticleEmitter::getSourceColorA(void) const
{
const auto& iterator = m_attributes.find("/particle_emitter/source_color_a");
assert(iterator != m_attributes.end());
ui8 value; iterator->second->get(&value);
return value;
}
ui8 CConfigurationParticleEmitter::getDestinationColorR(void) const
{
const auto& iterator = m_attributes.find("/particle_emitter/destination_color_r");
assert(iterator != m_attributes.end());
ui8 value; iterator->second->get(&value);
return value;
}
ui8 CConfigurationParticleEmitter::getDestinationColorG(void) const
{
const auto& iterator = m_attributes.find("/particle_emitter/destination_color_g");
assert(iterator != m_attributes.end());
ui8 value; iterator->second->get(&value);
return value;
}
ui8 CConfigurationParticleEmitter::getDestinationColorB(void) const
{
const auto& iterator = m_attributes.find("/particle_emitter/destination_color_b");
assert(iterator != m_attributes.end());
ui8 value; iterator->second->get(&value);
return value;
}
ui8 CConfigurationParticleEmitter::getDestinationColorA(void) const
{
const auto& iterator = m_attributes.find("/particle_emitter/destination_color_a");
assert(iterator != m_attributes.end());
ui8 value; iterator->second->get(&value);
return value;
}
f32 CConfigurationParticleEmitter::getSourceSizeX(void) const
{
const auto& iterator = m_attributes.find("/particle_emitter/source_size_x");
assert(iterator != m_attributes.end());
f32 value; iterator->second->get(&value);
return value;
}
f32 CConfigurationParticleEmitter::getSourceSizeY(void) const
{
const auto& iterator = m_attributes.find("/particle_emitter/source_size_y");
assert(iterator != m_attributes.end());
f32 value; iterator->second->get(&value);
return value;
}
f32 CConfigurationParticleEmitter::getDestinationSizeX(void) const
{
const auto& iterator = m_attributes.find("/particle_emitter/destination_size_x");
assert(iterator != m_attributes.end());
f32 value; iterator->second->get(&value);
return value;
}
f32 CConfigurationParticleEmitter::getDestinationSizeY(void) const
{
const auto& iterator = m_attributes.find("/particle_emitter/destination_size_y");
assert(iterator != m_attributes.end());
f32 value; iterator->second->get(&value);
return value;
}
ui32 CConfigurationParticleEmitter::getMinEmittInterval(void) const
{
const auto& iterator = m_attributes.find("/particle_emitter/min_emitt_interval");
assert(iterator != m_attributes.end());
ui32 value; iterator->second->get(&value);
return value;
}
ui32 CConfigurationParticleEmitter::getMaxEmittInterval(void) const
{
const auto& iterator = m_attributes.find("/particle_emitter/max_emitt_interval");
assert(iterator != m_attributes.end());
ui32 value; iterator->second->get(&value);
return value;
}
std::vector<std::shared_ptr<IConfiguration>> CConfigurationParticleEmitter::getMaterialsConfigurations(void) const
{
const auto& iterator = m_configurations.find("/particle_emitter/materials/material");
if(iterator == m_configurations.end())
{
return std::vector<std::shared_ptr<IConfiguration>>();
}
assert(iterator != m_configurations.end());
return iterator->second;
}
void CConfigurationParticleEmitter::serialize(const std::string& filename)
{
pugi::xml_document document;
pugi::xml_parse_result result = IConfiguration::openXMLDocument(document, filename);
assert(result.status == pugi::status_ok);
pugi::xpath_node node;
node = document.select_single_node("/particle_emitter");
ui32 num_particles = node.node().attribute("num_particles").as_uint();
IConfiguration::setAttribute("/particle_emitter/num_particles", std::make_shared<CConfigurationAttribute>(num_particles));
ui32 duration = node.node().attribute("duration").as_uint();
IConfiguration::setAttribute("/particle_emitter/duration", std::make_shared<CConfigurationAttribute>(duration));
f32 duration_randomness = node.node().attribute("duration_randomness").as_float();
IConfiguration::setAttribute("/particle_emitter/duration_randomness", std::make_shared<CConfigurationAttribute>(duration_randomness));
f32 velocity_sensitivity = node.node().attribute("velocity_sensitivity").as_float();
IConfiguration::setAttribute("/particle_emitter/velocity_sensitivity", std::make_shared<CConfigurationAttribute>(velocity_sensitivity));
f32 min_horizontal_velocity = node.node().attribute("min_horizontal_velocity").as_float();
IConfiguration::setAttribute("/particle_emitter/min_horizontal_velocity", std::make_shared<CConfigurationAttribute>(min_horizontal_velocity));
f32 max_horizontal_velocity = node.node().attribute("max_horizontal_velocity").as_float();
IConfiguration::setAttribute("/particle_emitter/max_horizontal_velocity", std::make_shared<CConfigurationAttribute>(max_horizontal_velocity));
f32 min_vertical_velocity = node.node().attribute("min_vertical_velocity").as_float();
IConfiguration::setAttribute("/particle_emitter/min_vertical_velocity", std::make_shared<CConfigurationAttribute>(min_vertical_velocity));
f32 max_vertical_velocity = node.node().attribute("max_vertical_velocity").as_float();
IConfiguration::setAttribute("/particle_emitter/max_vertical_velocity", std::make_shared<CConfigurationAttribute>(max_vertical_velocity));
f32 end_velocity = node.node().attribute("end_velocity").as_float();
IConfiguration::setAttribute("/particle_emitter/end_velocity", std::make_shared<CConfigurationAttribute>(end_velocity));
f32 gravity_x = node.node().attribute("gravity_x").as_float();
IConfiguration::setAttribute("/particle_emitter/gravity_x", std::make_shared<CConfigurationAttribute>(gravity_x));
f32 gravity_y = node.node().attribute("gravity_y").as_float();
IConfiguration::setAttribute("/particle_emitter/gravity_y", std::make_shared<CConfigurationAttribute>(gravity_y));
f32 gravity_z = node.node().attribute("gravity_z").as_float();
IConfiguration::setAttribute("/particle_emitter/gravity_z", std::make_shared<CConfigurationAttribute>(gravity_z));
ui8 source_color_r = node.node().attribute("source_color_r").as_uint();
IConfiguration::setAttribute("/particle_emitter/source_color_r", std::make_shared<CConfigurationAttribute>(source_color_r));
ui8 source_color_g = node.node().attribute("source_color_g").as_uint();
IConfiguration::setAttribute("/particle_emitter/source_color_g", std::make_shared<CConfigurationAttribute>(source_color_g));
ui8 source_color_b = node.node().attribute("source_color_b").as_uint();
IConfiguration::setAttribute("/particle_emitter/source_color_b", std::make_shared<CConfigurationAttribute>(source_color_b));
ui8 source_color_a = node.node().attribute("source_color_a").as_uint();
IConfiguration::setAttribute("/particle_emitter/source_color_a", std::make_shared<CConfigurationAttribute>(source_color_a));
ui8 destination_color_r = node.node().attribute("destination_color_r").as_uint();
IConfiguration::setAttribute("/particle_emitter/destination_color_r", std::make_shared<CConfigurationAttribute>(destination_color_r));
ui8 destination_color_g = node.node().attribute("destination_color_g").as_uint();
IConfiguration::setAttribute("/particle_emitter/destination_color_g", std::make_shared<CConfigurationAttribute>(destination_color_g));
ui8 destination_color_b = node.node().attribute("destination_color_b").as_uint();
IConfiguration::setAttribute("/particle_emitter/destination_color_b", std::make_shared<CConfigurationAttribute>(destination_color_b));
ui8 destination_color_a = node.node().attribute("destination_color_a").as_uint();
IConfiguration::setAttribute("/particle_emitter/destination_color_a", std::make_shared<CConfigurationAttribute>(destination_color_a));
f32 source_size_x = node.node().attribute("source_size_x").as_float();
IConfiguration::setAttribute("/particle_emitter/source_size_x", std::make_shared<CConfigurationAttribute>(source_size_x));
f32 source_size_y = node.node().attribute("source_size_y").as_float();
IConfiguration::setAttribute("/particle_emitter/source_size_y", std::make_shared<CConfigurationAttribute>(source_size_y));
f32 destination_size_x = node.node().attribute("destination_size_x").as_float();
IConfiguration::setAttribute("/particle_emitter/destination_size_x", std::make_shared<CConfigurationAttribute>(destination_size_x));
f32 destination_size_y = node.node().attribute("destination_size_y").as_float();
IConfiguration::setAttribute("/particle_emitter/destination_size_y", std::make_shared<CConfigurationAttribute>(destination_size_y));
ui32 min_emitt_interval = node.node().attribute("min_emitt_interval").as_uint();
IConfiguration::setAttribute("/particle_emitter/min_emitt_interval", std::make_shared<CConfigurationAttribute>(min_emitt_interval));
ui32 max_emitt_interval = node.node().attribute("max_emitt_interval").as_uint();
IConfiguration::setAttribute("/particle_emitter/max_emitt_interval", std::make_shared<CConfigurationAttribute>(max_emitt_interval));
pugi::xpath_node_set material_nodes = document.select_nodes("/particle_emitter/materials/material");
for (pugi::xpath_node_set::const_iterator iterator = material_nodes.begin(); iterator != material_nodes.end(); ++iterator)
{
std::shared_ptr<CConfigurationMaterial> material = std::make_shared<CConfigurationMaterial>();
material->serialize((*iterator).node().attribute("filename").as_string());
IConfiguration::setConfiguration("/particle_emitter/materials/material", material);
}
}
