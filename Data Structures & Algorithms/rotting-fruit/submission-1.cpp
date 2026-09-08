class Solution {
public:
    const int ROTTEN = 2;
    const int FRESH = 1;

    const vector<pair<int, int>> DIRS = {{1,0}, {0,1}, {0,-1}, {-1,0}};
    bool isInvalid(int x, int n) {
        return x < 0 || x == n;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        const int n = grid.size(), m = grid[0].size();
        queue<pair<int,int>> q;
        int freshFruits = 0;

        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (grid[i][j] == FRESH) freshFruits++;
                else if (grid[i][j] == ROTTEN) {
                    q.push({i, j});
                }
            }
        }

        int time = 0;
        while(!q.empty()) {
            int size = q.size();
            if (freshFruits == 0) break;

            for(int i=0; i<size; i++) {
                int ux = q.front().first, uy = q.front().second;
                q.pop();
                for (auto [x, y]: DIRS) {
                    int vx = ux + x, vy = uy + y;
                    if (isInvalid(vx, n) || isInvalid(vy, m)) continue;

                    if (grid[vx][vy] == FRESH) {
                        grid[vx][vy] = ROTTEN;
                        q.push({ vx, vy });
                        freshFruits--;
                    }
                }
            }
            time++;
        }

        return (freshFruits == 0) ? time: -1; 
    }
};
