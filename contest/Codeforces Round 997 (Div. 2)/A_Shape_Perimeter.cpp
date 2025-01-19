#include <bits/stdc++.h>

using namespace std;

template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type>
ostream &operator<<(ostream &os, const T_container &v)
{
    os << '{';
    string sep;
    for (const T &x : v)
        os << sep << x, sep = ", ";
    return os << '}';
}
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T)
{
    cerr << ' ' << H;
    dbg_out(T...);
}
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

#define ar array
#define ll long long
#define ld long double
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

void solve()
{
    int n, m;
    cin >> n >> m;
    int x, y;
    cin >> x >> y;
    int x_a = x, y_a = y;
    int t_x = x, t_y = y;
    int ans = n * m * 4;
    for (int i = 1; i < n; i++)
    {
        cin >> x >> y;
        x_a += x;
        y_a += y;
        t_x += m, t_y += m;
        // cout << "x-a" << x_a << " " << y_a << "\n";
        if (x_a < t_x || y_a < t_y)
        {
            int rem = (2 * abs(x_a - t_x) + 2 * abs(y_a - t_y));
            ans = ans - rem;
        }
        // cout << "t-x" << t_x << " " << t_y << "\n";
        t_x = x_a, t_y = y_a;
    }
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++)
    {

        // cout << "Case #" << t << ": ";
        solve();
    }
}