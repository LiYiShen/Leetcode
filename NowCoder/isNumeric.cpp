class Solution {
public:
    bool isNumeric(string str) {
        // ���� -- continue
        // �Ӽ� -- 1��Ҫ�ڿ�ͷ����E�ĺ���; 2���Һ��治����E
        // E -- 1��ֻ�ܳ���һ��; 2���Ҳ����ڿ�ͷ�����
        // С���� -- 3����eǰֻ�ܳ���1��,e����; 2��С�����Ҫ������
        bool hasE = false;
        int dot = 0;
        for (int i = 0; i < str.size(); ++i) {
            //cout<<str[i]<<endl;
            if (str[i] >= '0' && str[i] <= '9') continue;
            if (str[i] == '+' || str[i] == '-') {
                if (i != 0 && str[i-1] != 'e' && str[i-1] != 'E') return false;
                if (i == str.size()-1 || str[i+1] == 'E' || str[i+1] == 'e') return false;
            } else if (str[i] == 'E' || str[i] == 'e') {
                if (hasE || i == 0 || i == str.size()-1) return false;
                hasE = true;
            } else if (str[i] == '.') {
                if (hasE) return false;
                if (dot > 0) return false;
                if (i == str.size()-1 || str[i+1] < '0' || str[i+1] > '9') return false;
                dot++;
            } else return false;
        }
        return true;
    }
};