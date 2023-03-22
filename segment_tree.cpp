#include <bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

#define MAXN 100100
int n, m;
int arr[MAXN];
int aar[MAXN];
// asuming every number given in the input is positive
struct node
{
	int nin;
	int cnt;
	node(int a = INT_MAX, int b = 0) {
		nin = a;
		cnt = b;
	}
};

node merge(node &a, node &b) {
	if (a.nin == b.nin) {
		// cout << "*" << endl;
		return node(a.nin, a.cnt + b.cnt);
	} else if (a.nin < b.nin) {
		// cout << "@" << endl;
		return node(a.nin, a.cnt);
	} else {
		// cout << "#" << endl;
		return node(b.nin, b.cnt);
	}
}


node t[4 * MAXN];


void build(int id, int l, int r) {
	// cout << id << " " << l << " " << r << endl;
	if (l == r) {
		t[id] = node(arr[l], 1);
		return;
	}
	int mid = (l + r) >> 1;
	build(id << 1, l, mid);
	build(id << 1 | 1, mid + 1, r);
	t[id] = merge(t[id << 1], t[id << 1 | 1]);
}

void update(int id, int l, int r, int pos, int val) {
	// cout << id << " " << l << " " << r << endl;
	if (pos > r || l > pos) return;
	if (l == r) {
		t[id] = node(val, 1);
		// cout << t[id].nin << " " << t[id].cnt << endl;
		arr[l] = val;
		return;
	}
	int mid = (l + r) >> 1;
	update(id << 1, l, mid, pos, val);
	update(id << 1 | 1, mid + 1, r, pos, val);
	t[id] = merge(t[id << 1], t[id << 1 | 1]);

}

node query(int id, int l, int r, int lq, int rq) {
	// cout << id << " " << l << " " << r << endl;
	if (lq > r || l > rq) return node();
	if (lq <= l && r <= rq) {
		return t[id];
	}
	int mid = (l + r) / 2;
	// return merge(query(id << 1, l, mid, lq, rq), query(id << 1 | 1, mid + 1, r, lq, rq)); //  cant write if passing in merge with &
	node ll = query(id << 1, l, mid, lq, rq);
	node rr = query(id << 1 | 1, mid + 1, r, lq, rq);
	return merge(ll, rr);
}


void solve() {
    ll n,m; cin >> n >> m;
    fo(i,0,(1<<n)-1){
    	cin >> arr[i];
    }
    
}

signed main() {
	fastio();
	int T = 1;
	// cin >> T;
	for (int i = 1; i <= T; i++) {
		solve();
	}
}
