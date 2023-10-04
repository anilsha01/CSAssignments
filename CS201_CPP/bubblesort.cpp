/*Write a program that ask user to enter 7 numbers and store that in array.
Display that all numbers before and after performing Bubble sort. You
must have to create new function with required parameter to perform
Bubble sort.*/
#include <iostream>

using namespace std;
void bubblesort(int array[],int size);
void swap(int &a, int &b);

int main()
{
    int arraysize=7;
    int numbers[7];
    //cout<<"Enter 7 numbers to store: "<<endl;
    for (int i=0; i<arraysize; i++)
    {
        int temp;
        cout<<"Enter number "<<i+1<<": ";
        cin>>temp;
        numbers[i]=temp;
    }
    cout<<"Numbers before bubble sort:"<<endl;
    for (int i=0; i<arraysize; i++)
    {
        cout<<numbers[i]<<endl;
    }
    cout<<"Numbers after bubble sort:"<<endl;
    bubblesort(numbers, arraysize);

    return 0;
}

void bubblesort(int array[],int size)
{
    int max, index;

    for (max=size-1; max>0; max--)
    {
        for (index=0; index< max; index++)
        {
            if (array[index]>array[index+1])
            {
                swap(array[index],array[index+1]);
            }
        }
    }
    for (index=0; index<size; index++)
    {
        cout<<array[index]<<endl;
    }
}

void swap(int &a, int &b)
{
    int temp=a;
    a=b;
    b=temp;
}