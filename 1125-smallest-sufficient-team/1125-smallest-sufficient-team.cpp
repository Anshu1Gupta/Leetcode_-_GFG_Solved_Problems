class Solution {
public:
    vector<int>result;
    unordered_map<string,int>dp;
    void findPart(int ind,vector<int>&temp,vector<int>&arr,int mask,int req_mask){
        if(ind>=arr.size()){
            if(mask==req_mask){
                if(result.size()==0||result.size()>temp.size())result=temp;
            }
           return;
        }
        if(result.size()!=0&&temp.size()>result.size())return;
        
        string rem=to_string(ind)+':'+to_string(mask);
        
        if(dp.find(rem)!=dp.end()){
            if(dp[rem]<=temp.size())return;
        }
        
        
        if((mask|arr[ind])!=mask){
            temp.push_back(ind);
            findPart(ind+1,temp,arr,mask|arr[ind],req_mask);
            temp.pop_back();
            
            
            dp[rem]=temp.size()!=0?temp.size():-1;
        }
        
        findPart(ind+1,temp,arr,mask,req_mask);
        
    }
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        unordered_map<string,int>mp;
        
        for(int i=0;i<req_skills.size();i++){
            mp[req_skills[i]]=i;
        }
        
        vector<int>arr;
        for(int i=0;i<people.size();i++){
            int dec=0;
            for(int j=0;j<people[i].size();j++){
                int shift=mp[people[i][j]];
                dec=dec|(1<<shift);
            }
            arr.push_back(dec);
        }
        vector<int>temp;
        int n=req_skills.size();
        int req_mask=pow(2,n)-1;
        
        findPart(0,temp,arr,0,req_mask);
        return result;
        
    }
};