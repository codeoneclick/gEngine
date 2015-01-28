#!/usr/bin/python
import sys
import os
import re
from xml.etree import ElementTree
from re import sub, split, UNICODE
from os import walk, listdir
from os.path import isfile, join, basename

kConfiguratiomShader = "../../ie3D-Bundle/Configurations/sample.shader.xml"
kConfiguratiomTexture = "../../ie3D-Bundle/Configurations/sample.texture.xml"
kConfigurationMaterial = "../../ie3D-Bundle/Configurations/sample.material.xml"
kConfigurationAnimation= "../../ie3D-Bundle/Configurations/sample.animation.xml"
kConfigurationModel = "../../ie3D-Bundle/Configurations/sample.model.xml"
kConfigurationWSTechnique = "../../ie3D-Bundle/Configurations/sample.ws_technique.xml"
kConfigurationSSTechnique = "../../ie3D-Bundle/Configurations/sample.ss_technique.xml"
kConfigurationOutputTechnique = "../../ie3D-Bundle/Configurations/sample.output_technique.xml"
kConfigurationTransition = "../../ie3D-Bundle/Configurations/sample.transition.xml"
kConfigurationParticleEmitter = "../../ie3D-Bundle/Configurations/sample.particle_emitter.xml"

kConfigurationAutogeneratedSourcesPath = "../Autogenerated/"

def get_filepathes(directory, extension):
    filepathes = [] 

    for root, directories, files in os.walk(directory):
        for filename in files:

            filepath = os.path.join(root, filename)
            if filename.endswith(extension) and "example" in filename:
            	filepathes.append(filepath)

    return filepathes


def get_attribute_type_converter(attribute_type):
 	if attribute_type == 'bool':
 		return 'as_bool()'
 	elif attribute_type == 'i64' or attribute_type == 'i32' or attribute_type == 'i16' or attribute_type == 'i8':
 		return 'as_int()'
 	elif attribute_type == 'ui64' or attribute_type == 'ui32' or attribute_type == 'ui16' or attribute_type == 'ui8':
 		return 'as_uint()'
 	elif attribute_type == 'f32':
 		return 'as_float()'
 	elif attribute_type == 'std::string':
 		return 'as_string()'
 	raise Exception('unknown attribute type')


def write_attributes_serializer(source_cpp_file, attributes):
 	for attribute in attributes:

		source_cpp_file.write(attribute.get('type') + ' ' + attribute.get("attribute_name") + ' = node.node().attribute("'+ attribute.get("attribute_name") + '").' + get_attribute_type_converter(attribute.get('type')) +';\n')
		if attribute.get('is_convert_to_ogl_enum') == '1':

			source_cpp_file.write('assert(g_stringToGLenum.find('+ attribute.get("attribute_name") +') != g_stringToGLenum.end());\n')
			source_cpp_file.write('GLenum '+ attribute.get("attribute_name") + 'Enum' + ' = g_stringToGLenum.find('+ attribute.get("attribute_name") +')->second;\n')
			source_cpp_file.write('IConfiguration::setAttribute("' + attribute.get("path") + '/' + attribute.get("attribute_name") + '", std::make_shared<CConfigurationAttribute>(' + attribute.get("attribute_name") + 'Enum));\n')

		else:

			source_cpp_file.write('IConfiguration::setAttribute("' + attribute.get("path") + '/' + attribute.get("attribute_name") + '", std::make_shared<CConfigurationAttribute>(' + attribute.get("attribute_name") + '));\n')
			



