/*
 * File Name   : Keybaord.cpp
 * Author      : Er Xuan Yu
 * Description : Implementation for keyboard.hpp, a simple console input handler for C++
 */

#include <algorithm>
#include <iostream>
#include <sstream>

#include "Keyboard.hpp"

namespace keyboard
{
	template <typename T>
	bool valid (const std::string input)
	{
		std::istringstream iss (input);

		T t;
		iss >> t;

		return iss.eof () && !iss.fail ();
	}

	std::string readString (const std::string & prompt)
	{
		std::string input;

		std::cout << prompt;
		std::getline (std::cin, input);

		return input;
	}

	char readChar (const std::string & prompt)
	{
		std::string input = readString (prompt);

		while (input.size () != 1)
		{
			std::cout << "*** Please enter a character ***" << std::endl;
			input = readString (prompt);
		}

		return input [0];
	}

	int readInt (const std::string & prompt)
	{
		std::string input = readString (prompt);

		while (!valid <int> (input))
		{
			std::cout << "*** Please enter an integer ***" << std::endl;
			input = readString (prompt);
		}

		return atoi (input.c_str ());
	}

	int menuInput (std::string title, std::string menu [], int length)
	{
		std::transform (title.begin (), title.end (), title.begin (), ::toupper);

		printLine (80, '=');
		std::cout << title << std::endl;
		printLine (80, '-');

		for (int i = 0; i < length; ++ i) std::cout << '[' << i + 1 << "] " << menu [i] << std::endl;
		std::cout << "[0] Quit" << std::endl;
		
		printLine (80, '-');

		int choice = readInt ("Your choice : ");
		while (choice < 0 || choice > length)
		{
			std::cout << "*** Invalid choice ***" << std::endl;
			choice = readInt ("Your choice : ");
		}

		std::cout << std::endl;
		return choice;
	}

	void printLine (const int size, const char pattern)
	{
		for (int i = 0; i < size; ++ i)

			std::cout << pattern;
		
		std::cout << std::endl;
	}
}