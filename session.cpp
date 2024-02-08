#include <iostream>

using namespace std;

struct Stock {
    string stockID;
    char stockName[10];
    Stock *link;
};

void atBeggining (Stock* &node, Stock* &head){
    node->link = head;
    head = node;
}

void atEnd (Stock* &node, Stock* &head){
    Stock *trav = head;
    while (trav->link){
        trav = trav->link;
    }
    trav->link = node;
}

void atPosition (Stock* &node, Stock* &head, int pos){
    int count = 1;
    Stock *trav = head;
    while (count < pos){
        trav = trav->link;
        count++;
    }
    node->link = trav->link;
    trav->link = node;
}

int main() {
    Stock *head = NULL;
    Stock *traversal = head;

    for (int m = 1; m <= 4; m++) {
            Stock *item = new Stock();
            cout << endl << "Enter stock ID: ";
            cin >> item->stockID;
            cout << endl << "Enter stock name: ";
            cin >> item->stockName;
            item->link = NULL;

            if (head == NULL){
                head = item;
            } else {
                traversal = head;

                while (traversal->link != NULL){
                    traversal = traversal->link;
                }
                traversal->link = item;
            }
    }
    //Adding new node at the beginning
    Stock *node = new Stock();
    node->stockID = "2024";
    cout << "Enter stock name: ";
    cin >> node->stockName;
    atBeggining(node, head);

    //Appending at the end
    Stock *itm = new Stock();
    itm->stockID = "29t";
    cout << "Enter stock name: " ;
    cin >> itm->stockName;
    atEnd(itm, head);

    //adding to the 3rd node
    Stock *mm = new Stock();
    mm->stockID = "90t";
    cout << endl << "Enter stock name: ";
    cin >> mm->stockName;
    atPosition(mm, head, 2);

    cout << endl;
    Stock *item = new Stock();
    item = head;
    for (int i = 1; i <= 7; i++) {
        cout <<"Stock ID: " << item->stockID << endl;
        cout << "Stock Name: " << item->stockName << endl;
        item = item->link;
    }

    return 0;
    
}

