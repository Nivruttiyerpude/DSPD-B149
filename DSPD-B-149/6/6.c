#include <stdio.h>
#include <stdlib.h>

// Structure for a BST node
struct Node {
    int data;
    struct Node *left, *right;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert an element into BST
struct Node* insert(struct Node* root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    else
        printf("Duplicate elements not allowed.\n");

    return root;
}

// Search for an element in BST
void search(struct Node* root, int key, int *found) {
    if (root == NULL)
        return;

    if (root->data == key) {
        *found = 1;
        return;
    } else if (key < root->data)
        search(root->left, key, found);
    else
        search(root->right, key, found);
}

// Delete a leaf node
struct Node* deleteLeaf(struct Node* root, int key) {
    if (root == NULL)
        return NULL;

    // If found the key
    if (root->data == key) {
        if (root->left == NULL && root->right == NULL) {
            free(root);
            printf("Leaf node deleted successfully.\n");
            return NULL;
        } else {
            printf("Not a leaf node. Only leaf nodes can be deleted.\n");
            return root;
        }
    }

    // Recur left or right
    root->left = deleteLeaf(root->left, key);
    root->right = deleteLeaf(root->right, key);
    return root;
}

// Inorder Traversal (for display)
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Main function
int main() {
    struct Node* root = NULL;
    int choice, value, key, found;

    while (1) {
        printf("\n\n Binary Search Tree Operations \n");
        printf("1. Search an element\n");
        printf("2. Insert an element\n");
        printf("3. Delete leaf element\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to search: ");
                scanf("%d", &key);
                found = 0;
                search(root, key, &found);
                if (found)
                    printf("Found\n");
                else
                    printf("NULL\n");
                break;

            case 2:
                printf("Enter element to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                printf("Inorder traversal: ");
                inorder(root);
                //printf("\n");
                break;

            case 3:
                printf("Enter leaf node value to delete: ");
                scanf("%d", &key);
                root = deleteLeaf(root, key);
                printf("Inorder traversal: ");
                inorder(root);
                //printf("\n");
                break;

            case 4:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
