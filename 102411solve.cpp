#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
ll n;
ll x, y, h;
ll x_1=INT_MAX, x_2=INT_MIN, y_1=INT_MAX, y_2=INT_MIN;
ll ans_x, ans_y, ans_h = 1e18;
 
int main() {
    scanf("%lld", &n);
    for(int i=0; i<n; i++) {
        scanf("%lld %lld %lld", &x, &y, &h);
        x_1 = min(x_1, x-h);
        x_2 = max(x_2, x+h);
        y_1 = min(y_1, y-h);
        y_2 = max(y_2, y+h);
    }
    
    for(int i=0; i<2; i++)
        for(int j=0; j<2; j++){
            ll x_ans = (x_2+x_1)/2+i; //((x_2-x_1)%2);
            ll y_ans = (y_2+y_1)/2+j; //((y_2-y_1)%2);
            ll h_ans = max(max(x_2-x_ans, x_ans-x_1), max(y_2-y_ans, y_ans-y_1));
             if(h_ans < ans_h)
                 ans_h = h_ans, ans_x = x_ans, ans_y = y_ans;
        }
    assert(ans_h >= 0);
    printf("%lld %lld %lld\n", ans_x, ans_y, ans_h);
 
    return 0;
}
