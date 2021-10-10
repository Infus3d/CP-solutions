#include <bits/stdc++.h>

using namespace std;

const int N = 2e5+7;
const ll MX = 2e18;
typedef long long ll;

int n, k, ans;
ll arr[N], s[N];

int main(){
	scanf("%d%d", &n, &k);
	for(int i=1; i<=n; i++)	scanf("%lld", &arr[i]), s[i] = arr[i]*k;
	
	for(int i=1; i<=n; i++){
		ll cur = 1;
		ll sum = 0;
		
		for(int j=i; j<=n; j++){
			if(cur * arr[j] > MX || cur*arr[j] < cur)
				break;
			
			cur *= arr[j];
			sum += s[j];

			if(cur == sum)
				ans++;
		}
	}
	
	printf("%d\n", ans);

	return 0;
}