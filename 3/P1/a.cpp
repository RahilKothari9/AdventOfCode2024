#include<bits/stdc++.h>
#include<regex>
using namespace std;

#define ll long long
#define int long long
#define kr9 kotharirahil9
#define v32 vector<int>

ll MOD = 1e9 + 7;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    
    string s; 
    string x;
    while(cin >> x)s+=x;
    regex r("mul\\([0-9]{1,3},[0-9]{1,3}\\)");

    smatch m;

    sregex_iterator begin(s.begin(), s.end(), r);
    sregex_iterator end;
    int ans = 0;
    for(auto it = begin; it != end; ++it)
    {
        smatch match;
        match = *it;
        string st = match.str(0);
        // cout << st << endl;
        int x = 0;
        int j =4;
        for(j = 4; st[j] != ','; j++)
        {
            x += st[j]-'0';
            x*=10;
        }
        x/=10;
        j++;
        int y = 0;
        for(; st[j] != ')'; j++)
        {
            y += st[j]-'0';
            y*=10;
        }
        y/=10;
        ans += x*y;
    }
    cout << ans << "\n";
}