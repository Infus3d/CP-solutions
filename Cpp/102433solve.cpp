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
 
const int N = 5e5+7;
const int MOD = 11092019;
const int B = 707;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b;return 1;}return 0;}
template<class T> bool umax(T& a, T b) { if(a < b){ a = b;return 1;}return 0;}
template<class T> bool umod(T& a) { while(a < 0) a += MOD; a %= MOD; return 1;}
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> omar;
 
//	freopen("file.in" , "r" , stdin);
//	freopen("file.out" , "w" , stdout);

struct myNode{
    int st, en, val;
} T[N*8];

int n, m, q, qcount=1, arr[N], siz[N];
vector<int> M[N*8];
int a, b, c, cn, cnt, type;
pii p[N];
vector<pii> v, vv;

void updM(int x, int y, int val, int l, int r, int v){
    if(y < l || r < x)
        return;
    
    if(x <= l && r <= y){
        M[v].pb(val);
        return;
    }
    
    updM(x, y, val, l, mid(l, r), v<<1);
    updM(x, y, val, mid(l, r)+1, r, v<<1|1);
}

int getM(int x, int val, int l, int r, int v){
    int tr = upper_bound(all(M[v]), val)-M[v].begin();
    if(!sz(M[v]))   tr = 0;
    if(l == r)
        return tr;
    
    if(x <= mid(l, r))
        return tr + getM(x, val, l, mid(l, r), v<<1);
    else
        return tr + getM(x, val, mid(l, r)+1, r, v<<1|1);
}

void push(int l, int r, int v){
    if(!T[v].val)    return;
    
    T[v<<1].st = T[v].st; 
    T[v<<1].en = mid(T[v].st, T[v].en);   
    T[v<<1].val = T[v].val;
    
    T[v<<1|1].st = mid(T[v].st, T[v].en)+1; 
    T[v<<1|1].en = T[v].en; 
    T[v<<1|1].val = T[v].val;
    
    T[v].st = T[v].en = T[v].val = 0;
}

void updT(int x, int y, int valst, int valen, int val, int l, int r, int v){
//    printf("updT(): %d %d %d %d %d %d %d %d\n", x, y, valst, valen, val, l, r, v);
    if(y < l || r < x)
        return;
        
    if(x <= l && r <= y){
        T[v].st = l-x+valst;
        T[v].en = l-x+valst+(r-l);
        T[v].val = val;
        return;
    }
    
    push(l, r, v);
    
    updT(x, y, valst, valen, val, l, mid(l, r), v<<1);
    updT(x, y, valst, valen, val, mid(l, r)+1, r, v<<1|1);
}

pii getT(int x, int l, int r, int v){
//    printf("getT(): %d %d %d %d %d %d %d\n", x, T[v].st, T[v].en, T[v].val, l, r, v);
    if(l == r){
        assert(T[v].st == T[v].en);
        return {T[v].st, T[v].val};
    }
    
    push(l, r, v);
    
    if(x <= mid(l, r))
        return getT(x, l, mid(l, r), v<<1);
    else
        return getT(x, mid(l, r)+1, r, v<<1|1);
}

int main(){
    scanf("%d%d%d", &n, &m, &q);
    int tot = 0;
    for(int i=1; i<=m; i++){
        scanf("%d", &a);
        p[i].ff = cn+1;
        siz[i] = a; tot += a;
        for(int j=1; j<=a; j++){
            scanf("%d", &arr[++cn]);
        }
        p[i].ss = cn;
    }
    
    for(int query=1; query<=q; query++){
        scanf("%d%d", &type, &a);
        if(type == 1){
            scanf("%d", &b);
            updT(b, b+siz[a]-1, p[a].ff, p[a].ss, qcount, 1, n, 1);
//            pii temp = getT(5, 1, n, 1);
//            printf("%d %d\n", temp.ff, temp.ss);
        }
        else if(type == 2){
            pii ind = getT(a, 1, n, 1);
            if(ind.ff == 0){
                puts("0");
                continue;
            }
            assert(ind.ff > 0 && ind.ss > 0);
//            printf("**** %d %d %d %d\n", ind.ff, ind.ss, arr[ind.ff], getM(ind.ff, ind.ss, 1, N-7, 1));
            int cur = (arr[ind.ff] + getM(ind.ff, ind.ss, 1, N-6, 1))%256;
            printf("%d\n", cur);
        }
        else{
            scanf("%d%d", &b, &c); 
            int aa = p[a].ff+b-1, bb = p[a].ff+c-1;
            ++qcount;
            updM(aa, bb, qcount, 1, N-6, 1);
        }
    }
    
	return 0;
}
