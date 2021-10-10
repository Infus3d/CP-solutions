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

int n, a, b, mx, dist[N][3], root1, root2, deg[N];
vector<int> E[N];
vector<pii> order;
ll ans;
queue<int> Q;

void dfs(int x, int y, int turn){
    dist[x][turn] = dist[y][turn]+1;
    
    for(int i : E[x])
        if(i != y)
            dfs(i, x, turn);
}

int main(){
    scanf("%d", &n);
    
    for(int i=1; i<n; i++){
        scanf("%d%d", &a, &b);
        
        E[a].pb(b); deg[a]++;
        E[b].pb(a); deg[b]++;
    }
    
    for(int i=1; i<n; i++)
        if(E[i].size() == 1){
            dist[0][0] = -1;
            dfs(i, 0, 0);
            break;
        }
    
    for(int i=1; i<=n; i++)
        if(dist[i][0] > mx){
            mx = dist[i][0];
            root1 = i;
        }
    
    dist[0][1] = -1;
    dfs(root1, 0, 1);
    
    mx = 0;
    for(int i=1; i<=n; i++)
        if(dist[i][1] > mx){
            mx = dist[i][1];
            root2 = i;
        }
    
    dist[0][2] = -1;
    dfs(root2, 0, 2);
    
    for(int i=1; i<=n; i++)
        if(deg[i] == 1 && i != root1 && i != root2)
            Q.push(i);
    
    while(!Q.empty()){
        int cur = Q.front(); Q.pop();
        
        for(int i : E[cur]){
            deg[i]--;
            
            if(deg[i] == 1)
                Q.push(i);
        }
        
        if(dist[cur][1] >= dist[cur][2])
            order.pb(mp(root1, cur));
        else
            order.pb(mp(root2, cur));
        
        ans += max(dist[cur][1], dist[cur][2]);
    }
    
    Q.push(root2);
    
    while(!Q.empty()){
        int cur = Q.front(); Q.pop();
        
        for(int i : E[cur]){
            deg[i]--;
            
            if(deg[i] == 1)
                Q.push(i);
        }
        
        order.pb(mp(root1, cur));
        ans += dist[cur][1];
    }
    
    printf("%lld\n", ans);
    for(pii i : order)
        printf("%d %d %d\n", i.ff, i.ss, i.ss);
    
	return 0;
}

