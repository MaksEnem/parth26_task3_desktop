#include <iostream>

class Monitor
{
private:
	int columnsMonitor = 80;
	int linesMonitor = 50;

public:
	int abscissa = columnsMonitor;
	int ordinate = linesMonitor;

};

class Windows
{
private:
	int columnsWindow;
	int linesWindow;
	int initialCoordinates[2];

public:

	int coordinateX;
	int coordinateY;

	void SetVector(Monitor screenSettings)
	{
		do 
		{

			std::cout << "Enter X coordinate: ";
			std::cin >> coordinateX;			

		} while (coordinateX < 0 || coordinateX >= screenSettings.abscissa || coordinateX == screenSettings.abscissa - 1);
		
		do
		{

			std::cout << "Enter Y coordinate: ";
			std::cin >> coordinateY;			

		} while (coordinateY < 0 || coordinateY >= screenSettings.ordinate || coordinateY == screenSettings.ordinate - 1);

		initialCoordinates[0] = coordinateX;
		initialCoordinates[1] = coordinateY;

		std::cout << "Coordinates of the upper left corner of the window: " << coordinateX << " " << coordinateY << std::endl;
	};

	

};

int main() 
{

	/*for (int i = 0; i < 50; ++i) {
		for (int j = 0; j < 80; ++j) {

			std::cout << j << " ";

		}

		std::cout << std::endl;
	}*/

	Windows windowSettings;
	Monitor monitorSettings;

	std::string command;

	do {
		std::cout << "Enter command: ";
		std::cin >> command;

		if (command == "move")
		{

			windowSettings.SetVector(monitorSettings);

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