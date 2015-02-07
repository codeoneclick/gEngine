// autogenerated: do not add any changes
#include "CConfigurationLandscape.h"
std::string CConfigurationLandscape::getHeightmapDataFilename(void) const
{
const auto& iterator = m_attributes.find("/landscape/heightmap_data_filename");
assert(iterator != m_attributes.end());
std::string value; iterator->second->get(&value);
return value;
}
#if defined(__EDITOR__)
void CConfigurationLandscape::set_heightmap_data_filename(std::string heightmap_data_filename)
{
IConfiguration::setAttribute("/landscape/heightmap_data_filename", std::make_shared<CConfigurationAttribute>(heightmap_data_filename));
}
#endif
std::string CConfigurationLandscape::getSplattingDataFilename(void) const
{
const auto& iterator = m_attributes.find("/landscape/splatting_data_filename");
assert(iterator != m_attributes.end());
std::string value; iterator->second->get(&value);
return value;
}
#if defined(__EDITOR__)
void CConfigurationLandscape::set_splatting_data_filename(std::string splatting_data_filename)
{
IConfiguration::setAttribute("/landscape/splatting_data_filename", std::make_shared<CConfigurationAttribute>(splatting_data_filename));
}
#endif
ui32 CConfigurationLandscape::getSizeX(void) const
{
const auto& iterator = m_attributes.find("/landscape/size_x");
assert(iterator != m_attributes.end());
ui32 value; iterator->second->get(&value);
return value;
}
#if defined(__EDITOR__)
void CConfigurationLandscape::set_size_x(ui32 size_x)
{
IConfiguration::setAttribute("/landscape/size_x", std::make_shared<CConfigurationAttribute>(size_x));
}
#endif
ui32 CConfigurationLandscape::getSizeY(void) const
{
const auto& iterator = m_attributes.find("/landscape/size_y");
assert(iterator != m_attributes.end());
ui32 value; iterator->second->get(&value);
return value;
}
#if defined(__EDITOR__)
void CConfigurationLandscape::set_size_y(ui32 size_y)
{
IConfiguration::setAttribute("/landscape/size_y", std::make_shared<CConfigurationAttribute>(size_y));
}
#endif
f32 CConfigurationLandscape::getFrequency(void) const
{
const auto& iterator = m_attributes.find("/landscape/frequency");
assert(iterator != m_attributes.end());
f32 value; iterator->second->get(&value);
return value;
}
#if defined(__EDITOR__)
void CConfigurationLandscape::set_frequency(f32 frequency)
{
IConfiguration::setAttribute("/landscape/frequency", std::make_shared<CConfigurationAttribute>(frequency));
}
#endif
i32 CConfigurationLandscape::getOctaves(void) const
{
const auto& iterator = m_attributes.find("/landscape/octaves");
assert(iterator != m_attributes.end());
i32 value; iterator->second->get(&value);
return value;
}
#if defined(__EDITOR__)
void CConfigurationLandscape::set_octaves(i32 octaves)
{
IConfiguration::setAttribute("/landscape/octaves", std::make_shared<CConfigurationAttribute>(octaves));
}
#endif
ui32 CConfigurationLandscape::getSeed(void) const
{
const auto& iterator = m_attributes.find("/landscape/seed");
assert(iterator != m_attributes.end());
ui32 value; iterator->second->get(&value);
return value;
}
#if defined(__EDITOR__)
void CConfigurationLandscape::set_seed(ui32 seed)
{
IConfiguration::setAttribute("/landscape/seed", std::make_shared<CConfigurationAttribute>(seed));
}
#endif
std::vector<std::shared_ptr<IConfiguration>> CConfigurationLandscape::getMaterialsConfigurations(void) const
{
const auto& iterator = m_configurations.find("/landscape/materials/material");
if(iterator == m_configurations.end())
{
return std::vector<std::shared_ptr<IConfiguration>>();
}
assert(iterator != m_configurations.end());
return iterator->second;
}
#if defined(__EDITOR__)
void CConfigurationLandscape::add_material(const std::shared_ptr<CConfigurationMaterial>& material)
{
IConfiguration::setConfiguration("/landscape/materials/material", material);
}
#endif
#if defined(__EDITOR__)
void CConfigurationLandscape::set_material(const std::shared_ptr<CConfigurationMaterial>& material, i32 index)
{
IConfiguration::setConfiguration("/landscape/materials/material", material, index);
}
#endif
void CConfigurationLandscape::serialize(const std::string& filename)
{
pugi::xml_document document;
pugi::xml_parse_result result = IConfiguration::openXMLDocument(document, filename);
assert(result.status == pugi::status_ok);
pugi::xpath_node node;
node = document.select_single_node("/landscape");
std::string heightmap_data_filename = node.node().attribute("heightmap_data_filename").as_string();
IConfiguration::setAttribute("/landscape/heightmap_data_filename", std::make_shared<CConfigurationAttribute>(heightmap_data_filename));
std::string splatting_data_filename = node.node().attribute("splatting_data_filename").as_string();
IConfiguration::setAttribute("/landscape/splatting_data_filename", std::make_shared<CConfigurationAttribute>(splatting_data_filename));
ui32 size_x = node.node().attribute("size_x").as_uint();
IConfiguration::setAttribute("/landscape/size_x", std::make_shared<CConfigurationAttribute>(size_x));
ui32 size_y = node.node().attribute("size_y").as_uint();
IConfiguration::setAttribute("/landscape/size_y", std::make_shared<CConfigurationAttribute>(size_y));
f32 frequency = node.node().attribute("frequency").as_float();
IConfiguration::setAttribute("/landscape/frequency", std::make_shared<CConfigurationAttribute>(frequency));
i32 octaves = node.node().attribute("octaves").as_int();
IConfiguration::setAttribute("/landscape/octaves", std::make_shared<CConfigurationAttribute>(octaves));
ui32 seed = node.node().attribute("seed").as_uint();
IConfiguration::setAttribute("/landscape/seed", std::make_shared<CConfigurationAttribute>(seed));
pugi::xpath_node_set material_nodes = document.select_nodes("/landscape/materials/material");
for (pugi::xpath_node_set::const_iterator iterator = material_nodes.begin(); iterator != material_nodes.end(); ++iterator)
{
std::shared_ptr<CConfigurationMaterial> material = std::make_shared<CConfigurationMaterial>();
material->serialize((*iterator).node().attribute("filename").as_string());
IConfiguration::setConfiguration("/landscape/materials/material", material);
}
}
