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
void test(int n) {
    string s;
    int tmp = n;
    while(true) {
        s += to_string(n);
        int nn = 0;
        while(n > 0) {
            nn += (n % 10);
            n /= 10;
        }
        n = nn;
        if(n <= 9) break;
    }
    cout << tmp << " " << s << nl;
    if(s == "75321") {
        cout << "WOW!: " << tmp << nl;
    }
}
void solve(){
    
    string s; cin>>s;
    // 10 -> 1
    // 11 -> 2
    // 12 -> 3
    // 13 -> 4
    // 14 -> 5
    // 18 -> 9
    // 19 -> 10 -> 1
    // 20 -> 2
    // 21 -> 3
    /*
    for(int x = 10; x <= 10000; x++) {
        test(x);
    }
    */
    int sum = 0;
    int n = s.length();
    if(n == 1) {
        cout << s << nl;
        return;
    }
    vector<int> freq(10, 0);
    for(int i = 0; i < n; i++) {
        sum += s[i] - '0';
        freq[s[i]-'0']++;
    }
    for(int i = sum - 100; i <= sum; i++) {
        int cur = i;
        vector<int> now{cur};
        while(cur > 9) {
            int nn = 0;
            while(cur > 0) {
                nn += cur % 10;
                cur /= 10;
            }
            cur = nn;
            now.push_back(cur);
        }
        ll check = 0;
        for(auto &x : now) {
            check += x;
        }
        check += now.back();
        if(check == sum) {
            vector<int> cnt(10, 0);
            for(auto &x : now) {
                string k = to_string(x);
                for(auto &y : k) {
                    cnt[y-'0']++;
                }
            }
            bool flag = true;
            for(int i = 0; i < 10; i++) {
                if(cnt[i] > freq[i]) {
                    flag = false;
                    break;
                }
            }

            if(flag) {
                vector<int> rem = freq;
                for(int i = 0; i < 10; i++) {
                    rem[i] -= cnt[i];
                }

                string y0 = "";
                for(int i = 1; i < 10; i++) {
                    if(rem[i] > 0) {
                        y0 += to_string(i);
                        rem[i]--;
                        break;
                    }
                }

                for(int i = 0; i < 10; i++) {
                    while(rem[i] > 0) {
                        y0 += to_string(i);
                        rem[i]--;
                    }
                }

                string ans = y0;
                for(auto &x : now) {
                    ans += to_string(x);
                }
                cout << ans << nl;
                return;
            }
        }
    }
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

