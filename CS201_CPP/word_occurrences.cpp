/* Queries a list of words in a file (up to 4 words) and finds the occurrences of words with the line number, as well as the co-occurrence line number(s) for all words */

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

void readfile(string nameOfFile);
void find_matches(vector<vector<string> > *ptr, string query_list);


int main()
{
    string filename;
    string words;
    cout<<"Enter a file name: ";
    cin>>filename;
    cin.ignore();


    readfile(filename);
    return 0;
}

void readfile(string nameOfFile)
{
    vector<vector<string> > *wordsSentence= new vector<vector<string> >;
    string line, word;
    ifstream myfile;
    myfile.open(nameOfFile);


    int line_number = 0;
    vector<string> wordsInLine;
    while (getline (myfile, line))
    {
        int i = 0;
        stringstream iss (line);
        iss << line;
        while (getline (iss, word, ' '))
	    {
            transform(word.begin(), word.end(), word.begin(), ::tolower);
            reverse(word.begin(), word.end());
	        wordsInLine.push_back(word); 
            i++;
	    }
        line_number++;
        reverse(wordsInLine.begin(), wordsInLine.end());
        wordsSentence->push_back(wordsInLine);
        wordsInLine.clear();
    }
    myfile.close();

    string words;
    
    cout<<"Enter space-separated words: ";
    getline(cin, words);
    while (words!="quit")
    {
        find_matches(wordsSentence, words);
    }
}

void find_matches(vector<vector<string> > *ptr, string query_list)
{
    vector<vector<string> >&sentences= *ptr;
    string word;

    int amountInQueryList=0;
    stringstream iss (query_list);
    iss<< query_list;
    vector<string> split_words;
    while (getline (iss, word, ' '))
    {
        split_words.push_back(word);
        amountInQueryList++;
    }

    vector<int> linesOf1stWord, linesOf2ndWord, linesOf3rdWord, linesOf4thWord;
    for (int row=0; row<9; row++)
    {
        int sizeOfColumn= sentences[row].size();
        for (int column=0; ; column++)
        {     
            if (sentences[row][column].compare(split_words[0])==0)
            {
                linesOf1stWord.push_back(row+1);
                break;
            }
            sizeOfColumn--;
            if (sizeOfColumn==0)
                break;
        }
         sort(linesOf1stWord.begin(),linesOf1stWord.end());
    }
    if (amountInQueryList>=2)
    {
        for (int row=0; row<9; row++)
        {
            int sizeOfColumn= sentences[row].size();
            for (int column=0; ; column++)
            {     
                if (sentences[row][column].compare(split_words[1])==0)
                {
                    linesOf2ndWord.push_back(row+1);
                    break;
                }
                sizeOfColumn--;
                if (sizeOfColumn==0)
                    break;
            }
        }
        sort(linesOf2ndWord.begin(),linesOf2ndWord.end());

    }
    if (amountInQueryList>=3)
    {
        for (int row=0; row<9; row++)
        {
            int sizeOfColumn= sentences[row].size();
            for (int column=0; ; column++)
            {     
                if (sentences[row][column].compare(split_words[2])==0)
                {
                    linesOf3rdWord.push_back(row+1);
                    break;
                }
                sizeOfColumn--;
                if (sizeOfColumn==0)
                    break;
            }
        }
        sort(linesOf3rdWord.begin(),linesOf3rdWord.end());
    }
    if (amountInQueryList==4)
    {
        for (int row=0; row<9; row++)
        {
            int sizeOfColumn= sentences[row].size();
            for (int column=0; ; column++)
            {     
                if (sentences[row][column].compare(split_words[3])==0)
                {
                    linesOf4thWord.push_back(row+1);
                    break;
                }
                sizeOfColumn--;
                if (sizeOfColumn==0)
                    break;
            }
        }
        sort(linesOf4thWord.begin(),linesOf4thWord.end());
    }

    vector<int> commonOf2Words, commonOf3Words, commonOf4Words;
    if (amountInQueryList>=2)
    {
        set_intersection(linesOf1stWord.begin(), linesOf1stWord.end(), 
            linesOf2ndWord.begin(), linesOf2ndWord.end(), back_inserter(commonOf2Words));
    
        if (amountInQueryList>=3)
        {
            set_intersection(commonOf2Words.begin(), commonOf2Words.end(), 
                linesOf3rdWord.begin(), linesOf3rdWord.end(), back_inserter(commonOf3Words));
        
            if (amountInQueryList==4)
            {
                set_intersection(commonOf3Words.begin(), commonOf3Words.end(), 
                    linesOf4thWord.begin(), linesOf4thWord.end(), back_inserter(commonOf4Words));
            }
        }

    }
    
    if (amountInQueryList==1)
    {
        cout<<"lines in which '"<< query_list<<"' occurred: ";
        for (int i=0; i<linesOf1stWord.size(); i++)
            {
                cout<<linesOf1stWord[i]<<" ";
            }
        cout<<"\n\n";
    }
    
    if (amountInQueryList==2)
    {
        if (commonOf2Words.size()==0)
            cout<<"No occurrences occurred."<<endl;
        else
        {
            cout<<"Lines in which co-occurrence occurred: ";
            for (int i=0; i<commonOf2Words.size(); i++)
            {
                cout<<commonOf2Words[i]<<" ";
            }
        }
        cout<<"\n\n";
    }

    if (amountInQueryList==3)
    {
        if (commonOf3Words.size()==0)
            cout<<"No occurrences occurred."<<endl;
        else
        {
            cout<<"Lines in which co-occurrence occurred: ";
            for (int i=0; i<commonOf3Words.size(); i++)
            {
                cout<<commonOf3Words[i]<<" ";
            }
        }
        cout<<"\n\n";
    }

    if (amountInQueryList==4)
    {
        if (commonOf4Words.size()==0)
            cout<<"No occurrences occurred."<<endl;
        else
        {
            cout<<"Lines in which co-occurrence occurred: ";
            for (int i=0; i<commonOf4Words.size(); i++)
            {
                cout<<commonOf4Words[i]<<" ";
            }
        }
        cout<<"\n\n";
    }
}
