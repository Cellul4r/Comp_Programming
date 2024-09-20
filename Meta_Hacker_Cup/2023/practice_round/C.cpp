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
const ll INF = LLONG_MAX;
const int N = 1e5;

ll helper(ll k, vector<ll>& a) {

    int l = 0, r = a.size() - 1;
    ll skipVal = -1;
    while(l <= r) {
       if(l == r) {
           if(skipVal == -1) skipVal = a[l];
           else return INF;
           ++l,--r;
       } else if(a[l] + a[r] == k) {
           ++l;
           --r;
       } else if(a[l] + a[r] < k) {
           if(skipVal == -1) skipVal = a[l];
           else {
               //cout << l << " " << r << endl;
               return INF;
           }
           ++l;
       } else {
           if(skipVal == -1) skipVal = a[r];
           else {
               //cout << l << " " << r << endl;
               return INF;
           }
           --r;
       }
    }
    //cout << "Check : " << skipVal << endl;
    if(skipVal == -1 || k - skipVal <= 0) return INF;
    return k - skipVal;
}
void solve() {
    
    int n;
    cin>>n;
    int m = 2*n-1;
    vector<ll> a(m);
    for(int i=0;i<m;++i) {
        cin>>a[i];
    }
    if(n == 1) {
        cout << 1 << endl;
        return;
    }
    sort(A(a));
    ll ans = INF;
    vector<ll> candi{a[0] + a[m-1],
                     a[0] + a[m-2],
                     a[1] + a[m-1]};
     
    for(auto c:candi) {
        ans = min(ans,helper(c,a));
    }
    cout << (ans == INF ? -1 : ans) << endl;
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

