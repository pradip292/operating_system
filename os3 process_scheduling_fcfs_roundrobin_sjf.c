#include <stdio.h>
#include <stdbool.h>

struct Process {
    char pname[5];
    int at;
    int bt;
    int ct; // Completion Time
    int tat; // Turnaround Time
    int wt; // Waiting Time
};

void roundRobinScheduling(struct Process processes[], int n, int quantum) {
    int remainingTime[n];
    int currentTime = 0;
    int i;

    for ( i = 0; i < n; i++) {
        remainingTime[i] = processes[i].bt;
    }

    while (true) {
        bool allFinished = true;

        for ( i = 0; i < n; i++) {
            if (processes[i].at <= currentTime) {
                if (remainingTime[i] > 0) {
                    allFinished = false;

                    if (remainingTime[i] <= quantum) {
                        currentTime += remainingTime[i];
                        processes[i].ct = currentTime;
                        remainingTime[i] = 0;
                    } else {
                        currentTime += quantum;
                        remainingTime[i] -= quantum;
                    }
                }
            }
        }

        if (allFinished) {
            break;
        }
    }
}

void fcfs(struct Process processes[], int n) {
    int currentTime = 0,i;
    for ( i = 0; i < n; i++) {
        if (processes[i].at > currentTime) {
            currentTime = processes[i].at;
        }
        processes[i].ct = currentTime + processes[i].bt;
        processes[i].tat = processes[i].ct - processes[i].at;
        processes[i].wt = processes[i].tat - processes[i].bt;
        currentTime = processes[i].ct;
    }
}

void sjf(struct Process processes[], int n) {
	int i,j;
    for ( i = 0; i < n - 1; i++) {
        for ( j = 0; j < n - i - 1; j++) {
            if (processes[j].bt > processes[j + 1].bt) {
                struct Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }
    fcfs(processes, n);
}

int main() {
    int n, quantum,i;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];

    for ( i = 0; i < n; i++) {
//        printf("Enter the name of process P%d: ", i + 1);
//        scanf("%s", processes[i].pname);
        printf("Enter the Arrival Time for P%d: ", i + 1);
        scanf("%d", &processes[i].at);
        printf("Enter the Burst Time for P%d: ", i + 1);
        scanf("%d", &processes[i].bt);
    }

//    printf("Enter the time quantum for Round Robin: ");
//    scanf("%d", &quantum);

    printf("Choose a scheduling algorithm:\n");
    printf("1. FCFS\n");
    printf("2. SJF\n");
    printf("3. Round Robin\n");

    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("FCFS Scheduling\n");
            fcfs(processes, n);
            break;
        case 2:
            printf("SJF Scheduling\n");
            sjf(processes, n);
            break;
//        case 3:
//            printf("Round Robin Scheduling\n");
//            roundRobinScheduling(processes, n, quantum);
//            break;
        default:
            printf("Invalid choice\n");
            return 1;
    }

    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");

    int totalTAT = 0;
    int totalWT = 0;

    for ( i = 0; i < n; i++) {
        processes[i].tat = processes[i].ct - processes[i].at;
        processes[i].wt = processes[i].tat - processes[i].bt;
        totalTAT += processes[i].tat;
        totalWT += processes[i].wt;

        printf("%s\t%d\t%d\t%d\t%d\t%d\n", processes[i].pname, processes[i].at, processes[i].bt, processes[i].ct, processes[i].tat, processes[i].wt);
    }

    double avgTAT = (double) totalTAT / n;
    double avgWT = (double) totalWT / n;

    printf("\nAverage TAT: %.2f\n", avgTAT);
    printf("Average WT: %.2f\n", avgWT);

    return 0;
}
