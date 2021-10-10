/*
ID : omarmuh1
PROG : test
LANG : C++11
*/

#include "bits/stdc++.h"
#include "ext/pb_ds/assoc_container.hpp"
#include "time.h"

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

const ll N = 1e3+7;
const ll MOD = 99824435332321;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b;return 1;}return 0;}
template<class T> bool umax(T& a, T b) { if(a < b){ a = b;return 1;}return 0;}
template<class T> bool umod(T& a, T b) { a += b; while(a < 0) a += MOD; a %= MOD; return 1;}
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> omar;

//	freopen("file.in" , "r" , stdin);
//	freopen("file.out" , "w" , stdout);
/*
int arr[N], vis[N];

ll mod(ll x){ return x % MOD; }
map <int, int> M;


int exp(int x, int y){
    if(!y)  return 1;
    
    int h = exp(x, y/2);
    
    return mod(mod(1LL * h * h) * (y&1 ? x : 1LL));
}*/
/*
long long a = 3000;
long long b[] = {1, 2, 3, 4, 5, 6};
long long *ptr, **ptrr;
int pointr;
*/
void printdey(long long *pt){
	/*for(int i=0; i<6; i++)
		printf("%d ", *(pt+i));
	puts("");*/
	
	*(pt+1) = 18LL;
}

//int arr[] = {4, 1, 12, 3, 8};
int a=1;
vector<int> v;

int main(){
    v.pb(1); v.pb(6); v.pb(123);
    printf("%d\n", lower_bound(all(v), 6)-v.begin());
    printf("%d\n", lower_bound(all(v), 124)-v.begin());
    /*
    M[1] = 1;
    M[4] = 2;
    M[6] = 3;
    M[7] = 3;
    M[-2] = 6;
    M[-5] = 10;
    
    auto a = M.upper_bound(-5);
    
    printf("%d %d %d\n", a->ff, a->ss,  a == M.end());*/
    /*
    ptr = &a;
	ptrr = &ptr;
	printf("%d\n", a);
	printf("%d\n", ptr);
	printf("%d\n", ptrr);
	printdey(b);
	for(int i=0; i<6; i++)
		printf("%d ", b[i]); puts("");
	*/
	/*
	sort(arr, arr+5, [](int x, int y){
		return x < y;
	});
	
	for(int i=0; i<5; i++)	
		printf("%d ", arr[i]); 
	puts("");*/
	
	return 0;
}
/*

*/
