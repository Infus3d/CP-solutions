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

const int N = 1e6+2;
const int K = 1e3+2;
const int MOD = 998244353;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0; }
template<class T> bool umax(T& a, T b) { if(a < b){ a = b; return 1; } return 0; }

long long T[2][N<<2];
long long lz[2][N<<2];

void push(int l, int r, int t, int v){
    if(!lz[t][v]) return;
    T[t][v<<1] += (mid(l, r) - l + 1) * lz[t][v];
    T[t][v<<1|1] += (r - mid(l, r)) * lz[t][v];
    lz[t][v<<1] += lz[t][v];
    lz[t][v<<1|1] += lz[t][v];
    lz[t][v] = 0;
}

void upd(int x, int y, int t, int l, int r, int v){
    if(y < l || r < x) return;
    if(x <= l && r <= y){
        T[t][v] += (r-l+1);
        lz[t][v] += 1;
        return;
    }
    push(l, r, t, v);
    upd(x, y, t, l, mid(l, r), v<<1);
    upd(x, y, t, mid(l, r)+1, r, v<<1|1);
    T[t][v] = T[t][v<<1] + T[t][v<<1|1];
}

long long get(int x, int y, int t, int l, int r, int v){
    if(y < l || r < x) return 0LL;
    if(x <= l && r <= y) return T[t][v];
    push(l, r, t, v);
    return get(x, y, t, l, mid(l, r), v<<1) + get(x, y, t, mid(l, r)+1, r, v<<1|1);
}

void solve(){
    int n; scanf("%d", &n);
    vector<int> a(n), b(n);
    map<int, vector<pair<int, int>>> mk;
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
        mk[a[i]].push_back({i+1, 0});
    }
    for(int i=0; i<n; i++){
        scanf("%d", &b[i]);
        mk[b[i]].push_back({i+1, 1});
    }
    vector<int> v;
    int mini = 0;
    for(auto &i : mk){
        v.push_back(i.ff);
        assert(sz(i.ss) == 2);
        if(i.ss[0].ss != i.ss[1].ss){
            mini = i.ff;
        }
    }
    reverse(all(v));
    for(int i : v){
        if(i == mini){
            printf("%d\n", mini);
            return;
        }
        int l = mk[i][0].ff, r = mk[i][1].ff, t = mk[i][0].ss;
        if(get(l, r, t, 1, n, 1) > 0LL){
            printf("%d\n", i);
            return;
        }
        upd(l, r, t, 1, n, 1);
    }
    puts("0");
}

int main(){
    int testcase = 1;
    // scanf("%d", &testcase);
    while(testcase--){
        solve();
    }
    return 0;
}