def write_relationships_serializer(source_cpp_file, relationships):
	for relationship in relationships:

		if relationship.get("is_to_many") == '0':

			source_cpp_file.write('std::shared_ptr<' + relationship.get('type') + '> ' + relationship.get('relationship_name') + ' = std::make_shared<' + relationship.get('type') + '>();\n')

			if relationship.get("is_external") == '0':

				source_cpp_file.write(relationship.get('relationship_name') + '->serialize(document, "' + relationship.get('path') + '");\n')

			else:

				source_cpp_file.write('pugi::xpath_node ' + relationship.get('relationship_name') + '_node' + ' = document.select_single_node("' + relationship.get('path') + relationship.get('relationship_name') + '");\n')
				source_cpp_file.write(relationship.get('relationship_name') + '->serialize(' + relationship.get('relationship_name') + '_node' + '.node().attribute("filename").as_string());\n')

			source_cpp_file.write('IConfiguration::setConfiguration("' + relationship.get('path') + '/' + relationship.get("relationship_name") + '", ' + relationship.get('relationship_name') + ');\n')

		else:

			source_cpp_file.write('pugi::xpath_node_set ' + relationship.get('relationship_name') + '_nodes = document.select_nodes("' + relationship.get('path') + '/' + relationship.get('relationship_name') + '");\n')
			source_cpp_file.write('for (pugi::xpath_node_set::const_iterator iterator = ' + relationship.get('relationship_name') + '_nodes.begin(); iterator != ' + relationship.get('relationship_name') + '_nodes.end(); ++iterator)\n')
			source_cpp_file.write('{\n')
			source_cpp_file.write('std::shared_ptr<' + relationship.get('type') + '> ' + relationship.get('relationship_name') + ' = std::make_shared<' + relationship.get('type') + '>();\n')

			if relationship.get("is_external") == '0':

				source_cpp_file.write(relationship.get('relationship_name') + '->serialize(document, "' + relationship.get('path') + '");\n')

			else:

				source_cpp_file.write(relationship.get('relationship_name') + '->serialize((*iterator).node().attribute("filename").as_string());\n')

			source_cpp_file.write('IConfiguration::setConfiguration("' + relationship.get('path') + '/' + relationship.get("relationship_name") + '", ' + relationship.get('relationship_name') + ');\n')
			source_cpp_file.write('}\n')
			



