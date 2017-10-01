#pragma once
#include <vector>
#include <memory>
#include <cereal\types\vector.hpp>
#include "Component.h"
class Container
{
public:
	std::string name;
	std::vector<std::shared_ptr<Component>> components;

	Container();
	~Container();
	void addComponents(std::shared_ptr<Component> component) {
		components.push_back(component);
	}
	void runComponents() {
		for (std::shared_ptr<Component> &component : components) {
			component->doSomething();
		}
	}
	template<class Archive>
	void serialize(Archive & ar)
	{
		ar(CEREAL_NVP(name), CEREAL_NVP(components));
	}
};

