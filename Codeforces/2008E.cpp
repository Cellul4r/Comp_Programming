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
    string s;
    cin>>n>>s;

    // operation 1 delete a character
    // operation 2 replace character to the new one
    // suppose n is even
    // then we do only operation 2 
    vector<int> even(26), odd(26); 
    for(int i = 0; i < n; i++) {
        if(i & 1) {
            odd[s[i]-'a']++;
        } else {
            even[s[i]-'a']++;
        }
    }

    if(n % 2 == 0) {
        int mxEven = 0, mxOdd = 0;
        for(int i = 0; i < 26; i++) {
            mxEven = max(mxEven, even[i]);
            mxOdd = max(mxOdd, odd[i]);
        }
        cout << n - mxEven - mxOdd << nl;
        return;
    }
    // length odd we must delete some character to make it even
    // ejibmyyju
    // eibmyyju
    // eji myyju
    int ans = INF;
    for(int i = 0; i < n; i++) {
        int x = s[i] - 'a';
        if(i & 1) {
            odd[x]--;
        } else {
            even[x]--;        
        }
        int mxEven = *max_element(all(even));
        int mxOdd = *max_element(all(odd));

        ans = min(ans, n - mxEven - mxOdd);
        if(i & 1) {
            even[x]++;
        } else {
            odd[x]++;
        }
    }

    cout << ans << nl;
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

