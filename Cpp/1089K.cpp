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

const int N = 1e6+1;
const int M = 3e5+7;
const int MOD = 1e9+7;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b;return 1;}return 0;}
template<class T> bool umax(T& a, T b) { if(a < b){ a = b;return 1;}return 0;}
template<class T> bool umod(T& a, T b) { a += b; while(a < 0) a += MOD; a %= MOD; return 1;}
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> omar;

//	freopen("file.in" , "r" , stdin);
//	freopen("file.out" , "w" , stdout);

ll T[(N<<2)+7], lazy[N<<2];
char event;
pii arr[M];
int m, t, d, exist[N+7];

void push(int l, int r, int v){
    if(!lazy[v])    return;
    
    T[v<<1] += T[v<<1] ? lazy[v] : 0;
    T[v<<1|1] += T[v<<1|1] ? lazy[v] : 0;
    
    lazy[v<<1] += lazy[v];
    lazy[v<<1|1] += lazy[v];
    
    lazy[v] = 0;
}

void upd(int x, int l, int r, int v){
    if(l == r){
        T[v] = (l + lazy[v]) * exist[r];
        return;
    }
    
    push(l, r, v);
    
    if(x <= mid(l, r))
        upd(x, l, mid(l, r), v<<1);
    else
        upd(x, mid(l, r)+1, r, v<<1|1);
    
    T[v] = max(T[v<<1], T[v<<1|1]);
}

void inc(int x, int y, int val, int l, int r, int v){
    if(y < l || r < x)
        return;
    
    if(x <= l && r <= y){
        T[v] += T[v] ? val : 0;
        lazy[v] += val;
        return;
    }
    
    push(l, r, v);
    
    inc(x, y, val, l, mid(l, r), v<<1);
    inc(x, y, val, mid(l, r)+1, r, v<<1|1);
    
    T[v] = max(T[v<<1], T[v<<1|1]);
}

ll get(int x, int y, int l, int r, int v){
    if(y < l || r < x)
        return 0LL;
    
    if(x <= l && r <= y)
        return T[v];
    
    push(l, r, v);
    
    return max(get(x, y, l, mid(l, r), v<<1), get(x, y, mid(l, r)+1, r, v<<1|1));
}

ll getSum(int x, int l, int r, int v){
    if(l == r)
        return lazy[v];
    
    push(l, r, v);
    
    if(x <= mid(l, r))
        return getSum(x, l, mid(l, r), v<<1);
    else
        return getSum(x, mid(l, r)+1, r, v<<1|1);
}

int main(){
    scanf("%d", &m); 
    
    for(int query=1; query<=m; query++){
        scanf(" %c%d", &event, &t);
        
        if(event == '+'){
            scanf("%d", &d);
            arr[query] = mp(t, d);
            
            exist[t] = 1;
            upd(t, 1, N, 1);
            inc(1, t, d, 1, N, 1);
        }
        else if(event == '-'){
            d = arr[t].ss;
            t = arr[t].ff;
            
            exist[t] = 0;
            upd(t, 1, N, 1);
            inc(1, t, -d, 1, N, 1);
        }
        else{
            ll mx = get(1, t, 1, N, 1);
            ll cur = getSum(t+1, 1, N, 1);
            ll furthest = mx-cur;
            
            printf("%lld\n", max(0LL, furthest-t));
        }
    }
    
	return 0;
}

