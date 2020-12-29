class Solution {
private:
    vector<vector<int>> res;
public:
    vector<vector<int>> combine(int n, int k) {
        if (n <= 0 || k <= 0 || n < k) return res;
        vector<int> track;
        backtrack(n, k, 1, track);
        return res;
    }
    void backtrack(int n, int k, int start, vector<int>& track) {
        if (track.size() == k) {
            res.push_back(track);
            return;
        }
        for (int i = start; i <= n - (k - track.size()) + 1; ++i) {  // ��֦--����ѭ������
            track.push_back(i);
            backtrack(n, k, i + 1, track);
            track.pop_back();
        }
    }
};