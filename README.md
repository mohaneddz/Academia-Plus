# School-Management-System
First C++ Qt Program, created with the goal of simulating a school environment.

## Introduction
Welcome to the School-Management-System project! This ambitious venture aimed to simulate a school system with students, teachers, exams, and courses, all developed using Qt C++. This project was a non-mandatory homework assignment that took me 20 days to complete. I really hope you go through this description along with me. 

## Project Design
I took a day to design the interface on paper, plan the class hierarchy, and only one day to finish the basic C++ version, which had nearly all the needed functionality. The design is sleek, minimalist, modern, and fancy. Unique, (would have been cooler if QSS worked like it should on Qt), and most importantly: NOT BORING! It is dynamic and uses real-time composition and layer adjustments to create the frames and widgets demanded by the user. 💎

During the creation of this program, my goal was mostly to learn and try the [What IFs?] to fill my curiosity and build for my future knowledge base. This resulted in the code being a bit less readable for others, since I experimented in each class with different methods. Some used arrays, some vectors, some pointers to store the names, some used extern functions, and others made them into dialogue boxes with inside verifications, and others from the outside... but you get the idea. The whole point of this project was for me to **Try and Learn**, to become a better software developer when I need to, and a better programmer in general. The **best programmer is not the one who memorizes every good algorithm, but the one who understands why every other algorithm is less efficient than the one they choose**.

## Project Journey
### The Timeline
I dedicated 20 days to this project, but let's be real – it felt like 240% more due to numerous reworks. The primary reason for this extended timeline was the lack of initial information and the subsequent need to rework significant portions of the project. I took 12 days out of my 21-day holiday just making this project (instead of actually studying something more useful because I love making projects), on my laptop's 17-inch 2k display (Qt DOES NOT HAVE A ZOOM NOR A SCALE). My eyes hurt so much because of this small text consistent focus, but that's okay I guess. After 4 more days, just when I thought I was done, and after I continued to make this project mid-sessions (even in math amphitheaters but don't tell the teachers, okay?), some students might have stolen my design, but WE ARE THE ORIGIN! and ALL ELSE ARE COPYCATS! My friend sent an email asking about some details, and man... I had to rework some core features that everything relied on, mostly related to the groups and allocation of students and teachers, alongside the distribution of the courses. So in the other 6 days, I had to remove many things, give up on some, and restart from scratch multiple things. But all that Qt debugging took the time needed, and now I am left with this OK program instead of the jaw-dropping one I dreamed of when I started this journey.

### Challenges and Motivation
At some point, I lost the motivation to continue the project. This happened after my friends told me the project's additional info (such as no duplicated names, courses must not conflict, the teachers can be for labs and tutorials too, this can also change for each group, the students can be of second, third... year), revealing additional requirements I had no knowledge of (stuck to the given tasks, and added my touch to it ✨). Here are some of those disheartening details:
- **1:** *Using Vectors Instead of arrays (past 60% into the project)*
- **2:** *MAKING EVERYTHING DYNAMICALLY ALLOCATED BECAUSE WHY NOT!!??*
- **3:** *Remaking all the functions to better suit Qt*
- **4:** *Making the teachers have different roles (about 80% into the project) reworked half of my Qt functions and spent 3 days debugging*
- **5:** *Making the students from multiple years instead of one, which was suitable at first to my initial minimalist design (impossible to change at this advanced level)*
- **6:** *Performance analysis, first it was more of attendance and notes for each of the students and the teachers, but the UI made that look bad, so I split it, one each, to not waste my previous codes*
- **7:** *Making the schedule more courses-focused than administration-oriented (now you cannot set the schedule using strings and verifications, it must be FORMAL, and follow only the courses the student takes)*
- **x:** *other things... idk I got sad just writing this list*

### Rework Highlights
Some of the things I removed after the work doubled:
- **1:** *Removed the ability to add and remove Icons to the courses, teachers, students (the UI got janky after I added all those extra features)*
- **2:** *I had many easter eggs hidden in the project (such as hidden auto image assignments when naming the courses the same as our ENSIA courses), which is usually the most I have in any project [Check my ITE Website if you want more context about my usual style], still left some there*
- **3:** *Removed the ability to set the schedules on a predefined timetable that the courses must be adjusted to (now it is completely the opposite)*
- **4:** *Removed some courses sections, such as descriptions, locations, and additional links for extra resources..etc*
- **5:** *Exam types were multiples (Finals, Midterms, Tests), maybe some parts of the code remained, but the calculations alongside the dynamic rework and lack of motivation made me just stick to the assignment*
- **x:** *this list is not exhaustive, it is what it is 😔*

And, unfortunately, there were some features that I could not include due to time constraints and complexity:
- **The ability to manage the groups on multiple year levels** (if you see the code, you will know why this would require not hard but very boring things to be adjusted) to literally double x5 the groups I have for ENSIA, and make a stacked widget for assigning to each group.
- **The ability to manually save and load the data** (now automatically done which is kind of a feature I guess?).

## Lessons Learned
Despite the struggles, I learned a lot from this project:
- **Lesson 1:** *don't use Qt*
- **Lesson 1(really):** *The world of software development is huge, and the best way to learn is to practice and make mistakes.*
- **Lesson 2:** *write less code, give it more attention. Writing 1 line that I do not need to debug is better than writing 10 that I need to review every day.*
- **Lesson 3:** *pointers are painful to deal with, for real, and they should be avoided in the future for things that can be done normally.*
- **Lesson 4:** *Planning can take more than one day, and that's ok! since it will in the long run for sure minimize the amount of time spent fixing and maintaining the code!*

## Conclusion
Creating the School-Management-System was a rollercoaster ride filled with highs, lows, and unexpected turns. Despite the setbacks and the moments of lost motivation, it was a valuable learning experience. Plus, who knew that reworking a project 240% of the time could be so character-building?

As stated above, this Frankenstein of a code was my tears and sweat, and no matter how hard it is to fix it, to build it, to run it, I was happy that I took the hard path, and learned along the journey, what otherwise could have cost me more to acknowledge in my developmental career. I am happy that I used this not as a serious life-depending project, but as an experimental playground, testing all the things to fill in my curiosity. Now, I'll move on from this experiment, to continue forward with my studies!

Feel free to browse through the code, and don't hesitate to reach out if you have any questions or suggestions. Enjoy!
