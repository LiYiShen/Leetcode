/* �ҳ���������Ĺ����ڵ㣺
 * �ֱ����������Ľ���������ջ��������������β����λ������ջ��ջ�����������Ƚ�����ջ���Ľ���Ƿ���ͬ��
 * �����ͬ�����ջ���������űȽ���һ��ջ����ֱ���ҵ����һ����ͬ�Ľ�㡣
 *
 * ���ȱ�����������õ����ǵĳ��ȣ�����֪���ĸ�����Ƚϳ����Լ���������ȶ̵�����༸����㡣
 * �ڵڶ��α�����ʱ���ڽϳ����������������ɲ���������ͬʱ�����������ϱ������ҵ��ĵ�һ����ͬ�Ľ��������ǵĵ�һ��������㡣
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return NULL;
        ListNode *pa = headA;
        ListNode *pb = headB;
        while (pa != pb) {  // ʹ pa pb �߹���ͬ���ȵľ���, ֱ���ཻ
            pa = (pa != NULL) ? pa->next : headB;
            pb = (pb != NULL) ? pb->next : headA;
        }
        return pa;  // �ҵ������������ཻ����ʼ�ڵ�
    }
};

// �õݹ�ͷǵݹ鷽����ת����
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;
        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* newHead = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newHead;
    }
};

class Solution {
public:
    ListNode* lastNode;
    ListNode* reverseN(ListNode* head, int n) {
        if (1 == n) {
            lastNode = head->next;
            return head;
        }
        ListNode* node = reverseN(head->next, n-1);
        head->next->next = head;
        head->next = lastNode;
        return node;
    }
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (m == 1) {
            return reverseN(head, n);
        }
        head->next = reverseBetween(head->next, m-1, n-1);
        return head;
    }
};

// �����еĽڵ�ÿK��һ�鷭ת
/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k <= 1) return head;
        ListNode* pre = nullptr;
        ListNode* cur = head;
        ListNode* next = nullptr;
        for (int i = 0; i < k; ++i) {
            if (!cur) return head;
            cur = cur->next;
        }
        cur = head;
        for (int i = 0; i < k; ++i) {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        head->next = reverseKGroup(next, k);
        return pre;
    }
};

// ��ת�����ÿ2��Ԫ�أ����� 1,2,3,4,5 ���2,1,4,3,5
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dHead = new ListNode(0);
        dHead->next = head;
        ListNode* p = dHead;
        while (p->next && p->next->next) {
            ListNode* node1 = p->next;
            ListNode* node2 = node1->next;
            ListNode* next = node2->next;
            node2->next = node1;
            node1->next = next;
            p->next = node2;
            p = node1;
        }
        ListNode* resNode = dHead->next;
        delete dHead;
        return resNode;
    }
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode* next = head->next;
        head->next = swapPairs(next->next);
        next->next = head;
        return next;
    }
};

// ��������������ϲ�Ϊһ���µ� ���� �������ء���������ͨ��ƴ�Ӹ�����������������нڵ���ɵġ�
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *p = l1, *q = l2;
        ListNode* res = new ListNode(0);
        ListNode* cur = res;
        while (p && q) {
            if (q->val > p->val) {
                cur->next = p;
                cur = cur->next;
                p = p->next;
            } else {
                cur->next = q;
                cur = cur->next;
                q = q->next;
            }
        }
        if (q) cur->next = q;
        if (p) cur->next = p;
        return res->next;
    }
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* p1, ListNode* p2) {
        if (!p1) return p2;
        if (!p2) return p1;
        if (p1->val <= p2->val) {
            p1->next = mergeTwoLists(p1->next, p2);
            return p1;
        } else {
            p2->next = mergeTwoLists(p1, p2->next);
            return p2;
        }
    }
};

// ���ж�һ�������Ƿ�Ϊ��������
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head, *pre = NULL, *fast = head;
        while (fast && fast->next) {  // fastȷ��slow�ߵ������м�
            ListNode* temp = slow;
            slow = slow->next;
            fast = fast->next->next;
            temp->next = pre;
            pre = temp;
        }
        if (fast) slow = slow->next;  // ����Ԫ�ظ���Ϊ����, �������м�Ԫ��
        while (pre && slow) {
            if (pre->val != slow->val) return false;
            pre = pre->next;
            slow = slow->next;
        }
        return true;  // �ж�һ�������Ƿ�Ϊ�������� (��������ǰ�벿��)
    }
};

// �ϲ�������������
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    struct Comp {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };
    /* �������ȶ��У�����Ҫȫ��Ԫ��һ������ӣ�ֻ��������ͷԪ����Ӽ��ɣ�������Ԫ�غ󣬸����������ơ�*/
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        priority_queue<ListNode*, vector<ListNode*>, Comp> q;
        for (ListNode* list : lists) {
            if (list) q.push(list);
        }
        ListNode *head = new ListNode(0), *cur = head;
        while (!q.empty()) {
            cur->next = q.top();
            q.pop();
            cur = cur->next;
            if (cur->next) q.push(cur->next);
        }
        return head->next;
    }
};

class Solution {
public:
    ListNode* merge(ListNode* p1, ListNode* p2) {
        if (!p1) return p2;
        if (!p2) return p1;
        if (p1->val <= p2->val) {
            p1->next = merge(p1->next, p2);
            return p1;
        } else {
            p2->next = merge(p1, p2->next);
            return p2;
        }
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return nullptr;
        ListNode* head = lists[0];
        for (int i = 1; i < lists.size(); ++i) {
            if (lists[i]) head = merge(head, lists[i]);
        }
        return head;
    }
};

class Solution {
public:
    ListNode* merge(ListNode* p1, ListNode* p2) {
        if (!p1) return p2;
        if (!p2) return p1;
        if (p1->val <= p2->val) {
            p1->next = merge(p1->next, p2);
            return p1;
        } else {
            p2->next = merge(p1, p2->next);
            return p2;
        }
    }
    ListNode* merge(vector<ListNode*>& lists, int start, int end) {
        if (start == end) return lists[start];
        int mid = (start + end) / 2;
        ListNode* l1 = merge(lists, start, mid);
        ListNode* l2 = merge(lists, mid + 1, end);
        return merge(l1, l2);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return nullptr;
        return merge(lists, 0, lists.size() - 1);
    }
};