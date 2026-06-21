class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int p;
        for (int i=0; i<nums.size(); i++){
            if ((i!=0)&&(nums[i] == p)){
                return true;
            }
            p = nums[i];
        }
        return false;
    }
};