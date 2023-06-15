class Solution {
public:
    
 // #include <bits/stdc++.h>

vector<int> majorityElement(vector<int>& arr) 
{
     int n=arr.size();

   int ele1=INT_MIN,ele2=INT_MIN;
   int count1=0,count2=0;
   for(int i=0;i<arr.size();i++){
       if(count1==0&&ele2!=arr[i]){
           count1=1;
           ele1=arr[i];
       }
       else if(count2==0&&ele1!=arr[i]){
           count2=1;
           ele2=arr[i];
       }
       else if(arr[i]==ele1)count1++;
       else if(arr[i]==ele2)count2++;
       else{
           count1--,count2--;
       }
   }
 count1=0,count2=0;
 vector<int>res;
 for(int i=0;i<n;i++){
     if(arr[i]==ele1)count1++;
     if(arr[i]==ele2)count2++;
 }
 if(count1>=n/3+1)res.push_back(ele1);
 if(count2>=(n/3+1))res.push_back(ele2);
 return res;
}
    };