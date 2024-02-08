#include <iostream>
using namespace std;

struct node {
    int data;
    node *right;
};

node *head = NULL;

void beginning (node* &itm) {
    if (head == NULL) {
        head = itm;
    } else {
        itm->right = head;
        head = itm;
    }
}

void end (node* &itm) {
    node *temp = head;
    while (temp->right != NULL) {
        temp = temp->right;
    }
    temp->right = itm;
}

void middle (node* &itm, int pos) {
    node* temp = head;
    int count = 0;
    while (count < pos-2) {
        temp = temp->right;
        count++;
    }
    itm->right = temp->right;
    temp->right = itm;
}

void dBeginning() {
    node *temp = head;
    head = head->right;
    temp->right = NULL;
    delete temp;
}

void dEnd() {
    node *temp = head;
    while (temp->right->right != NULL) {
        temp = temp->right;
    }
    delete temp->right;
    temp->right = NULL;

}

void dMiddle(int pos) {
    node* temp = head;
    node *tmp = head->right;
    int count = 0;
    while (count < pos-2) {
        temp = temp->right;
        tmp = tmp->right;
        count++;
    }
    temp->right = tmp->right;
    delete tmp;
}

void print(){
    node *trav = head;
    while (trav != NULL) {
        cout << "Data: " << trav->data << endl;
        trav = trav->right;
    }
}

int size() {
    node *trav = head;
    int size = 0;
    if (head != NULL) {
        while (trav != NULL) {
            size++;
            trav = trav->right; 
        }
    } else {
        size = 0;
    }
    return size;
}

int main() {
    for (int i = 1; i <= 20; i++) {
        node *item = new node();
        item->data = i*10;

        if (head == NULL) {
            beginning(item);
        } else {
            end(item);
        }
    }

    int ss = size();
    cout << "Size: " << ss << endl;
    dMiddle(7);
    

    node *nn = new node();
    nn->data = 12;
    middle(nn, 3);

    print();

    return 0;
}