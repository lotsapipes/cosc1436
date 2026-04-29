
//fresh creation of new chapter
//hopefully it's named right because this is kinda permanennt

#include <iostream>
#include <iomanip>
#include <string>
#include <cctype> // for character classification functions like isalpha(), isdigit(), etc.

//"Char classify functions
// int func(int ch); this means that the function takes an int as a parameter and returns an int as a result. The parameter ch is typically used to represent a character, and the function is designed to classify that character in some way. The specific classification performed by the function would depend on its implementation, but common classifications include checking if the character is a letter, digit, whitespace, etc. The function would return an integer value that indicates the result of the classification, such as 1 for true and 0 for false.
// isalpha() - checks if the character is a letter (either uppercase or lowercase)
// isdigit() - checks if the character is a digit (0-9)
// 

// below is a function that will classify characters using the isalpha(), isdigit(), and other similar functions. It will read characters from the user until they enter 'Q' or 'q', and for each character, it will print whether it is a letter or not.
// those functions are the following:
// isalpha()
// isdigit()
// isspace() - checks if the character is a whitespace character (space, tab, newline, etc.)
// isalnum() - checks if the character is either a letter or a digit
// isupper() - checks if the character is an uppercase letter (i've used these already)
// islower() - checks if the character is a lowercase letter (i've used these already)
// also the tolower() and toupper() functions can be used to convert characters to lowercase or uppercase, respectively. 
// These functions take a character as input and return the converted character. For example, tolower('A') would return 'a', 
// and toupper('b') would return 'B'. These functions can be useful for normalizing input or for performing case-insensitive comparisons.
void ClassifyChars() {
    std::cout << std::setw(7) << "Value " << std::setw(7) << "Letter? " << std::endl;
    std::cout << std::setw(7) << "----- " << std::setw(7) << "------- " << std::endl;
    std::cout << std::setw(7) << "Is it a digit? " << std::setw(7) << "------- " << std::endl;
    std::cout << std::setw(7) << "Is it a whitespace? " << std::setw(7) << "------- " << std::endl;
    std::cout << std::setw(7) << "Is it alphanumeric? " << std::setw(7) << "------- " << std::endl;
    std::cout << std::setw(7) << "Is it an uppercase letter? " << std::setw(7) << "------- " << std::endl;
    std::cout << std::setw(7) << "Is it a lowercase letter? " << std::setw(7) << "------- " << std::endl;

    do {
        char input;
        std::cin >> input;
        std::cout << std::setw(7) << input << (isalpha(input) ? "Y" : "N") << std::endl;
        if (input == 'Q' || input == 'q')
            break;

    } while (true);
}


//the code below is written in a "Fail Fast Philosophy" style, which means that it will check for invalid input and return false immediately if it finds any. 
// This is a common approach to writing functions that validate input, as it allows the function to quickly exit if the input is not valid, rather than continuing to check for other conditions that may not be relevant if the input is already invalid. 
// In this case, the function checks if the input string is empty or if the first character is not a letter or an underscore, and returns false if either of those conditions is true. Then it checks each character in the string to see if it is not a letter, digit, or underscore, and returns false if it finds any such character. 
// If all characters are valid, it returns true at the end.
//          the way BOUNDS CHECKING works below is that it checks the first character separately
// to ensure that it is a valid starting character for an identifier (a letter or underscore), 
// and then it checks the rest of the characters in the string to ensure that they are all valid characters for an 
// identifier (letters, digits, or underscores).
bool IsValidIdentifier(std::string const& value)
{
        if (value.empty() || !isalpha(value[0]) && value[0] != '_')
        return false;
    for (char ch : value) {
        if (!isalnum(ch) && ch != '_')
            return false;
    }
    return true;
}

int main(){
    std::string programName = "StringDemo";
    ClassifyChars();

    //ansi - 1 byte per character, 256 characters
    char ansiChar = 'A';
    for (int index = 0; index < 10; ++index)
        std::cout << programName[index] << std::endl;

        //unicode - 2 bytes per character, 65536 characters;
        wchar_t unicodeChar = 'A';
    std::wstring programNameUnicode = L"StringDemo";
    for (int index = 0; index < 10; ++index)
        std::wcout << programNameUnicode[index] << std::endl;

    //other vaiants of unicode:
    //char8_t - 1 byte per character, UTF-8 encoding
    char16_t utf16;
    char32_t utf32; 
    //cin is an ANSI input stream, wcin is a unicode input stream
    std::wstring nameUnicode;
    std::wcin >> nameUnicode;

    //IMPORTANT wchar is a Microsoft-Only solution, so if you want to be cross-platform, use "char16_t or char32_t instead"
    //If using g++ vs Microsoft stuff...actually this sounds pretty janky trying to be cross-platform, read on it later

    return 0;
}
//these are alt + keys:
//ABCabc
