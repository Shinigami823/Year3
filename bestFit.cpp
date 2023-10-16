#include<stdio.h>

int main()
{
    //initializing variables
    int nBlock, nProcess, sizeBlock, sizeProcess, flag;

    printf("----------Best Fit Algorithm---------\n");
    printf("------------MEMORY BLOCKS------------\n");
    //taking input from user
    printf("Enter the number of blocks in the memory: ");
    //using scanf to take input from user
    scanf("%i", &nBlock);
    //declaring array
    int blockSize[nBlock];
    int allocation[nBlock];
    //using for loop to take inputs
    for (int i = 0; i < nBlock; i++)
    {
        printf("Enter the size of block %i: ", i+1);
        scanf("%i", &sizeBlock);
        blockSize[i] = sizeBlock;
    }
    
	printf("---------------PROCESS---------------\n");
    printf("Enter the number of processes in the input queue: ");
    scanf("%i", &nProcess);
    int processSize[nProcess];
    for (int i = 0; i < nProcess; i++)
    {
        printf("Enter the size of process %i: ", i+1);
        scanf("%i", &sizeProcess);
        processSize[i] = sizeProcess;
    }

	for (int i = 0; i < nBlock; i++)	{
		allocation[i] = -1;
	}
	printf("\n----------------PRINT----------------\n");
    printf("Process No.\tProcess Size\tBlock no.\tBlock Size\tTransfered Process Size\t\tRemaining Block Size\n");
    for (int i = 0; i < nProcess; i++)
    {
		flag = -1;
		for (int j = 0; j < nBlock; j++)	
		{
			if (blockSize[j] >= processSize[i])
			{
				if (blockSize[flag] > blockSize[j]) 
				{
					flag = j;
				}
			}
		}
				printf("%i\t\t", i+1);
				printf("%i\t\t", processSize[i]);
				if (flag != -1)
				{
					allocation[i] = flag;
					blockSize[flag] -= processSize[i];
					printf("%i\t\t", allocation[i] + 1);
					printf("%i\t\t", blockSize[flag] + processSize[i]);
					printf("%i\t\t\t\t", processSize[i]);
					printf("%i", blockSize[allocation[i]]);
				}
				else
				{
					printf("Not Allocated");
					printf("\t-");
					printf("\t\t-");
					printf("\t\t\t\t-");
				}
				printf("\n");
    }
    return 0;
}