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

int n, m;
int T[N<<2];
int loc[N];

void build_tree(int l, int r, int v){
    T[v] = 0;
    if(l == r){
        loc[l] = 0;
        return;
    }
    build_tree(l, mid(l, r), v<<1);
    build_tree(mid(l, r)+1, r, v<<1|1);
}

void upd(int x, int y, int l, int r, int v){
    if(y < l || r < x) return;
    if(x <= l && r <= y){
        T[v]++;
        return;
    }
    upd(x, y, l, mid(l, r), v<<1);
    upd(x, y, mid(l, r)+1, r, v<<1|1);
}

int get(int x, int l, int r, int v){
    if(l == r){
        return T[v];
    }
    if(x <= mid(l, r)){
        return T[v] + get(x, l, mid(l, r), v<<1);
    } else {
        return T[v] + get(x, mid(l, r)+1, r, v<<1|1);
    }
}

void solve(){
    scanf("%d%d", &n, &m);
    int nn = n + m;
    build_tree(1, nn, 1); // rather, empty the tree
    for(int i=n; i>=1; i--){
        int a = loc[i] + 1, b = n-i;
        if(a <= b){
            upd(a, b, 1, nn, 1);
        }
        loc[i] = n-i+1;
    }
    for(int i=n+1; i<=nn; i++){
        int k; scanf("%d", &k);
        int a = loc[k]+1, b = i-1;
        printf("%d ", get(loc[k], 1, nn, 1));
        if(a <= b){
            upd(a, b, 1, nn, 1);
        }
        loc[k] = i;
    }
    puts("");
}

int main(){
    int testcase = 1;
    scanf("%d", &testcase);
    while(testcase--){
        solve();
    }
    return 0;
}
