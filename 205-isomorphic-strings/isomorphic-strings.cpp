class Solution {
public:
    bool isIsomorphic(string s, string t) {
       if (s.size() != t.size()) return false;
        int m1[256] = {0}, m2[256] = {0};
        for (int i = 0; i < (int)s.size(); ++i) {
            unsigned char a = s[i], b = t[i];
            if (m1[a] != m2[b]) return false;
            m1[a] = m2[b] = i + 1;
        }
        return true; 
    }
};