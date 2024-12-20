//
// Created by rnahra on 10/20/2024.
//
#include <iostream>
#include <bits/stdc++.h>

using namespace std;



//~ double prob(int n, double* p, int S, int i) {
    //~ double p1=1.0,p2=1.0;
    //~ for(int j=0;j<n;j++) {
        //~ if ( (S&(1<<j)) &&  i!=j) {
            //~ p1*=1-p[j];
            //~ p2*=p[j];
        //~ }
    //~ }
    //~ return p[i]*p1+(1-p[i])*p2;
//~ }


int main() {
    int n;
    vector<vector<int>> subsetk;

    scanf("%d",&n);
    double p[n];
    double E[1<<n];

    int i;
    for(i=0;i<n;i++) {
        subsetk.push_back(vector<int>());
        cin>> p[i];
    }
    subsetk.push_back(vector<int>());
    for (int S=0;S<(1<<n);S++) {
        E[S]=0;
        int sizeS = 0;
        for(int i = 0; i < n; i++){
            sizeS += (bool)((1 << i) & S);

        }
        //cout<<sizeS<<endl;
        subsetk[sizeS].push_back(S);
    }


	for(int S=0; S<(1<<n); S++){
		if(__builtin_popcount(S) <= 2) continue;
		double sum1=0.0;
		double pos = 1.0, neg = 1.0;
		for(int j=0;j<n;j++){
			if (S&(1<<j)){
				pos *= p[j];
				neg *= (1 - p[j]);
			}
		}
		for(int j=0; j<n; j++){
			if(S&(1<<j)){
				sum1 += pos/p[j]*(1-p[j]);
				sum1 += neg/(1-p[j])*p[j];
			}
		}
		//~ if (S==7) {
			//~ cout<<"here!!!-> "<<prob(n,p,S,0)/sum1<<endl;
		//~ }
		E[S] = 1.0/sum1;
		for(int i=0;i<n;i++){
			if (S&(1<<i)) {
				double x=pos/p[i]*(1-p[i]) + neg/(1-p[i])*p[i];
				E[S] += (x/sum1)*E[S^(1<<i)];
			}
		}

    }
    printf("%.6lf\n", E[((1<<(n))-1)]);

    return 0;
}
