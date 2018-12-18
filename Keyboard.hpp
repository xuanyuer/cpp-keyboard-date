namespace keyboard
{
	std::string	readString	(const std::string & prompt);
	char		readChar	(const std::string & prompt);
	int 		readInt		(const std::string & prompt);
	double 		readDouble	(const std::string & prompt);

	template <size_t length>
	int menuInput (std::string title, std::string (& menu) [length]);

	template <typename T>
	bool valid (const std::string input);
	
	void printLine (const int length, const char pattern);
}