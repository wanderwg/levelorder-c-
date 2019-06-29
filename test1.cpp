#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<vector<int>> leverOrder(TreeNode* root)
	{
		vector<vector<int>> vRet;
		if (root == nullptr)
			return vRet;
		queue<TreeNode*> q;
		q.push(root);
		while (q.empty())
		{
			size_t levelCount = q.size();
			vector<int> level;
			for (size_t i = 0; i < levelCount; ++i)
			{
				TreeNode* pCur = q.front();
				level.push_back(pCur->val);
				if (pCur->left)
					q.push(pCur->left);
				if (pCur->right)
					q.push(pCur->right);
				q.pop();
			}
			vRet.push_back(level);
		}
		return vRet;
	}
};