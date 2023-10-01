import java.util.*;

public class firstFitAct{

    public static Scanner sc = new Scanner(System.in);

    public static void main (String args[]) {
        int nBlock, nProcess, sizeBlock, sizeProcess, block[], process[], allocation[];
        String sBlock, sProcess;
        System.out.print("Enter the number of memory blocks: ");
        sBlock = sc.next();
        nBlock = Integer.parseInt(sBlock);
        System.out.println("--------------------");
    
        block = new int[nBlock];
        allocation = new int[nBlock];
        for (int i = 0; i < nBlock; i++) {
            System.out.print("Enter the size of memory block " + (i+1) + ": ");
            sizeBlock = sc.nextInt();
            block[i] = sizeBlock;
        }
        
        System.out.print("Enter the number of processes: ");
        sProcess = sc.next();
        nProcess = Integer.parseInt(sProcess);
        System.out.println("--------------------");
        
        process = new int[nProcess ];
        for (int i = 0; i < nProcess; i++) {
            System.out.print("Enter the size of file process " + (i+1) + ": ");
            sizeProcess = sc.nextInt();
            process[i] = sizeProcess;
        }

        System.out.println("--------------------INPUTS");
        for (int i = 0; i < nBlock; i++) {
            System.out.println("Block " + (i+1) + ": " + block[i]);
        }
        for (int i = 0; i < nProcess; i++) {
            System.out.println("Process " + (i+1) + ": " + process[i]);
        }

        for (int i = 0; i < nBlock; i++) {
            allocation[i] = -1;
        }

        for (int i = 0; i < nProcess; i++) {
            for (int j = 0; j < nBlock; j++) {
                if (block[j] >= process[i]) {
                    allocation[i] = j;
                    block[j] -= process[i];
                    break;
                }
            }
        }

        System.out.println("--------------------OUTPUTS");
        System.out.println("Process No.\tProcess Size\tBlock No.\tTransferred Process Size\tRemaining Block Size");
        for (int i = 0; i < nProcess; i++) {
            System.out.print("     " + (i+1) + "\t\t     " + process[i] + "\t   ");
            if (allocation[i] != -1) {
                System.out.println((allocation[i] + 1) + "\t\t\t" + process[i] + "\t\t\t" + block[i]);
            } else {
                System.out.println("Not Allocated" + "\t\t-" + "\t\t\t-");
            }
        }
    }
}