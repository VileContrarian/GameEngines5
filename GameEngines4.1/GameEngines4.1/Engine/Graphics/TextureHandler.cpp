#include "TextureHandlerr.h"

std::unique_ptr<TextureHandler> TextureHandler::textureInstance = nullptr;

std::vector<Texture*> TextureHandler::Textures = std::vector<Texture*>();

TextureHandler::TextureHandler() {
	Textures.reserve(10);
}
TextureHandler::~TextureHandler() {
	OnDestroy();
}

TextureHandler* TextureHandler::GetInstance() {
	if (textureInstance.get() == nullptr) {
		textureInstance.reset(new TextureHandler);
	}
	return textureInstance.get();
}
void TextureHandler::CreateTexture(const std::string& textureName_, const std::string& textureFilePath_) {
	Texture* t = new Texture();
	SDL_Surface* surface = nullptr;
	surface = IMG_Load(textureFilePath_.c_str());

	if (surface == nullptr) {
		Debug::Error("Surface failed to load " + textureName_, "TextureHandler.cpp", __LINE__);

		delete t;
		t = nullptr;

		return;
	}

	glGenTextures(1, &t->TextureID);
	glBindTexture(GL_TEXTURE_2D, t->TextureID);

	int mode = surface->format->BytesPerPixel == 4 ? GL_RGBA : GL_RGB;

	glTexImage2D(GL_TEXTURE_2D, 0, mode, surface->w, surface->h, 0, mode, GL_UNSIGNED_BYTE, surface->pixels);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);

	glGenerateMipmap(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, 0);

	t->Width = surface->w;
	t->height = surface->h;
	t->TextureName = textureName_;

	Textures.push_back(t);

	SDL_FreeSurface(surface);
	surface = nullptr;
}
const GLuint TextureHandler::GetTexture(const std::string& textureName_) {
	for (auto t : Textures)
	{
		if (t->TextureName == textureName_) {
			return t->TextureID;
		}
	}
	return 0;
}
const Texture* TextureHandler::GetTextureData(const std::string& textureName_) {
	for (auto t : Textures)
	{
		if (t->TextureName == textureName_) {
			return t;
		}
	}
	return nullptr;
}

void TextureHandler::OnDestroy() {
	if (Textures.size() > 0) {
		for (auto t : Textures)
		{
			glDeleteTextures(sizeof(GLuint), &t->TextureID);
			delete t;
			t = nullptr;
		}
		Textures.clear();
	}
}
