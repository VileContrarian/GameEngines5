#ifndef TEXTURE_HANDLER_H
#define TEXTURE_HANDLER_H

#include <memory>
#include <string>
#include <vector>
#include <SDL.h>
#include <SDL_image.h>
#include "..\Core\Debug.h"
#include <glew.h>

struct Texture {
	GLuint TextureID = 0;
	float Width = 0.0f;
	float height = 0.0f;
	std::string TextureName = "";
};

class TextureHandler {
public:
	TextureHandler(const TextureHandler&) = delete;
	TextureHandler(TextureHandler&&) = delete;
	TextureHandler& operator = (const TextureHandler&) = delete;
	TextureHandler& operator = (TextureHandler&&) = delete;

	static TextureHandler* GetInstance();
	void CreateTexture(const std::string& textureName_, const std::string& textureFilePath_);
	const GLuint GetTexture(const std::string& textureName_);
	const Texture* GetTextureData(const std::string& textureName_);

	void OnDestroy();
private:
	TextureHandler();
	~TextureHandler();

	static std::unique_ptr<TextureHandler> textureInstance;
	friend std::default_delete<TextureHandler>;
	static std::vector<Texture*> Textures;
};

#endif