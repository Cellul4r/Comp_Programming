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
    
    int zero,one;
    string s;
    cin>>zero>>one>>s;
    int n = s.size();

    bool mustOdd = false, ok = true;
    for(int i = 0; i < n / 2; i++) {
        if(s[i] != '?' && s[n-i-1] != '?') {
            if(s[i] != s[n-i-1]) ok = false;
        } else if(s[i] == '?' && s[n-i-1] != '?') {
            s[i] = s[n-i-1];
        } else if(s[n-i-1] == '?' && s[i] != '?') {
            s[n-i-1] = s[i]; 
        }
    }

    for(int i = 0; i < n; i++) {
        if(s[i] == '0') zero--;
        else if(s[i] == '1') one--;
    }

    if(n % 2 == 1 && s[n / 2] == '?') {
        mustOdd = true;
    }

    if(one % 2 == 1 && zero % 2 == 1) {
        ok = false;
    }

    if(one % 2 == 0 && zero % 2 == 0 && mustOdd) {
        ok = false;
    }

    for(int i = 0; i < n / 2; i++) {
        if(s[i] != '?') continue;
        // both mirror i and n - i - 1 is ?
        if(zero >= 2) {
            s[i] = s[n-i-1] = '0';
            zero -= 2;
        } else {
            s[i] = s[n-i-1] = '1';
            one -= 2;
        }
    }
    if(n % 2 == 1 && s[n / 2] == '?') {
        if(one) {
            s[n / 2] = '1';
            one--;
        }
        else {
            s[n / 2] = '0';
            zero--;
        }
    }
    
    if(one || zero) ok = false;
    if(!ok) {
        cout << -1 << nl;
        return;
    }

    cout << s << nl;
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

