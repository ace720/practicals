#include <iostream>
using namespace std;

int main(){
    int x = 90, y = 40, z = 60;
    int min;

    min = x;

    if (min < y) {
        if (min < z){
            cout << min << " is the smallest.:X" <<endl;
        }
        else {
            min = z;
            cout << min << " is the smallest.Z1" <<endl;
        }
    } else {
        min = y;
        if (min < z){
            cout << min << " is the smallest.:Y" <<endl;
        } else {
            min = z;
            cout << min << " is the smallest.:Z" <<endl;
        }
    }
}