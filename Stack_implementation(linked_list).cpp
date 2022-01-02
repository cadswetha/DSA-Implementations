#include<iostream>
using namespace std;
struct node{
    int data ;
    node* link;
};
void Push(node* &first ,int x){
        node* p=new node;
        p->data=x;
        p->link=first;
        first=p;
}
void Display(node* first){
    node *t=first;
	while(t!=NULL)
	{
		cout<<t->data<<"  ";
		t=t->link;
	}
    cout<<endl;
}
void pop(node* &first){
    node* t=first;
    first =first->link;
    cout<<"element deleted: "<<t->data<<endl;
    delete t;
}
int top(node* first){
    return first->data;
}
int main()
{
    node* first=NULL;
    int n, choice , x;
    cout<<"enter the size of the stack: ";
    cin>>n;
    do
    {
        cout<<"enter your choice\n"
            <<"1.Push\n2.Display\n3.delete\n4.seek\n";
        cin>>choice;
        switch (choice)
        {
        case 1:
            cout<<"enter the element you want to push: ";
            cin>>x;
            Push( first ,x );
            break;
        case 2:
            cout<<"the elements are: \n";
            Display(first);
            break;
        case 3:
            pop(first);
            break;
        case 4:
            cout<<"stack top is : "<<top(first)<<endl;
            break;
        default:
            break;
        }
    } while (choice<=4);
    return 0;
}
