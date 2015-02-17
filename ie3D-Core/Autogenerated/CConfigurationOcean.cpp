// autogenerated: do not add any changes
#include "CConfigurationOcean.h"
i32 CConfigurationOcean::getZOrder(void) const
{
const auto& iterator = m_attributes.find("/ocean/z_order");
assert(iterator != m_attributes.end());
i32 value; iterator->second->get(&value);
return value;
}
#if defined(__EDITOR__)
void CConfigurationOcean::setZOrder(i32 z_order)
{
IConfiguration::setAttribute("/ocean/z_order", std::make_shared<CConfigurationAttribute>(z_order));
}
#endif
ui32 CConfigurationOcean::getSize(void) const
{
const auto& iterator = m_attributes.find("/ocean/size");
assert(iterator != m_attributes.end());
ui32 value; iterator->second->get(&value);
return value;
}
#if defined(__EDITOR__)
void CConfigurationOcean::setSize(ui32 size)
{
IConfiguration::setAttribute("/ocean/size", std::make_shared<CConfigurationAttribute>(size));
}
#endif
f32 CConfigurationOcean::getAltitude(void) const
{
const auto& iterator = m_attributes.find("/ocean/altitude");
assert(iterator != m_attributes.end());
f32 value; iterator->second->get(&value);
return value;
}
#if defined(__EDITOR__)
void CConfigurationOcean::setAltitude(f32 altitude)
{
IConfiguration::setAttribute("/ocean/altitude", std::make_shared<CConfigurationAttribute>(altitude));
}
#endif
f32 CConfigurationOcean::getWaveGenerationInterval(void) const
{
const auto& iterator = m_attributes.find("/ocean/wave_generation_interval");
assert(iterator != m_attributes.end());
f32 value; iterator->second->get(&value);
return value;
}
#if defined(__EDITOR__)
void CConfigurationOcean::setWaveGenerationInterval(f32 wave_generation_interval)
{
IConfiguration::setAttribute("/ocean/wave_generation_interval", std::make_shared<CConfigurationAttribute>(wave_generation_interval));
}
#endif
std::vector<std::shared_ptr<IConfiguration>> CConfigurationOcean::getMaterialsConfigurations(void) const
{
const auto& iterator = m_configurations.find("/ocean/materials/material");
if(iterator == m_configurations.end())
{
return std::vector<std::shared_ptr<IConfiguration>>();
}
assert(iterator != m_configurations.end());
return iterator->second;
}
#if defined(__EDITOR__)
void CConfigurationOcean::addMaterialsConfigurations(const std::shared_ptr<CConfigurationMaterial>& material)
{
IConfiguration::setConfiguration("/ocean/materials/material", material);
}
#endif
#if defined(__EDITOR__)
void CConfigurationOcean::setMaterialsConfigurations(const std::shared_ptr<CConfigurationMaterial>& material, i32 index)
{
IConfiguration::setConfiguration("/ocean/materials/material", material, index);
}
#endif
void CConfigurationOcean::serialize(const std::string& filename)
{
pugi::xml_document document;
pugi::xml_parse_result result = IConfiguration::openXMLDocument(document, filename);
assert(result.status == pugi::status_ok);
pugi::xpath_node node;
node = document.select_single_node("/ocean");
i32 z_order = node.node().attribute("z_order").as_int();
IConfiguration::setAttribute("/ocean/z_order", std::make_shared<CConfigurationAttribute>(z_order));
ui32 size = node.node().attribute("size").as_uint();
IConfiguration::setAttribute("/ocean/size", std::make_shared<CConfigurationAttribute>(size));
f32 altitude = node.node().attribute("altitude").as_float();
IConfiguration::setAttribute("/ocean/altitude", std::make_shared<CConfigurationAttribute>(altitude));
f32 wave_generation_interval = node.node().attribute("wave_generation_interval").as_float();
IConfiguration::setAttribute("/ocean/wave_generation_interval", std::make_shared<CConfigurationAttribute>(wave_generation_interval));
pugi::xpath_node_set material_nodes = document.select_nodes("/ocean/materials/material");
for (pugi::xpath_node_set::const_iterator iterator = material_nodes.begin(); iterator != material_nodes.end(); ++iterator)
{
std::shared_ptr<CConfigurationMaterial> material = std::make_shared<CConfigurationMaterial>();
material->serialize((*iterator).node().attribute("filename").as_string());
IConfiguration::setConfiguration("/ocean/materials/material", material);
}
}
#if defined(__EDITOR__)
void CConfigurationOcean::deserialize(const std::string& filename)
{
pugi::xml_document document;
pugi::xml_parse_result result = document.load("");
assert(result.status == pugi::status_ok);
pugi::xml_node node = document.append_child("ocean");
pugi::xml_node parent_node = node;
pugi::xml_attribute attribute;
attribute = node.append_attribute("z_order");
i32 z_order = CConfigurationOcean::getZOrder();
attribute.set_value(z_order);
attribute = node.append_attribute("size");
ui32 size = CConfigurationOcean::getSize();
attribute.set_value(size);
attribute = node.append_attribute("altitude");
f32 altitude = CConfigurationOcean::getAltitude();
attribute.set_value(altitude);
attribute = node.append_attribute("wave_generation_interval");
f32 wave_generation_interval = CConfigurationOcean::getWaveGenerationInterval();
attribute.set_value(wave_generation_interval);
node = parent_node.append_child("materials");
for(const auto& iterator : CConfigurationOcean::getMaterialsConfigurations())
{
std::shared_ptr<CConfigurationMaterial> configuration = std::static_pointer_cast<CConfigurationMaterial>(iterator);
pugi::xml_node child_node = node.append_child("material");
attribute = child_node.append_attribute("filename");
attribute.set_value(configuration->getFilename().c_str());
}
document.save_file(filename.c_str());
}
#endif
