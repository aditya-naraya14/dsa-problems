class Solution {
public:
    vector<vector<int>> dirs = {{1,0}, {0,1}, {-1,0}, {0,-1}};
    bool isInvalid(int x, int n) {
        return x < 0 || x >= n;
    }

    int dfs(vector<vector<int>> &grid, int sx, int sy) {
        grid[sx][sy] = 0;
        int ans = 0;

        for (vector<int> &dir: dirs) {
            int ux = sx + dir[0], uy = sy + dir[1];
            if (
                isInvalid(ux, grid.size()) ||
                isInvalid(uy, grid[0].size())
            ) continue;

            if (grid[ux][uy] == 1) {
                ans += dfs(grid, ux, uy);
            }
        }

        return 1 + ans;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int ans = 0;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (grid[i][j] == 1) {
                    ans = max(ans, dfs(grid, i, j));
                }
            }
        }

        return ans;
    }
};
