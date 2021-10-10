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

const int N = 2e3+7;
const int MOD = 1e9+7;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b;return 1;}return 0;}
template<class T> bool umax(T& a, T b) { if(a < b){ a = b;return 1;}return 0;}
template<class T> bool umod(T& a) { while(a < 0) a += MOD; a %= MOD; return 1;}
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> omar;

//	freopen("file.in" , "r" , stdin);
//	freopen("file.out" , "w" , stdout);

int arr[N], root, cn, n, d[N], p[N], e[N];
vector<int> E[N];
bool f = false;

vector<pair<pii, int>> dfs(int x, int y){
    e[x] = --cn;
    vector<pair<pii, int>> v;
    for(int i : E[x]){
        vector<pair<pii, int>> vv = dfs(i, x);
        for(pair<pii, int> j : vv)
            v.pb(j);
    }
    
    sort(all(v));
    for(int i=arr[x]; i<sz(v); i++)
        v[i].ff.ff++;
    
    if(arr[x] > sz(v)){
        printf("NO\n");
        exit(0);
    }    
    
    if(!arr[x])
        v.pb({{1, cn}, x});
    else
        v.pb({{v[arr[x]-1].ff.ff+1, cn}, x});
    
    return v;
}

int main(){
    scanf("%d", &n); cn = n;
    for(int i=1; i<=n; i++){    
        scanf("%d%d", &p[i], &arr[i]);
        if(p[i])
            E[p[i]].pb(i);
        else
            root = i;
    }
    vector<pair<pii, int>> vec = dfs(root, 0);
    
    for(auto i : vec)
        d[i.ss] = i.ff.ff;
    
    puts("YES");
    for(int i=1; i<=n; i++)
	   printf("%d ", d[i]);
    return 0;
}
