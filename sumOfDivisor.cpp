#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll sum_all_divisors(ll num)
{
    ll sum = 0;
    for (ll i = 1; i <= sqrt(num); i++)
    {
        ll t1 = i * (num / i - i + 1);                                   // adding i every time it appears with numbers greater than or equal to itself
        ll t2 = (((num / i) * (num / i + 1)) / 2) - ((i * (i + 1)) / 2); // adding numbers that appear with i and are greater than i
        sum += t1 + t2;
    }
    return sum;
}
int main()
{
    int n=100;
    ll sum = sum_all_divisors(n);
    cout << sum << '\n';
    return 0;
}

