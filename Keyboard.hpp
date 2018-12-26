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
	// Menu Methods
	int  menu_input (std::string title, const std::string menu [], int length);
	int	 menu_input (std::string title, const std::vector <std::string> & menu);
	void print_line (const int length, const char pattern);

	// Read Methods
	char		read_char	(const std::string & prompt);
	double 		read_double	(const std::string & prompt);
	int 		read_int	(const std::string & prompt);
	long		read_long	(const std::string & prompt);
	std::string	read_string	(const std::string & prompt);

	/* Template for obtaining size of an array, useful for menu input
	 * For instance, you may use the menu_input () method together with the template:
	 * 
	 * 		std::string menu [] = {"Option 1", "Option 2", "Option 3"};
	 * 		std::size_t length = get_array_length (menu);
	 * 		int choice = menu_input ("Menu Title", menu, length);
	 * 		// Do something with choic
	 */
	template <typename T, std::size_t length>
	std::size_t get_array_length (const T (&) [length])
	{
		return length;
	}
}

#endif