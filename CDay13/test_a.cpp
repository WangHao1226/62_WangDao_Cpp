// 实现 BST 的下列 API:

// typedef char K;

// typedef struct tree_node {
// 	K key;
// 	struct tree_node* left;
// 	struct tree_node* right;
// } TreeNode;

// typedef struct {
// 	TreeNode* root;
// } BST;

// void bst_inorder(BST* tree);
// void bst_postorder(BST* tree);
// void bst_destroy(BST* tree);

#include<stdio.h>
#include<stdlib.h>

typedef char K;
typedef struct tree_node{
    K key;
    struct tree_node* left;
    struct tree_node* right;
}TreeNode;

typedef struct{
    TreeNode* root;
}BST;

static void inorder_helper(TreeNode* node){
    if(node==NULL) return;
    inorder_helper(node->left);
    printf("%c",node->key);
    inorder_helper(node->right);
}

static void postorder_helper(TreeNode* node){
    if(node==NULL) return;
    postorder_helper(node->left);
    postorder_helper(node->right);
    printf("%c",node->key);
}

static void destroy_helper(TreeNode* node){
    if(node==NULL) return;
    destroy_helper(node->left);
    destroy_helper(node->right);
    free(node);
}

void bst_inorder(BST* tree){
    inorder_helper(tree->root);
    printf("\n");
}

void bst_postorder(BST* tree){
    postorder_helper(tree->root);
    printf("\n");
}

void bst_destroy(BST* tree){
    destroy_helper(tree->root);
    tree->root=NULL;
}

int main() {
    // 创建BST并插入节点(需自行实现插入函数)
    BST tree = {NULL};
    
    // 示例操作
    bst_inorder(&tree);    // 打印中序序列
    bst_postorder(&tree);  // 打印后序序列
    bst_destroy(&tree);    // 销毁树
    
    return 0;
}

