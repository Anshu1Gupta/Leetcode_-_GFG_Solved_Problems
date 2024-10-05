class Solution {
public:
    bool checkInclusion(string s1, string s2) {
      int k=0;
      int n=s2.length();
      int p=s1.length();
      int j=min(p,n);
      vector<int>first(300,0);
      for(int i=0;i<s1.length();i++){
          first[s1[i]]++;
      }
         
      for(int i=0;i<s2.length();i++,j++){
          vector<int>second(300,0);
          int k=i;
          while(k<j){
              if(first[s2[k]]){
                  second[s2[k]]++;

              }
              else{
                  break;
              }
              k++;
          }
        
          if(second==first)return true;
      }


return false;


    }

};