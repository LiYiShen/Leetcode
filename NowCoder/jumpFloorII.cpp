// һֻ����һ�ο�������1��̨�ף�Ҳ��������2��������Ҳ��������n���������������һ��n����̨���ܹ��ж�����������
// 2^(n-1)
class Solution {
public:
    int jumpFloorII(int number) {
        return 1 << --number;
    }
};