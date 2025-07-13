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
int v[] = {1,1,1,0,0,1,0,0,1,0};

string getReverse(int n) {
    
    string ans;
    if(n == 0) {
        return "00";
    }
    while(n > 0) {
        int k = n % 10;
        if(k == 2) {
            k = 5;
        } else if(k == 5) {
            k = 2;
        }
        ans += (k + '0');
        n /= 10;
    }
    if(ans.size() == 1) {
        ans += "0";
    }
    //reverse(all(ans));
    return ans;
}
string format(int n) {
    string res = to_string(n);
    if(n < 10) {
        res = "0" + res;
    }
    return res;
}
void solve(){
    
    int h,m;
    string s;
    cin>>h>>m>>s;

    // if we change hour, then minute should be 00
    vector<int> hour(h), mn(m);
    for(int i = 0; i < h; i++) {
        int x = i % 10, y = i / 10;
        if(v[x] && v[y]) {
            hour[i] = 1;
        }
    }
    for(int i = 0; i < m; i++) {
        int x = i % 10, y = i / 10;
        if(v[x] && v[y]) {
            mn[i] = 1;
        }
    }

    int hh = (s[0] - '0') * 10 + (s[1] - '0');
    int mm = (s[3] - '0') * 10 + (s[4] - '0');
    int revH = stoi(getReverse(hh)), revM = stoi(getReverse(mm));
    //cerr << revH << " " << revM << " " << hour[revH] << nl;
    string hhh, mmm;
    if(revH < m && revM < h && hour[hh] && mn[mm]) {
    } else if(hour[hh] && revH < m) {
        // must find minute
        // the hour is good to reverse to the moon
        bool found = false;
        for(int i = mm + 1; i < m; i++) {
            if(mn[i] && stoi(getReverse(i)) < h) {
                mm = i;
                found = true;
                break;
            }
        }
        if(!found) {
            for(int i = hh + 1; i != hh; i++) {
                i %= h;
                if(hour[i] && stoi(getReverse(i)) < m) {
                    hh = i;
                    break;
                }
            }
            mm = 0;
        }
    } else {
        for(int i = hh + 1; i != hh; i++) {
            i %= h;
            if(hour[i] && stoi(getReverse(i)) < m) {
                hh = i;
                break;
            }
        }
        mm = 0;
    }
    hhh = format(hh), mmm = format(mm);
    cout << hhh << ":" << mmm << nl;
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

