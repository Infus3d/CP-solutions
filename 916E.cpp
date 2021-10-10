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

const int N = 1e5+7;
const int MOD = 1e9+7;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b;return 1;}return 0;}
template<class T> bool umax(T& a, T b) { if(a < b){ a = b;return 1;}return 0;}
template<class T> bool umod(T& a, T b) { a += b; while(a < 0) a += MOD; a %= MOD; return 1;}
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> omar;

//	freopen("file.in" , "r" , stdin);
//	freopen("file.out" , "w" , stdout);

int n, m, arr[N], root, type, a, b, val, lvl[N], P[N][19], in[N], out[N], counter, index[N];
vector<int> E[N];
ll T[N<<2], lz[N<<2];

void dfs(int x, int y){
    lvl[x] = lvl[y]+1;
    P[x][0] = y;
    in[x] = ++counter;
    index[counter] = x;
    
    for(int i : E[x])
        if(i != y)
            dfs(i, x);
    
    out[x] = counter;
}

void build_lca(){
    for(int j=1; j<=17; j++)
        for(int i=1; i<=n; i++)
            if(P[i][j-1] > 0)
                P[i][j] = P[P[i][j-1]][j-1];
}

int lca(int x, int y){
    if(lvl[x] < lvl[y])
        swap(x, y);
    
    for(int i=17; i>=0; i--)
        if(lvl[x] - (1<<i) >= lvl[y])
            x = P[x][i];
        
    if(x == y)  return x;
    
    for(int i=17; i>=0; i--)
        if(P[x][i] > 0 && P[x][i] != P[y][i])
            x = P[x][i], y = P[y][i];
    
    return P[x][0];
}

int find_ancestor(int x, int k){
    for(int i=17; i>=0; i--)
        if(k - (1<<i) >= 0)
            x = P[x][i], k -= (1<<i);
    
    return x;
}

void form_tree(int l, int r, int v){
    if(l == r){
        T[v] = arr[index[l]];
        return;
    }
    
    form_tree(l, mid(l, r), v<<1);
    form_tree(mid(l, r)+1, r, v<<1|1);
    
    T[v] = T[v<<1] + T[v<<1|1];
}

void push(int l, int r, int v){
    if(!lz[v])  return;
    
    T[v<<1] += (1LL * lz[v] * (mid(l, r)-l+1));
    T[v<<1|1] += (1LL * lz[v] * (r-mid(l, r)));
    
    lz[v<<1] += lz[v];
    lz[v<<1|1] += lz[v];
    
    lz[v] = 0;
}

void upd(int x, int y, int value, int l, int r, int v){
    if(r < x || y < l)
        return;
    
    if(x <= l && r <= y){
        T[v] += (1LL * value * (r-l+1));
        lz[v] += value;
        return;
    }
    
    push(l, r, v);
    
    upd(x, y, value, l, mid(l, r), v<<1);
    upd(x, y, value, mid(l, r)+1, r, v<<1|1);
    
    T[v] = T[v<<1] + T[v<<1|1];
}

ll get(int x, int y, int l, int r, int v){
    if(y < l || r < x)
        return 0LL;
    
    if(x <= l && r <= y)
        return T[v];
    
    push(l, r, v);
    
    return get(x, y, l, mid(l, r), v<<1) + get(x, y, mid(l, r)+1, r, v<<1|1);
}

int main(){
    scanf("%d%d", &n, &m);
    
    for(int i=1; i<=n; i++) scanf("%d", &arr[i]);
    for(int i=1; i<n; i++){
        scanf("%d%d", &a, &b);
        
        E[a].pb(b);
        E[b].pb(a);
    }
    root = 1;
    
    dfs(1, 0); 
    build_lca();
    form_tree(1, n, 1);
    
    while(m--){
        scanf("%d%d", &type, &a);
        
        if(type == 1){
            root = a;
        }
        else if(type == 2){
            scanf("%d%d", &b, &val);
            
            int lca1 = lca(a, b);
            int lca2 = lca(a, root);
            int lca3 = lca(b, root);
            int actual_lca = lca1;
            
            if(lvl[lca2] > lvl[actual_lca])     actual_lca = lca2;
            if(lvl[lca3] > lvl[actual_lca])     actual_lca = lca3;
            
            if(in[actual_lca] <= in[root] && out[root] <= out[actual_lca]){
                upd(1, n, val, 1, n, 1);
                
                if(actual_lca != root){
                    int ancestor = find_ancestor(root, lvl[root]-lvl[actual_lca]-1);
                    upd(in[ancestor], out[ancestor], -val, 1, n, 1);
                }
            }
            else
                upd(in[actual_lca], out[actual_lca], val, 1, n, 1);
        }
        else{
            ll ans = 0LL;
            
            if(in[a] <= in[root] && out[root] <= out[a]){
                ans += get(1, n, 1, n, 1);
                
                if(root != a){
                    int ancestor = find_ancestor(root, lvl[root]-lvl[a]-1);
                    ans -= get(in[ancestor], out[ancestor], 1, n, 1);
                }
            }
            else
                ans = get(in[a], out[a], 1, n, 1);
            
            printf("%lld\n", ans);
        }
    }  
    
	return 0;
}

