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

void solve() {
    
    int s,d,k;
    cin>>s>>d>>k;
    int bun = 2*s+2*d;
    int pat = s+2*d;
    if(bun > k && pat >= k) {
        cout << "YES\n";
    } else{
        cout << "NO\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin>>t;

    int i = 1;
    while(t--) {
        cout << "Case #" << i++ << ": ";
        solve();
    }
    return 0;
}

