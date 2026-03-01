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

// Function to count occurrences
int countOccurrences(struct node* head, int key) {
    int count = 0;
    struct node* temp = head;

    while(temp != NULL) {
        if(temp->data == key)
            count++;
        temp = temp->next;
    }

    return count;
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

    // Count occurrences
    int result = countOccurrences(head, key);
    printf("%d", result);

    return 0;
}