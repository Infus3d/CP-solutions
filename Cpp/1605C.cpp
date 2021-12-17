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
 
const int N = 1e6+7;
const int M = 600;
const int MOD = 998244353;
const int K = 1e3+7;
 
template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0;}
template<class T> bool umax(T& a, T b) { if(a < b){ a = b;return 1;}return 0;}
template<class T> bool umod(T& a) { while(a < 0) a += MOD; a %= MOD; return 1;}
// typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
 
//	freopen("file.in" , "r" , stdin);
//	freopen("file.out" , "w" , stdout);

int testcase, n, d[N][3];
char s[N];

int solve(){
    scanf("%d", &n);
    scanf("%s", s);
    
    for(int i=0; i<n; i++){
        d[i][0] = d[i][1] = d[i][2] = 0;
        d[i][s[i]-'a']++;
        if(i > 0)
            for(int j=0; j<3; j++)
                d[i][j] += d[i-1][j];
    }
        
    for(int i=0; i<n-1; i++)
        if(s[i] == 'a' && s[i+1] == 'a')
            return 2;
    for(int i=0; i<n-2; i++)
        if(s[i] == 'a' && s[i+2] == 'a')
            return 3;
    for(int i=0; i<n-3; i++)
        if(s[i] == 'a' && s[i+3] == 'a' && (d[i+2][1] - d[i][1] == d[i+2][2] - d[i][2]))
            return 4;
    
    for(int i=0; i<n-6; i++)
        if(s[i] == 'a' && s[i+3] == 'a' && s[i+6] == 'a' && (d[i+5][1] - d[i][1] == d[i+5][2] - d[i][2]))
            return 7;
    
     return -1;
}

int main(){
    scanf("%d", &testcase);
    while(testcase--){
        printf("%d\n", solve());
    }
    
	return 0;
}
