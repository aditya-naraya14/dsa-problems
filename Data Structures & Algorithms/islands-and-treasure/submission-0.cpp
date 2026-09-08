class Solution {
public:
    int LAND = 2147483647;
    int TREASURE = 0;
    vector<vector<int>> dirs = {{1,0}, {0,1}, {-1,0}, {0,-1}};

    bool isInvalid(int x, int n) {
        return x < 0 || x >= n;
    }

    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        queue<vector<int>> q;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (grid[i][j] == TREASURE) {
                    q.push({i, j});
                }
            }
        }

        int dist = 1;
        while(!q.empty()) {
            int size = q.size();

            for (int i=0; i<size; i++) {
                int ux = q.front()[0], uy = q.front()[1];
                q.pop();

                for (vector<int> &dir: dirs) {
                    int vx = ux + dir[0], vy = uy + dir[1];
                    if (isInvalid(vx, n) || isInvalid(vy, m)) continue;

                    if (grid[vx][vy] == LAND) {
                        grid[vx][vy] = dist;
                        q.push({vx, vy});
                    }
                }
            }
            dist++;
        }
    }
};
