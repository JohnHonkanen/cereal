#pragma once
#include <iostream>
#include <string>
#include <cereal/types/polymorphic.hpp>

class Component
{
public:
	virtual void doSomething() = 0;
	template<class Archive>
	void serialize(Archive & ar) {
	};
};

class Multiply : public Component {
	int x, y;

	public:
		Multiply() {

		}

		Multiply(int _x, int _y) {
			x = _x;
			y = _y;
		}

		template<class Archive>
		void serialize(Archive & ar)
		{
			ar(x, y);
		}

		void doSomething() {
			int z = x*y;
			std::cout << "Multiply Component: " << z << std::endl;
		}
};

class SayHello : public Component {
	std::string name;

public:
	SayHello() {

	}

	SayHello(std::string _name) {
		name = _name;
	}

	template<class Archive>
	void serialize(Archive & ar)
	{
		ar(name);
	}

	void doSomething() {
		std::cout << "Halo: " << name << std::endl;
	}
};

// Include any archives you plan on using with your type before you register it
// Note that this could be done in any other location so long as it was prior
// to this file being included
#include <cereal/archives/binary.hpp>

// Register DerivedClassOne
CEREAL_REGISTER_TYPE(Multiply);
CEREAL_REGISTER_TYPE(SayHello);

// Note that there is no need to register the base class, only derived classes
//  However, since we did not use cereal::base_class, we need to clarify
//  the relationship (more on this later)
CEREAL_REGISTER_POLYMORPHIC_RELATION(Component, Multiply)
CEREAL_REGISTER_POLYMORPHIC_RELATION(Component, SayHello)

