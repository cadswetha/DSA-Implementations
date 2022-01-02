#include <iostream>
using namespace std;
struct edge;
struct vertex{
    char name;
    vertex *nextv;
    edge *firste;
    bool intree;
};
struct edge{
    vertex *dest;
    edge *nexte;
    int wt;
};

void insv(vertex *&, char);
void insarc(vertex *&, char, char , int);
void prims(vertex *&first);
int main(){
    vertex *first = NULL;
    int choice;
    char n, u, v;
    int cost;
    do{
        cout << "enter your choice" << endl;
        cout << "1.insert vertex\t 2. list all vertices \t 3. insert arc\t 4. display all edges\t5.prims" << endl;
        cin >> choice;
        switch (choice){
        case 1:
            cout << "enter vertex name: ";
            cin >> n;
            insv(first, n);
            break;
        case 2:{
            cout << "List of vertices:" << endl;
            vertex *y = first;
            while (y != NULL)
            {
                cout << y->name << " ";
                y = y->nextv;
            }
            cout << endl;
            break;
        }
        case 3:
            cout << "enter end vertices : ";
            cin >> u >> v ;
            cout<<"Enter the edge cost";
			cin>>cost;
            insarc(first, u, v ,cost);
            break;
        case 4:{
            vertex *temp = first;
            while (temp != NULL){
                edge *temp1 = temp->firste;
                while (temp1 != NULL){
                    cout << temp->name << "->" << temp1->dest->name <<"  "<<temp1->wt <<endl;
                    temp1 = temp1->nexte;
                }
                temp = temp->nextv;
            }
            break;
        }
        case 5:
            prims(first);
            cout << endl;
            break;

        default:
            break;
        }
    } while (choice < 6);
}
void insv(vertex *&first, char c){
    vertex *v = new vertex;
    v->name = c;
    v->firste = NULL;
    v->nextv = NULL;
	v->intree=false;
    if (first == NULL)
        first = v;
    else{
        vertex *t = first;
        while (t->nextv != NULL){
            t = t->nextv;
        }
        t->nextv = v;
    }
}
void insarc(vertex *&first, char u, char v , int cost){
    vertex *t = first;
    vertex *t1 = first;
    while (t->name != u){
        t = t->nextv;
    }
    while (t1->name != v){
        t1 = t1->nextv;
    }
    edge *e = new edge;
    e->dest = t1;
    e->nexte = NULL;
   	e->wt=cost;
    if (t->firste == NULL)
        t->firste = e;
    else{
        edge *temp = t->firste;
        while (temp->nexte != NULL){
            temp = temp->nexte;
        }
        temp->nexte = e;
    }
}
void prims(vertex *&first){
    int sum = 0;
    vertex *mindest = NULL;
    int min;
    vertex *s;
    vertex *temp;
    edge *tarc;

    if (first == NULL)
        return;
    else{
        first->intree = true;
        bool treeComplete = false;
        while (!treeComplete){
            treeComplete = true;
            min = 99999;
            mindest = NULL;
            temp = first;
            while (temp != NULL){
                if (temp->intree){
                    tarc = temp->firste;
                    while (tarc != NULL){
                        if (!tarc->dest->intree){
                            treeComplete = false;
                            if (tarc->wt < min){
                                min = tarc->wt;
                                mindest = tarc->dest;
                                s = temp;
                            }
                        }
                        tarc = tarc->nexte;
                    }
                }
                temp = temp->nextv;
            }

            if (mindest != NULL){
                mindest->intree = true;
                sum = sum + min;
                cout << s->name << "->";
                cout << mindest->name << "\n";
            }
        }
        cout << "\nMinimum spanning tree cost=" << sum;
    }
}
