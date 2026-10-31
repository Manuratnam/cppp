//Implements a Doubly Circular Linked List with insertion and deletion at the beginning, end, and a specific position. 
//It also displays the list.
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* head = NULL;

void insertBeg(int val) {
    Node* newNode = new Node();
    newNode->data = val;

    if (head == NULL) {
        newNode->next = newNode;
        newNode->prev = newNode;
        head = newNode;
        cout << "Inserted at beginning.\n";
        return;
    }

    Node* last = head->prev;

    newNode->next = head;
    newNode->prev = last;
    last->next = newNode;
    head->prev = newNode;

    head = newNode;

    cout << "Inserted at beginning.\n";
}

void insertEnd(int val) {
    Node* newNode = new Node();
    newNode->data = val;

    if (head == NULL) {
        newNode->next = newNode;
        newNode->prev = newNode;
        head = newNode;
        cout << "Inserted at end.\n";
        return;
    }

    Node* last = head->prev;

    newNode->next = head;
    newNode->prev = last;
    last->next = newNode;
    head->prev = newNode;

    cout << "Inserted at end.\n";
}

void insertPos(int val, int pos) {
    if (pos == 1) {
        insertBeg(val);
        return;
    }

    if (head == NULL || pos < 1) {
        cout << "Invalid position!\n";
        return;
    }

    Node* temp = head;

    for (int i = 1; i < pos - 1; i++) {
        temp = temp->next;

        if (temp == head) {
            cout << "Invalid position!\n";
            return;
        }
    }

    Node* newNode = new Node();
    newNode->data = val;

    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;

    cout << "Inserted at position " << pos << ".\n";
}

void deleteBeg() {
    if (head == NULL) {
        cout << "List is empty!\n";
        return;
    }

    if (head->next == head) {
        delete head;
        head = NULL;
        cout << "Deleted from beginning.\n";
        return;
    }

    Node* last = head->prev;
    Node* temp = head;

    head = head->next;
    head->prev = last;
    last->next = head;

    delete temp;

    cout << "Deleted from beginning.\n";
}

void deleteEnd() {
    if (head == NULL) {
        cout << "List is empty!\n";
        return;
    }

    if (head->next == head) {
        delete head;
        head = NULL;
        cout << "Deleted from end.\n";
        return;
    }

    Node* last = head->prev;
    Node* secondLast = last->prev;

    secondLast->next = head;
    head->prev = secondLast;

    delete last;

    cout << "Deleted from end.\n";
}

void deletePos(int pos) {
    if (head == NULL || pos < 1) {
        cout << "List is empty or position is invalid!\n";
        return;
    }

    if (pos == 1) {
        deleteBeg();
        return;
    }

    Node* temp = head;

    for (int i = 1; i < pos; i++) {
        temp = temp->next;

        if (temp == head) {
            cout << "Invalid position!\n";
            return;
        }
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    delete temp;

    cout << "Deleted from position " << pos << ".\n";
}

void display() {
    if (head == NULL) {
        cout << "List is empty!\n";
        return;
    }

    Node* temp = head;

    cout << "(HEAD) <-> ";

    do {
        cout << temp->data << " <-> ";
        temp = temp->next;
    } while (temp != head);

    cout << "(BACK TO HEAD)\n";
}

int main() {
    int choice, val, pos;

    while (true) {
        cout << "\n--- DOUBLY CIRCULAR LINKED LIST MENU ---\n";
        cout << "1. Insert Beginning\n";
        cout << "2. Insert End\n";
        cout << "3. Insert Position\n";
        cout << "4. Delete Beginning\n";
        cout << "5. Delete End\n";
        cout << "6. Delete Position\n";
        cout << "7. Display\n";
        cout << "8. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter value: ";
            cin >> val;
            insertBeg(val);
        }
        else if (choice == 2) {
            cout << "Enter value: ";
            cin >> val;
            insertEnd(val);
        }
        else if (choice == 3) {
            cout << "Enter value and position: ";
            cin >> val >> pos;
            insertPos(val, pos);
        }
        else if (choice == 4) {
            deleteBeg();
        }
        else if (choice == 5) {
            deleteEnd();
        }
        else if (choice == 6) {
            cout << "Enter position to delete: ";
            cin >> pos;
            deletePos(pos);
        }
        else if (choice == 7) {
            display();
        }
        else if (choice == 8) {
            break;
        }
        else {
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}
