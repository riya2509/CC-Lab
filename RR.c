// Round Robin
/* This algorithm is designed for time sharing system where it is not necessary to complete one process 
and start another but to be responsive and divide the time of CPU among all the processes. 
Here the ready queue will be treated as a circular queue.
We fix a time quantum upto which a process can access a CPU within which either a process terminates or 
process must release the CPU and re-enter into the circular queue and wait for the next chance.*/

// Min min algorithm
/*For each task determine it's minimum completion time over all machines.
Over all tasks find the minimum completion time.
Assign the tasks to the machine that gives this completion time.
Repeat the above steps until all the tasks are getting scheduled.*/

//Max-Min algorithm
/*no.of task , no.of machine, completion time of each macine*/