#include "bits/stdc++.h"

using namespace std;

int main(){
  int n; scanf("%d", &n);
  long long sum = 0;
  vector<long long> v(n);
  for(int i=0; i<n; i++){
    int a; scanf("%d", &a);
    sum += a;
    v[i] = (sum+i)/(i+1);
    if(i > 0)
      v[i] = max(v[i], v[i-1]);
  }
  
  int q; scanf("%d", &q);
  while(q--){
    int x; scanf("%d", &x);
    long long y = sum / x + (sum % x > 0);
    if(y > n || x < v[y-1]) y = -1;
    printf("%lld\n", y);
  }
  
  return 0;
}
