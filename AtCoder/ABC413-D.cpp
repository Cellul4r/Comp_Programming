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
bool equal(long double a, long double b) {
    return abs(a - b) < 1e-9;
}
void solve(){
    
    int n;
    cin>>n;
    vector<ll> pos,neg,a(n);
    for(int i = 0; i < n; i++) {
        ll x;
        cin>>x;
        if(x < 0) {
            neg.push_back(x);
        } else {
            pos.push_back(x);
        }
    }
    auto comp = [&](ll i, ll j) {
        return llabs(i) < llabs(j);
    };
    sort(all(pos), comp);
    sort(all(neg), comp);
    if(neg.empty()) {
        a = pos;
    } else if(pos.empty()) {
        a = neg;
    } else if(abs((int)pos.size() - (int)neg.size()) > 1) {
        cout << "No\n";
        return;
    } else if(pos.size() == neg.size()) {
        int i = 0, j = 0;
        int start = 0;
        if(pos[0] < llabs(neg[0])) {
            start = 1;
        }
        for(int k = 0; k < n; k++, start^=1) {
            if(start) {
                a[k] = pos[i++];
            } else {
                a[k] = neg[j++];
            }
        }
    } else if(neg.size() < pos.size()) {
        // pos neg pos neg pos neg
        int i = 0, j = 0;
        for(int k = 0, start = 1; k < n; k++, start^=1) {
            if(start) {
                a[k] = pos[i++];
            } else {
                a[k] = neg[j++];
            }
        }

    } else {
        // neg pos neg pos neg
        int i = 0, j = 0;
        for(int k = 0, start = 0; k < n; k++, start^=1) {
            if(start) {
                a[k] = pos[i++];
            } else {
                a[k] = neg[j++];
            }
        }
    }
    for(int i = 0; i < n; i++) cerr << a[i] << " ";
    for(int i = 1; i < n - 1; i++) {
        if(a[i] * a[i] != a[i-1] * a[i+1]) {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
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


