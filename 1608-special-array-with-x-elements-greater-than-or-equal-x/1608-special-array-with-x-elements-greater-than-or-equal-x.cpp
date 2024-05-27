class Solution {
public:
    int specialArray(vector<int>& nums) {
     sort(nums.begin(),nums.end());
        
     for(int i=1;i<=100;i++){
         int num=lower_bound(nums.begin(),nums.end(),i)-nums.begin();
         
         if(num!=-1){
            num= nums.size()-num;
         }
         if(i==num)return i;
     }
        return -1;
        
     
    }
};