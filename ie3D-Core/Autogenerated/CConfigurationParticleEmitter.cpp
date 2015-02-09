// autogenerated: do not add any changes
#include "CConfigurationParticleEmitter.h"
ui32 CConfigurationParticleEmitter::getNumParticles(void) const
{
const auto& iterator = m_attributes.find("/particle_emitter/num_particles");
assert(iterator != m_attributes.end());
ui32 value; iterator->second->get(&value);
return value;
}
#if defined(__EDITOR__)
void CConfigurationParticleEmitter::setNumParticles(ui32 num_particles)
{
IConfiguration::setAttribute("/particle_emitter/num_particles", std::make_shared<CConfigurationAttribute>(num_particles));
}
#endif
ui32 CConfigurationParticleEmitter::getDuration(void) const
{
const auto& iterator = m_attributes.find("/particle_emitter/duration");
assert(iterator != m_attributes.end());
ui32 value; iterator->second->get(&value);
return value;
}
#if defined(__EDITOR__)
void CConfigurationParticleEmitter::setDuration(ui32 duration)
{
IConfiguration::setAttribute("/particle_emitter/duration", std::make_shared<CConfigurationAttribute>(duration));
}
#endif
f32 CConfigurationParticleEmitter::getDurationRandomess(void) const
{
const auto& iterator = m_attributes.find("/particle_emitter/duration_randomness");
assert(iterator != m_attributes.end());
f32 value; iterator->second->get(&value);
return value;
}
#if defined(__EDITOR__)
void CConfigurationParticleEmitter::setDurationRandomess(f32 duration_randomness)
{
IConfiguration::setAttribute("/particle_emitter/duration_randomness", std::make_shared<CConfigurationAttribute>(duration_randomness));
}
#endif
f32 CConfigurationParticleEmitter::getVelocitySensitivity(void) const
{
const auto& iterator = m_attributes.find("/particle_emitter/velocity_sensitivity");
assert(iterator != m_attributes.end());
f32 value; iterator->second->get(&value);
return value;
}
#if defined(__EDITOR__)
void CConfigurationParticleEmitter::setVelocitySensitivity(f32 velocity_sensitivity)
{
IConfiguration::setAttribute("/particle_emitter/velocity_sensitivity", std::make_shared<CConfigurationAttribute>(velocity_sensitivity));
}
#endif
f32 CConfigurationParticleEmitter::getMinHorizontalVelocity(void) const
{
const auto& iterator = m_attributes.find("/particle_emitter/min_horizontal_velocity");
assert(iterator != m_attributes.end());
f32 value; iterator->second->get(&value);
return value;
}
#if defined(__EDITOR__)
void CConfigurationParticleEmitter::setMinHorizontalVelocity(f32 min_horizontal_velocity)
{
IConfiguration::setAttribute("/particle_emitter/min_horizontal_velocity", std::make_shared<CConfigurationAttribute>(min_horizontal_velocity));
}
#endif
f32 CConfigurationParticleEmitter::getMaxHorizontalVelocity(void) const
{
const auto& iterator = m_attributes.find("/particle_emitter/max_horizontal_velocity");
assert(iterator != m_attributes.end());
f32 value; iterator->second->get(&value);
return value;
}
#if defined(__EDITOR__)
void CConfigurationParticleEmitter::setMaxHorizontalVelocity(f32 max_horizontal_velocity)
{
IConfiguration::setAttribute("/particle_emitter/max_horizontal_velocity", std::make_shared<CConfigurationAttribute>(max_horizontal_velocity));
}
#endif
f32 CConfigurationParticleEmitter::getMinVerticalVelocity(void) const
{
const auto& iterator = m_attributes.find("/particle_emitter/min_vertical_velocity");
assert(iterator != m_attributes.end());
f32 value; iterator->second->get(&value);
return value;
}
#if defined(__EDITOR__)
void CConfigurationParticleEmitter::setMinVerticalVelocity(f32 min_vertical_velocity)
{
IConfiguration::setAttribute("/particle_emitter/min_vertical_velocity", std::make_shared<CConfigurationAttribute>(min_vertical_velocity));
}
#endif
f32 CConfigurationParticleEmitter::getMaxVerticalVelocity(void) const
{
const auto& iterator = m_attributes.find("/particle_emitter/max_vertical_velocity");
assert(iterator != m_attributes.end());
f32 value; iterator->second->get(&value);
return value;
}
#if defined(__EDITOR__)
void CConfigurationParticleEmitter::setMaxVerticalVelocity(f32 max_vertical_velocity)
{
IConfiguration::setAttribute("/particle_emitter/max_vertical_velocity", std::make_shared<CConfigurationAttribute>(max_vertical_velocity));
}
#endif
f32 CConfigurationParticleEmitter::getEndVelocity(void) const
{
const auto& iterator = m_attributes.find("/particle_emitter/end_velocity");
assert(iterator != m_attributes.end());
f32 value; iterator->second->get(&value);
return value;
}
#if defined(__EDITOR__)
void CConfigurationParticleEmitter::setEndVelocity(f32 end_velocity)
{
IConfiguration::setAttribute("/particle_emitter/end_velocity", std::make_shared<CConfigurationAttribute>(end_velocity));
}
#endif
f32 CConfigurationParticleEmitter::getGravityX(void) const
{
const auto& iterator = m_attributes.find("/particle_emitter/gravity_x");
assert(iterator != m_attributes.end());
f32 value; iterator->second->get(&value);
return value;
}
#if defined(__EDITOR__)
void CConfigurationParticleEmitter::setGravityX(f32 gravity_x)
{
IConfiguration::setAttribute("/particle_emitter/gravity_x", std::make_shared<CConfigurationAttribute>(gravity_x));
}
#endif
f32 CConfigurationParticleEmitter::getGravityY(void) const
{
const auto& iterator = m_attributes.find("/particle_emitter/gravity_y");
assert(iterator != m_attributes.end());
f32 value; iterator->second->get(&value);
return value;
}
#if defined(__EDITOR__)
void CConfigurationParticleEmitter::setGravityY(f32 gravity_y)
{
IConfiguration::setAttribute("/particle_emitter/gravity_y", std::make_shared<CConfigurationAttribute>(gravity_y));
}
#endif
f32 CConfigurationParticleEmitter::getGravityZ(void) const
{
const auto& iterator = m_attributes.find("/particle_emitter/gravity_z");
assert(iterator != m_attributes.end());
f32 value; iterator->second->get(&value);
return value;
}
#if defined(__EDITOR__)
void CConfigurationParticleEmitter::setGravityZ(f32 gravity_z)
{
IConfiguration::setAttribute("/particle_emitter/gravity_z", std::make_shared<CConfigurationAttribute>(gravity_z));
}
#endif
ui8 CConfigurationParticleEmitter::getSourceColorR(void) const
{
const auto& iterator = m_attributes.find("/particle_emitter/source_color_r");
assert(iterator != m_attributes.end());
ui8 value; iterator->second->get(&value);
return value;
}
#if defined(__EDITOR__)
void CConfigurationParticleEmitter::setSourceColorR(ui8 source_color_r)
{
IConfiguration::setAttribute("/particle_emitter/source_color_r", std::make_shared<CConfigurationAttribute>(source_color_r));
}
#endif
ui8 CConfigurationParticleEmitter::getSourceColorG(void) const
{
const auto& iterator = m_attributes.find("/particle_emitter/source_color_g");
assert(iterator != m_attributes.end());
ui8 value; iterator->second->get(&value);
return value;
}
#if defined(__EDITOR__)
void CConfigurationParticleEmitter::setSourceColorG(ui8 source_color_g)
{
IConfiguration::setAttribute("/particle_emitter/source_color_g", std::make_shared<CConfigurationAttribute>(source_color_g));
}
#endif
ui8 CConfigurationParticleEmitter::getSourceColorB(void) const
{
const auto& iterator = m_attributes.find("/particle_emitter/source_color_b");
assert(iterator != m_attributes.end());
ui8 value; iterator->second->get(&value);
return value;
}
#if defined(__EDITOR__)
void CConfigurationParticleEmitter::setSourceColorB(ui8 source_color_b)
{
IConfiguration::setAttribute("/particle_emitter/source_color_b", std::make_shared<CConfigurationAttribute>(source_color_b));
}
#endif
ui8 CConfigurationParticleEmitter::getSourceColorA(void) const
{
const auto& iterator = m_attributes.find("/particle_emitter/source_color_a");
assert(iterator != m_attributes.end());
ui8 value; iterator->second->get(&value);
return value;
}
#if defined(__EDITOR__)
void CConfigurationParticleEmitter::setSourceColorA(ui8 source_color_a)
{
IConfiguration::setAttribute("/particle_emitter/source_color_a", std::make_shared<CConfigurationAttribute>(source_color_a));
}
#endif
ui8 CConfigurationParticleEmitter::getDestinationColorR(void) const
{
const auto& iterator = m_attributes.find("/particle_emitter/destination_color_r");
assert(iterator != m_attributes.end());
ui8 value; iterator->second->get(&value);
return value;
}
#if defined(__EDITOR__)
void CConfigurationParticleEmitter::setDestinationColorR(ui8 destination_color_r)
{
IConfiguration::setAttribute("/particle_emitter/destination_color_r", std::make_shared<CConfigurationAttribute>(destination_color_r));
}
#endif
ui8 CConfigurationParticleEmitter::getDestinationColorG(void) const
{
const auto& iterator = m_attributes.find("/particle_emitter/destination_color_g");
assert(iterator != m_attributes.end());
ui8 value; iterator->second->get(&value);
return value;
}
#if defined(__EDITOR__)
void CConfigurationParticleEmitter::setDestinationColorG(ui8 destination_color_g)
{
IConfiguration::setAttribute("/particle_emitter/destination_color_g", std::make_shared<CConfigurationAttribute>(destination_color_g));
}
#endif
ui8 CConfigurationParticleEmitter::getDestinationColorB(void) const
{
const auto& iterator = m_attributes.find("/particle_emitter/destination_color_b");
assert(iterator != m_attributes.end());
ui8 value; iterator->second->get(&value);
return value;
}
#if defined(__EDITOR__)
void CConfigurationParticleEmitter::setDestinationColorB(ui8 destination_color_b)
{
IConfiguration::setAttribute("/particle_emitter/destination_color_b", std::make_shared<CConfigurationAttribute>(destination_color_b));
}
#endif
ui8 CConfigurationParticleEmitter::getDestinationColorA(void) const
{
const auto& iterator = m_attributes.find("/particle_emitter/destination_color_a");
assert(iterator != m_attributes.end());
ui8 value; iterator->second->get(&value);
return value;
}
#if defined(__EDITOR__)
void CConfigurationParticleEmitter::setDestinationColorA(ui8 destination_color_a)
{
IConfiguration::setAttribute("/particle_emitter/destination_color_a", std::make_shared<CConfigurationAttribute>(destination_color_a));
}
#endif
f32 CConfigurationParticleEmitter::getSourceSizeX(void) const
{
const auto& iterator = m_attributes.find("/particle_emitter/source_size_x");
assert(iterator != m_attributes.end());
f32 value; iterator->second->get(&value);
return value;
}
#if defined(__EDITOR__)
void CConfigurationParticleEmitter::setSourceSizeX(f32 source_size_x)
{
IConfiguration::setAttribute("/particle_emitter/source_size_x", std::make_shared<CConfigurationAttribute>(source_size_x));
}
#endif
f32 CConfigurationParticleEmitter::getSourceSizeY(void) const
{
const auto& iterator = m_attributes.find("/particle_emitter/source_size_y");
assert(iterator != m_attributes.end());
f32 value; iterator->second->get(&value);
return value;
}
#if defined(__EDITOR__)
void CConfigurationParticleEmitter::setSourceSizeY(f32 source_size_y)
{
IConfiguration::setAttribute("/particle_emitter/source_size_y", std::make_shared<CConfigurationAttribute>(source_size_y));
}
#endif
f32 CConfigurationParticleEmitter::getDestinationSizeX(void) const
{
const auto& iterator = m_attributes.find("/particle_emitter/destination_size_x");
assert(iterator != m_attributes.end());
f32 value; iterator->second->get(&value);
return value;
}
#if defined(__EDITOR__)
void CConfigurationParticleEmitter::setDestinationSizeX(f32 destination_size_x)
{
IConfiguration::setAttribute("/particle_emitter/destination_size_x", std::make_shared<CConfigurationAttribute>(destination_size_x));
}
#endif
f32 CConfigurationParticleEmitter::getDestinationSizeY(void) const
{
const auto& iterator = m_attributes.find("/particle_emitter/destination_size_y");
assert(iterator != m_attributes.end());
f32 value; iterator->second->get(&value);
return value;
}
#if defined(__EDITOR__)
void CConfigurationParticleEmitter::setDestinationSizeY(f32 destination_size_y)
{
IConfiguration::setAttribute("/particle_emitter/destination_size_y", std::make_shared<CConfigurationAttribute>(destination_size_y));
}
#endif
ui32 CConfigurationParticleEmitter::getMinEmittInterval(void) const
{
const auto& iterator = m_attributes.find("/particle_emitter/min_emitt_interval");
assert(iterator != m_attributes.end());
ui32 value; iterator->second->get(&value);
return value;
}
#if defined(__EDITOR__)
void CConfigurationParticleEmitter::setMinEmittInterval(ui32 min_emitt_interval)
{
IConfiguration::setAttribute("/particle_emitter/min_emitt_interval", std::make_shared<CConfigurationAttribute>(min_emitt_interval));
}
#endif
ui32 CConfigurationParticleEmitter::getMaxEmittInterval(void) const
{
const auto& iterator = m_attributes.find("/particle_emitter/max_emitt_interval");
assert(iterator != m_attributes.end());
ui32 value; iterator->second->get(&value);
return value;
}
#if defined(__EDITOR__)
void CConfigurationParticleEmitter::setMaxEmittInterval(ui32 max_emitt_interval)
{
IConfiguration::setAttribute("/particle_emitter/max_emitt_interval", std::make_shared<CConfigurationAttribute>(max_emitt_interval));
}
#endif
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
#if defined(__EDITOR__)
void CConfigurationParticleEmitter::addMaterialsConfigurations(const std::shared_ptr<CConfigurationMaterial>& material)
{
IConfiguration::setConfiguration("/particle_emitter/materials/material", material);
}
#endif
#if defined(__EDITOR__)
void CConfigurationParticleEmitter::setMaterialsConfigurations(const std::shared_ptr<CConfigurationMaterial>& material, i32 index)
{
IConfiguration::setConfiguration("/particle_emitter/materials/material", material, index);
}
#endif
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
#if defined(__EDITOR__)
void CConfigurationParticleEmitter::deserialize(const std::string& filename)
{
pugi::xml_document document;
pugi::xml_parse_result result = document.load("");
assert(result.status == pugi::status_ok);
pugi::xml_node node = document.append_child("particle_emitter");
pugi::xml_node parent_node = node;
pugi::xml_attribute attribute;
attribute = node.append_attribute("num_particles");
ui32 num_particles = CConfigurationParticleEmitter::getNumParticles();
attribute.set_value(num_particles);
attribute = node.append_attribute("duration");
ui32 duration = CConfigurationParticleEmitter::getDuration();
attribute.set_value(duration);
attribute = node.append_attribute("duration_randomness");
f32 duration_randomness = CConfigurationParticleEmitter::getDurationRandomess();
attribute.set_value(duration_randomness);
attribute = node.append_attribute("velocity_sensitivity");
f32 velocity_sensitivity = CConfigurationParticleEmitter::getVelocitySensitivity();
attribute.set_value(velocity_sensitivity);
attribute = node.append_attribute("min_horizontal_velocity");
f32 min_horizontal_velocity = CConfigurationParticleEmitter::getMinHorizontalVelocity();
attribute.set_value(min_horizontal_velocity);
attribute = node.append_attribute("max_horizontal_velocity");
f32 max_horizontal_velocity = CConfigurationParticleEmitter::getMaxHorizontalVelocity();
attribute.set_value(max_horizontal_velocity);
attribute = node.append_attribute("min_vertical_velocity");
f32 min_vertical_velocity = CConfigurationParticleEmitter::getMinVerticalVelocity();
attribute.set_value(min_vertical_velocity);
attribute = node.append_attribute("max_vertical_velocity");
f32 max_vertical_velocity = CConfigurationParticleEmitter::getMaxVerticalVelocity();
attribute.set_value(max_vertical_velocity);
attribute = node.append_attribute("end_velocity");
f32 end_velocity = CConfigurationParticleEmitter::getEndVelocity();
attribute.set_value(end_velocity);
attribute = node.append_attribute("gravity_x");
f32 gravity_x = CConfigurationParticleEmitter::getGravityX();
attribute.set_value(gravity_x);
attribute = node.append_attribute("gravity_y");
f32 gravity_y = CConfigurationParticleEmitter::getGravityY();
attribute.set_value(gravity_y);
attribute = node.append_attribute("gravity_z");
f32 gravity_z = CConfigurationParticleEmitter::getGravityZ();
attribute.set_value(gravity_z);
attribute = node.append_attribute("source_color_r");
ui8 source_color_r = CConfigurationParticleEmitter::getSourceColorR();
attribute.set_value(source_color_r);
attribute = node.append_attribute("source_color_g");
ui8 source_color_g = CConfigurationParticleEmitter::getSourceColorG();
attribute.set_value(source_color_g);
attribute = node.append_attribute("source_color_b");
ui8 source_color_b = CConfigurationParticleEmitter::getSourceColorB();
attribute.set_value(source_color_b);
attribute = node.append_attribute("source_color_a");
ui8 source_color_a = CConfigurationParticleEmitter::getSourceColorA();
attribute.set_value(source_color_a);
attribute = node.append_attribute("destination_color_r");
ui8 destination_color_r = CConfigurationParticleEmitter::getDestinationColorR();
attribute.set_value(destination_color_r);
attribute = node.append_attribute("destination_color_g");
ui8 destination_color_g = CConfigurationParticleEmitter::getDestinationColorG();
attribute.set_value(destination_color_g);
attribute = node.append_attribute("destination_color_b");
ui8 destination_color_b = CConfigurationParticleEmitter::getDestinationColorB();
attribute.set_value(destination_color_b);
attribute = node.append_attribute("destination_color_a");
ui8 destination_color_a = CConfigurationParticleEmitter::getDestinationColorA();
attribute.set_value(destination_color_a);
attribute = node.append_attribute("source_size_x");
f32 source_size_x = CConfigurationParticleEmitter::getSourceSizeX();
attribute.set_value(source_size_x);
attribute = node.append_attribute("source_size_y");
f32 source_size_y = CConfigurationParticleEmitter::getSourceSizeY();
attribute.set_value(source_size_y);
attribute = node.append_attribute("destination_size_x");
f32 destination_size_x = CConfigurationParticleEmitter::getDestinationSizeX();
attribute.set_value(destination_size_x);
attribute = node.append_attribute("destination_size_y");
f32 destination_size_y = CConfigurationParticleEmitter::getDestinationSizeY();
attribute.set_value(destination_size_y);
attribute = node.append_attribute("min_emitt_interval");
ui32 min_emitt_interval = CConfigurationParticleEmitter::getMinEmittInterval();
attribute.set_value(min_emitt_interval);
attribute = node.append_attribute("max_emitt_interval");
ui32 max_emitt_interval = CConfigurationParticleEmitter::getMaxEmittInterval();
attribute.set_value(max_emitt_interval);
node = parent_node.append_child("materials");
for(const auto& iterator : CConfigurationParticleEmitter::getMaterialsConfigurations())
{
std::shared_ptr<CConfigurationMaterial> configuration = std::static_pointer_cast<CConfigurationMaterial>(iterator);
pugi::xml_node child_node = node.append_child("material");
attribute = child_node.append_attribute("filename");
attribute.set_value(configuration->getFilename().c_str());
}
document.save_file(filename.c_str());
}
#endif
