#include "Model.h"



Model::Model(GLuint shaderProgram_, glm::vec3 position_, float angle_, glm::vec3 rotation_, glm::vec3 scale_) : subMeshes(std::vector<Mesh*>())
{
	subMeshes.reserve(10);
	shaderProgram = shaderProgram_;

	Position = position_;
	Angle = angle_;
	Rotation = rotation_;
	Scale = scale_;
}


Model::~Model()
{
	if (subMeshes.size() > 0) {
		for (auto m : subMeshes) {
			delete m;
			m = nullptr;
		}
		subMeshes.clear();
	}
}

void Model::Render(Camera* camera_) {
	glUseProgram(shaderProgram);
	for (auto m : subMeshes) {
		m->Render(camera_, GetTransform());
	}
}

void Model::AddMesh(Mesh* mesh_) {
	subMeshes.push_back(mesh_);
}

void Model::SetPosition(glm::vec3 position_) {
	Position = position_;
}
void Model::SetAngle(float angle_) {
	Angle = angle_;
}
void Model::SetRotation(glm::vec3 rotation_) {
	Rotation = rotation_;
}
void Model::SetScale(glm::vec3 scale_) {
	Scale = scale_;
}

glm::vec3 Model::GetPosition() const{
	return Position;
}
float Model::GetAngle() const{
	return Angle;
}
glm::vec3 Model::GetRotation() const{
	return Rotation;
}
glm::vec3 Model::GetScale() const{
	return Scale;
}

glm::mat4 Model::GetTransform() {
	glm::mat4 Model;

	Model = glm::translate(Model, Position);
	Model = glm::rotate(Model, Angle, Rotation);
	Model = glm::scale(Model, Scale);

	return Model;
}