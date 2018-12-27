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

	int menu_input (const std::string & prompt, std::string & title, const std::string menu [], int menu_length)
	{
		/*
		 * prompt	-	The prompt for user input
		 * title	-	The title of the menu
		 * menu		-	A array of strings containing the menu options
		 * length	-	The size of the menu array
		 */
		std::transform (title.begin (), title.end (), title.begin (), ::toupper);

		print_line (80, '=');
		std::cout << title << std::endl;
		print_line (80, '-');

		for (int i = 0; i < menu_length; ++ i) std::cout << '[' << i + 1 << "] " << menu [i] << std::endl;
		std::cout << "[0] Quit" << std::endl;
		
		print_line (80, '-');

		int choice = read_int (prompt);
		while (choice < 0 || choice > menu_length)
		{
			print_message ("Invalid choice");
			choice = read_int (prompt);
		}

		std::cout << std::endl;
		return choice;
	}

	int menu_input (std::string & title, const std::string menu [], int menu_length)
	{
		return menu_input ("Your choice : ", title, menu, menu_length);
	}

	int menu_input (const std::string & prompt, std::string & title, const std::vector <std::string> & menu)
	{
		return menu_input (prompt, title, & menu [0], menu.size ());
	}

	int menu_input (std::string & title, const std::vector <std::string> & menu)
	{
		return menu_input ("Your choice : ", title, menu);
	}

	// ------------------------------ Read Methods ------------------------------

	char read_char (const std::string & prompt)
	{
		std::string input = read_string (prompt);

		while (input.size () != 1)
		{
			print_error (CHAR);
			input = read_string (prompt);
		}

		return input [0];
	}

	double read_double (const std::string & prompt)
	{
		std::string input = read_string (prompt);

		while (!valid <double> (input))
		{
			print_error (DOUBLE);
			input = read_string (prompt);
		}

		return std::atof (input.c_str ());
	}

	int read_int (const std::string & prompt)
	{
		std::string input = read_string (prompt);

		while (!valid <int> (input))
		{
			print_error (INTEGER);
			input = read_string (prompt);
		}

		return std::atoi (input.c_str ());
	}

	long read_long (const std::string & prompt)
	{
		std::string input = read_string (prompt);

		while (!valid <int> (input))
		{
			print_error (LONG);
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

	// ------------------------------ Print Methods ------------------------------

	void print_line (const int size, const char pattern)
	{
		for (int i = 0; i < size; ++ i) std::cout << pattern;
		std::cout << std::endl;
	}

	void print_error (Primitive primitive)
	{
		std::string prefix = "Please enter a ";
		switch (primitive)
		{
			case CHAR:	  print_message (prefix + "character"); return;
			case DOUBLE:  print_message (prefix + "double");	return;
			case INTEGER: print_message (prefix + "integer");	return;
			case LONG:	  print_message (prefix + "long");		return;
		}
	}

	void print_message (const std::string & message)
	{
		std::cout << "*** " << message << " ***" << std::endl;
	}
}