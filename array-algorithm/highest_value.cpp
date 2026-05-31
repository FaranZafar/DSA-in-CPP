#include <iostream>
using namespace std;

int main() {
    int a[8] = {33, 23, 43, 2, 22, 43, 1, 3};
    int maxnum = a[0];

    for (int i = 1; i < 8; i++) {
        if (a[i] > maxnum) {
            maxnum = a[i];
        }
    }

    cout << "maximum number is: " << maxnum << endl;
    return 0;
}