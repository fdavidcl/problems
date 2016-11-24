// https://leetcode.com/problems/merge-intervals/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        if (intervals.size() > 1) {
            sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b) { 
                return a.start < b.start || (a.start == b.start && a.end < b.end);
            });
            
            vector<Interval> result;
            result.push_back(*intervals.begin());
            
            for (auto ni = intervals.begin()+1; ni != intervals.end(); ni++) {
                if (ni->start <= result.back().end) {
                    result.back().end = max(ni->end, result.back().end);
                } else {
                    result.push_back(*ni);
                }
            }
            
            return result;
        } else {
            return intervals;
        }
    }
};
