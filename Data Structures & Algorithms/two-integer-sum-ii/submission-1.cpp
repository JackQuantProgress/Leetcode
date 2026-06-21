class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0;
        int r = numbers.size()-1;

        int temp;
        vector<int> res(2);

        while (true) {
            temp = numbers[l] + numbers[r];

            if (temp == target) {
                return {l+1, r+1};
            }
            else if (temp > target) {
                r--;
            }
            else {
                l++;
            }
        }
    }
};
