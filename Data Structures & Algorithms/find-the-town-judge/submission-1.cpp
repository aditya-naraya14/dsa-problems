class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> inD(n+1, 0);
        vector<int> outD(n+1, 0);
        for (vector<int> &tr: trust) {
            int u = tr[0], v = tr[1];
            outD[u]++;
            inD[v]++;
        }

        for (int i=1; i<=n; i++) {
            if (inD[i] == n-1 and outD[i] == 0) return i;
        }

        return -1;
    }
};