class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        { istringstream in(s); string w; while (in >> w) words.push_back(w); }
        if (pattern.size() != words.size()) return false;

        unordered_map<char,int> pc;
        unordered_map<string,int> wc;

        for (int i = 0; i < (int)pattern.size(); ++i) {
            if (!pc.count(pattern[i])) pc[pattern[i]] = i+1;
            if (!wc.count(words[i]))   wc[words[i]]   = i+1;
            if (pc[pattern[i]] != wc[words[i]]) return false;
        }
        return true;
        
    }
};