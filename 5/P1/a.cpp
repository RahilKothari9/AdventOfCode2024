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

    vector<vector<int>> order(100);

    string temp;
    int ans = 0;
    while(cin >> temp)
    {
        if(temp.size()==5 && temp[2]=='|')
        {
            int n1 = (temp[0]-'0')*10+temp[1]-'0';
            int n2 = (temp[3]-'0')*10+temp[4]-'0';
            order[n2].push_back(n1);
        }
        else
        {
            
            unordered_set<int> st, cont;
            bool flag = true;
            vector<int> nums;
            for(int i = 0; i < temp.size(); i+=3)
            {
                int n = (temp[i]-'0')*10+temp[i+1]-'0';
                nums.push_back(n);
                cont.insert(n);
            }

            for(auto &i: nums)
            {
                for(auto &j: order[i])
                {
                    if(cont.count(j) == 1 && st.count(j) == 0)
                    {
                        flag = false;
                        break;
                    }
                }
                if(!flag)break;
                st.insert(i);
            }
            if(flag)ans += nums[nums.size()/2];

        }

    }
    cout << ans << "\n";
}