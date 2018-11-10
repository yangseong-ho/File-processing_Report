#include<iostream>

class node {

private:
	int key;
	node* left;
	node* right;
	node* parent;
public:
	node(int key=0 , node* left = NULL, node* right = NULL, node* parent = NULL) {
		this->key = key;
		this->left = left;
		this->right = right;
		this->parent = parent;
	}
	node* searchBST(node* T, int searchKey) {
		
		node* p = T;
		if (p == NULL)
			return NULL;
		if (p->key == searchKey)
			return p;
		if (p->key < searchKey)
			return searchBST(p->right, searchKey);
		else
			return searchBST(p->left, searchKey);
	}
	node* deleteBST(node* T, int deleteKey) {
		node* p = searchBST(T, deleteKey);
		node* r ;
		std::string flag = "";

		if (p==NULL) // 원소x
			return T;
		if ( p->parent == NULL) {// 루트 노드만 있는 경우
			T = NULL;
			return T;
		}

		if (p->left == NULL && p->right == NULL) {// 리프노드인 경우
			if (p->parent->right == p)
				p->parent->right = NULL;
			else
				p->parent->left = NULL;
		}
		else if (p->left == NULL || p->right == NULL) { //차수 1
			
			if (p->left == NULL && p->parent == NULL) {
				T = p->right;
				T->parent = NULL;
			}
			else if (p->right == NULL && p->parent == NULL) {
				T = p->left;
				T->parent = NULL;
			}
			if (p->left == NULL) {
				if (p->parent->left == p) {
					p->parent->left = p->right;
					p->right->parent = p->parent;
				}
				else {
					p->parent->right = p->right;
					p->right->parent = p->parent;
				}
			}
			else {
				if (p->parent->left == p) {
					p->parent->left = p->left;
					p->left->parent = p->parent;
				}
				else {
					p->parent->right = p->left;
					p->left->parent = p->parent;
				}
			}
		}
		else  {			//차수 2
			
			if (height(p->left) > height(p->right)) {
				r = maxNodes(p->left);
				flag = "LEFT";
			}
			else if (height(p->left) < height(p->right)) {
				r = minNodes(p->right); 
				flag = "RIGHT";
			}
			else {
				if (noNodes(p->left) >= noNodes(p->right)) {
					r = maxNodes(p->left);
					flag = "LEFT";
				}
				else {
					r = minNodes(p->right);
					flag = "RIGHT";
				}
			}
			p->key = r->key;
			
			if (flag == "LEFT") {
				 deleteBST(p->left, r->key);
			}
			else {
				deleteBST(p->right, r->key);
			}
		}
		return T;
	}

	int height(node* T) {
		if (T == NULL)
			return -1;
		
		else {
			int left_height = height(T->left);
			int right_height = height(T->right);

			return (left_height > right_height ? left_height : right_height) + 1;
		}
	}

	int noNodes(node* T) {
		if (T == NULL)
			return 0;
		else {
			return noNodes(T->left) + noNodes(T->right) + 1;
		}
	}
	node* minNodes(node* T) {
		node* min = T;
		while (min->left != NULL) {
			min = min->left;
		}
		return min;
	}
	node* maxNodes(node* T) {
		node* max = T;
		while (max->right != NULL) {
			max = max->right;
		}
		return max;
	}

	node* insertBST(node* T, int newKey) {
		node* p = T;
		node* q = NULL;
		while (p != NULL) {
			if (newKey == p->key)
				break;

			q = p;

			if (newKey < p->key)
				p = p->left;
			
			else
				p = p->right;
		}
		node* newNode = new node(newKey);

		if (T == NULL)
			T = newNode;
		else if (newKey < q->key) {
			newNode->parent = q;
			q->left = newNode;
		}
		else {
			newNode->parent = q;
			q->right = newNode;
		}
		return T;
	}
	void inorder(node* T) {
		if (T != NULL) {
			inorder(T->left);
			printf("%d ", T->key);
			inorder(T->right);
		}
	}
	void print(node* T) {
		printf("Inorder : "); T->inorder(T); printf("\n");
	}
	
	node* insertNode(node* T) {

		printf("Insert method\n");
		insertBST(T, 8);   print(T);
		insertBST(T, 18);	print(T);
		insertBST(T, 11);	print(T);
		insertBST(T, 5);	print(T);
		insertBST(T, 15);	print(T);
		insertBST(T, 4);	print(T);
		insertBST(T, 9);	print(T);
		insertBST(T, 1);	print(T);
		insertBST(T, 7);	print(T);
		insertBST(T, 17);	print(T);
		insertBST(T, 6);	print(T);
		insertBST(T, 14);	print(T);
		insertBST(T, 10);	print(T);
		insertBST(T, 3);	print(T);
		insertBST(T, 19);	print(T);
		insertBST(T, 20);	print(T);
		return T;
	}
	node* deleteNode1(node* T) {
		printf("Delete method1\n");
		print(T);
		deleteBST(T, 8);	print(T);
		deleteBST(T, 18);	print(T);
		deleteBST(T, 11);	print(T);
		deleteBST(T, 5);	print(T);
		deleteBST(T, 15);	print(T);
		deleteBST(T, 4);	print(T);
		deleteBST(T, 9);	print(T);
		deleteBST(T, 1);	print(T);
		deleteBST(T, 7);	print(T);
		deleteBST(T, 17);	print(T);
		deleteBST(T, 6);	print(T);
		deleteBST(T, 14);	print(T);
		deleteBST(T, 10);	print(T);
		deleteBST(T, 3);	print(T);
		deleteBST(T, 19);	print(T);
		deleteBST(T, 20);	print(T);
		return T;
	}
	node* deleteNode2(node* T) {
		printf("Delete method2\n");
		print(T);
		deleteBST(T, 20);	print(T);
		deleteBST(T, 19);	print(T);
		deleteBST(T, 3);	print(T);
		deleteBST(T, 10);	print(T);
		deleteBST(T, 14);	print(T);
		deleteBST(T, 6);	print(T);
		deleteBST(T, 17);	print(T);
		deleteBST(T, 7);	print(T);
		deleteBST(T, 1);	print(T);
		deleteBST(T, 9);	print(T);
		deleteBST(T, 4);	print(T);
		deleteBST(T, 15);	print(T);
		deleteBST(T, 5);	print(T);
		deleteBST(T, 11);	print(T);
		deleteBST(T, 18);	print(T);
		deleteBST(T, 8);	print(T);
		return T;
	}

};
int main() {

	node* bst =new node(0);
	bst = bst->insertNode(bst);
	bst = bst->deleteNode1(bst);
	bst = bst->insertNode(bst);
	bst = bst->deleteNode2(bst);
	return 0;
}
