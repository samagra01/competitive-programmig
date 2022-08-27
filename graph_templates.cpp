vector<int> graph[N];
vector<char> color(N, 0);
vector<int> parent(N, -1);
int cycle_start = -1, cycle_end;
int cnt = 0;

bool dfs_directed(int v)
{
    color[v] = 1;
    for (int u : graph[v])
    {
        if (color[u] == 0)
        {
            parent[u] = v;
            if (dfs_directed(u))
                return true;
        }
        else if (color[u] == 1)
        {
            cycle_end = v;
            cycle_start = u;
            return true;
        }
    }
    color[v] = 2;
    return false;
}

bool find_cycle_directed(int n)
{
    for (int v = 0; v < n; v++)
    {
        if (dp[v] and color[v] == 0 && dfs_directed(v))
        {
            break;
        }
    }

    if (cycle_start == -1)
    {
        return false;
    }
    else
    {
        return true;
    }
}


vector<bool> visited(N, false);
vector<int> ans;

void dfs(int v) {
    visited[v] = true;
    for (int u : graph[v]) {
        if (!visited[u])
            dfs(u);
    }
    ans.push_back(v);
}

void topological_sort(int n)
{
    ans.clear();
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs(i);
    }
    reverse(ans.begin(), ans.end());
}
