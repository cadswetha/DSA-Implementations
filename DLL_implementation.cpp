#include<iostream>
using namespace std;
struct node{
	int data;
	node* back;
	node* fore;
};
struct list{
	int count;
	node* head;
	node* rear;
};
void createList(list* &);
bool search(list* , node* & ,node *& ,int);
void insert(list*&,int);
void traverse(list*);
void traverseBack(list *);
void deleteNode(list *& , node*& );
int PosFromHead(list* ,  int );
int PosFromRear(list* ,  int );
bool FullList(list*);
bool EmptyList(list* );
int ListCount(list* );
void destroyList(list*& );
int main(){
    list* dll =NULL;
    node* ppre;
    node* ploc;
    int choice;
    bool f;
    do{
    cout<<"1.Create list, 2.Insert node, 3.search, 4.traverse, 5.traverseBack, 6.deleteNode, 7.Full List, 8.Is Empty, 9.List count, 10.Position of target from Head, 11.Position of target from Rear,12.Destroy List\n";
    cout<<"Enter the option:";
    cin>>choice;
    int x,y;
    switch(choice){
        case 1:
            createList(dll);
            break;
        case 2:
            cout<<"enter the element you want to insert: ";
            cin>>x;
            insert(dll, x);
            break;
        case 3:
            cout<<"Enter the elemnt you want to search: ";
            cin>>x;
            f = search(dll , ppre ,ploc ,x);
            if(f) cout<<"Element found!\n";
            else cout<<"Element not found!\n";
            break;
        case 4:
            traverse(dll);
            break;
        case 5:
            traverseBack(dll);
            break;
        case 6:
            cout<<"enter the element you want to delete";
            cin>>x;
            if(search(dll ,ppre , ploc ,x)){
                deleteNode(dll ,ploc);
            }
            else{
                cout<<"element not present cannot be deleted!"<<endl;
            }
            break;
        case 7:
            if(FullList(dll))cout<<"The list is full!!\n";
            else cout<<"The list is not empty\n";
            break;
        case 8:
            if(EmptyList(dll)) cout<<"The list is empty!\n";
            else cout<<"The list is not empty\n";
            break;
        case 9 : 
            cout<<"No.of nodes in the list : "<<ListCount(dll)<<endl;
            break;
        case 10:
            cout<<"Enter the element you want to find the position from Head: ";
            cin>>x;
            y = PosFromHead(dll , x);
            if(y !=-1){
                cout<<"Element found at "<<y<<" from head."<<endl;
            }
            else cout<<"Element not found"<<endl;
            break;
        case 11:
            cout<<"Enter the element you want to find the position from Rear: ";
            cin>>x;
            y = PosFromRear(dll , x);
            if(y !=-1){
                cout<<"Element found at "<<y<<" from rear end."<<endl;
            }
            else cout<<"Element not found"<<endl;
            break;
        case 12 : 
            destroyList(dll);
            cout<<"List Destroyed!\n";
            break;
    }
    }while(choice<=12);
}
void createList(list* &ref){
    ref = new list;
    ref->head = NULL;
    ref->count =0;
}
bool search(list *s , node*& ppre ,node*& ploc,int target){
    bool found;
     ppre =NULL;
     ploc = s->head;
     while(ploc!=NULL && target> ploc->data){
         ppre = ploc;
         ploc= ploc->fore;
     }
     if(ploc==NULL)
         found = false;
     else{
         if(ploc->data == target)
             found = true;
         else
             found = false;
     }
     return found;
}
void insert(list*& s, int dataIn){
    node* pred = NULL; 
    node* succ = NULL;
    bool found = search(s , pred , succ , dataIn);
    node* temp = new node;
    temp->data = dataIn;
    if(pred==NULL){
        temp->back=NULL;
        temp->fore=s->head;
        s->head= temp;
    }
    else{
        temp->back= pred;
        temp->fore= succ;
        pred->fore=temp;
    }
    if(succ==NULL){
        s->rear= temp;
    }
    else{
        succ->back=temp;
    }
    s->count++;
}
void traverse(list *s){
    node* temp = s->head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->fore;
    }
    cout<<endl;
}
void traverseBack(list *s){
    node* temp = s->rear;
    while (temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->back;
    }
    cout<<endl;
}
void deleteNode(list *& s ,node*& ploc){
    node* pred = NULL; 
    node* succ = NULL;
    if(ploc->back !=NULL){
    pred = ploc->back;
    pred->fore = ploc->fore;
    }
    else{
        s->head = ploc->fore;
    }
    if(ploc->fore !=NULL){
        succ = ploc->fore;
        succ->back = ploc->back;
    }
    else{
        s->rear = ploc->back;
    }
    delete ploc;
    s->count--;
}
bool FullList(list* s){
    if(new node) return false;
    else return true;
}
bool EmptyList(list* s){
     if(s->count==0) return true;
     else return false;
}
int ListCount(list* s){
    return s->count;
}
int PosFromHead(list* s ,int x){
    int pos=1;
    node* temp = s->head;
    while (temp!=NULL && temp->data < x)
    {
        pos++;
        temp = temp->fore;
    }
    if(temp== NULL) return -1;
    if(temp->data==x) return pos;
    else return -1;
}
int PosFromRear(list* s ,int x){
    int pos=1;
    node* temp = s->rear;
    while (temp!=NULL && temp->data > x)
    {
        pos++;
        temp = temp->back;
    }
    if(temp== NULL) return -1;
    if(temp->data==x) return pos;
    else return -1;
}
void destroyList(list*& s){
    node* t2 = s->head;
    node* t1 =NULL;
    while (t2!=NULL)
    {
        t1 = t2->fore;
        delete t2;
        t2 =t1;
    }
    s->count=0;
    s->head=NULL;
    s->rear =NULL;
}