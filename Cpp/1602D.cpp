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
 
const int N = 3e5+7;
const int M = 600;
const int MOD = 998244353;
const int K = 1e5+7;
 
template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0;}
template<class T> bool umax(T& a, T b) { if(a < b){ a = b;return 1;}return 0;}
template<class T> bool umod(T& a) { while(a < 0) a += MOD; a %= MOD; return 1;}
// typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
 
//	freopen("file.in" , "r" , stdin);
//	freopen("file.out" , "w" , stdout);

int n, a[N], b[N], vis[N], track[N], lim;

int main(){
    scanf("%d", &n);
    for(int i=1; i<=n; i++)
        scanf("%d", &a[i]);
    for(int i=1; i<=n; i++)
        scanf("%d", &b[i]), b[i] = i+b[i];
    
    queue<int> Q;
    vis[n] = lim = n+1;
    Q.push(n);
    
    while(!Q.empty()){
        int tr = Q.front();
        Q.pop();
        //~ printf("tr:%d\n", tr);
        if(tr == 0) break;
        
        for(int i=tr-a[tr]; i<min(lim, tr); i++){
            if(!vis[b[i]]){
                vis[b[i]] = tr, track[b[i]] = i;
                Q.push(b[i]);
            }
        }
        
        lim = min(lim, tr-a[tr]);
    }
    
    if(!vis[0])
        puts("-1");
    else{
        vector<int> v;
        int cur = 0;
        while(cur <= n){
            v.pb(track[cur]);
            cur = vis[cur];
        }
        
        printf("%d\n", sz(v)-1);
        for(int i=sz(v)-2; i>=0; i--)
            printf("%d ", v[i]);
        puts("");
    }
    
	return 0;
}
