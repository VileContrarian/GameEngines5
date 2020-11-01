#include "GameObject.h"



GameObject::GameObject(Model* model_) : model(nullptr) {
	model = model_;
}

GameObject::~GameObject() {
	if (model) {
		delete model;
	}
	model = nullptr;

	components.clear();
}

void GameObject::Render(Camera* camera_) {
	if (model) {
		model->Render(camera_);
	}
}

void GameObject::Update(const float deltaTime_) {
	if (model) {
		model->SetAngle(model->GetAngle() + 0.005f);
	}

	for (int i = 0; i <= components.size(); ++i) {
		if (components[i]) {
			components[i]->OnUpdate(deltaTime_);
		}
	}
}

