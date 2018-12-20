/*
 * File Name   : Keybaord.hpp
 * Author      : Er Xuan Yu
 * Description : Header file for Keyboard.cpp, a simple console input handler for C++
 */

namespace keyboard
{
	std::string	readString	(const std::string & prompt);
	char		readChar	(const std::string & prompt);
	int 		readInt		(const std::string & prompt);
	double 		readDouble	(const std::string & prompt);
	int			menuInput	(std::string title, std::string menu [], int length);
	void		printLine	(const int length, const char pattern);
}