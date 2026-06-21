class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int i = 0;
        int target;
        vector<vector<int>> res;
        //sort to deal with duplicate entries
        std::sort(nums.begin(), nums.end());

        while (i < nums.size()) {
            //check for duplicate
            if (i != 0 && nums[i] == nums[i - 1]) {
                i++;
            }
            else {
                unordered_set<int> s = {};
                //create target for remaining list two sum
                target = -nums[i];
                //iterate over remaining list
                for (int x = i + 1; x < nums.size(); x++) {
                    int focal_value = nums[x];
                    if (s.count(target-focal_value)) {
                        res.push_back({nums[i], focal_value, (target-focal_value)});
                        // Skip duplicate values for the second element to avoid duplicate triplets
                        while (x + 1 < nums.size() && nums[x] == nums[x + 1]) x++;
                    }
                    s.insert(focal_value);
                }
                i++;
            }
        }
        return res;
    }
};
