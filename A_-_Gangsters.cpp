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
vector<ll> Gang, C;
vector<bitset<11>> mask;
ll N, M, P, K;
void calculate(ll &cost, ll node, bitset<11> &s)
{

    for (ll i = 0; i < P; i++)
    {
        if (mask[node][i] == 1 && s[i] == 0)
        {
            cost += C[i];
            s[i] = 1;
        }
    }
}

void bfs(ll node, ll pos, vector<vector<ll>> &G)
{
    vector<bool> visit(N + 1, false);

    queue<pair<ll, ll>> q;

    q.push({node, K});

    visit[q.front().first] = true;

    mask[q.front().first][pos] = 1;

    while (!q.empty())
    {
        if (q.front().second == 0)
        {
            q.pop();
            continue;
        }

        for (ll i = 0; i < G[q.front().first].size(); i++)
        {
            if (visit[G[q.front().first][i]] == false)
            {
                visit[G[q.front().first][i]] = true;
                mask[G[q.front().first][i]][pos] = 1;
                q.push({G[q.front().first][i], q.front().second - 1});
            }
        }
        q.pop();
    }
}
struct Compare
{
    bool operator()(tuple<ll, ll, bitset<11>> &p1, tuple<ll, ll, bitset<11>> &p2)
    {
        auto [x, y, z] = p1;
        auto [xx, yy, zz] = p2;

        return x <= xx;
    }
};
void solve()
{
    cin >> N >> M >> P >> K;
    vector<vector<ll>> G(N + 1);
    Gang.resize(P), C.resize(P);
    mask.resize(N + 1, 0);
    for (auto &i : Gang)
    {
        cin >> i;
    }
    for (auto &i : C)
    {
        cin >> i;
    }
    for (ll i = 0; i < M; i++)
    {
        ll x, y;
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }

    for (ll i = 0; i < Gang.size(); i++)
    {
        bfs(Gang[i], i, G);
    }

    ll s, e;
    cin >> s >> e;
    priority_queue<tuple<ll, ll, bitset<11>>, vector<tuple<ll, ll, bitset<11>>>, Compare> pq;

    vector<pair<ll, bitset<11>>> dis(N + 1, {INF, 0});

    ll ccost = 0;

    bitset<11> ms = 0;

    calculate(ccost, s, ms);

    pq.push({ccost, s, ms});

    while (!pq.empty())
    {
        auto [cost, node, ss] = pq.top();
        pq.pop();

        if (dis[node].first == cost && dis[node].second == ss)
        {
            continue;
        }
        else if (dis[node].first < cost)
        {
            continue;
        }

        dis[node].first = cost;
        dis[node].second = ss;

        for (ll i = 0; i < G[node].size(); i++)
        {
            bitset<11> t = ss;
            ll c = cost;
            calculate(c, G[node][i], t);

            if (c < dis[G[node][i]].first)
            {
                pq.push({c, G[node][i], t});
            }
        }
    }
    cout << dis[e].first << nn;
}

int main()
{
    FIO;
    // read;
    // write;
    // testcase
    solve();

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