class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int start=0;
        int n=gas.size();
        int petrol=0;
        int deficit=0;
        for(int i=0;i<n;i++){
            gas[i]=gas[i]-cost[i];
            
            petrol+=gas[i];
            deficit+=gas[i];
            if(petrol<0){
                petrol=0;
                start=i+1;
            }
            
            
        }
        if(deficit<0)return -1;
        return start;
    }
};