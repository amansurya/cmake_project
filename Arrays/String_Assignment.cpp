/**
 *****************************************************************************************
 * @file String_Assignment1.cpp
 * @details 
 *
 *****************************************************************************************
 */
#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <algorithm>
#include "String_Assignment.h"
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

using namespace std;
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
int String_Assignment( void )
{
/******Assignment 1 *********/
/*Requirement 1*/  
    cout << "Requirement 1" << endl;
/*Case 1*/
    string str = "This is a string";
    cout << "case 1" << endl << "input is \"This is a string\"" << endl;
    Assignment_1(str);
/*Case 2*/
    str = "This is a string with 1234 numbers";
    cout << "case 2" << endl << "input is \"This is a string with 1234 numbers\"" << endl;
    Assignment_1(str);
/*Case 3*/
    str = "This is a string with 1234 numbers and special characters like @#$%^&*()";
    cout << "case 3" << endl << "input is \"This is a string with 1234 numbers and special characters like @#$%^&*()\"" << endl;
    Assignment_1(str);
/*Case 4*/
    str = "This is a with string with with with repetitionssssss";
    cout << "case 4" << endl << "input is \"This is a with string with with with repetitionssssss\"" << endl;
    Assignment_1(str);
/*Case 5*/
    str = "NitiN"; // [palindrome test case]
    cout << "case 5" << endl << "input is \"NitiN\" . Check Palindrome" << endl;
    Assignment_1(str);
/*Case 6*/
    str = "Nitin"; // [not palindrome test case]
    cout << "case 6" << endl << "input is \"Nitin\" . Check Palindrome" << endl;
    Assignment_1(str);
/*Case 7*/
    str = "Ni12@#t#@21iN"; // [palindrome with numbers and spl char test case]
    cout << "case 7" << endl << "input is \"Ni12@#t#@21iN\" . Check Palindrome" << endl;
    Assignment_1(str);

/*Requirement 2*/
/*Case 1*/

/*Requirement 3*/ 


//to come more requirements of 1st test case


/******Assignment 2 *********/
    Assignment_2();
/******Assignment 3 *********/    
    Assignment_3(); 
    //Assignment_4( int n );
    return ( 0 );
}

/**
 *  @brief 
 *  1) Find out the number of words, vowels, letters, consonants, repetative letters and number of repetitions,
 *      numbers, special characters in the given string and print the results. 
 *      Check if the string is palindrome or not.
 *  2) Copy string contents to another string and make the capitals small and vice versa.
 *  3) Print all the unique characters in the string.
 *  4) Check if the string is pangram or not.
 *  5) Find out distinct subsequences of the string.
 *  6) Find out minimum number of deletions to make the string palindrome
 *  7) If the string has numbers, form a separate variable acc to the number and find if the numbwer is palindrome
 *  8) Separated numbers must be assingned to a string and separated by commas as per indian standard representatiion.
 *  9) Take valid numbers and speacial characters from the string and perform arthimatic operations on them.
 *  10) Take valid numbers and speacial characters from the string and perform bitwise operations on them.
 *  11) Take valid numbers and speacial characters from the string and perform shift operations on them.
 *  12) Find out largest wor and smallest word in the string. 
 *  13) Sort the characters in the string and print the result.
 *  14) Find if any two characters appear exactly same number of times in the string and if so print characters and number.
 *  15) Separate numbers in the string and insert '-' in between odd numbers from string.
 *  16) Alter the cases of each word in the string and substring. 
 *  17) Convert numbers from the string into english words and print them.
 *  18) Separate branckets from strings and form well formatted bracketted string out of it. ( follow bodmas for brancket order)
 *  19) Form Binary number out of string and print it. Convert it to decimal and hexa decimal using strings concept.
 *  20) Form Decimal number out of the string and follow above approach.
 *  21) Form Hexa decimal number out of the string and follow above approach.
 *  22) Find out consecutive numbers forms a roman number and convert it to integer.
 *  23) To each word, encrypt it and print. Encryption -> take a letter in word, replace it with letter followed by number 
 *      of repetitions in word. 
 *  24) Palindrome with/without small and capital letters.  
 *  @details Use string class and without it
 *  @param[in] void
 *  @n @b Usage: Assignment 1
 *  @return none
 */
