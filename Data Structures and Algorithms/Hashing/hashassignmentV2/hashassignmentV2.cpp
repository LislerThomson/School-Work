/*******************************************************************************
* File Name          : hashAssignmentV2.cpp
* Description        : Implemenation of a hash skelleton
*
* Author:              PROG8130 / Lisler Thomson Pulikkottil
* Date:                Dec 09, 2018
******************************************************************************
*/

#include "stdafx.h"
#include <string.h>
#include <stdlib.h>
#include <string.h>

unsigned int putIntoHashTable(char *ptrInputData, unsigned int bufferLength);    // function to add to hash table
unsigned int getFromHashTable(char *ptrOutputData, unsigned int bufferLength);   // function to retrieve data from hash table

#define INPUT_BUFFER_SIZE         200             // local buffer used for adding data to the hash table (there is no reason in this assignment to change this value)

#define HASH_SIZE    100                          // size of hash table to be used (for testing I suggest making this number much lower)

												  // data structure used to keep track of hashed data
struct myHashStruct {
	char *ptrBuffer = NULL;                       // pointer to data stored in hash (you will need to malloc space for string to be stored)
	struct myHashStruct *ptrNextHashData = NULL;  // pointer to next item in this hash bucket (or NULL if no more)
};

struct myHashStruct *myHash[HASH_SIZE];           // create an empty hash table structure (note this is basically an arrary of linked list heads)

int main()
{
	char    inputBuffer[INPUT_BUFFER_SIZE];

	// initialize the hash table to empty one
	for (int i = 0; i < HASH_SIZE; i++)
	{
		if ((myHash[i] = (struct myHashStruct *)calloc(1, sizeof(struct myHashStruct))) == NULL)
		{
			printf("calloc failed!\n");
			return(-1);
		}
	}

	// add to hash table loop
	while (1)
	{
		printf("enter data to be added to hash table or exit when done\n");

		// get strings from the console and place in hash until nothing entered
		scanf_s("%s", inputBuffer, INPUT_BUFFER_SIZE);

		// stop adding data into hash table when "exit" is entered
		if (strcmp(inputBuffer, "exit") == 0)
			break;

		if (putIntoHashTable(inputBuffer, strlen(inputBuffer)) == HASH_SIZE)
			printf("Error putting into hash table\n");
	}

	// check if data is in hash table
	while (1)
	{
		unsigned int hashIndexNumber = 0;

		printf("Enter data to find, done when complete\n");

		// get strings from the console and check if in hash table
		scanf_s("%s", inputBuffer, INPUT_BUFFER_SIZE);

		// stop adding data into hash table when "done" is entered
		if (strcmp(inputBuffer, "done") == 0)
			break;

		if ((hashIndexNumber = getFromHashTable(inputBuffer, strlen(inputBuffer))) == HASH_SIZE)
			printf("%s not found in hash table\n", inputBuffer);
		else
			printf("%s found in hash table at %u\n", inputBuffer, hashIndexNumber);
	}

	return 0;
}

// FUNCTION      : myHashFunction
// DESCRIPTION   :
//   Calculate a hash value to use in storing the data into the hash table
// PARAMETERS    :
//   ptrInputBuffer - a pointer to the buffer to be put into the hash table
//
// RETURNS       :
//   Hash value calculated ( HASH_SIZE on failure)

unsigned int myHashFunction(char *ptrInputBuffer)
{
	unsigned int calculatedHashValue = 0;

	// add code to create a hashed value here!!!
	// sdbm Hashing Algorithm
	int c;

	while (c = *ptrInputBuffer++)
	{
		calculatedHashValue = c + (calculatedHashValue << 6)
			+ (calculatedHashValue << 16) - calculatedHashValue;
	}
	// make sure if hash value is bigger than the table size, the value wraps
	return calculatedHashValue % HASH_SIZE;
}

// FUNCTION      : putIntoHashTable
// DESCRIPTION   :
//   Put the supplied data into a hash table
// PARAMETERS    :
//   ptrInputBuffer - a pointer to the buffer to be put into the hash table
//   bufferLength   - how many characters are in the buffer being put into the hash table
//
// RETURNS       :
//   Hash value used ( HASH_SIZE on failure)

unsigned int putIntoHashTable(char *ptrInputData, unsigned int bufferLength)
{
	unsigned int hashValue = myHashFunction(ptrInputData);

	// check if the value is in the hash
	if (myHash[hashValue]->ptrBuffer != NULL)
	{
		while (myHash[hashValue]->ptrNextHashData == NULL)
		{
			struct myHashStruct *dataLink = (struct myHashStruct *) malloc(sizeof(struct myHashStruct));
			dataLink->ptrBuffer = (char*)malloc(bufferLength + 1); // creating pointer for data in bucket
			/* Data in each bucket is stored as linked list with new data placed at the head of the list */
			strcpy_s(dataLink->ptrBuffer, bufferLength + 1, ptrInputData);
			dataLink->ptrNextHashData = myHash[hashValue]; 
			myHash[hashValue] = dataLink; 

		}
	}
	else {
		myHash[hashValue]->ptrBuffer = (char*)malloc(bufferLength + 1); // if the bucket is empty
		strcpy_s(myHash[hashValue]->ptrBuffer, bufferLength + 1, ptrInputData);
	}
	// add code to put data into the hash table!!!

	return hashValue;
}

// FUNCTION      : getFromHashTable
// DESCRIPTION   :
//   Read as much data as there is room for from the hash table
// PARAMETERS    :
//   ptrOutputBuffer - a pointer to the buffer to place the data read from hash table
//   bufferLength    - maxiumum number of characters that can be read
//
// RETURNS       :
//   Hash value used ( return HASH_SIZE value on failure)

unsigned int getFromHashTable(char *ptrOutputData, unsigned int bufferLength)
{
	unsigned int hashValue = myHashFunction(ptrOutputData);

	// check if the data is in the hash table here!!!
	if (myHash[hashValue]->ptrBuffer != NULL)
	{
		struct myHashStruct *checkData = myHash[hashValue];
		while (checkData->ptrBuffer != NULL)
		{
			if (strcmp(checkData->ptrBuffer, ptrOutputData) == 0)
			{
				printf("Data is ");
				return hashValue;
			}
			checkData->ptrNextHashData = checkData;
		}
	}
	else {
		return HASH_SIZE;
	}
//	return hashValue;
}

// end code *    *     *   
