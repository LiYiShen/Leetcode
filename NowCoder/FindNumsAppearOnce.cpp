class Solution {
public:
    vector<int> FindNumsAppearOnce(vector<int>& array) {
        int res = 0;
        for (int & num : array) {
            res ^= num;
        }
        int index = 0;  // ���� index λ���� a/b
        while ((res & 1) == 0) {  // & ���ȼ����� ==
            index++;
            res = res >> 1;
        }
        int a = 0, b = 0;
        for (int num : array) {
            if (partition(num, index)) {  // ���� index λ�����黮��Ϊ������
                a ^= num;
            } else {
                b ^= num;
            }
        }
        return a < b ? vector<int>{a, b} : vector<int>{b, a};
    }
    bool partition(int num, int index) {
        num = num >> index;
        return (num & 1) != 0;
    }
};

class Solution {
public:
    vector<int> FindNumsAppearOnce(vector<int>& array) {
        sort(array.begin(), array.end());
        vector<int> v;
        for (int i = 0; i < array.size(); ++i) {
            if (array[i] == array[i+1]) ++i;
            else v.push_back(array[i]);
        }
        return v;
    }
};