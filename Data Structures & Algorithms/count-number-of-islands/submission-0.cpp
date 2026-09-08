class Solution {
public:
    vector<vector<int>> dirs = {{1,0}, {0,1}, {-1,0}, {0,-1}};
    bool isInvalid(int x, int n) {
        return x < 0 || x >= n;
    }

    void dfs(vector<vector<char>> &grid, int sx, int sy, int n, int m) {
        grid[sx][sy] = '0';
        for (vector<int> &dir: dirs) {
            int vx = sx + dir[0];
            int vy = sy + dir[1];
            if (isInvalid(vx, n) || isInvalid(vy, m)) continue;

            if (grid[vx][vy] == '1') {
                dfs(grid, vx, vy, n, m);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int ans = 0;

        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (grid[i][j] == '1') {
                    // cout<<i<<" "<<j<<endl;
                    dfs(grid, i, j, n, m);
                    ans++;
                }
            }
        }

        return ans;
    }
};
