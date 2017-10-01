// CerealTest.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <cereal/archives/xml.hpp>
#include <cereal/types/polymorphic.hpp>

#include <iostream>
#include <fstream>

#include "TestClass.h"
#include "Container.h"



int main()
{
	int choice;
	std::cout << "0. Add Values or 1. Load Old and Add 2. Run" << std::endl;
	std::cin >> choice;

	if (choice == 0) {
		auto container = std::make_unique<Container>();
		int cc;

		do {
			std::cout << "0. Multiply Compnent or 1. SayHello Component 2. Exit" << std::endl;
			std::cin >> cc;

			if (cc == 0) {
				int x, y;
				std::cout << "Enter X Value: ";
				std::cin >> x;
				std::cout << std::endl;
				std::cout << "Enter Y Value: ";
				std::cin >> y;
				std::cout << std::endl;
				std::shared_ptr<Component> component1 = std::make_shared<Multiply>(x, y);
				container->addComponents(component1);
			}
			else if (cc == 1) {
				std::string name;
				std::cout << "Say Hello To: ";
				std::cin >> name;
				std::cout << std::endl;

				std::shared_ptr<Component> component2 = std::make_shared<SayHello>(name);

				container->addComponents(component2);
			}
		} while (cc != 2);
		

		

		std::ofstream os("level.bin");
		cereal::BinaryOutputArchive oarchive(os);
		oarchive(container);

	}
	else if (choice == 1) {
		std::ifstream is("level.bin");
		cereal::BinaryInputArchive iarchive(is);
		std::unique_ptr<Container> container;

		iarchive(container);
		int cc;

		do {
			std::cout << "0. Multiply Compnent or 1. SayHello Component 2. Exit" << std::endl;
			std::cin >> cc;

			if (cc == 0) {
				int x, y;
				std::cout << "Enter X Value: ";
				std::cin >> x;
				std::cout << std::endl;
				std::cout << "Enter Y Value: ";
				std::cin >> y;
				std::cout << std::endl;
				std::shared_ptr<Component> component1 = std::make_shared<Multiply>(x, y);
				container->addComponents(component1);
			}
			else if (cc == 1) {
				std::string name;
				std::cout << "Say Hello To: ";
				std::cin >> name;
				std::cout << std::endl;

				std::shared_ptr<Component> component2 = std::make_shared<SayHello>(name);

				container->addComponents(component2);
			}
		} while (cc != 2);




		std::ofstream os("level.bin");
		cereal::BinaryOutputArchive oarchive(os);
		oarchive(container);
	}
	else
	{
		std::ifstream is("level.bin");
		cereal::BinaryInputArchive iarchive(is);
		std::unique_ptr<Container> container;

		iarchive(container);

		container->runComponents();
	}

	system("pause");
	return 0;
}

