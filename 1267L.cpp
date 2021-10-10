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

const int N = 1e3+7;
const int MOD = 1e9+7;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b;return 1;}return 0;}
template<class T> bool umax(T& a, T b) { if(a < b){ a = b;return 1;}return 0;}
template<class T> bool umod(T& a, T b) { a += b; while(a < 0) a += MOD; a %= MOD; return 1;}
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> omar;

//	freopen("file.in" , "r" , stdin);
//	freopen("file.out" , "w" , stdout);

string s[N];
int n, l, k, a, cur, m, d[30], las=25;
char st[N*N];

int main(){
    cin.tie(0);    
    scanf("%d%d%d", &n, &l, &k); scanf("%s", st);
    for(int i=0; i<n*l; i++) d[st[i]-'a']++;
    while(!d[las])  las--; while(!d[cur])   cur++;
    for(int i=0; i<k; i++)  s[i] = "";
    for(int t=0; t<l; t++)
        for(int i=a; i<k; i++){
            if(!d[cur]){
                while(!d[cur]) cur++;
                if(a != k-1){
                    for(int j=a; j<i; j++)
                        for(int w=t+1; w<l; w++){
                            while(!d[las]) las--; d[las]--;
                            s[j] += 'a'+las;
                        }
                    a = i;
                }
            }
            d[cur]--;
            s[i] += cur+'a';        
        }
    
    for(int j=0; j<l; j++)
        for(int i=k; i<n; i++){
            while(!d[cur]) cur++; d[cur]--;
            s[i] += cur+'a';
        }
    sort(s, s+n);
    
    for(int i=0; i<n; i++)
        cout << s[i] << endl;
    
	return 0;
}

