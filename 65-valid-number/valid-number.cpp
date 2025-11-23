class Solution {
public:
    bool isNumber(string s) {
        int n = s.size();
        int i = 0;

        // Trim leading/trailing spaces
        while (i < n && s[i] == ' ') i++;
        while (n > i && s[n - 1] == ' ') n--;

        if (i == n) return false;

        bool seenDigit = false;
        bool seenDot = false;
        bool seenExp = false;
        
        for (int j = i; j < n; j++) {
            char c = s[j];

            if (isdigit(c)) {
                seenDigit = true;
            }
            else if (c == '+' || c == '-') {
                // Sign only allowed at start or right after e/E
                if (j > i && !(s[j-1] == 'e' || s[j-1] == 'E')) return false;
            }
            else if (c == '.') {
                // Dot allowed only once and never after exponent
                if (seenDot || seenExp) return false;
                seenDot = true;
            }
            else if (c == 'e' || c == 'E') {
                // Exponent allowed only once and only after a digit
                if (!seenDigit || seenExp) return false;
                seenExp = true;
                seenDigit = false;  // must see digits after exponent
            }
            else {
                return false;
            }
        }

        return seenDigit;
    
    }
};