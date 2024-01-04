class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int>mp;
        
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        int count=0;
        for(auto it:mp){
            int num=it.second;
            
            if(num==1)return -1;
            else{
                count+=num%3==0?num/3:num/3+1;
            }
            cout<<num<<endl;
        }
        return count;
    }
};

// 2 1
// 3 1
// 4 2
// 5 2
// 6 2
// 7 3
// 8 3
// 9 3
// 10 4
// 11 4
// 12 4
// 13 5
// 14 5
// 15 5
// 16 6
// 17 6
// 18 6