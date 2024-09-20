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
 
    int n,v;
    cin>>n>>v;
    int now = 0;
    int price = 0;
    for(int i=1;i<=n;++i) {
 
        int minFuel = min(n - i,v - now);
        price += minFuel * i;
        now += minFuel;
        if(n - i <= now) break;
        --now;
    }
 
    cout << price;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    //cin>>t;
    //sf("%d",&t); 
    while(t--) {
        solve();
    }
    return 0;
}
