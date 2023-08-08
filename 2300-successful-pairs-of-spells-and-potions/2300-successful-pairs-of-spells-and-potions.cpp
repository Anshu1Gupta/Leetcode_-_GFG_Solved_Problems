class Solution {
public:

    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        
        vector<int>ans;
        for(int i=0;i<spells.size();i++){
        int low=0;
        int high=potions.size()-1;
        
        int an=-1;
        while(low<=high){
            int mid=(low+high)/2;
            long long value = (long)potions[mid]*spells[i] ; 
            if(value>=success){
                an=mid;
              high=mid-1;
            }
            else{
               low=mid+1;
            }
        }
        if(an==-1)ans.push_back(0);
        else ans.push_back(potions.size()-an);
        }
        return ans;
    }
};
 