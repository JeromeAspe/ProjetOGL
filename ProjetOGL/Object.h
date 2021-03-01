#pragma once
#include <string>

class Object
{
protected:

	std::string name = "";

public :

#pragma region Constructors
	Object();
#pragma endregion

	virtual std::string ToString();
};

