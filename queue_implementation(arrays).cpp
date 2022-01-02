#include<iostream>
using namespace std;
void enqueue(int queue[],int &f,int &r,int n,int x){ 
    if(r==n-1){
       cout<<"stack overflow\n";
    }
    else{
        r++;
        queue[r]=x;
        if(f==-1){
            f=0;
        }
    }
}
void dequeue(int queue[],int &f ,int& r, int n){
    if(f==-1){
        cout<<"stack underflow\n";
        return;
    }
    int y= queue[f];
      if(f==r){
        f=r=-1;
      }
      else{
        f++;
      }
    cout<<"element popped is "<<y<<"\n";
}
void queueFront(int queue[],int f){
     if(f==-1){
         cout<<"queue is empty\n";
     }
     else{
         cout<<"queue front is "<<queue[f]<<endl;
     }
}
void queueRear(int queue[],int r){
     if(r==-1){
         cout<<"queue is empty\n";
     }
     else{
         cout<<"queue back is "<<queue[r]<<endl;
     }
}
void display(int queue[],int f ,int r){
    if(f==-1 &&r==-1){
        cout<<"queue is empty\n";
    }
    else{
        cout<<"queue elements are: "<<endl;
        for (int i = f; i <= r; i++)
        {
            cout<<queue[i]<<" " ;
        }
        cout<<endl;
    }
}
int main()
{
    int queue[10];
    int n, choice , x,f,r;
    f=r=-1;
    cout<<"enter the size of the queue: ";
    cin>>n;
    do
    {
        cout<<"enter your choice\n"
            <<"1.enqueue\n2.dequeue\n3.front\n4.back\n5.display\n";
        cin>>choice;
        switch (choice)
        {
        case 1:
            cout<<"enter the element you want to push: ";
            cin>>x;
            enqueue(queue ,f,r,n,x);
            break;
        case 2:
            dequeue(queue,f,r,n);
            break;
        case 3:
            queueFront(queue,f);
            break;
        case 4:
            queueRear(queue ,r);
            break;
        case 5:
            display(queue,f,r);
            break;
        default:
            break;
        }
    } while (choice<=5);
    return 0;
}
