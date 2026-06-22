class Solution {
public:
    int maxArea(vector<int>& heights) {
        //two points
        //check values of pointer
        //smaller one moves in
        //incase of tie look forward to next item to settle
        int l = 0;
        int r = heights.size()-1;
        int distance;
        int best = 0;
        int current = 0;

        while (l<r) {
            distance = r-l;
            cout << heights[l];
            cout << "-";
            cout << heights[r];
            cout << "=====";
            if (heights[l] > heights[r]) {
                cout << "left bigger";
                current = heights[r] * distance;
                r--;
            }
            else if (heights[l] < heights[r]){
                cout << "right bigger";
                current = heights[l] * distance;
                l++;
            }
            else if (heights[l+1] > heights[r-1]) {
                current = heights[r] * distance;
                l++;
            }
            else {
                current = heights[l] * distance;
                r--;
            }
            //cout << current;
            best = max(best, current);
        }
        return best;
    }
};
