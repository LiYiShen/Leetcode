// ��1+2+3+...+n��Ҫ����ʹ�ó˳�����for��while��if��else��switch��case�ȹؼ��ּ������ж���䣨A?B:C����
class Solution {
public:
    int Sum_Solution(int n) {
        int res = n;
        res && (res += Sum_Solution(n-1));
        return res;
    }
};