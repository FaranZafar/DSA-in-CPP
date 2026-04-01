#include <iostream>
using namespace std;

int main() {
    int a[8] = {33, 23, 43, 2, 22, 43, 1, 3};
    int minnum = a[0];

    for (int i = 1; i < 8; i++) {
        if (a[i] < minnum) {
            minnum = a[i];
        }
    }

    cout << "minimum number is: " << minnum << endl;
    return 0;
}