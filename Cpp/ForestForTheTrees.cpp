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
    int n, m, rmax;
    scanf("%d%d%d", &n, &m, &rmax);
    vector<pair<int, int>> t(n), v(m);
    for(int i=0; i<n; i++){
        scanf("%d%d", &t[i].ff, &t[i].ss);
    }
    for(int i=0; i<m; i++){
        scanf("%d%d", &v[i].ff, &v[i].ss);
        if(v[i].ff == 0 && v[i].ss == 0){
            puts("Impossible");
            return;
        }
    }
    vector<pair<int, int>> g(m);
    for(int i=0; i<m; i++){
        g[i] = {v[i].ff - v[0].ff, v[i].ss - v[0].ss};
    }
    vector<pair<int, int>> ans;
    auto doit = [&](int h){
        map<pair<int, int>, bool> mk;
        for(int i=0; i<n; i++){
            mk[t[i]] = true;
        }
        for(int i=0; i<n; i++){
            bool ok = true;
            for(int j=0; j<m; j++){
                pii p = {t[i].ff + g[j].ff, t[i].ss + g[j].ss};
                if(!mk[p]){
                    ok = false;
                    break;
                }
            }
            if(ok){
                pii coors = {t[i].ff - v[0].ff, t[i].ss - v[0].ss};
                
                int cnt = 0;
                for(int j=0; j<m; j++){
                    assert(mk[make_pair(coors.ff + v[j].ff, coors.ss + v[j].ss)] == true);
                }
                for(int j=0; j<n; j++){
                    int dist = abs(coors.ff - t[j].ff) + abs(coors.ss - t[j].ss);
                    if(dist <= rmax){
                        cnt++;
                    }
                }
                if(cnt == m){
                    for(int j=0; j<h; j++){
                        swap(coors.ff, coors.ss);
                        coors.ff *= -1;
                    }
                    ans.push_back(coors);
                }
            }
        }
    };
    for(int j=0; j<4; j++){
        doit(4-j);
        for(int i=0; i<n; i++){
            swap(t[i].ff, t[i].ss);
            t[i].ff *= -1;
        }
    }
    
    if((int)ans.size() < 1){
        puts("Impossible");
    } else if((int)ans.size() > 1){
        puts("Ambiguous");
    } else {
        printf("%d %d\n", ans[0].ff, ans[0].ss);
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
