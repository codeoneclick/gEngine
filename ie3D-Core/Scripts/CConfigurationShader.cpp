// autogenerated: do not add any changes
std::string CConfigurationShader::getVSFilename(void) const
{
const auto& iterator = m_attributes.find("/shader/vs_filename");
assert(iterator != m_attributes.end());
std::string value; iterator->second->get(&value);
return value
}
std::string CConfigurationShader::getFSFilename(void) const
{
const auto& iterator = m_attributes.find("/shader/fs_filename");
assert(iterator != m_attributes.end());
std::string value; iterator->second->get(&value);
return value
}
std::shared_ptr<CConfigurationShader> CConfigurationShader::serialize(pugi::xml_document& document, const std::string& path)
{
pugi::xpath_node node;
node = document.select_single_node(path + "/shader");
std::string vs_filename = node.node().attribute("vs_filename").as_string();
IConfiguration::setAttribute("/shader/vs_filename", std::make_shared<CConfigurationAttribute>(vs_filename));
GLenum vs_filenameEnum = g_stringToGLenum.find(vs_filename)->second;
std::string fs_filename = node.node().attribute("fs_filename").as_string();
IConfiguration::setAttribute("/shader/fs_filename", std::make_shared<CConfigurationAttribute>(fs_filename));
GLenum fs_filenameEnum = g_stringToGLenum.find(fs_filename)->second;
}
