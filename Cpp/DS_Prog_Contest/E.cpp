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

struct node{
    int mx, ind;
    int ans;
    pii pairInd;
};

struct segTree{
    node T[N<<2];
    
    node merge(const node &lef, const node &rig){
        node cur;
        if(lef.mx < rig.mx)
            cur.mx = rig.mx, cur.ind = rig.ind;
        else
            cur.mx = lef.mx, cur.ind = lef.ind;
        
        if(lef.ans < rig.ans)
            cur.ans = rig.ans, cur.pairInd = rig.pairInd;
        else
            cur.ans = lef.ans, cur.pairInd = lef.pairInd;
        
        if(~lef.ind && ~rig.ind){
            int merged = lef.mx + rig.mx;
            pii mergedInd = mp(lef.ind, rig.ind);
            
            if(cur.ans < merged)
                cur.ans = merged, cur.pairInd = mergedInd;
        }
        
        return cur;
    }
    
    void upd(int x, int val, int l, int r, int v){
        if(l == r){
            T[v].mx = val;
            T[v].ind = x;
            T[v].ans = T[v].pairInd.ff = T[v].pairInd.ss = -1;
            return;
        }
        
        if(x <= mid(l, r))
            upd(x, val, l, mid(l, r), v<<1);
        else
            upd(x, val, mid(l, r)+1, r, v<<1|1);
        
        T[v] = merge(T[v<<1], T[v<<1|1]);
    }
    
    node getMax(int x, int y, int l, int r, int v){
        if(r < x || y < l)
            return (node){-1, -1, -1, mp(-1, -1)};
        
        if(x <= l && r <= y)
            return T[v];
        
        node lef = getMax(x, y, l, mid(l, r), v<<1);
        node rig = getMax(x, y, mid(l, r)+1, r, v<<1|1);
        
        return merge(lef, rig);
    }
} Tree;

int n, q, a, b;
char type;

int main(){
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        scanf("%d", &a);
        Tree.upd(i, a, 1, n, 1);
    }
    
    scanf("%d", &q);
    while(q--){
        scanf(" %c%d%d", &type, &a, &b);
        
        if(type == 'U')
            Tree.upd(a, b, 1, n, 1);
        else{
            node temp = Tree.getMax(a, b, 1, n, 1);
            printf("%d\n", temp.ans);
        }
    }
    
	return 0;
}
