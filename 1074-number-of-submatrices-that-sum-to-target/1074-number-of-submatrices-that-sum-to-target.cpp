class Solution {
public:
int findSubMat(vector<int>&arr,int target){
   unordered_map<int,int>mp;
   mp[0]=1;
   int sum=0;
   int count=0;
   for(int i=0;i<arr.size();i++){
      sum+=arr[i];
      count+=mp[sum-target];
      mp[sum]++;
   }
   return count;
}

int numSubmatrixSumTarget(vector<vector<int>>& A, int target) {
        
   int n=A.size();
   int m=A[0].size();
   int count=0;
   vector<int>rect(m);
   for(int i=0;i<A.size();i++)                    //Convert 2D array to 1D by row.
        {
            fill(rect.begin(),rect.end(),0);                  //Clear vector to start the rect with i as starting rect.
            for(int j=i;j<A.size();j++)
            {
                for(int x=0;x<A[0].size();x++)         //Add next rect
                    rect[x]+=A[j][x];
                count+=findSubMat(rect,target);
            }
        }
   return count;
}












};