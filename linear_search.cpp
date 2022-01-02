#include<iostream>
using namespace  std;
bool linearSearch(int list[] , int last ,int target ,int& locn){
       int looker =0;
       bool found;
       while (looker <= last && list[looker] != target)
       {
           looker++;
       }
       locn = looker;
       if(looker<=last){
           found =true;
       }
       else{
           found = false;
       }
    return found;
}
int main(){
    int n,t,locn;
    bool found;
    int arr[10];
    cout<<"enter no.of elements: ";
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand()%100 ;
    }
    cout<<"array elements are: "<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" " ;
    }
    cout<<endl;
    cout<<"Enter the number to be searched: ";
    cin>>t;
    found = linearSearch(arr,n-1,t,locn);
    if(found){
        cout<<"Element "<<t<<" found at position "<<locn+1<<endl;
    }
    else{
        cout<<"Element "<<t<<" not found in the list "<<endl;
    }
    return 0;
}

