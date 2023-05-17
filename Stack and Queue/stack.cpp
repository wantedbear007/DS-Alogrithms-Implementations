#include<iostream>
using namespace std;

#define MAX 5
int stack[MAX],i,j,choice=0,top=-1;
void push();
void pop();
void show();


int main ()
{
    cout << "Stack imp" << endl;

    while(choice != 4)
    {

        cout << "Choose one from the following" << endl;
        cout << "1. Push 2. pop 3. Show 4. Exit";
        cout << "Enter your choice" << endl;

        cin >> choice;

        switch(choice)
        {	
            case 1:
            {
                push();
                break;
            }
            case 2:
            {
                pop();
                break;
            }
            case 3:
            {
                show();
                break;
            }
            case 4:
            {
                break;

            }
            default:
            {
                printf("Please Enter valid choice\n ");
            }
        };
    }

    return 0;
}

void push ()
{
    int val;
    if (top == MAX-1) cout << "Overflow";
    else
    {
        cout << "Enter the value to insert" << endl;
        cin >> val;
        top = top + 1;
        stack[top] = val;
        cout << "Value inserted " << endl;
    }

}

void pop ()
{
    int val;
    if(top == -1) cout << "Underflow" << endl;
    else
    {  val=stack[top];
       cout << "Item deleted " << val << endl;
       top = top -1;
    }

}
void show()
{
    if(top == -1)
    {
        cout << "Nothing to print";
    }
    else
    {        cout << "Printing values";
         for (i=top;i>=0;i--)//for(i=0;i<=top;i++)
            {

             cout << stack[i];
            }

    }

}