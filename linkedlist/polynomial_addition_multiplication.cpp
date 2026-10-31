#include <iostream>
using namespace std;

struct Node
{
    int coeff;
    int exp;
    Node* next;
};

void insertTerm(Node*& head, int c, int e)
{
    if (c == 0)
        return;

    Node* newNode = new Node();
    newNode->coeff = c;
    newNode->exp = e;
    newNode->next = NULL;

    if (head == NULL || e > head->exp)
    {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* temp = head;

    while (temp->next != NULL && temp->next->exp > e)
    {
        temp = temp->next;
    }

    if (temp->exp == e)
    {
        temp->coeff = temp->coeff + c;
        delete newNode;

        if (temp->coeff == 0)
        {
            if (temp == head)
            {
                head = head->next;
            }
            else
            {
                Node* prev = head;

                while (prev->next != temp)
                    prev = prev->next;

                prev->next = temp->next;
            }

            delete temp;
        }
    }
    else
    {
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void createPoly(Node*& head)
{
    int n, c, e;

    cout << "How many terms in this polynomial? ";
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cout << "Enter coefficient and exponent for term " << i << ": ";
        cin >> c >> e;

        insertTerm(head, c, e);
    }
}

Node* addPoly(Node* p1, Node* p2)
{
    Node* sum = NULL;

    Node* temp1 = p1;

    while (temp1 != NULL)
    {
        insertTerm(sum, temp1->coeff, temp1->exp);
        temp1 = temp1->next;
    }

    Node* temp2 = p2;

    while (temp2 != NULL)
    {
        insertTerm(sum, temp2->coeff, temp2->exp);
        temp2 = temp2->next;
    }

    return sum;
}

Node* multiplyPoly(Node* p1, Node* p2)
{
    Node* prod = NULL;

    for (Node* i = p1; i != NULL; i = i->next)
    {
        for (Node* j = p2; j != NULL; j = j->next)
        {
            int newCoeff = i->coeff * j->coeff;
            int newExp = i->exp + j->exp;

            insertTerm(prod, newCoeff, newExp);
        }
    }

    return prod;
}

void display(Node* head)
{
    if (head == NULL)
    {
        cout << "0\n";
        return;
    }

    Node* temp = head;

    while (temp != NULL)
    {
        cout << temp->coeff << "x^" << temp->exp;

        if (temp->next != NULL && temp->next->coeff > 0)
            cout << " + ";
        else if (temp->next != NULL)
            cout << " ";

        temp = temp->next;
    }

    cout << endl;
}

int main()
{
    Node* poly1 = NULL;
    Node* poly2 = NULL;

    cout << "--- Enter First Polynomial ---\n";
    createPoly(poly1);

    cout << "\n--- Enter Second Polynomial ---\n";
    createPoly(poly2);

    cout << "\nPolynomial 1: ";
    display(poly1);

    cout << "Polynomial 2: ";
    display(poly2);

    Node* sum = addPoly(poly1, poly2);

    cout << "\nAddition Result: ";
    display(sum);

    Node* prod = multiplyPoly(poly1, poly2);

    cout << "Multiplication Result: ";
    display(prod);

    return 0;
}
