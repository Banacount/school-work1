#include <cstdlib>
#include <stdio.h>

typedef struct Node {
    int data;
    Node *next;
} node;

void printHeader ();
void printLinkedList (node * node_pointer);
Node * createNode (int data);
int freeHead (node * head_pointer);
// Node operations
int deleteEnd (node * head_pointer);
int deleteHead (node ** head_pointer);
int appendNode (node * head_pointer, int value);
int insertHead (node ** head_pointer, int value);

int main () {
    int user_decision = 0, value_input = 0;
    node *head = createNode(12);
    node *nodenum1 = createNode(22);
    node *nodenum2 = createNode(32);
    node *nodenum3 = createNode(42);
    head->next = nodenum1;
    nodenum1->next = nodenum2;
    nodenum2->next = nodenum3;
    nodenum3->next = NULL;

    printHeader();
    while (true) {
        printf("Enter your choice: ");
        scanf("%d", &user_decision);

        if (user_decision == 1) {
            printf("Insert value at the beginning: ");
            scanf("%d", &value_input);
            insertHead(&head, value_input);
        } else if (user_decision == 2) {
            printf("Insert value at the end: ");
            scanf("%d", &value_input);
            appendNode(head, value_input);
        } else if (user_decision == 3) {
            deleteHead(&head);
        } else if (user_decision == 4) {
            deleteEnd(head);
        } else if (user_decision == 5) {
            printLinkedList(head);
        } else if (user_decision == 6) {
            printf("Exitting..\n");
            break;
        } else {
            printf("Invalid command.\n");
            break;
        }
    }

    freeHead(head);
    return 0;
}

void printLinkedList (node * node_pointer) {
    node * temp = node_pointer;
    
    while (temp->next != NULL) {
        printf(" %d ->", temp->data);
        temp = temp->next;
    }
    printf(" %d\n", temp->data);
}

Node * createNode (int data) {
    node * node_pointer = (node *)malloc(sizeof(node));
    node_pointer->data = data;
    node_pointer->next = NULL;
    return node_pointer;
};

int freeHead (node * head_pointer) {
    //for testing purposes
    //int deep_num = 1;

    node *next_addr = head_pointer->next;
    node *cur_addr = head_pointer;
    //printf("Clearing link number head with a value of '%d'.\n", head_pointer->data);
    free(cur_addr);

    while (next_addr != NULL) {
        //printf("Clearing link number [ %d ] with a value of '%d'.\n", deep_num, next_addr->data);
        //deep_num++;
        cur_addr = next_addr;
        next_addr = cur_addr->next;
        free(cur_addr);
    }

    return 0;
}

void printHeader () {
    printf("<-- Action menu -->\n");
    printf("1. Insert at the beginning.\n");
    printf("2. Insert at the end.\n");
    printf("3. Delete at beginning.\n");
    printf("4. Delete at end.\n");
    printf("5. Display list.\n");
    printf("6. Exit\n\n");
}

int deleteEnd (node * head_pointer) {
    if (head_pointer->next == NULL) return 2;

    node *end = head_pointer;
    while (end->next->next != NULL) {
        end = end->next;
    }

    free(end->next);
    end->next = NULL;
    return 0;
}

int deleteHead (node ** head_pointer) {
    if ((**head_pointer).next == NULL) return 2;

    node *temp = *head_pointer;
    *head_pointer = (**head_pointer).next;
    free(temp);
    return 0;
}

int appendNode (node * head_pointer, int value) {
    node *temp = head_pointer;
    
    while (temp->next != NULL) {
        temp = temp->next;
    }

    node *newNode = createNode(value);
    temp->next = newNode;
    return 0;
}

int insertHead (node ** head_pointer, int value) {
    node *newHead = createNode(value);
    newHead->next = *head_pointer;
    *head_pointer = newHead;
    return 0;
}
