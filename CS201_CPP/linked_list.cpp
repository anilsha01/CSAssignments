#include <iostream>

using namespace std;


struct Node 
{
    int data;
    struct Node *next;
};
struct Node *head=NULL;

class linked_list
{
    private:
    Node *head, *tail;

    public:
    linked_list()
    {
        head=NULL;
        tail=NULL;
    }
    void insert(int num)
    {
        
        Node *newNode;

        newNode= new Node;
        newNode->data = num;       //make a new node and store number
        newNode->next = nullptr;

        if (head==NULL)
        {
            head=newNode;
            tail=newNode;
        }
        else
        {
            tail->next=newNode;
            tail=tail->next;
        }
    }
    void display()
    {
        Node *nodeptr;
        nodeptr=head;
        while (nodeptr)
        {
            cout<<nodeptr->data<<"  ";
            nodeptr=nodeptr->next;
        }
    }
    int search(int num)
    {   
        int found=-1;
        int i=0;
       
       struct Node* newptr;
       newptr=head;

        while (newptr)
        {
            if (newptr->data == num)
            {
                newptr=newptr->next;
                found=i+1;
                break;
                //cout<<found;
            }
            else
            {
                i++;
                newptr=newptr->next;
            }
        
        }
        return found;
    }

    int deleteElement(int num)
    {
        int found=0;
        struct Node *newptr, *prev;
        newptr = head;
        while (newptr)
        {
            if (newptr->data == num)
            {
                newptr=newptr->next;
                delete(newptr);
                found=1;
                break;
            }
            else
            {
                prev= newptr;
                newptr = newptr->next;
            }
        }
        return found;
    }
    
};

int main() 
{
    linked_list ls;


    ls.insert(31);
    ls.insert(11);
    ls.insert(70);
    ls.insert(24);
    ls.insert(9);
    ls.insert(4);
    cout<<"The linked list is: ";   
    ls.display();
    cout << "\nLocation : " << ls.search(9) << endl;
    cout<<"Delete item: "<<ls.deleteElement(24)<<endl;
    cout<<"Delete item: "<<ls.deleteElement(19)<<endl;


    
    return 0;
}   