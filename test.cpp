#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
const int M = 5e2 + 10;
const double PI = acos(-1);
#define all(s) s.begin(), s.end()
#define sz(s) (int)s.size()
#define endl '\n'
int a, b;
int get(int x)
{
    int cnt = 0;
    while (x)
    {
        ++cnt;
        x /= 10;
    }
    return cnt;
}
vector<int> ans;
vector<int> now;
bool flag(int x)
{
    if (x == 1)
        return false;
    for (int i = 2; i <= x / i; ++i)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}
void add(int x, int t)
{
    if (x == 0)
    {
        long long tt = 0;
        for (auto i : now)
        {
            tt *= 10;
            tt += i;
        }
        int ed = now.size() - 1;
        if (t & 1)
            ed--;
        for (int i = ed; i >= 0; i--)
        {
            tt *= 10;
            tt += now[i];
        }
        if (tt >= a && tt <= b && flag(tt))
            ans.push_back(tt);
        return;
    }
    int st = 0;
    if (x == (t + 1) / 2)
        st = 1;
    for (int i = st; i < 10; ++i)
    {
        now.push_back(i);
        add(x - 1, t);
        now.pop_back();
    }
}
void solve()
{
    cin >> a >> b;
    if (a == 100000000)
        a--;
    if (b == 100000000)
        b--;
    int l = get(a), r = get(b);
    for (int i = l; i <= r; ++i)
    {
        add((i + 1) / 2, i);
    }
    for (auto x : ans)
        cout<<x<<'\n';
}

signed main()
{
    int _ = 1;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    // cin>>_;
    while (_--)
        solve();
    return 0;
}