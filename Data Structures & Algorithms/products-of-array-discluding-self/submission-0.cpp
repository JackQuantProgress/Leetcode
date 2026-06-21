class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            int temp = 1;
            for (int j = 0; j < nums.size(); j++) {
                if (i!=j) {
                temp = temp * nums[j];
                }
            }
            res.push_back(temp);
        }
        return res;
    }
};
