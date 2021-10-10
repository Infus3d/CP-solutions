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
#define pll pair<ll, ll>

using namespace std;
//using namespace __gnu_pbds;

const int N = 4e5+7;
const int MOD = 1e9+7;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b;return 1;}return 0;}
template<class T> bool umax(T& a, T b) { if(a < b){ a = b;return 1;}return 0;}
template<class T> bool umod(T& a) { while(a < 0) a += MOD; a %= MOD; return 1;}
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

//	freopen("file.in" , "r" , stdin);
//	freopen("file.out" , "w" , stdout);

struct Node{
    int sum;
    int lz, inv;
} T[N*2+5];

int type, m, n;
ll a, b, actual[N<<1];
map<ll, int> mk;
pair<int, pll> p[N];

void push(int l, int r, int v){
    if(T[v].lz != 0){
        T[v<<1].inv = T[v<<1|1].inv = 0;
        T[v<<1].lz = T[v<<1|1].lz = T[v].lz;
        T[v<<1].sum = max(0, T[v].lz*(mid(l, r)-l+1));
        T[v<<1|1].sum = max(0, T[v].lz*(r-mid(l, r)));
        T[v].lz = 0;
    }
    if(T[v].inv){
        if(T[v<<1].lz != 0){
            T[v<<1].lz *= -1;
            T[v<<1].sum = max(0, T[v<<1].lz*(mid(l, r)-l+1));
        }
        else{
            T[v<<1].inv ^= 1;
            T[v<<1].sum = (mid(l, r)-l+1) - T[v<<1].sum;
        }
        
        if(T[v<<1|1].lz != 0){
            T[v<<1|1].lz *= -1;
            T[v<<1|1].sum = max(0, T[v<<1|1].lz*(r-mid(l, r)));
        }
        else{
            T[v<<1|1].inv ^= 1;
            T[v<<1|1].sum = (r-mid(l, r)) - T[v<<1|1].sum;
        }
        T[v].inv = 0;
    }
}

void upd(int x, int y, int type, int l, int r, int v){
    if(y < l || r < x)
        return;
    
    if(x <= l && r <= y){
        T[v].lz = type;
        T[v].sum = max(0, type*(r-l+1));
        T[v].inv = 0;
        return;
    }
    
    push(l, r, v);
    
    upd(x, y, type, l, mid(l, r), v<<1);
    upd(x, y, type, mid(l, r)+1, r, v<<1|1);
    
    T[v].sum = T[v<<1].sum + T[v<<1|1].sum;
}

void invert(int x, int y, int l, int r, int v){
    if(y < l || r < x)
        return;
    
    if(x <= l && r <= y){
        T[v].sum = (r-l+1) - T[v].sum;
        if(T[v].lz == 0)
            T[v].inv ^= 1;
        else
            T[v].lz *= -1;
        return;
    }
    
    push(l, r, v);
    
    invert(x, y, l, mid(l, r), v<<1);
    invert(x, y, mid(l, r)+1, r, v<<1|1);
    
    T[v].sum = T[v<<1].sum + T[v<<1|1].sum;
}

int get(int l, int r, int v){
    if(l == r)
        return l;
    
    push(l, r, v);
    
    if(T[v<<1].sum < mid(l, r)-l+1)
        return get(l, mid(l, r), v<<1);
    else
        return get(mid(l, r)+1, r, v<<1|1);
}

int main(){
    scanf("%d", &m);
    for(int i=1; i<=m; i++){
        scanf("%d%lld%lld", &type, &a, &b);
        p[i] = {type, {a, b}};
        mk[a] = mk[b] = mk[b+1] = 1;
    }
    mk[1] = 1;
    tr(i, mk)   i->ss = ++n, actual[n] = i->ff;
//    for(int i=1; i<=n; i++)
//        printf("%d --> %d\n", i, actual[i]);
    for(int i=1; i<=m; i++){
        p[i].ss.ff = mk[p[i].ss.ff];
        p[i].ss.ss = mk[p[i].ss.ss];
        type = p[i].ff, a = p[i].ss.ff, b = p[i].ss.ss;
//        printf("type:%d a:%d b:%d\n", type, a, b);
        
        if(type == 1)
            upd(a, b, 1, 1, n, 1);
        else if(type == 2)  
            upd(a, b, -1, 1, n, 1);
        else
            invert(a, b, 1, n, 1);
        
        int tmp = get(1, n, 1);
        printf("%lld\n", actual[tmp]);
    }
    
	return 0;
}
/*
8
1 3 6
1 8 27
1 6 27
3 1 29
1 3 5
2 12 15
1 6 8
3 9 29

1
1
1
3
6
6
9
28
*/

