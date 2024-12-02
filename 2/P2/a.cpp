#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define int long long
#define kr9 kotharirahil9
#define v32 vector<int>

ll MOD = 1e9 + 7;


bool check1(vector<int> &v, bool flag)
{
    for(int i = 1; i < v.size(); i++)
    {
        if(v[i]-v[i-1] < 1 || v[i]-v[i-1] > 3)
        {
            if(!flag)return false;
            vector<int> a=v,b=v,c=v;
            a.erase(a.begin()+i);
            b.erase(b.begin()+i-1);
            if(i != v.size()-1)c.erase(c.begin()+i+1);
            if(check1(a,false))return true;
            else if(check1(b,false))return true;
            else if(check1(c,false))return true;
            return false;
        }
    }
    return true;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    std::string line;
    std::vector< std::vector<int> > all_integers;
    while ( getline( std::cin, line ) ) {
        std::istringstream is( line );
        all_integers.push_back( 
                std::vector<int>( std::istream_iterator<int>(is),
                                std::istream_iterator<int>() ) );
    }
    int count = 0;
    for(auto &i: all_integers)
    {
        vector<int> copy = i;
        reverse(copy.begin(), copy.end());
        if(check1(i,true)||check1(copy,true))count++;
    }
    cout << count << endl;
}