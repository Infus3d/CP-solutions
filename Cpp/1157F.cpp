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
const int nn = N-7;
const int MOD = 1e9+7;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b;return 1;}return 0;}
template<class T> bool umax(T& a, T b) { if(a < b){ a = b;return 1;}return 0;}
template<class T> bool umod(T& a, T b) { a += b; while(a < 0) a += MOD; a %= MOD; return 1;}
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> omar;

//	freopen("file.in" , "r" , stdin);
//	freopen("file.out" , "w" , stdout);

int n, arr[N], P[N], S[N], ans, ind, lef, rig;
int T[N<<2];

void form_tree(int l, int r, int v){
    if(l == r){
        T[v] = P[l];
        return;
    }
    
    form_tree(l, mid(l, r), v<<1);
    form_tree(mid(l, r)+1, r, v<<1|1);
    
    T[v] = min(T[v<<1], T[v<<1|1]);
}

void upd(int x, int val, int l, int r, int v){
    if(l == r){
        T[v] += val;
        return;
    }
    
    if(x <= mid(l, r))
        upd(x, val, l, mid(l, r), v<<1);
    else
        upd(x, val, mid(l, r)+1, r, v<<1|1);
        
    T[v] = min(T[v<<1], T[v<<1|1]);
}

int get(int x, int y, int l, int r, int v){
    if(y < l || r < x)
        return MOD;
    
    if(x <= l && r <= y)
        return T[v];
        
    return min(get(x, y, l, mid(l, r), v<<1), get(x, y, mid(l, r)+1, r, v<<1|1));
}

int main(){
    scanf("%d", &n);
    for(int i=1; i<=n; i++) scanf("%d", &arr[i]), P[arr[i]]++, S[arr[i]]++;
    form_tree(1, nn, 1);
    for(int i=1; i<=nn; i++)    S[i] += S[i-1];
    
    for(int i=1; i<=nn; i++){
        if(!P[i])   continue;
        upd(i, +1, 1, nn, 1);
        
        int lup=i, rup = nn;
        
        while(lup + 1 < rup){
            if(get(i, mid(lup, rup), 1, nn, 1) >= 2)
                lup = mid(lup, rup);
            else
                rup = mid(lup, rup)-1;
        }
        
        for(int j=lup; j<=rup; j++)
            if(get(i, j, 1, nn, 1) >= 2)
                lup = j;
        
        int ldown = 1, rdown = i;
        
        while(ldown + 1 < rdown){
            if(get(mid(ldown, rdown), i, 1, nn, 1) >= 2)
                rdown = mid(ldown, rdown);
            else
                ldown = mid(ldown, rdown)+1;
        }
        
        for(int j=rdown; j>=ldown; j--)
            if(get(j, i, 1, nn, 1) >= 2)
                rdown = j;
        
        upd(i, -1, 1, nn, 1);
        
        if(P[i] == 1){
            int sumup = S[lup] - S[i-1] + P[lup+1];
            int sumdown = S[i] - S[rdown-1] + P[rdown-1];
            int smax = max(sumup, sumdown);
            
            if(sumup > ans)
                ans = sumup, ind = i, lef = i, rig = lup;
            if(sumdown > ans)
                ans = sumdown, ind = i, lef = rdown, rig = i;
        }
        else{
            int sum = P[i];
            if(lup > i)
                sum += S[lup] - S[i];
            if(rdown < i)
                sum += S[i-1] - S[rdown-1];
            
            if(sum > ans)
                ans = sum, ind = i, lef = rdown, rig = lup;
        }
    }
    
    printf("%d\n", ans); 
    for(int i=ind; i<=rig; i++) printf("%d ", i), P[i]--;
    if(P[rig+1])
        if(P[rig] || lef == ind)
            printf("%d ", rig+1);
    for(int i=rig; i>=ind; i--)
        while(P[i]) printf("%d ", i), P[i]--;
    
    for(int i=ind-1; i>=lef; i--)   printf("%d ", i), P[i]--;
    if(P[lef-1] == 1)   
        if(P[lef] || rig == ind)
            printf("%d ", lef-1);
            
    for(int i=lef; i<ind; i++)
        while(P[i]) printf("%d ", i), P[i]--;
    
	return 0;
}

