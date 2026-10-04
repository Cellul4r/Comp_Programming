*
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

struct p {
    
    string name;
    int point = 0;
    int pos = 0;
    int neg = 0;
};

void solve(){
    
    int n; cin>>n;
    vector<p> a(n); 
    map<string,int> save;
    for(int i = 0; i < n; i++) {
        cin>>a[i].name;
        save[a[i].name] = i;
    }

    for(int i = 1; i <= n * (n - 1) / 2; i++) {
        string s,t;
        cin>>s>>t;
        string x,y;
        int k = 0;
        for(; k < (int)s.size() && s[k] != '-'; k++) {
            x += s[k];
        }
        k++;
        for(; k < (int)s.size(); k++) {
            y += s[k];
        }
        int now = 0, now2 = 0, j = 0;
        for(; j < (int)t.size() && t[j] != ':'; j++) {
            now = now * 10 + (t[j] - '0');
        }
        j++;
        for(; j < (int)t.size(); j++) {
            now2 = now2 * 10 + (t[j] - '0');
        }
        a[save[x]].pos += now;
        a[save[x]].neg += now2;
        a[save[y]].pos += now2;
        a[save[y]].neg += now;
        if(now == now2) {
            a[save[x]].point++;
            a[save[y]].point++;
        } else if(now > now2) {
            a[save[x]].point += 3;
        } else {
            a[save[y]].point += 3;
        }
        //cout << now << " " << now2 << nl;
    }
    sort(all(a), [&](p &x, p &y) {
                if(x.point != y.point) {
                    return x.point > y.point;
                }
                if(x.pos - x.neg != y.pos - y.neg) {
                    return x.pos - x.neg > y.pos - y.neg;
                }
                return x.pos > y.pos;
            });
    vector<string> name;
    for(int i = 0; i < n / 2; i++) {
        name.push_back(a[i].name);
    }
    sort(all(name));
    for(auto &x : name) cout << x << nl;
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

