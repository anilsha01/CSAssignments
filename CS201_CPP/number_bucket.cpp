/* Please implement the Number_bucket class. The Number_bucket class will contain a dynamic sized LIFO data structure. It should also have reasonable setters and getters, isEmpty(), push(int n), pop(), and get_size().
Deliverables:
1 Project plan (a text file, e.g. Word Document, PDF, etc.)
1 screenshot (e.g. JPEG, PNG, PDF, etc.)
1 main.cpp
1 number_bucket.h
You can submit additional files as needed to run your program.
All files may be compressed into one ZIP file.
Project plan
The project plan should include test cases, expectations, class names, and functions you plan to implement. Include the a description of the logic you are trying to implement.
Screen shot
This should be a screenshot of your program output. 
number_bucket.h
This will be the class definition Number_bucket class. It must be dynamic with a good constructor and destructor for credit. 
main.cpp Driver
The driver should include your class, create objects, and preform a reasonable number of tests to demonstrate your class.
*/
#include <iostream>
#include <string>
#include <vector>
#include "number_bucket.h"

using namespace std;

Number_Bucket::Number_Bucket()
{
    top=-1;
}
Number_Bucket::~Number_Bucket()
{

}


int Number_Bucket::getTop()
{
    return top;
}

void Number_Bucket::setTop()
{
    top=top+1;
}



bool Number_Bucket::isEmpty()
{
    if (getTop()==-1)
        return true;
    else
        return false;
}

void Number_Bucket::push(int n)
{
    setTop();
    stack[top]=n;

}

void Number_Bucket::pop()
{
    if (isEmpty()==true)
        cout<<"Underflow error!"<<endl;
    else 
    {
        stack[top]=0;
        top--;
    }
    cout<<"\n";
}

int Number_Bucket::get_size()
{
    return top+1;
}

void Number_Bucket::display_values()
{
    if (top==-1)
        cout<<"There are no items in the bucket!"<<endl;
    else
    {
        cout<<"Values of the bucket: ";
        for (int i=getTop(); i>=0; i--)
        {
            cout<<stack[i]<<" ";
        }
    }
    cout<<"\n";
}

void Number_Bucket::display_size()
{
    if (get_size()==0)
    {
        cout<<"Bucket is empty!"<<endl;
    }
    else
        cout<<"Size of bucket: "<<get_size();
    cout<<"\n";
}

int main()
{
    int number;
    Number_Bucket bucket; 
    bool repeat=true;
    cout<<"Options:\n"
            <<"1. Display the values in the bucket.\n"
            <<"2. Display the size of the bucket.\n"
            <<"3. Push a number into the bucket.\n"
            <<"4. Pop a number from the bucket.\n"
            <<"5. Display whether the bucket is empty.\n"
            <<"6. Quit."<<endl;
    do
    {
        cout<<"Enter option: ";
        int option;
        cin>> option;
        switch (option)
        {
            case 1:
            {
                bucket.display_values();
                break;
            }
            case 2:
            {
                bucket.display_size();
                break;
            }
            case 3:
            {
                int value;
                cout<<"Enter a value to push: ";
                cin>>value;
                bucket.push(value);
                cout<<"\n";
                break;
            }
            case 4:
            {
                bucket.pop();
                break;
            }
            case 5:
            {
                if (bucket.isEmpty()==true)
                    cout<<"The bucket is empty!"<<endl;
                else   
                    cout<<"The bucket is not empty!"<<endl;
                cout<<"\n";
                break;
            }
            case 6:
            {
                repeat=false;
                break;

            }
            default:
            {   cout << "Invalid selection. Please select from the menu items." <<endl;
                cout<<"\n";
	            break;
            }
        }
    }
    while (repeat==true);

    return 0;
}