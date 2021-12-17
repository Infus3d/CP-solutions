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
 
const int N = 1e5+7;
const int M = 600;
const int MOD = 998244353;
const int K = 1e3+7;
 
template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0;}
template<class T> bool umax(T& a, T b) { if(a < b){ a = b;return 1;}return 0;}
template<class T> bool umod(T& a) { while(a < 0) a += MOD; a %= MOD; return 1;}
// typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
 
//	freopen("file.in" , "r" , stdin);
//	freopen("file.out" , "w" , stdout);

struct segTree{
    ll T[N<<2], lz[N<<2];
    
    segTree(){
        reset();
    }
    
    void reset(){
        memset(T, 0LL, sizeof(T));
        memset(lz, 0LL, sizeof(lz));
    }
    
    void push(int l, int r, int v){
        if(!lz[v]) return;
        T[v<<1] += 1LL * lz[v] * (mid(l, r)-l+1);
        T[v<<1|1] += 1LL * lz[v] * (r-mid(l, r));
        
        lz[v<<1] += lz[v];
        lz[v<<1|1] += lz[v];
        
        lz[v] = 0LL;
    }
    
    void upd(int x, int y, int val, int l, int r, int v){
        if(r < x || y < l)  return;
        if(x <= l && r <= y){
            T[v] += 1LL * val * (r-l+1);
            lz[v] += val;
            return;
        }
        
        push(l, r, v);
        upd(x, y, val, l, mid(l, r), v<<1);
        upd(x, y, val, mid(l, r)+1, r, v<<1|1);
        
        T[v] = T[v<<1] + T[v<<1|1];
    }
    
    ll get(int x, int y, int l, int r, int v){
        if(r < x || y < l)  return 0LL;
        if(x <= l && r <= y)    return T[v];
        
        push(l, r, v);
        return get(x, y, l, mid(l, r), v<<1) + get(x, y, mid(l, r)+1, r, v<<1|1);
    }
} sTree;

int testcase, n, q, type, a, b, c;

int main(){
    scanf("%d", &testcase);
    for(int caseNum=1; caseNum<=testcase; caseNum++){
        sTree.reset();
        scanf("%d%d", &n, &q);
        
        printf("Case %d:\n", caseNum);
        while(q--){
            scanf("%d%d%d", &type, &a, &b);
            a++, b++;
            
            if(!type){
                scanf("%d", &c);
                sTree.upd(a, b, c, 1, n, 1);
            }
            else
                printf("%lld\n", sTree.get(a, b, 1, n, 1));
        }
    }
	return 0;
}
