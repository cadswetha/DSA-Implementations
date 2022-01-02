#include<iostream>
using namespace std;
void reheapup(int heap[] , int newnode){
    if(newnode!=0){
        int parent = (newnode-1)/2;
        if(heap[newnode]>heap[parent]){
            int temp = heap[newnode];
            heap[newnode] = heap[parent];
            heap[parent] = temp;
            reheapup(heap , parent);
        }
    }
}
void reheapdown(int heap[] , int root , int last){
    int leftsubtree = 2*root +1;
    int rightsubtree = 2*root +2;
    int largesubtree=-1;
    int leftkey=-1 , rightkey=-1;
    int temp;
    if(leftsubtree<=last){
       leftkey = heap[leftsubtree];
       if(rightsubtree<=last){
          rightkey= heap[rightsubtree];
       }
       else{
           rightkey = -9999;
       }
       if(leftkey > rightkey){
           largesubtree = leftsubtree;
       }
       else {
           largesubtree = rightsubtree;
       }
       if(heap[root]<heap[largesubtree]){
           temp = heap[root];
           heap[root] = heap[largesubtree];
           heap[largesubtree] = temp;
           reheapdown(heap , largesubtree,last);
       }
    }
}
void buildheap(int heap[] ,int size ){
    int walker = 1;
    while (walker<size)
    {
        reheapup(heap , walker);
        walker++;
    }
}
void insertheap(int heap[] , int newele ,int& n){
    n++;
    heap[n-1] = newele;
    reheapup(heap , n-1);
}
void sortheap(int heap[]  , int size){
    buildheap(heap , size);
    int heapsize = size;
    int temp;
    while(heapsize > 1){
        temp = heap[0] ;
        heap[0] = heap[heapsize-1];
        heap[heapsize-1] = temp;
        heapsize--;
        reheapdown(heap, 0,heapsize-1);
    }
}
int main(){
    int arr[200];
    int size,choice,data;
    cout<<"enter no.of elements in the array: ";
    cin>>size;
    cout<<"enter the array elements\n";
    for(int i = 0 ;i<size ; i++){
        cin>>arr[i];
    }
    do{
       cout<<"enter your choice:"<<endl;
       cout<<"1.buildheap\t 2. insert element\t 3. Sort heap: ";
       cin>>choice;
       switch (choice)
       {
       case 1:
           buildheap(arr, size);
           break;
       case 2:
           cout<<"enter the data you want to insert: ";
           cin>>data;
           insertheap(arr, data, size);
           break;
       case 3:
           cout<<"sorting heap"<<endl;
           sortheap(arr,size);
           break;
       default:
           break;
       }
       cout<<"current state of heap elements"<<endl;
       for (int i = 0; i < size; i++)
       {
            cout<<arr[i]<<" ";
       }
       cout<<endl;
    }while(choice<=3);
    return 0;
}