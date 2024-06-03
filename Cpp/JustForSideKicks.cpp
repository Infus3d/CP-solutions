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

const int N = 2e5+5;
const int K = 1e3+2;
const int MOD = 998244353;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0; }
template<class T> bool umax(T& a, T b) { if(a < b){ a = b; return 1; } return 0; }

long long res[7];
long long T[N<<2][7];
char s[N];
vector<int> d;

void combine(int v){
    for(int i=1; i<7; i++){
        T[v][i] = T[v<<1][i] + T[v<<1|1][i];
    }
}

void build_tree(int l, int r, int v){
    if(l == r){
        T[v][d[l]] = 1;
        return;
    }
    build_tree(l, mid(l, r), v<<1);
    build_tree(mid(l, r)+1, r, v<<1|1);
    combine(v);
}

void upd(int x, int val, int l, int r, int v){
    if(l == r){
        T[v][d[x]] = 0;
        d[x] = val;
        T[v][d[x]] = 1;
        return;
    }
    if(x <= mid(l, r)){
        upd(x, val, l, mid(l, r), v<<1);
    } else {
        upd(x, val, mid(l, r)+1, r, v<<1|1);
    }
    combine(v);
}

void get(int x, int y, int l, int r, int v){
    if(y < l || r < x) return;
    if(x <= l && r <= y){
        // printf("Range: %d %d", l, r);
        for(int i=1; i<7; i++){
            // printf("%lld ", T[v][i]);
            res[i] += T[v][i];
        }
        // puts("");
        return;
    }
    get(x, y, l, mid(l, r), v<<1);
    get(x, y, mid(l, r)+1, r, v<<1|1);
}

void solve(){
    int n, q;
    scanf("%d%d", &n, &q);
    vector<int> v(7);
    for(int i=1; i<=6; i++){
        scanf("%d", &v[i]);
    }
    d = vector<int>(n+1);
    scanf("%s", s);
    for(int i=1; i<=n; i++){
        d[i] = s[i-1] - '0';
    }
    build_tree(1, n, 1);
    while(q--){
        int t, a, b;
        scanf("%d%d%d", &t, &a, &b);
        if(t == 1){
            upd(a, b, 1, n, 1);
        } else if(t == 2){
            v[a] = b;
        } else {
            for(int i=1; i<7; i++){
                res[i] = 0;
            }
            get(a, b, 1, n, 1);
            long long ans = 0;
            for(int i=1; i<=6; i++){
                // printf("i: %d, res[i]: %lld\n", i, res[i]);
                ans += 1LL * v[i] * res[i];
            }
            printf("%lld\n", ans);
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
