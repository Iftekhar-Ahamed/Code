/***
**      Bismillahir Rahmanir Rahim
**              ALLAHU AKBAR
**
**     Author: Iftekhar Ahamed Siddiquee
**     Bangladesh University of Business and Technology,
**     Dept. of CSE.
***/
#include <bits/stdc++.h>
using namespace std;

#define FIO cin.tie(NULL), ios_base::sync_with_stdio(false)
#define read freopen("0_input.txt", "r", stdin)
#define write freopen("0_output.txt", "w", stdout)
#define ll long long
#define INF (ll)1e16
#define nn "\n"
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define test   \
    ll ct;     \
    cin >> ct; \
    for (ll i = 1; i <= ct; i++)
#define testcase cout << "Case " << i << ": ";
#define Dpos(n) fixed << setprecision(n)
int dRow[] = {-1, 0, 1, 0, 1, 1, -1, -1};
int dCol[] = {0, 1, 0, -1, 1, -1, -1, 1};
const double pi = acos(-1.0);
const ll mod = 1e9 + 7;
const ll mXs = 1e6;

struct Bigint
{
    // representations and structures
    string a; // to store the digits
    int sign; // sign = -1 for negative numbers, sign = 1 otherwise
    // constructors
    Bigint() {}                       // default constructor
    Bigint(string b) { (*this) = b; } // constructor for string
    // some helpful methods
    int size()
    { // returns number of digits
        return a.size();
    }
    Bigint inverseSign()
    { // changes the sign
        sign *= -1;
        return (*this);
    }
    Bigint normalize(int newSign)
    { // removes leading 0, fixes sign
        for (int i = a.size() - 1; i > 0 && a[i] == '0'; i--)
            a.erase(a.begin() + i);
        sign = (a.size() == 1 && a[0] == '0') ? 1 : newSign;
        return (*this);
    }
    // assignment operator
    void operator=(string b)
    { // assigns a string to Bigint
        a = b[0] == '-' ? b.substr(1) : b;
        reverse(a.begin(), a.end());
        this->normalize(b[0] == '-' ? -1 : 1);
    }
    // conditional operators
    bool operator<(const Bigint &b) const
    { // less than operator
        if (sign != b.sign)
            return sign < b.sign;
        if (a.size() != b.a.size())
            return sign == 1 ? a.size() < b.a.size() : a.size() > b.a.size();
        for (int i = a.size() - 1; i >= 0; i--)
            if (a[i] != b.a[i])
                return sign == 1 ? a[i] < b.a[i] : a[i] > b.a[i];
        return false;
    }
    bool operator==(const Bigint &b) const
    { // operator for equality
        return a == b.a && sign == b.sign;
    }
    // mathematical operators
    Bigint operator+(Bigint b)
    { // addition operator overloading
        if (sign != b.sign)
            return (*this) - b.inverseSign();
        Bigint c;
        for (int i = 0, carry = 0; i < a.size() || i < b.size() || carry; i++)
        {
            carry += (i < a.size() ? a[i] - 48 : 0) + (i < b.a.size() ? b.a[i] - 48 : 0);
            c.a += (carry % 10 + 48);
            carry /= 10;
        }
        return c.normalize(sign);
    }
    Bigint operator-(Bigint b)
    { // subtraction operator overloading
        if (sign != b.sign)
            return (*this) + b.inverseSign();
        int s = sign;
        sign = b.sign = 1;
        if ((*this) < b)
            return ((b - (*this)).inverseSign()).normalize(-s);
        Bigint c;
        for (int i = 0, borrow = 0; i < a.size(); i++)
        {
            borrow = a[i] - borrow - (i < b.size() ? b.a[i] : 48);
            c.a += borrow >= 0 ? borrow + 48 : borrow + 58;
            borrow = borrow >= 0 ? 0 : 1;
        }
        return c.normalize(s);
    }
    Bigint operator*(Bigint b)
    { // multiplication operator overloading
        Bigint c("0");
        for (int i = 0, k = a[i] - 48; i < a.size(); i++, k = a[i] - 48)
        {
            while (k--)
                c = c + b;                // ith digit is k, so, we add k times
            b.a.insert(b.a.begin(), '0'); // multiplied by 10
        }
        return c.normalize(sign * b.sign);
    }
    Bigint operator/(Bigint b)
    { // division operator overloading
        if (b.size() == 1 && b.a[0] == '0')
            b.a[0] /= (b.a[0] - 48);
        Bigint c("0"), d;
        for (int j = 0; j < a.size(); j++)
            d.a += "0";
        int dSign = sign * b.sign;
        b.sign = 1;
        for (int i = a.size() - 1; i >= 0; i--)
        {
            c.a.insert(c.a.begin(), '0');
            c = c + a.substr(i, 1);
            while (!(c < b))
                c = c - b, d.a[i]++;
        }
        return d.normalize(dSign);
    }
    Bigint operator%(Bigint b)
    { // modulo operator overloading
        if (b.size() == 1 && b.a[0] == '0')
            b.a[0] /= (b.a[0] - 48);
        Bigint c("0");
        b.sign = 1;
        for (int i = a.size() - 1; i >= 0; i--)
        {
            c.a.insert(c.a.begin(), '0');
            c = c + a.substr(i, 1);
            while (!(c < b))
                c = c - b;
        }
        return c.normalize(sign);
    }
    // output method
    void print()
    {
        if (sign == -1)
            putchar('-');
        for (int i = a.size() - 1; i >= 0; i--)
            putchar(a[i]);
    }
};

void solve()
{
    Bigint a, b, c;
    string s;
    cin >> s;
    a = s;
    string t = s;
    cin >> s;
    sort(t.begin(), t.end());
    sort(s.begin(), s.end());
    cout << t << " " << s << nn;
}

int main()
{
    FIO;
    // read;
    // write;
    test
    {
        // testcase
        solve();
    }
    return 0;
}
/*
 * do something instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */
/* Final check before submit :
1. array size or integer overflow,like uninitialised 0 index.
2. Think twice,code once.check all possible counter test case.
3. Be careful about corner case! n=1?k=1? something about 0?
4. avoid stupid mistake!complexity(t/m)?precision error?submit same code twice?
5. if got WA than remember that you are missing something common.
*** Be confident!!! who knows? may be your one step back to AC ***
4. minus mod ans=(ans-k+mod)%mod;
*/
/* IF WA???
1. corner case! n=1?k=1? something about 0?
2. check code(avoid stupid mistake)
3. read the statement again(if there any missing point???)
4. check the idea(check all possible counter test case again!!!)
5. be calm,don't be panic!!!.(***this problem not going to decide your future***)
6. don't waste too much time. move to next problem
*/