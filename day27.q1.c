 #include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

struct Node* insertEnd(struct Node* head, int data) {
    struct Node* node = createNode(data);
    if (head == NULL) return node;
    struct Node* temp = head;
    while (temp->next != NULL) temp = temp->next;
    temp->next = node;
    return head;
}

int getLength(struct Node* head) {
    int len = 0;
    while (head != NULL) {
        len++;
        head = head->next;
    }
    return len;
}

struct Node* findIntersection(struct Node* l1, struct Node* l2) {
    int n1 = getLength(l1);
    int n2 = getLength(l2);

    int diff = abs(n1 - n2);

    if (n1 > n2) {
        for (int i = 0; i < diff; i++) l1 = l1->next;
    } else {
        for (int i = 0; i < diff; i++) l2 = l2->next;
    }

    while (l1 != NULL && l2 != NULL) {
        if (l1->data == l2->data) return l1;
        l1 = l1->next;
        l2 = l2->next;
    }

    return NULL;
}

int main() {
    int n, m, x;
    struct Node* l1 = NULL;
    struct Node* l2 = NULL;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        l1 = insertEnd(l1, x);
    }

    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &x);
        l2 = insertEnd(l2, x);
    }

    struct Node* res = findIntersection(l1, l2);

    if (res != NULL) printf("%d", res->data);
    else printf("No Intersection");

    return 0;
}