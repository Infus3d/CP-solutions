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

void solve(){
    int n; scanf("%d", &n);
    vector<int> a(n);
    map<int, vector<int>> mk;
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
        mk[a[i]].push_back(i+1);
    }
    for(auto &i : mk){
        sort(all(i.second));
    }
    auto countEm = [&](int x, int y, vector<int> &v){
        if((int)v.size() == 0) return 0;
        int lef = lower_bound(all(v), x) - v.begin();
        int rig = upper_bound(all(v), y) - v.begin();
        return rig - lef;
    };
    int q; scanf("%d", &q);
    vector<int> idx(q);
    vector<vector<int>> b(q);
    for(int i=0; i<q; i++){
        scanf("%d", &idx[i]);
        int m; scanf("%d", &m);
        for(int j=0; j<m; j++){
            int aa; scanf("%d", &aa);
            b[i].push_back(aa);
        }
        int l = idx[i]-1, r = n+1;
        while(l + 1 < r){
            int curTotal = 0;
            for(int j : b[i]){
                curTotal += countEm(idx[i], mid(l, r), mk[j]);
            }
            int range = mid(l, r) - idx[i] + 1;
            if(curTotal < range){
                r = mid(l, r);
            } else {
                l = mid(l, r);
            }
        }
        printf("%d\n", l - idx[i] + 1);
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
