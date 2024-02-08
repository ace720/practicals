#include <iostream>
using namespace std;

int main() {
    int tmp;
    int arr[] = {6,2,-11,7,5,8};
    for (int i = 0; i < 6; i++) {
        for (int m = 0; m < 6; m++) {
            if (arr[m] > arr[m+1]) {
                tmp = arr[m];
                arr[m] = arr[m+1];
                arr[m+1] = tmp;
            }
        }
    }

    for (int i = 0; i < 6; i++) {
        cout << arr[i] << "\t";
    }
    cout <<endl;

    return 0;
}