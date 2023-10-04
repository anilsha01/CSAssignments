/* Write a function, isPalindrome, that accepts a string and determines 
if the string is a palindrome. -> void isPalindrome(string); */

#include <iostream>
#include <string>

using namespace std;

void ispalindrome(string input, int begin, int end)
{
    //compares if beginning and ending characters are the same
    if (input[begin]==input[end])
    {
        //compares the characters from first and second halves of the string
        //breaks when the two halves are already compared
        if (begin<end)
        {
            //calls recursive function to compare next two characters
            ispalindrome(input, begin+1, end-1);
        }
    }
    //if two characters are not equal, string is not a palindrome.
    else
    {
        cout<<"The string '"<<input<<"' is not a palindrome."<<endl;
    }

    // if we reach middle character (odd sized strings) or overlap (even sized strings)
    // string is a palindrome as string is equal to its reverse 
    if(begin==end || begin>end)
    {
        cout<<"The string '"<<input<<"' is a palindrome."<<endl;
    }
}


int main()
{
    cout << "Enter a string to test: ";
    string inp;
    getline(cin, inp);
    //receive input includong whitespaces

    //if string is one character, it is a palindrome
    if (inp.length()==1)
    {
        cout<<"The string '"<<inp<<"' is a palindrome."<<endl;
    }
    else
    {
        //creates indexes to traverse and compare the string
        int first=0, last=inp.length()-1;
        //initial call for recursive function
        ispalindrome(inp, first, last);
    }

    return 0;
}