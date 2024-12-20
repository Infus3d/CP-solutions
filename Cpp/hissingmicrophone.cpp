#include "bits/stdc++.h"

using namespace std;

char s[35];

int main(){
	scanf("%s", s);
	int n = strlen(s);
	for(int i=1; i<n; i++){
		if(s[i] == s[i-1] && s[i] == 's'){
			puts("hiss");
			return 0;
		}
	}
	puts("no hiss");
	return 0;
}
