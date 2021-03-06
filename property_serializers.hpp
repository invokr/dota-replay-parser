#ifndef _PROPERTY_SERIALIZERS_HPP_
#define _PROPERTY_SERIALIZERS_HPP_

#include <iostream>
#include <math.h>
#include <regex>

#include "bitstream.hpp"
#include "parser_types.hpp"
#include "property_decoder.hpp"

void fillSerializer(PropertySerializerTable* pst, dt_field* field);
PropertySerializer* GetPropertySerializerByName(PropertySerializerTable* pst, const std::string &name);
PropertySerializerTable* getDefaultPropertySerializerTable();

#endif /* _PROPERTY_SERIALIZERS_HPP_ */