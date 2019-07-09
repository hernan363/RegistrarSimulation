# RegistrarSimulation
A C++ assignment that uses Doubly Linked Lists, Queues, and File I/O to
simulate students at the registrar office.

Link to the assignment documentation:
https://drive.google.com/file/d/1jpTCKcD647a6vdMwJfH7ntLY1ibQlEQK/view?usp=sharing

\\\\\\\\\\\\ Goal \\\\\\\\\\\\
The goal of this program is return statistics on how long students have been
waiting in line and how much time the registrar windows spend doing nothing.


\\\\\\\\\\\\ Overall layout of the program \\\\\\\\\\\\
There are 3 main singleton classes. The Statistics, WindowLists, and
StudentQueue classes hold all the important data in the program. Statistics
contains all the information that we are trying to collect by simulating the
registrar. The WindowLists class contains the Window's Queue that is used to
store open windows that are ready to server students. It also contains a
Window's List that is used to store a window after it has been removed from the
Queue. The StudentQueue class contains the student queue with all the students
that will appear during the simulation.

This programs requires a command line argument of a text file that follows a
specific format. If an argument or valid file does not exist, the program will
exit.

After opening the file, the program stripes the text file to fill two queues.
One queue is filled with the registrar windows that are ready to serve
students. The other queue is filled with the students who are need to be served.

Next, the program runs a loop that will not end until the last student is
removed from its queue, and all the windows are reopened which will conclude
that all the students have been fully served.

There is a counter that increments each successful iteration of the loop. One
increment will represent one minute. As a minute passes, students will "arrive"
by matching their arrival time with the current counter status. If a window is
open and the student arrives, then both the student and window will be removed
from their queues. The student takes its statistics and adds it to the
Statistics class. The window is placed into the window list where it will wait
until the student it is helping is done. The window's statistics work are
different than the student's. The windows hold their own statistics until the
simulation is over, then they will add their statics to the Statistics class.
After being placed into the list, the window's statistics are updated.

This will run in a loop until all students are removed from the queue, and all
windows are reopened. 
