#include "Bounds.h"

Bounds::Bounds(const glm::vec3 _center, const glm::vec3 _size,float _sizeMultiplier)
{
	center = _center;
	size = _size;
	sizeMultiplier = _sizeMultiplier;
}


bool Bounds::Intersects(const Bounds& _bounds)
{
	printf("Mine x => %f z => %f\n", size.x, size.z);
	printf("Ohter x => %f y => %f z => %f\n", _bounds.GetSize().x, _bounds.GetSize().y, _bounds.GetSize().z);
	glm::vec3 _otherSize = _bounds.GetSize() * _bounds.sizeMultiplier;
	glm::vec3 _mineSize = size * sizeMultiplier;

	float _minXMine = center.x - (_mineSize.x / 2), _maxXMine = center.x + (_mineSize.x / 2);
	float _minXOther = _bounds.GetCenter().x - (_otherSize.x / 2), _maxXOther = _bounds.GetCenter().x + (_otherSize.x / 2);

	float _minYMine = center.y - (_mineSize.y / 2), _maxYMine = center.y + (_mineSize.y / 2);
	float _minYOther = _bounds.GetCenter().y - (_otherSize.y / 2), _maxYOther = _bounds.GetCenter().y + (_otherSize.y / 2);

	float _minZMine = center.z - (_mineSize.z / 2), _maxZMine = center.z + (_mineSize.z / 2);
	float _minZOther = _bounds.GetCenter().z - (_otherSize.z / 2), _maxZOther = _bounds.GetCenter().z + (_otherSize.z / 2);

	bool _collideX = (_minXMine > _minXOther&& _minXMine < _maxXOther) || (_maxXMine > _minXOther && _maxXMine < _maxXOther);
	bool _collideY = (_minYMine > _minYOther&& _minYMine < _maxYOther) || (_maxYMine > _minYOther&& _maxYMine < _maxYOther);
	bool _collideZ = (_minZMine > _minZOther&& _minZMine < _maxZOther) || (_maxZMine > _minZOther&& _maxZMine < _maxZOther);

	if (_collideX && _collideY && _collideZ)return true;
	else return false;
}
