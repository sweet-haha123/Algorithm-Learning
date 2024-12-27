//递归遍历，栈
void traverse(TreeNode *root,vector<int> &result)
{
    if (root==nullptr)
            return;
    
    //前序递归
    result.push_back(root->val);
    traverse(root->left,result);
    traverse(root->right,result);

    //中序递归
    traverse(root->left,result);
    result.push_back(root->val);
    traverse(root->right,result);

    //后序递归
    traverse(root->left,result);
    traverse(root->right,result);
    result.push_back(root->val);
}

/*##################################################
##################################################
############统一的迭代遍历##########################
##################################################
##################################################*/
//使用栈
//前序遍历
 vector<int> preorderTraversal(TreeNode* root) {
      vector<int> result;
      stack<TreeNode*> st;
      if (root!=nullptr) st.push(root);

      while(!st.empty())
      {
        TreeNode *node=st.top();
        if (node!=nullptr)
        {
            st.pop();
            if (node->right) st.push(node->right);
            if (node->left) st.push(node->left);
            st.push(node);
            st.push(nullptr);
        }
        else
        {
            st.pop();
            node=st.top();
            st.pop();
            result.push_back(node->val);
        }
      }
       return result;
    }

//中序遍历
vector<int> inorderTraversal(TreeNode* root) {
        vector <int> result;
        stack<TreeNode *> st;
        if (root!=nullptr) st.push(root);

        while (!st.empty())
        {
            TreeNode *node=st.top();
            if (node!=nullptr)
            {
                st.pop();

                if (node->right) st.push(node->right);
                st.push(node);
                st.push(nullptr);
                if (node->left) st.push(node->left);
            }
            else
            {
                st.pop();
                node=st.top();
                st.pop();
                result.push_back(node->val);
            }
        }
        return result;
    }

//后序遍历
vector<int> postorderTraversal(TreeNode* root) {
        vector <int> result;
        stack<TreeNode *> st;
        if (root!=nullptr) st.push(root);

        while (!st.empty())
        {
            TreeNode *node=st.top();
            if (node!=nullptr)
            {
                st.pop();

                st.push(node);
                st.push(nullptr);

                if (node->right) st.push(node->right);
                if (node->left) st.push(node->left);
            }
            else
            {
                st.pop();
                node=st.top();
                st.pop();
                result.push_back(node->val);
            }
        }
        return result;
    }



/*##################################################
##################################################
############层序遍历##########################
##################################################
##################################################*/
//使用队列
vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> que;
        if (root != nullptr) que.push(root);
        vector<vector<int>> result;
        while (!que.empty())
        {
            int size = que.size();
            vector<int> vec;
            for (int i = 0; i < size; i++)
            {   
                TreeNode* node = que.front();
                vec.push_back(node->val);
                que.pop();

                if (node->left )que.push(node->left);
                if (node->right) que.push(node->right);
            }
            result.push_back(vec);
        }
        return result;
  }