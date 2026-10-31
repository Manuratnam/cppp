#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *front = NULL;
Node *rear = NULL;

void enqueue()
{
    int num;

    cout << "Enter element to insert: ";
    cin >> num;

    Node *newNode = new Node;
    newNode->data = num;
    newNode->next = NULL;

    if(front == NULL)
    {
        front = newNode;
        rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }

    cout << "Inserted successfully\n";
}

void dequeue()
{
    if(front == NULL)
    {
        cout << "Queue is empty. Cannot delete.\n";
        return;
    }

    Node *temp = front;

    cout << "Deleted element: " << front->data << endl;

    front = front->next;

    if(front == NULL)
        rear = NULL;

    delete temp;
}

void display()
{
    if(front == NULL)
    {
        cout << "Queue is empty\n";
        return;
    }

    Node *temp = front;

    cout << "Queue elements: ";

    while(temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

int main()
{
    int choice;

    do
    {
        cout << "\n--- QUEUE USING LINKED LIST ---";
        cout << "\n1. Enqueue";
        cout << "\n2. Dequeue";
        cout << "\n3. Display";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                enqueue();
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                cout << "Program ended\n";
                break;

            default:
                cout << "Invalid choice\n";
        }

    } while(choice != 4);

    return 0;
}
