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
int n;
int p = 0;
vector<int> a;
multiset<int> b;
while(cin >> n) {
    if(p == 0)a.push_back(n);
    else b.insert(n);

    p=1-p;
}
sort(a.begin(), a.end());


int x = 0;
for(int i = 0; i < a.size(); i++)
{
    x += a[i]*b.count(a[i]);
}
cout << x << endl;
}