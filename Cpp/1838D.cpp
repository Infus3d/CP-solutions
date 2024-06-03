#include "bits/stdc++.h"

#define ff first
#define ss second
#define pb push_back
#define ll long long
#define db puts("*****")
#define sz(x) int(x.size())
#define pii pair <int , int>
#define mid(x , y) ((x+y)>>1)
#define all(x)	x.begin(),x.end()
#define y1 your_name_engraved_herein

using namespace std;

const int N = 2e5+2;
const int K = 1e3+2;
const int MOD = 998244353;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0; }
template<class T> bool umax(T& a, T b) { if(a < b){ a = b; return 1; } return 0; }

char s[N];

void solve(){
    int n, m;
    scanf("%d%d", &n, &m);
    scanf("%s", s);
    set<int> opening, closing;
    for(int i=0; i<n-1; i++){
        if(s[i] == '(' && s[i+1] == '('){
            opening.insert(i);
        }
        if(s[i] == ')' && s[i+1] == ')'){
            closing.insert(i);
        }
    }
    // opening.insert(n);
    // closing.insert(-1);
    for(int qcnt=1; qcnt<=m; qcnt++){
        int x; scanf("%d", &x); x--;
        if(x > 0){
            if(s[x] == '('){
                if(s[x-1] == s[x]) opening.erase(x-1);
                else closing.insert(x-1);
            } else {
                if(s[x-1] == s[x]) closing.erase(x-1);
                else opening.insert(x-1);
            }
        }
        if(x < n-1){
            if(s[x] == '('){
                if(s[x+1] == s[x]) opening.erase(x);
                else closing.insert(x);
            } else {
                if(s[x+1] == s[x]) closing.erase(x);
                else opening.insert(x);
            }
        }
        s[x] = (s[x] == ')') ? '(' : ')';
        // printf("******************* query %d: %s *******************\n", qcnt, s);
        // printf("Double opening indices:\n");
        // for(int i : opening) printf("%d ", i);
        // puts("");
        // printf("Double closing indices:\n");
        // for(int i : closing) printf("%d ", i);
        // puts("");
        if(n % 2 == 1 || s[0] == ')' || s[n-1] == '('){
            puts("NO");
            continue;
        }
        if(opening.empty() && closing.empty()){
            puts("YES");
        } else if((opening.empty() && !closing.empty()) || (!opening.empty() && closing.empty())){
            puts("NO");
        } else if(*closing.begin() < *opening.begin() || *closing.rbegin() < *opening.rbegin()){
            puts("NO");
        } else {
            puts("YES");
        }
    }
}

int main(){
    int testcase = 1;
    // scanf("%d", &testcase);
    while(testcase--){
        solve();
    }
    return 0;
}
