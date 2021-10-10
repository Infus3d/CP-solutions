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

int dp[(1<<20)+7], n, vis[22], exist[(1<<20)+7], ans;
char s[N];

int main(){
    scanf("%s", s); n = strlen(s);
    
    for(int i=0; i<n; i++){
        int index = i;
        int mask = 0;
        
        memset(vis, 0, sizeof(vis));
        
        while(index < n && !vis[s[index]-'a']){
            mask |= (1<<(s[index]-'a'));
            exist[mask] = dp[mask] = index-i+1;
            vis[s[index]-'a'] = 1;
            index++;
        }
    }
    
    for(int i=0; i<(1<<20); i++)
        for(int j=0; j<20; j++)
            if(!(i&(1<<j)))
                umax(dp[i|(1<<j)], dp[i]);
    
    for(int i=0; i<(1<<20); i++)
        if(exist[i])
            umax(ans, exist[i] + dp[i^((1<<20)-1)]);
    
    printf("%d\n", ans);
    
	return 0;
}

