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
    
    int n;
    double p;
    cin>>n>>p;
    p /= 100.00;
    //cout << p/pow(p, (double)1/n) - p << endl;
    double k = (p/(pow(p,(double)1/n)) - p) * 100; 
    cout << fixed << setprecision(9) << k << endl;
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
