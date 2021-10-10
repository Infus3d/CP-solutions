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

const int N = 1e5+7;
const int MOD = 1e9+7;
const int MX = 1e5;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b;return 1;}return 0;}
template<class T> bool umax(T& a, T b) { if(a < b){ a = b;return 1;}return 0;}
template<class T> bool umod(T& a, T b) { a += b; while(a < 0) a += MOD; a %= MOD; return 1;}
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> omar;

//	freopen("file.in" , "r" , stdin);
//	freopen("file.out" , "w" , stdout);

int n, m, arr[N], number, T[N<<2];
char arrow;

void assignment(int v, int val){
    if(val == 1){
        if(T[v] < 2)
            T[v] ^= val;
        else if(T[v] == 2)
            T[v] = 3;
        else
            T[v] = 2;
    }
    else
        T[v] = val;
}

void push(int l, int r, int v){
    if(!T[v])   return;
    
    assignment(v<<1, T[v]);
    assignment(v<<1|1, T[v]);
    
    T[v] = 0;
}

void upd(int x, int y, int val, int l, int r, int v){
    if(y < l || r < x)
        return;
    
    if(x <= l && r <= y){
        assignment(v, val);
        return;
    }
    
    push(l, r, v);
    
    upd(x, y, val, l, mid(l, r), v<<1);
    upd(x, y, val, mid(l, r)+1, r, v<<1|1);
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
    scanf("%d%d", &n, &m);
    
    for(int i=1; i<=n; i++) scanf("%d", &arr[i]);
    
    while(m--){
        scanf(" %c%d", &arrow, &number);
        
        if(arrow == '<'){
            if(number > 0){
                upd(0, number-1, 1, 0, MX, 1);
                upd(number, MX, 2, 0, MX, 1);
            }
            else if(abs(number) != MX)
                upd(abs(number)+1, MX, 2, 0, MX, 1);
        }
        else{ // '>' number
            if(number < 0){
                upd(0, abs(number)-1, 1, 0, MX, 1);
                upd(abs(number), MX, 3, 0, MX, 1);
            }
            else if(number != MX)
                upd(number+1, MX, 3, 0, MX, 1);
        }
    }
    
    for(int i=1; i<=n; i++){
        int sign = get(abs(arr[i]), 0, MX, 1);
        int temp = arr[i];
        
        if(sign == 1)
            temp = -temp;
        else if(sign == 2)
            temp = (int)abs(temp);
        else if(sign == 3)
            temp = -(int)abs(temp);
        
        printf("%d ", temp);
    }
    puts("");
    
	return 0;
}

