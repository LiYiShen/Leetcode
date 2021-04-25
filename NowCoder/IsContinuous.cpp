class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
        if (numbers.empty()) return false;
        set<int> st;
        int maxNum = 0, minNum = 14;
        for (int & val : numbers) {
            if (val > 0) {
                if (st.count(val) > 0) return false;
                st.insert(val);
                maxNum = max(maxNum, val);
                minNum = min(minNum, val);
            }
        }
        return maxNum - minNum < 5;  // �����˿��Ƶ�˳��--���ֵ����Сֵ�Ĳ�ֵС��5
    }
};