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

int a, b, c, d[N], n, m;
int dp[N];
pii p[N];

int main(){
    scanf("%d%d", &n, &m);
    for(int i=1; i<=n; i++){
        scanf("%d%d", &a, &b);
        p[i] = {max(0, a-b), min(m+1, a+b)};
        d[p[i].ff]++; d[p[i].ss+1]--;
    }
    for(int i=1; i<=m; i++) d[i] += d[i-1];
    for(int i=1; i<=m; i++){
        dp[i] = MOD;
        if(d[i])
            umin(dp[i], dp[i-1]);
        for(int j=1; j<=n; j++){
            if(i > p[j].ss)
                umin(dp[i], dp[max(0, p[j].ff-(i-p[j].ss)-1)]+(i-p[j].ss));
        }
    }
    printf("%d\n", dp[m]);
    
    return 0;
}

