class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size) {
        vector<int> res;
        deque<int> deque;
        if (num.size() == 0 || size < 1 || num.size() < size) return res;
        for (int i = 0; i < num.size(); i++) {
            if (!deque.empty() && deque.front() == i - size)  // ���ڴ�С���� size, ������ͷ (i-size+1��Ϊ��Ԫ��index)
                deque.pop_front();
            while (!deque.empty() && num[i] > num[deque.back()])
                deque.pop_back();
            deque.push_back(i);
            if (i + 1 >= size) res.push_back(num[deque.front()]);
        }
        return res;
    }
};