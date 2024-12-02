class Solution {
public:
   int isPrefixOfWord(string sentence, string searchWord) {
        stringstream ss(sentence);
        string word;
        int index = 1; // 1-indexed position

        while (ss >> word) {
            if (word.find(searchWord) == 0) { // Check if searchWord is a prefix
                return index;
            }
            index++;
        }
        return -1; // No match found
    }
};