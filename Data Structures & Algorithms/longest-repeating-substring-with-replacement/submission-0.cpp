class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> count;
        int l = 0, r = 0;
        int best = 0;

        while (r < s.size()) {

            // add right character first
            count[s[r]]++;

            // shrink window if invalid
            while ((r - l + 1) - maximum_count(count) > k) {
                count[s[l]]--;
                l++;
            }

            // update answer (window size, not map size)
            best = std::max(best, r - l + 1);

            r++;
        }

        return best;
    }

    int maximum_count(unordered_map<char, int> count) {
        int m = 0;
        for (auto &x : count) {
            m = std::max(m, x.second);
        }
        return m;
    }
};