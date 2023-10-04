#define NUMBER_BUCKET_H
#include <string>
#include <vector>

using namespace std;

class Number_Bucket
{
    private:
        int top;

    public:

        Number_Bucket();
        ~Number_Bucket();
        int stack[];

        bool isEmpty();
        void push(int n); 
        void pop();
        int get_size();

        int getTop();
        void setTop();
        void display_values();
        void display_size();
};