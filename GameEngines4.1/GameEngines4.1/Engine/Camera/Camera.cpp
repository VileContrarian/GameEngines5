#include "Camera.h"
#include "../Core/CoreEngine.h"

Camera::Camera(): Position(glm::vec3()) {
	FOV = 45.0f;
	Forwards = glm::vec3(0.0f,0.0f,1.0f);
	Up = glm::vec3(0.0f, 1.0f, 0.0f);
	WorldUp = Up;
	NearPlane = 2.0f;
	FarPlane = 50.0f;
	Yaw = -90.0f;
	Pitch = 0.0f;

	Perspective = glm::perspective(FOV, CoreEngine::GetInstance()->GetWindowSize().x/ CoreEngine::GetInstance()->GetWindowSize().y, NearPlane, FarPlane);
	Ortho = glm::ortho(0.0f, CoreEngine::GetInstance()->GetWindowSize().x, 0.0f, CoreEngine::GetInstance()->GetWindowSize().y, -1.0f, 1.0f);

	UpdateCameraVecs();
}
Camera::~Camera() {

}

void Camera::SetPosition(glm::vec3 position_) {
	Position = position_;
	UpdateCameraVecs();
}
void Camera::SetRotation(float yaw_, float pitch_) {
	Yaw = yaw_;
	Pitch = pitch_;
	UpdateCameraVecs();
}

glm::mat4 Camera::GetView() const {
	return glm::lookAt(Position, Position + Forwards, Up);
}
glm::mat4 Camera::GetPerspective() const {
	return Perspective;
}
glm::mat4 Camera::GetOrtho() const {
	return Ortho;
}

void Camera::UpdateCameraVecs() {
	Forwards.x = cos(glm::radians(Yaw)) * cos(glm::radians(Pitch));
	Forwards.y = sin(glm::radians(Pitch));
	Forwards.z = sin(glm::radians(Yaw))* cos(glm::radians(Pitch));

	Forwards = glm::normalize(Forwards);

	Right = glm::normalize(glm::cross(Forwards, WorldUp));

	Up = glm::normalize(glm::cross(Right, Forwards));
}