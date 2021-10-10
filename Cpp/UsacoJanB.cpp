/*
ID : omarmuh1
PROG : test
LANG : C++11
*/

#include "bits/stdc++.h"
//#include "ext/pb_ds/assoc_container.hpp"

#define mp make_pair
#define pb push_back
#define ppb pop_back
#define db puts("*****")
#define mid(x , y) ((x+y)>>1)
#define ff first
#define ss second
#define all(x)	x.begin(),x.end()
#define ll long long
#define sqr(x)	((x)*(x))
#define pii pair <int , int>
#define sz(x) int(x.size())
#define tr(it , c) for(__typeof(c.begin()) it = (c.begin()); it != (c.end()); it++)
#define y1 you_made_my_day

using namespace std;
//using namespace __gnu_pbds;

const int N = 2e5+7;
const int MOD = 1e9+7;
const int K = 22;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b;return 1;}return 0;}
template<class T> bool umax(T& a, T b) { if(a < b){ a = b;return 1;}return 0;}
template<class T> bool umod(T& a) { while(a < 0) a += MOD; a %= MOD; return 1;}
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

//	freopen("file.in" , "r" , stdin);
//	freopen("file.out" , "w" , stdout);

int n, k, m, arr[N], ans[N];
vector<pii> E[N];
int T[N<<2], R[N<<2][K], lz[N<<2][K];

int mod(int x, int y){
    int temp = x + y;
    if(temp >= MOD)
        temp -= MOD;
    return temp;
}

void ins(int x, int val, int l, int r, int v){
    if(l == r){
        R[v][val] = 1;
        return;
    }
    
    if(x <= mid(l, r))
        ins(x, val, l, mid(l, r), v<<1);
    else
        ins(x, val, mid(l, r)+1, r, v<<1|1);
    
    for(int i=1; i<=k; i++)
        R[v][i] = R[v<<1][i] + R[v<<1|1][i];
}

void push(int l, int r, int v){
    for(int i=1; i<=k; i++){
        T[v<<1] = mod(T[v<<1], (1LL*lz[v][i]*R[v<<1][i])%MOD);
        T[v<<1|1] = mod(T[v<<1|1], (1LL*lz[v][i]*R[v<<1|1][i])%MOD);
        lz[v<<1][i] = mod(lz[v<<1][i], lz[v][i]);
        lz[v<<1|1][i] = mod(lz[v<<1|1][i], lz[v][i]);
        lz[v][i] = 0;
    }
}

void upd(int x, int y, int val, int l, int r, int v){
    if(y < l || r < x)
        return;
    
    if(x <= l && r <= y){
//        printf("Girdim: %d %d %d %d %d %d\n", x, y, val, l, r, v);
//        for(int i=val; i<=k; i++)
//            printf("%d %d\n", i, R[v][i]);
        for(int i=val; i<=k; i++)
            lz[v][i]++, T[v] = mod(T[v], R[v][i]);
//        printf("T[v]: %d\n", T[v]);
        return;
    }
    
    push(l, r, v);
    
    upd(x, y, val, l, mid(l, r), v<<1);
    upd(x, y, val, mid(l, r)+1, r, v<<1|1);
    
    T[v] = mod(T[v], mod(T[v<<1], T[v<<1|1]));
}

int get(int x, int y, int l, int r, int v){
    if(y < l || r < x)
        return 0;
    
    if(x <= l && r <= y)
        return T[v];
    
    push(l, r, v);
    
    return mod(get(x, y, l, mid(l, r), v<<1), get(x, y, mid(l, r)+1, r, v<<1|1));
}

int main(){
    scanf("%d%d", &n, &k);
    for(int i=1; i<=n; i++)
        scanf("%d", &arr[i]), ins(i, arr[i], 1, n, 1);
    
    scanf("%d", &m);
    for(int i=1; i<=m; i++){
        int a, b;
        scanf("%d%d", &a, &b);
        E[a].pb({b, i});
    }
    for(int i=n; i>=1; i--){
        upd(i, n, arr[i], 1, n, 1);
        for(pii j : E[i])
            ans[j.ss] = get(i, j.ff, 1, n, 1);
    }
    
    for(int i=1; i<=m; i++)
        printf("%d\n", ans[i]);
    
	return 0;
}
