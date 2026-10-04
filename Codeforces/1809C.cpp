/*
 *   author : cellul4r
 */
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(x) x.begin(), x.end()
const char nl = '\n';
const int N =1e5+1;
const int INF = 1e9+7;
const ll LINF = 1e18+7;

void setIO(string);
void solve(){
    
    // k = 0 -> all negatvie numbers
    // k = n*(n+1)/2 -> all positive numbers
    // k = 1 ->
    // n = 2
    // 1, 3, 6, 10, 15, 21 -> try to fit sum = k
    // -3 -4 10 -2    
    //  1  1  1 -1000

    // n = 3
    // k = 1 (1, -1000, -1000)
    // k = 2 (1, -2,     2)
    // k = 3 (1,  1,    -1000) 
    // k = 4 (2,  -1,    3)
    // k = 5 (1,   2,   -1)
    // k = 6 (1,   2,    3)
    // n = 4
    // (1, 2, 3 -1)
    // k = 7 -> (1, 1, 1, -2)
    // k = 8 -> (1, 2, 3, -3)
    // k = 9 -> (1, 2, 3, -1)
    // k = 10 -> (1, 2, 3, 4)
    vector<int> ans;
    for(int i = 1; i <= n; i++) {
        if(k == 0) {
            ans.push_back(-1000);
            continue;
        }
        if(i <= k) {
            ans.push_back(i);
            k -= i;
        } else {
            // how??
             
        }
    }
    for(auto &x : ans) {
        cout << x << " ";
    }
    cout << nl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;

    //setIO("");
    cin>>t;
    while(t--)solve();

    return 0;
}

void setIO(string s) {
    (void)!freopen((s + ".in").c_str(), "r", stdin);
    (void)!freopen((s + ".out").c_str(), "w", stdout);
}

