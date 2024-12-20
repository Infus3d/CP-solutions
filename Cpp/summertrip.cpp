/*
There are only 26 letters in the egnlish alphabet. So you can count for each r = i,
the number of candidate l = j where j < i, with last[s[i]] < last[s[j]]. Note that
there can be at most 25 such candidates for l. Here, last[a] represents the last index
the character 'a' was seen so far (as you are scanning 1 to n).

Runtime O(|alphabet| * n)
or O(n)
*/
#include "bits/stdc++.h"

using namespace std;

const int N = 1e5+2;

char s[N];

int main(){
	scanf("%s", s);
	int n = strlen(s);
	vector<int> seen(26, -1);
	int ans = 0;
	for(int i=0; i<n; i++){
		int cur = s[i] - 'a';
		for(int j=0; j<26; j++){
			if(seen[j] > seen[cur]){
				ans++;
			}
		}
		seen[cur] = i;
	}
	printf("%d\n", ans);
	return 0;
}
