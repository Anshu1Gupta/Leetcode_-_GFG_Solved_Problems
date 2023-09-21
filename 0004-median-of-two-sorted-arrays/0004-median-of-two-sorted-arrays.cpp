class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size()){
           return findMedianSortedArrays( nums2, nums1);
        }
        long long n1=nums1.size();
        long long n2=nums2.size();
        long long low=0;
        long long high=n1;
        
        while(low<=high){
            long long cut1=(low+high)/2;
            long long cut2=(n1+n2+1)/2-cut1;
            
            long long left1=cut1==0?INT_MIN:nums1[cut1-1];
            long long left2=cut2==0?INT_MIN:nums2[cut2-1];
            long long right1=cut1==n1?INT_MAX:nums1[cut1];
            long long right2=cut2==n2?INT_MAX:nums2[cut2];
            
            if(left1<=right2&&left2<=right1){
                if((n1+n2)%2==0){
                    return (max(left1,left2)+min(right1,right2))/2.0;
                }
                return max(left1,left2);
            }
            if(left1>right2){
                high=cut1-1;
            }
            else{
                low=cut1+1;
            }
        }
        return 0.0;
    }
};
