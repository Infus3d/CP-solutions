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

void solve(){
    int n; cin >> n;
    set<pair<string, string>> setik;
    for(int i=0; i<n; i++){
        string name;
        cin >> name;
        name = name.substr(0, name.length()-1);
        string sclass, theWordClass;
        cin >> sclass >> theWordClass;
        istringstream sstream(sclass);
        string token;
        vector<string> v;
        while(std::getline(sstream, token, '-')) {
            // std::cout << token << endl;
            v.push_back(token);
        }
        reverse(all(v));
        while(sz(v) < 10){
            v.push_back("middle");
        }
        string socialRank = "";
        for(int j=0; j<sz(v); j++){
            string toAdd = "m";
            if(v[j][0] == 'l') toAdd = "u";
            else if(v[j][0] == 'u') toAdd = "l";
            socialRank += toAdd;
            if(j < sz(v)-1){
                socialRank += "-";
            }
        }
        // cout << name << " " << socialRank << endl;
        setik.insert({socialRank, name});
    }
    for(auto [sclass, name] : setik){
        cout << name << endl;
    }
    for(int i=0; i<30; i++){
        cout << "=";
    }
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int testcase = 1;
    cin >> testcase;
    while(testcase--){
        solve();
    }
    return 0;
}
