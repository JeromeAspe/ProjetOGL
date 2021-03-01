#include "Object.h"
#include <typeinfo>

Object::Object()
{
    name = typeid(this).name();
}

std::string Object::ToString()
{
    return name;
}
