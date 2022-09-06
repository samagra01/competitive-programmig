// sparse table for maximum in a range
struct sparse_table {
    int n; int m;
    vector<vector<int>> mat;
    vector<int> logtable;
    void init(int _n, int _m) {
        n = _n; m = _m;
        mat.assign(n + 1, vector<int>(m + 1, 0));
        logtable.assign(n + 1, 0);
        for (int i = 2; i <= n; i++) {
            logtable[i] = logtable[i / 2] + 1;
        }
    }
    void build(vector<int> &v) {
        for (int i = 1; i <= n; i++) {
            mat[i][0] = v[i];
        }
        for (int j = 1; j <= m; j++) {
            for (int i = 1; i + (1ll << j) - 1 <= n; i++) {
                mat[i][j] = max(mat[i][j - 1], mat[i + (1ll << (j - 1))][j - 1]);
            }
        }
    }
    int query(int l, int r) {
        // cout << l << " " << r << endl;
        int pw = logtable[r - l + 1];
        // cout << pw << endl;
        int ans = max(mat[l][pw], mat[r - (1ll << pw) + 1][pw]);
        return ans;
    }


};
//https://cp-algorithms.com/data_structures/sparse-table.html
