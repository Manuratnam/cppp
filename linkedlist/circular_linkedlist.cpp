
#include <iostream>
using namespace std;

struct node
{
    int data;
    node* link;
};

node* tail = NULL;

void insertend(int num)
{
    node* newnode = new node;
    newnode->data = num;

    if (tail == NULL)
    {
        tail = newnode;
        tail->link = tail;
    }
    else
    {
        newnode->link = tail->link;
        tail->link = newnode;
        tail = newnode;
    }
}

void display()
{
    if (tail == NULL)
    {
        cout << "List is empty.\n";
    }
    else
    {
        node* temp = tail->link;

        cout << "Circular Linked List: ";

        do
        {
            cout << temp->data << " -> ";
            temp = temp->link;

        } while (temp != tail->link);

        cout << "(back to start)\n";
    }
}

int main()
{
    insertend(10);
    insertend(20);
    insertend(30);

    display();

    return 0;
}
