#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define L long
#define sLL signed long long
#define uLL unsigned long long
#define f first 
#define s second
#define pf printf
#define sf scanf
using pii = pair<int,int>;
using piL = pair<int,long>;
using pip = pair<int,pair<int,int>>;
const int INF = 1e9;
const int N = 1e9;
const ll mod = 1e12+7;
 
void solve() {
 
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;++i) {
        cin>>a[i];
    }
 
    int prev = 0;
    vector<int> ans(n);
    for(int i=n-1;i>=0;--i) {
        int k = max(prev,a[i]);
        if(k >= 1) {
            ans[i] = 1;
            --k;
            prev = k;
        }
    }
 
    for(auto x:ans) {
        cout << x << " ";
    }
    cout << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin>>t;
    //sf("%d",&t); 
    while(t--) {
        solve();
    }
    return 0;
}
