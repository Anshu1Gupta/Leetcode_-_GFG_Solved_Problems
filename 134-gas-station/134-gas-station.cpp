class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
       int ans=0;
       int tgas=0;
        int currgas=0;
        for(int i=0;i<cost.size();i++){
         currgas+=gas[i]-cost[i];
         tgas+=gas[i]-cost[i];
            if(currgas<0){
                ans=i+1;
                currgas=0;
            }
        }
        return tgas<0?-1:ans;
        
       
    }
};
// -2 -2 -2  3 3 