//Finds the k-th node from the end of a singly linked list and displays its data. 
//It uses two pointers (first and second) to find the node without counting the entire list twice.

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* findKthFromLast(Node* head, int k) {
    if (head == NULL || k <= 0) {
        return NULL;
    }

    Node* first = head;
    Node* second = head;

    for (int i = 0; i < k; i++) {
        if (first == NULL) {
            cout << "K is greater than the number of nodes!\n";
            return NULL;
        }
        first = first->next;
    }

    while (first != NULL) {
        first = first->next;
        second = second->next;
    }

    return second;
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;
    int n, k;

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

    cout << "Enter k: ";
    cin >> k;

    Node* result = findKthFromLast(head, k);

    if (result != NULL) {
        cout << "K-th node from last: " << result->data << endl;
    } else {
        cout << "Node not found!" << endl;
    }

    return 0;
}
