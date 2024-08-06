//6630300394 teetat pitanupong
#include <iostream>
using namespace std;

int fib(int i, int a[]) {
    if (i == 0) return a[i] = 0;
    if (i == 1) return a[i] = 1;
    return a[i] = fib(i - 1, a) + fib(i - 2, a);
}

int main() {
    int a[20];
    for (int i = 0; i < sizeof(a) / 4; i++) {
        cout << "F(" << i << ") = " << fib(i, a) << endl;
    }
    return 0;
}
