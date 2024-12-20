/*
Count how many of each verdict you have in kattis and dom judge separately.
Add the minimum of the two to the answer for each such verdict.

Runtime O(n)
*/
#include "bits/stdc++.h"

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	map<string, int> dom, kattis;
	for(int i=0; i<n; i++){
		string s; cin >> s;
		dom[s]++;
	}
	for(int i=0; i<n; i++){
		string s; cin >> s;
		kattis[s]++;
	}
	int ans = 0;
	for(auto &i : dom){
		ans += min(dom[i.first], kattis[i.first]);
	}
	cout << ans << endl;
		
	return 0;
}
