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
const int MOD = 1e9+7;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0; }
template<class T> bool umax(T& a, T b) { if(a < b){ a = b; return 1; } return 0; }

int c[50];
unordered_map<int, bool>vis;

void solve(){
  c[1] = 2;
	c[2] = 2;
	c[3] = 3;
	c[4] = 3;
	c[5] = 3;
	c[6] = 3;
  int n, total;
		cin>>n;
		if(n <= 6){
			cout<<c[n]<<endl;
			return;
		}
		int x = n/6, y, z;
		x = sqrt(x);
		y = x;
		z = y;
		total = x * x * 6;
		if(total >= n){	
			cout<<x+y+z<<endl;
			return;
		}	
		int alpha = z/2+1;
		total-=(x-alpha)*2;
		total+=(x-alpha)*6;	
		total+=(x-(x-alpha))*2;
		if(total >= n){
			cout<<x+y+z+1<<endl;
			return;
		}
		else
			cout<<x+y+z+2<<endl;
}

int main(){
  int testcase = 1;
  scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
