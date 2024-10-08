#include <bits/stdc++.h>

using namespace std;
#define int long long
#define MAXN 200005

/***************************************C-H-A-O-S**************************************/

struct node {
    int sum, pref, suff, ans;
};

int n;
node t[4*MAXN];

node combine(node l, node r) {
    node res;
    res.sum = l.sum + r.sum;
    res.pref = max(l.pref, l.sum + r.pref);
    res.suff = max(r.suff, r.sum + l.suff);
    res.ans = max(max(l.ans, r.ans), l.suff + r.pref);
    return res;
}

node make_node(int val = 0) {
    node res;
    res.sum = val;
    int k = 0;
    res.pref = res.suff = res.ans = max(k, val);
    return res;
}

void build(int a[], int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = make_node(a[tl]);
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = combine(t[v*2], t[v*2+1]);
    }
}

void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        t[v] = make_node(new_val);
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        t[v] = combine(t[v*2], t[v*2+1]);
    }
}

node query(int v, int tl, int tr, int l, int r) {
    if (l > r) 
        return make_node();
    if (l == tl && r == tr) 
        return t[v];
    int tm = (tl + tr) / 2;
    return combine(query(v*2, tl, tm, l, min(r, tm)), 
                   query(v*2+1, tm+1, tr, max(l, tm+1), r));
}

void solve() {

  int q;
  cin>>n>>q;
  
  int arr[n];

  for(int i=0; i<n; i++) cin>>arr[i];

  build(arr, 1, 0, n-1);

  while(q--){
    int a, b, c;

    cin>>b>>c;

    update(1, 0, n-1, b-1, c);

    cout<<query(1, 0, n-1, 0, n-1).ans<<endl;
    
  }

}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}