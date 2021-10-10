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

const int N = 1e6+7;
const int MOD = 1e9+7;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b;return 1;}return 0;}
template<class T> bool umax(T& a, T b) { if(a < b){ a = b;return 1;}return 0;}
template<class T> bool umod(T& a, T b) { a += b; while(a < 0) a += MOD; a %= MOD; return 1;}
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> omar;

//	freopen("file.in" , "r" , stdin);
//	freopen("file.out" , "w" , stdout);

int n, testcase, Trie[N][27], Cn[N][27], node, ans;
char str[N];

void add(){
    int m = strlen(str);
    int cur = 0;
    
    for(int i=0; i<m; i++){
        if(!Trie[cur][str[i]-'a']){
            Cn[cur][str[i]-'a'] = 0, Trie[cur][str[i]-'a'] = ++node;
            for(int j=0; j<26; j++)  Trie[node][j] = 0;
        }
        Cn[cur][str[i]-'a']++;
        cur = Trie[cur][str[i]-'a'];
    }
}

int get(){
    int cur = 0;
    int m = strlen(str);
    int res = 0;
    
    for(int i=0; i<m; i++){
        res++;
        
        if(Cn[cur][str[i]-'a'] == 1)    
            break;
        
        cur = Trie[cur][str[i]-'a'];
    }
    
    return res;
}

int main(){
    scanf("%d", &testcase);
    
    for(int tcase=1; tcase<=testcase; tcase++){
        scanf("%d", &n);
        
        node = 0; ans = 0;
        for(int i=0; i<26; i++) Trie[node][i] = 0;
        
        for(int i=1; i<=n; i++){
            scanf("%s", str);
            add();
            ans += get();
        }
        
        printf("Case #%d: %d\n", tcase, ans);
    }
    
	return 0;
}
/*
1
3
having
fun
yet

*/
