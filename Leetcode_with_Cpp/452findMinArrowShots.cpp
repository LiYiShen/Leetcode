class Solution {
private:
    static bool cmp(vector<int>& a, vector<int>& b) {
        return a[1] < b[1];
    }
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.size() == 0) return 0;
        sort(points.begin(), points.end(), cmp);
        int res = 1;
        int end = points[0][1];
        for (int i = 1; i < points.size(); ++i)
            if (points[i][0] > end) {
                end = points[i][1];
                res++;
            }
        return res;
    }
};

// 区间边界触碰也算重叠