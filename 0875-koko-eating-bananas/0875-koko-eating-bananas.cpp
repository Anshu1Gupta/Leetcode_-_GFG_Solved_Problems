class Solution {
public:
    bool canEat(int capacity,vector<int>&piles,int maxHour){
        
        int initialHour=0;
        for(int i=0;i<piles.size();i++){
            int t=ceil(piles[i]/(capacity*1.0));
            initialHour+=t;
            if(initialHour>maxHour)return false;
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high=*max_element(piles.begin(),piles.end());
        
        
        
        int ans=h;
        while(low<=high){
            int mid=(low+high)/2;
            
            
            if(canEat(mid,piles,h)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        
        return ans;
        
    }
};