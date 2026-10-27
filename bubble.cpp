
#include <iostream>
using namespace std;
int main()
{
    int a[5] = {5, 2, 4, 1, 3};
    int i, j, temp;
    for(i = 0; i < 4; i++)
    {
        for(j = 0; j < 4 - i; j++)
        {
            if(a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    cout << "Sorted array: ";
    for(i = 0; i < 5; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}
