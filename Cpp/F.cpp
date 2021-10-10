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

const int N = 2e2+7;
const int MOD = 1e3+7;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b;return 1;}return 0;}
template<class T> bool umax(T& a, T b) { if(a < b){ a = b;return 1;}return 0;}
template<class T> bool umod(T& a) { while(a < 0) a += MOD; a %= MOD; return 1;}
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> omar;

//	freopen("file.in" , "r" , stdin);
//	freopen("file.out" , "w" , stdout);

int dp[N][N][N], track[N][N][N], a, b, c;
int n, m;
char s[N], t[N];

int rec(int x, int y, int bal){
    if(bal > N-7 || bal < 0 || x > n || y > m) return MOD;
    if(x == n && y == m)    return bal;
    
    int &ret = dp[x][y][bal];
    if(~ret)    return ret;
    ret = MOD;
    
    int x1 = x + (x < n && s[x] == ')');
    int y1 = y + (y < m && t[y] == ')');
    int x2 = x + (x < n && s[x] == '(');
    int y2 = y + (y < m && t[y] == '(');
    
    if(umin(ret, rec(x1, y1, bal-1)))
        track[x][y][bal] = 0;
    if(umin(ret, rec(x2, y2, bal+1)))
        track[x][y][bal] = 1;
    
    return ++ret;
}

int main(){
    scanf("%s%s", s, t);
    n = strlen(s); m = strlen(t);
    memset(dp, -1, sizeof(dp));
    memset(track, -1, sizeof(track));
    rec(0, 0, 0);
    
    while(track[a][b][c] != -1){
        if(track[a][b][c]){
            printf("(");
            a += a < n && s[a] == '(';
            b += b < m && t[b] == '(';
            c++;
        }
        else{
            printf(")");
            a += a < n && s[a] == ')';
            b += b < m && t[b] == ')';
            c--;
        }
    }
    while(c--)  printf(")");
    puts("");
    
	return 0;
}

