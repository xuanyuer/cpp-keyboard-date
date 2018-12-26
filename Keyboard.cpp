/*
 * File Name   : Keybaord.cpp
 * Author      : xyer24@outlook.com
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

	// ------------------------------ Menu Methods ------------------------------

	int menu_input (std::string title, const std::string menu [], int length)
	{
		std::transform (title.begin (), title.end (), title.begin (), ::toupper);

		print_line (80, '=');
		std::cout << title << std::endl;
		print_line (80, '-');

		for (int i = 0; i < length; ++ i) std::cout << '[' << i + 1 << "] " << menu [i] << std::endl;
		std::cout << "[0] Quit" << std::endl;
		
		print_line (80, '-');

		int choice = read_int ("Your choice : ");
		while (choice < 0 || choice > length)
		{
			std::cout << "*** Invalid choice ***" << std::endl;
			choice = read_int ("Your choice : ");
		}

		std::cout << std::endl;
		return choice;
	}

	int menu_input (std::string title, const std::vector <std::string> & menu)
	{
		return menu_input (title, & menu [0], menu.size ());
	}

	void print_line (const int size, const char pattern)
	{
		for (int i = 0; i < size; ++ i) std::cout << pattern;
		std::cout << std::endl;
	}

	// ------------------------------ Read Methods ------------------------------

	char read_char (const std::string & prompt)
	{
		std::string input = read_string (prompt);

		while (input.size () != 1)
		{
			std::cout << "*** Please enter a character ***" << std::endl;
			input = read_string (prompt);
		}

		return input [0];
	}

	double read_double (const std::string & prompt)
	{
		std::string input = read_string (prompt);

		while (!valid <double> (input))
		{
			std::cout << "*** Please enter a double ***" << std::endl;
			input = read_string (prompt);
		}

		return std::atof (input.c_str ());
	}

	int read_int (const std::string & prompt)
	{
		std::string input = read_string (prompt);

		while (!valid <int> (input))
		{
			std::cout << "*** Please enter an integer ***" << std::endl;
			input = read_string (prompt);
		}

		return std::atoi (input.c_str ());
	}

	long read_long (const std::string & prompt)
	{
		std::string input = read_string (prompt);

		while (!valid <int> (input))
		{
			std::cout << "*** Please enter a long ***" << std::endl;
			input = read_string (prompt);
		}

		return std::atol (input.c_str ());
	}

	std::string read_string (const std::string & prompt)
	{
		std::string input;

		std::cout << prompt;
		std::getline (std::cin, input);

		return input;
	}
}