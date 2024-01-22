#include <iostream>

class Screen
{



};

class Monitor
{



};

int main() 
{

	std::string command;

	do {
		std::cout << "Enter command: ";
		std::cin >> command;

		if (command == "move")
		{

			std::cout << "move" << std::endl;

		}
		else if (command == "resize")
		{

			std::cout << "resize" << std::endl;

		}
		else if(command == "display")
		{

			std::cout << "display" << std::endl;

		}

	} while (command != "close");
	return 0;
}