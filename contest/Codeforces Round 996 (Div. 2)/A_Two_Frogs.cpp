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

bool is_valid(int n, int p)
{
    if (p >= 1 && p <= n)
        return true;
    return false;
}

void solve()
{
    int n, a, b;
    cin >> n >> a >> b;
    bool alice_win = false, a_turn = true;
    int k = max(a, b), i = 0;
    while (i < k)
    {
        if (a_turn)
        {
            if (abs(a - 1 - b) < abs(a + 1 - b))
            {
                if (is_valid(n, a - 1) && a - 1 != b)
                {
                    a -= 1;
                    alice_win = true;
                }
            }
            else
            {
                if (is_valid(n, a + 1) && a + 1 != b)
                {
                    a += 1;
                    alice_win = true;
                }
            }
            a_turn = false;
        }
        else
        {
            if (abs(b - 1 - a) < abs(b + 1 - a))
            {
                if (is_valid(n, b - 1) && b - 1 != a)
                {
                    b -= 1;
                    alice_win = false;
                }
            }
            else
            {
                if (is_valid(n, b + 1) && b + 1 != a)
                {
                    b += 1;
                    alice_win = false;
                }
            }
            a_turn = true;
        }
        i++;
    }
    cout << (alice_win == true ? "YES\n" : "NO\n");
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