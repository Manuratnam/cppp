#include <iostream>
using namespace std;

int main()
{
    int arr[100], n, search;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter array elements: ";

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter element to search: ";
    cin >> search;

    int found = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == search)
        {
            cout << "Element found at position " << i + 1;
            found = 1;
            break;
        }
    }

    if (found == 0)
    {
        cout << "Element not found";
    }

    return 0;
}
