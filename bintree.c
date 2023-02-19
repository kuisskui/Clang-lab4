#include <stdio.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *newNode(int data)
{
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return (node);
}

struct node *insert(struct node *node, int data)
{
    // 1. If the tree is empty, return a new, single node
    if (node == NULL)
    {
        return (newNode(data));
    }
    else
    {
        // 2. Otherwise, recur down the tree
        if (data <= node->data)
            node->left = insert(node->left, data);
        else
            node->right = insert(node->right, data);

        return (node); // return the (unchanged) node pointer
    }
}

void printTree(struct node *root, int level)
{
    int i;
    if (root != NULL)
    {
        printTree(root->right, level + 1);
        for (i = 0; i < level; i++)
            printf("  ");
        printf("%d", root->data);
        printf("\n");
        printTree(root->left, level + 1);
    }
}

int search(int x, struct node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    if (x == root->data)
    {
        return 1;
    }
    if (x > root->data)
    {
        return search(x, root->right);
    }
    if (x < root->data)
    {
        return search(x, root->left);
    }
}

int size(struct node *node)
{
    if (node == NULL)
    {
        return 0;
    }
    return 1 + size(node->left) + size(node->right);
}

int maxDepth(struct node *node)
{
    if (node == NULL)
    {
        return 0;
    }
    int left_node = 1 + maxDepth(node->left);
    int right_node = 1 + maxDepth(node->right);

    if (left_node > right_node)
    {
        return left_node;
    }
    return right_node;
}

int minValue(struct node *node)
{
    if (node->left == NULL)
    {
        return node->data;
    }
    return minValue(node->left);
}

void printPreOrder(struct node *node)
{
    if (node == NULL)
    {
        return;
    }
    printf("%d ", node->data);
    printPreOrder(node->left);
    printPreOrder(node->right);
}

void printPostorder(struct node *node)
{
    if (node == NULL)
    {
        return;
    }
    printPostorder(node->left);
    printPostorder(node->right);
    printf("%d ", node->data);
}

void printOrder(struct node *node)
{
    if (node == NULL)
    {
        return;
    }
    printOrder(node->left);
    printf("%d ", node->data);
    printOrder(node->right);
}

int sameTree(struct node *a, struct node *b)
{
    if (a == NULL && b == NULL)
    {
        return 1;
    }
    if (a->data == b->data)
    {
        return sameTree(a->right, b->right) && sameTree(a->left, b->left);
    }
    else
    {
        return 0;
    }
}

int main(int argc, char **argv)
{
    FILE *f, *f2;
    int i, i2;
    struct node *root;
    struct node *root2;
    root = NULL;
    root2 = NULL;
    f = fopen(argv[1], "r");
    while (fscanf(f, "%d", &i) != EOF)
    {
        root = insert(root, i);
    }

    f2 = fopen(argv[1], "r");
    while (fscanf(f2, "%d", &i2) != EOF)
    {
        root2 = insert(root2, i2);
    }

    root->left->data = 100000;
    printf("show root tree.\n");
    printTree(root, 0);
    printf("show root2 tree.\n");
    printTree(root2, 0);

    printf("Test search function.\n");
    if (search(58, root))
    {
        printf("It's found!\n");
    }
    else
    {
        printf("It's not found!\n");
    }
    if (search(93, root))
    {
        printf("It's found!\n");
    }
    else
    {
        printf("It's not found!\n");
    }
    if (search(2, root))
    {
        printf("It's found!\n");
    }
    else
    {
        printf("It's not found!\n");
    }
    if (search(93123123, root))
    {
        printf("It's found!\n");
    }
    else
    {
        printf("It's not found!\n");
    }

    printf("Test size function.\n");
    printf("node size: %d\n", size(root));
    printf("node size: %d\n", size(root->left));
    printf("node size: %d\n", size(root->right));
    printf("node size: %d\n", size(root->left->left));
    printf("node size: %d\n", size(root->right->right));

    printf("Test maxDepth function.\n");
    printf("max depth: %d\n", maxDepth(root));
    printf("max depth: %d\n", maxDepth(root->left));
    printf("max depth: %d\n", maxDepth(root->right));
    printf("max depth: %d\n", maxDepth(root->left->left));
    printf("max depth: %d\n", maxDepth(root->right->right));

    printf("Test minvalue function.\n");
    printf("min value: %d\n", minValue(root));
    printf("min value: %d\n", minValue(root->left));
    printf("min value: %d\n", minValue(root->right));
    printf("min value: %d\n", minValue(root->left->left));
    printf("min value: %d\n", minValue(root->right->right));

    printf("Test printPreOrder function.\n");
    printPreOrder(root);
    printf("\n");
    printPreOrder(root->left);
    printf("\n");
    printPreOrder(root->right);
    printf("\n");
    printPreOrder(root->left->left);
    printf("\n");
    printPreOrder(root->right->right);
    printf("\n");

    printf("Test printPreOrder function.\n");
    printPostorder(root);
    printf("\n");
    printPostorder(root->left);
    printf("\n");
    printPostorder(root->right);
    printf("\n");
    printPostorder(root->left->left);
    printf("\n");
    printPostorder(root->right->right);
    printf("\n");

    printf("Test printOrder function.\n");
    printOrder(root);
    printf("\n");
    printOrder(root->left);
    printf("\n");
    printOrder(root->right);
    printf("\n");
    printOrder(root->left->left);
    printf("\n");
    printOrder(root->right->right);
    printf("\n");

    printf("Test sameTree function.\n");
    printf("check: %d \n",sameTree(root, root2));
    if (sameTree(root, root))
    {
        printf("they are structurally identical.\n");
    }
    else
    {
        printf("they are not structurally identical.\n");
    }
    if (sameTree(root, root2))
    {
        printf("they are structurally identical.\n");
    }
    else
    {
        printf("they are not structurally identical.\n");
    }
    if (sameTree(root->left, root->left))
    {
        printf("they are structurally identical.\n");
    }
    else
    {
        printf("they are not structurally identical.");
    }
    if (sameTree(root->left, root2->left))
    {
        printf("they are structurally identical\n.");
    }
    else
    {
        printf("they are not structurally identical.\n");
    }
    if (sameTree(root->left->right, root->left))
    {
        printf("they are structurally identical\n.");
    }
    else
    {
        printf("they are not structurally identical.\n");
    }
    return 0;
}
