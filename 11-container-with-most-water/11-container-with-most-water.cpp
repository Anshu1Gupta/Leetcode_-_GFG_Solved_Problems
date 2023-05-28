class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0;
        int j=height.size()-1;
        int sum=0;
        while(i<j){
            if(height[i]>height[j]){
                sum=max(sum,(j-i)*(height[j]));
                j--;
            }
            else{
                sum=max(sum,(j-i)*(height[i]));
                i++;
                
            }
        }
        return sum;
    }
};