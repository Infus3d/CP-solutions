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

const int N = 1e6+7;
const int MOD = 1e9+7;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b;return 1;}return 0;}
template<class T> bool umax(T& a, T b) { if(a < b){ a = b;return 1;}return 0;}
template<class T> bool umod(T& a, T b) { a += b; while(a < 0) a += MOD; a %= MOD; return 1;}
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> omar;

//	freopen("file.in" , "r" , stdin);
//	freopen("file.out" , "w" , stdout);

int n, m, q, temp, cur, a, b, c;
int arr[N];
vector<int> V[N];
int T[N<<2], lz[N];

void upd(int x, int val, int l, int r, int v){
    if(l == r){
        T[v] = val;
        return;
    }
    
    if(x <= mid(l, r))
        upd(x, val, l, mid(l, r), v<<1);
    else
        upd(x, val, mid(l, r)+1, r, v<<1|1);
    
    T[v] = max(T[v<<1], T[v<<1|1]);
}

void push(int l, int r, int v){
    if(!lz[v])  return;
    
    T[v<<1] += lz[v];
    T[v<<1|1] += lz[v];
    
    lz[v<<1] += lz[v];
    lz[v<<1|1] += lz[v];
    
    lz[v] = 0;
}

void inc(int x, int y, int val, int l, int r, int v){
    if(y < l || r < x)
        return;
    
    if(x <= l && r <= y){
        T[v] += val;
        lz[v] += val;
        
        return;
    }
    
    push(l, r, v);
    
    inc(x, y, val, l, mid(l, r), v<<1);
    inc(x, y, val, mid(l, r)+1, r, v<<1|1);
    
    T[v] = max(T[v<<1] , T[v<<1|1]);
}

int main(){
    scanf("%d%d%d", &n, &m, &q);
    
    for(int i=1; i<=n; i++) scanf("%d", &arr[i]), cur += arr[i] >= arr[1];
    
    for(int i=1; i<=m; i++){    
        scanf("%d", &temp);
        upd(i, cur-(n-temp), 1, m, 1);
        
        for(int j=0; j<temp; j++){
            scanf("%d", &a);
            
            V[i].pb(a);
            cur += a > arr[1];
        }
    }
    
    while(q--){
        scanf("%d%d%d", &a, &b, &c); b--;
        
        if(a < m){
            if(V[a][b] < arr[1] && c > arr[1])
                inc(a+1, m, +1, 1, m, 1);
            else if(V[a][b] > arr[1] && c < arr[1])
                inc(a+1, m, -1, 1, m, 1);
        }
        
        V[a][b] = c;
        printf("%d\n", T[1] < 1);
    }
    
	return 0;
}

