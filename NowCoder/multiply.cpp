class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        int len = A.size();
        vector<int> left(len, 1);
        vector<int> right(len, 1);
        for (int i = 1; i < len; ++i) {
            left[i] = left[i-1] * A[i-1];
        }
        for (int j = len-2; j >= 0; --j) {
            right[j] = right[j+1] * A[j+1];
        }
        vector<int> B;
        B.reserve(len);  // reserve������Ԥ���ռ�(capacity)���ڿռ��ڲ���������Ԫ�ض���������û������¶���֮ǰ���������������ڵ�Ԫ�ء�������Ԫ��ʱ��Ҫ����push_back()/insert()������
        for (int i = 0; i < len; ++i) {
            B.push_back(left[i] * right[i]);
        }
        return B;
    }
};