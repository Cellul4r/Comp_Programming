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
const int N =2e5+1;
const int INF = 1e9+7;
const ll LINF = 1e18+7;

bool isRev(vector<int>& a, vector<int>& b) {

    int n = a.size();
    for(int i = 0; i < n; i++) {
        if(a[i] != b[n - i - 1]) {
            return false;
        }
    }
    return true;
}

int valA[N], valB[N];
void doSwap(vector<int>& a, vector<int>& b, int i, int j) {
    swap(valA[a[i]],valA[a[j]]);
    swap(valB[b[i]],valB[b[j]]);
    swap(a[i],a[j]);
    swap(b[i],b[j]);
}

void solve(){
    
    int n;
    cin>>n;
    vector<int> a(n),b(n);
    for(auto &x : a) {
        cin>>x;
    }
    for(auto &x : b) {
        cin>>x;
    }
    if(isRev(a,b)) {
        cout << 0 << nl << nl;
        return;
    }
    
    for(int i = 0; i < n; i++) {
        valA[a[i]] = i;
        valB[b[i]] = i;
    }
    // check if it is possible
    // it's impossible only if there are more than 1 position such that a[i] = b[i]
    int cnt = 0;
    int idx = -1;
    for(int i = 0; i < n; i++) {
        if(a[i] == b[i]) {
            idx = i;
            cnt++;
        }
    }
    if(cnt >= 2 || (cnt == 1 && n % 2 == 0)) {
        cout << -1 << nl;
        return;
    }
    vector<pi> op;

    if(cnt == 1 && idx != n / 2) {
        // that one has to be in the middle of the array
        op.push_back(make_pair(idx, n / 2));
        doSwap(a,b,idx,n/2);
    }

    for(int i = 0; i < n; i++) {
        if(a[i] != b[n - i - 1]) {
            //cerr << a[i] << " " << valB[a[i]] << nl;
            if(valB[a[i]] <= i) {
                cout << -1 << nl;
                return;
            }
            op.push_back(make_pair(n - i - 1, valB[a[i]]));
            doSwap(a,b,n-i-1,valB[a[i]]);
        }
    }

    if(!isRev(a,b)) {
        cout << -1 << nl;
        return;
    }
    assert((int)op.size() <= n);
    cout << op.size() << nl;
    for(auto &x : op) {
        cout << x.first + 1 << " " << x.second + 1 << nl;
    }
    cout << nl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin>>t;
    while(t--)solve();

    return 0;
}

