#include <iostream>
using namespace std;

struct node {
    int data;
    node *next;
};

node *head = NULL;
node *tail = NULL;

void enqueque(node* &itm) {
    if (!head) {
        head = itm;
        tail = itm;
    } else {
        node *trav = head;
        while (trav->next) {
            trav = trav->next;
        }
        trav->next = itm;
        tail = trav->next;
    }
}

bool isEmpty() {
    bool rs;
    if (!head) {
        rs = true;
    } else {
        rs = false;
    }

    return rs;
}

node* dequeque() {
    if (isEmpty()) {
        cout << "Error ! No item to dequeque " <<endl;
    }
    node *temp = head;
    head = head->next;
    temp->next = NULL;
    
    return temp;
}

int main () {
    for (int m = 1; m < 6; m++) {
        node *item = new node();
        item->data = (m + 10) * 2;
        enqueque(item);
    }

    cout << "Dequequed Items: " << endl;
    while (!isEmpty()) {
        node *dd = dequeque();
        cout << dd->data << endl;
    }

    return 0;
}