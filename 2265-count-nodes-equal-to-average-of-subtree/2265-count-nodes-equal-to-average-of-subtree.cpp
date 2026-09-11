/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

int return_avg(TreeNode* root)
{
    queue<TreeNode*> q;
    int count = 0;
    int sum  = 0;
    q.push(root);
    while(!q.empty())
    {
        auto el = q.front();
        sum+=el->val;
        q.pop();
        count++;
        if(el->left) q.push(el->left);
        if(el->right) q.push(el->right);
    }
    return sum/count;
}


class Solution {
public:
    int averageOfSubtree(TreeNode* root) {
        int cnt = 0;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            auto el = q.front();
            q.pop();
            int value = el->val;
            int avg = return_avg(el);
            if (value == avg)
                cnt++;
            if (el->left)
                q.push(el->left);
            if (el->right)
                q.push(el->right);        
        }

        return cnt;
    }
};