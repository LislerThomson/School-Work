/*******************************************************************************************
* File Name          : Assignment1.cpp
* Description        : Prog8130 - Assignment 1: Linked Lists
*					   This program uses linked lists to hold and print a list of words
*					   organized by index number assosciated with each word. Each word can
*					   consist of maximum 30 characters.
*
* Author:              Lisler Thomson Pulikkottil / Allan Smith
* Date:                2018/10/02
********************************************************************************************/

#include "pch.h" // my version of Visual studio gave me an error when i tried include
				 // "stdafx.h". That error  was resolved when i added "pch.h"
//#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUMBER_OF_DATA_ITEMS   10					// the number of data items to be used in list

// structure/typedef used for holding data
typedef struct {
	char name[30];
	int index;
} inputData;

// definition of linked list data nodes
typedef struct LinkedListNode {
	struct LinkedListNode		*ptrNextNode;		// pointer to next node in list (NULL if the end)
	char						NameData[30];		// the name to be stored (no need to store index)
} LinkedListNodeDef;

// prototypes
LinkedListNodeDef *AddToLinkedList(LinkedListNodeDef *ptrHead, char *NameData, int DataIndex);
void PrintLinkedList(LinkedListNodeDef *ptrHead);
void insertAtEnd(LinkedListNodeDef **ptrHead, char *NameData);
void insertAtTop(LinkedListNodeDef **ptrHead, char *NameData);
void create(LinkedListNodeDef **ptrHead, char *NameData);
void insertAtIndex(LinkedListNodeDef **ptrHead, char *NameData, int DataIndex);

// make the data positions the last 5 digits of student number
// for example if my student number ended in 94330 the data will be as supplied

// data used for test 
// last 4 digits of my student number as requested by the data creater, 8212565
inputData iData[10] = {
		{ "car", 6 },
		{ "orange", 7 },
		{ "carrot", 7 },
		{ "candy", 8 },
		{ "milk", 7 },
		{ "chocolate", 3 },
		{ "snake", 7 },
		{ "airplane", 1 },
		{ "water", 9 },
		{ "butter", 8 }
};

void main(void) {
	int i;

	// define linked list head
	LinkedListNodeDef *ptrHead = NULL;

	// Print out the input data
	printf("Data before Linked List is:\n");
	printf("====================================\n");
	for (i = 0; i < NUMBER_OF_DATA_ITEMS; i++)
		printf("%s , %d\n", iData[i].name, iData[i].index);
	printf("\n\n");

	// insert the data into Linked List
	for (i = 0; i < NUMBER_OF_DATA_ITEMS; i++)
		ptrHead = AddToLinkedList(ptrHead, iData[i].name, iData[i].index);

	// now print out the list in order it is stored starting at head
	printf("Data after Linked List is: \n");
	printf("====================================\n");
	PrintLinkedList(ptrHead);
}

// FUNCTION      : AddToLinkedList()
// DESCRIPTION   : This function takes an input of Data of 30 Char word and an index and 
//				   places them in a linked list organized by priority of index number. 
// PARAMETERS    : LinkedListNodeDef *ptrHead	- variable to store address of ptrHead
//				   char *NameData				- Array of Characters with data 
//		           int DataIndex				- Index of data
// RETURNS       : possibly updated pointer to the head of the list
LinkedListNodeDef *AddToLinkedList(LinkedListNodeDef *ptrHead, char *NameData, int DataIndex) {
	static int nodeCount = 0;
	if (DataIndex == 0 || DataIndex == 1)
	{
		insertAtTop(&ptrHead, NameData);
		nodeCount++;
	}
	else if (DataIndex > nodeCount)
	{
		insertAtEnd(&ptrHead, NameData);
		nodeCount++;
	}
	else
	{
		insertAtIndex(&ptrHead, NameData, DataIndex);
		nodeCount++;
	}
	return ptrHead;
}

