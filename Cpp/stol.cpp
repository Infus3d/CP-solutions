#include "bits/stdc++.h"

using namespace std;

const int N = 1e3+1;
char s[N][N];

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i=0; i<n; i++){
		scanf("%s", s[i]);
	}
	vector<vector<int>> a(n, vector<int>(m, 0));
	for(int i=0; i<n; i++){
		int idx = -1;
		for(int j=0; j<m; j++){
			if(s[i][j] == 'X'){
				idx = j;
			} else {
				a[i][j] = j - idx;
			}
		}
	}
	int ans = 0;
	for(int j=0; j<m; j++){
		stack<pair<int, int>> st;
		for(int i=0; i<n; i++){
			int val = a[i][j];
			int maxPerim = val ? (val + i + 1) : val;
			while(!st.empty() && a[st.top().first][j] >= val){
				st.pop();
			}
			if(!st.empty()){
				maxPerim = max(st.top().second + i - st.top().first, i - st.top().first + val);
			}
			st.push({i, maxPerim});
			ans = max(ans, maxPerim);
		}
	}
	printf("%d\n", 2*ans-1);
	
	return 0;
}
/**
7 7
XXX.XXX
XX...XX
X.....X
.......
.......
.......
.......

10 10
XXXXX.XXXX
XXXX..XXXX
......XXXX
XXXXX.....
XXXXX.XXXX
XXXXX.XXXX
XXXXX.XXXX
XXXXX.XXXX
XXXXX.XXXX
XXXXX.XXXX
**/
