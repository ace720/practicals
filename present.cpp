#include <iostream>
using namespace std;

struct Stock {
    string iName;
    char ID[3];
    int iQuantity;
    Stock *next;
};

Stock *head = NULL;

//Ingiza data mwanzoni
void atBeginning(Stock* &item){
    item->next = head;
    head = item;
}

//Ingiza data mwishoni
void atEnd(Stock* &item){
    Stock *trav = head;
    while(trav->next){
        trav = trav->next;
    }
    trav->next = item;
}

//Ingiza data katikati
void atAnyP(Stock* &item, int pos){
    pos = pos - 2;
    int count =0 ;
    Stock *trav = head;

    while(count < pos){
        trav = trav->next;
        count++;
    }
    item->next = trav->next;
    trav->next = item;
}

void multNodes(int num){
    for (int i = 1; i <= num; i++){
      Stock *item = new Stock();
        cout << "Enter Item name: ";
        cin >> item->iName;
        cout << "Enter Item ID: ";
        cin >> item->ID;
        cout << "Enter Item Quantity: ";
        cin >> item->iQuantity;
        item->next = NULL;
        cout << endl;  
        atAnyP(item, num);
    }
}

//Futa mwanzoni
void dMwanzo(){
    Stock *deleted = head;
    head = head->next;
    deleted->next = NULL;
    delete deleted;
}

//Futa Mwisho
void dMwisho(){
    Stock *p = head;
    while(p->next->next){
        p = p->next;
    }
    delete p->next;
    p->next = NULL;

}

//Futa katikati
void dkatikat(int pos){
    Stock *p= head;
    Stock *q = head->next;
    pos = pos - 2;
    for (int i = 0; i < pos; i++ ){
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    q->next = NULL;

    delete q;
}

//Delete the List
void Destroy(){
    Stock *tmp;
    while(head){
        tmp = head;
        head = head->next;
        delete tmp;
    }
}

//Print nodes
void print(){
    Stock *tmp = head;
    while (tmp){
        cout <<"Item Name: " << tmp->iName;
        cout <<" Item ID: " << tmp->ID;
        cout <<" Item Quantity: " << tmp->iQuantity;
        cout <<endl;
        tmp = tmp->next;
    }
}

int main(){
    for (int i = 1; i <= 3; i++){
        Stock *item = new Stock();
        cout << "Enter Item name: ";
        cin >> item->iName;
        cout << "Enter Item ID: ";
        cin >> item->ID;
        cout << "Enter Item Quantity: ";
        cin >> item->iQuantity;
        item->next = NULL;
        cout << endl;
        
        if (head == NULL){
           atBeginning(item);
        } else {
            atEnd(item);
        }
    }
    Stock *item = new Stock();
        cout << "Enter Item name: ";
        cin >> item->iName;
        cout << "Enter Item ID: ";
        cin >> item->ID;
        cout << "Enter Item Quantity: ";
        cin >> item->iQuantity;
        item->next = NULL;

        atEnd(item);

   print();

   Stock *nn = new Stock();
   cin >> nn->ID ;
   nn->iName = "3";
   nn->iQuantity = 3; 
   atAnyP(nn, 1);

   cout <<"Print after addition: " <<endl;
   print();

   dkatikat(2);
   cout <<endl;

   cout << "Print after katikati: ";
   print();

    
}