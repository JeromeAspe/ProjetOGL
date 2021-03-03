#pragma once

#include "PacketData.h"


class PacketDataJSon : public PacketData
{
public :
	//template<typename T>
	void SetJsonContent(const char* _object);
	const char* GetContent();
	void* Serialize(unsigned int& _size);
	void Deserialize(void* _data, int _size);


	
};


