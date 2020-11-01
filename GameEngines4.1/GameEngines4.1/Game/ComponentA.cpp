#include "ComponentA.h"

ComponentA::ComponentA() : Component()
{
}

ComponentA::~ComponentA()
{
}

bool ComponentA::OnCreate(GameObject* parent_)
{
	parent = parent_;
	return true;
}

void ComponentA::OnUpdate(const float deltaTime_)
{
	std::cout << "Updating component A" << std::endl;
}
