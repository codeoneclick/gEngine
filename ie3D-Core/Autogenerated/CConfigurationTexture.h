// autogenerated: do not add any changes
#ifndef CConfigurationTexture_h
#define CConfigurationTexture_h
#include "IConfiguration.h"
class CConfigurationTexture : public IConfiguration
{
public:
CConfigurationTexture(void) = default;
~CConfigurationTexture(void) = default;
bool isCubemap(void) const;
#if defined(__EDITOR__)
void set_is_cubemap(bool is_cubemap);
#endif
std::string getFilename(void) const;
#if defined(__EDITOR__)
void set_filename(std::string filename);
#endif
std::string getFilenamePositiveX(void) const;
#if defined(__EDITOR__)
void set_filename_x_positive(std::string filename_x_positive);
#endif
std::string getFilenameNegativeX(void) const;
#if defined(__EDITOR__)
void set_filename_x_negative(std::string filename_x_negative);
#endif
std::string getFilenamePositiveY(void) const;
#if defined(__EDITOR__)
void set_filename_y_positive(std::string filename_y_positive);
#endif
std::string getFilenameNegativeY(void) const;
#if defined(__EDITOR__)
void set_filename_y_negative(std::string filename_y_negative);
#endif
std::string getFilenamePositiveZ(void) const;
#if defined(__EDITOR__)
void set_filename_z_positive(std::string filename_z_positive);
#endif
std::string getFilenameNegativeZ(void) const;
#if defined(__EDITOR__)
void set_filename_z_negative(std::string filename_z_negative);
#endif
std::string getRenderOperationName(void) const;
#if defined(__EDITOR__)
void set_render_operation_name(std::string render_operation_name);
#endif
ui32 getSamplerIndex(void) const;
#if defined(__EDITOR__)
void set_sampler_index(ui32 sampler_index);
#endif
GLenum getWrapMode(void) const;
#if defined(__EDITOR__)
void set_wrap_mode(GLenum wrap_mode);
#endif
GLenum getMagFilter(void) const;
#if defined(__EDITOR__)
void set_mag_filter(GLenum mag_filter);
#endif
GLenum getMinFilter(void) const;
#if defined(__EDITOR__)
void set_min_filter(GLenum min_filter);
#endif
void serialize(pugi::xml_document& document, const std::string& path);
void serialize(pugi::xml_document& document, pugi::xpath_node& node);
};
#endif
