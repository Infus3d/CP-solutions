#include "bits/stdc++.h"

#define N 1000+7

using namespace std;


int a, b, d[N];
int n, m;
long long ans, avail, sum;

int main(){
    scanf("%d", &n);
    for(int i=0; i<n; i++)
        scanf("%d", &d[i]);
    
    for(int i=0; i<n; i+=2){
        sum = avail = d[i];

        for(int j=i+1; j<n; j++){
            if(j % 2){
                sum -= d[j];
                long long csum = max(0ll, sum);
                if(csum <= avail){
                    ans += avail - csum + 1;
                    if(avail == d[i])
                        ans--;
                }
                avail = min(avail, max(0ll, sum));
            }
            else
                sum += d[j];

            // printf("i:%d,  j:%d, sum:%lld, avail:%lld,  ans:%lld\n", i, j, sum, avail, ans);

            if(sum < 0) break;
        }
    }

    printf("%lld\n", ans);

    return 0;
}