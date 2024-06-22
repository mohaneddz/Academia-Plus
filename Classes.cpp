#include "Classes.h"

// Static Counters

int Teachers::totalteachers = 0;
int Students::totalstudents = 0;
int Courses::totalcourses = 0;
int Exams::totalexams = 0;
int Members::totalmembers = 0;

// Forward Declaration

School ENSIA;

// Date --------------------------------------------

Date::Date() : day(0), month(0), year(0) {}
Date::Date(int day, int month, int year) : day(day), month(month), year(year) {}
Date::~Date() {};

// Setters and Getters

void Date::setDay(int day)
{
    this->day = day;
}
void Date::setMonth(int month)
{
    this->month = month;
}
void Date::setYear(int year)
{
    this->year = year;
}
void Date::setDate(int day, int month, int year)
{
    this->day = day;
    this->month = month;
    this->year = year;
}

int Date::getDay() const
{
    return day;
}
int Date::getMonth() const
{
    return month;
}
int Date::getYear() const
{
    return year;
}

// Courses Class -------------------------------------------------------------------
// Setters

void Courses::setName(const string &newName)
{
    name = newName;
}
void Courses::setGroups(const bool newgroups[12])
{
    for (int i = 0; i < 12; i++)
    {
        groups[i] = newgroups[i];
    }
}
void Courses::setSchedule(const string schedule[7][2])
{
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            this->schedule[i][j] = schedule[i][j];
        }
    }
}
void Courses::setId(const int id)
{
    this->id = id;
}

string Courses::getName() const
{
    return name;
}
string (*Courses::getSchedule())[2]
{
    return schedule;
}
bool *Courses::getGroups()
{
    return groups;
}
int Courses::getId()
{
    return id;
}

Courses::Courses()
{
    setName("Unknown");
    Courses::totalcourses++;

    for (int i = 1; i < 12; i++)
    {
        groups[i] = false;
    }
    // the schedule :
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            schedule[i][j] = "";
        }
    }
}
Courses::Courses(const string &newName, string newSchedule[7][2], const bool newgroups[12])
{
    Courses::totalcourses++;

    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            schedule[i][j] = newSchedule[i][j];
        }
    }

    setName(newName);
    setSchedule(newSchedule);
    setGroups(newgroups);
    setId(ENSIA.getCourses().size());
    ENSIA.addCourse(this);
}
Courses::~Courses()
{
    // No dynamic memory to deallocate
    cout << "Course " << name << " ID :" << id << " has been Removed." << endl;
}

// Exams --------------------------------------------

Exams::Exams() : Module{}, start{}, end{}, groups{0}
{
    // cout << "Exam has been created." << endl;
};
Exams::Exams(Courses *Module, float Marks[7], const Time *start, const Time *end, bool groups[12]) : Module{Module}, start{*start}, end{*end}
{

    Exams::totalexams++;
    setId(ENSIA.getExams().size());
    ENSIA.addExam(this);

    for (int i = 0; i < 12; i++)
    {
        this->groups[i] = groups[i];
    }

    // cout << "Exam has been created." << endl;
};
Exams::~Exams()
{
    cout << "Exam has been removed." << endl;
}

void Exams::setModule(Courses *Module)
{
    this->Module = Module;
};
Courses *Exams::getModule()
{
    return Module;
};

void Exams::setDate(const Time &start, const Time &end)
{
    this->start = start;
    this->end = end;
};
Time Exams::getStartDate()
{
    return start;
};
Time Exams::getEndtDate()
{
    return end;
};

void Exams::setGroups(const bool groups[12])
{
    for (int i = 0; i < 12; i++)
    {
        this->groups[i] = groups[i];
    }
}
bool *Exams::getGroups()
{
    return groups;
}

void Exams::setId(int id)
{
    this->id = id;
}
int Exams::getid()
{
    return id;
}

Time &Exams::getTimeStart()
{
    return start;
}
Time &Exams::getTimeEnd()
{
    return end;
}

string Exams::getResponsible()
{
    return responsible;
}
void Exams::setResponsible(const string &newResponsible)
{
    responsible = newResponsible;
}

// Time Class -------------------------------------------------------------------

Time::Time() : Date{}, hour(0), minute(0) {}
Time::Time(const int hour, const int minute, const int day, const int month, const int year) : Date(day, month, year), hour(hour), minute(minute) {}
Time::~Time() {}

void Time::setHour(int hour)
{
    if (hour >= 0 && hour <= 23)
    {
        this->hour = hour;
    }
    else
    {
        // handle error
    }
}
int Time::getHour() const
{
    return this->hour;
}

void Time::setMinute(int minute)
{
    if (minute >= 0 && minute <= 59)
    {
        this->minute = minute;
    }
    else
    {
        // handle error
    }
}
int Time::getMinute() const
{
    return this->minute;
}

void Time::setTime(int hour, int minute, int day, int month, int year)
{
    setHour(hour);
    setMinute(minute);
    setDate(day, month, year);
}

// Members Class -------------------------------------------------------------------

