#include <iostream>
using namespace std;

struct stock {
    string name;
    char id[3];
    int quantity;
    stock *next;
};

int main() {
    stock *head = NULL;
   
    stock *trav = head;

    for (int i = 1; i <= 3; i++){
        stock *item = new stock();
        cout << "Item name: ";
        cin >> item->name;
        cout << "Item ID: ";
        cin >> item->id;
        cout << "Quantity: ";
        cin >> item->quantity;
        item->next = NULL;
        cout << endl;

        if (!head){
            head = item;
        } else {
            trav = head;
            while (trav->next){
                trav = trav->next;
            }
            trav->next = item;
        }
    }

    stock *itm = new stock();
    itm = head;
    cout << "Item ID: \t Item Name: \t Item Quantity: " << endl;
    for (int m = 1; m <= 3; m++){
        cout << itm->id << "  \t\t" << itm->name << "  \t\t" << itm->quantity;
        cout << endl;
        itm = itm->next;
    }

    return 0;
}