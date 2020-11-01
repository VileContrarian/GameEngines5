#ifndef MESH_H
#define MESH_H

#include <glew.h>
#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "..\..\Camera\Camera.h"

struct Vertex {
	glm::vec3 Pos;
	glm::vec3 Norm;
	glm::vec2 CoOrd;
	glm::vec3 Colour;
};

class Mesh{
public:
	Mesh(std::vector<Vertex>* vertexlist_, GLuint shaderprogram_, GLuint textureID_);
	~Mesh();
	void Render(Camera * camera_, glm::mat4 transform_);
private:
	void GenerateBuffers();
	GLuint VAO, VBO;
	std::vector<Vertex> vertexlist;

	GLuint shaderprogram;
	GLuint ModelLock, ViewLock, ProjLock;

	GLuint TextureID;
	GLuint TextureLock;
};

#endif MESH_H

