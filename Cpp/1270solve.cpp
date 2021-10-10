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

int n, m, k, arr[N], d[N], pos, val, ans, id=1, ppos, vval, a, cn, pos1, pos2;

int main(){
    scanf("%d%d", &n, &k);
    for(int t=1; t<=k+1; t++){
        printf("? ");
        for(int i=1; i<=k+1; i++)
            if(i != t)
                printf("%d ", i);
        puts(""); fflush(stdout);
        scanf("%d%d", &pos, &val);
        d[pos]++;
        arr[pos] = val;
        if(pos1 == 0)   pos1 = pos;
        if(pos1 != pos) pos2 = pos;
    }
    if(arr[pos1] > arr[pos2])
        printf("! %d\n", d[pos1]);
    else
        printf("! %d\n", d[pos2]);
    return 0;
}

