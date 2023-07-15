    #include <bits/stdc++.h>
    using namespace std;

    #define read freopen("wigz.in", "r", stdin)
    #define write freopen("0_output.txt", "w", stdout)
    #define ll long long
    #define INF (ll)1e16
    #define nn "\n"
    #define EPS 1e-9
    #define PI 3.1415926535897932384626433832795
    #define test                 \
        ll ct;                   \
        cin >> ct, cin.ignore(); \
        for (ll i = 1; i <= ct; i++)
    #define testcase cout << "Case " << i << ": ";
    #define Dpos(n) fixed << setprecision(n)
    int dRow[] = {-1, 0, 1, 0, 1, 1, -1, -1};
    int dCol[] = {0, 1, 0, -1, 1, -1, -1, 1};
    const double pi = acos(-1.0);
    const ll mod = 1e9 + 7;
    const ll mXs = 1e6;

    void solve()
    {
        ll n, m, k;
        cin >> n >> m >> k;
        ll a[n][m];
        vector<vector<ll>> v(2);

        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < m; j++)
            {
                cin >> a[i][j];
            }
        }

        for (ll i = 0; i < n; i++)
        {
            ll sum = 0;
            for (ll j = 0; j < m; j++)
            {
                sum += a[i][j];
            }
            v[0].push_back(sum);
        }
        for (ll i = 0; i < m; i++)
        {
            ll sum = 0;
            for (ll j = 0; j < n; j++)
            {
                sum += a[j][i];
            }
            v[1].push_back(sum);
        }
        ll finalanse = -1;
        if (n < m)
        {
            for (ll i = 0; i < (1LL << n); i++)
            {
                if (__popcount(i) > k)
                    continue;

                ll tc[m];
                ll ans = 0;
                for (ll j = 0; j < m; j++)
                    tc[j] = v[1][j];
                ll c = 0;
                for (ll j = 0; j < n; j++)
                {
                    if (i & (1LL << j))
                    {
                        c++;
                        ans += v[0][j];
                        for (ll k = 0; k < m; k++)
                        {
                            tc[k] -= a[j][k];
                        }
                    }
                }
                sort(tc, tc + m, greater<ll>());
                ll ex = k - c;
                for (ll j = 0; j < min(ex, m); j++)
                {
                    ans += tc[j];
                }
                finalanse = max(finalanse, ans);
            }
        }
        else
        {
            for (ll i = 0; i < (1LL << m); i++)
            {
                if (__popcount(i) > k)
                    continue;

                ll tr[n];
                ll ans = 0;
                for (ll j = 0; j < n; j++)
                    tr[j] = v[0][j];
                ll c = 0;
                for (ll j = 0; j < m; j++)
                {
                    if (i & (1LL << j))
                    {
                        c++;
                        ans += v[1][j];
                        for (ll k = 0; k < n; k++)
                        {
                            tr[k] -= a[k][j];
                        }
                    }
                }
                sort(tr, tr + n, greater<ll>());
                ll ex = k - c;
                for (ll j = 0; j < min(ex, n); j++)
                {
                    ans += tr[j];
                }
                finalanse = max(finalanse, ans);
            }
        }
        cout << finalanse << nn;
    }

    int main()
    {
    #ifdef ONLINE_JUDGE
        cin.tie(NULL), ios_base::sync_with_stdio(false);
    #endif
        read;
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
