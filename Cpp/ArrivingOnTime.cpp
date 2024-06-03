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
    int n, m, s;
    scanf("%d%d%d", &n, &m, &s);
    vector<vector<int>> E(n+1, vector<int>());
    vector<int> u(m), v(m), t(m), p(m), d(m);
    for(int i=0; i<m; i++){
        scanf("%d%d%d%d%d", &u[i], &v[i], &t[i], &p[i], &d[i]);
        E[u[i]].push_back(i);
    }
    auto ok = [&](long long x){
        set<pair<long long, int>> setik;
        vector<long long> dist(n+1, (long long)2e18);
        vector<bool> visited(n+1, 0);
        dist[0] = x;
        setik.insert({x, 0});
        while(!setik.empty()){
            auto [arrivalTime, curNode] = *setik.begin();
            setik.erase(setik.begin());
            if(visited[curNode]) continue;
            if(curNode == n-1) break;
            visited[curNode] = true;
            for(int i : E[curNode]){
                long long w = (arrivalTime - t[i] + p[i] - 1) / p[i]; // w for wait-time
                if(arrivalTime <= t[i]) w = 0LL;
                int nextNode = (curNode == u[i] ? v[i] : u[i]);
                if(dist[nextNode] > 1LL*w*p[i] + t[i] + d[i]){
                    dist[nextNode] = 1LL*w*p[i] + t[i] + d[i];
                    setik.insert({dist[nextNode], nextNode});
                }
            }
        }
        // printf("dist[n-1]: %lld\n", dist[n-1]);
        return dist[n-1] <= (long long) s;
    };
    int l = 0, r = (int)1e9+1;
    while(l+1 < r){
        bool okk = ok(mid(l, r));
        // printf("l: %d, r: %d, mid: %d, ok: %d\n", l, r, mid(l, r), okk);
        if(okk){
            l = mid(l, r);
        } else {
            r = mid(l, r);
        }
    }
    if(ok(r)) l = r;
    if(ok(l)){
        printf("%d\n", l);
    } else {
        puts("Impossible");
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
