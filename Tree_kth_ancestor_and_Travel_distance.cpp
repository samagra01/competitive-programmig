
int const N = 2e5 + 5;
 
int par[N][20];
int level[N];
 
void dfs(int node, int parent, vector<int> adj[], int l = 0){
    level[node] = l;
    par[node][0] = parent;
    for(int i = 1; i < 20; i++){
        par[node][i] = par[par[node][i-1]][i-1];
    }
 
    for(auto adjNode : adj[node]){
        if(adjNode == parent) continue;
        dfs(adjNode, node, adj, l+1);
    }
}
 
int find_par(int x, int k){
    int cnt = 0;
    while(k){
        if(k&1){
            x = par[x][cnt];
        }
        cnt++;
        k = k >> 1;
    }
    return x;
}
//  distance for traveling certain nodes from node and comming back to root node 
//  ans will be twice of it 
int getans(vector<int> adj[], set<int> &st){
    set<int> temp;
    temp.insert(1);
    for(auto it : st){
        int node = it;
        while(temp.find(node) == temp.end()){
            temp.insert(node);
            node = par[node][0];
        }
    }
    return temp.size() - 1;
}


// https://codeforces.com/contest/1774/problem/E
// application question //
 
