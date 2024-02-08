#include <iostream>
using namespace std;

int main() {
    int arr[] = {100, 3, 1, 7, 50};
    int tmp;

    for (int i = 0; i < 5; i++) {
        for (int m = 4; m >= 0; m--) {
            if (arr[m] < arr[m-1]) {
                tmp = arr[m];
                arr[m] = arr[m-1];
                arr[m-1] = tmp;
            }
        }
    }

    for (int y = 0; y < 5; y++) {
        cout << arr[y] << "\t";
    }
    cout <<endl;

    return 0;
}