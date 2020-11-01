#ifndef MODEL_H
#define MODEL_H

#include "Mesh.h"
#include <glm/gtc/matrix_transform.hpp>

class Model
{
public:
	Model(GLuint shaderProgram_, glm::vec3 position_, float angle_ = 0.0f, glm::vec3 rotation_ = glm::vec3(0.0f,1.0f,0.0f), glm::vec3 scale_ = glm::vec3(1.0f));
	~Model();
	void Render(Camera* camera_);
	void AddMesh(Mesh* mesh_);

	glm::vec3 GetPosition() const;
	float GetAngle() const;
	glm::vec3 GetRotation() const;
	glm::vec3 GetScale() const;

	void SetPosition(glm::vec3 position_);
	void SetAngle(float angle_);
	void SetRotation(glm::vec3 roation_);
	void SetScale(glm::vec3 scale_);
private:
	std::vector<Mesh*> subMeshes;
	GLuint shaderProgram;

	glm::vec3 Position;
	float Angle;
	glm::vec3 Rotation;
	glm::vec3 Scale;

	glm::mat4 GetTransform();
};

#endif MODEL_H

