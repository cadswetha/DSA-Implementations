#include<iostream>
using namespace  std;
bool binarySearch(int list[] , int last ,int target ,int& locn){
       int begin =0;
       int end =last;
       int mid;
       bool found;
       while (begin<=end)
       {
           mid =(begin +end)/2;
           if(target>list[mid]){
               begin = mid+1;
           }
           else if(target< list[mid]){
               end = mid-1;
           }
           else{
               break;
           }
       }
       locn = mid;
       if(target == list[mid]){
           found = true;
       }
       else{
           found = false;
       }
       return found;
}
int main(){
    int n,t,locn;
    int arr[10];
    bool f;
    cout<<"enter no.of elements: ";
    cin>>n;
    cout<<"enter array elements: "<<endl;
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    cout<<"Enter the number to be searched: ";
    cin>>t;
    f= binarySearch(arr,n-1,t ,locn);
     if(f){
         cout<<"Element "<<t<<" found in the list at position "<<locn+1<<endl;
     }
     else{
         cout<<"Element "<<t<<" not found in the list"<<endl;
     }
    return 0;
}