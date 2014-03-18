#include <stdlib.h>
#include <stdio.h>

#define MAX 8

typedef struct Node
{
    int d;
    struct Node *lc, *rc;
}TNode;

void printH(TNode *r)
{
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
    return;
}

void link(TNode *root, TNode *h, TNode *t)
{
    TNode *lt = NULL, *rh = NULL;
 
    if (root->lc == NULL)
        t = root;
    else
    {
       link(root->lc, h, lt);
       lt->rc = root;
    }

    if (root->rc == NULL)
        h = root;
    else
    {
        link(root->rc, rh, t);
        root->rc = rh;
    }

    return;
}

int
main(int argc, char** argv)
{
    TNode *root, *p, *t, *h;
    int data[9] = {0, 7, 10, 6, 14, 4, 8, 12, 16}; 
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
    
    printf("[%d], [%d]\n", root->d, root->rc->d);
    printH(root);

    link(root, h, t);
    printL(root);

    return 0;
}
