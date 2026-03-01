#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node* next;
};
struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
int main() {
    int n, value;
    struct node *head = NULL, *temp = NULL, *newNode = NULL;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &value);
        newNode = createNode(value);

        if(head == NULL) {
            head = newNode;   // First node
        } else {
            temp->next = newNode;  // Link previous node to new node
        }

        temp = newNode;  // Move temp forward
    }

    // Traverse and print the linked list
    temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}