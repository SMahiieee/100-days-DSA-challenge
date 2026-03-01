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

// Function to merge two sorted lists
struct node* mergeLists(struct node* head1, struct node* head2) {
    struct node *result = NULL, *temp = NULL;

    while(head1 != NULL && head2 != NULL) {
        struct node* newNode;

        if(head1->data <= head2->data) {
            newNode = createNode(head1->data);
            head1 = head1->next;
        } else {
            newNode = createNode(head2->data);
            head2 = head2->next;
        }

        if(result == NULL) {
            result = newNode;
        } else {
            temp->next = newNode;
        }

        temp = newNode;
    }

    // Copy remaining elements
    while(head1 != NULL) {
        temp->next = createNode(head1->data);
        temp = temp->next;
        head1 = head1->next;
    }

    while(head2 != NULL) {
        temp->next = createNode(head2->data);
        temp = temp->next;
        head2 = head2->next;
    }

    return result;
}

int main() {
    int n, m, value;
    struct node *head1 = NULL, *head2 = NULL, *temp = NULL, *newNode;

    // First list
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &value);
        newNode = createNode(value);

        if(head1 == NULL)
            head1 = newNode;
        else
            temp->next = newNode;

        temp = newNode;
    }

    // Reset temp
    temp = NULL;

    // Second list
    scanf("%d", &m);
    for(int i = 0; i < m; i++) {
        scanf("%d", &value);
        newNode = createNode(value);

        if(head2 == NULL)
            head2 = newNode;
        else
            temp->next = newNode;

        temp = newNode;
    }

    // Merge lists
    struct node* merged = mergeLists(head1, head2);

    // Print merged list
    temp = merged;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}