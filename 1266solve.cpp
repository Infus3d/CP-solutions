
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
template<class T> bool umod(T& a) { while(a < 0) a += MOD; a %= MOD; return 1;}
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> omar;
 
//	freopen("file.in" , "r" , stdin);
//	freopen("file.out" , "w" , stdout);
 
int n, T[N<<2], arr[N], q, a, b, c, d[N];
map<pii, int> mk;
ll M[N<<2];
 
void form_tree(int l, int r, int v){
    if(l == r){
        T[v] = arr[l];
        M[v] = arr[l];
        return;
    }
    
    form_tree(l, mid(l, r), v<<1);
    form_tree(mid(l, r)+1, r, v<<1|1);
    
    M[v] = M[v<<1] + M[v<<1|1];
}
 
void upd(int x, int val, int l, int r, int v){
    if(l == r){
        T[v] += val;
        M[v] = max(0, T[v]);
        return;
    }
    
    if(x <= mid(l, r))
        upd(x, val, l, mid(l, r), v<<1);
    else
        upd(x, val, mid(l, r)+1, r, v<<1|1);
    
    M[v] = M[v<<1] + M[v<<1|1];
}
 
int main(){
    scanf("%d", &n);
    for(int i=1; i<=n; i++) scanf("%d", &arr[i]);
    form_tree(1, n, 1);
    
    scanf("%d", &q);
    while(q--){
        scanf("%d%d%d", &a, &b, &c);
        if(mk[{a, b}] != 0)
            upd(mk[{a, b}], +1, 1, n, 1);
        mk[{a, b}] = c;
        if(c > 0)
            upd(c, -1, 1, n, 1);
        
        printf("%lld\n", max(1LL, M[1]));
    }
    
	return 0;
}
