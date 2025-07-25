/*
 *   author : cellul4r
 */
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
#define all(x) x.begin(), x.end()
const char nl = '\n';
const int N =1e5+1;
const int INF = 1e9+7;
const ll LINF = 1e18+7;

void setIO(string);
void solve(){
    
    int n;
    cin>>n;
    multiset<ll> a;
    ll sum = 0;
    for(int i = 0; i < n; i++) {
        int x;
        cin>>x;
        a.insert(x);
        sum += x;
    }
    // the initial weight of array a is sum!
    priority_queue<ll> Q; 
    Q.push(sum);
    while(!Q.empty() && !a.empty()) {
        ll u = Q.top(); 
        Q.pop();
        if(a.count(u)) {
            a.erase(a.find(u));
            continue;
        }
        if(u == 1 || *a.rbegin() > u) break;
        Q.push(u / 2);
        Q.push((u+1) / 2);
    }
    cout << (a.empty() ? "YES" : "NO") << nl;
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

