class Solution {
public:
    bool match(string str, string pattern) {
        return match(str, pattern, 0, 0);
    }
    bool match(string& str, string& pattern, int i, int j) {
        /* Four case:
         * i,j����ɱ��� -- true
         * i,j��δ��ɱ��� -- ���ж�pattern[j+1]�Ƿ�Ϊ*,���ж�str[i]��pattern[j]�Ƿ����; ����,�ֱ�ƥ�� ���ɴ�/1��/0��
         * i��ɱ���, jδ��ɱ��� -- pattern������*��β
         * iδ��ɱ���,j��ɱ��� -- false */
        if (i == str.size() && j == pattern.size()) return true;
        if (i != str.size() && j == pattern.size()) return false;
        if (pattern[j+1] == '*') {
            if (str[i] == pattern[j] || (i != str.size() && pattern[j] == '.'))
                return match(str, pattern, i+1, j) || match(str, pattern, i+1, j+2) || match(str, pattern, i, j+2);
            else return match(str, pattern, i, j+2);
        } else {
            if (str[i] == pattern[j] || (i != str.size() && pattern[j] == '.'))
                return match(str, pattern, i+1, j+1);
            else return false;
        }
    }
};