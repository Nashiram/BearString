#include <iostream>
#include "BearEngine.h"

int main()
{
	bear::string name = "Andreius";

	name.clear();

	//std::cout << name << std::endl;

	if(name.isEmpty())
		std::cout << "DA" << std::endl;

	if (name.isNull())
		std::cout << "da" << std::endl;



	
	std::cin.get();
}