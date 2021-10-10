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
struct malrak{
    int a, b, c, d;
} p[N];

int n, cn1, cn2, cur;
int T[N<<2], lz[N<<2];
map<int, int> mk1, mk2;
vector<int> E[N], R[N];

void upd(int x, int y, int val, int l, int r, int v){
    if(y < l || r < x)
        return;
    
    if(x <= l && r <= y){
        T[v] += val;
        lz[v] += val;
        return;
    }
    
    if(lz[v] != 0){
        T[v<<1] += lz[v];
        T[v<<1|1] += lz[v];
        
        lz[v<<1] += lz[v];
        lz[v<<1|1] += lz[v];
        lz[v] = 0;
    }
    
    upd(x, y, val, l, mid(l, r), v<<1);
    upd(x, y, val, mid(l, r)+1, r, v<<1|1);
    
    T[v] = max(T[v<<1], T[v<<1|1]);
}

int main(){
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        scanf("%d%d%d%d", &p[i].a, &p[i].b, &p[i].c, &p[i].d);
        mk1[p[i].a] = mk1[p[i].b] = 1;
        mk2[p[i].c] = mk2[p[i].d] = 1;
    }
    tr(i, mk1) i->ss = ++cn1;
    tr(i, mk2) i->ss = ++cn2;
    
    for(int i=1; i<=n; i++){
        p[i].a = mk1[p[i].a]; p[i].b = mk1[p[i].b];
        p[i].c = mk2[p[i].c]; p[i].d = mk2[p[i].d];
        
        E[p[i].a].pb(i);
        R[p[i].b].pb(i);
    }
    for(int i=1; i<=cn1; i++){
        for(int j : E[i])
            upd(p[j].c, p[j].d, +1, 1, cn2, 1), cur++;
        E[i].clear();
        
        if(T[1] != cur)
            return 0 * printf("NO\n");
        
        for(int j : R[i])
            upd(p[j].c, p[j].d, -1, 1, cn2, 1), cur--;
        R[i].clear();
    }
    
    cur = 0;
    memset(T, 0, sizeof(T));
    memset(lz, 0, sizeof(lz));
    for(int i=1; i<=n; i++){
        E[p[i].c].pb(i);
        R[p[i].d].pb(i);
    }
    for(int i=1; i<=cn2; i++){
        for(int j : E[i])
            upd(p[j].a, p[j].b, +1, 1, cn1, 1), cur++;
            
        if(T[1] != cur)
            return 0 * printf("NO\n");
        
        for(int j : R[i])
            upd(p[j].a, p[j].b, -1, 1, cn1, 1), cur--;
    }
    
    printf("YES\n");
	
    return 0;
}

