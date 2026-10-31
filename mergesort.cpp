#include <iostream>
using namespace std;

void merge(int arr[], int lb, int mid, int ub)
{
    int temp[100];
    int i = lb;
    int j = mid + 1;
    int k = lb;

    while (i <= mid && j <= ub)
    {
        if (arr[i] <= arr[j])
        {
            temp[k] = arr[i];
            i++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }

    while (i <= mid)
    {
        temp[k] = arr[i];
        i++;
        k++;
    }

    while (j <= ub)
    {
        temp[k] = arr[j];
        j++;
        k++;
    }

    for (int x = lb; x <= ub; x++)
    {
        arr[x] = temp[x];
    }
}

void mergesort(int arr[], int lb, int ub)
{
    if (lb < ub)
    {
        int mid = (lb + ub) / 2;

        mergesort(arr, lb, mid);
        mergesort(arr, mid + 1, ub);

        merge(arr, lb, mid, ub);
    }
}

int main()
{
    int arr[100];
    int lb, ub;

    cout << "Enter lower bound: ";
    cin >> lb;

    cout << "Enter upper bound: ";
    cin >> ub;

    cout << "Enter the elements:\n";
    for (int i = lb; i <= ub; i++)
    {
        cin >> arr[i];
    }

    cout << "Array before sorting:\n";
    for (int i = lb; i <= ub; i++)
    {
        cout << arr[i] << " ";
    }

    mergesort(arr, lb, ub);

    cout << "\nArray after sorting:\n";
    for (int i = lb; i <= ub; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
