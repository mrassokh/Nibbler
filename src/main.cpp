// #include <dlfcn.h>
// #include <iostream>
// #include "IEntity.hpp"
#include "../includes/nibbler.hpp"
#include "../includes/CustomExeptions.hpp"



int main(int ac, char **av)
{
	try{
		if (ac != 3){
			throw CustomExeption("Wrong number of input arguments!!!");
		}
	} catch (std::exception& e)	{
		std::cerr << "exception caught: " << e.what() << std::endl;
		return 0;
	}

	Nibbler::Instance(std::stoi(av[1]),std::stoi(av[2])).processing();

    return 0;
}
