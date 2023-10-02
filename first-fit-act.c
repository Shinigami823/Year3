#include<stdio.h>

int main()
{
    //initializing variables
    int nBlock, nProcess, sizeBlock, sizeProcess;

    //taking input from user
    printf("Enter the number of blocks in the memory: ");
    //using scanf to take input from user
    scanf("%i", &nBlock);
    //declaring array
    int blockSize[nBlock];
    int allocation[nBlock];
    //using for loop to take inputs
    printf("Enter the number of processes in the input queue: ");
    scanf("%i", &nProcess);
    int processSize[nProcess];
    for (int i = 0; i < nBlock; i++)
    {
        printf("Enter the size of block %i: ", i+1);
        scanf("%i", &sizeBlock);
        blockSize[i] = sizeBlock;
    }
    for (int i = 0; i < nProcess; i++)
    {
        printf("Enter the size of process %i: ", i+1);
        scanf("%i", &sizeProcess);
        processSize[i] = sizeProcess;
    }

    //allocation array
    for (int i = 0; i < nBlock; i++) {
            allocation[i] = -1;
    }
    for (int i = 0; i < nProcess; i++) {
            for (int j = 0; j < nBlock; j++) {
                if (blockSize[j] >= processSize[i]) { //if block size is greater than process size
                    allocation[i] = j; 
                    blockSize[j] -= processSize[i]; 
                    break;
                }
            }
        }
    
    printf("\nProcess No.\t\tProcess Size\t\t\tBlock no.\t\t\tTransffered Process Size\n");
    for (int i = 0; i < nProcess; i++)
    {
        printf("%i\t\t\t", i+1);
        printf("%i\t\t\t\t", processSize[i]);
        if (allocation[i] != -1)
        {
            printf("%i\t\t\t\t", allocation[i] + 1);
            printf("%i\t\t\t\t", processSize[i]);
        }
        else
        {
            printf("Not Allocated");
            printf("\t\t\t-");
        }
        printf("\n");
    }
    return 0;
}