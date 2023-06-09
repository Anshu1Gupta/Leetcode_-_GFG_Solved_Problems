class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int mini=INT_MAX;
        char ans=letters[0];
        for(int i=0;i<letters.size();i++){
          if(letters[i]>target&&(abs(letters[i]-target)<mini)){
              mini=abs(letters[i]-target);
              ans=letters[i];
          }
        }
        return ans;
    }
};