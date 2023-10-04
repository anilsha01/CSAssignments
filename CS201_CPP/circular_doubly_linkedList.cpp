/* Write a circular doubly linked list for integers. Include append, insert, and print member functions. 
void append(int n); This should add n to the end of the list.
void insert(int n);This should insert n to the beginning of the list.
void print();This should print all of the elements of the list in order. */

#include <iostream>

using namespace std;

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};
struct Node *start=NULL;

class doubly_list
{
    private:
        Node *start, *last;

    public:
        doubly_list()
        {
            start=NULL;
            last=NULL;
        }
        void append(int n)
        {
            //if list is empty
            if (start==NULL)
            {
                Node *newNode= new Node;
                newNode->data = n;       //make a new node and store number
                newNode->next = newNode->prev;
                start = newNode;
            }
            //create node
            Node *newNode= new Node;
            newNode->data = n;
           //find predecessor / last node
            last = (start)->prev;
            //node->next points to successor
            newNode->next = start;
            //node->prev points to predecessor
            newNode->prev = last;
            //successor points to new node
            start->prev = newNode; 
            //predecessor points to new node
            last->next = newNode;
        }

        void insert (int n)
        {
            //if list is empty
            if (start==NULL)
            {
                Node *newNode= new Node;
                newNode->data = n;
                newNode->next = newNode->prev;
                start=newNode;
            }

            //create node
            Node *newNode= new Node;
            newNode->data = n;
            //find last node
            last= (start)->prev;
            //new node points to predecessor and successor
            newNode->next= start;
            newNode->prev= last;
            //predecessor and successor point to new node
            start->prev = newNode;
            last->next = newNode;
            start = newNode;
        }  

        void print()
        {
            //create temporary pointer to traverse the list
            Node *temp= start;

            if (start == NULL)
            {
                cout<<"List is empty."<<endl;
            }
            else
            {
                cout<<"List contents: ";

                while (temp->next != start)
                {
                cout<< temp->data <<" ";
                temp = temp->next;
                }
            }
        } 
};




int main()
{
    doubly_list list;
    list.append(3);
    list.append(5);
    list.append(4);
    list.print();
    list.insert(1);
    list.print();

}