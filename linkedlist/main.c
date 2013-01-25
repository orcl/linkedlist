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

typedef struct node
{
    int num;
    struct node * next;
} Node;

//now we need to define the method to create a list
   Node* create()
{
   //we need to have a head node
    Node* head = NULL;
    head = (Node *)malloc(sizeof(Node));
    if (head == NULL)
    {
        printf("Sorry, node applied failure.");
        return NULL;
    }
    
    
    
    
    
    
}




//method prepend

//method append

//method freeall

//method delete
