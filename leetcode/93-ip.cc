// https://leetcode.com/problems/restore-ip-addresses/
#include <cstdlib>
#include <algorithm>

class Solution {
public:
    vector<string> restoreIpAddresses(string s, int num_groups = 4) {
        if (num_groups == 1)
            if (s.size() > 0 && s.size() < 4 && atoi(s.c_str()) < 256 && (s[0] != '0' || s == "0"))
                return vector<string>{s};
            else
                return vector<string>();
        //if (num_groups == 0 && s.size() > 0) return vector<string>();
        //if (num_groups > 0 && s.size() == 0) return vector<string>();
        
        int limit = atoi(s.substr(0, 3).c_str()) < 256 ? 3 : 2;
        //int limit = 3;
        if (s.size() < limit) limit = s.size();
        vector<string> all_groups;
        
        for (int c = 1; c <= limit; c++) {
            string prefix = s.substr(0, c);
            if (prefix.size() == c && (prefix[0] != '0' || prefix == "0")) {
                vector<string> groups = restoreIpAddresses(string(s.begin() + c, s.end()), num_groups - 1);
                for (const string& el : groups) all_groups.push_back(prefix + '.' + el);
            }
        }
        
        return all_groups;
    }
};
