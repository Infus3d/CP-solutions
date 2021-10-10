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

int n, T[N<<2], M[N<<2], m=1, lz[N<<2];
char s[N], arr[N];

void push(int l, int r, int v){
    if(!lz[v])  return;
    
    T[v<<1] += lz[v]; T[v<<1|1] += lz[v];
    M[v<<1] += lz[v]; M[v<<1|1] += lz[v];
    
    lz[v<<1] += lz[v]; lz[v<<1|1] += lz[v];
    lz[v] = 0;
}

void upd(int x, int y, int val, int l, int r, int v){
    if(y < l || r < x)
        return;
    
    if(x <= l && r <= y){
        lz[v] += val;
        T[v] += val; M[v] += val;
        return;
    }
    
    push(l, r, v);
    
    upd(x, y, val, l, mid(l, r), v<<1);
    upd(x, y, val, mid(l, r)+1, r, v<<1|1);
    
    T[v] = min(T[v<<1], T[v<<1|1]);
    M[v] = max(M[v<<1], M[v<<1|1]);
}

int get(int x, int l, int r, int v){
    if(l == r)
        return T[v];
    
    push(l, r, v);
    
    if(x <= mid(l, r))
        return get(x, l, mid(l, r), v<<1);
    else
        return get(x, mid(l, r)+1, r, v<<1|1);
}

int main(){
    int nn = N-7;
    scanf("%d%s", &n, s);
    for(int i=0; i<n; i++){
        if(s[i] == 'L' || s[i] == 'R')
            m += s[i] == 'L' ? m > 1 ? -1 : 0 : +1;
        else{
            if(arr[m] == '(')   upd(m, nn, -1, 1, nn, 1);
            if(arr[m] == ')')   upd(m, nn, +1, 1, nn, 1);
            
            if(s[i] == '(')         upd(m, nn, +1, 1, nn, 1);
            else if(s[i] == ')')    upd(m, nn, -1, 1, nn, 1);
            
            arr[m] = s[i];
        }
        int minn = T[1], lastt = get(nn, 1, nn, 1);
        int maxx = M[1];
        
        if(minn > -1 && !lastt) printf("%d ", maxx);
        else                    printf("-1 ");
    }
    puts("");
    
	return 0;
}

