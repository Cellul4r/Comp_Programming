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
#define A(a) (a).begin(),(a).end()
using pii = pair<int,int>;
using piL = pair<int,long>;
using pip = pair<int,pair<int,int>>;
const int INF = 1e9;
const int N = 1e5;

ll triArea(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {

    ll area = x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2);
    return area;
}
void solve() {
    
    int n;
    cin>>n;
    int ans = INF;
    vector<pair<ll,ll>> coor(n);
    for(int i=0;i<n;++i) {
        cin>> coor[i].f >> coor[i].s;
    }
    for(int i=0;i<n;++i) {
        ll x1 = coor[i].f, y1 = coor[i].s;
        for(int j=i+1;j<n;++j) {
            ll x1 = coor
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin>>t;

    for(int i=1;i<=t;++i){
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}
