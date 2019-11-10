class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //dp
        //1.״̬���� F(i): �±�Ϊiʱ�������������
        //2.״̬ת�Ʒ��� F(i) = max(F(i-1)+nums[i], nums[i]);
        //3.��ʼ״̬ F(0) = nums[0];
        //4.����ֵ F(nums.size()-1)

        if(nums.empty()) 
            return 0;  
        vector<int> v(nums);
        int maxNum = nums[0];
        for(int i = 1; i < nums.size(); i++)
        {
            v[i] = max(v[i-1]+nums[i], nums[i]);
            if(maxNum < v[i])
                maxNum = v[i];
        }
        return maxNum;
    }
};