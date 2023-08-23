class Solution {
public:
    bool isPossible(int key,vector<int>&citations){
        int count=0;
        for(int i=0;i<citations.size();i++){
            if(citations[i]>=key)count++;
        }
        if(count>=key)return true;
        return false;
    }
    int hIndex(vector<int>& citations) {
        int n=citations.size();
        int low=1;
        int high=n;
        
        while(low<=high){
            int mid=(low+high)/2;
            if(isPossible(mid,citations)){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return high;
    }
};