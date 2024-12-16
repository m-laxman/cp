#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s = "codeforces", inp;
        cin >> inp;
        int cnt = 0;
        for (int i = 0; i < 10; i++)
        {
            if (s[i] != inp[i])
                cnt++;
        }
        cout << cnt << "\n";
    }

    return 0;
}