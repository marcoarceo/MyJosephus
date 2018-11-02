#pragma once
#include <fstream>
#include "TestListMyJosephus.h"
#include "TestVectorMyJosephus.h"
#include <string>
#include <cstdlib>
#include <chrono>
using namespace std;
using namespace std::chrono;

class Wrapper
{

public:

	void runApp()
	{
		int option = 0;
		bool flag = true;

		while (flag)
		{
			do
			{
				option = determineOption(); // Gets the users option
				switch (option) // Runs the program depending on the users option
				{
				case 1: // Runs ListMyJosephus
					runList.runListGame();
					break;

				case 2: // Runs VectorMyJosephus
					runVector.runVectorGame();
					break;

				case 3: // Exit Program
					flag = false; // Sets the flag to false thus making the program end
					break;
				}
			} while (option > 0 && option < 3);
		}
	}

private:
	TestListMyJosephus runList;
	TestVectorMyJosephus runVector;

	void displayMenu()
	{ // Displays the options for the user to choose
		cout << "1.) Run ListMyJosephus" << endl;
		cout << "2.) Run VectorMyJosephus" << endl;
		cout << "3.) Exit the program" << endl;
	}

	int getOption()
	{ // Gathers the users choice 
		int option = 0, status = 0;
		cout << "\nEnter your option: ";
		cin >> option;
		status = option;
		if ((status = 0))
		{
			cout << "Failed at reading the option" << endl;
		}
		return option;
	}

	int determineOption()
	{ // Determines if the option is valid, if not, the program asks again
		int option = 0;

		do
		{
			displayMenu();
			option = getOption();
		} while ((option < 1) || (option > 3));
		return option;
	}

};