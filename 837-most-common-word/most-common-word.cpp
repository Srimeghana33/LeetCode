class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string> ban(banned.begin(), banned.end());
        unordered_map<string, int> freq;

        string word;
        for (char ch : paragraph) {
            if (isalpha(ch)) {
                word.push_back(tolower(ch));
            } else if (!word.empty()) {
                if (!ban.count(word)) freq[word]++;
                word.clear();
            }
        }
        // handle last word if paragraph ends with a letter
        if (!word.empty() && !ban.count(word)) freq[word]++;

        string ans;
        int best = 0;
        for (auto &p : freq) {
            if (p.second > best) {
                best = p.second;
                ans = p.first;
            }
        }
        return ans;
        
    }
};