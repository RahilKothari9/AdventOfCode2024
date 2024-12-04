#include<bits/stdc++.h>
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

    vector<string> v;
    string x;
    while(cin >> x)v.push_back(x);

    
    int n = v.size();
    int m = v[0].size();

    auto isValid = [&](int i, int j)
    {
        if(i < 0 || i >= n || j < 0 || j >= m)return false;
        return true;
    };

    auto checkLeft = [&](int i, int j)
    {
        if(isValid(i,j)&&(v[i][j]=='M'||v[i][j]=='S')&& isValid(i-2,j-2)&&(((v[i-2][j-2]=='M'||v[i-2][j-2]=='S') && v[i][j] != v[i-2][j-2])))
            if(isValid(i-1,j-1)&&v[i-1][j-1]=='A')
                if(isValid(i,j-2)&&(v[i][j-2]=='M'||v[i][j-2]=='S')&& isValid(i-2,j)&&(((v[i-2][j]=='M'||v[i-2][j]=='S') && v[i][j-2] != v[i-2][j])))
                    return 1;
        return 0;
    };
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(checkLeft(i,j))ans++;
        }
    }
    cout << ans << "\n";
}