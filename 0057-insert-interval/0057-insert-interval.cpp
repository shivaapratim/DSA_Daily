class Solution {
public:
    int call(int it, vector<vector<int>>& intervals, int e) {
        for (auto t : intervals) {
            if (t[1] > it) {
                return max(t[1], e);
            }
        }
        return e;
    }

    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> arr;
        
        int s = newInterval[0];
        int e = newInterval[1];
        bool inserted = false;

        for (auto it : intervals) {
            if (it[1] < s) {
                arr.push_back(it);
            } else if (it[0] > e) {
                if (!inserted) {
                    arr.push_back({s, e});
                    inserted = true;
                }
                arr.push_back(it);
            } else {
                s = min(s, it[0]);
                e = max(e, it[1]);
            }
        }

        if (!inserted) {
            arr.push_back({s, e});
        }

        return arr;
    }
};