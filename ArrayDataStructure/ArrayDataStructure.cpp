#include <iostream>

using namespace std;

struct Process {
    int numOfJob;
    int arrivalTime;
    int burstTime;
    int completionTime;
    int turnAroundTime;
    int waitingTime;
};

void findWaitingTime(Process job[], int n) {
    int currentTime = 0;
    for (int i = 0; i < n; i++) {
        if (job[i].arrivalTime > currentTime) {
            currentTime = job[i].arrivalTime;
        }
        job[i].waitingTime = currentTime - job[i].arrivalTime;
        currentTime += job[i].burstTime;
        job[i].completionTime = currentTime;
    }
}

void findTurnAroundTime(Process job[], int n) {
    for (int i = 0; i < n; i++) {
        job[i].turnAroundTime = job[i].completionTime - job[i].arrivalTime;
    }
}

void sortProcesses(Process job[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (job[j].arrivalTime > job[j + 1].arrivalTime) {
                swap(job[j], job[j + 1]);
            }
        }
    }
}

void printGanttChart(Process job[], int n) {
    cout << "Gantt Chart:\n";
    cout << "| ";
    for (int i = 0; i < n; i++) {
        cout << "P" << job[i].numOfJob << " | ";
    }
    cout << "\n0";
    for (int i = 0; i < n; i++) {
        cout << "   " << job[i].completionTime << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    Process job[10];
    for (int i = 0; i < n; i++) {
        cout << "Enter arrival time and burst time for process " << i + 1 << ": ";
        cin >> job[i].arrivalTime >> job[i].burstTime;
        job[i].numOfJob = i + 1;
    }

    sortProcesses(job, n);
    findWaitingTime(job, n);
    findTurnAroundTime(job, n);
    printGanttChart(job, n);

    cout << "\nJob\tArrival Time\tBurst Time\tCompletion Time\t\tTurn Around Time\tWaiting Time\n";
    for (int i = 0; i < n; i++) {
        cout << job[i].numOfJob << "\t\t" << job[i].arrivalTime << "\t\t" << job[i].burstTime << "\t\t"
            << job[i].completionTime << "\t\t\t" << job[i].turnAroundTime << "\t\t\t" << job[i].waitingTime << endl;
    }

    return 0;
}