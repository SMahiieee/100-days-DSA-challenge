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

// Function to count nodes
int countNodes(struct node* head) {
    int count = 0;
    struct node* temp = head;

    while(temp != NULL) {
        count++;
        temp = temp->next;
    }

    return count;
}

int main() {
    int n, value;
    struct node *head = NULL, *temp = NULL, *newNode = NULL;

    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &value);
        newNode = createNode(value);

        if(head == NULL) {
            head = newNode;
        } else {
            temp->next = newNode;
        }

        temp = newNode;
    }

    // Count nodes
    int total = countNodes(head);
    printf("%d", total);

    return 0;
}