#include <iostream> 
#include <utility>

using namespace std;

void goodSwap02(int &p, int &q) {
    int t = p;
    p = q;
    q = t;
}

void goodSwap01(int *p, int *q) {
    int t = *p;
    *p = *q;
    *q = t;
}

void badSwap(int a, int b) {
    int t = a;
    a = b;
    b = t;
}   

template <typename T>
void auSwap(T &x, T &y) {
    T t = x;
    x = y;
    y = t;
}

int main() {
    cout << "1st int: ";
    int a; 
    cin >> a;

    cout << "2nd int: ";
    int b; 
    cin >> b;

    cout << "std::swap:\n";
    cout << "Before swap a = " << a << ", b = " << b << '\n';
    swap(a, b);
    cout << "After swap a = " << a << ", b = " << b << '\n';

    
    cout << "badSwap:\n";
    cout << "Before swap a = " << a << ", b = " << b << '\n';
    badSwap(a, b);
    cout << "After swap a = " << a << ", b = " << b << '\n';

    
    cout << "goodSwap01:\n";
    cout << "Before swap a = " << a << ", b = " << b << '\n';
    goodSwap01(&a, &b);
    cout << "After swap a = " << a << ", b = " << b << '\n';

    cout << "goodSwap02:\n";
    cout << "Before swap a = " << a << ", b = " << b << '\n';
    goodSwap02(a, b);
    cout << "After swap a = " << a << ", b = " << b << '\n';

    cout << "general swap for doubles:\n";
    double d1 = 2.55;
    double d2 = 4.15;
    cout << "Before swap a = " << a << ", b = " << b << '\n';
    auSwap(d1, d2);
    cout << "After swap a = " << a << ", b = " << b << '\n';
}