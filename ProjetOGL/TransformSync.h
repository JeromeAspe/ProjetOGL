#pragma once
#include "MonoBehaviour.h"
#include "ENet.h"
class TransformSync : MonoBehaviour
{
public :

	TransformSync(bool _isMine, ENet* _reseau);
};

