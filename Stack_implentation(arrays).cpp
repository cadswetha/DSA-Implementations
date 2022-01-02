#include<iostream>
using namespace std;
void Push(int Stack[] ,int& top ,int x,int n){
    if(top>=n-1){
        cout<<"Stack overflow\n";
        return;
    }
    top++;
    Stack[top]=x;
}
void Display(int Stack[],int top){
    if(top==-1){
        cout<<"Stack is empty!\n";
        return;
    }
    int i =top;
    while (i>=0)
    {
        cout<<Stack[i]<<" ";
        i--;
    }
    cout<<"\n";
}
void Pop(int Stack[] ,int& top){
    if(top==-1){
        cout<<"Stack underflow on Pop!\n";
        return;
    }
    int x = Stack[top];
    top--;
    cout<<"Element popped is : "<<x<<"\n";
}
void Peek(int Stack[],int top){
    if(top==-1){
        cout<<"Stack is empty!\n";
        return;
    }
    cout<<"Stack top is : "<<Stack[top]<<endl;
}
int main()
{
    int Stack[10];
    int n, choice , x,e=0,top=-1;
    cout<<"enter the size of the stack: ";
    cin>>n;
    do
    {
        cout<<"enter your choice\n"
            <<"1.Push\n2.Display\n3.Pop\n4.Peek\n";
        cin>>choice;
        switch (choice)
        {
        case 1:
            cout<<"enter the element you want to push: ";
            cin>>x;
            Push(Stack , top ,x ,n);
            break;
        case 2:
            cout<<"the elements are: \n";
            Display(Stack,top);
            break;
        case 3:
            Pop(Stack , top);
            break;
        case 4:
            Peek(Stack ,top);
            break;
        default:
            break;
        }
    } while (choice<=4);
    return 0;
}
