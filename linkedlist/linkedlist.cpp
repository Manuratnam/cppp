//This program creates a singly linked list using a class and a constructor. 
//It keeps accepting numbers until the user enters something other than y, then displays all the nodes.
#include <iostream>
using namespace std;

class linkedlist
{
private:
    struct node
    {
        int data;
        node *link;
    } *start, *newnode, *temp;

public:
    linkedlist();
    void insert();
    void display();
};

linkedlist::linkedlist()
{
    start = NULL;
}

void linkedlist::insert()
{
    int num;
    char ch = 'y';

    do
    {
        cout << "Enter the number: ";
        cin >> num;

        newnode = new node;
        newnode->data = num;
        newnode->link = NULL;

        if (start == NULL)
        {
            start = temp = newnode;
        }
        else
        {
            temp->link = newnode;
            temp = newnode;
        }

        cout << "Do you want to continue? (y/n): ";
        cin >> ch;

    } while (ch == 'y');
}

void linkedlist::display()
{
    temp = start;

    if (start == NULL)
    {
        cout << "Linked list is empty\n";
    }
    else
    {
        while (temp != NULL)
        {
            cout << temp->data << "\n";
            temp = temp->link;
        }

        cout << "END\n";
    }
}

int main()
{
    linkedlist obj;

    obj.insert();
    obj.display();

    return 0;
}
