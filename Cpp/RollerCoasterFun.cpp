#include <bits/stdc++.h> 

#define ll long long

using namespace std;

int N, a[105], b[105], tx[105], dp[100][25005];


int f(int i, int t){
	if(i == N)
		return 0;
	if(t > 25000)
		return 0;
	if(dp[i][t] != -1)
		return dp[i][t];
	int k = 0, tt;
	int maxi = -1;
	
	maxi =  max(maxi, f(i+1, t));
    
    if(b[i] > 0){
        for(int j = 0; j <= 25000 && a[i] - j*j*b[i] > 0; j++){
            k += a[i] - j*j*b[i];
            tt = tx[i] * (j + 1);
            
            if(tt <= t){
                maxi = max(maxi, k + f(i+1, t - tt));
            }else{
                break;
            }
        }
    } else {
        if(tx[i] <= t){
            maxi = max(maxi, f(i, t - tx[i]) + a[i]);
        }
    }
	return (dp[i][t] = maxi);
}

int main(){

	cin >> N;

	for(int i = 0; i < N; i++){
		cin >> a[i] >> b[i] >> tx[i];
	}
	
	int q,x;
	cin >> q;
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j <= 25000; j++){
			dp[i][j] = -1;
		}
	}
	
	f(0, 25000);
	
	for(int i = 0; i < q; i++){
		cin >> x;
		
		cout << f(0, x) << endl;
	}
	return 0;	
}
