struct UnionFind {
    int n, set_size, *parent, *rank;
    UnionFind() {}
    UnionFind(int a) {
        n = set_size = a;
        parent = new int[n + 1];
        rank = new int[n + 1];
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            rank[i] = 1;
        }
    }
    int find(int x) {
        if (x != parent[x])
            return parent[x] = find(parent[x]);
        return x;
    }
    void merge(int x, int y) {
        int xroot = find(x) , yroot = find(y) ;
        if (xroot != yroot) {
            if (rank[xroot] >= rank[yroot]) {
                parent[yroot] = xroot;
                rank[xroot] += rank[yroot];
            } else {
                parent[xroot] = yroot;
                rank[yroot] += rank[xroot];
            }
            set_size -= 1;
        }
    }
    void reset() {
        set_size = n;
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 1;
        }
    }
    int size() {
        return set_size;
    }
    int s(ll a) {
        return rank[a];
    }
    int print() {
        for (int i = 1; i <= n; i++) {
            cout << parent[i] << " ";
        } cout << endl;
    }

};
// my own written dsu //  
struct UnionFind {

    int par[100010];
    int rank[100010];
    void init() {
        for (int i = 1; i <= 100000; i++) {
            par[i] = i;
            rank[i] = 1;
        }
    }

    int find(int x) {
        if(par[x]==x)return x;
        else return par[x] = find(par[x]);
    }

    int unite(int x, int y) {
        int rootx = find(x);
        int rooty = find(y);
        if(rank[rootx]<rank[rooty])swap(x,y);
        if(rank[rootx]==rank[rooty])rank[rootx]++;
        par[rooty]  =  rootx;
    }

};
// this is sweet and simple so hmmm... 
