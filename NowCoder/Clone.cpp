// ����һ����������ÿ���ڵ����нڵ�ֵ���Լ�����ָ�룬һ��ָ����һ���ڵ㣬��һ������ָ��randomָ��һ������ڵ㣩����Դ������������������ؿ������ͷ��㡣
/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead) {
        RandomListNode* p = pHead;
        unordered_map<RandomListNode*, RandomListNode*> m;
        while (p) {
            RandomListNode* newHead = new RandomListNode(p->label);
            m[p] = newHead;
            p = p->next;
        }
        p = pHead;
        while (p) {
            m[p]->next = p->next == NULL ? NULL : m[p->next];
            m[p]->random = p->random == NULL ? NULL : m[p->random];
            p = p->next;
        }
        return m[pHead];
    }
};

class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead) {
        if (!pHead) return NULL;
        RandomListNode* p = pHead;
        while (p) {
            RandomListNode* newNode = new RandomListNode(p->label);
            newNode->next = p->next;
            p->next = newNode;
            p = newNode->next;
        }
        p = pHead;
        while (p) {
            p->next->random = p->random == NULL ? NULL : p->random->next;
            p = p->next->next;
        }
        p = pHead;
        RandomListNode* newHead = p->next;
        while (p) {
            RandomListNode* newNode = p->next;
            p->next = newNode->next;
            newNode->next = newNode->next == NULL ? NULL : newNode->next->next;
            p = p->next;
        }
        return newHead;
    }
};