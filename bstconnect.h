#ifndef BSTFUN_H
#define BSTFUN_H
struct node {
    int key;
    int type;
    void *data;
    struct node *left;
    struct node *right;
};

struct newtype {
    int num;
    float score;
    char grade;
};

struct node *create(int key, void *data, int type);
struct node *insert(struct node *root, int key, void *data, int type);
void print(void *data, int type);
void inorder(struct node *root);
void preorder(struct node *root);
void postorder(struct node *root); 
void free_mem(struct node * root);
#endif