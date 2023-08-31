class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        // int n=ranges.size();
        vector<int>arr(n+1,0);
        
        for(int i=0;i<=n;i++){
            int low=max(0,i-ranges[i]);
            int high=min(n,i+ranges[i]);
            arr[low]=max(arr[low],high);
        }
        
        int current=0;
        int maxEnd=0;
        int taps=0;
        
        for(int i=0;i<=n;i++){
            if(i>maxEnd)return -1;
            
            if(i>current){
                taps++;
                current=maxEnd;
            }
            
            maxEnd=max(maxEnd,arr[i]);
        }
        return taps;
    }
};