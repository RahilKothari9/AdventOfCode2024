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
    string temp;
    while(cin >> temp)
    {
        v.push_back(temp);
    }

    vector<int> dx = {-1,0,1,0}, dy = {0,1,0,-1};

    int dir = 0;
    

    int x1,y1;
    for(int i = 0; i < v.size(); i++)
    {
        for(int j = 0; j < v[0].size(); j++)
        {
            if(v[i][j]=='^')
            {
                x1 = i;
                y1 = j;
            }
        }
    }
   
    
    
    auto checkLoop = [&](int x, int y) ->bool{
        set<vector<int>> st;
        dir = 0;
        while(x >= 0 && x < v.size() && y >= 0 && y < v[0].size())
        {
            // cout << x << " " << y << endl;
            
            int xx = x + dx[dir];
            int yy = y + dy[dir];
            while(xx >= 0 && xx < v.size() && yy >= 0 && yy < v[0].size() && v[xx][yy]=='#')
            {
                if(st.count({x,y,dir}) == 1)return true;
                st.insert({x,y,dir});
                dir = (dir+1)%4;
                xx = x + dx[dir];
                yy = y + dy[dir];
            }
            x= xx;
            y = yy;
        }
        return false;
    } ;

   

    int count = 0;
    for(int i = 0; i < v.size(); i++)
    {
        for(int j = 0; j < v[0].size(); j++)
        {
        
            if(v[i][j] == '.')
            {
                v[i][j]='#';
                count+=checkLoop(x1,y1);
                v[i][j]='.';
                
            }
        }
    }
    cout << count << "\n";
}