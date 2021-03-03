
#include "PacketDataJSon.h"



const char* PacketDataJSon::GetContent()
{
    
    return m_Content.c_str();
}


void PacketDataJSon::SetJsonContent(const char* _object)
{
	
	/*json::JSON _json = json::JSON(_object);
	std::cout << _json.ToString() << std::endl;
	m_Content = _json.ToString();*/
	std::cout << _object << std::endl;
	m_Content = _object;
	m_Type = Type::JSon;
	m_Valid = true;
}
void* PacketDataJSon::Serialize(unsigned int& _size)
{
	// no content !
	if (!m_Valid)
	{
		_size = 0;
		return nullptr;
	}

	// compute the size of the packet over the network
	_size = sizeof(Type) + m_Content.length() + 1;
	// allocate the content we are preparing to send
	m_Data = malloc(_size);
	void* workBuffer = m_Data;

	// write the packet type : json, string, whatever
	Type* ptrType = static_cast<Type*>(workBuffer);
	*ptrType = m_Type;

	//workBuffer = (void *)((int)workBuffer + sizeof(Type));
	ptrType++;
	workBuffer = (void*)ptrType;


	// then write the content
	char* contentStr = static_cast<char*>(workBuffer);
	strcpy_s(contentStr, m_Content.length() + 1, m_Content.c_str());

	// return it
	return m_Data;
    
    
}

void PacketDataJSon::Deserialize(void* _data, int _size)
{
	// read the packet type : json, string, ...
	Type* ptrType = static_cast<Type*>(_data);
	m_Type = *ptrType;
	_data = (void*)((int)_data + sizeof(Type));

	if (m_Type == Type::JSon)
	{
		// then read the content according to the packet type
		char* contentStr = static_cast<char*>(_data);
		m_Content = contentStr;

		m_Valid = true;
	}
}
