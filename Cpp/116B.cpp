#include "bits/stdc++.h"
// #include "ext/pb_ds/assoc_container.hpp"
 
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
#define pll pair <ll, ll>
#define sz(x) int(x.size())
#define tr(it , c) for(__typeof(c.begin()) it = (c.begin()); it != (c.end()); it++)
#define y1 you_made_my_day
 
using namespace std;
// using namespace __gnu_pbds;
 
const int N = 2e5+7;
const int M = 600;
const int MOD = 998244353;
const int K = 1e3+7;
 
template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0;}
template<class T> bool umax(T& a, T b) { if(a < b){ a = b;return 1;}return 0;}
template<class T> bool umod(T& a) { while(a < 0) a += MOD; a %= MOD; return 1;}
// typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
 
//	freopen("file.in" , "r" , stdin);
//	freopen("file.out" , "w" , stdout);

struct Point{
    int x, y;
    bool flag = false;
    bool operator< (const Point &other) const {
        return ((*this).x < other.x) || (x == other.x && y < other.y);
    }
};

int n, m, top;
Point p[N];
Point s[N];

ll cross_product(const Point &O, const Point &A, const Point &B){
    return 1LL*(A.x - O.x)*(B.y - O.y) - 1LL * (B.x - O.x)*(A.y - O.y);
}

void andrew_chain(){
    sort(p, p+n);
    
    for(int i=0; i<n; i++){
        while(top >= 2 && cross_product(s[top-2], s[top-1], p[i]) < 0LL) top--;
        s[top++] = p[i];
    }
    top--;
    
    for(int i=n-1, temp = top; i>=0; i--){
        while(top >= temp+2 && cross_product(s[top-2], s[top-1], p[i]) < 0LL) top--;
        s[top++] = p[i];
    }
    top--;
}

int main(){
    scanf("%d", &n);
    for(int i=0; i<n; i++)
        scanf("%d%d", &p[i].x, &p[i].y);
    
    scanf("%d", &m);
    for(int i=n; i<n+m; i++)
        scanf("%d%d", &p[i].x, &p[i].y), p[i].flag = true;
    
    n += m;
    andrew_chain();
    
    for(int i=0; i<top; i++)
        if(s[i].flag == true)
            return printf("NO\n"), 0;
    printf("YES\n");
    
	return 0;
}
