#include <iostream>
using namespace std;

struct node {
    node *left;
    int data;
    node *right;
};

node *head = NULL;
node *tail = NULL;

void beginning( node* &itm) {
    if (head == NULL) {
        head  = itm;
        tail = itm;
        itm->left = itm;
        itm->right = itm;
    } else {
        itm->right = head;
        head->left->right = itm;
        itm->left = head->left;
        head->left = itm;
        head = itm;
    }
}

void end(node* &itm) {
    itm->left = tail;
    itm->right = tail->right;
    tail->right->left = itm;
    tail->right = itm;
    tail = itm;
}

void middle(node* &itm, int pos) {
    pos = pos - 2;
    int count = 0;
    node *tmp = head;
    while(count < pos) {
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
    head->left = tmp->left;
    tmp->left->right = head;
    delete tmp;
}

void dEnd() {
    node *tmp = tail;
    tail = tail->left;
    tail->right = tmp->right;
    tmp->right->left = tail;
    delete tmp;
}

void dMiddle(int pos) {
    pos = pos - 1;
    node *tmp = head;
    int count = 0;
    while (count < pos) {
        tmp = tmp->right;
        count++;
    }
    tmp->left->right = tmp->right;
    tmp->right->left = tmp->left;
    delete tmp;
}

int size(){
    node *tmp = head;
    int s = 1;
    while (tmp->right != head){
        tmp = tmp->right;
        s++;
    }
    return s;
}

void printLR() {
    node *tmp = head;
    cout << "Printing Left to Right: " <<endl;
    cout <<"Data: " << tmp->data <<endl;
    tmp = tmp->right;
    while (tmp != head) {
        cout <<"Data: " << tmp->data <<endl;
        tmp = tmp->right;
    }
}

void printRL() {
    node *tmp = tail;
    cout << "Printing Right to Left: " <<endl;
    cout << "Data: " << tmp->data <<endl;
    tmp = tmp->left;
    while (tmp != tail) {
        cout << "Data: " << tmp->data <<endl;
        tmp = tmp->left;
    }
}

int main() {
    for (int i = 1; i <= 7; i++){
        node *item = new node();
        item->data = i*10;

        if (!head) {
            beginning(item);
        } else {
            end(item);
        }
    }
    
    node *b = new node();
    b->data = 0;
    beginning(b);
    //dBeginning();

    node *bb = new node();
    bb->data = 100;
    middle(bb, 3);
    //dMiddle(3);

    cout << "Head: " << head->data << endl;
    cout << "Tail: " << tail->data << endl;
    cout <<"List size: " << size() << endl;
    printLR();


    printRL();
   

    return 0;

}