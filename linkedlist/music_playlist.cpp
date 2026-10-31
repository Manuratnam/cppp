/*This program uses a singly linked list to manage a music playlist. It allows you to:
- Add a song
- Delete a song
- Sort songs alphabetically using bubble sort
- Search for a song
- Display the playlist*/
#include <iostream>
#include <string>
using namespace std;

struct Node
{
    string song;
    Node* next;
};

Node* head = NULL;

void addSong(string name)
{
    Node* newNode = new Node();
    newNode->song = name;
    newNode->next = head;
    head = newNode;

    cout << "Song added successfully!\n";
}

void deleteSong(string name)
{
    if (head == NULL)
    {
        cout << "Playlist is empty!\n";
        return;
    }

    if (head->song == name)
    {
        Node* temp = head;
        head = head->next;
        delete temp;

        cout << "Song deleted successfully!\n";
        return;
    }

    Node* temp = head;

    while (temp->next != NULL && temp->next->song != name)
    {
        temp = temp->next;
    }

    if (temp->next == NULL)
    {
        cout << "Song not found!\n";
        return;
    }

    Node* toDelete = temp->next;
    temp->next = toDelete->next;
    delete toDelete;

    cout << "Song deleted successfully!\n";
}

void sortPlaylist()
{
    if (head == NULL || head->next == NULL)
    {
        cout << "Playlist sorted!\n";
        return;
    }

    for (Node* i = head; i->next != NULL; i = i->next)
    {
        for (Node* j = head; j->next != NULL; j = j->next)
        {
            if (j->song > j->next->song)
            {
                string temp = j->song;
                j->song = j->next->song;
                j->next->song = temp;
            }
        }
    }

    cout << "Playlist sorted successfully!\n";
}

void searchSong(string name)
{
    Node* temp = head;
    int pos = 1;

    while (temp != NULL)
    {
        if (temp->song == name)
        {
            cout << "Song found at position " << pos << "!\n";
            return;
        }

        temp = temp->next;
        pos++;
    }

    cout << "Song not found in the playlist!\n";
}

void display()
{
    Node* temp = head;

    cout << "\nPlaylist: ";

    while (temp != NULL)
    {
        cout << temp->song << " -> ";
        temp = temp->next;
    }

    cout << "NULL\n";
}

int main()
{
    int choice;
    string songName;

    while (true)
    {
        cout << "\n--- MUSIC PLAYLIST MENU ---\n";
        cout << "1. Add Song\n";
        cout << "2. Delete Song\n";
        cout << "3. Sort Playlist\n";
        cout << "4. Search Song\n";
        cout << "5. Display\n";
        cout << "6. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1)
        {
            cout << "Enter song name: ";
            cin >> songName;
            addSong(songName);
        }
        else if (choice == 2)
        {
            cout << "Enter song name to delete: ";
            cin >> songName;
            deleteSong(songName);
        }
        else if (choice == 3)
        {
            sortPlaylist();
        }
        else if (choice == 4)
        {
            cout << "Enter song name to search: ";
            cin >> songName;
            searchSong(songName);
        }
        else if (choice == 5)
        {
            display();
        }
        else if (choice == 6)
        {
            break;
        }
        else
        {
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}
