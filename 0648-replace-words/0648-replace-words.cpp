class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_set<string> st(dictionary.begin(), dictionary.end());

        string ans = "";
        int i = 0;
        while (i < sentence.length()) {
            string word = "";
            bool skip = false;
            while (i < sentence.length() && sentence[i] != ' ') {
                if (skip) {
                    i++;
                    continue;
                } 
                word += sentence[i++];
                if (st.find(word) != st.end()) {
                    skip = true;
                }
            }
            ans += word;
            if (i < sentence.length() && sentence[i] == ' ') {
                ans += " ";
            }
            i++;
        }
        return ans;
    }
};