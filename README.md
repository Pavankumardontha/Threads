# Threads

Processor and CPU difference :- Both are same 
CPU core :- A core is a small CPU or processor built into a big CPU or CPU socket. It can independently perform or process all computational tasks. From this perspective, we can consider a core to be a smaller CPU or a smaller processor within a big processor.
A multi-core processor is a computer processor  with two or more separate processing units (CPUs), called cores, each of which reads and executes program instructions, as if the computer had several processors. A single core CPU it can only do one thing at a time however it gives the appearance that it's doing two things at once and the way it does that is it gives a little bit of time to each of the tasks it has to achieve.When we are on a computer then we might be running like Microsoft Word and you might also have the Chrome web browser open and kind of a new email comes in to Gmail and yet you can still carry on typing in Microsoft Word. You get the appearance that you're doing two things at once and that's because the computer gives a slice of its time to each program. This is on a single core CPU. 

1. Multitasking on a single-core CPU:- CPU time is divided for different programs, and program executions are switched instead of being executed one after another, but there is no real speed improvement. 
2. Multithreading on a single-core CPU:- Codes in the same program were executed in "parallel", and threads are switched instead of being executed one after another, but there is no real speed improvement.
3. Multiprocessing:- this is when we have more than one CPU core, and we can do real multitasking and multithreading (i.e. executing programs and threads on different cores at the same time)

""""" So a CPU can have Multi-Cores, each Core can Multi-Task, and each Task can Multi-Thread. """""

Difference between parallelism and concurrency :- 

























