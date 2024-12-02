#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define int long long
#define kr9 kotharirahil9
#define v32 vector<int>

ll MOD = 1e9 + 7;


bool check1(vector<int> &v)
{
    for(int i = 1; i < v.size(); i++)
    {
        if(v[i]-v[i-1] < 1 || v[i]-v[i-1] > 3)return false;
    }
    return true;
}
bool check2(vector<int> &v)
{
    for(int i = 0; i < v.size()-1; i++)
    {
        if(v[i]-v[i+1] < 1 || v[i]-v[i+1] > 3)return false;
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
        if(check1(i)||check2(i))count++;
    }
    cout << count << endl;
}