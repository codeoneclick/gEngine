// autogenerated: do not add any changes
#ifndef CConfigurationOcean_h
#define CConfigurationOcean_h
#include "IConfiguration.h"
#include "CConfigurationMaterial.h"
class CConfigurationOcean : public IConfigurationGameObject
{
public:
CConfigurationOcean(void) = default;
~CConfigurationOcean(void) = default;
ui32 getSize(void) const;
ui32 getAltitude(void) const;
ui32 getWaveGenerationInterval(void) const;
std::vector<std::shared_ptr<IConfiguration>> getMaterialsConfigurations(void) const;
void serialize(const std::string& filename);
};
#endif
