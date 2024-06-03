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

const int N = 1e5+2;
const int K = 1e3+2;
const int MOD = 998244353;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0; }
template<class T> bool umax(T& a, T b) { if(a < b){ a = b; return 1; } return 0; }

vector<int> E[N];
vector<pair<int, int>> H[N];

void dfs(int u){
    for(int v : E[u]){
        dfs(v);
        H[u].push_back({H[v][0].ff + 1, v});
    }
    if(!sz(E[u])){
        H[u].push_back({1, u});
    }
    sort(all(H[u]));
    reverse(all(H[u]));
}

void solve(){
    int n, k; scanf("%d%d", &n, &k);
    vector<int> v(n, -1);
    vector<int> childCnt(n);
    for(int i=1; i<n; i++){
        scanf("%d", &v[i]);
        v[i]--;
        childCnt[v[i]]++;
        E[v[i]].push_back(i);
    }
    int leafCnt = 0;
    for(int i=0; i<n; i++){
        if(!childCnt[i]){
            leafCnt++;
        }
    }
    if(leafCnt <= k){
        printf("%d\n", n);
        return;
    }
    dfs(0);
    vector<vector<pair<int, int>>::iterator> it(n);
    for(int i=0; i<n; i++){
        // printf("for u: %d\n", i);
        // for(auto [v, w] : H[i]){
            // printf("w: %d, v: %d\n", v, w);
        // }
        it[i] = H[i].begin();
    }
    set<pair<int, int>> setik;
    setik.insert({H[0][0].ff, 0});
    int ans = 0;
    while(k > 0){
        int u = (*setik.rbegin()).ss;
        ans += (*setik.rbegin()).ff;
        setik.erase(*setik.rbegin());
        // printf("u: %d, ans: %d\n", u, ans);
        // int limita = 10;
        while(childCnt[u] > 0){
            // printf("********** u: %d, k: %d\n", u, k);
            // for(auto [v, w] : H[u]){
                // printf("w: %d, v: %d\n", v, w);
            // }
            // if(limita == 0) break;
            // limita--;
            if(it[u] != H[u].end()){
                int tempu = (*it[u]).ss;
                it[u]++;
                if(it[u] != H[u].end()){
                    setik.insert({(*it[u]).ff-1, u});
                }
                u = tempu;
            }
        }
        k--;
    }
    printf("%d\n", ans);
}

/*
5 3
1 1 1 1
4

5 4
1 1 1 1 1
5

10 2
1 1 1 2 2 2 3 3 9
6


18 3
1 1 2 2 5 5 6 7 4 10 8 8 11 11 4 16 17
13


18 4
1 1 2 2 5 5 6 7 4 10 8 8 11 11 4 16 17
15
*/

int main(){
    int testcase = 1;
    // scanf("%d", &testcase);
    while(testcase--){
        solve();
    }
    return 0;
}
