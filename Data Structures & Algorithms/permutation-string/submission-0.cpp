class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        //create frequency hash map
        unordered_map<char, int> freq;
        unordered_map<char, int> comp;
        for (char x : s1) {
            freq[x]++;
        }

        for (int i = 0; i < (s2.size() - s1.size()+1); i++) {
            // i + s1.size() = end of window
            for (int x = i; x < (i+s1.size()); x++) {
                //build comp
                comp[s2[x]]++; 
            }
            //compare and reset
            if (freq == comp) {
                return true;
            }
            comp.clear();
        }
        return false;
    }
};
