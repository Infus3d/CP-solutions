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
template<class T> bool umod(T& a) { while(a < 0) a += MOD; a %= MOD; return 1;}
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> omar;

//	freopen("file.in" , "r" , stdin);
//	freopen("file.out" , "w" , stdout);

int T[N<<2], pos[N], n, m, arr[N], middle;
set<int> setik;
ll ans[N], S[N<<2], p[N];

void updT(int x, int l, int r, int v){
    if(l == r){
        T[v] = 1;
        return;
    }
    
    if(x <= mid(l, r))
        updT(x, l, mid(l, r), v<<1);
    else
        updT(x, mid(l, r)+1, r, v<<1|1);
    
    T[v] = T[v<<1] + T[v<<1|1];
}

int getT(int x, int y, int l, int r, int v){
    if(y < l || r < x)
        return 0;
    
    if(x <= l && r <= y)
        return T[v];
    
    return getT(x, y, l, mid(l, r), v<<1) + getT(x, y, mid(l, r)+1, r, v<<1|1);
}

void updS(int x, int val, int l, int r, int v){
    if(l == r){
        S[v] = val*l;
        return;
    }
    
    if(x <= mid(l, r))
        updS(x, val, l, mid(l, r), v<<1);
    else
        updS(x, val, mid(l, r)+1, r, v<<1|1);
    
    S[v] = S[v<<1] + S[v<<1|1];
}

ll getS(int x, int y, int l, int r, int v){
    if(y < l || r < x)
        return 0LL;
        
    if(x <= l && r <= y)
        return S[v];
    
    return getS(x, y, l, mid(l, r), v<<1) + getS(x, y, mid(l, r)+1, r, v<<1|1);
}

ll cnt(int x, int y){
    return (1LL*(y+x)*(y-x+1))/2LL;
}

int main(){
    scanf("%d", &n);
    for(int i=1; i<=n; i++) scanf("%d", &arr[i]), pos[arr[i]] = i;
    for(int i=n; i>=1; i--){
        updT(arr[i], 1, n, 1);
        if(arr[i] > 1)
            p[arr[i]] = getT(1, arr[i]-1, 1, n, 1);
    }
    for(int i=1; i<=n; i++) p[i] += p[i-1];
    
    setik.insert(pos[1]); middle = pos[1];
    updS(pos[1], -1, 1, n, 1);
    for(int step=2; step<=n; step++){
        updS(pos[step], pos[step] > middle ? 1 : -1, 1, n, 1);
        setik.insert(pos[step]);
        
        if((step-1)%2 == 1 && pos[step] < middle){
            updS(middle, 1, 1, n, 1);
            middle = *(--setik.lower_bound(middle));
        }
        else if((step-1)%2 == 0 && pos[step] > middle){
            middle = *(setik.upper_bound(middle));
            updS(middle, -1, 1, n, 1);
        }
        
        int half = step / 2 + (step%2);
        if(step % 2 == 1){
            ans[step] = getS(1, middle-1, 1, n, 1) + getS(middle+1, n, 1, n, 1);
            ans[step] += cnt(1, half-1) - cnt(half+1, step);
        }
        else
            ans[step] = S[1] + cnt(1, half) - cnt(half+1, step);
        
        ans[step] += p[step];
    }
    
    for(int i=1; i<=n; i++)
        printf("%lld ", ans[i]);
    puts("");
    
	return 0;
}