void Assignment_1(string str)
{
    /* Requirement 1*/
    int words = 0, vowels = 0, letters = 0, consonants = 0, repetative_letters = 0, repetitions = 0, numbers = 0,
         special_characters = 0, word_count=0;
    string unique_letters;
    string str_cpy = str;
    string str_words,str_vowels, str_letters, str_consonants, str_repetative_letters, str_repetitions, 
         str_numbers, str_special_characters;
    reverse(str_cpy.begin(), str_cpy.end());
    for(string::iterator it = str.begin(); it != str.end(); it++)
    {
        if(((int)*it>=65 && (int)*it<=90)||((int)*it>=97 && (int)*it<=122))
        {
            str_words += *it;
            words+=1;
            //str_words.append(*it);
            //str_words.push_back(*it);
        }
        else if ((int)*it >= 48 && (int)*it <= 57)
        {
            if (str_numbers.find(*it)==-1)
            {
                str_numbers += *it;
            }             
            numbers+=1;
            //str_numbers.append(*it);
            //str_numbers.push_back(*it);
        }
        else if (*it == ' ')
        {
            cout << "word " << word_count++ << " is :" << str_words << endl;
            str_words.clear();
        }
        else
        {
            if (str_special_characters.find(*it)==-1)
            {
                str_special_characters += *it;
            }            
            str_special_characters += *it;
            special_characters += 1;
            //str_special_characters.append(*it);
            //str_special_characters.push_back(*it);            
        }
        if (  *it == 'a' || *it == 'e' || *it == 'i' || *it == 'o' || *it == 'u'
                || *it == 'A' || *it == 'E' || *it == 'I' || *it == 'O' || *it == 'U' )   
        {
            if (str_vowels.find(*it)==-1)
            {
                str_vowels += *it;
            }
            vowels += 1;
            //str_vowels.append(*it);
            //str_vowels.push_back(*it);
        }
        else if (((int)*it>=65 && (int)*it<=90)||((int)*it>=97 && (int)*it<=122))
        {
            if (str_consonants.find(*it)==-1)
            {
                str_consonants += *it;
            }
            consonants += 1;
            //str_consonants.append(*it);
            //str_consonants.push_back(*it);
        }
        if (unique_letters.find(*it) == -1)
        {
            //same letter not found
            // future implementation scope usage of maps concept
            unique_letters += *it;
        }
        else
        {
            //same letter already found
            string str_temp(1, *it);
            unique_letters.insert(unique_letters.find(*it), str_temp);
        }
    }
    cout << "word " << word_count++ << " is :" << str_words << endl;
    str_words.clear();
    if ( str_cpy == str)
    {
        cout<< "Palindrome!" << endl;
    }
    else
    {
        cout<< "Not a Palindrome!" << endl;
    }
    // for(string::iterator it= unique_letters.begin(); *it != '\0' ; *it)
    // {
    //     size_t position = unique_letters.find_last_of(*it);
    //     //cout<< "Occurances of "<< *it << " : " << position <<endl;
    //     //unique_letters.erase(0,position);
    // }
    cout << "number of consonants are :" << consonants << endl;
    cout << "consonants are :" << str_consonants << endl;
    cout << "number of vowels are :" << vowels << endl;
    cout << "vowels are :" << str_vowels << endl;   
    cout << "number of special_characters are :" << special_characters << endl;
    cout << "special_characters are :" << str_special_characters << endl;   
    cout << "number of numbers are :" << numbers << endl;
    cout << "numbers are :" << str_numbers << endl; 

}

/**
 *  @brief 
 *  Given two strings, find out the common letters, unique letters in each string, swap strings.
 *  Findout if the given string is substring of another string, and how many times.
 *  Findout if the two strings are isomorphic to each other. refer : https://www.geeksforgeeks.org/check-if-two-given-strings-are-isomorphic-to-each-other/
 *  Future -> Findout if the two strings are k-anagrams to each other.
 *  Given two strings, the task is to find if a string can be obtained by rotating another string by two places.
 *  If the two strings are purely numbers, find their multiplication. 
 *  Minimum number of times the first string needs to be repeated so if the second string can be part of it or vice versa
 *  @details Use string class and without it, take strings as input from main assignments function. 
 *  @param[in] void
 *  @n @b Usage: Assignment 2
 *  @return none
 */
void Assignment_2()
{

}

/**
 *  @brief Look and say pattern nth term
 *  @details refer https://www.geeksforgeeks.org/look-and-say-sequence/
 *  @param[in] void
 *  @n @b Usage: Assignment 3
 *  @return none
 */
void Assignment_3()
{

}

/**
 *  @brief Find out the name of the nth collumn in excel sheet
 *  @details n needs to be taken as input from main assignments function
 *  @param[in] int n
 *  @n @b Usage: Assignment 4
 *  @return none
 */
void Assignment_4( int n )
{

}