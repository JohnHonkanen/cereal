#pragma once
#include "cereal\cereal.hpp"
class AbstractClass
{
public:
	AbstractClass();
	~AbstractClass();

	template<class Archive>
	void serialize(Archive & archive) {

	}
};

