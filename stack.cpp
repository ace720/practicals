#include <iostream>
using namespace std;

struct node {
    char data;
    node *next;
};

node *head = NULL;

void push (node *itm) {
    if (!head) {
        head = itm;
    } else {
        itm->next = head;
        head = itm;
    }
}

node*  pop() {
    if (!head) {
        cout << "Error ! Empty stack" << endl;
    } else {
        node *tmp = head;
        head = head->next;
        tmp->next = NULL;
        return tmp;
    }
}

int main() {
    node *stack = new node;
    if ()
}