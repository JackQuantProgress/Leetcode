class Solution {
public:
    bool isValid(string s) {
        vector<char> st;

        unordered_map<char, char> bracket_map;

        bracket_map['('] = ')';
        bracket_map['{'] = '}';
        bracket_map['['] = ']';

        for (char x : s) {
            if ((x == '(') || (x == '{') || (x == '[')) {
                st.push_back(x);
            }
            else {
                if (st.empty()) {
                    return false;
                }
                if (bracket_map[st.back()] != x) {
                    return false;
                }
                st.pop_back();
            }
        }
        if (st.empty()) {
            return true;
        }
        return false;
    }
};
