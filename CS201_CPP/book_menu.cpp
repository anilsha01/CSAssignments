/* Use a multidimensional array of books to create a menu that can display the books categorized as the following:
- display all books in a year range
- search for an author
-display all books from a category
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Book.h"

using namespace std;

void Book::setStartYear(int a)
{
    startYear=a;
}
void Book::setEndYear(int b)
{
    endYear= b;
}
void Book::setAuthorStr(string c)
{
    author=c; 
}
void Book::setCategory(string d)
{
    category=d;
}



int Book::getStartYear() const
{
    return startYear;
}
int Book::getEndYear() const
{
    return endYear;
}
string Book::getAuthorStr() const
{
    return author;
}
string Book::getCategory() const
{
    return category;
}


int Book::getYear(string d)
{
    year=stoi(d.substr(6));
    return year;
}


int main()
{
    Book search;
    string data[40][5]=
        {{"A Breath of Snow and Ashes","Diana Gabaldon","Delacorte","10/16/2005","Fiction"},
        {"A Common Life","Jan Karon","Viking","04/29/2001","Fiction"},
        {"A Dance With Dragons","George R. R. Martin","Bantam","07/31/2011","Non Fiction"},
        {"A Day Late and a Dollar Short","Terry McMillan","Viking","02/04/2001","Fiction"},
        {"A Feast For Crows","George R. R. Martin","Bantam","11/27/2005","Fiction"},
        {"A Lion Is In the Streets","Adria Locke Langley","McGraw","07/01/1945","Non Fiction"},
        {"A Man In Full","Tom Wolfe","Farrar","11/22/1998","Fiction"},
        {"A Painted House","John Grisham","Doubleday","02/25/2001","Non Fiction"},
        {"A Perfect Spy","John le Carre","Knopf","05/04/1986","Fiction"},
        {"A Rage to Live","John O'Hara","Random House","09/18/1949","Fiction"},
        {"A Shade of Difference","Allen Drury","Doubleday","10/28/1962","Non Fiction"},
        {"A Thousand Splendid Suns","Khaled Hosseini","Riverhead","06/10/2007","Fiction"},
        {"A Tree Grows In Brooklyn","Betty Smith","Harper","01/02/1944","Fiction"},
        {"A Widow For One Year","John Irving","Random House","06/14/1998","Non Fiction"},
        {"Accident","Danielle Steel","Delacorte","02/27/1994","Fiction"},
        {"Acheron","Sherrilyn Kenyon","St. Martin's","08/24/2008","Non Fiction"},
        {"Across the River and Into the Trees","Ernest Hemingway","Scribner's","10/15/1950","Fiction"},
        {"Advise and Consent","Allen Drury","Doubleday","10/04/1959","Non Fiction"},
        {"Against All Enemies","Tom Clancy","Putnam","07/03/2011","Non Fiction"},
        {"Airframe","Michael Crichton","Knopf","12/29/1996","Fiction"},
        {"Airport","Arthur Hailey","Doubleday","04/07/1968","Non Fiction"},
        {"Alaska","James Michener","Random House","07/03/1988","Fiction"},
        {"Alex Cross's Trial","James Patterson","Brown","09/13/2009","Non Fiction"},
        {"American Assassin","Vince Flynn","Atria","10/31/2010","Fiction"},
        {"An Indecent Obsession","Colleen McCullough","Harper","11/15/1981","Fiction"},
        {"Anansi Boys","Neil Gaiman","Morrow","10/09/2005","Fiction"},
        {"Anathem","Neal Stephenson","William Morrow","09/28/2008","Fiction"},
        {"Anatomy of a Murder","Robert Traver","St. Martin's","03/09/1958","Non Fiction"},
        {"And Now Tomorrow","Rachel Field","MacMillan","08/09/1942","Non Fiction"},
        {"Andersonville","McKinley Kantor","World Publishing","01/01/1956","Fiction"},
        {"Angels Fall","Nora Roberts","Putnam","07/30/2006","Fiction"},
        {"Answered Prayers","Danielle Steel","Delacorte","11/17/2002","Fiction"},
        {"Arch of Triumph","Erich Maria Remarque","Appleton-Century","03/10/1946","Fiction"},
        {"Armageddon","Tim LaHaye","Tyndale","04/27/2003","Fiction"},
        {"At First Sight","Nicholas Sparks","Warner","11/06/2005","Non Fiction"},
        {"Bad Moon Rising","Sherrilyn Kenyon","St. Martin's","08/23/2009","Non Fiction"},
        {"Bag of Bones","Stephen King","Scribner","10/11/1998","Non Fiction"},
        {"Beach Music","Pat Conroy","Talese/Doubleday","07/16/1995","Fiction"},
        {"Before I Say Goodbye","Mary Higgins Clark","Simon & Schuster","05/07/2000","Fiction"},
        {"Best Friends Forever","Jennifer Weiner","Atria","08/02/2009","Fiction"}};

    char option;
    bool repeat;
    do
    {
        cout<<"Enter a selection:\n"
            <<"1: Display all books in a year range.\n"
            <<"2: Search for an author.\n"
            <<"3: Display all books from a category.\n"
            <<"Q: Exit the program."<<endl;
        cin>>option;
        cout<<"\n\n";

        switch (option)
        {
            case '1':
            {
                int s, e;
                cout<<"Enter a starting year: ";
                cin>>s;
                search.setStartYear(s);
                cout<<"Enter an ending year: ";
                cin>>e;
                search.setEndYear(e);



                search.display_year_range(data);
                repeat=true;
                break;
            }
            case '2':
            {
                string str;
                cout<<"Enter an author name: ";
                cin.ignore();
                getline(cin, str);
                transform(str.begin(), str.end(), str.begin(), ::tolower);
                search.setAuthorStr(str);

                search.search_author(data);
                repeat=true;
                break;
            }
            case '3':
            {
                string c;
                cout << "Enter a category: ";
                cin.ignore();
                getline(cin, c);
                transform(c.begin(), c.end(), c.begin(), ::tolower);
                for(int i = 0; i < 40; i++){
                  transform(data[i][4].begin(), data[i][4].end(), data[i][4].begin(), ::tolower);
                }

                search.setCategory(c);
                

                search.display_category(data);
                
                repeat = true;
                break;
            }
            case 'q':
            {
                abort();
                break;
            }
            case 'Q':
            {
                abort();
                break;
            }   
            default:
            {
                cout<<"Invalid input. Please try again."<<endl;
                cout<<"\n\n\n";
                repeat=true;
                break;
            }

        }
    }
    while(repeat);
}


void Book::display_year_range(string array[40][5])
{
    int line, temp_year;
    string date;
    vector <string> books_in_range;

    temp_year=getStartYear();
    for (temp_year; temp_year<= getEndYear(); temp_year++)
    {
        for (line=0; line<40; line++) 
        {
            date= array[line][3];
            if ((stoi(date.substr(6)))==temp_year)  
            {
                books_in_range.push_back(array[line][0]);
            }
        }  
    }
    if (books_in_range.size()==0)
    {
        cout<<"No books found between "<< startYear<<" and "<<endYear<<"."<<endl;
        cout<<"\n\n\n";
    }
    else
    {
        cout<<"\nBooks published between "<< startYear<<" and "<<endYear<<": "<<endl;
        for (int i=0; i<books_in_range.size(); i++)
        {
            cout<<books_in_range[i]<<endl;
        }
        cout<<"\n\n\n";
    }
        
}
void Book::search_author(string array[40][5])
{
    vector <string> books_from_author;
    vector <string> full_name;
    string full_author_name;
    int line;

    for (line=0; line< 40; line++)
    {
        full_author_name= array[line][1];
        transform(full_author_name.begin(), full_author_name.end(), full_author_name.begin(), ::tolower);
        size_t found= full_author_name.find( getAuthorStr() ) ;
        if (found != std::string::npos)
	    {
            books_from_author.push_back(array[line][0]);
            full_name.push_back(array[line][1]);
        }
    }
    if (books_from_author.size()==0)
    {
        cout<<"No books were found from that author."<<endl;
        cout<<"\n\n\n";
    }
    else
    {
        cout<<"\nBooks published from "<<"'"<< author<<"'"<<": "<<endl;
        for (int i=0; i< books_from_author.size(); i++)
        {
            cout<<'"'<< books_from_author[i]<< '"'<<" by "<< full_name[i] <<endl;
        }
        cout<<"\n\n\n";
    }



}
void Book::display_category(string array[40][5])
{
    //Prompt the user for a string, then display all books whose
    //category matches the user input.
  vector <string> book_with_wanted_category;
  string category_of_book;

  int line;

  for(line=0; line < 40; line++){
    category_of_book = array[line][4];
    size_t found = category_of_book.find(getCategory());
    if(found != std::string::npos){
      for (int i=0; i<category_of_book.size(); i++){
          if (getCategory().size()==category_of_book.size()){
              book_with_wanted_category.push_back(array[line][0]);
              break;
          }
      }
      
    }
  }


  if(book_with_wanted_category.size() == 0){
    cout << "No books of that category were found." << endl;
  }

  else{
    cout << "\nBooks with category " << category << ": " << endl;
    for(int i = 0; i < book_with_wanted_category.size(); i++){
      cout << book_with_wanted_category[i] << endl;
    }
  }


  cout << "\n\n\n";
     
}