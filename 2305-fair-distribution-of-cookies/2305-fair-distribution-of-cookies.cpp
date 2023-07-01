class Solution {
public:
    
bool isPossible(int limit,vector<int>&cookies,int t_stu){
   
    
    do{
       int pages=0;
       int c_stu=1;
  for(int i=0;i<cookies.size();i++){
    if(cookies[i]>limit){
      return false;
    }
    else if(pages+cookies[i]>limit){
      c_stu++;
      pages=cookies[i];
    }
    else{
      pages+=cookies[i];
    }
  }
  if(c_stu<=t_stu)
  return true;
        
    }while(next_permutation(cookies.begin(),cookies.end()));
return false;
     
}
    int distributeCookies(vector<int>& cookies, int k) {
        sort(cookies.begin(),cookies.end());
        int low=*max_element(cookies.begin(),cookies.end());
        int high=0;
        for(int i=0;i<cookies.size();i++){
            high+=cookies[i];
        }
        int n=cookies.size();
        vector<int>visited(n,0);
        int ans=-1;
        while(low<=high){
            int mid=(low+high)/2;
            
            if(isPossible(mid,cookies,k)){
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