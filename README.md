# School-Management-System
First C++ QT Program, created with the goal of simulating a school environment.

## Introduction
Welcome to the School-Management-System project! This was an ambitious venture to simulate a school system with students, teachers, exams, and courses, all developed using Qt C++. This project was a non-mandatory homework assignment that took me 20 days to complete. I really hope you go through this description along with me. 

## Project Design
Took a day to design the interface on paper, plan the classes hierachy, and only 1 day to finish the basic C++ version, which had nearly all the functionality needed in the tasks. the design is sleek, minimalist, modern and fancy feeling, Unique, (would have been cooler if QSS worked like it should on QT), and most importantly : NOT BORING!, as it is dynamic and uses realtime composition and layer adjustements to create the frames and widgets demanded by the user. 💎
During the creation of this program, my goal was mostly to learn and try the [ What IFs ?] to fill my curiosity and build for my future knowledge base, which resulted in the code to be a bit less readable for others, since I experimented in each class with different methods, some i used arrays, some vectors, some pointers to store the names, some used extern functions, some made them into dialogue boxed with inside verifications, and others from the outside..you get the idea
But the Hole point of this project was for me to **Try and Learn**, to become a better software devlopper when I need to, and a better programmer in general, since the **best programmer is not that who memorizes every good algorithm, but the one who understands why every other algorithm is less effecient than the one he choses**

## Project Journey
### The Timeline
I dedicated 20 days to this project, but let's be real – it felt like 240% more due to numerous reworks. The primary reason for this extended timeline was the lack of initial information and the subsequent need to rework significant portions of the project. Took 12 days out of my 21 days holiday just making this peoject (instead of actually studying something more useful because I love making projects),on my laptop's 17 inch 2k display (QT DOES NOT HAVE A ZOOM NOR A SCALE), my eyes hurts so much because of this small text consistant focus, but that's ok I guess, after 4 more days, just when I thought I was done, and after I continued to make this project mid sessions (even in math amphiters but don't tell the teachers ok?), some students might have stole my design but WE ARE THE ORIGINE! and ALL ELSE ARE COPYCATS! My friend sent an email asking about some details, and man.. I had to rework some core features that everything relied on, mostly related to the groups and allocation of students and teachers, alongside the distribution of the courses.. so in the other 6 days, I had to remove many things, give up on some, and restart from scratch multiple things, but all that QT DEBUGGING took the time needed, and now I am left with this OK instead of the jaw dropping program, that I dreamed of when I started this journey. 

### Challenges and Motivation
At some point, I lost the motivation to continue the project. This happened after a my friends told me the project additional info ( such as no duplicated names, courses must not conflict, the teachers can be for labs and tutos too, this can also change for each group, the students can be of second, third.. year), revealing additional requirements I had no knowledge of (sticked to the given tasks, and added my touch to it ✨). Here are some of those disheartening details:
There were several points in the project where I had to go back and redo my work. Here are some of the highlights:
- **1:** *Using Vectors Instead of array (past 60% into the project)*
- **2:** *MAKING EVERYTHIGN DYNAMICLY ALLOCATED BECAUSE WHY NOT!!??*
- **3:** *Remaking all the functions was using to better suit QT*
- **4:** *Making the teahcers have Different roles (about 80% into the project) reworked half of my qt functions and spent 3 days debugging*
- **5:** *Making the students from multiple years instead of one, which was suitable at first to my initial minimalist design (impossible to change at this advanced level)*
- **6:** *Performance analysis, first it was more of attendance and notes for each the students and the teachers, but the ui made that look bad, so I split it one each to not waste my previous codes*
- **7:** *Making the schedule more courses focused than administration oriented (now you cannot set the schedule using strings and verifications, it must be FORMAL, and following only the courses the student takes)*
-**x**other things... idk I got sad just writing this list*

### Rework Highlights
Some of the things I removed after the work doubled :
- **1:** *Removed the ability to add and remove Icons to the courses, teachers, studetns (the ui got janky after I added all those extra features)*
- **2:** *I had many easter eggs hidden in the project ( such as hidden auto image assignements when naming the courses same as our ENSIA courses ) , which is usually the most I have in any project [Check my ITE Website if you want more context about my usual style], still left some there*
- **3:** *Removed the ability to set the schedules on a pre defined timetable that the courses must be adjusted to (now it is completely the opposite)*
- **4:** *Removed some Courses sections, such as descriptions, locations, and addtional links for extra resources..etc*
- **5:** *Exam types, were multiples (Finals, Midterms, Tests), maybe some parts of the code remained, but the calculations alongside the dynamic rework and lack of motivation made me just stick to the assigemnet*
- **x:** *this list is not exaustive, it is what it is 😔*

And, unfortunately, there were some features that I could not include due to time constraints and complexity:
**-** *the ability to manage the groups on multiple year levels (if you see the code, you will know why this will require not hard but very boring things to be adjusted) to literally double x5 the groups I have for ensia, and make a stacked widget for assigning to each group (not worth +0.25 pts on the cc) .*
**-** *the ability to manually save and load the data ( now automatically done which is kind of a feature I guess ? ).*

## Lessons Learned
Despite the struggles, I learned a lot from this project:
- **Lesson 1:** *don't use qt*
- **Lesson 1(really):** *The world of software devloppement is huge, and the best way to learn is to practice and make mistakes.*
- **Lesson 2:** *write less code, give it more attention, writing 1 line that I do not need to debug is better than writing 10 that I need to review every day*
- **Lesson 3:** *pointers are painful to deal with, for real, and they should be avoided in the future for things that can be done normally*
- **Lesson 4:** *Planning can take more than one day, and that's ok! since it will on the long run for sure minimize the amount of time spent fixing and maintaining the code!*

## Conclusion
Creating the School-Management-System was a rollercoaster ride filled with highs, lows, and unexpected turns. Despite the setbacks and the moments of lost motivation, it was a valuable learning experience. Plus, who knew that reworking a project 240% of the time could be so character-building?
As stated above, this Frankenstein of a code, was my tears and sweat, and no matter how hard it is to fix it, to build it, to run it, I was happy that I took the hard path, and learned along the journey, what otherwise could have cost me more to acknowledge in my declopemental carrier. and now I'll move on from this experiment, to continue forward with my studies!

Feel free to browse through the code, and don't hesitate to reach out if you have any questions or suggestions. Enjoy!
