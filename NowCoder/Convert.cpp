/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    TreeNode* pre = NULL;
    TreeNode* Convert(TreeNode* pRootOfTree) {
        if (!pRootOfTree) return pRootOfTree;
        TreeNode* p = pRootOfTree;
        while (p && p->left) p = p->left;
        inOrder(pRootOfTree);
        return p;
    }
    void inOrder(TreeNode* root) {
        if (!root) return;
        inOrder(root->left);
        root->left = pre;  // ���µ�ǰ�ڵ��leftָ��������һ���ڵ�
        if (pre) pre->right = root;  // ����������һ���ڵ��rightָ��ǰ�ڵ�
        pre = root;
        inOrder(root->right);
    }
};