class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int l = i + 1, r = nums.size() - 1;
            while (l < r) {
                if (nums[l] + nums[r] + nums[i] < 0)
                    ++l;
                else if (nums[l] + nums[r] + nums[i] > 0)
                    --r;
                else {
                    res.push_back({nums[i], nums[l], nums[r]});
                    ++l,
                    --r;
                    while (l < r && nums[l] == nums[l - 1])
                        ++l;
                    while (l < r && nums[r] == nums[r + 1])
                        --r;
                }
            }
        }
        return res;
    }
};