void Members::setName(const string &name)
{
    if (name != "")
    {
        this->name = name;
    }
    else
    {
        this->name = "Unknown";
    }
}
string Members::getName() const
{
    return name;
}
void Members::setId(const long int &id)
{
    if (id > 0)
    {
        this->id = id;
    }
    else
    {
        this->id = 0;
    }
}
long int Members::getId() const
{
    return id;
}
void Members::setPassword(const string &password)
{
    if (password != "")
    {
        this->password = password;
    }
    else
    {
        this->password = "x";
    }
}
string Members::getPassword() const
{
    return password;
}
void Members::setEmail(const string &email)
{
    if (email != "")
    {
        this->email = email;
    }
    else
    {
        this->email = "";
    }
}
string Members::getEmail() const
{
    return email;
}
void Members::setPhone(const string &phone)
{
    if (phone != "")
    {
        this->phone = phone;
    }
    else
    {
        this->phone = "0000000000";
    }
}
string Members::getPhone() const
{
    return phone;
}
void Members::setAddress(const string &address)
{
    if (address != "")
    {
        this->address = address;
    }
    else
    {
        this->address = "Unknown";
    }
}
string Members::getAddress() const
{
    return address;
}
void Members::setCourses(const vector<Courses *> &courses)
{
    this->courses = courses;
}
vector<Courses *> Members::getCourses() const
{
    return courses;
}
void Members::setBirthDate(int day, int month, int year)
{
    this->BD.setDay(day);
    this->BD.setMonth(month);
    this->BD.setYear(year);
}
Date &Members::getBirthDate()
{
    return BD;
};

void Members::setevent(const string &event, QDateTime &time, int index)
{
    cout << this->name << endl;
    if (index < performance.size())
    {
        performance[index] = event;
        dates[index] = time;
    }
    else
    {
        performance.push_back(event);
        dates.push_back(time);
    }
}
string Members::getevent(int index)
{
    if (index < performance.size())
        return performance[index];
    else
        return "";
}
QDateTime &Members::geteventtime(int index)
{
    if (index < dates.size())
        return dates[index];
}
vector<string> *Members::getevents()
{
    return &performance;
}
vector<QDateTime> *Members::geteventstime()
{
    return &dates;
}

Members::Members() : courses{}
{
    name = "Unknown";
    id = 0;
    password = "x";
    email = "email@ensia.edu.dz";
    phone = "0000000000";
    address = "Unknown";
    totalmembers++;
    performance.resize(0);
    dates.resize(0);
}
Members::Members(const string &name, const string &password, const string &email, const string &phone, const string &address, const vector<Courses *> &courses, int day, int month, int year)
{

    // default id :
    setId(totalmembers);

    // Checking Name
    if (name != "")
    {
        setName(name);
    }
    else
    {
        cerr << "Name is Empty!" << endl;
    }

    // Checking Password
    if (password != "")
    {
        setPassword(password);
    }
    else
    {
        cerr << "Password is Empty!" << endl;
    }

    // Checking Email
    if (email != "")
    {
        setEmail(email);
    }
    else
    {
        cerr << "Email is Empty!" << endl;
    }

    // Checking Phone
    if (phone != "")
    {
        setPhone(phone);
    }
    else
    {
        cerr << "Phone is Empty!" << endl;
    }

    // Checking Address
    if (address != "")
    {
        setAddress(address);
    }
    else
    {
        cerr << "Address is Empty!" << endl;
    }

    // Checking Course

    this->courses.resize(courses.size());

    for (int i = 0; i < courses.size(); i++)
    {
        if (courses[i] != nullptr)
        {
            this->courses[i] = new Courses(*courses[i]); // Copy constructor
        }
        else
        {
            this->courses[i] = new Courses(); // Default constructor
        }
    }

    // The schedule is combination of the courses schedule sorted by time
    totalmembers++;

    // events

    // Birth Date
    setBirthDate(day, month, year);
}

string (*Members::getSchedule())[2]
{
    return schedule;
};
bool Members::fixschedule() {
    // check if there is no overlapping
};
void Members::setSchedule(int a, int b, string newSchedule)
{
    schedule[a][b] = newSchedule;
};

// Teachers Class -------------------------------------------------------------------

