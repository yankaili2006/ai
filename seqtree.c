#include <stdlib.h>
#include <stdio.h>

#define MAX 8

typedef struct Node
{
    int d;
    struct Node *lc, *rc;
}TNode;

void printH(TNode *root)
{
    TNode *r = root;
    TNode *nl[9] = {NULL};
    int h=0, t=0;
    if (r == NULL)
        return;

    nl[t] = r;
    t++;
    
    while(h < t)
    {
        r = nl[h];
        h++;
        printf("%d\t", r->d);
        if (r->lc != NULL)
            nl[t++] = r->lc;
        if (r->rc != NULL)
            nl[t++] = r->rc;
    }

    printf("\n");
    return;
}

void printL(TNode *root)
{
    while(root != NULL)
    {
         printf("%d\t", root->d);
         root = root->rc;
    }
    printf("\n");

    return;
}

TNode* link(TNode *root, TNode **h, TNode **t)
{
    TNode *lt, *rh;
 
    /* printf("root->d = [%d]\n", root->d); */
    if (root->lc == NULL)
        *h = root;
    else
    {
       link(root->lc, h, &lt);
       /* printf("root->d = [%d], *h = [%p], *h->d = [%d], lt = [%p], lt->d = [%d]\n", root->d, *h, (*h)->d, lt, lt->d); */
       lt->rc = root;
       root->lc = lt;
    }

    if (root->rc == NULL)
        *t = root;
    else
    {
        link(root->rc, &rh, t);
        /* printf("root->d = [%d], rh = [%p], *t = [%p]\n", root->d, rh, *t); */
        root->rc = rh;
        rh->lc = root;
    }
    /* printf("root->d = [%d], *h->d = [%d], *t->d = [%d]\n", root->d, (*h)->d, (*t)->d); */

    return *h;
}

int
main(int argc, char** argv)
{
    TNode *root, *p, *t, *h, *lh;
    int data[9] = {0, 10, 6, 14, 4, 8, 12, 16, 1}; 
    TNode *nl[9] = {NULL};
    int i=0;

    for(i=MAX; i>0; i--)
    {
        p = (TNode*)malloc(sizeof(TNode));
        if(2*i > MAX)
            p->lc = p->rc = NULL;
        else
            p->lc = nl[2*i];

        if(2*i + 1 > MAX)
            p->rc = NULL;
        else
            p->rc = nl[2*i + 1];
        p->d = data[i];
        nl[i] = p;
    }
    root = nl[1];
    
    printH(root);

    lh = link(root, &h, &t);
    printL(lh);

    return 0;
}
