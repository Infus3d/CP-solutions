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

const int N = 4e5+7;
const int MOD = 1e9+7;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b;return 1;}return 0;}
template<class T> bool umax(T& a, T b) { if(a < b){ a = b;return 1;}return 0;}
template<class T> bool umod(T& a) { while(a < 0) a += MOD; a %= MOD; return 1;}
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> omar;

//	freopen("file.in" , "r" , stdin);
//	freopen("file.out" , "w" , stdout);

struct mine{
    int col, l, r;
};

int a, b, c, n, m, C, ch[N], id[N], par[N], lz[N<<2], P[N], lvl[N], d[N], lastt[N], cn=1, pos;
vector<int> E[N];
vector<mine> T[N<<2], temp;
int ans[N], colcnt[N];

void dfs(int x, int y){
    P[x] = y;
    d[x] = 1;
    lvl[x] = lvl[y]+1;
    
    for(int i : E[x])
        if(i != y)
            dfs(i, x), d[x] += d[i];
}

void HLD(int x, int y){
    if(!par[cn])    
        par[cn] = x;
    id[x] = ++pos;
    ch[x] = cn;
    lastt[cn] = x;
    
    int aa = 0, bb = -1;
    for(int i : E[x])
        if(i != y && umax(aa, d[i]))
            bb = i;
    
    if(bb != -1)
        HLD(bb, x);
    
    for(int i : E[x])
        if(i != y && i != bb)
            ++cn, HLD(i, x);
}

void push(int l, int r, int v){
    if(!lz[v])  return;
    
    T[v<<1].clear(); T[v<<1|1].clear();
    T[v<<1].pb({lz[v], l, mid(l, r)});
    T[v<<1|1].pb({lz[v], mid(l, r)+1, r});
    
    lz[v<<1] = lz[v]; lz[v<<1|1] = lz[v];
    lz[v] = 0;
}

void upd(int bl, int br, int x, int y, int val, int l, int r, int v){
//    printf("%d %d %d %d %d %d %d %d\n", bl, br, x, y, val, l, r, v);
    if(y < l || r < x)
        return;
    
    if(x <= l && r <= y){
        for(auto i : T[v])
            temp.pb(i);
        T[v].clear(); T[v].pb({val, l, r});
        lz[v] = val;
        return;
    }
    
    push(l, r, v);
    
    upd(bl, br, x, y, val, l, mid(l, r), v<<1);
    upd(bl, br, x, y, val, mid(l, r)+1, r, v<<1|1);
    
    if(bl <= l && r <= br){
        while(sz(T[v]) && T[v][sz(T[v])-1].r <= min(y, r))
            T[v].ppb();
        if(sz(T[v]) && T[v][sz(T[v])-1].l <= min(y, r))
            T[v][sz(T[v])-1].l = min(y, r)+1;
        T[v].pb({val, l, min(y, r)});
    }
}

int main(){
    scanf("%d%d%d", &n, &C, &m);
    for(int i=1; i<n; i++){
        scanf("%d%d", &a, &b);
        E[a].pb(b);
        E[b].pb(a);
    }
    lvl[0] = -1;
    dfs(1, 0);
    HLD(1, 0);
    ans[0] = C;
//    printf("%d %d %d %d %d\n", id[2], id[4], id[9], id[18], id[17]);
    while(m--){
        scanf("%d%d%d", &a, &c, &b);
        int A = a;
        
        temp.clear();
        while(ch[a] != ch[1]){
            upd(id[par[ch[a]]], id[lastt[ch[a]]], id[par[ch[a]]], id[a], c, 1, n, 1);
            a = P[par[ch[a]]];
        }
        if(id[1] < id[a])
            upd(id[1], id[lastt[ch[1]]], id[1]+1, id[a], c, 1, n, 1);
        
        for(auto i : temp){
//            db;
//            printf("%d %d %d\n", i.col, i.l, i.r);
            ans[colcnt[i.col]]--;
            colcnt[i.col] -= i.r-i.l+1;
            ans[colcnt[i.col]]++;
        }
        ans[colcnt[c]]--;
        colcnt[c] += lvl[A];
        ans[colcnt[c]]++;
        /*
        puts("Colors:");
        for(int i=1; i<=C; i++)
            printf("%d ", colcnt[i]);puts("");
        for(int i=0; i<=20; i++)
            printf("%d ", ans[i]); puts("");
        */
        printf("%d\n", ans[b]);
    }
    
	return 0;
}
/*
21 5 123
1 2
1 6
1 3
2 4
2 5
6 10
6 11
3 7
4 8
4 9
9 17
9 18
9 19
10 15
10 16
16 20
16 21
11 14
11 13
11 12
15 1 3
18 4 5
21 2 2
4 1 4
13 2 1
14 3 3
1 1 2
*/
