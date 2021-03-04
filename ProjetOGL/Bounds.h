#pragma once
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <GLFW/glfw3.h>


class Bounds
{
protected:
	glm::vec3 center = glm::vec3(0, 0, 0);
	glm::vec3 size = glm::vec3(0, 0, 0);
	float sizeMultiplier = 1.f;

public:
	/*----Getter----*/
	inline glm::vec3 GetCenter() const { return center; };
	inline glm::vec3 GetSize() const { return size; };

	/*----Size----*/
	inline void SetCenter(glm::vec3 _center) { center = _center; };
	inline void SetSize(glm::vec3 _size) { size = _size; };

	/*----Constructor----*/
	Bounds(const glm::vec3 _center, const glm::vec3 _size,float _sizeMulitplier);

	inline float GetSizeMultiplier() { return sizeMultiplier; };
	/*----Methods----*/
	bool Intersects(const Bounds& _bounds);
};

