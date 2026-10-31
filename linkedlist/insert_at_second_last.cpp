//Inserts a new node at the second-last position of a singly linked list. If the list is empty or contains only one node, it inserts the new node at the beginning instead.

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void insertAtSecondLast(Node*& head, int val) {
    if (head == NULL || head->next == NULL) {
        Node* newNode = new Node();
        newNode->data = val;
        newNode->next = head;
        head = newNode;

        cout << "Inserted at the beginning instead.\n";
        return;
    }

    Node* temp = head;

    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    Node* newNode = new Node();
    newNode->data = val;

    newNode->next = temp->next;
    temp->next = newNode;

    cout << "Element inserted at second-last position!\n";
}

void display(Node* head) {
    Node* temp = head;

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;
    int n, val;

    cout << "Enter number of nodes: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        Node* newNode = new Node();

        cout << "Enter data: ";
        cin >> newNode->data;

        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    cout << "Enter value to insert: ";
    cin >> val;

    insertAtSecondLast(head, val);

    cout << "Final Linked List: ";
    display(head);

    return 0;
}
