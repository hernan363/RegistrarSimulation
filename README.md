# RegistrarSimulation
A C++ assignment that uses Doubly Linked Lists, Queues, and File I/O to simulate a typical day at the registrar.

Thought process:

I have the queue, doubly-linked list, student, and window classes setup. The simulation is basic because it follows a standard path. The first thing I need to setup is File I/O and get the information into student and window objects. Both the students and windows are going to be placed into a queue. If windows queue is not empty, then pop one off the student queue and window queue. Every time a student is done at a window, that window will be placed into the window queue. This will repeat until the student queue is empty, and the window queue is full. This would signify that all students have been serviced and the windows are all open. 
