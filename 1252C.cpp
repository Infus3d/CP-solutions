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

const int N = 1e5+7;
const int MOD = 1e9+7;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b;return 1;}return 0;}
template<class T> bool umax(T& a, T b) { if(a < b){ a = b;return 1;}return 0;}
template<class T> bool umod(T& a, T b) { a += b; while(a < 0) a += MOD; a %= MOD; return 1;}
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> omar;

//	freopen("file.in" , "r" , stdin);
//	freopen("file.out" , "w" , stdout);

int n, q, R[N], C[N], ra, ca, rb, cb, a;

int main(){
    scanf("%d%d", &n, &q);
    
    for(int i=1; i<=n; i++) scanf("%d", &a), R[i] = R[i-1] + (a%2);
    for(int i=1; i<=n; ++i) scanf("%d", &a), C[i] = C[i-1] + (a%2);
    
    while(q--){
        scanf("%d%d%d%d", &ra, &ca, &rb, &cb);
        if(ra > rb)  swap(ra, rb);
        if(ca > cb)  swap(ca, cb);
        
        if(R[ra]-R[ra-1])
            printf("%s\n", (R[rb]-R[ra-1] == rb-ra+1 && C[cb]-C[ca-1] == cb-ca+1 ? "YES" : "NO"));
        else
            printf("%s\n", (R[rb]-R[ra-1] == 0 && C[cb]-C[ca-1] == 0 ? "YES" : "NO"));
    }
    
	return 0;
}

