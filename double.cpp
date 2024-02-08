#include <iostream>
using namespace std;

struct Node {
    Node *right;
    int data;
    Node *left;
};

Node *head = NULL;

//Insert at Beginning
void mwanzo(Node* &item){
    item->right = head;
    item->left = NULL;
    head = item;
}

//Insert Mwishoni
void mwishon(Node* &item){
    Node *trav = head;
    while (trav->right){
        trav = trav->right;   
    }
    trav->right = item;
    item->left = trav;
}

//Insert katikati
void katikati(Node* &item, int pos){
    Node *trav = head;
    pos = pos - 2;
    int count = 0;
    while (count < pos){
        trav = trav->right;
        count++;
    }
    item->left = trav;
    item->right = trav->right;
    trav->right->left = item;
    trav->right = item;
}

//Delete beginning
void dMwanzo(){
    Node *tmp = head;
    head = head->right;
    head->left = NULL;
    delete tmp;
}

//Delete Mwisho
void dMwisho(){
    Node *trav = head;
    while(trav->right){
        trav = trav->right;
    }
    trav->left->right = NULL;
    delete trav;
}

//Delete Katikati
void dkatikat(int pos){
    Node *trav = head;
    pos = pos - 2;
    int count = 0;

    while(count < pos){
        trav = trav->right;
        count++;
    }
    trav->right->left = trav->left;
    trav->left->right = trav->right;
    delete trav;
}

void printLR(){
    Node *tmp = head;
    if (!head){
        cout << "Empty List";
    } else {
        while(tmp){
            cout << tmp->data;
            tmp = tmp->right;
            cout << endl;
        }
    }
}

void printRL(){
    Node *tmp = head;
    if (!head){
        cout << "Empty List";
    } else {
        while(tmp->right){
            tmp = tmp->right;
        }
        while(tmp){
            cout << tmp->data;
            tmp = tmp->left;
            cout << endl;
        }
    }
}

int main(){
    for (int m = 0; m < 20; m++){
        Node *item = new Node();
        item->data = m;
        item->right = NULL;
        item->left = NULL;

        if (!head){
            mwanzo(item);
        } else {
            mwishon(item);
        }
    }
    Node *num = new Node();
    num->data = 8;
    katikati(num, 3);

    cout << "Printing from Left to Right" << endl;
    printRL();
    

    return 0;
}