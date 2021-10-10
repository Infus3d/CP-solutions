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

int n, a, b, pr[30], cur[30], vis[30];
char s[60];
set<int> setik;

int bul(int x){
    if(pr[x] == x)
        return x;
    return pr[x] = bul(pr[x]);
}

int main(){
    for(int i=0; i<27; i++) pr[i] = i;
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        scanf("%s", s);
        a = strlen(s);
        memset(cur, 0, sizeof(cur));
        for(int j=0; j<a; j++)  cur[s[j]-'a']=vis[s[j]-'a']=1;
        for(int j=0; j<26; j++)
            for(int k=j+1; k<26; k++)
                if(cur[j] == cur[k] && cur[j])
                    pr[bul(j)] = bul(k);
    }
    
    for(int i=0; i<26; i++)
        if(vis[i])
            setik.insert(bul(i));
    printf("%d\n", setik.size());
    
	return 0;
}

