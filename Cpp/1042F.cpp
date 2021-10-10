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

int n, k, ans, a, b;
vector<int> E[N];

int dfs(int x, int y){
    if(sz(E[x]) == 1)   return 0;
    
    vector <int> v;
    for(int i : E[x])
        if(i != y)
            v.pb(dfs(i, x)+1);
    
    sort(all(v));
    
    while(sz(v) > 1 && v.end()[-1] + v.end()[-2] > k)   v.ppb(), ans++;
    
    return v.end()[-1];
}


int main(){
    scanf("%d%d", &n, &k);
    
    for(int i=1; i<n; i++){
        scanf("%d%d", &a, &b);
        
        E[a].pb(b);
        E[b].pb(a);
    }
    
    for(int i=1; i<=n; i++)
        if(sz(E[i]) > 1){
            dfs(i, 0);
            break;
        }
    
    printf("%d\n", ans+1);
    
	return 0;
}
/*
22 5
1 11
11 6
11 19
1 8
8 14
8 20
8 5
5 13
8 12
12 4
1 10
10 17
17 7
1 15
15 16
15 2
1 18
18 3
18 9
9 21
21 22
*/
