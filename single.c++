#include <iostream>
using namespace std;

struct node{
    int data;
    node *next;
};

node *head = NULL;

void mwanzo(node* &itm) {
    if (head == NULL) {
        head = itm;
    } else {
        itm->next = head;
        head = itm;
    }

}

void mwisho(node* &itm) {
    node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = itm;
}

void middle (node* &itm, int pos) {
    node *trav = head;
    int count = 0;
    while (count < pos-2) {
        trav = trav->next;
        count++;
    }
    itm->next = trav->next;
    trav->next = itm;
}

int main() {
    for (int i = 1; i < 5; i++) {
        node *item = new node();
        item->data = i*2;
        if (head == NULL) {
            mwanzo(item);
        } else {
            mwisho(item);
        }
    }
    node *nn = new node();
    nn->data = 99;
    mwanzo(nn);

    node *p = new node();
    p->data  = 0;
    middle(p, 3);   

    node *temp = head;
    while (temp != NULL) {
        cout << temp->data << endl;
        temp = temp->next;
    }

    return 0;
}