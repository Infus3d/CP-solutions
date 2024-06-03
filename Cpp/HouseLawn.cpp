#include "bits/stdc++.h"

#define ff first
#define ss second
#define pb push_back
#define ll long long
#define db puts("*****")
#define sz(x) int(x.size())
#define pii pair <int , int>
#define mid(x , y) ((x+y)>>1)
#define all(x)	x.begin(),x.end()
#define y1 your_name_engraved_herein

using namespace std;

const int N = 2e5+2;
const int K = 1e3+2;
const int MOD = 998244353;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0; }
template<class T> bool umax(T& a, T b) { if(a < b){ a = b; return 1; } return 0; }

char sss[100];

void solve(){
    int l, m;
    cin >> l >> m;
    vector<string> names(m);
    vector<pair<int, int>> v;
    for(int i=0; i<m; i++){
        getline(cin, names[i], ',');
        int p, c, t, r;
        scanf("%d,%d,%d,%d", &p, &c, &t, &r);
        // cout << line << " " << p << " " << c << " " << t << " " << r << "\n";
        if(1LL * l * (r + t) <= 10080LL * c * t){
            v.push_back({p, i});
        }
    }
    // for(auto i : v){
        // cout << i.ff << " " << i.ss << "\n";
    // }
    if((int)v.size() == 0){
        puts("no such mower");
        return;
    }
    sort(all(v));
    int minPrice = v[0].ff;
    for(int i=0; i<(int)v.size(); i++){
        if(v[i].ff == minPrice){
            cout << names[v[i].ss];
        }
    }
}

int main(){
    int testcase = 1;
    // scanf("%d", &testcase);
    while(testcase--){
        solve();
    }
    return 0;
}
