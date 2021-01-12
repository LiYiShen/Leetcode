class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // ת��
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = tmp;
            }
        }
        // ����Գ�
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n/2; ++j) {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[i][n-j-1];
                matrix[i][n-j-1] = tmp;
            }
        }
    }
};

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int count = 0;
        int digit = 0;
        /* һȦһȦ�Ĵ���, ������㴦�����ڲ� */
        while (n - 2 * count > 1) {
            /* ����һ���� */
            for (int i = count; i < n - count - 1; ++i) {
                // �Ĵ���ת
                digit = matrix[count][i];
                matrix[count][i] = matrix[n - i - 1][count];
                matrix[n - i - 1][count] = matrix[n - count - 1][n - i - 1];
                matrix[n - count - 1][n - i - 1] = matrix[i][n - count - 1];
                matrix[i][n - count - 1] = digit;
            }
            count++;
        }  
    }
};
