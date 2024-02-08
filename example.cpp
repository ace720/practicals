#include <iostream>

using namespace std;

struct Node{
    int number;
    Node *next;
};

int main(int argc, char* argv[]){
    Node *head = NULL;
    for (int i = 1; i < argc; ++i){
        int number = atoi(argv[i]);
        Node *n = new Node();
        n->number = number;
        n->next = NULL;
        n->next = head;
        head = n;
    }

    Node *m = head;
    while(m != NULL){
    cout << m->number <<endl;
        m = m->next;
    }
}