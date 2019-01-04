#include <iostream>
#include <string>

#include "Keyboard.hpp"

using std::cout;
using std::endl;

const std::string MENU [] =
{
    "Read Char",
    "Read Double",
    "Read Float",
    "Read Int",
    "Read Long",
    "Read Long Long",
    "Read String",
    "Menu Custom Prompt",
    "Menu Vector",
    "Menu Vector Custom Prompt"
};

void read_char ();
void read_double ();
void read_float ();
void read_int ();
void read_long ();
void read_long_long ();
void read_string ();
void menu_custom ();
void menu_vector ();
void menu_vector_custom ();

int main (int argc, char const ** argv)
{
    std::string title = "Keyboard Test";
    int choice = -1;

    while (choice != 0)
    {
        choice = keyboard::menu_input (title, MENU, keyboard::get_array_length (MENU));
        switch (choice)
        {
            case 1:  read_char ();          break;
            case 2:  read_double ();        break;
            case 3:  read_float ();         break;
            case 4:  read_int ();           break;
            case 5:  read_long ();          break;
            case 6:  read_long_long ();     break;
            case 7:  read_string ();        break;
            case 8:  menu_custom ();        break;
            case 9:  menu_vector ();        break;
            case 10: menu_vector_custom ();
        }
    }

    return 0;
}

void read_char ()
{
    char c = keyboard::read_char ("Enter a char : ");
    cout << "You entered " << c << endl;
}

void read_double ()
{
    double d = keyboard::read_double ("Enter a double : ");
    cout << "You entered " << d << endl;
}

void read_float ()
{
    float f = keyboard::read_float ("Enter a float : ");
    cout << "You entered " << f << endl;
}

void read_int ()
{
    int i = keyboard::read_int ("Enter an int : ");
    cout << "You entered " << i << endl;
}

void read_long ()
{
    long l = keyboard::read_long ("Enter a long : ");
    cout << "You entered " << l << endl;
}

void read_long_long ()
{
    long long ll = keyboard::read_long_long ("Enter a long long : ");
    cout << "You entered " << ll << endl;
}

void read_string ()
{
    std::string s = keyboard::read_string ("Enter a string : ");
    cout << "You entered " << s << endl;
}

void menu_custom ()
{
    std::string title = "Menu Custom";
    std::string arr [] = {"Option 1", "Option 2", "Option 3"};
    int choice = keyboard::menu_input ("Custom Prompt : ", title, arr, keyboard::get_array_length (arr));
    cout << "Returning to main menu..." << endl << endl;
}

void menu_vector ()
{
    std::string title = "Menu Vector";
    
    std::vector <std::string> vec;
    vec.push_back ("Option 1");
    vec.push_back ("Option 2");
    vec.push_back ("Option 3");

    int choice = keyboard::menu_input (title, vec);
    cout << "Returning to main menu..." << endl << endl;
}

void menu_vector_custom ()
{
    std::string title = "Menu Vector Custom";
    
    std::vector <std::string> vec;
    vec.push_back ("Option 1");
    vec.push_back ("Option 2");
    vec.push_back ("Option 3");
    
    int choice = keyboard::menu_input ("Custom Prompt : ", title, vec);
    cout << "Returning to main menu..." << endl << endl;
}