class Solution {
private:
    class MonotonicQueue {  // ��������
    private:
        deque<int> data;
    public:
        void push(int n) {
            while (!data.empty() && data.back() < n)
                data.pop_back();
            data.push_back(n);
        }
        int max() { return data.front(); }
        void pop(int n) {
            if (!data.empty() && data.front() == n)
                data.pop_front();
        }
    };
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        MonotonicQueue window;
        for (int i = 0; i < k - 1; i++)
            window.push(nums[i]);
        for (int j = k - 1; j < nums.size(); j++) {
            window.push(nums[j]);
            res.push_back(window.max());
            window.pop(nums[j - k + 1]);
        }
        return res;
    }
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> deque;
        for (int i = 0; i < nums.size(); i++) {
            if (!deque.empty() && deque.front() == i-k)  // ���ڴ�С���� k, ������ͷ 
                deque.pop_front();
            while (!deque.empty() && nums[i] > nums[deque.back()])  // ��������
                deque.pop_back();
            deque.push_back(i);
            if (i >= k-1) res.push_back(nums[deque.front()]);
        }
        return res;
    }
};