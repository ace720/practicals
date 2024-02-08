#include <iostream>
using namespace std;

struct node {
    int data;
    node *next;
};

node *Head = NULL;

bool isEmpty() {
    if (!Head) {
        return 1;
    }
    return 0;
}

void push (int data) {
    node *item = new node();
    item->data = data;
    item->next = NULL;

    item->next = Head;
    Head = item; 
}

int pop() {
    node* temp;
    int data;
    if (isEmpty()) {
        cout <<"No item." <<endl;
        exit(1);
    }
    temp = Head;
    data = temp->data;
    Head = Head->next;
    delete temp;

    return data;
}

int peek() {
    if(isEmpty()) {
        cout << "Empty Stack." << endl;
        exit(1);
    }
    return Head->data;
}

void display() {
    node* temp;
    temp =Head;
    if (isEmpty()) {
        cout <<"Empty Stack." <<endl;
        exit(1);
    }
    cout << "The stack Items are: " << endl;
    while (temp) {
        cout << temp->data << endl;
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    int choice, data;
    while(1) {
        cout <<"\n";
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Display top element" << endl;
        cout << "4. Display all the elements of stack" << endl;
        cout << "5. Quit." << endl;
        cin >> choice;

        switch (choice) {
            case 1: 
            cout << "Enter the element to be Pushed: ";
            cin  >> data;
            push(data);
            break;

            case 2:
            data = pop();
            cout << "Deleted element is:  "<< data;
            break;

            case 3:
            cout << "The topmost element of the Stack is: " << peek();
            break;

            case 4:
            display();
            break;

            case 5:
            exit(1);

            default:
            cout << ("Wrong choice") << endl;
        }
    }

    return 0;
}