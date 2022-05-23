---
layout: post
title: The Dining Philosophers Problem
permalink: /dining-philosophers.html
---

The 'dining philosophers problem' is a famous problem in computer science.
This problem helps us to understand and work with several subjects that are related to concurrent programmming.

# Data races / race conditions
In [pipex](/pipex-blog-en.html) we have learned that a program can consist out of multiple processes. In the dining philosophers project we will not be dealing with multiple processes, but with multiple threads instead. A thread is a succession of instructions within a program that can be executed independently of other code. A proces always consists out at least 1 or multiple threads. A thread on the other hand, can not consist out of multiple processes. The different threads that are part of one process, share the same memory space, and the threads can be run simultaneously, i.e. concurrently. The different threads can use the same resources from the memory space of their comprending process, and so multiple threads can try to access the same resources at the exact same time of execution. If such a thing happens, and multiple threads try to modify the same resources (e.g. variables) at the same time, then this can have unwanted side effects. Data can be lost in this process.
Imagine that de variable x is in memory and this variable has a value of 1. There are two threads of execution and they both have access to this variable. If both threads than have a function to increase the value of x with 1, it can so happen that one thread sets the value of x to 2, en the other thread does the same. If we wanted to make the value of x increase by 1 two times, so that it should be 3 than we run into a problem. The threads should not have executed the mutation on x at the same time but after one another. Now because both read that x was 1 and then increased it with 1, we end up with the value of x = 2, but this should have been x = 3. This phenomena where problems arise by threads having access to the same shared resources, is called a data race, or a race condition.

## Deadlock
Another infamous problem that can occur when multiple threads have access to shared resources, is the so-called deadlock. This is a state of impasse, where a program is unable to make any more progress, because different parts make use of the same shared resources, and one part of the program needs resources that another part has currently in use, and it cannot continue when the other part is still using this resource. The other part, however, needs the part that the other part has in its use: they both need something from each other to move forward, and are thereby never able to continue anymore.
