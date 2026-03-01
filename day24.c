#include <stdio.h>
#include <stdlib.h>

// Structure of node
struct node {
    int data;
    struct node* next;
};

// Create new node
struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Delete first occurrence of key
struct node* deleteKey(struct node* head, int key) {

    // If list is empty
    if(head == NULL)
        return head;

    // If head itself holds the key
    if(head->data == key) {
        struct node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    struct node* temp = head;
    struct node* prev = NULL;

    // Traverse to find key
    while(temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // If key not found
    if(temp == NULL)
        return head;

    // Remove node
    prev->next = temp->next;
    free(temp);

    return head;
}

int main() {
    int n, value, key;
    struct node *head = NULL, *temp = NULL, *newNode = NULL;

    scanf("%d", &n);

    // Create linked list
    for(int i = 0; i < n; i++) {
        scanf("%d", &value);
        newNode = createNode(value);

        if(head == NULL)
            head = newNode;
        else
            temp->next = newNode;

        temp = newNode;
    }

    // Input key
    scanf("%d", &key);

    // Delete key
    head = deleteKey(head, key);

    // Print updated list
    temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}