class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        vector<int> monsters(n, 0);

        for (int i = 0; i < n; i++) {
            int arrival = ceil(static_cast<double>(dist[i]) / speed[i]);

            if (arrival < n) {
                monsters[arrival]++;
            }
        }

        int eliminated = 0;
        for (int i = 0; i < n; i++) {
            if (eliminated + monsters[i] > i) {
                return i;
            }

            eliminated += monsters[i];
        }

        return n;        
    }
};