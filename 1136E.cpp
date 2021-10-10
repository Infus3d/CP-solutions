#include <bits/stdc++.h>

#define mid(x, y)	((x+y)>>1)
#define ff first
#define ss second
#define ll long long

const int N = 1e5+7;
const ll MOD = -1e18-7;

using namespace std;

ll T[N<<2], lz[N<<2], S[N<<2];
ll arr[N], k[N], t[N];
int n, m, a, b;
char ch;

void push(int l, int r, int v){
	if(lz[v] == MOD)	return;
	
	T[v<<1] = lz[v];
	T[v<<1|1] = lz[v];
	
	S[v<<1] = lz[v]*(mid(l, r)-l+1);
	S[v<<1|1] = lz[v]*(r-mid(l,r));
	
	lz[v<<1] = lz[v];
	lz[v<<1|1] = lz[v];
	lz[v] = MOD;
}

void upd(int x, int y, ll val, int l, int r, int v){
	if(y < l || r < x)
		return;
	
	if(x <= l && r <= y){
		T[v] = val;
		S[v] = val*(r-l+1);
		lz[v] = val;
		return;
	}
	
	push(l, r, v);
	
	upd(x, y, val, l, mid(l, r), v<<1);
	upd(x, y, val, mid(l, r)+1, r, v<<1|1);
	
	T[v] = max(T[v<<1], T[v<<1|1]);
	S[v] = S[v<<1] + S[v<<1|1];
}

ll get(int x, int l, int r, int v){
	if(l == r)
		return T[v];
	
	push(l, r, v);
	
	if(x <= mid(l, r))
		return get(x, l, mid(l, r), v<<1);
	else
		return get(x, mid(l, r)+1, r, v<<1|1);
}

int getIndex(ll val, int l, int r, int v){
	if(l == r)
		return l;
	
	push(l, r, v);
	
	if(T[v<<1] < val)
		return getIndex(val, mid(l, r)+1, r, v<<1|1);
	else
		return getIndex(val, l, mid(l, r), v<<1);
}

ll getSum(int x, int y, int l, int r, int v){
	if(y < l || r < x)
		return 0;
	
	if(x <= l && r <= y)
		return S[v];
	
	push(l, r, v);
	
	return getSum(x, y, l, mid(l, r), v<<1) + getSum(x, y, mid(l, r)+1, r, v<<1|1);
}

int main(){
	for(int i=0; i<(N<<2); i++)	 lz[i] = MOD;
	scanf("%d", &n);
	for(int i=1; i<=n; i++)	scanf("%lld", &arr[i]);
	for(int i=1; i<n; i++)	scanf("%lld", &k[i]);
	for(int i=2; i<=n; i++)	t[i] = t[i-1]+k[i-1];
	for(int i=1; i<=n; i++) t[i] += t[i-1];
	for(int i=1; i<=n; i++)	upd(i, i, arr[i]-(t[i]-t[i-1]), 1, n, 1);
	
    scanf("%d", &m);
	while(m--){
		scanf(" %c%d%d", &ch, &a, &b);
		
		if(ch == 's')
			printf("%lld\n", getSum(a, b, 1, n, 1)+(t[b]-t[a-1]));
		else{
			ll cur = get(a, 1, n, 1);
			int ind = getIndex(cur+b, 1, n, 1);
			upd(a, ind-(get(ind, 1, n, 1) > cur+b), cur+b, 1, n, 1);
		}
	}
	
	return 0;
}
