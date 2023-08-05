class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int>arr;
        int perm=1;
        string str="";
        for(int i=1;i<n;i++){
            arr.push_back(i);
            perm=perm*i;
        }
        arr.push_back(n);
        k--;
        
        while(true){ 
        str+=to_string(arr[k/perm]);
        arr.erase(arr.begin()+k/perm);
        if(arr.size()==0)break;
        k=k%perm;
        perm=perm/(arr.size());
            
         }
        
        return str;
    }
};