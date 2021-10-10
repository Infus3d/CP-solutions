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

const int N = 5e3+7;
const int MOD = 1e9+7;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b;return 1;}return 0;}
template<class T> bool umax(T& a, T b) { if(a < b){ a = b;return 1;}return 0;}
template<class T> bool umod(T& a, T b) { a += b; while(a < 0) a += MOD; a %= MOD; return 1;}
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> omar;

//	freopen("file.in" , "r" , stdin);
//	freopen("file.out" , "w" , stdout);

int L, n, lvl[N], dp[N][N], counter, type[N];
char charray[N];     // charrryyyy beytmedaou

int main(){
    scanf("%d", &n);
    
    for(int i=0; i<n; i++){
        scanf(" %c", &charray[i]);
        
        lvl[i] = counter;
        
        if(charray[i] == 'f')
            counter++;
    }
    
    dp[0][0] = 1;
    
    for(int i=1; i<n; i++){
        if(charray[i-1] == 'f'){
            for(int j=1; j<=lvl[i]; j++)
                dp[i][j] = dp[i-1][j-1];
        }
        else{
            for(int j=lvl[i-1]; j>=0; j--)
                dp[i-1][j] = (dp[i-1][j] + dp[i-1][j+1]) % MOD;
            
            for(int j=0; j<=lvl[i]; j++)
                dp[i][j] = dp[i-1][j];
        }
    }
    
    for(int i=lvl[n-1]; i>=0; i--)
        dp[n-1][i] = (dp[n-1][i] + dp[n-1][i+1]) % MOD;
    
    printf("%d\n", dp[n-1][0]);
    
	return 0;
}