Teachers::Teachers() : Members{}
{
    totalteachers++;
    for (int i = 1; i < 12; i++)
    {
        groups[i] = false;
    }
    for (int i = 0; i < 12; i++)
    {
        type[i] = 0;
    }

    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            schedule[i][j] = "";
        }
    }

    // cout << "Teacher " << name << " with ID " << id << " has been added." << endl;
};
Teachers::Teachers(string name, string password, string email, string phone, string address, vector<Courses *> course, bool groups[12], int day, int month, int year, int type[12])
    : Members{name, password, email, phone, address, course, day, month, year}
{
    totalteachers++;
    setId(ENSIA.getTeachers().size());
    ENSIA.addTeacher(this);

    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            schedule[i][j] = "";
        }
    }

    for (int i = 0; i < 12; i++)
    {
        setType(i, type[i]);
    }

    for (int i = 0; i < 12; i++)
    {
        this->groups[i] = groups[i];
    }

    // cout << "Teacher " << name << " with ID " << id << " has been added." << endl;
};
Teachers::~Teachers() {
    // cout << "Teacher " << name << " with ID " << id << " has been Removed." << endl;
};
void Teachers::addCourse(Courses *course)
{
    // Check if the course is already added
    for (auto it = courses.begin(); it != courses.end(); ++it)
    {
        if (*it == course)
        {
            return;
        }
    }

    if (course != nullptr)
    {
        courses.push_back(course);
    }
};
void Teachers::removeCourse(int index)
{
    for (int i = 0; i < courses.size(); i++)
    {
        if (courses[i]->getId() == index)
        {
            courses.erase(courses.begin() + i);
        }
    }
}
bool Teachers::fixschedule()
{
    // Initialize a vector of bools to represent each minute of the day
    vector<bool> timeSlots(24 * 60, false);

    for (const auto &course : courses)
    {
        // Convert the start and end times of the courses to QTime
        QTime start = QTime::fromString(QString::fromStdString(course->getSchedule()[0][0]), "hh:mm");
        QTime end = QTime::fromString(QString::fromStdString(course->getSchedule()[0][1]), "hh:mm");

        // Convert QTime to minutes since start of day
        int startMinutes = start.hour() * 60 + start.minute();
        int endMinutes = end.hour() * 60 + end.minute();

        // Check each minute in the course's time slot
        for (int i = startMinutes; i < endMinutes; ++i)
        {
            // If the time slot is already occupied, there is an overlap
            if (timeSlots[i])
            {
                return false;
            }

            // Mark the time slot as occupied
            timeSlots[i] = true;
        }
    }

    return true;
}
// Getters and Setters

void Teachers::setGroups(const bool newgroups[12])
{
    for (int i = 0; i < 12; i++)
    {
        groups[i] = newgroups[i];
    }
};
bool *Teachers::getGroups()
{
    return groups;
};
int *Teachers::getType()
{
    return type;
}
void Teachers::setType(int index, int type)
{
    if (type == 1 || type == 2 || type == 3 || type == 0)
    {
        this->type[index] = type;
    }
    else
    {
        this->type[index] = 1;
    }

    return;
}

// Students Class -------------------------------------------------------------------

Students::Students(string name, string password, string email, string phone, string address, vector<Courses *> course, int Group, int schoolYear, int section, int day, int month, int year)
    : Members(name, password, email, phone, address, course, day, month, year), group(Group), schoolYear(schoolYear), section(section)
{
    // const string &name, const string &password, const string &email, const string &phone, const string &address, const vector<Courses *> &courses, const Date &birthDate
    totalstudents++;
    setId(ENSIA.getStudents().size());

    // cout << "Student " << name << " with ID " << id << " has been added." << endl;
    ENSIA.addStudent(this);
}
void Students::setYear(const int schoolYear)
{
    this->schoolYear = schoolYear;
}
int Students::getYear()
{
    return schoolYear;
}
void Students::setSection(const int newSection)
{
    section = newSection;
}
int Students::getSection()
{
    return section;
}
Students::Students() : Results{}, group{0}, Members{}, schoolYear{1}, section{1}
{
    totalstudents++;
    setId(ENSIA.getStudents().size());
    // cout << "Student " << name << " with ID " << id << " has been added." << endl;
    ENSIA.addStudent(this);
}
Students::~Students()
{
    for (int i = 0; i < Results.size(); i++)
    {
        delete Results[i];
    }
}

vector<Exams *> Students::getResults()
{
    return Results;
};
vector<double> Students::getResultsValue()
{
    return ResultsValue;
};
void Students::setResult(int index = 0, Exams *exam = nullptr)
{
    Results[index] = exam;
};
void Students::setResultvalue(int index = 0, double value = 10)
{
    ResultsValue[index] = value;
};
void Students::setResultvalue(Exams *exam, double value)
{
    for (int i = 0; i < Results.size(); i++)
    {
        if (Results[i] == exam)
        {
            ResultsValue[i] = value;
        }
    }
};

void Students::addCourse(Courses *course)
{
    // scan if the course is already added
    for (int i = 0; i < courses.size(); i++)
    {
        if (courses[i] == course)
        {
            return;
        }
    }
    courses.push_back(course);
};
void Students::removeCourse(Courses *course)
{
    for (int i = 0; i < courses.size(); i++)
    {
        if (courses[i] == course)
        {
            courses.erase(courses.begin() + i);
        }
    }
};

string *Members::getAttendance()
{
    return Attendance;
};
int Students::getGroup()
{
    return group;
};
void Students::setGroup(const int newGroup)
{
    group = newGroup;
};
void Students::pushExam(Exams *exam)
{
    Results.push_back(exam);
}
void Students::removeExam(Exams *exam)
{
    for (int i = 0; i < Results.size(); i++)
    {
        if (Results[i] == nullptr)
        {
            continue;
        }
        if (Results[i]->getid() == exam->getid())
        {
            Results.erase(Results.begin() + i);
            ResultsValue.erase(ResultsValue.begin() + i);
        }
    }
}
bool Students::fixschedule()
{
    unordered_map<int, bool> timeSlots;

    // Iterate over all courses
    for (const auto &course : courses)
    {
        // Convert the start and end times of the courses to QTime
        QTime start = QTime::fromString(QString::fromStdString(course->getSchedule()[0][0]), "hh:mm");
        QTime end = QTime::fromString(QString::fromStdString(course->getSchedule()[0][1]), "hh:mm");

        // Convert QTime to minutes since start of day
        int startMinutes = start.hour() * 60 + start.minute();
        int endMinutes = end.hour() * 60 + end.minute();

        // Check each minute in the course's time slot
        for (int i = startMinutes; i < endMinutes; ++i)
        {
            // If the time slot is already occupied, there is an overlap
            if (timeSlots[i])
            {
                return false;
            }

            // Mark the time slot as occupied
            timeSlots[i] = true;
        }
    }

    return true;
}
void Students::pushExamResult(double value)
{
    ResultsValue.push_back(value);
}

