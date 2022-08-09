#include <iostream>
#include "add.h"
using namespace std;
int main() {
    int a, b;
    cout << "please input two numbers: " << endl;
    cin >> a >> b;
    cout << "a + b = " << myAdd(a, b) << endl;
    cout << "a - b = " << mySub(a, b) << endl;
    return 0;
}

