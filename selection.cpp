
#include <iostream>
using namespace std;
int main()
{
    int a[5] = {5, 2, 4, 1, 3};
    int i, j, temp, min;
    for(i = 0; i < 4; i++)
    {
        min = i;

        for(j = i + 1; j < 5; j++)
        {
            if(a[j] < a[min])
            {
                min = j;
            }
        }

        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
    cout << "Sorted array: ";
    for(i = 0; i < 5; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}
