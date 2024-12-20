#include "bits/stdc++.h"

using namespace std;

const int N = 2e5+1;
const int K = 450+1;

int lightTotal[K][K];
int A[N];

int main(){
	int n, q;
	scanf("%d%d", &n, &q);
	while(q--){
		int t; scanf("%d", &t);
		if(t == 1){
			int a, b, c;
			scanf("%d%d%d", &a, &b, &c);
			if(b < K){
				lightTotal[b][a] += c;
			} else {
				for(int i=a; i<=n; i+=b){
					A[i] += c;
				}
			}
		} else {
			int d; scanf("%d", &d);
			int additional = 0;
			for(int i=1; i<K; i++){
				additional += lightTotal[i][d%i];
			}
			printf("%d\n", A[d] + additional);
		}
	}
	return 0;
}