//   -------------------------------------------- School - Class --------------------------------------------

// Constructors and Destructor

School::School() : teachers{}, courses{}, students{}, exams{}
{
    // cout << "School has been created." << endl;
};
School::School(const vector<Students *> &students, const vector<Teachers *> &teachers, const vector<Courses *> &courses, const vector<Exams *> &exams)
{
    this->students = students;
    this->teachers = teachers;
    this->courses = courses;
    this->exams = exams;

    // cout << "School has been created." << endl;
}
School::~School()
{
    for (auto student : students)
    {
        delete student;
    }
    students.clear();

    for (auto teacher : teachers)
    {
        delete teacher;
    }
    teachers.clear();

    for (auto course : courses)
    {
        delete course;
    }
    courses.clear();

    for (auto exam : exams)
    {
        delete exam;
    }

    cout << "School has been removed." << endl;
}
void School::setCourses(const vector<Courses *> &courses)
{
    this->courses = courses;
}
void School::setStudents(const vector<Students *> &students)
{
    this->students = students;
}
void School::setTeachers(const vector<Teachers *> &teachers)
{
    this->teachers = teachers;
}
void School::setExams(const vector<Exams *> &exams)
{
    this->exams = exams;
}

// Add Objects to the Lists

void School::pushstudent(Students *s, int group)
{
    switch (group)
    {
    case 1:
        g1.push_back(s);
        break;
    case 2:
        g2.push_back(s);
        break;
    case 3:
        g3.push_back(s);
        break;
    case 4:
        g4.push_back(s);
        break;
    case 5:
        g5.push_back(s);
        break;
    case 6:
        g6.push_back(s);
        break;
    case 7:
        g7.push_back(s);
        break;
    case 8:
        g8.push_back(s);
        break;
    case 9:
        g9.push_back(s);
        break;
    case 10:
        g10.push_back(s);
        break;
    case 11:
        g11.push_back(s);
        break;
    case 12:
        g12.push_back(s);
        break;
    default:
        cout << "Invalid group number." << endl;
        break;
    }
}

vector<Students *> School::getGroup(int index)
{
    switch (index)
    {
    case 1:
        return g1;
        break;
    case 2:
        return g2;
        break;
    case 3:
        return g3;
        break;
    case 4:
        return g4;
        break;
    case 5:
        return g5;
        break;
    case 6:
        return g6;
        break;
    case 7:
        return g7;
        break;
    case 8:
        return g8;
        break;
    case 9:
        return g9;
        break;
    case 10:
        return g10;
        break;
    case 11:
        return g11;
        break;
    case 12:
        return g12;
        break;
    default:
        cout << "Invalid group number." << endl;
        break;
    }
}

void School::popstudent(Students *s, int group)
{
    switch (group)
    {
    case 1:
        g1.erase(remove(g1.begin(), g1.end(), s), g1.end());
        break;
    case 2:
        g2.erase(remove(g2.begin(), g2.end(), s), g2.end());
        break;
    case 3:
        g3.erase(remove(g3.begin(), g3.end(), s), g3.end());
        break;
    case 4:
        g4.erase(remove(g4.begin(), g4.end(), s), g4.end());
        break;
    case 5:
        g5.erase(remove(g5.begin(), g5.end(), s), g5.end());
        break;
    case 6:
        g6.erase(remove(g6.begin(), g6.end(), s), g6.end());
        break;
    case 7:
        g7.erase(remove(g7.begin(), g7.end(), s), g7.end());
        break;
    case 8:
        g8.erase(remove(g8.begin(), g8.end(), s), g8.end());
        break;
    case 9:
        g9.erase(remove(g9.begin(), g9.end(), s), g9.end());
        break;
    case 10:
        g10.erase(remove(g10.begin(), g10.end(), s), g10.end());
        break;
    case 11:
        g11.erase(remove(g11.begin(), g11.end(), s), g11.end());
        break;
    case 12:
        g12.erase(remove(g12.begin(), g12.end(), s), g12.end());
        break;
    default:
        cout << "Invalid group number." << endl;
        break;
    }
}

