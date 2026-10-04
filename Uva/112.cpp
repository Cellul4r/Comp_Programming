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

    node() {}
    node(int val) : val(val), left(NULL), right(NULL) {}
};
int sum;
string cur;
node* transform(int idx) {
    
    if(cur[idx] != '(') return NULL;

    if(cur[idx] == '(' && cur[idx+1] == ')') return NULL;
    node* root = NULL;
    int val = 0;
    bool neg = false;
    for(int i = idx + 1; i < cur.size(); i++) {
        if(cur[i] == '-') {
            neg = true;
            continue;
        }
        if(cur[i] < '0' || cur[i] > '9') break;
        val = val * 10 + (cur[i] - '0');
    }
    if(neg) val *= -1;
    root = new node(val);
    // find left tree
    // find next '(' 
    for(int i = idx+1; i < cur.size(); i++) {
        if(cur[i] == '(') {
            root->left = transform(i);
            idx = i;
            break;
        }
    }
    int op = 0, cl = 0;
    //cout << idx << " ";
    for(int i = idx; i < cur.size(); i++) {
        if(cur[i] == '(') op++;
        else if(cur[i] == ')') cl++;
        if(op == cl) {
            idx = i + 1;
            break;
        }
    }
    //cout << idx << nl;
    // find right tree
    root->right = transform(idx);
    return root;
}
void inorder(node* root) {
    if(root == NULL) return;
    cout << root->val << " ";
    inorder(root->left);
    inorder(root->right);
}
bool path(node* root, int cur) {
    if(root == NULL) return false;
    int now = cur + root->val;
    if(root->left == NULL && root->right == NULL) {
        return now == sum;
    }
    if(path(root->left,now) || path(root->right,now)) return true;
    return false;
}
void solve(){
    
    while(cin>>sum) {
        cin.ignore();
        cur = "";
        string s;
        int op = 0, cl = 0;
        while(getline(cin, s)) {
            for(auto &x : s) {
                if(x == ' ') continue;
                if(x == '(') op++;
                else if(x == ')') cl++;
                cur += x;
            }
            if(op == cl) break;
        }
        //cout << sum << " " << cur << nl;
        node* root = transform(0);
        //inorder(root);
        if(root == NULL) {
            cout << "no" << nl;
            continue;
        }
        if(path(root, 0)) {
            cout << "yes";
        } else {
            cout << "no";
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

