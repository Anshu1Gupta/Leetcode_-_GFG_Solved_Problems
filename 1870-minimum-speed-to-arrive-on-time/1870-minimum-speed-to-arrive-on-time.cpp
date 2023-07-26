class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
      
       long long low=1;
        int ans=-1;
       long long high=1e9;
       int n=dist.size();
        while(low<=high){
            long long mid=(low+high)/2;
            double time=0;
            for(int i=0;i<n;i++){
                
                if(i!=n-1){
                    
                    time+=ceil(dist[i]/(mid*1.0));
                    
                }
                else{
                    time+=(dist[i]/(mid*1.0));
                   
                }
                
               
            }
            if(time>hour){
                low=mid+1;
            }
            else if(time<=hour){
                ans=mid;
                high=mid-1;
            }
        }
        
        return ans;
    }
};