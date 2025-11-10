#include <stdio.h>
#include <stdlib.h>

// Structure for a tree node
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

// Insert nodes in level order (simple binary tree)
struct Node* insert(struct Node* root, int value) {
    struct Node* newNode = createNode(value);
    if (root == NULL)
        return newNode;

    // Use a queue for level-order insertion
    struct Node* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear) {
        struct Node* temp = queue[front++];

        if (temp->left == NULL) {
            temp->left = newNode;
            return root;
        } else
            queue[rear++] = temp->left;

        if (temp->right == NULL) {
            temp->right = newNode;
            return root;
        } else
            queue[rear++] = temp->right;
    }

    return root;
}

// Inorder Traversal (Left, Root, Right)
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Preorder Traversal (Root, Left, Right)
void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Postorder Traversal (Left, Right, Root)
void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

// Search for an element in Binary Tree
void search(struct Node* root, int key, int *found) {
    if (root == NULL)
        return;

    if (root->data == key)
        *found = 1;

    search(root->left, key, found);
    search(root->right, key, found);
}

// Main function
int main() {
    struct Node* root = NULL;
    int n, value, key, found = 0;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }

    printf("\nInorder Traversal: ");
    inorder(root);

    printf("\nPreorder Traversal: ");
    preorder(root);

    printf("\nPostorder Traversal: ");
    postorder(root);

    printf("\n\nEnter element to search: ");
    scanf("%d", &key);

    search(root, key, &found);
    if (found)
        printf("Found\n");
    else
        printf("NULL\n");

    return 0;
}
