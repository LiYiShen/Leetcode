class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if (n < 2) return n;
        vector<int> nums(n, 1);
        for (int i = 1; i < n; ++i)  // ̰�Ĳ��� ÿ�α���ֻ���ǲ���������һ��Ĵ�С��ϵ
            if (ratings[i] > ratings[i - 1]) nums[i] = nums[i - 1] + 1;
        for (int i = n - 1; i > 0; --i)
            if (ratings[i - 1] > ratings[i]) nums[i - 1] = max(nums[i - 1], nums[i] + 1);
        return accumulate(nums.begin(), nums.end(), 0);
    }
};