class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        std::sort(nums.begin(), nums.end());
        int i = 1;
        int longest = 1;
        int current = 1;

        while (i < nums.size()) {

            if (nums[i] == nums[i-1]) {
                i++;
                continue;
            }
            else if (nums[i]-1 == nums[i-1]) {
                current ++;
            }
            else {
                if (current > longest) {
                    longest = current;
                }
                current = 1;
            }
            i ++;
        }
        return max(longest, current);
    }
};
