/*
ID : omarmuh1
PROG : test
LANG : C++11
*/

#include "bits/stdc++.h"
//#include "ext/pb_ds/assoc_container.hpp"

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
//using namespace __gnu_pbds;

const int N = 2e5+7;
const ll MOD = 998244353;
const int K = 7;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b;return 1;}return 0;}
template<class T> bool umax(T& a, T b) { if(a < b){ a = b;return 1;}return 0;}
template<class T> bool umod(T& a) { while(a < 0) a += MOD; a %= MOD; return 1;}
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

//	freopen("file.in" , "r" , stdin);
//	freopen("file.out" , "w" , stdout);

int n, m, k, arr[N][K], c[K], type, a, b;
int T[N<<2][35], M[N<<2][35];

void upd(int x, int id, int val, int l, int r, int v){
    if(l == r){
        T[v][id] = val;
        M[v][id] = val;
        return;
    }
    
    if(x <= mid(l, r))
        upd(x, id, val, l, mid(l, r), v<<1);
    else
        upd(x, id, val, mid(l, r)+1, r, v<<1|1);
    
    T[v][id] = max(T[v<<1][id], T[v<<1|1][id]);
    M[v][id] = min(M[v<<1][id], M[v<<1|1][id]);
}

int getMax(int x, int y, int id, int l, int r, int v){
    if(y < l || r < x)
        return -MOD;
    
    if(x <= l && r <= y)
        return T[v][id];
    
    return max(getMax(x, y, id, l, mid(l, r), v<<1), getMax(x, y, id, mid(l, r)+1, r, v<<1|1));
}

int getMin(int x, int y, int id, int l, int r, int v){
    if(y < l || r < x)
        return MOD;
    
    if(x <=l && r <= y)
        return M[v][id];
    
    return min(getMin(x, y, id, l, mid(l, r), v<<1), getMin(x, y, id, mid(l, r)+1, r, v<<1|1));
}

int main(){
    scanf("%d%d", &n, &k);
    for(int w=1; w<=n; w++){
        for(int j=1; j<=k; j++)
            scanf("%d", &arr[w][j]);
        
        for(int i=0; i<(1<<k); i++){
            int tmp = 0;
            for(int j=1; j<=k; j++)
                tmp += ((i&(1<<(j-1))) ? 1 : -1) * arr[w][j];
            upd(w, i, tmp, 1, n, 1);
        }
    }
    
    scanf("%d", &m);
    while(m--){
        scanf("%d", &type);
        if(type == 1){
            scanf("%d", &a);
            for(int i=1; i<=k; i++)
                scanf("%d", &c[i]);
            
            for(int i=0; i<(1<<k); i++){
                int tmp = 0;
                for(int j=1; j<=k; j++)
                    tmp += ((i&(1<<(j-1))) ? 1 : -1) * c[j];
                upd(a, i, tmp, 1, n, 1);
            }
            for(int i=1; i<=k; i++)
                arr[a][i] = c[i];
        }
        else{
            scanf("%d%d", &a, &b);
            int mx = -MOD;
            for(int i=0; i<(1<<k); ++i){
                int curmax = getMax(a, b, i, 1, n, 1);
                int curmin = getMin(a, b, i, 1, n, 1);
                
                umax(mx, curmax-curmin);
            }
            
            printf("%d\n", mx);
        }
    }
    return 0;
}

