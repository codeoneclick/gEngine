// autogenerated: do not add any changes
#ifndef CConfigurationShader_h
#define CConfigurationShader_h
class CConfigurationShader : public IConfiguration
{
public:
CConfigurationShader(void) = default
~CConfigurationShader(void) = default
std::string getVSFilename(void) const;
std::string getFSFilename(void) const;
std::shared_ptr<CConfigurationShader> serialize(pugi::xml_document& document);
};
