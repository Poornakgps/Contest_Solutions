#include <bits/stdc++.h>
using namespace std;
#define ss second
#define ff first
#define pb push_back
#define pf push_front
#define rep(i, a, b, c) for (ll i = a; i < (b); i += c)
#define all(x) begin(x), end(x)
#define pii pair<int, int>
typedef long long ll;
#define fill(v) for(auto& i: v) cin>>i;
#define has(c, x) {return c.find(x)!=c.end();}
#define pr(v) for(auto i: v) cout<<i<<" "; cout<<endl;
#define pr1(v, i) for(auto j: v) cout<<j[i]<<" "; cout<<endl; 
#define del(s, x) if(s.find(x)!=s.end()) s.erase(s.find(x)) 
#define show(x) cout<<#x<<": "<<x<<" ";
#define rev(v) reverse(v.begin(), v.end())
#define endl() cout << endl
#define mod_10 1000000007
#define mod_9 998244353
#define lmt 1000000000000000000
#define __builtin_popcount(x) count_ones(x)
#define Yes() cout << "YES\n"
#define No() cout << "NO\n"
#define  MAXN 200005

/***************************************C-H-A-O-S**************************************/
vector<ll> adj[MAXN];
ll depth[MAXN], parent[MAXN];
ll a, b, mx_depth, n;

void dfs(ll node, ll par = 0){

    depth[node] = depth[par] + 1;
    mx_depth = max(mx_depth, depth[node]);
    parent[node] = par;

    for(auto child: adj[node]){
        if(child==par) continue;
        dfs(child, node);
    }
}

vector<ll> shortest_path(){

    vector<ll> path;
    path.pb(b);
    while(a!=b){
        b = parent[b];
        path.pb(b);
    }
    return path;
}

void solve(){


    cin >> n;

    cin >> a >> b;

    for(int i=1; i<=n; i++){
        adj[i].clear();
    }
    depth[0] = -1;
    for(int i=0; i<n-1; i++){
        ll u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    mx_depth = -1;
    dfs(a);
    if(a==b){
        cout<< 2*(n-1) - mx_depth<<endl;
        return;
    }
    
    vector<ll> path = shortest_path();
    ll sz = path.size();
    reverse(path.begin(), path.end());
    ll x = path[(sz-1)/2];
    mx_depth = -1;
    dfs(x);
    cout<<2*(n-1) - mx_depth + (sz-1-(sz-1)/2)<<endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t=1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}