class Solution {
public:
    int trap(vector<int>& height) {
        //left pointer start of pool
        // right iterates over subtracting from lefts height accumulating the values until higher pole found
        // handle edge case of smaller pole as end on th right side finds max of iterated and uses that as right pole
        //set left pointer to right or backup if applicable
        int l = 0;
        int r = height.size()-1;
        int pocket = 0;
        int total = 0;

        int l_pillar = height[0];
        int r_pillar = height[r];

        while (l < r) {
            cout << l;
            cout << r;
            //decide which pocket to do left or right working inwards
            if (l_pillar < r_pillar) {
                l++;
                //left side moves
                while (l_pillar > height[l]) {
                    cout << l_pillar - height[l];
                    pocket += l_pillar - height[l];
                    l++;
                }
                l_pillar = height[l];
                total += pocket;
                pocket = 0;
            }
            else {
                r--;
                //right side moves
                while (r_pillar > height[r]) {
                    //cout << r_pillar - height[r];
                    pocket += r_pillar - height[r];
                    r--;
                }
                r_pillar = height[r];
                total += pocket;
                pocket = 0;
            }
        }
        return total;
    }
};
