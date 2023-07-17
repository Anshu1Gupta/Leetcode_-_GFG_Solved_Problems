/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int searchR(MountainArray &arr,int target,int low,int high){
        
        int key=-1;
        while(low<=high){
            int mid=(low+high)/2;
            
            if(arr.get(mid)==target){
                key=mid;
               low=mid+1;
            }
            if(arr.get(mid)>target){
                low=mid+1;
            }
            else high=mid-1;
        }
        return key;
    }
    int searchL(MountainArray &arr,int target,int low,int high){
        
        int key=-1;
        while(low<=high){
            int mid=(low+high)/2;
            
            if(arr.get(mid)==target){
                key=mid;
                high=mid-1;
            }
            if(arr.get(mid)>target){
                high=mid-1;
            }
            else low=mid+1;
        }
        return key;
    }
    int findInMountainArray(int target, MountainArray &arr) {
        int n=arr.length();
        
        int getPeakIndex=-1;
        
        int low=0,high=n-1,maxi=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(maxi<arr.get(mid)){
                maxi=arr.get(mid);
                getPeakIndex=mid;
            }
            
            if(arr.get(mid)<=arr.get(mid+1)){
             low=mid+1;
            }
            else high=mid-1;
        }
        
        int findLeft=searchL(arr,target,0,getPeakIndex);
        int findRight=searchR(arr,target,getPeakIndex+1,n-1);
        
        if(findLeft!=-1)return findLeft;
        if(findRight!=-1)return findRight;
        return -1;
    }
};