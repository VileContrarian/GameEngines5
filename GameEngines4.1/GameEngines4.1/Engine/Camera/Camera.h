#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Camera {
public:
	Camera();
	~Camera();

	void SetPosition(glm::vec3 position_);
	void SetRotation(float yaw_, float pitch_);

	glm::mat4 GetView() const;
	glm::mat4 GetPerspective() const;
	glm::mat4 GetOrtho() const;
private:
	void UpdateCameraVecs();
	
	glm::vec3 Position, Forwards, Up, Right, WorldUp;
	glm::mat4 Perspective, Ortho;
	float FOV, Yaw, Pitch, NearPlane, FarPlane;

};

#endif // !CAMERA_H