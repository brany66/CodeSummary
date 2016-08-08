void preOrder(treeNode *root) {
	if (root != NULL) {
		cout << root->val << " "；
		preOrder(root->left);
		preOrder(root->right);
	}
}
vector<int> preOrder_NotRec(treeNode *root) {
	vector<int> res;
	if (root == NULL) return res;
	stack<treeNode*> st;
	treeNode *p = root;
	while (p != NULL || !st.empty()) {
		while(p!= NULL) {
			res.push_back(p->val);
			st.push(p);
			p=p->left;
		}
		if (!st.empty()) {
			p = st.top();
			st.pop();
			p = p->right;
		}
	}
	return res;
}
void InOrder(treeNode *root) {
	if (root != NULL) {
		InOrder(root->left);
		cout << root->val << " ";
		InOrder(root->right);
	}
}
vector<int> InOrder_NotRec(treeNode *root) {
	vector<int> res;
	if (root == NULL ) return res;
	stack<treeNode*> st;
	treeNode *p = root;
	while (p != NULL || !st.empty()) {
		while (p != NULL) {
			st.push(p);
			p = p->left;
		}
		if (!st.empty()) {
			p = st.top();
			res.push_back(p->val);
			st.pop();
			p = p->right;
		}
	}
	return res;
}
void postOrder(treeNode *root) {
	if (root != NULL) {
		postOrder(root->left);
		postOrder(root->right);
		cout << root->val << " ";
	}
}
vector<int> postOrder_NotRec(treeNode *root) {
	vector<int> res;
	if (root == NULL) return res;
	stack<treeNode*> st;
	treeNode cur, pre = NULL;
	st.push(root);
	while (!st.empty()) {
		cur = st.top();
		if ((cur->left == NULL && cur->right == NULL) || 
		(pre != NULL && (pre == cur->left || pre == cur->right))){
			res.push_back(cur->val);
			st.pop();
			pre = cur;
		}else {
			if (cur->right != NULL)
				st.push(cur->right);
			if (cur->left != NULL)
				st.push(cur->left);
		}
	}
}
void LevelOrder(treeNode *root) {
	queue<treeNode *> q;
	treeNode *t;
	q.push(root);
	while (!q.empty()) {
		t = q.front();
		if (t->left)
			q.push(root->left);
		if (t->right)
			q.push(root->right);
		q.pop();
		cout << t->val << " ";
	}
}