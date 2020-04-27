#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int expn;
    int coef;
    struct Node *next;
} Node;

void * createPolyn() {
    Node *header = (Node *)malloc(sizeof(Node));
    header->next = NULL;
    
    for (int i = 0; i < 8; i++) {
        int expn = rand() % 20;
        int coef = rand() % 30;
        
        Node *p = header;
        Node *n = header->next;
        while (n != NULL && expn > n->expn) {
            p = n;
            n = p->next;
        }
        
        if (n != NULL && n->expn == expn) {
            n->coef += coef;
        } else {
            Node *newNode = (Node *)malloc(sizeof(Node));
            newNode->expn = expn;
            newNode->coef = coef;
            
            p->next = newNode;
            newNode->next = n;
        }
    }
    
    return header;
}

void printPolyn(Node *header) {
    printf("多项式：");
    Node *p = header->next;
    while (p!= NULL) {
        printf("%d^%d", p->coef, p->expn);
        if (p->next != NULL) {
            printf(" + ");
        }
        p = p->next;
    }
    printf("\n");
}

void * addPolyn(Node *p1, Node *p2) {
    Node *header = (Node *)malloc(sizeof(Node));
    header->next = NULL;
    
    Node *pA = p1->next;
    Node *pB = p2->next;
    Node *p = header;
    
    while (pA != NULL && pB != NULL) {
        int eA = pA->expn;
        int eB = pB->expn;
        
        if (eA < eB) {
            p->next = pA;
            pA = pA->next;
        } else if (eA == eB) {
            pA->coef += pB->coef;
            
            p->next = pA;
            pA = pA->next;
            pB = pB->next;
        } else {
            p->next = pB;
            pB = pB->next;
        }
        p = p->next;
    }
    
    p->next = pA != NULL ? pA : pB;
    
    return header;
}

int main() {
    Node *p1 = createPolyn();
    Node *p2 = createPolyn();
    
    printPolyn(p1);
    printPolyn(p2);
    
    Node *result = addPolyn(p1, p2);
    printPolyn(result);
    
    return 0;
}
