/*
 * File Name   : Keybaord.hpp
 * Author      : xyer24@outlook.com
 * Description : Header file for Keyboard.cpp, a simple console input handler for C++
 */

#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <vector>

namespace keyboard
{
	enum Primitive
	{
		CHAR, DOUBLE, INTEGER, LONG
	};

	// Menu Methods
	int menu_input (const std::string & prompt, std::string & title, const std::string menu [], int menu_length);
	int menu_input (std::string & title, const std::string menu [], int menu_length);
	int menu_input (const std::string & prompt, std::string & title, const std::vector <std::string> & menu);
	int menu_input (std::string & title, const std::vector <std::string> & menu);

	// Read Methods
	char		read_char	(const std::string & prompt);
	double 		read_double	(const std::string & prompt);
	int 		read_int	(const std::string & prompt);
	long		read_long	(const std::string & prompt);
	std::string	read_string	(const std::string & prompt);

	// Print Methods
	void print_line    (const int length, const char pattern);
	void print_error   (const Primitive primitive);
	void print_message (const std::string & message);

	// Array Length Method
	template <typename T, std::size_t length>
	std::size_t get_array_length (const T (&) [length])
	{
		/* Template for obtaining size of an array, useful for menu input
		 * For instance, you may use the menu_input () method together with the template:
		 * 
		 * 		std::string menu [] = {"Option 1", "Option 2", "Option 3"};
		 * 		std::size_t length = get_array_length (menu);
		 * 		int choice = menu_input ("Menu Title", menu, length);
		 * 		// Do something with choice
		 */
		return length;
	}
}

#endif