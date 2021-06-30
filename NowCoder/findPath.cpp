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
    void dfs(TreeNode* root, int exp, vector<int>& path, vector<vector<int> >& res) {
        path.push_back(root->val);
        if (root->val == exp && !root->left && !root->right) {
            res.push_back(path);
        }
        if (root->left) dfs(root->left, exp - root->val, path, res);
        if (root->right) dfs(root->right, exp - root->val, path, res);
        path.pop_back();
    }
    vector<vector<int> > FindPath(TreeNode* root, int expectNumber) {
        vector<vector<int> > res;
        vector<int> path;
        if (!root) return res;
        dfs(root, expectNumber, path, res);
        return res;
    }
};

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