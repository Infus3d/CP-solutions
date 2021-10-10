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
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

//	freopen("file.in" , "r" , stdin);
//	freopen("file.out" , "w" , stdout);

int T[N<<2];
int n, m, a, b;
char s[N], c;
set<int> setik[130];

void form_tree(int l, int r, int v){
    if(l == r){
        T[v] = 1;
        return;
    }
    
    form_tree(l, mid(l, r), v<<1);
    form_tree(mid(l, r)+1, r, v<<1|1);
    
    T[v] = T[v<<1] + T[v<<1|1];
}

void upd(int x, int l, int r, int v){
    if(l == r){
        T[v] = 0;
        return;
    }
    
    if(x <= mid(l, r))
        upd(x, l, mid(l, r), v<<1);
    else
        upd(x, mid(l, r)+1, r, v<<1|1);
    
    T[v] = T[v<<1] + T[v<<1|1];
}

int getInd(int x, int l, int r, int v){  
    if(l == r)
        return l;
    
    if(T[v<<1] >= x)
        return getInd(x, l, mid(l, r), v<<1);
    else
        return getInd(x-T[v<<1], mid(l, r)+1, r, v<<1|1);
}

int main(){
    scanf("%d%d", &n, &m);
    scanf("%s", s);
    
    for(int i=1; i<=n; i++)
        setik[s[i-1]-'0'].insert(i);
    form_tree(1, n, 1);
    
    while(m--){
        scanf("%d%d %c", &a, &b, &c);
        
        int aa = getInd(a, 1, n, 1);
        int bb = getInd(b, 1, n, 1);
//        printf("*** %d %d %d\n", aa, bb, c-'0');  
        vector<int> temp;     
        auto ptr = setik[c-'0'].lower_bound(aa);
        while(ptr != setik[c-'0'].end() && *ptr <= bb)
            upd(*ptr, 1, n, 1), temp.pb(*ptr), ptr++;
        while(sz(temp))
            setik[c-'0'].erase(temp[sz(temp)-1]), temp.ppb();
    }
    
    for(int i=1; i<=n && i<=T[1]; i++)
        printf("%c", s[getInd(i, 1, n, 1)-1]);
    puts("");
    
	return 0;
}

