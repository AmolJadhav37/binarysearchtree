#include <stdio.h>
#include <stdlib.h>
#include"bstconnect.h"

struct node *tree = NULL;



int main() {
    while (1) {
        printf("Enter operation you want to perform\n");
        printf("1: Insert\n");
        printf("2: Inorder Traversal\n");
        printf("3: Preorder Traversal\n");
        printf("4: Postorder Traversal\n");
        printf("5: Exit\n");

        int choose_op;
        scanf("%d", &choose_op);

        switch (choose_op) {
        case 1: {
            int key;
            printf("Insert key for maintaining bst property: ");
            scanf("%d", &key);

            int choose_type;
            printf("Choose data type to insert:\n");
            printf("1: int\n");
            printf("2: float\n");
            printf("3: char\n");
            printf("4: structure (int, float, char)\n");
            scanf("%d", &choose_type);

            void *data;
            switch (choose_type) {
            case 1: {
                data = malloc(sizeof(int));
                if(data==NULL){
                fprintf(stderr,"failed to allocate memory.\n");
                exit(EXIT_FAILURE);
                }
                printf("Enter an integer: ");
                scanf("%d", (int *)data);
                tree = insert(tree, key, data, 1);
                break;
            }
            case 2: {
                data = malloc(sizeof(float));
                if(data==NULL){
                fprintf(stderr,"failed to allocate memory.\n");
                exit(EXIT_FAILURE);
                }
                printf("Enter a float: ");
                scanf("%f", (float *)data);
                tree = insert(tree, key, data, 2);
                break;
            }
            case 3: {
                data = malloc(sizeof(char));
                if(data==NULL){
                fprintf(stderr,"failed to allocate memory.\n");
                exit(EXIT_FAILURE);
                }
                printf("Enter a character: ");
                scanf(" %c", (char *)data);
                tree = insert(tree, key, data, 3);
                break;
            }
            case 4: {
                data = malloc(sizeof(struct newtype));
                if(data==NULL){
                fprintf(stderr,"failed to allocate memory.\n");
                exit(EXIT_FAILURE);
                }
                printf("Enter data for struct (int float char): ");
                struct newtype *nt = (struct newtype *)data;
                scanf("%d %f %c", &nt->num, &nt->score, &nt->grade);
                tree = insert(tree, key, data, 4);
                break;
            }
            default:
                printf("Please enter a valid data type.\n");
                break;
            }
            break;
        }
        case 2:
            inorder(tree);
            break;
        case 3:
            preorder(tree);
            break;
        case 4:
            postorder(tree);
            break;
        case 5:
        free_mem(tree);
            return 0;
        default:
            printf("Please enter a correct choice\n");
            break;
        }
    }
}
