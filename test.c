#include "push_swap.h"



// Function to merge two sorted linked lists
stack* merge(stack* first, stack* second) {
    if (!first)
        return second;
    if (!second)
        return first;

    if (first->data < second->data) {
        first->next = merge(first->next, second);
        return first;
    } else {
        second->next = merge(first, second->next);
        return second;
    }
}

// Function to find the middle of a linked list
stack* findMiddle(stack* head) {
    stack* slow = head;
    stack* fast = head->next;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

// Merge Sort function for linked list
stack* mergeSort(stack** head) {
    if (!(*head) || !(*head)->next)
        return (*head);

    stack* middle = findMiddle(*head);
    stack* secondHalf = middle->next;
    middle->next = NULL;

    stack* firstHalf = mergeSort(head);
    secondHalf = mergeSort(secondHalf);

    return merge(firstHalf, secondHalf);
}

// Function to print the linked list
// void printList(stack* node) {
//     while (node) {
//         printf("%d -> ", node->data);
//         node = node->next;
//     }
//     printf("NULL\n");
// }

// Function to insert a new node at the end of the linked list
// void insert(stack** head, int data) {
//     stack* newNode = (stack*)malloc(sizeof(stack));
//     newNode->data = data;
//     newNode->next = NULL;

//     if (!*head) {
//         *head = newNode;
//         return;
//     }

//     stack* temp = *head;
//     while (temp->next)
//         temp = temp->next;

//     temp->next = newNode;
// }