void School::addStudent(Students *student)
{
    if (student != nullptr)
    {
        student->setId(students.size());
        this->students.push_back(student);
    }
}
void School::addCourse(Courses *course)
{
    if (course != nullptr)
    {
        course->setId(courses.size());
        this->courses.push_back(course);
        // cout << "Course " << course->getName() << " with ID : " << course->getId() << " has been added." << endl;
    }
}
void School::addTeacher(Teachers *teacher)
{
    if (teacher != nullptr)
    {
        teacher->setId(teachers.size());
        this->teachers.push_back(teacher);
    }
}
void School::addExam(Exams *exam)
{
    if (exam != nullptr)
    {
        exam->setId(exams.size());
        this->exams.push_back(exam);
    }
}
Students *School::getStudents(string name)
{
    for (int i = 0; i < students.size(); i++)
    {
        if (students[i]->getName() == name)
        {
            return students[i];
        }
    }
    return nullptr;
}
void School::pushexam(Exams *e, int group)
{
    switch (group)
    {
    case 1:
        for (auto student : g1)
        {
            student->pushExam(e);
            student->pushExamResult(0.0);
        }
        break;
    case 2:
        for (auto student : g2)
        {
            student->pushExam(e);
            student->pushExamResult(0.0);
        }
        break;
    case 3:
        for (auto student : g3)
        {
            student->pushExam(e);
            student->pushExamResult(0.0);
        }
        break;
    case 4:
        for (auto student : g4)
        {
            student->pushExam(e);
            student->pushExamResult(0.0);
        }
        break;
    case 5:
        for (auto student : g5)
        {
            student->pushExam(e);
            student->pushExamResult(0.0);
        }
        break;
    case 6:
        for (auto student : g6)
        {
            student->pushExam(e);
            student->pushExamResult(0.0);
        }
        break;
    case 7:
        for (auto student : g7)
        {
            student->pushExam(e);
            student->pushExamResult(0.0);
        }
        break;
    case 8:
        for (auto student : g8)
        {
            student->pushExam(e);
            student->pushExamResult(0.0);
        }
        break;
    case 9:
        for (auto student : g9)
        {
            student->pushExam(e);
            student->pushExamResult(0.0);
        }
        break;
    case 10:
        for (auto student : g10)
        {
            student->pushExam(e);
            student->pushExamResult(0.0);
        }
        break;
    case 11:
        for (auto student : g11)
        {
            student->pushExam(e);
            student->pushExamResult(0.0);
        }
        break;
    case 12:
        for (auto student : g12)
        {
            student->pushExam(e);
            student->pushExamResult(0.0);
        }
        break;
    // Ensure to handle default case
    default:
        // Handle error or unexpected group number
        break;
    }
}

// Removing Objects From the Lists

void School::removeStudent(int index)
{
    students.erase(students.begin() + index);
    // remove him from his group
    for (int i = 1; i < 13; i++)
    {
        switch (i)
        {
        case 1:
            g1.erase(remove(g1.begin(), g1.end(), students[index]), g1.end());
            break;
        case 2:
            g2.erase(remove(g2.begin(), g2.end(), students[index]), g2.end());
            break;
        case 3:
            g3.erase(remove(g3.begin(), g3.end(), students[index]), g3.end());
            break;
        case 4:
            g4.erase(remove(g4.begin(), g4.end(), students[index]), g4.end());
            break;
        case 5:
            g5.erase(remove(g5.begin(), g5.end(), students[index]), g5.end());
            break;
        case 6:
            g6.erase(remove(g6.begin(), g6.end(), students[index]), g6.end());
            break;
        case 7:
            g7.erase(remove(g7.begin(), g7.end(), students[index]), g7.end());
            break;
        case 8:
            g8.erase(remove(g8.begin(), g8.end(), students[index]), g8.end());
            break;
        case 9:
            g9.erase(remove(g9.begin(), g9.end(), students[index]), g9.end());
            break;
        case 10:
            g10.erase(remove(g10.begin(), g10.end(), students[index]), g10.end());
            break;
        case 11:
            g11.erase(remove(g11.begin(), g11.end(), students[index]), g11.end());
            break;
        case 12:
            g12.erase(remove(g12.begin(), g12.end(), students[index]), g12.end());
            break;
        }
    }

    // Reduce the id of students after the specified index
    for (int i = index; i < students.size(); i++)
    {
        students[i]->setId(students[i]->getId() - 1);
    }
    Students::totalstudents--;
}
void School::removeTeacher(int index)
{
    teachers.erase(teachers.begin() + index);

    // Reduce the id of teachers after the specified index
    for (int i = index; i < teachers.size(); i++)
    {
        teachers[i]->setId(teachers[i]->getId() - 1);
    }
    Teachers::totalteachers--;
}
void School::removeCourse(int index)
{

    // remove the course from any teacher if any teacher has that course :
    for (int i = 0; i < teachers.size(); i++)
    {
        for (int j = teachers[i]->getCourses().size() - 1; j >= 0; j--)
        {
            if (teachers[i]->getCourses()[j]->getId() == index)
            {
                teachers[i]->removeCourse(j);
            }
        }
    }

    courses.erase(courses.begin() + index);

    // Remove it from the list of exams
    for (int i = 0; i < exams.size(); i++)
    {
        if (exams[i]->getModule()->getId() == index)
        {
            exams.erase(exams.begin() + i);
        }
    }

    // Reduce the id of courses after the specified index
    for (int i = index; i < courses.size(); i++)
    {
        courses[i]->setId(courses[i]->getId() - 1);
    }
    Courses::totalcourses--;
}
void School::removeExam(int index)
{
    exams.erase(exams.begin() + index);
    // Remove the exam from the students
    for (int i = 0; i < students.size(); i++)
    {
        for (int j = 0; j < students[i]->getResults().size(); j++)
        {
            if (students[i]->getResults()[j]->getid() == index)
            {
                students[i]->removeExam(students[i]->getResults()[j]);
            }
        }
    }

    // Reduce the id of exams after the specified index
    for (int i = index; i < exams.size(); i++)
    {
        exams[i]->setId(exams[i]->getid() - 1);
    }
    Exams::totalexams--;
}

