class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int,int>>vect;
        
        for(auto num:arr){
            int count=0;
            for(int i=0;i<32;i++){
                if((1<<i)&num)count++;
            }
            vect.push_back({count,num});
        }
        
        sort(vect.begin(),vect.end());
        
        vector<int>ans;
        for(int i=0;i<vect.size();i++){
            ans.push_back(vect[i].second);
        }
        return ans;
    }
};