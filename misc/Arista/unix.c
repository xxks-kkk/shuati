/* What does this do? */

// Ans: man 2 write
// write 'strlen(c)' of the data from the buffer pointed to by 'c' to stdout (1)
write( 1, c, strlen(c) );

/* What does this do? */
// Ans: format print the string.
printf( "%s", c );

/* What's the difference? */

// printf() is a higher level abstraction than write() to stdout. Printf() converts the data
// into a formatted sequence of bytes and that calls write() to write those bytes to the output.
// Also, printf() provides buffering so that write() doesn't give invoked quite often.
// ref: https://stackoverflow.com/questions/21084218/difference-between-write-and-printf


/* What does malloc do?  */

// Ans: dynamically allocate the memory from the heap.
// man malloc; K&R 167



/* What does the '-9' mean in 'kill -9'?  */

// Ans: -9 means SIGKILL (kill the program)
// Ref: CSAPP p.737 (http://man7.org/linux/man-pages/man7/signal.7.html)



/* What would kill -11 do?  */

// Ans: -11 means SIGSEGV (Invalid memory reference aka seg fault)
//



/* What's a zombie process?  */

// Ans: three possible cases: process has terminated; parent process has not collected its status; dead but not gone
// Ref: CS439 slides


/* What does fork return?  */


// Ans: for the parent process: fork() returns parent pid
// for the child process: fork() returns 0
// Ref: CS439 Slides


/* What is the return value of main used for?  */
// for $? (the return value goes to the program which executed it (the parent process) as an exit status code)
// 0 exit code usually means normal while others signify the program may exit abnormally
// ref: https://stackoverflow.com/questions/4818888/main-functions-return-value



/* What is select used for?  Have you ever heard of epoll?  */

// select work mechanism: give it a list of file descriptors to get information about; then select() will tell which
// one have data available to read/write to. epoll() is linux specific.

// epoll a group system calls (epoll_create, epoll_ctl, epoll_wait)
// The epoll group of system calls (epoll_create, epoll_ctl, epoll_wait) give the Linux kernel a list of file
// descriptors to track and ask for updates about whether
//
// Here are the steps to using epoll:
//
// - Call epoll_create to tell the kernel you’re gong to be epolling! It gives you an id back
// - Call epoll_ctl to tell the kernel file descriptors you’re interested in updates about. Interestingly,
// you can give it lots of different kinds of file descriptors (pipes, FIFOs, sockets, POSIX message queues,
// inotify instances, devices, & more), but not regular files. I think this makes sense –
// pipes & sockets have a pretty simple API (one process writes to the pipe, and another process reads!),
// so it makes sense to say “this pipe has new data for reading”. But files are weird! You can write to the middle of a file!
// So it doesn’t really make sense to say “there’s new data available for reading in this file”.
// - Call epoll_wait to wait for updates about the list of files you’re interested in.
// ref: https://jvns.ca/blog/2017/06/03/async-io-on-linux--select--poll--and-epoll/