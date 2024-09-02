# Academia Plus ©
## School-Management-System!

**Prototype Demo**: A C++ Qt application created to simulate a school environment.

## Introduction
Welcome to the **School-Management-System** project! This prototype aims to simulate a school system encompassing students, teachers, exams, and courses, all developed using Qt C++. It was undertaken as a non-mandatory assignment, completed over 20 days, with the primary goal of exploring how such an application could be structured and function. Please note that this is a **demo** version, and it may undergo significant rework in the future.

## Project Design
The project began with a day dedicated to designing the interface and planning the class hierarchy. The core C++ version, which included nearly all required functionality, was completed within a day. The design focuses on a sleek, minimalist, and modern user experience, even though certain Qt limitations (such as QSS functionality) may affect the visual appeal. The application is dynamic, using real-time composition and layer adjustments to deliver user-demanded frames and widgets.

This project served as an experimental learning ground. Different approaches were taken across various classes—using arrays, vectors, pointers, extern functions, and diverse methods to explore their potential. This experimentation led to a less consistent codebase, but it provided invaluable learning opportunities. The aim was not just to complete the project but to enhance my skills as a software developer by embracing a broad range of programming techniques.

This project uses Local storage desing, featuring a C++ File Handeling system, so no internet connection is required after initial setup.

## Project Journey

### Timeline
Although the project was completed in 20 days, it involved extensive rework due to evolving requirements and unforeseen challenges. What began as a straightforward task evolved into a more complex undertaking, especially after integrating additional features and addressing unforeseen issues.

### Challenges and Motivation
Throughout the project, various challenges emerged that required significant rework, including:
- Transitioning from arrays to vectors after significant progress had been made.
- Dynamically allocating resources for greater flexibility.
- Adapting functions to better align with Qt's capabilities.
- Redesigning the application to accommodate multiple roles for teachers and multiple year levels for students.
- Adjusting the scheduling system to be more course-focused rather than administration-oriented.

Despite these challenges, the project provided a deep understanding of the complexities involved in software development. 

### Rework Highlights
Several features were removed or scaled back due to time constraints and the need to maintain project stability:
- The ability to add and remove icons for courses, teachers, and students was removed due to UI limitations.
- Hidden Easter eggs and other personalized features were minimized to focus on core functionality.
- The scheduling system was simplified to prioritize course-based scheduling.
- Additional course details and exam types were streamlined to meet project requirements.

Certain planned features, such as managing groups across multiple year levels and manual data saving/loading, were omitted due to their complexity and time constraints.

## Lessons Learned
This project offered several key takeaways:
- **Lesson 1:** The importance of careful planning to reduce the need for extensive rework.
- **Lesson 2:** Writing concise, high-quality code is more valuable than producing large quantities of code that require frequent debugging.
- **Lesson 3:** Avoiding unnecessary complexity, particularly with pointers, can save time and reduce errors.
- **Lesson 4:** It's acceptable to spend additional time on the planning phase, as it can ultimately save time in development and debugging.

## Conclusion
The **School-Management-System** project was a valuable exercise in both design and problem-solving. While it involved numerous challenges and reworks, the experience gained was substantial. As a prototype, it fulfilled its purpose as a testing ground for various approaches and techniques, laying the groundwork for future projects.

Please feel free to explore the code, and reach out if you have any questions or suggestions. This project is a stepping stone, and I'm excited to continue developing my skills and knowledge in software development.


## Screenshots
Here are some screenshots of the application:

### Login Window
![Screenshot 1](Screenshots/qt1.png)
*Either use admin|admin, or an actual Name|Password combination from the database*

### Home Page
![Screenshot 2](Screenshots/qt2.png)
*Home Page for the program, alongside the Main Logo and homework description*

### Menu Illustation
![Screenshot 3](Screenshots/qt3.png)
*Example of a Menu, here chosen Teachers, all features are implemented*

### Adding a new member/Element to the School!
![Screenshot 4](Screenshots/qt4.png)
*Depends on the member type :Teacher/Student/Course/Exam*

### User Credentials
![Screenshot 5](Screenshots/qt5.png)
*Simple User interface for showcasing the information related to the user of the application*

### About Context window
![Screenshot 6](Screenshots/qt6.png)

*Simple about window, Embracing hardowrk and showcasing motivation*

### Running the Application on Qt
![Screenshot 7](Screenshots/howto.png)
*After downloading the zip file, make sure to set the project build location in order to run the program*