// Getters

vector<Courses *> School::getCourses()
{
    return courses;
}
vector<Students *> School::getStudents()
{
    return students;
}
vector<Teachers *> School::getTeachers()
{
    return teachers;
}
vector<Exams *> School::getExams()
{
    return exams;
}


// Data and File Handling

// Courses --------------------------------------------
void Courses::save(const vector<Courses *> &coursesList)
{

    // Open the file in trunc mode to clear its contents
    ofstream file("Courses.txt", ios::out | ios::trunc);
    if (!file.is_open())
    {
        cerr << "Error opening file: " << strerror(errno) << endl;
        return;
    }

    for (const auto &course : coursesList)
    {
        file << course->name << endl;
        for (int i = 0; i < 7; i++)
        {
            file << course->schedule[i][0] << "," << course->schedule[i][1] << endl;
        }
        for (int i = 0; i < 12; i++)
        {
            file << (course->groups[i] ? "1" : "0");
            if (i < 11)
                file << ",";
        }
        file << endl;
        file << course->id << endl;
        file << endl; // Add a separator between courses
    }
    file.close();
}
vector<Courses *> Courses::load()
{
    ifstream file("Courses.txt");
    vector<Courses *> coursesList;
    if (!file.is_open())
    {
        cerr << "Error opening file: " << strerror(errno) << endl;
        return coursesList;
    }

    string line;
    while (getline(file, line))
    {
        if (line.empty())
            continue; // Skip empty lines

        Courses *course = new Courses();
        course->name = line;

        for (int i = 0; i < 7; ++i)
        {
            if (!getline(file, line))
                break;
            stringstream ss(line);
            getline(ss, course->schedule[i][0], ',');
            getline(ss, course->schedule[i][1]);
        }

        if (!getline(file, line))
            break;
        stringstream ss(line);
        for (int i = 0; i < 12; ++i)
        {
            char group;
            ss >> group;
            course->groups[i] = (group == '1');
            if (i < 11)
                ss.ignore();
        }

        if (!getline(file, line))
            break;
        course->id = stoi(line);

        coursesList.push_back(course);

        getline(file, line); // Read the separator line
    }
    file.close();
    return coursesList;
}

// Exams --------------------------------------------
void Exams::save(const vector<Exams *> &examsList)
{
    ofstream file("Exams.txt", ios::out | ios::trunc);
    if (!file.is_open())
    {
        cerr << "Error opening file: " << strerror(errno) << endl;
        return;
    }

    for (const auto &exam : examsList)
    {
        file << exam->start.getYear() << "-" << exam->start.getMonth() << "-" << exam->start.getDay()
             << "," << exam->start.getHour() << ":" << exam->start.getMinute()
             << "," << exam->end.getYear() << "-" << exam->end.getMonth() << "-" << exam->end.getDay()
             << "," << exam->end.getHour() << ":" << exam->end.getMinute() << endl;

        for (int i = 0; i < 12; ++i)
        {
            file << (exam->groups[i] ? "1" : "0");
            if (i < 11)
                file << ",";
        }
        file << endl;

        file << exam->id << endl;
        file << (exam->Module ? exam->Module->getId() : -1) << endl;
        file << exam->responsible << endl;
        file << endl; // Add a separator between exams
    }
    file.close();
}
vector<Exams *> Exams::load()
{
    ifstream file("Exams.txt");
    vector<Exams *> examsList;
    if (!file.is_open())
    {
        cerr << "Error opening file: " << strerror(errno) << endl;
        return examsList;
    }

    string line;
    while (getline(file, line))
    {
        if (line.empty())
            continue; // Skip empty lines

        Exams *exam = new Exams();
        stringstream ss(line);
        string start_date, start_time, end_date, end_time;

        getline(ss, start_date, ',');
        getline(ss, start_time, ',');
        getline(ss, end_date, ',');
        getline(ss, end_time);

        int startYear, startMonth, startDay, startHour, startMinute;
        int endYear, endMonth, endDay, endHour, endMinute;

        sscanf(start_date.c_str(), "%d-%d-%d", &startYear, &startMonth, &startDay);
        sscanf(start_time.c_str(), "%d:%d", &startHour, &startMinute);
        sscanf(end_date.c_str(), "%d-%d-%d", &endYear, &endMonth, &endDay);
        sscanf(end_time.c_str(), "%d:%d", &endHour, &endMinute);

        Time startTime(startHour, startMinute, startDay, startMonth, startYear);
        Time endTime(endHour, endMinute, endDay, endMonth, endYear);
        exam->setDate(startTime, endTime);

        if (!getline(file, line))
            break;
        stringstream groupStream(line);
        for (int i = 0; i < 12; ++i)
        {
            char group;
            groupStream >> group;
            exam->groups[i] = (group == '1');
            if (i < 11)
                groupStream.ignore();
        }

        if (!getline(file, line))
            break;
        exam->id = stoi(line);

        if (!getline(file, line))
            break;
        int moduleId = stoi(line);
        exam->Module = nullptr;
        for (auto course : ENSIA.getCourses())
        {
            if (course->getId() == moduleId)
            {
                exam->Module = course;
                break;
            }
        }

        if (!getline(file, line))
            break;
        exam->responsible = line;

        examsList.push_back(exam);

        getline(file, line); // Read the separator line
    }
    file.close();
    return examsList;
}

