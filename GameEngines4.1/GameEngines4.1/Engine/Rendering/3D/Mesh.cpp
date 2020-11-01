#include "Mesh.h"

Mesh::Mesh(std::vector<Vertex>* vertexlist_, GLuint shaderprogram_, GLuint textureID_) : vertexlist(std::vector<Vertex>()), VAO(0), VBO(0), ModelLock(0), ViewLock(0), ProjLock(0), TextureLock(0) {
	vertexlist.reserve(100);
	vertexlist = *vertexlist_;

	shaderprogram = shaderprogram_;
	TextureID = textureID_;
	GenerateBuffers();
}
Mesh::~Mesh() {
	vertexlist.clear();
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
}
void Mesh::Render(Camera* camera_,glm::mat4 transform_) {
	glUniform1i(TextureLock, 0);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, TextureID);

	glUniformMatrix4fv(ModelLock, 1, GL_FALSE, glm::value_ptr(transform_));
	glUniformMatrix4fv(ViewLock, 1, GL_FALSE, glm::value_ptr(camera_->GetView()));
	glUniformMatrix4fv(ProjLock, 1, GL_FALSE, glm::value_ptr(camera_->GetPerspective()));

	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, vertexlist.size());
	glBindVertexArray(0);
	glBindTexture(GL_TEXTURE_2D, 0);
}
void Mesh::GenerateBuffers() {
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	glBufferData(GL_ARRAY_BUFFER, vertexlist.size() * sizeof(Vertex), &vertexlist[0], GL_STATIC_DRAW);

	//POSISTION
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)0);

	//NORMAL
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, Norm));

	//TEXT COORDS
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, CoOrd));

	//Colour
	glEnableVertexAttribArray(3);
	glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, Colour));

		glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	ModelLock = glGetUniformLocation(shaderprogram, "model");
	ViewLock = glGetUniformLocation(shaderprogram, "view");
	ProjLock = glGetUniformLocation(shaderprogram, "proj");
	TextureLock = glGetUniformLocation(shaderprogram, "inputText");
}