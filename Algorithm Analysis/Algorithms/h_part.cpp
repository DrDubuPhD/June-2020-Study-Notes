#include <iostream>
#include <algorithm>

using namespace std;

int h_part(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low - 1;
    int j = high + 1;

    while (true)
    {
        do
        {
            j--;
        } while (!(arr[j] <= pivot));

        do
        {
            i++;
        } while (!(arr[i] >= pivot));

        if (i < j)
        {
            swap(arr[i], arr[j]);
        }
        else
        {
            return j;
        }
    }
}

int main(void)
{
    int a[] = {5, 3, 2, 6, 4, 1, 3, 7};

    cout << "Before Partition: ";

    for (int x : a)
    {
        cout << x << " ";
    }

    cout << endl;

    int pivot = h_part(a, 0, 7);

    cout << "After Partition: ";

    for (int x : a)
    {
        cout << x << " ";
    }

    cout << endl;
    cout << "Pivot is: " << pivot << endl;

    return 0;
}