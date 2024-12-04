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

    int n = v.size(), m = v[0].size();
    auto checkLeft = [&](int i, int j) {
        if(v[i][j]=='X')
        {
            if(j - 1 >= 0 && v[i][j-1]=='M')
            {
                if(j-2 >= 0 && v[i][j-2] == 'A')
                {
                    if(j-3>=0 && v[i][j-3] == 'S')
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    };

    auto checkRight = [&](int i, int j) {
        if(v[i][j]=='X')
        {
            if(j + 1 < m && v[i][j+1]=='M')
            {
                if(j+2 < m && v[i][j+2] == 'A')
                {
                    if(j+3 < m && v[i][j+3] == 'S')
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    };

    auto checkTop = [&](int i, int j) {
        if(v[i][j]=='X')
        {
            if(i - 1 >= 0 && v[i-1][j]=='M')
            {
                if(i-2 >= 0 && v[i-2][j] == 'A')
                {
                    if(i-3>=0 && v[i-3][j] == 'S')
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    };

    auto checkBottom = [&](int i, int j) {
        if(v[i][j]=='X')
        {
            if(i + 1 < n && v[i+1][j]=='M')
            {
                if(i+2 < n && v[i+2][j] == 'A')
                {
                    if(i+3 < n && v[i+3][j] == 'S')
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    };

    auto checkDia1 = [&](int i, int j) {
        if(v[i][j]=='X')
        {
            if(i - 1 >= 0 && j - 1 >= 0 && v[i-1][j-1]=='M')
            {
                if(i-2 >= 0 && j-2 >= 0 && v[i-2][j-2] == 'A')
                {
                    if(i-3>=0 && j-3>=0 && v[i-3][j-3] == 'S')
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    };

    auto checkDia2 = [&](int i, int j) {
        if(v[i][j]=='X')
        {
            if(i - 1 >= 0 && j + 1 < m && v[i-1][j+1]=='M')
            {
                if(i-2 >= 0 && j+2 < m && v[i-2][j+2] == 'A')
                {
                    if(i-3>=0 && j+3 < m && v[i-3][j+3] == 'S')
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    };

    auto checkDia3 = [&](int i, int j) {
        if(v[i][j]=='X')
        {
            if(i + 1 < n && j - 1 >= 0 && v[i+1][j-1]=='M')
            {
                if(i+2 < n && j-2 >= 0 && v[i+2][j-2] == 'A')
                {
                    if(i+3 < n && j-3 >= 0 && v[i+3][j-3] == 'S')
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    };

    auto checkDia4 = [&](int i, int j) {
        if(v[i][j]=='X')
        {
            if(i + 1 < n && j + 1 < m && v[i+1][j+1]=='M')
            {
                if(i+2 < n && j+2 < m && v[i+2][j+2] == 'A')
                {
                    if(i+3 < n && j+3 < m && v[i+3][j+3] == 'S')
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    };


    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(checkLeft(i,j))ans++;
            if(checkRight(i,j))ans++;
            if(checkTop(i,j))ans++;
            if(checkBottom(i,j))ans++;
            if(checkDia1(i,j))ans++;
            if(checkDia2(i,j))ans++;
            if(checkDia3(i,j))ans++;
            if(checkDia4(i,j))ans++;
        }
    }
    cout << ans << "\n";
}