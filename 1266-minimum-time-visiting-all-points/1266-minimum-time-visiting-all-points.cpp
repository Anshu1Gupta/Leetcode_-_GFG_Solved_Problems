
class Solution {
public:
    // Function to calculate the minimum time to visit all points
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans = 0; // Variable to store the total time taken
        int n = points.size(); // Get the number of points

        // Iterate through the points starting from the second point
        for (int i = 1; i < n; ++i) {
            // Calculate the absolute differences in x and y coordinates between consecutive points
            int diffx = abs(points[i][0] - points[i - 1][0]);
            int diffy = abs(points[i][1] - points[i - 1][1]);

            // Add the maximum difference between x and y coordinates to the total time
            ans += max(diffx, diffy);
        }
        return ans; // Return the total time taken to visit all points
    }
};


