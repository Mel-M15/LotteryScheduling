# LotteryScheduling README

Please run this LotteryScheduling project in C++.

# Overview

This C++ program implements a basic lottery scheduling algorithm. Processes are assigned lottery tickets, and the scheduler randomly selects a ticket to determine which process wins the lottery. 

# Functionality
The lottery scheduling algorithm has the following functionality:
1. Process class - represents a process. Each process has a unique ID and several lottery tickets. Process class has 2 methods: getID(), which returns the ID of each process, and getNumTickets() which returns the number of tickets each process has.
2. Scheduler class - schedules the processes using a first-come-first-serve(FCFS) scheduling algorithm.
3. Processes are added to the scheduler using the 'addProcess' method. Each process with its ID and number of tickets is pushed into a queue.
   
5. 1. Add processes to the scheduler using the `addProcess` method.
2. Allocate lottery tickets using the `allocateTickets` method.
3. Select the next process to run using the `selectProcess` method.
4. Output the winner process using the returned process ID.

   
# Instructions for Execution
1. Run this program in C++.
2. There is no user input required by the user to run the program
3. Run the program and a random process from IDs of 1,2,3 will be randomly selected to win the lottery.
4. Optional: Run the program many more times to verify that the processes that win the lottery are selected at random.


