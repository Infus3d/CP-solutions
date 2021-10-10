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

const int N = 1e6+7;
const int MOD = 1e9+7;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b;return 1;}return 0;}
template<class T> bool umax(T& a, T b) { if(a < b){ a = b;return 1;}return 0;}
template<class T> bool umod(T& a, T b) { a += b; while(a < 0) a += MOD; a %= MOD; return 1;}
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> omar;

//	freopen("file.in" , "r" , stdin);
//	freopen("file.out" , "w" , stdout);

int n, a, b, cn;
pii P[N];
map <int, int> Map;
ll T[N<<2];
long double ans, ans1;
int C[N<<2];

void upd(int x, ll val, int l, int r, int v){
    if(l == r){
        T[v] = val;
        return;
    }
    
    if(x <= mid(l, r))
        upd(x, val, l, mid(l, r), v<<1);
    else
        upd(x, val, mid(l,r)+1, r, v<<1|1);
    
    T[v] = max(T[v<<1], T[v<<1|1]);
}

ll get(int x, int y, int l, int r, int v){
    if(y < l || r < x)
        return 0LL;
    
    if(x <= l && r <= y)
        return T[v];
    
    return max(get(x, y, l, mid(l, r), v<<1), get(x, y, mid(l, r)+1, r, v<<1|1));
} 

void updC(int x, int val, int l, int r, int v){
    if(l == r){
        C[v] = val;
        return;
    }
    
    if(x <= mid(l, r))
        updC(x, val, l, mid(l, r), v<<1);
    else
        updC(x, val, mid(l, r)+1, r, v<<1|1);
    
    C[v] = max(C[v<<1], C[v<<1|1]);
}

int getC(int x, int y, int l, int r, int v){
    if(y < l || r < x)
        return 0;
    
    if(x <= l && r <= y)
        return C[v];
    
    return max(getC(x, y, l, mid(l, r), v<<1), getC(x, y, mid(l, r)+1, r, v<<1|1));
}

int main(){
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        scanf("%d%d", &P[i].ff, &P[i].ss);
        umax(ans, (long double)(1LL*P[i].ff*P[i].ss/2.0));
        
        if(P[i].ff > P[i].ss)   swap(P[i].ff, P[i].ss);
        Map[P[i].ss] = 1;
    }
    
    tr(i, Map)  i->ss = ++cn;
    sort(P+1, P+n+1);
    
    upd(Map[P[1].ss], 1LL*P[1].ff*P[1].ss, 1, cn, 1);
    updC(Map[P[1].ss], P[1].ff, 1, cn, 1);
    for(int i=2; i<=n; i++){
        umax(ans, (long double)get(1, Map[P[i].ss], 1, cn, 1));
        upd(Map[P[i].ss], 1LL*P[i].ff*P[i].ss, 1, cn, 1);
        
        umax(ans, (long double)(1LL*getC(Map[P[i].ss], cn, 1, cn, 1)*P[i].ss));
        updC(Map[P[i].ss], P[i].ff, 1, cn, 1);
    }
    
    printf("%.1lf\n", ans);

//    
//    for(int i=1; i<=n; i++)
//        for(int j=1; j<=n; j++){
//            if(i == j)
//                umax(ans1, (double)(1LL*P[i].ff*P[i].ss/2.0));
//            else
//                umax(ans1, (double)(1LL*min(P[i].ff, P[j].ff)*min(P[i].ss, P[j].ss)));
//        }
//    printf("%.1lf\n", ans1);
    
	return 0;
}
/*
6
123 45  
654 1
1 1
100 10
69 45
34 120
*/
