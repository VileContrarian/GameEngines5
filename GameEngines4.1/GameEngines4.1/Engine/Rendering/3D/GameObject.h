#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "Model.h"
#include "Component.h"
#include "..\..\Core\Debug.h"

class GameObject
{
public:
	GameObject(Model* model_);
	~GameObject();
	void Render(Camera* camera_);
	void Update(const float deltaTime_);

	template<typename T> void AddComponent();
	template<typename T> Component* GetComponent();
	template<typename T> void RemoveComponent();

private:
	Model* model;
	std::vector<Component*> components;

};

template<typename T>
inline void GameObject::AddComponent()
{
	T* t_;

	if (dynamic_cast<Component*>(t_)) {	
		if (GetComponent<t_>() == nullptr) {
			components.push_back(t_);
			t_->OnCreate(this); // ->OnCreate(this);

		}
	}
	else {
		Debug::Error("Template not a Component", "GameObject.h.cpp", __LINE__);
		delete t_;
		t_ = nullptr;
		return;
	}
}

template<typename T>
inline Component* GameObject::GetComponent()
{
	T* t_;
	for (int i = 0; i <= components.size(); ++i){
		if (components[i] == t_) {
			return components[i];
		}
	}

	return nullptr;
}

template<typename T>
inline void GameObject::RemoveComponent()
{
	T* t_;

	if (dynamic_cast<Component>(T)) {
		for (int i = 0; i <= components.size(); ++i) {
			if (components[i] == t_) {
				delete components[i];
				components[i] = nullptr;
				break;
			}
		}
	}
	else
	{
		Debug::Error("RemoveComponent not child of component", "GameObject.h.cpp", __LINE__);
		delete t_;
		t_ = nullptr;
		return;
	}


}

#endif GAMEOBJECT_H
