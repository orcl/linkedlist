//
//  main.c
//  linkedlist
//
//  Created by Shipeng Xu on 1/25/13.
//  Copyright (c) 2013 Cuier. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

//for linked list implementation
//we first define a struct for it

typedef struct student
{
    int num;
    int score;
    struct student * next;
} STU;

//now we need to define the method to create a list
//create a linked list means we need to return a Node
   STU* create()
{
   //we need to have a head node
    STU* head = NULL;
    STU* tail = NULL;
    head = (STU *)malloc(sizeof(STU));
    if (head == NULL)
    {
        printf("Sorry, node applied failure.");
        return NULL;
    }
    head->next = NULL;
    tail = head;
    STU* pNewElement = NULL;
    int n,s;
    while (1)
    {
        printf("please enter the student's number and score.\n");
        scanf("%d%d", &n, &s);
        if (n>0 && s>0)
        {
            pNewElement = (STU*)malloc(sizeof(STU));
            if (pNewElement == NULL)
            {
                printf("node applied failure.");
                return NULL;
            }
            
            pNewElement->num = n;
            pNewElement->score = s;
            pNewElement->next = NULL;
            tail->next = pNewElement;
            tail = pNewElement;
        }
        else
        {
            break;
        }
    }//end while loop
    
    pNewElement=head;
    head = head->next;
    free(pNewElement);
    return head;
    
}//end create()

void display(STU* head)
{
    STU* p=NULL;
    
    //use a for loop to display all the nodes
    for (p = head; p!=NULL; p=p->next)
    {
        printf("student number is %d, score is %d\n", p->num, p->score);
    }
}

void freeall(STU* head)
{
    STU* p=NULL, *q = NULL;
    
    p=head;
    while (p->next!=NULL)
    {
        q =p->next;
        p->next = q->next;
        free(q);
    }
    //after the for loop, we have to free the head node
    free(head);
}


void main(void)
{
    STU* head = NULL;
    head = create();
    display(head);
    freeall(head);
   // display(head);
}



//method prepend

//method append

//method freeall

//method delete
