/* Takes a file of catastrophes as input and separates each field into categories. 
Give the user an option to search for catastrophes by year or by type of disaster.
Also give an option to create a summary report. */

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <ctype.h>
#include <numeric>

using namespace std;

void year_range (string disasters[74][5]);
void disaster_search (string disasters[74][5]);
void summary_report (string disasters[74][5]);


int main ()
{
    ifstream myfile;
    myfile.open ("catastrophe.txt");
    string catastrophes[74][5];
    string line;
    string category;

  // if (myfile.is_open())
  //    cout << "it is open";
  //else
  //    cout << "it is not";

    int line_number = 0;
    //int i = 0;
    while (getline (myfile, line))
    {
        int i = 0;
        stringstream iss (line);
        iss << line;
        while (getline (iss, category, ','))
	    {
	        catastrophes[line_number][i] = category;
            i++;
	    }
        line_number++;
    }
    myfile.close();
    
    cout<< "What would you like to do?" << endl << "1: Look up year range" <<endl 
        << "2: Look up disaster" << endl << "3: Generate summary report" <<endl;
        
    bool repeat;
    do
    {
        repeat=false;
        int selection;
        cin >> selection;
        switch (selection)
        {
            case 1:
            {
	            year_range (catastrophes);
	            break;
            }
            case 2:
            {
	            disaster_search (catastrophes);
	            break;
            }
            case 3:
            {
	            summary_report (catastrophes);
	            break;
            }
            default:
            {
	            cout << "Invalid selection. Please select from the menu items." <<endl;
	            repeat=true;
	            break;
            }
        }
    }
    while (repeat);


  return 0;
}

void year_range (string disasters[74][5])
{
    int begin_year, end_year, temp_year;
    vector < string > disasters_in_year_range;

    cout << "Enter the beginning year: ";
    cin >> begin_year;
    cout << "Enter ending year: ";
    cin >> end_year;
    temp_year = begin_year;
    for (temp_year; temp_year <= end_year; temp_year++)
    {
        for (int line = 0; line < 74; line++)
	    {
	        //temp_year=begin_year;
	        std::size_t found =(disasters[line][0]).find (std::to_string (temp_year));
	        if (found != std::string::npos)
	        {
	            (disasters[line][0]).erase(remove((disasters[line][0]).begin (),(disasters[line][0]).end(), '"'),(disasters[line][0]).end());
	            disasters_in_year_range.push_back (disasters[line][0]);
	        }
	    }
    }
    cout << "All disasters between " << begin_year << " and " << end_year << ":"<< endl;
    for (int i = 0; i < disasters_in_year_range.size (); i++)
    {
        cout << disasters_in_year_range[i] << endl;
    }


}

void disaster_search (string disasters[][5])
{
    string disaster_name;
    cout << "Enter a disaster name: ";
    cin >> disaster_name;
    vector < string > disaster;
    vector < string > resized;
    for (int line = 0; line < 74; line++)
    {
        transform ((disasters[line][1]).begin(), (disasters[line][1]).end(),(disasters[line][1]).begin(),::tolower);
        std::size_t found = (disasters[line][1]).find (disaster_name);
        if (found != std::string::npos)
	    {
	        size_t i = 0;
	        for (; i < (disasters[line][0]).length (); i++)
	        {
	            if (isdigit ((disasters[line][0])[i]))
		        break;
	        }
	        (disasters[line][0])=(disasters[line][0]).substr (i,(disasters[line][0]).length () - i);
	        int years = atoi ((disasters[line][0]).c_str ());
	        disaster.push_back (std::to_string (years));

	    }

    }
    if (disaster.size () == 0)
    {
        cout << "No catastrophes reported for the disaster inputted." << endl;
    }
    if (disaster.size () >= 1)
    {
        for (int i = 1; i < disaster.size (); i++)
	    {
	        if (disaster[i - 1] != disaster[i])
	        {
	            resized.push_back (disaster[i - 1]);
	        }
	    }
        cout << "Years in which disaster occurred: ";
        for (int i = 0; i < resized.size (); i++)
	    {
	        cout << resized[i] << " ";
	    }
    }

}

void summary_report (string disasters[][5])
{
    cout<<"Enter output file name: ";
    string file_name;
    cin>>file_name;


    int current_year = 2012, last_year = 2019;
    vector < vector <string> > summary;

    for (current_year; current_year <= last_year; current_year++)
    {
        vector <string> year;
        vector <string> disaster_type;
        vector <int> deaths;
        for (int line = 0; line < 74; line++)
	    {
	        std::size_t found =(disasters[line][0]).find (std::to_string (current_year));
	        if (found != std::string::npos)
	        {
	            size_t i = 0;
	            for (; i < (disasters[line][0]).length (); i++)
		        {
		            if (isdigit ((disasters[line][0])[i]))
		                break;
		        }
	            (disasters[line][0]) =(disasters[line][0]).substr (i,(disasters[line][0]).length ()-i);
	            int year_to_look_at = atoi ((disasters[line][0]).c_str ());
	            year.__emplace_back (::to_string (year_to_look_at));


	            (disasters[line][1]) =(disasters[line][1]).substr (0,(disasters[line][1]).length ()-0);
	            disaster_type.push_back (disasters[line][1]);

                (disasters[line][4]) =(disasters[line][4]).substr (0,(disasters[line][4]).length ()-0);
                int death_index= atoi ((disasters[line][4]).c_str ());
                deaths.push_back(death_index);
	        }

	        if (year.size () >= 1)
	        {
	            for (int i = 1; i < year.size (); i++)
		        {
		            if (year[i - 1] == year[i])
		            {
		                year.erase (year.begin () + i);
		            }
		        }
	        }
            map < string, int >m;
	        for (vector < string >::iterator i = disaster_type.begin();i != disaster_type.end (); ++i)
            {
                m[*i]++;
            }
	        disaster_type.clear ();
	        for (map < string, int >::iterator i = m.begin (); i != m.end ();++i)
            {
	            disaster_type.push_back (i->first);
            }



	    }
	    year.__emplace_back(": ");
        for (int i = 0; i < disaster_type.size (); i++)
	    {
	    year.__emplace_back (disaster_type[i]);
	    year.__emplace_back(", ");
	    }

        
        year.__emplace_back(::to_string(accumulate(deaths.begin(), deaths.end(), 0)));


        summary.push_back (year);


    }

    std::ofstream output_file(file_name, ios::app);
   
    
    for (int i = 0; i < summary.size (); i++)
    {
        for (int j = 0; j < summary[i].size (); j++)
	    {
            string data=summary[i][j];
	        output_file << data;
	    }
        output_file << "\n";
    }
    output_file.close();
    cout<<"File successfully created."<<endl;
    
}




//summary_report, option for switch statement to input new case selection
