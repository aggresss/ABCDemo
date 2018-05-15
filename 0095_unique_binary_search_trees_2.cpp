/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
class Solution {  
public:
    vector<TreeNode *> generateTrees(int n) {   
        vector<TreeNode *> ret = generateTrees(1,n);  
        return ret;  
    }  
    vector<TreeNode*> generateTrees(int start,int end)  
    {  
        vector<TreeNode*> ret;  
        if(start>end)  
        {  
            ret.push_back(nullptr);  
            return ret;  
        }  
        if(start==end)  
        {  
            ret.push_back(new TreeNode(start));  
            return ret;  
        }  
        for(int i=start;i<=end;i++)  
        {  
            vector<TreeNode*> left = generateTrees(start,i-1);  
            vector<TreeNode*> right = generateTrees(i+1,end);  
            for(auto l:left)  
            {  
                for(auto r:right)  
                {  
                    TreeNode* head = new TreeNode(i);  
                    head->left = l;  
                    head->right = r;  
                    ret.push_back(head);  
                }  
            }  
              
        }  
        return ret;  
    }  
};
