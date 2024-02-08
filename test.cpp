#include <iostream>

using namespace std;

struct bio {
    string name;
    int age;
    float height;
    float weight;
    bio *next;
    bio *prev;
};

int main() {
    bio *head, *dent1, *dent2, *dent3, *dent4, *ptrav;

    //section A
    head = NULL;
    dent1 = new bio();
    dent1->name = "Asio Omary";
    dent1->age = 20;
    dent1->height = 140;
    dent1->weight = 45.5;
    dent1->next = NULL;
    head = dent1;

    //section B
    dent2 = new bio();
    dent2->name = "Bilal Abubakar";
    dent2->age = 21;
    dent2->height = 135;
    dent2->weight = 55.5;
    dent2->next = NULL;
    dent1->next = dent2;

    //section C
    dent3 = new bio();
    dent3->name = "Fainesa Allen";
    dent3->age = 19;
    dent3->height = 130;
    dent3->weight = 40;
    dent3->next = NULL;
    dent2->next = dent3;

    //section D
    dent4 = new bio();
    dent4->name = "Daniel Baha";
    dent4->age = 22;
    dent4->height = 140;
    dent4->weight = 45;
    dent4->next = NULL;
    dent3->next = dent4;

    //section E
    bio *dent5;
    dent5 = new bio();
    dent5->name = "Rhian Corazona";
    dent5->age = 20;
    dent5->height = 143;
    dent5->weight = 45.57;
    dent5->next = NULL;
    dent5->next = dent1->next;
    dent1->next = dent5;

    //section F
    dent2->next = dent4; //ka set nxet node to dent4 kutok DENT 2
    dent3->next = NULL;
    dent3 = NULL;
    delete dent3;

    cout << "\nBio\n";
    ptrav = head;

    while(ptrav) {
        cout << "Name: " << ptrav-> name << endl;
        cout << "Age: " << ptrav->age << endl;
        cout << "Height: " << ptrav->height << endl;
        cout << "Weight: " << ptrav->weight << endl;
        cout << "\n";
        ptrav = ptrav->next;
    }

    return 0;

}