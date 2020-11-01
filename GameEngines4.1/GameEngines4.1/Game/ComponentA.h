#pragma once
#ifndef COMPONENTA_H
#define COMPONENTA_H

#include "../Engine/\Rendering/3D/Component.h"
#include <iostream>

//class Component;
class ComponentA : Component {
public:
	ComponentA();
	virtual ~ComponentA();

	virtual bool OnCreate(GameObject* parent_);
	virtual void OnUpdate(const float deltaTime_);
};

#endif // !COMPONENTA_H