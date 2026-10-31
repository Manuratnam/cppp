#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *link;
};

struct node *tail = NULL;
struct node *newnode = NULL;
struct node *temp = NULL;

void insertend(int num)
{
    newnode = new node;
    newnode->data = num;
    newnode->link = NULL;

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
        temp = tail->link;

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
