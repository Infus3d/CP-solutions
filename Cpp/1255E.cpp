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

const int N = 1e6+7;
const ll MOD = 998244353271;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b;return 1;}return 0;}
template<class T> bool umax(T& a, T b) { if(a < b){ a = b;return 1;}return 0;}
template<class T> bool umod(T& a, T b) { a += b; while(a < 0) a += MOD; a %= MOD; return 1;}
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> omar;

//	freopen("file.in" , "r" , stdin);
//	freopen("file.out" , "w" , stdout);

int prime[N];
vector <ll> V;
ll arr[N], ans = 2e18, cur, las, tot, d[N];
int n;

bool isPrime(ll x){
	for(ll i=2; i*i<=x; i++)
		if(x % i == 0)
			return false;
	
	return true;
}

ll mod(ll x, ll y){
	while(x < 0) x += y;
	
	return x % y;
}

int main(){
	scanf("%d", &n);
	
	for(int i=1; i<=n; i++)
		scanf("%lld", &arr[i]), tot += arr[i];
	
	if(tot == 1){
		printf("-1\n");
		return 0;
	}
	
	prime[1] = 1;
	for(int i=2; i<=N-7; i++)
		if(prime[i] == 0)
			for(int j=i+i; j<=N-7; j+=i)
				prime[j]++;
	
	ll m = tot;
	for(int i=1; i<=min((int)sqrt(m), N-7); i++){
		if(m % i != 0)	continue;
		
		ll j = m/i;
		
		if(!prime[i])
			V.pb(i);
		if(j <= N-7 && !prime[j])
			V.pb(j);
		if(j > N-7 && isPrime(j))
			V.pb(j);
	}
	
	for(ll f : V){
		cur = 0LL;
		for(int i=1; i<=n; i++)
			d[i] = arr[i];
		
		for(int i=1; i<=n; i++){
			if(mod(d[i], f) == 0)
				continue;
			
			ll md = mod(d[i], f);
			
			if(d[i] < 0){
				d[i] += f-md;
				d[i+1] -= f-md;
				cur += f-md;
			}
			else if(md <= f-md){
				d[i+1] += md;
				d[i] -= md;
				cur += md;
			}
			else{
				d[i] += f-md;
				d[i+1] -= f-md;
				cur += f-md;
			}
		}
		ans = min(ans, cur);
		
		cur = 0;
		for(int i=1; i<=n; i++)
			d[i] = arr[i];
		
		for(int i=n; i>=1; i--){
			if(mod(d[i], f) == 0)
				continue;
			
			ll md = mod(d[i], f);
			
			if(d[i] < 0){
				d[i] += f-md;
				d[i-1] -= f-md;
				cur += f-md;
			}
			else if(md <= f-md){
				d[i-1] += md;
				d[i] -= md;
				cur += md;
			}
			else{
				d[i] += f-md;
				d[i-1] -= f-md;
				cur += f-md;
			}
		}
		
		ans = min(ans, cur);
	}
	//puts("");
	printf("%lld\n", ans);
	
	return 0;
}