class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) { //edge case
            return 0;
        }

        int l = 0;
        int r = 1;
        int res = 0;

        while (r < prices.size()) {
            //compare l and r
            if (prices[l] <= prices[r]) {
                res = max(res, (prices[r] - prices[l]));
                r++;
            }
            else {
                l = r;
                r++;
            }
        }
        return res;
    }
};
