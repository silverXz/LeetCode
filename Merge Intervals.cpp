/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 
 bool cmp(const Interval& a,const Interval& b)
 {
     if( a.start != b.start )
        return a.start < b.start;
    else
        return a.end < b.end;
 }
 
class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) 
    {
        vector<Interval> res;
        if( intervals.size() <= 0 )
            return res;
        sort(intervals.begin(),intervals.end(),cmp);
        Interval tmp = intervals[0];
        for( int i = 0 ; i < intervals.size() ; i++ )
        {
            if( tmp.end >= intervals[i].start )
                tmp.end = tmp.end > intervals[i].end ? tmp.end : intervals[i].end;
            else
            {
                res.push_back(tmp);
                tmp = intervals[i];
            }
        }
        res.push_back(tmp);
        return res;
    }
};
