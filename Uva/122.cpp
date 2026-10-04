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
struct node {
    int val;
    node* left;
    node* right;

    node() : val(0), left(NULL), right(NULL) {}
    node(int val) : val(val), left(NULL), right(NULL) {}
};
string cur,s;
void solve(){
    
    while(true) {
        cur = "";
        while(getline(cin,s)) {
            cur += s;
            if(s.substr(s.length()-2,2) == "()") break;
        }
        if(cur.empty()) break;
        vector<pair<int,string>> a;
        int now = 0;
        string check;
        for(int i = 0; i < cur.size(); i++) {
            if(cur[i] == '(' && cur[i+1] == ')') break;
            if(cur[i] == ' ') continue;
            assert(cur[i] == '(');
            int j = i + 1;
            while(cur[j] != ',') {
                now = now * 10 + (cur[j++] - '0');
            }
            j++;
            while(cur[j] != ')') {
                check += cur[j++];
            }
            //cout << now << " " << check << nl;
            a.push_back(make_pair(now,check));
            now = 0;
            check = "";
            i = j;
        }

        sort(all(a), [](pair<int,string>& a, pair<int,string>& b) {
                    return a.second.size() < b.second.size();
                });
        bool complete = true;
        node* root = NULL;
        for(auto &x : a) {
            node* tmp = root;
            node* prev = NULL;
            string& y = x.second;
            int i = 0;
            while(i < y.length() && tmp != NULL) {
                prev = tmp;
                if(y[i] == 'L') {
                    tmp = tmp->left;
                } else {
                    tmp = tmp->right;
                }
                i++; 
            }
            if(i == y.length() && tmp == NULL) {
                if(y.empty() && root == NULL) {
                    root = new node(x.first);
                } else if(y[i-1] == 'L'){
                    prev->left = new node(x.first);
                } else {
                    prev->right = new node(x.first);
                }
            } else {
                complete = false;
            }
        }
        if(complete) {
            vector<int> ans;
            queue<node> Q;
            Q.push(*root);
            while(!Q.empty()) {
                node u = Q.front();
                Q.pop();
                ans.push_back(u.val);
                if(u.left != NULL) Q.push(*(u.left));
                if(u.right != NULL) Q.push(*(u.right));
            }
            cout << ans[0];
            for(int i = 1; i < ans.size(); i++) cout << " " << ans[i];
        } else {
            cout << "not complete";
        }
        cout << nl;

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

