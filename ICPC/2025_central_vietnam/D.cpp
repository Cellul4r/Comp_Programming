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
string s;
string a[] = {"one", "two", "three", "four", "five", "six", "seven", "eight",
                "nine", "ten", "eleven", "twelve", "thirteen", "fourteen",
                "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty"};
unordered_map<string,int> save;
void solve(){

    save["one"] = 1;
    save["two"] = 2;
    save["three"] = 3;
    save["four"] = 4;
    save["five"] = 5;
    save["six"] = 6;
    save["seven"] = 7;
    save["eight"] = 8;
    save["nine"] = 9;
    save["ten"] = 10;
    save["eleven"] = 11;
    save["twelve"] = 12;
    save["thirteen"] = 13;
    save["fourteen"] = 14;
    save["fifteen"] = 15;
    save["sixteen"] = 16;
    save["seventeen"] = 17;
    save["eighteen"] = 18;
    save["nineteen"] = 19;
    save["twenty"] = 20;
    cin>>s;
    
    bool num = false;
    if(s[0] >= '0' && s[0] <= '9') num = true;
    if(num) {
        cout << a[stoi(s)-1];
        return;
    }

    auto f = [&](string a, string b) {
        int n = a.size(), m = b.size();
        int diff = abs(n-m);
        for(int i = 0; i < min(n,m); i++) {
            if(a[i] != b[i]) diff++;
        }
        return diff <= 1;
    };

    for(auto &[x,y] : save) {
        if(f(x,s)) {
            cout << y;
            return;
        }
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

