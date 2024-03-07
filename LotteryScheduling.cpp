#include <iostream> // Include header file for input and output
#include <queue>    // Using queue for the scheduling algorithm
#include <vector>   // Using vector for holding the IDs of the processes
#include <cstdlib> // Using rand() function from cstdlib
#include <ctime>   // Needed to access the time
using namespace std;

// Represents a process
class Process {
private:
    // Process needs an id and number of tickets
    int id;
    int numTickets;
public:
    // Constructor
    Process(int id, int numTickets) {
        this->id = id;
        this->numTickets = numTickets;
    }

    // Gets the id
    int getId() const {
        return id;
    }

    // Get the number of tickets
    int getNumTickets() const {
        return numTickets;
    }
};

// Manages the lottery scheduling algorithm
class Scheduler {
private:
    // Using the first come first serve (FCFS) algorithm 
    queue<Process> processes;
    // For every lottery ticket a process has, the id of the process gets added to the vector
    vector<int> lotteryTickets;
public:
    // Using FCFS for each process, implemented through queue data structure
    void addProcess(const Process process) {
        processes.push(process);
    }

    // Selecting each process from the queue. The number of tickets a process has is how many times the id
    // number will be pushed into the vector of lotteryTickets. 
    void allocateTickets() {
        while (!processes.empty()) {
            Process process = processes.front();
            processes.pop();
            for (int i = 0; i < process.getNumTickets(); i++) {
                lotteryTickets.push_back(process.getId());
            }
        }
    }

    // Selecting the process to run (aka which process is the winner)
    int selectProcess() const {
        // Each process has 0 lottery tickets
        if (lotteryTickets.empty()) {
            return -1;
        }
        // Randomly selecting the winner, whichever id is selected from lotteryTickets vector is the winner
        int randomIndex = rand() % lotteryTickets.size();
        return lotteryTickets[randomIndex];
    }
};

int main() {

    // Seed the random number generator with the current time
    srand(static_cast<unsigned int>(time(0)));

    // Creating processes:
    //Each process has id and number of tickets
    Process process1(1, 5); //id: 1, tickets: 5
    Process process2(2, 2); //id: 2, tickets: 2
    Process process3(3, 7); //id: 3, tickets: 7

    // Create scheduler
    Scheduler scheduler;

    // Add processes to the scheduler
    scheduler.addProcess(process1);
    scheduler.addProcess(process2);
    scheduler.addProcess(process3);

    // Allocate lottery tickets
    scheduler.allocateTickets();

    // Select next process to run
    int id = scheduler.selectProcess();

    // Output the winner
    if (id != -1) {
        std::cout << "Process " << id << " wins the lottery!" << std::endl;
    }
    else {
        std::cout << "No winner. No process has tickets." << std::endl;
    }

    return 0;
}

