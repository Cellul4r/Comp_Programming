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

struct p {
    
    string title;
    string word;
    int idx;
    int inside;
    
    p(string title, string word, int idx, int inside) : title(title),
                                                    word(word), idx(idx), inside(inside) {}
    bool operator<(const p& rhs) const {
        if(word != rhs.word) {
            return word < rhs.word;
        }
        if(idx != rhs.idx) {
            return idx < rhs.idx;
        }
        return inside < rhs.inside;
    }
};
unordered_set<string> ig;
string s;

string toUpper(string s) {
    string ans;
    for(auto &x : s) {
        if(x >= 'a' && x <= 'z') {
            x = x - 'a' + 'A';
        }
        ans += x;
    }
    return ans;
}
void solve(){

    while(cin>>s) {
        if(s == "::") break;
        ig.insert(s);
    }

    vector<p> ans;
    int now = 0;
    while(getline(cin,s)) {
        string cur;
        for(auto &x : s) {
            if(x >= 'A' && x <= 'Z') x = x - 'A' + 'a';
        }
        //cout << s << nl; 
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == ' ') continue;
            cur = "";
            int j = i;
            while(j < s.size() && s[j] != ' ') {
                cur += s[j++];
            }
            if(ig.find(cur) == ig.end()) {
                cur = toUpper(cur);
                string tmp = s;
                for(int k = i; k < j; k++) {
                    tmp[k] = cur[k-i];
                }
                //cerr << tmp << nl;
                ans.push_back(p(tmp, cur, now, i));
            }
            i = j; 
        }
        now++;
    }
    sort(all(ans));
    for(auto &x : ans) {
        cout << x.title << nl;
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

