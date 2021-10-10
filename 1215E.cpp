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
const ll MOD = 1e14+7;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b;return 1;}return 0;}
template<class T> bool umax(T& a, T b) { if(a < b){ a = b;return 1;}return 0;}
template<class T> bool umod(T& a, T b) { a += b; while(a < 0) a += MOD; a %= MOD; return 1;}
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> omar;

//	freopen("file.in" , "r" , stdin);
//	freopen("file.out" , "w" , stdout);

int arr[N], n, counter[21];
ll dp[(1<<20)+2], tot[21], moves[(1<<20)+2][21], be4[21][21];

ll rec(int mask){
    if(__builtin_popcount(mask) == 1)
        return 0LL;
    
    if(~dp[mask])    return dp[mask];
    
    dp[mask] = MOD;
    
    for(int i=0; i<20; i++)
        if((1<<i)&mask)
            umin(dp[mask], rec(mask^(1<<i)) + moves[mask][i]);
    
    return dp[mask];
}

int main(){
    scanf("%d", &n);
    
    for(int i=1; i<=n; i++) scanf("%d", arr+i), arr[i]--;
    
    for(int i=1; i<=n; i++){
        int temp = 0;
        counter[arr[i]]++;
        
        for(int j=0; j<20; j++)
            if(arr[i] != j)
                be4[j][arr[i]] += counter[j];
    }
    
    for(int i=0; i<20; i++)
        for(int j=0; j<20; j++)
            tot[i] += be4[j][i];
    
    for(int i=0; i<20; i++)
        for(int j=0; j<(1<<20); j++){
            if(((1<<i)&j) == 0)   continue;
            
            moves[j][i] = tot[i];
            
            for(int k=0; k<20; k++)
                if(((1<<k)&j) == 0)
                    moves[j][i] -= be4[k][i];
        }
    
    memset(dp, -1, sizeof(dp));
    
    printf("%lld\n", rec((1<<20)-1));
    
	return 0;
}

