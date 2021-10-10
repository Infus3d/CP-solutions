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
template<class T> bool umod(T& a, T b) { a += b; while(a < 0) a += MOD; a %= MOD; return 1;}
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> omar;

//	freopen("file.in" , "r" , stdin);
//	freopen("file.out" , "w" , stdout);

int tr[N*101][2], node, n, testcase;
ll arr[N];

void add(ll x){
    int cur = 0;
    
    for(int i=31; i>=0; i--){
        int bit = x>>i&1;
        
        if(!tr[cur][bit])
            tr[cur][bit] = ++node;
        
        cur = tr[cur][bit];
    }
}

ll get(ll x){
    int cur = 0;
    ll res = 0;
    
    for(int i=31; i>=0; i--){
        int bit = x>>i&1;
        
        if(tr[cur][bit^1])
            res |= (1<<i), cur = tr[cur][bit^1];
        else
            cur = tr[cur][bit];
    }
    
    return res;
}

int main(){
    scanf("%d", &testcase);
    
    while(testcase--){
        scanf("%d", &n);
        for(int i=1; i<=n; i++) scanf("%d", &arr[i]);
        
        node = 0;
        memset(tr, 0, sizeof(tr));
        
        ll ans = 0;
        ll par = 0;
        
        add(0LL);
        for(int i=1; i<=n; i++){
            par ^= arr[i];
            umax(ans, get(par));
            add(par);
        }
        
        printf("%lld\n", max(ans, get(0LL)));
    }
    
	return 0;
}

