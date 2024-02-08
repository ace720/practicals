#include <iostream>
using namespace std;

struct node {
    int data;
    node *link;
};

node *head = NULL;
node *tail = NULL;

//Function to add node on the first position of List.
void beginning(node* &itm) {
    if (head == NULL) {
        head = itm;
        tail = itm;
        tail->link = head;
    } else {
        itm->link = head;
        head = itm;
        tail->link = head;
    }
}

//Function to add node on the end of the list
void end(node* &itm) {
    itm->link = tail->link;
    tail->link = itm;
    tail = itm;
}

//Function to add node on the Nth position
void middle(node* &itm, int pos) {
    node* trav = head;
    node* p = head->link;
    int count = 0;
    while(count < pos - 2) {
        trav = trav->link;
        p = p->link;
        count++;
    }
    trav->link = itm;
    itm->link = p;
}

//Function to delete the first node on the list 
void dBeginning() {
    node *temp = head;
    head = head->link;
    temp->link = NULL;
    tail->link = head;
    delete temp;
}

//Function to delete the last node on the list
void dEnd() {
    node *temp = head->link;
    node *p = head;
    while (temp->link != head) {
        p = p->link;
        temp = temp->link;
    }
    p->link = temp->link;
    tail = p;
    temp->link = NULL;
    delete temp;
}

//Function to delete the Nth node
void dMiddle (int pos) {
    pos = pos - 2;
    node *p = head;
    node *n = head->link;
    int count = 0;
    while (count < pos) {
        p = p->link;
        n = n->link;
        count++;
    }
    p->link = n->link;
    n->link = NULL;
    delete n;
}

//Function to display the size of the link;
int size() {
    node* trav = head->link;
    int size = 1;
    if (!head) {
        size = 0;
    } else {
        while (trav != head) {
        trav = trav->link;
        size++;
    }
    }
    return size;
}

//Function to display the node on the list from left to right
void print() {
    node* trav = head;
    cout <<"Data: " << trav->data << endl;
    trav = trav->link;
    while (trav != head) {
        cout <<"Data: " << trav->data << endl;
        trav = trav->link;
    }
}

int main() {
    for (int m = 1; m < 6; m++) {
        node *item = new node();
        item->data = m % 2;
        if (!head ) {
            beginning(item);
        } else {
            end(item);
        }
    }
    node *nn = new node();
    nn->data = 10;
    beginning(nn);

    node *mm = new node();
    mm->data = 50;
    middle(mm, 4);

    node *zz = new node();
    zz->data = 100;
    end(zz);

    //delete the second node
    dMiddle(2);
    //delete the last node
    dEnd();
    //print the size of the link
    cout << size() << endl;
    //Display all the nodes of the link
    print();

    return 0;
}