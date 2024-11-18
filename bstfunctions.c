
#include "bstconnect.h"
#include<stdlib.h>
#include<stdio.h>

struct node *create(int key, void *data, int type) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        fprintf(stderr,"malloc failed to allocate memory.\n");
        exit(EXIT_FAILURE);
    }
    newnode->key = key;
    newnode->type = type;
    newnode->data = data;
    newnode->left = newnode->right = NULL;
    return newnode;
}

struct node *insert(struct node *root, int key, void *data, int type) {
    if (root == NULL)
        return create(key, data, type);
    else if (key < root->key)
        root->left = insert(root->left, key, data, type);
    else if (key > root->key)
        root->right = insert(root->right, key, data, type);
    return root;
}

void print(void *data, int type) {
    switch (type) {
    case 1:
        printf("%d ", *(int *)data);
        break;
    case 2:
        printf("%.2f ", *(float *)data);
        break;
    case 3:
        printf("%c ", *(char *)data);
        break;
    case 4:
        struct newtype *nt = (struct newtype *)data;
        printf("{num: %d, score: %.2f, grade: %c}", nt->num, nt->score, nt->grade);
        break;
    default:
        printf("not valid data");
        break;
    }
}

void inorder(struct node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("Key: %d, Data: ", root->key);
        print(root->data, root->type);
        printf("\n");
        inorder(root->right);
    }
}


void preorder(struct node *root) {
    if (root != NULL) {
        printf("Key: %d, Data: ", root->key);
        print(root->data, root->type);
        printf("\n");
        preorder(root->left);
        preorder(root->right);
    }
}


void postorder(struct node *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("Key: %d, Data: ", root->key);
        print(root->data, root->type);
        printf("\n");
    } 
}

void free_mem(struct node * root)
{
    if(root==NULL)
    return;
    free_mem(root->left);
    free_mem(root->right);
    free(root->data);
    free(root);

}