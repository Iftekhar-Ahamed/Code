#include <iostream>
using namespace std;
#define int long long
signed main()
{
    int N, M, a, b;
    cin >> N >> M;
    a = N % 10;
    b = M % 10;

    cout << a + b << endl;
}