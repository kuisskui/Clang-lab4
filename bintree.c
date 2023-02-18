#include <stdio.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* newNode(int data) {
  struct node* node = (struct node*) malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;

  return(node);
}

struct node* insert(struct node* node, int data) {
  // 1. If the tree is empty, return a new, single node
  if (node == NULL) {
    return(newNode(data));
  }
  else {
    // 2. Otherwise, recur down the tree
    if (data <= node->data) node->left = insert(node->left, data);
    else node->right = insert(node->right, data);

    return(node); // return the (unchanged) node pointer
  }
}

void printTree(struct node* root, int level ) {
  int i;
  if (root != NULL) {
    printTree(root->right, level+1);
    for (i=0; i<level; i++) printf("  ");
    printf("%d", root->data);
    printf("\n");
    printTree(root->left, level+1);
  }
}

int main(int argc, char** argv) {
  FILE *f;
  int i;
  struct node *root;
  root = NULL;
  f = fopen(argv[1],"r");
  while (fscanf(f, "%d", &i) != EOF) {
    root = insert(root, i);
  }
  printTree(root, 0);
  return 0;
}
