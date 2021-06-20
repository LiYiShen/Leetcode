/* �����⣺���·��
 * ͼ��Ӵ����������JPEG��ʽͼƬ�����ܶ�node������Щnode����һ��ͼ�����pipeline�����е���Щ�ڵ������������ڵ������A->B��ʾB��ִ��������A��
 * ����ÿ��nodeִ��ʱ��ΪA(t)����node A��Ҫִ��t�룬û��������node���Բ���ִ�С���дһ����������һ�������޻�ͼpipeline�����ִ������Ҫ�����ʱ�䡣
 * ���룺��һ������node��ִ��ʱ�䣬�ڶ�������node��������ϵ��
 * ��������ʱ�䡣
 *
 * ÿ���ڵ���������ǰ���ڵ�����ֵ ����һ��ʼ�Ͱѱ߷����� */
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 100010;
int e[N], ne[N], h[N], w[N], idx;

// ��������ͼ
void add(int a, int b) {
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

// dfs����
int dfs(int u) {
    int s = 0;
    //����u�������ж���
    for(int i = h[u]; ~i; i = ne[i]) {
        int j = e[i];
        s = max(s, dfs(j)); // �ݹ������ж�����ֵ�����Ǹ�
    }
    return s + w[u]; // ���ض������ֵ+���������
}

int main() {
    memset(h, -1, sizeof(h));
    int num, k = 0;
    while (cin >> num) {
        w[++ k] = num;
        if (cin.get() == '\n') break;
    }
    vector<bool> st(k); // ��¼�ýڵ��Ƿ��и����
    k = 1;
    while (cin >> num) {
        add(k, num);
        st[num] = true;
        char op = cin.get();
        if (op == ';') k++;
        else if (op == '\n') break;
    }
    // dfs����ÿ�����ڵ����µݹ�
    int ans = 0;
    for (int i = 1; i <= st.size(); i++) {
        if (st[i] == false)
            ans += dfs(i);
    }
    cout << ans;
    system("pause");
    return 0;
}