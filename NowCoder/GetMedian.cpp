class Solution {
public:
    #define SCD static_cast<double>
    vector<int> ve;
    void Insert(int num) {
        if (ve.empty()) {
            ve.push_back(num);
        } else {
            auto it = lower_bound(ve.begin(), ve.end(), num);
            ve.insert(it, num);
        }
    }
    double GetMedian() {
        int sz = ve.size();
        if (sz & 1) return SCD(ve[sz >> 1]);
        else return SCD(ve[sz >> 1] + ve[(sz-1) >> 1]) / 2;
    }
};

class Solution {
public:
    #define SCD static_cast<double>
    priority_queue<int> min_q;  // ����
    priority_queue<int, vector<int>, greater<int>> max_q;  // С����
    void Insert(int num) {
        min_q.push(num);  // ��ͼ���뵽����
        // ƽ��һ��������
        max_q.push(min_q.top());
        min_q.pop();
        if (min_q.size() < max_q.size()) {
            min_q.push(max_q.top());
            max_q.pop();
        }
    }
    double GetMedian() {
        return min_q.size() > max_q.size() ? SCD(min_q.top()) : SCD(min_q.top() + max_q.top()) / 2;
    }
};