#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define int long long
#define kr9 kotharirahil9
#define v32 vector<int>

ll MOD = 1e9 + 7;


bool func(int i, int target, vector<int> &v, string &s)
{
    if(i == v.size()-1)
    {
        int ans = v[0];
        
        for(int j = 0; j < s.size(); j++)
        {
            if(s[j]=='+')
            {
                // if(ans > target - v[i+1])return false;
                ans += v[j+1];
            }
            else
            {
                // if(ans > target/v[i+1])return false;
                ans *= v[j+1];
            }
            if(ans > target)return false;
        }
        
        // cout << s << " " << ans << " " << target << endl;
        return ans == target;
    }

    string x = s+'+';
    string y = s+'*';
    return func(i+1,target,v,x)||func(i+1,target,v,y);
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    vector<int> a;
    vector<vector<int>> mp;
    string temp;
    int k;
    vector<int> v;
    bool flag = true;
    int mx = -1;
    while(cin >> temp)
    {
        // cout << temp << endl;
        // mx = max(mx, (ll)temp.size()-1);
        if(temp[temp.size()-1] == ':')
        {
            if(flag)
            {
                flag = false;
                string x = "";
                for(int i = 0; i < temp.size()-1;i++)x+=temp[i];
                k = stoll(x);
                continue;
            }
            a.push_back(k);
            mp.push_back(v);
            string x = temp;
            x.erase(x.begin()+x.size()-1);

            k = stoll(x);
            v.clear();
        }
        else
        {
            int a = stoll(temp);
            v.push_back(a);
        }
        
    }
    a.push_back(k);
    mp.push_back(v);
    // for(auto &i: mp)
    // {
    //     cout << i.first << ": ";
    //     for(auto &j: i.second)cout << j << " ";
    //     cout << endl;
    // }
    // cout << endl;

    // cout << mx << endl;
    int ans = 0;

    for(int i = 0; i < mp.size(); i++)
    {
        string s = "";
        if(func(0,a[i],mp[i],s))
        {
            ans += a[i];
            // cout << i.first << endl;
        }
        // cout << i.first << endl;
    }

    cout << ans << "\n";

}