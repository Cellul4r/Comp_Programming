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
bool isVow(char& c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}
void solve(){
    
    string s;
    while(true) {
        cin>>s;
        if(s == "end") break;
        bool ok = true, vowel = false;
        int n = s.length();
        for(int i = 0; i < n; i++) {
            if(isVow(s[i])) vowel = true;
        }
        for(int i = 0; i <= n - 3; i++) {
            if(isVow(s[i]) && isVow(s[i+1]) && isVow(s[i+2])) {
                ok = false;
            } else if((isVow(s[i]) || isVow(s[i+1]) || isVow(s[i+2])) == false) {
                ok =false;
            } else if((isVow(s[i]) || isVow(s[i+1]) || isVow(s[i+2]))) {
                vowel = true;
            }
        }
        for(int i = 0; i <= n - 2; i++) {
            if(s[i] == s[i+1] && s[i] != 'e' && s[i] != 'o') {
                ok = false;
            }
        }
        if(!vowel) ok = false;
        cout << "<" << s << "> is ";
        if(!ok) cout << "not ";
        cout << "acceptable.\n";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;

    //setIO("");
    //cin>>t;
    while(t--)solve();

    return 0;
}

void setIO(string s) {
    (void)!freopen((s + ".in").c_str(), "r", stdin);
    (void)!freopen((s + ".out").c_str(), "w", stdout);
}

