class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        int res = 1;
        vector<int> dp(nums.size(), 1);
        for(int i = 1; i < nums.size(); i++)
            for(int j = 0; j < i; j++) {
                if(nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j]+1);
                    res = max(res, dp[i]);
                }
            }
        return res;
    }
};

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // ���ֲ��� O(nlogn)
        if(nums.size() == 0)
            return 0;
        // ����ҵ������������У�����Ԫ��ֵԽСԽ�ã�����������һ����ֵ��ʱ�򣬹������������еĿ����Ծ�Խ�󡣣�
        vector<int> dp;   
        dp.push_back(nums[0]);
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] > dp.back()) {
                dp.push_back(nums[i]);
            }else {
                int aim = lower_bound(dp.begin(), dp.end(), nums[i]) - dp.begin();
                dp[aim] = nums[i];
            }
        }
        return dp.size();
    }
};