#include <iostream>
using namespace std;

int main() {
    int array[] = {0, 10, 90, 100, -90, -1, 50};
    int tmp;

    for (int m = 0; m < 7; m++) {
        for (int k = 0; k < 7; k++) {
            if (array[k] > array[k+1]) {
                tmp = array[k];
                array[k] = array[k+1];
                array[k+1] = tmp;
            }
        }
    }

    for (int m = 0; m < 7; m++) {
        cout << array[m] << "\t";
    }
    cout << endl;

    return 0;
}