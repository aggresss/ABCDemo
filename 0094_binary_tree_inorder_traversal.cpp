//包裹结构体，标明左子树是否已经访问过
 struct TreeNodeWrapper{
    struct TreeNode *pNode;
    bool lVisited; //左子树已访问过
    bool rVisited; //右子树已访问过
    TreeNodeWrapper(TreeNode * p){pNode = p; lVisited= false; rVisited= false;}
};
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
               vector<int> result;
        stack<TreeNodeWrapper*> node_stack;
        if (root == NULL)
               return result;
        node_stack.push(new TreeNodeWrapper(root));
        while(!node_stack.empty()){
            TreeNodeWrapper* pNode = node_stack.top();
            if (pNode->lVisited || pNode->pNode->left==NULL) //左子树已访问过，或者为空
            {
                node_stack.pop();
                result.push_back(pNode->pNode->val); //访问节点，访问右子树
                if (pNode->pNode->right) 
                {
                    node_stack.push(new TreeNodeWrapper(pNode->pNode->right));
                }
                delete pNode;
            }else{      //访问左子树，并标记
                node_stack.push(new TreeNodeWrapper(pNode->pNode->left));
                pNode->lVisited = true;
            }
        }
        return result;
    }
};
