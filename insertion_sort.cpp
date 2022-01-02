#include <iostream>
using namespace std;
void insert_iter(int a[], int x)
{
    int key;
    for (int i = 1; i < x; i++)
    {
        key =a[i];
        int j =i-1;
        while (j>=0 &&a[j]>key)
        {
            a[j+1] =a[j];
            j--;
        }
        a[j+1]=key;
    }
    
}
void insert_recur(int a[],int x){
    if(x<=1) return;
    insert_recur(a , x-1);
    int key = a[x-1];
    int j=x-2;
    while (j>=0 && a[j]>key)
    {
        a[j+1]=a[j];
        j--;
    }
    a[j+1]= key;
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
    insert_recur(arr,n);
    cout << "Array after sorting:\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}