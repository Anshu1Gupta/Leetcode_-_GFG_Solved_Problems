class Solution {
public:
    // time/space: O(n * k + m)/O(1)
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char, int> freq;
        for (auto& c : chars) freq[c]++;

        int count = 0;
        for (auto& word : words) {
            if (check(word, freq)) count += word.size();
        }
        return count;
    }
private:
    // time/space: O(k)/O(1)
    bool check(string& word, unordered_map<char, int>& freq) {
        unordered_map<char, int> request;
        for (auto& c : word) request[c]++;
        for (auto& [key, value] : request) {
            if (value > freq[key]) return false;
        }
        return true;
    }
};