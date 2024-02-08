#include <iostream>
using namespace std;

struct node {
    int data;
    node *link;
};

node *head = NULL;
node *tail = NULL;
bool isEmpty();

//Function to add item to the queque
void enqueque (node* &itm) {
    if (head == NULL) {
        head = itm;
    } else {
        node *trav = head;
        while (trav->link != NULL) {
            trav = trav->link;
        }
        trav->link = itm;
        tail = trav->link;
    }
}

/*
Function to delete item on the queque
Delete the first item and return it
*/
node* dequeque() {
    if (isEmpty()) {
        cout << "Error the queque is empty!" << endl;
    }

    node* tmp = head;
    head = head->link;
    tmp->link = NULL;
    
    return tmp;
}
/* 
Checks if the queque is empty
*/
bool isEmpty() {
    bool rs;
    if (!head) {
        rs = true;
    } else {
        rs = false;
    }
    return rs;
}

int main () {
    for (int m = 1; m < 6; m++) {
        node *qq = new node();
        qq->data = m * 2;
        
        enqueque(qq);
    }
    bool value = isEmpty();
    cout << "Que is empty?: " << value << endl;
    
    while (!isEmpty()) {
        node *tt = dequeque();
        cout << "Data: " << tt->data <<endl;
    }
    
    value = isEmpty();
    cout << "Que is empty?: " << value << endl;

    return 0;
}