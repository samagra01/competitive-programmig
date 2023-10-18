

int comp[100000 + 10];

struct Node
{
    vector<int> adj;
    vector<int> revadj;

};

Node g[100000 + 10];

stack<int> st;

int vis[100000 + 10];

void dfs1(int node) {
    vis[node] = 1;
    for (auto it : g[node].adj) {
        if (vis[it] == 1) continue;
        dfs1(it);
    }
    st.push(node);
}


int co = 1;

void dfs2(int node) {
    vis[node] = 1;
    comp[node] = co;
    for (auto it : g[node].revadj) {
        if (vis[it] == 1) continue;
        dfs2(it);
    }
}

ll ans = 0;
void dp_dfs(int node, vector<vector<int>> &gg, vector<long long int> &vv, vector<ll> &dp) {

    // cout << node << " " <<  dp[node] <<  " " << dp[par] << endl;
    if (dp[node] != 0) return;
    dp[node] = vv[node];

    for (auto it : gg[node]) {
        dp_dfs(it, gg, vv, dp);
        dp[node] = max(dp[node], vv[node] + dp[it]);

    }
}
