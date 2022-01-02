#include <iostream>
using namespace std;
struct node{
    int data;
    node *back;
    node *fore;
};
struct list{
    int count;
    node *head;
    node *rear;
};
void createList(list *&);
bool search(list *, node *&, node *&, int);
int insert(list *&, int);
void traverse(list *);
void traverseBack(list *);
void deleteNode(list *&, int);
int PosFromHead(list *, int);
int PosFromRear(list *, int);
bool FullList(list *);
bool EmptyList(list *);
int ListCount(list *);
void destroyList(list *&);
int main(){
    list *cdll = NULL;
    node *ppre;
    node *ploc;
    int choice, re;
    bool f;
    do{
        cout << "1.Create list,\t2.Insert node,\t 3.search,\t 4.traverse,\t 5.traverseBack,\t 6.deleteNode,\t 7.Full List,\t 8.Is Empty, \t9.List count,\t 10.Position of target from Head,\t 11.Position of target from Rear,\t12.Destroy List\n";
        cout << "Enter the option:";
        cin >> choice;
        int x, y;
        switch (choice){
        case 1:
            createList(cdll);
            break;
        case 2:
            cout << "enter the element you want to insert: ";
            cin >> x;
            re = insert(cdll, x);
            if(re==0) cout<<"List is full! Cannot insert\n";
            else if(re == 2) cout<<"Duplicate found. cannot insert element\n";
            break;
        case 3:
            cout << "Enter the elemnt you want to search: ";
            cin >> x;
            f = search(cdll, ppre, ploc, x);
            if (f)
                cout << "Element found!\n";
            else
                cout << "Element not found!\n";
            break;
        case 4:
            traverse(cdll);
            break;
        case 5:
            traverseBack(cdll);
            break;
        case 6:
            cout << "enter the element you want to delete";
            cin >> x;
            deleteNode(cdll, x);

            break;
        case 7:
            if (FullList(cdll))
                cout << "The list is full!!\n";
            else
                cout << "The list is not full\n";
            break;
        case 8:
            if (EmptyList(cdll))
                cout << "The list is empty!\n";
            else
                cout << "The list is not empty\n";
            break;
        case 9:
            cout << "No.of nodes in the list : " << ListCount(cdll) << endl;
            break;
        case 10:
            cout << "Enter the element you want to find the position from Head: ";
            cin >> x;
            y = PosFromHead(cdll, x);
            if (y != -1){
                cout << "Element found at " << y << " from head." << endl;
            }
            else
                cout << "Element not found" << endl;
            break;
        case 11:
            cout << "Enter the element you want to find the position from Rear: ";
            cin >> x;
            y = PosFromRear(cdll, x);
            if (y != -1){
                cout << "Element found at " << y << " from rear end." << endl;
            }
            else
                cout << "Element not found" << endl;
            break;
        case 12:
            destroyList(cdll);
            cout << "List Destroyed!\n";
            break;
        }
    } while (choice <= 12);
}
void createList(list *&ref)
{
    ref = new list;
    ref->head = NULL;
    ref->rear = NULL;
    ref->count = 0;
}
bool search(list *s, node *&ppre, node *&ploc, int target)
{
    bool found;
    ppre = NULL;
    ploc = s->head;
    if (ploc == NULL)
        return false;
    if (ploc->data == target)
        return true;
    if (target < ploc->data)
        return false;
    ppre = ploc;
    ploc = ploc->fore;
    while (ploc != s->head && target > ploc->data){
        ppre = ploc;
        ploc = ploc->fore;
    }
    if (ploc == s->head)
        found = false;
    else{
        if (ploc->data == target)
            found = true;
        else
            found = false;
    }
    return found;
}
int insert(list *&s, int dataIn)
{
    if (FullList(s))
        return 0;
    node *pred = NULL;
    node *succ = NULL;
    bool found = search(s, pred, succ, dataIn);
    if (!found){
        node *temp = new node;
        temp->data = dataIn;
        if (pred == NULL){
            if (s->count == 0){
                s->head = temp;
                s->rear = temp;
            }
            else{
                s->head->back = temp;
                s->rear->fore = temp;
            }
            temp->fore = s->head;
            temp->back = s->rear;
            s->head = temp;
        }
        else{
            temp->back = pred;
            temp->fore = succ;
            pred->fore = temp;
            if (succ == s->head)
            {
                s->rear = temp;
            }
            succ->back = temp;
        }
        s->count++;
        return 1;
    }
    else
        return 2;
}
void traverse(list *s){
    node *temp = s->head;
    if(temp!=NULL){
        cout << temp->data << " ";
        temp = temp->fore;
    }
    while (temp != s->head){
        cout << temp->data << " ";
        temp = temp->fore;
    }
    cout << endl;
}
void traverseBack(list *s){
    node *temp = s->rear;
    if(temp!=NULL){
        cout << temp->data << " ";
        temp = temp->back;
    }
    while (temp != s->rear){
        cout << temp->data << " ";
        temp = temp->back;
    }
    cout << endl;
}
void deleteNode(list *&s, int x){
    node *pred = NULL;
    node *succ = NULL;
    if (search(s, pred, succ, x)){
        if (s->count == 1){
            s->head = NULL;
            s->rear = NULL;
        }
        else{
            if (pred != NULL){
               pred->fore = succ->fore;
               succ->fore->back = pred;
               if(succ == s->rear){
                   s->rear = pred;
               }
            }
            else{
                s->head = succ->fore;
                succ->fore->back = succ->back;
                s->rear->fore = succ->fore;
            }
        }
        delete succ;
        s->count--;
    }
    else{
        cout << "element not present cannot be deleted!" << endl;
    }
}
bool FullList(list *s){
    if (new node)
        return false;
    else
        return true;
}
bool EmptyList(list *s){
    if (s->count == 0)
        return true;
    else
        return false;
}
int ListCount(list *s){
    return s->count;
}
int PosFromHead(list *s, int x){
    int pos = 1;
    node *temp = s->head;
    if(s->count==0) return -1;
    if(temp->data == x) return pos;
    temp = temp->fore;
    pos++;
    while (temp != s->head && temp->data < x){
        pos++;
        temp = temp->fore;
    }
    if (temp->data == x)
        return pos;
    else
        return -1;
}
int PosFromRear(list *s, int x){
    int pos = 1;
    node *temp = s->rear;
    if(s->count==0) return -1;
    if(temp->data == x) return pos;
    temp = temp->back;
    pos++;
    while (temp != s->rear && temp->data > x){
        pos++;
        temp = temp->back;
    }
    if (temp->data == x)
        return pos;
    else
        return -1;
}
void destroyList(list *&s){
    node *t2 = s->head;
    node *t1 = NULL;
    if(s->count!=0){
        t1 = t2;
        t2 = t2->fore;
        delete t1;
        while (t2 != s->head){
            t1 = t2;
            t2 = t2->fore;
            delete t1;
        }
    }
    s->count = 0;
    s->head = NULL;
    s->rear = NULL;
}