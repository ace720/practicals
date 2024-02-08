#include <iostream>
using namespace std;

struct node {
    string name;
    string age;
    node *link;
};
node *head = NULL;

void mwanzo(node* &nd){
    nd->link = head;
    head = nd;
}

void katik(int pos, int num){
    node  *tmp = head;
    int count = 1;
    while(count <= pos){
        tmp = tmp->link;
        count++;
    }
    for (int i = 1; i <= num; i++){
        node *itm = new node();
        cout << "Enter name:: ";
        cin >> itm->name;
        cout << "Enter age:: ";
        cin >> itm->age;
        itm->link = NULL;

        itm->link = tmp->link;
        tmp->link = itm;
        
    }
}

void end(node* &n){
    node* p = head;
    while (p->link){
        p = p->link;
    }
    p->link = n;
}

void katikati(node* &itm, int ps){
    int count = 1;
    node *tmp =head;

    while(count <= ps){
        tmp = tmp->link;
        count++;
    }
    itm->link = tmp->link;
    tmp->link = itm;
    
}

node* del(){
    node *l = head;
    head = head->link;
    l->link =NULL;
    return l;

}

int main() {

    for (int m = 1; m < 5; m++){
        node *person = new node();
        cout <<"Enter name: " ;
        cin >> person->name;
        cout << "Enter age: ";
        cin >>person->age;
        person->link = NULL;

        if(!head){
            mwanzo(person);
        }else {
            end(person);
        }
    }

    node *n = new node();
    n->name = "Mkadam";
    n->age = "28";
    mwanzo(n);

    katik(1, 3);

    cout<<endl;
    node *itm = head;
    while (itm->link) {
        cout << "Name: " << itm->name<<endl;
        cout <<"Age: " <<itm->age;
        cout<<endl;
        itm = itm->link;
    }

    node *nn = del();
    cout <<"Deleted Node: \n";
    cout << nn->name << "\t" << nn->age <<endl;

    node *tm = head;
    cout <<endl <<"After deleted node:"<<endl;
    while(tm->link){
        cout << "Name: " << tm->name<<endl;
        cout <<"Age: " <<tm->age;
        cout<<endl;
        tm = tm->link;
    }
    return 0;
}