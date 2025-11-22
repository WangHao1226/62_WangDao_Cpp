// 根据后序遍历序列和中序遍历序列构建 BST (元素类型为int)。

// BST* build_tree(const int* preorder, const int* inorder, int n);

#include<stdio.h>
#include<stdlib.h>

typedef struct tree_node{
    int key;
    struct tree_node* left;
    struct tree_node* right;
}TreeNode;

typedef struct{
    TreeNode* root;
}BST;

static int find_index(const int* arr,int start,int end,int value){
    for(int i=start;i<=end;i++){
        if(arr[i]==value){
            return i;
        }
    }
    return -1;
}

static TreeNode* build_tree_helper(
    const int* postorder,
    const int* inorder,
    int in_start,
    int in_end,
    int* post_index
){
    if(in_start>in_end){
        return NULL;
    }

    TreeNode* node=(TreeNode*)malloc(sizeof(TreeNode));
    node->key=postorder[*post_index];
    node->left=NULL;
    node->right=NULL;
    (*post_index)--;

    if(in_start==in_end){
        return node;
    }

    int in_index=find_index(inorder,in_start,in_end,node->key);

    node->right=build_tree_helper(postorder,inorder,in_index+1,in_end,post_index);
    node->left=build_tree_helper(postorder,inorder,in_start,in_index-1,post_index);

    return node;
}

BST* build_tree(const int* postorder,const int* inorder,int n){
    if(n==0||postorder==NULL||inorder==NULL){
        BST* empty_tree=(BST*)malloc(sizeof(BST));
        empty_tree->root=NULL;
        return empty_tree;
    }

    int post_index=n-1;

    BST* tree=(BST*)malloc(sizeof(BST));

    tree->root=build_tree_helper(postorder,inorder,0,n-1,&post_index);

    return tree;
}

// 示例：中序遍历打印（验证用）
void inorder_print(TreeNode* root) {
    if (root == NULL) return;
    inorder_print(root->left);
    printf("%d ", root->key);
    inorder_print(root->right);
}

// 释放树内存的辅助函数
static void free_tree_helper(TreeNode* node) {
    if (node == NULL) return;
    free_tree_helper(node->left);
    free_tree_helper(node->right);
    free(node);
}

// 释放整个BST
void bst_destroy(BST* tree) {
    if (tree == NULL) return;
    free_tree_helper(tree->root);
    free(tree);
}

int main() {
    // 示例序列
    int inorder[] = {4, 2, 5, 1, 6, 3, 7};
    int postorder[] = {4, 5, 2, 6, 7, 3, 1};
    int n = sizeof(inorder) / sizeof(inorder[0]);
    
    // 构建二叉树
    BST* tree = build_tree(postorder, inorder, n);
    
    // 验证：打印中序遍历结果
    printf("Inorder traversal: ");
    inorder_print(tree->root);
    printf("\n");
    
    // 清理内存
    bst_destroy(tree);
    return 0;
}
