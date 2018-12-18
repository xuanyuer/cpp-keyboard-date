#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>

#include "Keyboard.hpp"

std::string keyboard::readString (const std::string & prompt)
{
	std::string input;

	std::cout << prompt;
	std::getline (std::cin, input);

	return input;
}

char keyboard::readChar (const std::string & prompt)
{
	std::string input = readString (prompt);

	while (input.size () != 1)
	{
		std::cout << "*** Please enter a character ***" << std::endl;
		input = readString (prompt);
	}

	return input [0];
}

int keyboard::readInt (const std::string & prompt)
{
	std::string input = readString (prompt);

	while (!valid <int> (input))
	{
		std::cout << "*** Please enter an integer ***" << std::endl;
		input = readString (prompt);
	}

	return atoi (input.c_str ());
}

template <size_t length>
int keyboard::menuInput (std::string title, std::string (& menu) [length])
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

	return choice;
}

template <typename T>
bool keyboard::valid (const std::string input)
{
	std::istringstream iss (input);

	T t;
	iss >> t;

	return iss.eof () && !iss.fail ();
}

void keyboard::printLine (const int size, const char pattern)
{
	for (int i = 0; i < size; ++ i)

		std::cout << pattern;
	
	std::cout << std::endl;
}