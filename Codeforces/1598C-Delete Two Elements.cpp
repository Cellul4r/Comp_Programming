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
const ll INF = 1e15+5;
const int N = 1e5+5;
const ll mod = 1000000007;

bool comp( ll a, ll b) {
    return abs(a) > abs(b);
}
void solve() {

    int n;
    cin>>n;
    vector<double> a(n);
    double sortedA[n];
    double k = 0;
    for(int i=0;i<n;++i) {
        cin>>a[i];
        k += a[i];
        sortedA[i] = a[i];
    }
    sort(sortedA,sortedA+n);
    k /= n;

    ll ans = 0;
    for(int i=0;i<n;++i) {
        int idx = lower_bound(sortedA+i+1,sortedA+n, 2*k - sortedA[i]) - sortedA;
        int idxr = upper_bound(sortedA+i+1,sortedA+n, 2*k - sortedA[i]) - sortedA;

        //cout << idx << " " << idxr << endl;
        ans += (idxr - idx);
    }
    cout << ans << endl;
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
/*
 */
