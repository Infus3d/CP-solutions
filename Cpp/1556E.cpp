#include "bits/stdc++.h"
// #include "ext/pb_ds/assoc_container.hpp"
 
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
#define pll pair <ll, ll>
#define sz(x) int(x.size())
#define tr(it , c) for(__typeof(c.begin()) it = (c.begin()); it != (c.end()); it++)
#define y1 you_made_my_day
 
using namespace std;
// using namespace __gnu_pbds;
 
const int N = 1e5+7;
const int M = 600;
const int MOD = 998244353;
const int K = 1e3+7;
 
template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0;}
template<class T> bool umax(T& a, T b) { if(a < b){ a = b;return 1;}return 0;}
template<class T> bool umod(T& a) { while(a < 0) a += MOD; a %= MOD; return 1;}
// typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
 
//	freopen("file.in" , "r" , stdin);
//	freopen("file.out" , "w" , stdout);

int n, q;
long long d[N], T[N<<2], R[N<<2];
ll a[N], b[N];

void build_tree(int l, int r, int v){
    if(l == r){
        T[v] = d[l];
        R[v] = d[l];
        return;
    }
    build_tree(l, mid(l, r), v<<1);
    build_tree(mid(l, r)+1, r, v<<1|1);
    
    T[v] = max(T[v<<1], T[v<<1|1]);
    R[v] = min(R[v<<1], R[v<<1|1]);
}

ll getmin(int x, int y, int l, int r, int v){
    if(x > r || y < l)
        return LLONG_MAX;
    
    if(x <= l && r <= y)
        return R[v];
    
    return min(getmin(x, y, l, mid(l, r), v<<1), getmin(x, y, mid(l,r )+1, r, v<<1|1));
}

ll getmax(int x, int y, int l, int r, int v){
    if(x > r || y < l)
        return LLONG_MIN;
    
    if(x <= l && r <= y)
        return T[v];
    
    return max(getmax(x, y, l, mid(l, r), v<<1), getmax(x, y, mid(l, r)+1, r, v<<1|1));
}

int main(){
    scanf("%d %d", &n, &q);
    for(int i=1; i<=n; i++) scanf("%lld", a+i);
    for(int i=1; i<=n; i++) scanf("%lld", b+i);
    for(int i=1; i<=n; i++) d[i] = b[i] - a[i], d[i] += d[i-1];

    build_tree(1, n, 1);

    while(q--){
        int x, y;
        scanf("%d%d", &x, &y);

        if(d[y] - d[x-1] != 0 || getmin(x, y, 1, n, 1) - d[x-1] < 0)
            puts("-1");
        else
            printf("%lld\n", getmax(x, y, 1, n, 1) - d[x-1]);
    }

    return 0;
}