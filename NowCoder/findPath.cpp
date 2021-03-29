// ���Ҷ��������ڵ㵽�������·��
class Solution {
public:
    unordered_map<int, TreeNode*> mp;  // �洢���н��ĸ��ڵ�
    void dfs(TreeNode* root) {
        if (root->left) {
            mp[root->left->val] = root;
            dfs(root->left);
        }
        if (root->right) {
            mp[root->right->val] = root;
            dfs(root->right);
        }
    }
    vector<int> findPath(TreeNode* root, TreeNode* target) {
        if (!root) return nullptr;
        mp[root->val] == nullptr;  // ���ڵ�ĸ��ڵ�Ϊ nullptr
        dfs(root);
        vector<int> res;
        while (target) {
            res.emplace_back(target->val);
            target = mp[target->val];
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

class Solution {
public:
    // �ݹ���Ҹ��ڵ㣬����true����ǰ�������ҵ�������false����ǰ����û�в��ҵ�
    // sΪ������������������ý���ʱ��s�д洢target�ڵ㵽���ڵ��·������Ҫ��s�е�Ԫ�ؽ��з�ת
    bool findPath(TreeNode *root, stack<TreeNode*> & s, TreeNode *node) {
        if (!root) return false;
        s.push(root);
        if (root->val == node->val) return true;
        bool find = false;
        //��ȥ����������
        if (root->left) find = findPath(root->left, s, node);
        //��������û�в鵽ʱ��ȥ����������
        if (!find && root->right) find = findPath(root->right, s, node);
        if (!find) s.pop();
        return find;
    }
    vector<int> findPath(TreeNode* root, TreeNode* target) {
        stack<TreeNode*> s;
        findPath(root, s, target);
        vector<int> res;
        while (!s.empty()) {
            auto cur = s.top();
            s.pop();
            res.insert(res.begin(), cur->val);
        }
        return res;
    }
};