#include "bits/stdc++.h"

using namespace std;

int main(){
	int n; scanf("%d", &n);
	
	vector<int> ap(n), ah(n);
	vector<int> a(n);
	for(int i=0; i<n; i++){
		scanf("%d", &ap[i]);
		a[i] = i;
	}
	for(int i=0; i<n; i++){
		scanf("%d", &ah[i]);
	}
	
	vector<int> bp(n), bh(n);
	vector<int> b(n);
	for(int i=0; i<n; i++){
		scanf("%d", &bp[i]);
		b[i] = i;
	}
	for(int i=0; i<n; i++){
		scanf("%d", &bh[i]);
	}
	
	
	sort(a.begin(), a.end(), [&](int x, int y){
		return ap[x] < ap[y];
	});
	sort(b.begin(), b.end(), [&](int x, int y){
		return bp[x] < bp[y];
	});
	
	int aa = 0, bb = 0;
	
	vector<int> ansa, ansb;
	
	set<pair<int, int>> asetik;
	set<pair<int, int>> bsetik;
	while(aa < n || bb < n || (int)asetik.size() > 0 || (int)bsetik.size() > 0){
		if(!(int)asetik.size() && aa < n){
			int need = ap[a[aa]];
			asetik.insert({ah[a[aa]], a[aa]});
			aa++;
			while(aa < n && need == ap[a[aa]]){
				asetik.insert({ah[a[aa]], a[aa]});
				aa++;
			}
		}
		if(!(int)bsetik.size() && bb < n){
			int need = bp[b[bb]];
			bsetik.insert({bh[b[bb]], b[bb]});
			bb++;
			while(bb < n && need == bp[b[bb]]){
				bsetik.insert({bh[b[bb]], b[bb]});
				bb++;
			}
		}
		if((int)asetik.size() <= (int)bsetik.size()){
			while(!asetik.empty()){
				auto [aval, aid] = *asetik.begin();
				asetik.erase(asetik.begin());
				auto it = bsetik.lower_bound({aval, -1});
				if(it == bsetik.begin()){
					puts("impossible");
					return 0;
				}
				it--;
				ansa.push_back(aid);
				ansb.push_back((*it).second);
				bsetik.erase(it);
			}
		} else {
			while(!bsetik.empty()){
				auto [bval, bid] = *bsetik.begin();
				bsetik.erase(bsetik.begin());
				auto it = asetik.upper_bound({bval, n});
				if(it == asetik.end()){
					puts("impossible");
					return 0;
				}
				ansa.push_back((*it).second);
				ansb.push_back(bid);
				asetik.erase(it);
			}
		}
	}
	assert((int)ansa.size() == n);
	assert((int)ansb.size() == n);
	for(int i=0; i<n; i++){
		printf("%d ", ansa[i]+1);
	} puts("");
	for(int i=0; i<n; i++){
		printf("%d ", ansb[i]+1);
	} puts("");
	
	
	return 0;
}
