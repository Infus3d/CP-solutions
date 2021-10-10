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
const int prim = 31;
const int prima = 41;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b;return 1;}return 0;}
template<class T> bool umax(T& a, T b) { if(a < b){ a = b;return 1;}return 0;}
template<class T> bool umod(T& a) { while(a < 0) a += MOD; a %= MOD; return 1;}
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> omar;

//	freopen("file.in" , "r" , stdin);
//	freopen("file.out" , "w" , stdout);

map<pair<int, int>, int> maap;
int n, f[N], inv, e[N], inva;
char s[N];

int mod(ll x){
    while(x < 0)   x += MOD;
    return x % MOD;
}

int get(int x, int y){
    if(y == 0)
        return 1;
    
    int tr = get(x, y/2); tr = mod(tr*tr);
    if(y&1) return mod(tr*x);
    else    return tr;
}

bool can(int x){
    maap.clear();
    int cur1 = 0, cur2 = 0;
    for(int i=0; i<x; i++){
        cur1 = mod(cur1*prim), cur2 = mod(cur2*prima);
        cur1 = mod(cur1+(s[i]-'a'+1)); cur2 = mod(cur2+(s[i]-'a'+1));
    }
    maap[{cur1, cur2}] = 1;
    
    for(int i=x; i<n; i++){
        cur1 = mod(cur1-mod((s[i-x]-'a'+1)*f[x-1]));
        cur1 = mod(cur1*prim);
        cur1 = mod(cur1+(s[i]-'a'+1));
        
        cur2 = mod(cur2-mod((s[i-x]-'a'+1)*e[x-1]));
        cur2 = mod(cur2*prima);
        cur2 = mod(cur2+(s[i]-'a'+1));
        
        if(maap[{cur1, cur2}])   return false;
        maap[{cur1, cur2}] = 1;
    }
    
    return true;
}

int main(){
    scanf("%d", &n); scanf("%s", s);
    
    f[0] = e[0] = 1;
    for(int i=1; i<=n; i++) f[i] = (f[i-1] * prim) % MOD;
    for(int i=1; i<=n; i++) e[i] = (e[i-1] * prima) % MOD;
    inv = get(prim, MOD-2);
    inva = get(prima, MOD-2);
    
    int l = 1, r = n;
    while(l+1 < r){
        if(can(mid(l, r)))
            r = mid(l, r);
        else
            l = mid(l, r)+1;
    }
    if(can(l))  r = l;
    
    printf("%d\n", r);
    
	return 0;
}
/*
10
abcabcabca
*/

