class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int len=0,i=0,j=0,prev=0,count=0, ans=0;
         int n=nums.size();
        
        while(j<nums.size()){
           if(nums[j]==0&&count==1){
              i=prev+1;
              prev=j;
               count=1;
           }
            else if(nums[j]==0){
              prev=j;count=1;
          }
            ans=max(ans,(j-i+1));
            j++;
            
        }
            
            
            
//             if(nums[j]==0)count++;
//             if(count==2){
//                 while(nums[i]!=0){
//                     i++;
//                 }
//                 i++;
//                 count=1;
//             }
//             ans=max(ans,j-i+1);
//             j++;
//         }
        
        return ans-1;

    }
};
