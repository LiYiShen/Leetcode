// 01����
class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @return: The maximum size
     */
    int backPack(int m, vector<int> A) {
        int k = A.size();
        int f[k][m + 1] = {0};
        for (int i = 0; i < k; i++) {
            for (int j = 1; j <= m; j++) {
                if (i == 0) {
                    f[i][j] = (j >= A[i]) ? A[i] : 0;
                    continue;
                }
                if (j >= A[i])
                    f[i][j] = max(f[i-1][j], f[i-1][j-A[i]] + A[i]);
                else
                    f[i][j] = f[i-1][j];
            }
        }
        return f[k-1][m];
    }
};

// O(m*n) ʱ�临�Ӷȣ�O(m) �ռ临�Ӷȣ�forѭ���Ӵ�С
class Solution {
public:
    int backPack(int m, vector<int> W, vector<int> V) {
        int k = W.size();
        vector<int> f(m + 1, 0);
        for (int i = 0; i < k; i++) {
            for (int j = m; j >= W[i]; j--) {
                f[j] = max(f[j], f[j - W[i]] + V[i]);
            }
        }
        return f[m];
    }
};

// ��ȫ��������
int backPack(int m, vector<int> W, vector<int> V) {
    int k = W.size();
    vector<int> f(m + 1, 0);
    for (int i = 0; i < k; i++) {
        for (int j = w[i]; j <= m; j++) {
            f[j] = max(f[j], f[j - w[i]] + v[i]);
        }
    }
    return f[m];
}

// ���ر�������
int backPack(int m, vector<int> W, vector<int> cot, vector<int> V) {
    vector<int> f(m + 1, 0);
    for (int i = 0; i < W.size(); i++) {
        for (int k = 1; k <= cot[i]; k++) {
            for (int j = m; j >= w[i]; j--) {
                f[j] = max(f[j], f[j - w[i]] + v[i]);
            }
        }
    }
    return f[m];
}