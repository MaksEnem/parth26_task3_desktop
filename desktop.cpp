#include <iostream>
#include <vector>

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
	int initialCoordinates[2] = { 0, 0 };

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

	void SetResize(Monitor screenSettings)
	{

		do 
		{

			std::cout << "Window width cannot be larger " << screenSettings.abscissa - initialCoordinates[0] << std::endl;
			std::cout << "Enter window width: ";
			std::cin >> coordinateX;
			columnsWindow = coordinateX;

		} while ((columnsWindow < 0) || (columnsWindow > (screenSettings.abscissa - initialCoordinates[0])));

		do
		{

			std::cout << "The height of the window cannot be greater " << screenSettings.ordinate - initialCoordinates[1] << std::endl;
			std::cout << "Enter window height: ";
			std::cin >> coordinateY;
			linesWindow = coordinateY;

		} while ((linesWindow < 0) || (linesWindow > (screenSettings.ordinate - initialCoordinates[1])));
		
		std::cout << "The window width is: " << columnsWindow << std::endl;
		std::cout << "The window height is: " << linesWindow << std::endl;

	}

	void PrintDisplay(Monitor screenSettings)
	{


		for (int i = 0; i < 50; ++i)
		{
			for (int j = 0; j < 80; ++j) {

				if ((initialCoordinates[0] <= j && initialCoordinates[1] <= i) && (j <= (initialCoordinates[0] + columnsWindow)) && (i <= initialCoordinates[1] + linesWindow))
				{

					std::cout << "1" << " ";

				}
				else
				{

					std::cout << "O" << " ";

				}

				/*if (columnsWindow == j && linesWindow == i)
				{

					std::cout << "1" << " ";

				}
				else
				{

					std::cout << "O" << " ";

				}*/



			}
			std::cout << std::endl;
		}
	}

};

int main() 
{

	Windows windowSettings;
	Monitor monitorSettings;

	std::string command;

	do {
		std::cout << "Enter command: ";		
		std::cin >> command;
		//command = "display";
		if (command == "move")
		{

			windowSettings.SetVector(monitorSettings);

		}
		else if (command == "resize")
		{

			windowSettings.SetResize(monitorSettings);

		}
		else if(command == "display")
		{

			windowSettings.PrintDisplay(monitorSettings);

		}

	} while (command != "close");
	return 0;
}