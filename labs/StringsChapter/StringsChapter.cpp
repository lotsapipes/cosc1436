
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



/*
void ClassifyChars() {
    std::cout << std::setw(7) << "Value " << std::setw(7) << "Letter? " << std::endl;
    std::cout << std::setw(7) << "----- " << std::setw(7)  << std::endl;
    std::cout << std::setw(7) << "Is it a digit? " << std::setw(7) << std::endl;
    std::cout << std::setw(7) << "Is it a whitespace? " << std::setw(7) << std::endl;
    std::cout << std::setw(7) << "Is it alphanumeric? " << std::setw(7)  << std::endl;
    std::cout << std::setw(7) << "Is it an uppercase letter? " << std::setw(7)  << std::endl;
    std::cout << std::setw(7) << "Is it a lowercase letter? " << std::setw(7)  << std::endl;

    do {
        char input;
        std::cin >> input;
        std::cout << std::setw(7) << input << (isalpha(input) ? "Y" : "N") << std::endl;
        if (input == 'Q' || input == 'q')
            break;

    } while (true);
}
*/

//the code below is written in a "Fail Fast Philosophy" style, which means that it will check for invalid input and return false immediately if it finds any. 
// This is a common approach to writing functions that validate input, as it allows the function to quickly exit if the input is not valid, rather than continuing to check for other conditions that may not be relevant if the input is already invalid. 
// In this case, the function checks if the input string is empty or if the first character is not a letter or an underscore, and returns false if either of those conditions is true. Then it checks each character in the string to see if it is not a letter, digit, or underscore, and returns false if it finds any such character. 
// If all characters are valid, it returns true at the end.
//          the way BOUNDS CHECKING works below is that it checks the first character separately
// to ensure that it is a valid starting character for an identifier (a letter or underscore), 
// and then it checks the rest of the characters in the string to ensure that they are all valid characters for an 
// identifier (letters, digits, or underscores).



//random junk we threw together.
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


void CStringDemo() {
    char letterGrades[5] = {'A', 'B', 'C', 'D', 'F'};
    char* pLetterGrades = letterGrades; // pLetterGrades is a pointer to the first element of the letterGrades array
    char const* pConstLetterGrades = letterGrades; // pConstLetterGrades is a pointer to a constant character, which means that the characters it points to cannot be modified through this pointer

    char const* name = "regular name C++"; // name is a pointer to a constant character, which means that the characters it points to cannot be modified through this pointer
    char fixedName[] = "fixed name C++"; // fixedName is an array of characters that is initialized

    int len = strlen(fixedName);

    char name1[100]; // name is an array of characters that can hold up to 100 characters
    char name2[200]; // name is an array of characters that can hold up to 200 characters


    // actually, the 2 functions below are not really "safe" because they do not perform bounds checking, which means that if name1 contains more than 100 characters, it could cause a buffer overflow when copying to name2.
    // fixed in the early 2000s? 
    strcpy_s(name2, name1); // copies the contents of name1 into name2, assuming that name2 has enough space to hold the contents of name1
    strncpy_s(name2, name1, 100); // copies up to 100 characters from name1 into name2, ensuring that name2 is null-terminated if name1 is longer than 100 characters
    strncpy_s(name2, 200, name1, 100); // copies up to 100 characters from name1 into name2, ensuring that name2 is null-terminated and that it does not exceed the size of name2 (200 characters)

    strcat_s(name2, name1); // concatenates the contents of name1 to the end of name2, assuming that name2 has enough space to hold the combined contents of name2 and name1
    strncat_s(name2, 200, name1, 100); // concatenates up to 100 characters from name1 to the end of name2, ensuring that name2 is null-terminated and that it does not exceed the size of name2 (200 characters)

    int areEqual = _stricmp(name1, name2); // compares name1 and name2 in a case-insensitive manner, returning 0 if they are equal, a positive value if name1 is greater than name2, or a negative value if name1 is less than name2
    areEqual = strcmp(name2, name1); // compares name2 and name1 in a case-sensitive manner, returning 0 if they are equal, a positive value if name2 is greater than name1, or a negative value if name2 is less than name1

    char fullName[] = "Bob Miller"; //haha this brings back some ancient memories ha
    char* pSpace = strstr(fullName, " "); // pSpace is a pointer to the first occurrence of the space character in fullName, or nullptr if the space character is not found
    if (pSpace)
    {
        std::cout << "Last name = " << pSpace << std::endl; // prints the last name, which is the substring starting from the space character
    } else {
        std::cout << "No space found in fullName (no last name)" << std::endl; // prints a message if no space character is found in fullName
    }

    char number[] = "1234";

    do {
        std::cin >> number;


        // atof is a function that converts a string to a floating-point number (double) 
        // atoi is a function that converts a string to an integer (int).
        // atol is a function that converts a string to a long integer (long), while atoll is a function that converts a string to a long long integer (long long).

        char* endPtr = nullptr;
        int valueEntered = atoi(number);
        std::cout << "Value entered: " << valueEntered << std::endl;
        if (valueEntered == 0)
            break;
        

    } while (true);

    std::cout << letterGrades << std::endl;
    std::cout << name << std::endl;
}


void CppStringDemo() {

    std::string name = "Bob";

    int len = name.length(); // returns the length of the string (number of characters)

    std::string value1 = "Hello", value2 = "hello";
    bool areEqual = (value1 == value2); // compares value1 and value2 for equality, returning true if they are equal and false otherwise (case-sensitive)
    areEqual = _stricmp(value1.c_str(), value2.c_str()) == 0; // compares value1 and value2 for equality in a case-insensitive manner, returning true if they are equal and false otherwise

    name = "Sue"; // assigns a new value to the name string

    name += " Miller"; // concatenates " Miller" to the end of the name string
    name.append(" Senior Junsies"); // appends " Senior Junsies" to the end of the name string

    name = ""; // assigns an empty string to name, effectively clearing its contents
    name.clear(); // clears the contents of the name string, making it an empty string (equivalent to name = "") 
    //can't remember how many of these buffer clearing things i've found in this course

    int index = name.find(" ", 0);
    if (index >= 0)
    {
        std::string firstName = name.substr(0, index); // extracts the substring from the beginning of name up to (but not including) the space character, and assigns it to firstName
        std::string lastName = name.substr(index); // extracts the substring from the space character to the end of name, and assigns it to lastName
        std::cout << "First name: " << firstName << std::endl; // prints the first name
        std::cout << "Last name: " << lastName << std::endl; // prints the last name
    }



}





int main(){
    std::string programName = "StringDemo";
    //removed this thing because i struggle to type and listen at the same time.
    //ClassifyChars();

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
