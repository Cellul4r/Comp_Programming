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
const ll LINF = 1e12+10;

void solve(){
    
    int n;
    ll k;
    cin>>n>>k;
    string s;
    cin>>s;
    vector<ll> a(n);
    for(auto &x : a) {
        cin>>x;
    }

    vector<ll> pre(n+1), suff(n+1);

    for(int i = 0; i < n; i++) {
        pre[i+1] = pre[i] + a[i];
        //pre[i+1] = max(pre[i+1], a[i]);
        if(s[i] == '0') {
            pre[i+1] = 0;
        } else {
            if(pre[i+1] > k) {
                cout << "NO" << nl;
                return;
            }
        }
    }

    for(int i = n - 1; i >= 0; i--) {
        suff[i] = suff[i+1] + a[i];
        //suff[i] = max(suff[i], a[i]);
        if(s[i] == '0') {
            suff[i] = 0;
        } else if(suff[i] > k) {
            cout << "NO" << nl;
            return;
        }
    }

    
    int idx = -1;
    for(int i = 0; i < n; i++) {
        if(s[i] == '1') continue;
        idx = i;
        break;
    }
    
    if(idx != -1) {
        ll left = 0, right = 0;
        for(int i = 0; i < idx; i++) {
            if(s[i] == '0') break;
            left = max(left, pre[idx] - pre[i]);
        }
        for(int i = idx + 1; i < n; i++) {
            if(s[i] == '0') break;
            //cerr << suff[idx + 1] - suff[i] << nl;
            right = max(right, suff[idx + 1] - suff[i+1]);
        }

        cerr << left << " " << right << nl;
        a[idx] = k - (left + right);
        for(int i = 0; i < n; i++) {
            if(s[i] == '0' && a[i] == 0) {
                a[i] = -LINF;
            }
        }
    }

    ll maxSum = a[0], now = a[0]; 
    for(int i = 1; i < n; i++) {
        now = max(now + a[i], a[i]);

        maxSum = max(maxSum, now);
    }
    if(maxSum != k) {
        cout << "NO" << nl;
        return;
    }
    cout << "YES" << nl;
    for(auto &x : a) {
        cout << x << " ";
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

