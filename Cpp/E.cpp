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
const int K = 600;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b;return 1;}return 0;}
template<class T> bool umax(T& a, T b) { if(a < b){ a = b;return 1;}return 0;}
template<class T> bool umod(T& a) { while(a < 0) a += MOD; a %= MOD; return 1;}
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> omar;

//	freopen("file.in" , "r" , stdin);
//	freopen("file.out" , "w" , stdout);

int n, m, k, dleft[N], dright[N], tri[N][27], cn, word[N], num;
char s[N], t[N];
string str;
ll ans;

vector<int> z_function() {
    int nn = sz(str);
    vector<int> z(nn);
    for (int i = 1, l = 0, r = 0; i < nn; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < nn && str[z[i]] == str[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
 
    // for(int i = 0; i < z.size(); i++) {
    //     cout << z[i] << " ";
    // }
    return z;
}

void insert(){
    int x = 0;
    for(int i=0; i<m; i++){
        if(!tri[x][t[i]-'a'])
            tri[x][t[i]-'a'] = ++cn;
        x = tri[x][t[i]-'a'];
    }
    word[x]++;
}

void find(int idx){
    int x = 0;
    for(int i=idx; i<n; i++){
        if(!tri[x][s[i]-'a'])
            break;
        
        x = tri[x][s[i]-'a'];
        dleft[i] += word[x];
        dright[idx] += word[x];
    }
}

int main(){
    scanf("%s", s); n = strlen(s);
    scanf("%d", &k);
    while(k--){
        scanf("%s", t); m = strlen(t);
        
        if(m <= K)
            insert();
        else{
            str = "";
            for(int i=0; i<m; i++)  str += t[i];
            str += '#';
            for(int i=0; i<n; i++)  str += s[i];
            
            vector<int> z = z_function();
            for(int i=m+1; i<n+m+1; i++)
                z[i-m-1] = z[i];
            for(int i=0; i<n; i++)
                if(z[i] == m)
                    dright[i]++, dleft[i+m-1]++;
        }
    }
    for(int i=0; i<n; i++)  find(i);
	for(int i=0; i<n-1; i++)
	   ans += 1LL * dleft[i] * dright[i+1];
	
	printf("%lld\n", ans);
	
    return 0;
}

