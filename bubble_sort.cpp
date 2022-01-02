#include <iostream>
using namespace std;

void bubblesort(int a[], int x)
{
    int current = 0;
    bool sorted = false;
    for (current = 0; current <= x && sorted == false; current++)
    {
        sorted = true;
        int walker = x;
        for (walker = x; walker > current; walker--)
        {
            if (a[walker] < a[walker - 1])
            {
                int temp = a[walker];
                a[walker] = a[walker - 1];
                a[walker - 1] = temp;
                sorted = false;
            }
        }
    }
}
int main()
{
    int n;
    cout << "Enter no.of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter the array elements\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    bubblesort(arr, n - 1);
    cout << "Array after sorting:\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}