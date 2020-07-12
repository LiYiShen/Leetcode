class Solution {
public:
    int numSquares(int n) {
        queue< pair<int,int> > q;    // ���ö��н�� ��Ȩͼ�ṹ�� BFS
        q.push(make_pair(n, 0));    // ����ͼ�ṹ

        vector<bool> visited(n + 1, false);
        visited[n] = true;          // ͼ�ṹ����·�������ظ�

        while(!q.empty()) {
            int num = q.front().first;
            int step = q.front().second;
            q.pop();

            for(int i = 1;  ; i++) {
                int a = num - i * i;    // ��ȥƽ�����������һ��ͼ�ڵ�λ�ã�����step + 1�㡣�����ж���������ᵽ�����ڵ㡣
                if(a < 0)
                    break;
                if(a == 0)           // ������0�ڵ㣬˵���Ѿ������ˡ������ǲ���ģ���һ������0�ڵ��ֱ�ӷ��ز�����
                    return step + 1;
                if(!visited[a]) {
                    q.push(make_pair(a, step + 1));     // ��¼���ﵱǰ�ڵ㣬�Ѿ����˵Ĳ�����
                    visited[a] = true;
                }
            }
        }
        return 0;
    }
};

// n=10:    (10, 0)--(9, 1)--(6, 1)--(1, 1)--(8, 2)--(5, 2)--(0, 2)     10 = 3*3 + 1*1;  step = 2