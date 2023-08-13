class Solution {
public:
    int maxArea(vector<int>& height) {
        int low=0;
        int high=height.size()-1;
        int ans=0;
        while(low<high){
            if(height[low]>height[high]){
                ans=max(ans,(high-low)*height[high]);
                high--;
            }
            else{
                ans=max(ans,(high-low)*height[low]);
                low++;
            }
        }
        return ans;
    }
};