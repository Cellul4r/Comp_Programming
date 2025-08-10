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
    char val;
    node* left;
    node* right;

    node() : val('$'), left(NULL), right(NULL) {}
    node(int val) : val(val), left(NULL), right(NULL) {}
};

void preorder(node* root) {
    if(root == NULL) return;
    cout << root->val;
    preorder(root->left);
    preorder(root->right);

}
void solve(){
    
    string s;
    vector<string> a;
    bool flag = true;
    while(flag) {
        string s; cin>>s;
        if(s == "$") flag = false;
        if(s == "*" || s == "$") {
            reverse(all(a));
            node* root = new node(a[0][0]);
            for(int i = 1; i < (int)a.size(); i++) {
                for(int j = 0; j < (int)a[i].size(); j++) {
                    node* cur = root;
                    node* prev = NULL;
                    while(cur != NULL) {
                        prev = cur;
                        if(cur->val > a[i][j]) {
                            cur = cur->left;
                        } else {
                            cur = cur->right;
                        }
                    }
                    if(prev->val > a[i][j]) {
                        prev->left = new node(a[i][j]);
                    } else {
                        prev->right = new node(a[i][j]);
                    }
                }
            }
            preorder(root);
            cout << nl;
            a.clear();        
        } else {
            a.push_back(s);
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

