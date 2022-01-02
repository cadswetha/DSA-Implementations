#include<iostream>
using namespace std;
struct node{
    int data;
    node* link;
};
struct list{
    int count;
    node* head;
};
void createList(list* &);
bool search(list* , node* & ,node *& ,int);
void insert(list*&,node* &,int);
void display(list *);
void deleteNode(list *& , node*& ,node*& , int&);
bool retrieveNode(list* , int ,int&);
bool EmptyList(list* );
int ListCount(list* );
void destroyList(list*& );
int main(){
    list* sll =NULL;
    node* ppre;
    node* ploc;
    int o;
    bool f;
    do{
    cout<<"1.Create list, 2.Insert node, 3.search, 4.display, 5.deleteNode, 6.retriveNode, 7.Is empty, 8.List count, 9.Destroy List\n";
    cout<<"Enter the option:";
    cin>>o;
    int x,r;
    switch(o){
        case 1:
            createList(sll);
            break;
        case 2:
            cout<<"enter the element you want to insert: ";
            cin>>x;
            f = search(sll , ppre ,ploc ,x);
            insert(sll, ppre , x);
            break;
        case 3:
            cout<<"Enter the elemnt you want to search: ";
            cin>>x;
            f = search(sll , ppre ,ploc ,x);
            if(f) cout<<"Element found!\n";
            else cout<<"Element not found!\n";
            break;
        case 4:
            display(sll);
            break;
        case 5:
            cout<<"enter the element you want to delete";
            cin>>x;
            if(search(sll ,ppre , ploc ,x)){
                deleteNode(sll , ppre,ploc,r);
                cout<<"element deleted is : "<<r<<endl;
            }
            else{
                cout<<"element not present cannot be deleted!"<<endl;
            }
            break;
        case 6:
            cout<<"enter the elemnt you want to retrive: ";
            cin>>x;
            retrieveNode(sll , x, r);
            cout<<"After retrieving: "<<r<<endl;
            break;
        case 7:
            if(EmptyList(sll)) cout<<"The list i empty!\n";
            else cout<<"The list is not empty\n";
            break;
        case 8 : 
            cout<<"No.of nodes in the list : "<<ListCount(sll)<<endl;
            break;
        case 9 : 
            destroyList(sll);
            cout<<"List Destroyed!\n";
            break;
    }
    }while(o<=9);
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
         ploc= ploc->link;
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
void insert(list*& s , node*& ppre ,int dataIn){
    node* temp = new node;
    temp->data = dataIn;
    if(ppre==NULL){
        temp->link = s->head;
        s->head = temp;
    }
    else{
        temp->link = ppre->link;
        ppre->link = temp;
    }
    s->count++;
}
void display(list *s){
    node* temp = s->head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->link;
    }
    cout<<endl;
}
void deleteNode(list *& s , node*& ppre ,node*& ploc, int& dataOut){
    dataOut = ploc->data;
    if(ppre==NULL)
      s->head = ploc->link;
    else 
      ppre->link = ploc->link;
    delete ploc;
    s->count--;
}
bool retrieveNode(list* s, int key ,int& dataOut){
    node* ppre;
    node* ploc;
    bool fo = search(s, ppre , ploc , key);
    if(fo)
      dataOut = ploc->data;
    return fo; 
}
bool EmptyList(list* s){
     if(s->count==0) return true;
     else return false;
}
int ListCount(list* s){
    return s->count;
}
void destroyList(list*& s){
    node* t1 = s->head;
    node* t2 = NULL;
    while(t1!=NULL){
        t2 = t1->link;
        delete t1;
        t1 = t2;
    }
    s->count = 0;
    s->head = NULL;
}