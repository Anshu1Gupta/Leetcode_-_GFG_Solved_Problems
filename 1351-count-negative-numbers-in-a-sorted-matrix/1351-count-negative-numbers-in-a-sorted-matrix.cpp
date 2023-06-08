class Solution {
public:
    int findNeg(vector<int>&arr,int n){
        int low=0;
        int high=n-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(mid-1>=0&&arr[mid]<0&&arr[mid-1]>=0||mid==0&&arr[mid]<0){
                return n-mid;
            }
            else if(mid-1>=0&&arr[mid-1]<0&&arr[mid]<0){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
            
        }
        return 0;
    }
    int countNegatives(vector<vector<int>>& grid) {
        int sum=0;
       
        for(auto vect:grid){
            sum+=findNeg(vect,vect.size());
        }
        return sum;
    }
};