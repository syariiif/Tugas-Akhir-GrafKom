#pragma once

#include <glad/glad.h>
#include <SOIL/SOIL.h>
#include "Shader.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/vector_angle.hpp>

class Cube
{
private:
	GLuint vbo, ebo, vao;
	Shader* shader;
	glm::vec3 position, rotationAxis, scale, color;
	float angle;
	void InitData();
public:
	Cube(Shader* shader);
	~Cube();
	void Init();
	void Draw();
	void SetPosition(float x, float y, float z);
	void SetScale(float sx, float sy, float sz);
	void SetRotation(float angle, float x, float y, float z);
	void SetColor(float r, float g, float b);
};

