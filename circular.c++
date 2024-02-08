#include <iostream>
using namespace std;

struct node {
    node *left;
    int data;
    node *right;
};

node *head = NULL;
node *tail = NULL;

void beginning(node* &itm) {
    itm->right = head;
    head = itm;
    tail = itm;
}

void end(node* &itm) {
    tail->right = itm;
    itm->left = tail;
    tail = itm;
}

void middle(node* &itm, int pos) {
    pos = pos - 2;
    int count = 0;
    node *tmp = head;
    while (count < pos) {
        tmp = tmp->right;
        count++;
    }
    itm->right = tmp->right;
    itm->left = tmp;
    tmp->right->left = itm;
    tmp->right = itm;    
}

void dBeginning() {
    node *tmp = head;
    head = head->right;
    head->left = NULL;
    delete tmp;
}

void dEnd() {
    node *tmp = tail;
    tail = tail->left;
    tail->right = NULL;
    delete tmp;
}

void dMiddle(int pos) {
    pos = pos - 2;
    int count = 0;
    node *tmp = head;
    while (count < pos) {
        tmp = tmp->right;
        count++;
    }
    tmp->right->left = tmp->left;
    tmp->left->right = tmp->right;
    delete tmp;
}

int size() {
    int s = 0;
    node *tmp = head;
    while (tmp->right) {
        tmp = tmp->right;
        s++;
    }
    return s;
}

void printLR() {
    node *tmp = head;
    while (tmp){
        cout << "Data: " << tmp->data << endl;
        tmp = tmp->right;
    }
}

void printRL() {
    node *tmp = tail;
    while (tmp) {
        cout << "Data: " << tmp->data << endl;
        tmp = tmp->left;
    }
}

int main() {
    for (int i = 0; i < 5; i++){
        node *item = new node();
        item->data = i*10;
        if (!head){
            beginning(item);
        } else {
            end(item);
        }
    }
    cout <<"Size: " <<size()<<endl;
    cout << "Left to right: " << endl;
    printLR();
    cout << endl;
    dEnd();
    dBeginning();
    dMiddle(3);

    cout << "Right to Left: " << endl;
    printRL();

    cout << "Head: " << head->data <<endl;
    cout << "Tail: " << tail->data << endl;

    return 0;
}