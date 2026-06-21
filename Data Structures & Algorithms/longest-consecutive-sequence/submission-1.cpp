class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        int longest = 1;
        int current = 1;

        unordered_set<int> s(nums.begin(), nums.end());

        for (int i : s) {
            if (s.contains(i-1)) { //not start
                continue;
            }
            else { //start of a sequence
                int n = i + 1;
                while (s.contains(n)) {
                    current ++;
                    n++;
                }
                longest = max(longest, current);
                current = 1;
            }
        }
        return max(longest, current);
    }
};
