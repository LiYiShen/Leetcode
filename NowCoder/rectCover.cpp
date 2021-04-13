// ���ǿ�����2*1��С���κ��Ż�������ȥ���Ǹ���ľ��Ρ�������n��2*1��С�������ص��ظ���һ��2*n�Ĵ���Σ��ܹ��ж����ַ�����
// ���ֹ���--쳲�����
class Solution {
public:
    int rectCover(int number) {
        if (number == 1 || number == 2) return number;
        int n1 = 1, n2 = 2, res;
        for (int i = 3; i <= number; ++i) {
            res = n1 + n2;
            n1 = n2;
            n2 = res;
        }
        return res;
    }
};