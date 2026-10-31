//Finds and displays the data stored in the second-last node of a singly linked list.checks whether the list has fewer than two nodes and displays an error if no second-last node exists.

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void findSecondLast(Node* head) {
    if (head == NULL || head->next == NULL) {
        cout << "There is no second last node!" << endl;
        return;
    }

    Node* temp = head;

    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    cout << "The second last node data is: " << temp->data << endl;
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;
    int n, x;

    cout << "Enter number of nodes: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter data: ";
        cin >> x;

        Node* newNode = new Node;
        newNode->data = x;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    findSecondLast(head);

    return 0;
}