// Students --------------------------------------------
void Students::save(const vector<Students *> &studentsList)
{
    ofstream file("Students.txt", ios::out | ios::trunc);
    if (!file.is_open())
    {
        cerr << "Error opening file: " << strerror(errno) << endl;
        return;
    }

    for (const auto &student : studentsList)
    {
        file << student->name << endl;
        file << student->id << endl;
        file << student->password << endl;
        file << student->email << endl;
        file << student->phone << endl;
        file << student->address << endl;

        for (int i = 0; i < 7; i++)
        {
            file << student->schedule[i][0] << "," << student->schedule[i][1] << endl;
        }

        file << student->group << endl;
        file << student->section << endl;
        file << student->schoolYear << endl;

        for (int i = 0; i < 3; i++)
        {
            file << student->Attendance[i];
            if (i < 2)
                file << ",";
        }
        file << endl;

        for (const auto &course : student->courses)
        {
            file << course->getId() << ",";
        }
        file << endl;

        file << student->BD.getDay() << "-" << student->BD.getMonth() << "-" << student->BD.getYear() << endl;

        // save student results
        file << student->Results.size() << endl;
        for (int i = 0; i < student->Results.size(); i++)
        {
            file << student->Results[i]->getid() << "," << student->ResultsValue[i] << endl;
        }
        file << endl; // Add a separator between students
    }
    file.close();
}
vector<Students *> Students::load()
{
    ifstream file("Students.txt");
    vector<Students *> studentsList;
    if (!file.is_open())
    {
        cerr << "Error opening file: " << strerror(errno) << endl;
        return studentsList;
    }

    string line;
    while (getline(file, line))
    {
        if (line.empty())
            continue; // Skip empty lines

        Students *student = new Students();
        student->name = line;

        if (!getline(file, line))
            break;
        student->id = stol(line);

        if (!getline(file, student->password))
            break;
        if (!getline(file, student->email))
            break;
        if (!getline(file, student->phone))
            break;
        if (!getline(file, student->address))
            break;

        for (int i = 0; i < 7; i++)
        {
            if (!getline(file, line))
                break;
            size_t commaPos = line.find(',');
            student->schedule[i][0] = line.substr(0, commaPos);
            student->schedule[i][1] = line.substr(commaPos + 1);
        }

        if (!getline(file, line))
            break;
        student->group = stoi(line);

        if (!getline(file, line))
            break;
        student->section = stoi(line);

        if (!getline(file, line))
            break;
        student->schoolYear = stoi(line);

        if (!getline(file, line))
            break;
        stringstream ssAttendance(line);
        for (int i = 0; i < 3; i++)
        {
            getline(ssAttendance, student->Attendance[i], ',');
        }

        if (!getline(file, line))
            break;
        stringstream ssCourses(line);
        string courseId;
        while (getline(ssCourses, courseId, ','))
        {
            if (!courseId.empty())
            {
                for (auto course : ENSIA.getCourses())
                {
                    if (course->getId() == stoi(courseId))
                    {
                        student->courses.push_back(course);
                        break;
                    }
                }
            }
        }

        if (!getline(file, line))
            break;
        int day, month, year;
        sscanf(line.c_str(), "%d-%d-%d", &day, &month, &year);
        student->BD = Date(day, month, year);

        // Load student results
        if (!getline(file, line))
            break;
        int resultsCount = stoi(line);
        for (int i = 0; i < resultsCount; i++)
        {
            if (!getline(file, line))
                break;
            stringstream ssResults(line);
            string examIdStr, resultStr;
            getline(ssResults, examIdStr, ',');
            getline(ssResults, resultStr);
            try
            {
                int examId = stoi(examIdStr);
                double result = stod(resultStr);
                bool examFound = false;
                for (auto exam : ENSIA.getExams())
                {
                    if (exam->getid() == examId)
                    {
                        student->Results.push_back(exam);
                        student->ResultsValue.push_back(result);
                        examFound = true;
                        break;
                    }
                }
                if (!examFound)
                {
                    cerr << "Exam ID " << examId << " not found." << endl;
                }
            }
            catch (const invalid_argument &e)
            {
                cerr << "Invalid result value: " << resultStr << ". Error: " << e.what() << endl;
            }
            catch (const out_of_range &e)
            {
                cerr << "Result value out of range: " << resultStr << ". Error: " << e.what() << endl;
            }
        }

        studentsList.push_back(student);
        ENSIA.pushstudent(student, student->group);

        getline(file, line); // Read the separator line
    }
    file.close();
    return studentsList;
}