// FUNCTION      : insertAtIndex()
// DESCRIPTION   : This function inserts the data to the index spacified  
// PARAMETERS    : LinkedListNodeDef **ptrHead	- pointer to the ptrHead
//				   char *NameData				- Array of Characters with data 
//		           int DataIndex				- Index of data
// RETURNS       : void
void insertAtIndex(LinkedListNodeDef **ptrHead, char* NameData, int DataIndex) {
	if (ptrHead != NULL) {
		LinkedListNodeDef *ptrCurrent = *ptrHead;
		int i = 1;

		while (i < (DataIndex - 1)) {
			ptrCurrent = ptrCurrent->ptrNextNode;
			i++;
		}
		LinkedListNodeDef *newNode = NULL; // creates a new node
		
		newNode = (LinkedListNode*)malloc(sizeof(LinkedListNode)); // allocate memory of to the node
		if (newNode == NULL) {
			printf("ERROR!!!!!! Out of memory!!!! \n");
			exit(1);
		}
		
		strcpy_s(newNode->NameData, NameData); // copy the given data in the list	
		newNode->ptrNextNode = ptrCurrent->ptrNextNode;
		ptrCurrent->ptrNextNode = newNode;
	}
	else {
		create(ptrHead, NameData);
	}
}

// FUNCTION      : create()
// DESCRIPTION   : This function creates a new node and stores data into it.  
// PARAMETERS    : LinkedListNodeDef **ptrHead	- pointer to the ptrHead
//				   char *NameData				- Array of Characters with data 
// RETURNS       : void
void create(LinkedListNodeDef **ptrHead, char *NameData) {
	LinkedListNodeDef *newNode = NULL; // creates a new node

	newNode = (LinkedListNode*)malloc(sizeof(LinkedListNode)); // allocate memory of to the node		
	if (newNode == NULL) {
		printf("ERROR!!!!!! Out of memory!!!! \n");
		exit(1);
	}

	strcpy_s(newNode->NameData, NameData); // copy the given data in the list				
	newNode->ptrNextNode = *ptrHead;
	*ptrHead = newNode;
}

// FUNCTION      : insertAtTop()
// DESCRIPTION   : This function inserts data to the top of the linked list  
// PARAMETERS    : LinkedListNodeDef **ptrHead	- pointer to the ptrHead
//				   char *NameData				- Array of Characters with data 
// RETURNS       : void
void insertAtTop(LinkedListNodeDef **ptrHead, char *NameData) {
	if (*ptrHead != NULL) {
		LinkedListNodeDef *newNode = NULL; // creates a new node

		newNode = (LinkedListNode*)malloc(sizeof(LinkedListNode)); // allocates memory to the new node
		if (newNode == NULL) {
			printf("ERROR!!!!!! Out of memory!!!! \n");
			exit(1);
		}

		strcpy_s(newNode->NameData, NameData); // store the data in the new node		
		newNode->ptrNextNode = *ptrHead;
		*ptrHead = newNode;
	}
	else {
		create(ptrHead, NameData);
	}
}

// FUNCTION      : insertAtEnd()
// DESCRIPTION   : This function inserts data at the end of the linked list 
// PARAMETERS    : LinkedListNodeDef **ptrHead	- pointer to the ptrHead
//				   char *NameData				- Array of Characters with data 
// RETURNS       : void
void insertAtEnd(LinkedListNodeDef **ptrHead, char *NameData) {
	if (*ptrHead != NULL) {
		LinkedListNodeDef *currentNode = *ptrHead; // create new node

		while (currentNode->ptrNextNode != NULL) { // find the last node in the list
			currentNode = currentNode->ptrNextNode;
		}

		currentNode->ptrNextNode = (LinkedListNode*)malloc(sizeof(LinkedListNode));
		if (currentNode->ptrNextNode == NULL) {
			printf("ERROR!!!!!! Out of memory!!!! \n");
			exit(1);
		}

		strcpy_s(currentNode->ptrNextNode->NameData, NameData);
		currentNode->ptrNextNode->ptrNextNode = NULL;
	}
	else {
		create(ptrHead, NameData);
	}
}

// FUNCTION      : PrintLinkedList()
// DESCRIPTION   : This function takes an input of the head of the linked list, then loops through
//				   and prints each word in the linked list until the ptrNextNode is NULL.
// PARAMETERS    : LinkedListNodeDef *ptrHead 
// RETURNS       : void
void PrintLinkedList(LinkedListNodeDef *ptrHead) {
	LinkedListNodeDef *printNode = ptrHead;
	while (1) {
		if (printNode == NULL) break;
		printf("%s\n", printNode->NameData);
		printNode = printNode->ptrNextNode;
	}
	printf("\n");
}
