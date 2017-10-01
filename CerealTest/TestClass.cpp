#include "stdafx.h"
#include "TestClass.h"
#include <iostream>

void DerivedClassOne::sayType()
{
	std::cout << "DerivedClassOne" << std::endl;
}

void EmbarrassingDerivedClass::sayType()
{
	std::cout << "EmbarrassingDerivedClass. Wait.. I mean DerivedClassTwo!" << std::endl;
}