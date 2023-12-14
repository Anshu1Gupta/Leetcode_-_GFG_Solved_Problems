class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> ans(n, vector<int>(m, 0));
        vector<pair<int, int>> dpRow(n, pair<int, int>(0, 0));
        vector<pair<int, int>> dpCol(m, pair<int, int>(0, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0)
                    dpRow[i].first++;
                else
                    dpRow[i].second++;
            }
        }

        for (int j = 0; j < m; j++) {
            for (int i = 0; i < n; i++) {
                if (grid[i][j] == 0)
                    dpCol[j].first++;
                else
                    dpCol[j].second++;
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans[i][j] = dpRow[i].second + dpCol[j].second - (dpRow[i].first + dpCol[j].first);
            }
        }

        return ans;
    }
};
