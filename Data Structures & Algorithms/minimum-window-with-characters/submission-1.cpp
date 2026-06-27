class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size()) {
            return "";
        }

        unordered_map<char, int> t_count;
        unordered_map<char, int> window_count;

        int have = 0;
        int need = t.size();

        vector<int> res; // index of start and length

        for (char c : t) {
            t_count[c]++;
        }

        int l=0;
        int r=0;

        while ((r < s.size()) && (l< s.size())) {

            if (need != have) {

                window_count[s[r]]++;

                if (window_count[s[r]] <= t_count[s[r]]){
                    have++;
                }
                r++;

            }
            else {
                //length = l - r
                if (res.empty()) {
                    res.push_back(l);
                    res.push_back(r-l);
                }
                else if (res[1] > (r-l)) {
                    res[0] = l;
                    res[1] = r-l;
                }
                //check if have should be changed;
                if (window_count[s[l]] == t_count[s[l]]) {  
                    have--;
                }

                window_count[s[l]]--;
                l++;
            }
        }
        
        while (have == need) {

            if (res.empty() || res[1] > r-l) {
                res = {l, r-l};
            }

            if (window_count[s[l]] <= t_count[s[l]]) {
                have--;
            }

            window_count[s[l]]--;
            l++;
        }
        if (res.empty()) {
            return "";
        }
        
        string temp = "";

        for (int i = res[0]; i<res[0] + res[1]; i++) {
            temp += s[i];
        }
        
        return temp;
    }
};
