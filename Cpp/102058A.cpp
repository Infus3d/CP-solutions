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
template<class T> bool umod(T& a) { while(a < 0) a += MOD; a %= MOD; return 1;}
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> omar;

//	freopen("file.in" , "r" , stdin);
//	freopen("file.out" , "w" , stdout);

int n, m, a, b, degc[N], dege[N], degr[N], vis[N], ans[N];
vector<int> E[N], R[N];
bool cyclic = false;
pii p[N], init[N];
set<pii> setik;
vector<int> add[N], del[N];

void go(){
    queue<int> Q;
    for(int i=1; i<=n; i++)
        if(!degc[i])
            Q.push(i);
    
    while(!Q.empty()){
        int tr = Q.front(); Q.pop();
        vis[tr] = 1;
        
        for(int i : E[tr]){
            if(vis[i]){
                cyclic = true;
                return;
            }
            
            degc[i]--;
            if(!degc[i])
                Q.push(i);    
        }
    }
    
    for(int i=1; i<=n; i++)
        if(!vis[i])
            cyclic = true;
}

void lefts(){
    queue<int> Q;
    for(int i=1; i<=n; i++)
        if(!dege[i])
            Q.push(i);
    
    while(!Q.empty()){
        int tr = Q.front(); Q.pop();
        for(int i : E[tr]){
            p[i].ff = max(p[i].ff, p[tr].ff+1);
            dege[i]--;
            if(!dege[i])
                Q.push(i);
        }
    }
}

void rights(){
    queue<int> Q;
    for(int i=1; i<=n; ++i)
        if(!degr[i])
            Q.push(i);
    
    while(!Q.empty()){
        int tr = Q.front(); Q.pop();
        for(int i : R[tr]){
            p[i].ss = min(p[i].ss, p[tr].ss-1);
            degr[i]--;
            if(!degr[i])
                Q.push(i);
        }
    }
}

int main(){
    scanf("%d%d", &n, &m);
    for(int i=1; i<=n; i++){
        scanf("%d%d", &a, &b);
        p[i] = {a, b};
        init[i] = p[i];
    }
    for(int i=1; i<=m; i++){
        scanf("%d%d", &a, &b);
        E[a].pb(b);
        R[b].pb(a);
        dege[b]++;
        degr[a]++;
        degc[b]++;
    }
    
    go();
    if(cyclic)
        return 0 * printf("-1\n");
    
    lefts();
    rights();
    /*
    db;
    for(int i=1; i<=n; i++)
        printf("%d %d\n", p[i].ff, p[i].ss);
    */
    for(int i=1; i<=n; i++){
        if(p[i].ff > p[i].ss)
            return 0 * printf("-1\n");
            
        add[p[i].ff].pb(i), del[p[i].ss].pb(i);
    }
    
    for(int i=1; i<=n; i++){
        for(int j : add[i])
            setik.insert({p[j].ss, j});
//        printf("%d ", i);
        if(setik.empty())
            return 0 * printf("-1\n");
        
        pii tr = *setik.begin();
        ans[i] = tr.ss;
        setik.erase(tr);
//        printf("%d %d\n", tr.ss, tr.ff);
        
        for(int j : del[i])
            setik.erase({i, j});
    }
    
    for(int i=1; i<=n; i++){
        printf("%d\n", ans[i]);
        assert(init[ans[i]].ff <= i && i <= init[ans[i]].ss);
    }
	return 0;
}
/*
10 7
1 10
2 4
1 7
3 6
4 5
1 8
1 10
2 8
2 10
4 10
7 1
1 5
5 8
2 4
3 5
3 10
4 6
*/
