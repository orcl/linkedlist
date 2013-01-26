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
        printf("student %d is going to be deleted\n",q->num);
        free(q);
        
    }
    //after the for loop, we have to free the head node
    printf("student %d is going to be deleted\n",head->num);
    free(head);
    head = NULL;
}


STU* reverse(STU* head)
{
    STU* p1=NULL, *p2=NULL, *p3=NULL;
    
    if (head ==NULL||head->next==NULL)
    {
        return head;
    }
   
    p1=head;
    p2=p1->next;
    while (p2!=NULL)
    {
        p3=p2->next;
        p2->next = p1;
        p1=p2;
        p2=p3;
        
    }
    head->next = NULL;//adjust the head next pointer to null
    head = p1; //this time the head is on the other end now.
    return head; //return head.
    
}//end reverse

STU* del(STU* head, int num)
{
    STU* p1 =NULL, *p2 = NULL;
    p1=head;
    
    //this while loop is for finding the position
    while(num!=p1->num && p1->next!=NULL)
    {
        p2 = p1;
        p1 = p1->next;
    }
    
    //check if it's the node to be deleted.
    if (num==p1->num)
    {
        if (p1==head) //if the node we found is the head, update the head, then delete p1 node.
        {
            head = p1->next;
            free(p1);
        }
        else          //if the node we found is not the head, we simply just delete p1 node
        {
            p2->next = p1->next;
            free(p1);
        }
    }
    else
    {
        printf("can't find the node\n");
    }
    
    return head;
}

STU* append(STU* head, STU* t)
{
    STU* p=NULL;
    
    //we need to find the last node
    p = head;
    while (p->next!=NULL)
    {
        p = p->next;
    }
    
    //add the node at the end
    p->next = t;
    t->next = NULL;
    return head;
    
}//end append


STU* prepend(STU* head, STU* t)
{
    //we need to append the node at the beginning of the list
    t->next = head;
    head = t;
    return head;
}


void main(void)
{
    STU* head = NULL;
    STU* head1 = NULL;
    STU* head2 = NULL;
    head1 = (STU*)malloc(sizeof(STU));
    head1->num = 4;
    head1->score = 96;
    head1->next = NULL;
    
    head2 = (STU*)malloc(sizeof(STU));
    head2->num = 5;
    head2->score =95;
    head2->next =NULL;
    
    head = create();
    display(head);
    //head = reverse(head);
    //display(head);
   // head = del(head, 3);
   // display(head);
    
    head = append(head, head1);
   // display(head);
    printf("------------------------------------------\n");
   
    head = prepend(head, head2);
    display(head);
    
    
    freeall(head);
    display(head);
}



