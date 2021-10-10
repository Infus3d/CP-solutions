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

int n, m, vis[N], ans[N], par[N], tot;
char grid[N];
int dx[] = {-1, -1, 0, +1, +1, +1, 0, -1};
int dy[] = {0, +1, +1, +1, 0, -1, -1, -1};

int cell(int x, int y){
    return x < 1 || y < 1 ? 0 : (x-1)*m+y;
}

int getSum(int x, int y, int dif){
    return par[cell(x, y)] - par[cell(x-dif, y)] - par[cell(x, y-dif)] + par[cell(x-dif, y-dif)];
}

bool isOk(int x, int y){
    return x > 0 && y > 0 && x <= n && y <= m;
}

int isPossible(int t){
    int dif = t*2+1, curtot = 0;
    memset(vis, 0, sizeof(vis));
    
    queue<pair<pii,int>> Q;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            if((i >= dif && j >= dif) && !getSum(i, j, dif))
                vis[cell(i-t, j-t)] = 1, Q.push({{i-t, j-t}, t}), curtot++;
    
    while(!Q.empty()){
        auto tr = Q.front(); Q.pop();
        if(!tr.ss)  continue;
        
        for(int i=0; i<8; i++){
            int x = tr.ff.ff, y = tr.ff.ss;
            if(isOk(x+dx[i], y+dy[i]) && !vis[cell(x+dx[i], y+dy[i])])
                vis[cell(x+dx[i], y+dy[i])] = 1, Q.push({{x+dx[i], y+dy[i]}, tr.ss-1}), curtot++;
        }
    }
    
    return curtot == tot;
}

int main(){
    scanf("%d%d", &n, &m);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            scanf(" %c", &grid[cell(i, j)]);
            par[cell(i, j)] = par[cell(i-1, j)] + par[cell(i, j-1)] - par[cell(i-1, j-1)] + (grid[cell(i,j)] == '.');
            tot += grid[cell(i, j)] == 'X';
        }
    }
    
    int lo = 0, hi = (min(n,m)-1)/2;
    while(lo < hi){
        if(isPossible(mid(lo+1, hi)))
            lo = mid(lo+1, hi);
        else
            hi = mid(lo+1, hi)-1;
    }
    
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            if((i >= lo*2+1 && j >= lo*2+1) && !getSum(i, j, lo*2+1))
                ans[cell(i-lo, j-lo)] = 1;
    
    printf("%d\n", lo);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++)
            printf("%c", ans[cell(i, j)] ? 'X' : '.');
        puts("");
    }
    
	return 0;
}
/*
15 14               
..............      
..XXXXXXXX....      
..XXXXXXXXXXXX      
..XXXXXXXXXXXX      
XXXXXXXXXXXXXX      
XXXXXXXXXXXXXX      
XXXXXXXXXXXXXX      
XXXXXXXXXXXXX.      
XXXXXXXXXXXXX.      
..XXXXXXXXX...      
.XXXXXXXXXXX..      
.XXXXXXXXXXX..      
.XXXXXXXXXXX..      
.XXXXXXXXXXX..      
.XXXXXXXXXXX..      

2
..............
..............
..............
....XXXX......
....XXXXXXXX..
....XXXXXXX...
..XXXXXXXXX...
....XXXXX.....
....XXXXX.....
....XXXXX.....
....XXXXX.....
....XXXXX.....
...XXXXXXX....
..............
..............
*/
