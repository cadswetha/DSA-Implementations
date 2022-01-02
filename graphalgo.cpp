#include<iostream>
using namespace std;
struct edge;
struct vertex{
    char name;
    vertex* nextv;
    edge* firste;
    bool visited;
    bool inqueue ;
    bool instack;
};
struct edge{
    vertex* dest;
    edge* nexte;
};
struct Q{
    vertex* var;
    Q* link;
};
struct Stack{
    vertex* var;
    Stack* link;
};
void push(Stack*&  ,vertex* );
vertex* pop(Stack*&);
void insv(vertex*& , char );
void insarc(vertex*& , char ,char);
void BFS(vertex*);
void DFT(vertex*);
void Enqueue(Q*&  , Q*& ,vertex*);
vertex* Dequeue(Q*& ,Q*&);

int main(){
    vertex* first = NULL;
    int choice;
    Q* qp = NULL;
    char n,u,v;
    do{
        cout<<"enter your choice"<<endl;
        cout<<"1.insert vertex\t 2. list all vertices \t 3. insert arc\t 4. display all edges\t5.BFS\t6.DFT"<<endl;
        cin>>choice;
        switch (choice)
        {
        case 1:
            cout<<"enter vertex name: ";
            cin>>n;
            insv(first, n );
            break;
        case 2:{
            cout<<"List of vertices:"<<endl;
            vertex* y = first;
            while (y!=NULL){
                cout<<y->name<<" ";
                y= y->nextv;
            }
            cout<<endl;
            break;
        } 
        case 3:
            cout<<"enter end vertices : " ;
            cin>>u>>v;
            insarc(first,u,v);
            break;
        case 4:{
            vertex* temp = first;
            while(temp!=NULL){
                edge* temp1 = temp->firste;
                while(temp1!=NULL){
                    cout<<temp->name<<"->"<<temp1->dest->name<<endl;;
                    temp1 = temp1->nexte;
                }
                temp = temp->nextv;
            }
            break;
        }
        case 5 :
           BFS(first);
           cout<<endl;
           break;
        case 6:
           DFT(first);
           cout<<endl;
           break;
        default:
            break;
        }
    }while(choice<=6);
}
void Enqueue(Q*&front , Q*& rear,vertex* val){
    Q* temp = new Q;
    temp->var = val;
    temp->link= NULL;
    if(rear == NULL){
        front = rear = temp;
        return;
    }
    rear->link = temp;
    rear = temp;
}
vertex* Dequeue(Q*&front , Q*& rear){
    if(front==NULL) return NULL;
    Q* t = new Q;
    t = front;
    front = front->link;
    if(front==NULL){
        rear = NULL;
    }
    return t->var;
}
void insv(vertex*& first , char c){
     vertex* v = new vertex;
     v->name = c;
     v->firste = NULL;
     v->nextv = NULL;
     if(first==NULL) first = v;
     else{
        vertex* t = first;
        while(t->nextv != NULL){
            t = t->nextv;
        }
        t->nextv = v;
     }
}
void push(Stack*& first ,vertex* v){
     Stack* temp = new Stack;
     temp->var = v;
     temp->link = first;
     first = temp;
}
vertex* pop(Stack*& first){
    Stack* temp = first;
    if(first!=NULL)
      first = first->link;
    return temp->var;
}
void insarc(vertex*& first, char u ,char v){
    vertex* t = first;
    vertex* t1 = first;
    while(t->name!=u){
        t= t->nextv;
    }
    while(t1->name!=v){
        t1= t1->nextv;
    }
   edge* e = new edge;
   e->dest = t1;
   e->nexte = NULL;
   if(t->firste == NULL) t->firste = e;
   else{
       edge* temp = t->firste;
       while (temp->nexte!=NULL){
           temp = temp->nexte;
       }
       temp->nexte = e;
   }
}
void DFT(vertex* first){
    if(first == NULL) return;
    Stack* front= NULL;
    vertex* y = first;
    vertex* temp1;
    edge* temp2;
    while (y!=NULL){
        y->visited = false;
        y->instack = false;
        y= y->nextv;
    }
    y = first;
    while(y!=NULL){
        if(y->visited == false && y->instack==false){
           push(front,y);
           y->instack = true;
           while(front!=NULL){
               temp1= pop(front);
               cout<<temp1->name<<" ";
               temp1->visited=true;
               temp1->instack=false;
               temp2=temp1->firste;
               while(temp2!=NULL){
                   if(temp2->dest->visited==false && temp2->dest->instack==false){
                     push(front,temp2->dest);
                     temp2->dest->instack=true;
                   }
                   temp2=temp2->nexte;
               }
           }
        }
        y = y->nextv;
    }
}
void BFS(vertex* first){
    if(first==NULL) return;
    Q* front = NULL;
    Q* rear = NULL;
    vertex* y = first;
    vertex* temp;
    edge* temp2;
    while (y!=NULL){
        y->visited = false;
        y->inqueue = false;
        y= y->nextv;
    }
    y = first;
    while(y!=NULL){
        if(y->visited == false){
            if(y->inqueue==false){
                Enqueue(front , rear , y);
                y->inqueue = true;
            }
            while(front!=NULL){
                 temp = Dequeue(front ,rear);
                 cout<<temp->name<<" ";
                 temp->visited = true;
                 temp->inqueue=false;
                 temp2= temp->firste;
                 while(temp2!=NULL){
                    if(temp2->dest->inqueue==false && temp2->dest->visited==false){
                        Enqueue(front , rear,temp2->dest);
                        temp2->dest->inqueue = true;
                    }
                    temp2 = temp2->nexte;
                 }
            }
        }
        y = y->nextv;
    }
}