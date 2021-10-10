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

const int N = 5e3+7;
const int MOD = 1e9+7;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b;return 1;}return 0;}
template<class T> bool umax(T& a, T b) { if(a < b){ a = b;return 1;}return 0;}
template<class T> bool umod(T& a) { while(a < 0) a += MOD; a %= MOD; return 1;}
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> omar;

//	freopen("file.in" , "r" , stdin);
//	freopen("file.out" , "w" , stdout);

int n, m;
string a, b, t1, t2;
int ans = MOD;

vector<int> z_function(string s) {
    int nn = (int) s.length();
    vector<int> z(nn);
    for (int i = 1, l = 0, r = 0; i < nn; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < nn && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
 
    // for(int i = 0; i < sz(z; i++) {
    //     cout << z[i] << " ";
    // }
    // cout << endl;
 
    return z;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> a >> b; n = sz(a); m = sz(b);
    
    for(int i=0; i<n; i++){
        t1 = a.substr(i) + "#" + a;
        t2 = a.substr(i) + "#" + b;
//        cout << t1 << " " << t2 << endl;
        vector<int> z1 = z_function(t1);
        vector<int> z2 = z_function(t2);
        
        for(int j=0; j<n; j++)  z1[j] = z1[j+(n-i)+1];
        for(int j=0; j<m; j++)  z2[j] = z2[j+(n-i)+1];
        while(sz(z1) > n)   z1.ppb();
        while(sz(z2) > m)   z2.ppb();
        
        int z1mx1 = -1, z1mx2 = -1, seen1=0, z2mx1 = -1, z2mx2 = -1, seen2=0;
        for(int i : z1) umax(z1mx1, i);
        for(int i : z1){
            if(i != z1mx1)
                umax(z1mx2, i);
            if(i == z1mx1){
                if(seen1){
                    umax(z1mx2, i);
                    break;
                }
                seen1++;
            }
        }
        for(int i : z2) umax(z2mx1, i);
        for(int i : z2){
            if(i != z2mx1)
                umax(z2mx2, i);
            if(i == z2mx1){
                if(seen2){
                    umax(z2mx2, i);
                    break;
                }
                seen2++;
            }
        }
        
        int short1 = -1, short2 = -1;
        if(sz(z1) == 1) short1 = z1mx1;
        else            short1 = z1mx2+1;
        
        if(sz(z2) == 1) short2 = z2mx1;
        else            short2 = z2mx1 == 0 ? n-i+1 : z2mx2+1;
        
//        cout << short1 << " " << short2 << " x--> " << n-i+1 << endl;
        if(max(short1, short2) <= z1mx1 && max(short1, short2) <= z2mx1)
            umin(ans, max(short1, short2));
    }
    printf("%d\n", ans == MOD ? -1 : ans);
    
	return 0;
}

