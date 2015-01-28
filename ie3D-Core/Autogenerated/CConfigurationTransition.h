// autogenerated: do not add any changes
#ifndef CConfigurationTransition_h
#define CConfigurationTransition_h
#include "IConfiguration.h"
#include "CConfigurationOutputTechnique.h"
#include "CConfigurationWSTechnique.h"
#include "CConfigurationSSTechnique.h"
class CConfigurationTransition : public IConfiguration
{
public:
CConfigurationTransition(void) = default;
~CConfigurationTransition(void) = default;
std::string getGUID(void) const;
std::shared_ptr<CConfigurationOutputTechnique> getConfigurationOutputTechnique(void) const;
std::vector<std::shared_ptr<IConfiguration>> getConfigurationWSTechnique(void) const;
std::vector<std::shared_ptr<IConfiguration>> getConfigurationSSTechnique(void) const;
void serialize(const std::string& filename);
};
#endif
