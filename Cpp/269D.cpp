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
 
const int N = 1e6+2;
const int M = 600;
const int MOD = 998244353;
const int K = 1e3+2;
 
template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0;}
template<class T> bool umax(T& a, T b) { if(a < b){ a = b;return 1;}return 0;}
template<class T> bool umod(T& a) { while(a < 0) a += MOD; a %= MOD; return 1;}
// typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
 
//	freopen("file.in" , "r" , stdin);
//	freopen("file.out" , "w" , stdout);

int n, m, q, a, b;
int d[N];
char s[N];

int get(int x, int y) { return (!x || !y) ? n*m : (x-1)*m + (y-1); }

int main(){
    scanf("%d%d", &n, &m);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++)
            scanf(" %c", &s[get(i, j)]);
        for(int j=1; j<=m; j++){
            if(s[get(i-1, j)] == 'X' && s[get(i, j-1)] == 'X')
                d[get(i, j)] = 1;
            d[get(i, j)] += d[get(i, j-1)];
        }
        for(int j=1; j<=m; j++)
            d[get(i, j)] += d[get(i-1, j)];
    }
    
    scanf("%d", &q);
    while(q--){
        scanf("%d%d", &a, &b);
        if(b-a == 0 || d[get(n, b)] - d[get(n, a)] == 0)
            puts("YES");
        else
            puts("NO");
    }
	return 0;
}