def parse_xml(filename):
	document = ElementTree.parse(filename)
	root = document.getroot()

	class_name = root.get("class_name")
	base_class_name = root.get("base_class_name")
	is_external = root.get("is_external")

	source_h_file = open(kConfigurationAutogeneratedSourcesPath + class_name + '.h', 'w+')
	source_cpp_file = open(kConfigurationAutogeneratedSourcesPath + class_name + '.cpp', 'w+')
	source_cpp_file.write('// autogenerated: do not add any changes\n')
	source_cpp_file.write('#include "'+ class_name + '.h"\n')
	
	source_h_file.write('// autogenerated: do not add any changes\n')
	source_h_file.write('#ifndef ' + class_name + '_h\n')
	source_h_file.write('#define ' + class_name + '_h\n')
	source_h_file.write('#include "IConfiguration.h"\n')
	for relationship in root.iter('relationship'):
		source_h_file.write('#include "' + relationship.get("type") + '.h"\n')
	source_h_file.write('class ' + class_name + ' : public ' + base_class_name + '\n')
	source_h_file.write('{\n')
	
	source_h_file.write('public:\n')
	source_h_file.write(class_name + '(void) = default;\n')
	source_h_file.write('~' + class_name + '(void) = default;\n')

	for attribute in root.iter('attribute'):

		if attribute.get('is_convert_to_ogl_enum') == '0':

			source_h_file.write(attribute.get('type') + ' ' + attribute.get("getter") + '(void) const;\n')
			source_cpp_file.write(attribute.get('type') + ' ' + class_name + '::' + attribute.get("getter") + '(void) const\n')

		else:

			source_h_file.write('GLenum ' + attribute.get("getter") + '(void) const;\n')
			source_cpp_file.write('GLenum ' + class_name + '::' + attribute.get("getter") + '(void) const\n')

		source_cpp_file.write('{\n')
		source_cpp_file.write('const auto& iterator = m_attributes.find(\"' + attribute.get("path") + '/' + attribute.get("attribute_name") + '\");\n')
		source_cpp_file.write('assert(iterator != m_attributes.end());\n')
		if attribute.get('is_convert_to_ogl_enum') == '0':
			source_cpp_file.write(attribute.get('type') + ' value; iterator->second->get(&value);\n')
		else:
			source_cpp_file.write('GLenum value; iterator->second->get(&value);\n')
		source_cpp_file.write('return value;\n')
		source_cpp_file.write('}\n')

	for relationship in root.iter('relationship'):

		if relationship.get("is_to_many") == '0':

			source_h_file.write('std::shared_ptr<' + relationship.get("type") + '> ' + relationship.get("getter") + '(void) const;\n')
			source_cpp_file.write('std::shared_ptr<' + relationship.get("type") + '> ' + class_name + '::' + relationship.get("getter") + '(void) const\n')
			source_cpp_file.write('{\n')
			source_cpp_file.write('const auto& iterator = m_configurations.find(\"' + relationship.get("path") + '/' + relationship.get("relationship_name") + '\");\n')
			source_cpp_file.write('assert(iterator != m_configurations.end());\n')
			source_cpp_file.write('assert(iterator->second.size() != 0);\n')
			source_cpp_file.write('return std::static_pointer_cast<' + relationship.get("type") + '>(iterator->second.at(0));\n')
			source_cpp_file.write('}\n')

		else:

			source_h_file.write('std::vector<std::shared_ptr<IConfiguration>> ' + relationship.get("getter") + '(void) const;\n')
			source_cpp_file.write('std::vector<std::shared_ptr<IConfiguration>> ' + class_name + '::' + relationship.get("getter") + '(void) const\n')
			source_cpp_file.write('{\n')
			source_cpp_file.write('const auto& iterator = m_configurations.find(\"' + relationship.get("path") + '/' + relationship.get("relationship_name") + '\");\n')
			source_cpp_file.write('assert(iterator != m_configurations.end());\n')
			source_cpp_file.write('return iterator->second;\n')
			source_cpp_file.write('}\n')

	if is_external == "0":

		source_h_file.write('void serialize(pugi::xml_document& document, const std::string& path);\n')
		source_cpp_file.write('void ' + class_name + '::serialize(pugi::xml_document& document, const std::string& path)\n')
		source_cpp_file.write('{\n')
		source_cpp_file.write('pugi::xpath_node node;\n')
		source_cpp_file.write('node = document.select_single_node((path + "' + attribute.get("path") + '").c_str());\n')

	else:

		source_h_file.write('void serialize(const std::string& filename);\n')
		source_cpp_file.write('void ' + class_name + '::serialize(const std::string& filename)\n')
		source_cpp_file.write('{\n')
		source_cpp_file.write('pugi::xml_document document;\n')
		source_cpp_file.write('pugi::xml_parse_result result = IConfiguration::openXMLDocument(document, filename);\n')
		source_cpp_file.write('assert(result.status == pugi::status_ok);\n')
		source_cpp_file.write('pugi::xpath_node node;\n')
		source_cpp_file.write('node = document.select_single_node("' + attribute.get("path") + '");\n')

	write_attributes_serializer(source_cpp_file, root.iter('attribute'))
	write_relationships_serializer(source_cpp_file, root.iter('relationship'))

	source_cpp_file.write('}\n')

	source_h_file.write('};\n')
	source_h_file.write('#endif\n')
	source_h_file.close()
	source_cpp_file.close()

def main():

	parse_xml(kConfiguratiomShader)
	parse_xml(kConfiguratiomTexture)
	parse_xml(kConfigurationMaterial)
	parse_xml(kConfigurationAnimation)
	parse_xml(kConfigurationModel)
	parse_xml(kConfigurationWSTechnique)
	parse_xml(kConfigurationSSTechnique)
	parse_xml(kConfigurationOutputTechnique)
	parse_xml(kConfigurationTransition)
	parse_xml(kConfigurationParticleEmitter)

main()