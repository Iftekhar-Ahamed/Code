#include <cmath>
#include <iostream>
using namespace std;

int main() {
    int t;
    long long n, x, y;
    t=100;
    while (t--) {
        n=t;
        x = 1 + 8 * n;
        y = sqrt(x);
        if (x == y * y) cout << n << " eh perfeito\n";
        else cout << n << " nao eh perfeito\n";
    }
    return 0;
}
