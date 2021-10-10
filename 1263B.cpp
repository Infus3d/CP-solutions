/*
ID : omarmuh1
PROG : test
LANG : C++11
*/

#include "bits/stdc++.h"
#include "ext/pb_ds/assoc_container.hpp"

#define mp make_pair
#define pb push_back
#define ppb pop_back
#define db puts("*****")
#define mid(x , y) ((x+y)>>1)
#define ff first
#define ss second
#define all(x)	x.begin(),x.end()
#define ll long long
#define sqr(x)	((x)*(x))
#define pii pair <int , int>
#define sz(x) int(x.size())
#define tr(it , c) for(__typeof(c.begin()) it = (c.begin()); it != (c.end()); it++)
#define y1 you_made_my_day

using namespace std;
using namespace __gnu_pbds;

const int N = 2e5+7;
const int MOD = 1e9+7;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b;return 1;}return 0;}
template<class T> bool umax(T& a, T b) { if(a < b){ a = b;return 1;}return 0;}
template<class T> bool umod(T& a, T b) { a += b; while(a < 0) a += MOD; a %= MOD; return 1;}
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> omar;

//	freopen("file.in" , "r" , stdin);
//	freopen("file.out" , "w" , stdout);

int a, b, t, n;
string s[12];
map<string, int> mk, cn;

int main(){
    scanf("%d", &t);
    while(t--){
        mk.clear();
        a = 0;
        scanf("%d", &n);
        for(int i=1; i<=n; i++){
            cin >> s[i];
            mk[s[i]]++;
        }
        
        for(int i=1; i<=n; i++){
            if(mk[s[i]] > 1){
                a++;
                string tr = s[i];
                for(int j=0; j<4; j++){
                    bool f = false;
                    s[i] = tr;
                    for(int k=0; k<10; k++){
                        s[i][j] = k+'0';
                        if(!mk[s[i]]){
                            f = true;
                            break;
                        }
                    }
                    if(f)   break;
                }
                mk[tr]--;
                mk[s[i]]++;
            }
        }
        
        printf("%d\n", a);
        for(int i=1; i<=n; i++)
            cout << s[i] << endl, mk[s[i]] = 0;
    }
    
    
	return 0;
}