// Teachers --------------------------------------------
void Teachers::save(const vector<Teachers *> &teachersList)
{
    ofstream file("Teachers.txt", ios::out | ios::trunc); // Open for writing and truncate the file if it exists
    if (!file.is_open())
    {
        cout << "Error opening file: " << strerror(errno) << endl;
        return;
    }

    for (const auto &teacher : teachersList)
    {
        // Directly access private members since this function is a static member of the Teachers class
        file << teacher->name << endl;
        file << teacher->id << endl;
        file << teacher->password << endl;
        file << teacher->email << endl;
        file << teacher->phone << endl;
        file << teacher->address << endl;
        for (const auto &course : teacher->courses) // Assuming courses is a vector of pointers to Courses
        {
            file << course->getId() << ",";
        }
        file << endl;
        for (int i = 0; i < 12; ++i)
        {
            file << teacher->groups[i] << ",";
        }
        file << endl;
        for (int i = 0; i < 12; ++i)
        {
            file << teacher->type[i] << ",";
        }
        file << endl;
        // Assuming a Date structure or class is used for birthDate
        file << teacher->BD.getDay() << "-" << teacher->BD.getMonth() << "-" << teacher->BD.getYear() << endl;
        // print the performance size
        file << teacher->performance.size() << " ";
        for (int i = 0; i < teacher->performance.size(); i++)
        {
            file << teacher->performance[i] << ",";
        }
        file << endl;
        file << teacher->dates.size() << " ";
        for (int i = 0; i < teacher->dates.size(); i++)
        {
            file << teacher->dates[i].toString().toStdString() << ",";
        }
        file << endl;
    }
    file.close();
}
vector<Teachers *> Teachers::load()
{
    vector<Teachers *> teachersList;
    ifstream file("Teachers.txt", ios::in);
    if (file.peek() == ifstream::traits_type::eof())
    {
        cout << "File is empty, skipping loading." << endl;
        return teachersList; // Exit the function if the file is empty
    }
    string line;

    if (!file.is_open())
    {
        cout << "Error opening file: " << strerror(errno) << endl;
        return teachersList;
    }

    while (getline(file, line))
    {
        Teachers *teacher = new Teachers();
        teacher->name = line;

        if (!getline(file, line))
            break;
        try
        {
            teacher->id = stol(line);
        }
        catch (const invalid_argument &e)
        {
            cout << "Invalid ID encountered: " << line << ". Error: " << e.what() << endl;
            delete teacher;
            break;
        }

        if (!getline(file, teacher->password))
            break;
        if (!getline(file, teacher->email))
            break;
        if (!getline(file, teacher->phone))
            break;
        if (!getline(file, teacher->address))
            break;

        // Load courses
        if (!getline(file, line))
            break;
        stringstream ssCourses(line);
        string courseId;
        while (getline(ssCourses, courseId, ','))
        {
            if (!courseId.empty())
            {
                try
                {
                    int courseIdInt = stoi(courseId);
                    for (auto course : ENSIA.getCourses())
                    {
                        if (course->getId() == courseIdInt)
                        {
                            teacher->courses.push_back(course);
                            break;
                        }
                    }
                }
                catch (const invalid_argument &e)
                {
                    cerr << "Invalid courseId: " << courseId << endl;
                }
            }
        }

        // Load groups
        if (!getline(file, line))
            break;
        stringstream ssGroups(line);
        string group;
        int groupIndex = 0;
        while (getline(ssGroups, group, ',') && groupIndex < 12)
        {
            teacher->groups[groupIndex++] = (group == "1");
        }

        // Load types
        if (!getline(file, line))
            break;
        stringstream ssTypes(line);
        for (int i = 0; i < 12; ++i)
        {
            string typeStr;
            if (getline(ssTypes, typeStr, ','))
            {
                try
                {
                    teacher->type[i] = stoi(typeStr);
                }
                catch (const invalid_argument &e)
                {
                    cerr << "Invalid type value: " << typeStr << ". Error: " << e.what() << endl;
                    teacher->type[i] = 0; // Set a default value
                }
            }
            else
            {
                teacher->type[i] = 0; // Set a default value if not enough values are provided
            }
        }

        // Load birthDate
        if (!getline(file, line))
            break;
        int day, month, year;
        if (sscanf(line.c_str(), "%d-%d-%d", &day, &month, &year) == 3)
        {
            teacher->BD.setDate(day, month, year);
        }
        else
        {
            cerr << "Invalid birth date format: " << line << endl;
        }

        // Read the performance vector size and content
        if (!getline(file, line))
            break;
        int performanceSize;
        stringstream ssPerformanceSize(line);
        ssPerformanceSize >> performanceSize;
        if (performanceSize > 0)
        {
            if (!getline(file, line))
                break; // Read the performance data line
            stringstream ssPerformance(line);
            for (int i = 0; i < performanceSize; i++)
            {
                string perfItem;
                if (getline(ssPerformance, perfItem, ','))
                {
                    teacher->performance.push_back(perfItem);
                }
            }
        }

        // Read the dates vector size and content
        if (!getline(file, line))
            break;
        int datesSize;
        stringstream ssDatesSize(line);
        ssDatesSize >> datesSize;
        if (datesSize > 0)
        {
            if (!getline(file, line))
                break; // Read the dates data line
            stringstream ssDates(line);
            for (int i = 0; i < datesSize; i++)
            {
                string dateStr;
                if (getline(ssDates, dateStr, ','))
                {
                    QDateTime date = QDateTime::fromString(QString::fromStdString(dateStr), "yyyy-MM-dd hh:mm:ss");
                    teacher->dates.push_back(date);
                }
            }
        }

        teachersList.push_back(teacher);
    }
    file.close();
    return teachersList;
}
