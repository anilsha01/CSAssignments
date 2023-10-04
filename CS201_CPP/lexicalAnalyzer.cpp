/* implement a simple scanner for a source file given as a command-line argument. When all the input has been read, your program should produce a summary report 
that includes a list of all the tokens that appeared  in the input, the number of times each token appears in the input and the class of each token. Your program 
should also list how many times tokens of each category appeared in the input. */

#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

int main()
{
    ifstream file;
    file.open ("text.txt");
    map<string, int> keyword, digit, character, operators, specials;
    string line;
    int digitTokens=0, charTokens=0, operatorTokens=0, specialTokens=0, keywordTokens=0;

    while (getline(file, line))
    {
        if ( line=="0" || line=="1" || line=="2" || line=="3" || line=="4" || line=="5" || line=="6" || line=="7" || line=="8" || line=="9")
        {
            if (digit.find(line) != digit.end())
                digit[line]++;
            else
                //digit.insert({line, 1});
                digit.insert(pair<string, int>(line, 1));
            //cout<<line<<" is digit\n";
            digitTokens++;
        }

        else if ( line=="a" || line=="b" || line=="c" || line=="d" || line=="e" || line=="f" || line=="g" || line=="h" || line=="i" || line=="j" || line=="k" || line=="l" || 
        line=="m" || line=="n" || line=="o" || line=="p" || line=="q" || line=="r" || line=="s" || line=="t" || line=="u" || line=="v" || line=="w" || line=="x" || line=="y" || 
        line=="z" || line=="A" || line=="B" || line=="C" || line=="D" || line=="E" || line=="F" || line=="G" || line=="H" || line=="I" || line=="J" || line=="K" || line=="L" || 
        line=="M" || line=="N" || line=="O" || line=="P" || line=="Q" || line=="R" || line=="S" || line=="T" || line=="U" || line=="V" || line=="W" || line=="X" || line=="Y" || line=="Z")
        {
            if (character.find(line) != character.end())
                character[line]++;
            else
                character.insert(pair<string, int>(line, 1));
            //cout<<line<<" is character\n";
            charTokens++;
        }

        else if ( line=="*" || line=="/" || line=="%" || line=="-" || line=="+" || line=="=" || line=="<" || line==">" || line=="&&" || line=="||" || line=="!")
        {
            if (operators.find(line) != operators.end())
                operators[line]++;
            else
                operators.insert(pair<string, int>(line, 1));
            //cout<<line<<" is operator\n";
            operatorTokens++;
        }
        
        else if ( line=="{" || line=="}" || line=="[" || line=="]" || line=="(" || line==")" || line=="," || line==".")
        {
            if (specials.find(line) != specials.end())
                specials[line]++;
            else
                specials.insert(pair<string, int>(line, 1));
            //cout<<line<<" is special\n";
            specialTokens++;
        }

        else if (line=="else" ||line=="new" || line=="this" || line=="auto" || line=="enum" ||	line=="operator" ||	line=="throw" || line=="bool" || line=="private" || line=="true" ||
        line=="break" || line=="try" || line=="case" || line=="public" ||line=="catch" ||line=="false" || line=="char" || line=="float" ||	line=="class" || line=="for" || line=="return" ||
        line=="const" || line=="friend" || line=="short" || line=="unsigned" || line=="goto" || line=="using" || line=="continue" || line=="if" || line=="virtual" || line=="default" ||
        line=="static" || line=="void" || line=="delete" || line=="int" || line=="do" || line=="long" || line=="struct" || line=="double" || line=="switch" || line=="while" || line=="namespace" ||
        line=="template" )
        {
            if (keyword.find(line) != keyword.end())
                keyword[line]++;
            else
                keyword.insert(pair<string, int>(line, 1));
            //cout<<line<<" is keyword\n";
            keywordTokens++;
        }
    }
    cout<<"SUMMARY REPORT:\n\n";
    map<string, int>::iterator it;

    cout<<"Tokens that appear in the DIGIT class, and how many times they appear:"<<endl;
    for (it=digit.begin(); it!=digit.end(); it++)
    {
        cout<<it->first<<": "<<it->second<<" time(s)"<<endl;
    }
    cout<<"\n";

    cout<<"Tokens that appear in the CHARACTER class, and how many times they appear:"<<endl;
    for (it=character.begin(); it!=character.end(); it++)
    {
        cout<<it->first<<": "<<it->second<<" time(s)"<<endl;
    }
    cout<<"\n";

    cout<<"Tokens that appear in the OPERATOR class, and how many times they appear:"<<endl;
    for (it=operators.begin(); it!=operators.end(); it++)
    {
        cout<<it->first<<": "<<it->second<<" time(s)"<<endl;
    }
    cout<<"\n";

    cout<<"Tokens that appear in the SPECIAL class, and how many times they appear:"<<endl;
    for (it=specials.begin(); it!=specials.end(); it++)
    {
        cout<<it->first<<": "<<it->second<<" time(s)"<<endl;
    }
    cout<<"\n";

    cout<<"Tokens that appear in the KEYWORD class, and how many times they appear:"<<endl;
    for (it=keyword.begin(); it!=keyword.end(); it++)
    {
        cout<<it->first<<": "<<it->second<<" time(s)"<<endl;
    }
    cout<<"\n";

    cout<<"Tokens appeared in the DIGIT class "<<digitTokens<<" times."<<endl;
    cout<<"Tokens appeared in the CHARACTER class "<<charTokens<<" times."<<endl;
    cout<<"Tokens appeared in the OPERATOR class "<<operatorTokens<<" times."<<endl;
    cout<<"Tokens appeared in the SPECIAL class "<<specialTokens<<" times."<<endl;
    cout<<"Tokens appeared in the KEYWORD class "<<keywordTokens<<" times."<<endl;

   
    return 0;
}
