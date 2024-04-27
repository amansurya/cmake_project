/**
 *****************************************************************************************
 * @file
 * @details See header file for module overview.
 *
 *****************************************************************************************
 */
#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <algorithm>
/*
 *****************************************************************************************
 *		Prototypes
 *****************************************************************************************
 */


/*
 *****************************************************************************************
 *		Constants
 *****************************************************************************************
 */


/*
 *****************************************************************************************
 *		Globals
 *****************************************************************************************
 */

/*
 *****************************************************************************************
 *		Functions
 *****************************************************************************************
 */
int String_Basics( void )
{
{
	std::cout << "/************* String Basics ***********/" << std::endl;
	/** Ways to initialize the string **/
	char str1[] = "Hello";
	char str2[] = {'H', 'e', 'l', 'l', 'o', '\0'};
	char str3[6] = "Hello"; // note \0 is included in the size
	char str4[6] = {'H', 'e', 'l', 'l', 'o', '\0'};
	char *str5 = "Hell";
	char *str6 = new char[6];
	str6[0] = 'H';
	str6[1] = 'e';
	str6[2] = 'l';
	str6[3] = 'l';
	str6[4] = 'o';
	str6[5] = '\0';
	// print the size of the strings 1-6
	std::cout << "Size of str1: " << sizeof(str1) << std::endl;
	std::cout << "Size of str2: " << sizeof(str2) << std::endl;
	std::cout << "Size of str3: " << sizeof(str3) << std::endl;
	std::cout << "Size of str4: " << sizeof(str4) << std::endl;
	std::cout << "Size of str5: " << sizeof(str5) << std::endl; // expected size is 8 due to pointer
	std::cout << "Size of str6: " << sizeof(str6) << std::endl; // expected size is 8 due to pointer
	// print the strings 1-6
	std::cout << "Value of str1: " << str1 << std::endl;
	std::cout << "Value of str2: " << str2 << std::endl;
	std::cout << "Value of str3: " << str3 << std::endl;
	std::cout << "Value of str4: " << str4 << std::endl;
	std::cout << "Value of str5: " << str5 << std::endl;//note this is a pointer
	std::cout << "Value of str6: " << str6 << std::endl;
	// delete the memory allocated for str6
	delete[] str6;
	str6 = nullptr;
	char str7[] = {65,66,67,68,0,69,70};
	std::cout << "Value of str7: " << str7 << std::endl; // expeted to print ABCD
	// Till 0 is encountered, the string will be printed
	// If 0 is not encountered, it will print garbage values
	char str8[6] = {65,66,67,68,69,70};
	std::cout << "Value of str8: " << str8 << std::endl; // expeted to print ABCDEF and garbage
	char str9[7] = {65,66,67,68,69,70};
	std::cout << "Value of str9: " << str9 << std::endl; // expeted to print ABCDEF
	/**   taking input from user for assigning string  **/
	char str10[10];
	std::cout << "Enter a string to show space is termed as end: ";
	std::cin >> str10; // this will read only till the first space
	std::cout << "Value of str10: " << str10 << std::endl;
	std::cout << "Enter a string to test getline max 10: ";
	std::cin.getline(str10, 10); // this will read till the first newline character or till 9 characters
	std::cout << "Value of str10: " << str10 << std::endl;
	std::cout << "Enter a string to test get max 10: ";
	std::cin.get(str10, 10); // this will read till the first newline character or till 9 characters
	std::cin.ignore(); // to ignore the newline character this is problem with get not getline.
						// in get it will take enter into next buffer automatically and to avoid it we use ignore()

	char str11[4]; 
	std::cout << "Enter Hello: ";
	// std::cin >> str11 >> std::endl; std::endl is not required and not allowed in cin
	std::cin >> str11; //input "Hell0" 
	std::cout << "Value of str11: " << str11 << std::endl; 
	char *str12 = new char[5];
	std::cout << "Enter Hello: ";
	std::cin >> str12; //input "Hell0" //when iunput is more than 4 characters, behaviour is undefined
	std::cout << "Value of str12: " << str12 << std::endl; 
	delete[] str12;
	str12 = nullptr;

	/** String functions **/
	// strlen
	char str13[] = "Hello";
	std::cout << "Length of str13: " << strlen(str13) << std::endl; // expected 5
	// concat
	char str14[20] = "Hello";
	char str15[] = " World";
	strcat(str14, str15);
	std::cout << "Value of str14: " << str14 << std::endl; // expected Hello World
	char str16[20] = "Hello";
	char str17[] = " World";
	strncat(str16, str17, 3);
	std::cout << "Value of str16: " << str16 << std::endl; // expected Hello Wo
    // copy
	char str18[20] = "Hello";
	char str19[] = " World";
	strcpy(str18, str19);
	std::cout << "Value of str18: " << str18 << std::endl; // expected World
	char str20[20] = "Hello";
	char str21[] = "World";
	strncpy(str20, str21, 3);
	std::cout << "Value of str20: " << str20 << std::endl; // expected Worlo
	// compare
	char str22[] = "Hello";
	char str23[] = "Hello";
	std::cout << "Value of strcmp(str22, str23): " << strcmp(str22, str23) << std::endl; // expected 0
	char str24[] = "Hello";
	char str25[] = "Hell";
	std::cout << "Value of strcmp(str24, str25): " << strcmp(str24, str25) << std::endl; // expected 1
	char str26[] = "Hell";
	char str27[] = "Hello";
	std::cout << "Value of strcmp(str26, str27): " << strcmp(str26, str27) << std::endl; // expected -1
	// find
	char str28[] = "Hello";
	char *ptr = strchr(str28, 'l');
	std::cout << "Value of strchr(str28, 'l'): " << ptr << std::endl; // expected llo
	ptr = strrchr(str28, 'l');
	std::cout << "Value of strrchr(str28, 'l'): " << ptr << std::endl; // expected llo
	ptr = strstr(str28, "lo");
	std::cout << "Value of strstr(str28, 'lo'): " << ptr << std::endl; // expected lo
	// never print strstr or strchr directly thr cout as if the string is not found,
	// it will return null which will be run time error as cout cannot print null. 
	// always check for null before printing
	// to print null, use %p in printf
	// to print null, use std::cout << std::hex << ptr << std::endl;
	// to print null, use std::cout << std::hex << (unsigned int)ptr << std::endl;

	//string to number
	char str29[] = "123";
	int num = atoi(str29);
	std::cout << "Value of atoi(str29): " << num << std::endl; // expected 123
		// STRTOI
	char str33[] = "123";
	char *endptr = nullptr;
	num = strtol(str33, &endptr, 10);
	std::cout << "Value of strtol(str33, &endptr, 10): " << num << std::endl; // expected 123
	std::cout << "Value of endptr: " << endptr << std::endl; // expected empty string
		// TO FLOAT
	char str30[] = "123.45";
	float num1 = atof(str30);
	std::cout << "Value of atof(str30): " << num1 << std::endl; // expected 123.45
		// STRTOF
	char str34[] = "123.45";	
	num1 = strtof(str34, &endptr);
	std::cout << "Value of strtof(str34, &endptr): " << num1 << std::endl; // expected 123.45
		// TO LONG
	char str31[] = "123";
	long num2 = atol(str31);
	std::cout << "Value of atol(str31): " << num2 << std::endl; // expected 123
		// STRTOL
	char str35[] = "123";
	num2 = strtol(str35, &endptr, 10);
	std::cout << "Value of strtol(str35, &endptr, 10): " << num2 << std::endl; // expected 123
	std::cout << "Value of endptr: " << endptr << std::endl; // expected empty string
		// TO LONG LONG
	char str32[] = "123";
	long long num3 = atoll(str32);
	std::cout << "Value of atoll(str32): " << num3 << std::endl; // expected 123
		// STRTOLL
	char str36[] = "123";
	num3 = strtoll(str36, &endptr, 10);
	std::cout << "Value of strtoll(str36, &endptr, 10): " << num3 << std::endl; // expected 123
	std::cout << "Value of endptr: " << endptr << std::endl; // expected empty string
	// number to string
	int num4 = 123;
	char str37[10];
	itoa(num4, str37, 10);
	std::cout << "Value of itoa(num4, str37, 10): " << str37 << std::endl; // expected 123
		// STRTOI
	num4 = 123;
	sprintf(str37, "%d", num4);
	std::cout << "Value of sprintf(str37, \"%d\", num4): " << str37 << std::endl; // expected 123
		// TO FLOAT
	float num5 = 123.45;
	char str38[10];
	sprintf(str38, "%f", num5);
	std::cout << "Value of sprintf(str38, \"%f\", num5): " << str38 << std::endl; // expected 123.45
	
	// string to upper and lower
	char str39[] = "Hello";
	for (int i = 0; i < strlen(str39); i++)
	{
		str39[i] = toupper(str39[i]);
	}
	std::cout << "Value of toupper(str39): " << str39 << std::endl; // expected HELLO
	char str40[] = "Hello";
	for (int i = 0; i < strlen(str40); i++)
	{
		str40[i] = tolower(str40[i]);
	}
	std::cout << "Value of tolower(str40): " << str40 << std::endl; // expected hello

	// PARSING A STRING
	char str41[] = "Hello, World";
	char *token = strtok(str41, ", ");
	while (token != nullptr)
	{
		std::cout << "Value of token: " << token << std::endl;
		token = strtok(nullptr, ", ");
	}
}	// defined scope '{}' to limit the stack memory. previous variables will be cleared.
{	/******************** STRING STREAM ************************/

 	std::string str1 = "Hello, World";
	// Can take input too without specifying the size  and can reassign 
	// this string of bigger size without any modifications\

	// string append
	std::string str2 = "Hello";
	std::string str3 = " World";
	str2.append(str3);
	std::cout << "Value of str2: " << str2 << std::endl; // expected Hello World
	// string compare
	std::string str4 = "Hello";
	std::string str5 = "Hello";
	std::cout << "Value of str4.compare(str5): " << str4.compare(str5) << std::endl; // expected 0
	std::string str6 = "Hello";
	std::string str7 = "Hell";
	std::cout << "Value of str6.compare(str7): " << str6.compare(str7) << std::endl; // expected 1
	std::string str8 = "Hell";
	std::string str9 = "Hello";
	std::cout << "Value of str8.compare(str9): " << str8.compare(str9) << std::endl; // expected -1
	// string find
	std::string str10 = "Hello";
	size_t pos = str10.find("lo");
	std::cout << "Value of str10.find(\"lo\"): " << pos << std::endl; // expected 3
	std::cout << "Value of str10.find(\"lo\", 4): " << str10.find("lo", 4) << std::endl; // expected -1 
													// 4 is the position from where to start searching
	std::cout << "Value of str10.find(\"is\"): " << str10.find("is") << std::endl; // expected -1
	// string to number
	std::string str11 = "123";
	int num = std::stoi(str11);
	std::cout << "Value of std::stoi(str11): " << num << std::endl; // expected 123
	std::string str12 = "123.45";
	float num1 = std::stof(str12);
	std::cout << "Value of std::stof(str12): " << num1 << std::endl; // expected 123.45
	std::string str13 = "123";
	long num2 = std::stol(str13);
	std::cout << "Value of std::stol(str13): " << num2 << std::endl; // expected 123
	std::string str14 = "123";
	long long num3 = std::stoll(str14);
	std::cout << "Value of std::stoll(str14): " << num3 << std::endl; // expected 123
	// number to string
	int num4 = 123;
	std::string str15 = std::to_string(num4);
	std::cout << "Value of std::to_string(num4): " << str15 << std::endl; // expected 123
	float num5 = 123.45;
	std::string str16 = std::to_string(num5);
	std::cout << "Value of std::to_string(num5): " << str16 << std::endl; // expected 123.45
	// string insert
	std::string str17 = "Hello";
	std::string str18 = " World";
	str17.insert(5, str18);
	std::cout << "Value of str17: " << str17 << std::endl; // expected Hello World
	// string erase
	std::string str19 = "Hello World";
	str19.erase(5, 5);
	std::cout << "Value of str19: " << str19 << std::endl; // expected Hello
	// string replace
	std::string str20 = "Hello World";
	std::string str21 = "Universe";
	str20.replace(6, 2, str21); //replace from 6th position 2 characters with str21 in str20
	std::cout << "Value of str20: " << str20 << std::endl; // expected Hello Universerld
	// string stream
	std::string str22 = "Hello";
	std::string str23 = "World";
	std::stringstream ss;
	ss << str22 << " " << str23;
	std::string str24 = ss.str();
	std::cout << "Value of str24: " << str24 << std::endl; // expected Hello World
	// string pop_back
	std::string str25 = "Hello";
	str25.pop_back();
	std::cout << "Value of str25: " << str25 << std::endl; // expected Hell
	// string push_back
	std::string str26 = "Hello";
	str26.push_back('!');
	std::cout << "Value of str26: " << str26 << std::endl; // expected Hello!
	// string resize
	std::string str27 = "Hello";
	str27.resize(3);
	std::cout << "Value of str27: " << str27 << std::endl; // expected Hel
	// string clear
	std::string str28 = "Hello";
	str28.clear();
	std::cout << "Value of str28: " << str28 << std::endl; // expected empty string
	// string empty
	std::string str29 = "Hello";
	std::cout << "Value of str29.empty(): " << str29.empty() << std::endl; // expected 0
	std::string str30 = "";
	std::cout << "Value of str30.empty(): " << str30.empty() << std::endl; // expected 1
	// string size
	std::string str31 = "Hello";
	std::cout << "Value of str31.size(): " << str31.size() << std::endl; // expected 5
	// string length
	std::string str32 = "Hello";
	std::cout << "Value of str32.length(): " << str32.length() << std::endl; // expected 5
	// string capacity, reserve, shrink_to_fit
	std::string str33 = "Hello";
	std::cout << "Value of str33.capacity(): " << str33.capacity() << std::endl; // expected 15
	str33.reserve(100);
	std::cout << "Value of str33.capacity(): " << str33.capacity() << std::endl; // expected 100
	str33.shrink_to_fit();
	std::cout << "Value of str33.capacity(): " << str33.capacity() << std::endl; // expected 5
	// string at
	std::string str36 = "Hello";
	std::cout << "Value of str36.at(1): " << str36.at(1) << std::endl; // expected e
	// string front
	std::string str37 = "Hello";
	std::cout << "Value of str37.front(): " << str37.front() << std::endl; // expected H
	// string back
	std::string str38 = "Hello";
	std::cout << "Value of str38.back(): " << str38.back() << std::endl; // expected o
	// string substr
	std::string str39 = "Hello World";
	std::string str40 = str39.substr(6, 5);
	std::cout << "Value of str40: " << str40 << std::endl; // expected World
	// string rfind
	std::string str42 = "Hello";
	size_t pos2 = str42.rfind("l");
	std::cout << "Value of str42.rfind(\"l\"): " << pos2 << std::endl; // expected 3
	// string find_first_of
	std::string str43 = "Hello";
	size_t pos3 = str43.find_first_of("lo");
	std::cout << "Value of str43.find_first_of(\"lo\"): " << pos3 << std::endl; // expected 2
	std::cout << "Value of str43.find_first_of(\"lo\", 3): " << str43.find_first_of("lo", 3) << std::endl; // expected 3
	// string find_last_of
	std::string str44 = "Hellololo";
	size_t pos4 = str44.find_last_of("lo");
	std::cout << "Value of str44.find_last_of(\"lo\"): " << pos4 << std::endl; // expected 7
	std::cout << "Value of str44.find_last_of(\"lo\", 3): " << str44.find_last_of("lo", 3) << std::endl; // expected 3
	// string find_first_not_of
	std::string str45 = "Hello";
	size_t pos5 = str45.find_first_not_of("H");
	std::cout << "Value of str45.find_first_not_of(\"H\"): " << pos5 << std::endl; // expected 1
	// string find_last_not_of
	std::string str46 = "Hello";
	size_t pos6 = str46.find_last_not_of("o");
	std::cout << "Value of str46.find_last_not_of(\"o\"): " << pos6 << std::endl; // expected 3
	// string reverse
	std::string str47 = "Hello";
	std::reverse(str47.begin(), str47.end()); //from algorthm.h
	std::cout << "Value of str47: " << str47 << std::endl; // expected olleH
	// string sort
	std::string str48 = "Hello";
	std::sort(str48.begin(), str48.end()); //from algorthm.h
	std::cout << "Value of str48: " << str48 << std::endl; // expected eHllo
	// string copy
	std::string str49 = "Hello";
	char str50[10];
	str49.copy(str50, 4);
	std::cout << "Value of str50: " << str50 << std::endl; // expected Hell + junk
	str50[4] = '\0';
	std::cout << "Value of str50: " << str50 << std::endl; // expected Hell
	// string c_str
	std::string str51 = "Hello";
	const char *str52 = str51.c_str();
	std::cout << "Value of str52: " << str52 << std::endl; // expected Hello
	// string data
	std::string str53 = "Hello";
	const char *str54 = str53.data();
	std::cout << "Value of str54: " << str54 << std::endl; // expected Hello
	// string [], +, =
	std::string str55 = "Hello";
	std::cout << "Value of str55[1]: " << str55[1] << std::endl; // expected e
	std::string str56 = "Hello";
	std::string str57 = " World";
	std::string str58 = str56 + str57;
	std::cout << "Value of str58: " << str58 << std::endl; // expected Hello World
	std::string str59 = "Hello";
	std::string str60 = " World";
	str59 = str60;
	std::cout << "Value of str59: " << str59 << std::endl; // expected World
	// string +=
	std::string str61 = "Hello";
	std::string str62 = " World";
	str61 += str62;
	std::cout << "Value of str61: " << str61 << std::endl; // expected Hello World
	// string ==
	std::string str63 = "Hello";
	std::string str64 = "Hello";
	std::cout << "Value of str63 == str64: " << (str63 == str64) << std::endl; // expected 1
	// string !=
	std::string str65 = "Hello";
	std::string str66 = "Hello";
	std::cout << "Value of str65 != str66: " << (str65 != str66) << std::endl; // expected 0
	// string <
	std::string str67 = "Hello";
	std::string str68 = "Hello";
	std::cout << "Value of str67 < str68: " << (str67 < str68) << std::endl; // expected 0
	// string >
	std::string str69 = "Hello";
	std::string str70 = "Hello";
	std::cout << "Value of str69 > str70: " << (str69 > str70) << std::endl; // expected 0
	// string <=
	std::string str71 = "Hello";
	std::string str72 = "Hello";
	std::cout << "Value of str71 <= str72: " << (str71 <= str72) << std::endl; // expected 1
	// string >=
	std::string str73 = "Hello";
	std::string str74 = "Hello";
	std::cout << "Value of str73 >= str74: " << (str73 >= str74) << std::endl; // expected 1
	// string iterator, begin, end
	std::string str75 = "Hello";
	for (std::string::iterator it = str75.begin(); it != str75.end(); it++)
	{
		std::cout << "Value of *it: " << *it << std::endl;
		*it = 'A';
		std::cout << "Value of *it changed: " << *it << std::endl;
	}
	std::string str76 = "Hello";
	for (std::string::reverse_iterator it = str76.rbegin(); it != str76.rend(); it++)
	{
		*it = toupper(*it);
		//*it = *it - 32; // same as above
		std::cout << "Value of  reverse *it: " << *it << std::endl;
	}
	std::cout << "/*************  end String ***********/" << std::endl;
	return ( 0 );
}
}
