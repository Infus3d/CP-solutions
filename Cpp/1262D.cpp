/*
ID : omarmuh1
PROG : test
LANG : C++11
*/

#include "bits/stdc++.h"
#include "ext/pb_ds/assoc_container.hpp"

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
using namespace __gnu_pbds;

const int N = 2e5+7;
const int MOD = 1e9+7;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b;return 1;}return 0;}
template<class T> bool umax(T& a, T b) { if(a < b){ a = b;return 1;}return 0;}
template<class T> bool umod(T& a, T b) { a += b; while(a < 0) a += MOD; a %= MOD; return 1;}
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> omar;

//	freopen("file.in" , "r" , stdin);
//	freopen("file.out" , "w" , stdout);

int n, m, a, T[N<<2], ans[N], cn, b, org[N];
pii arr[N];
pair<pii, int> Q[N];

void updT(int x, int l, int r, int v){
    if(l == r){
        T[v] = 1;
        return;
    }
    
    if(x <= mid(l, r))
        updT(x, l, mid(l, r), v<<1);
    else
        updT(x, mid(l, r)+1, r, v<<1|1);
    
    T[v] = T[v<<1] + T[v<<1|1];
}

int getT(int val, int l, int r, int v){
    if(l == r)
        return l;
    
    if(T[v<<1] >= val)
        return getT(val, l, mid(l, r), v<<1);
    else
        return getT(val-T[v<<1], mid(l, r)+1, r, v<<1|1);
}

int main(){
    scanf("%d", &n);
    for(int i=1; i<=n; i++) scanf("%d", &arr[i].ff), arr[i].ss = i, org[i] = arr[i].ff;
    sort(arr+1, arr+n+1, [] (pii x, pii y){
        if(x.ff == y.ff)
            return x.ss > y.ss;
        return x.ff < y.ff;
    });
    
    scanf("%d", &m);
    for(int i=1; i<=m; i++)
        scanf("%d%d", &a, &b), Q[i] = {{a, b}, i};
    
    int m1 = m;
    int cc = 1;
    sort(Q+1, Q+m+1);
    
    for(int i=n; i>=1; i--){
        updT(arr[i].ss, 1, n, 1);
        while(cc <= m && n-Q[cc].ff.ff+1 == i)
            ans[Q[cc].ss] = org[getT(Q[cc].ff.ss, 1, n, 1)], cc++;
    }
    
    for(int i=1; i<=m1; i++)
        printf("%d\n", ans[i]);
    
	return 0;
}

