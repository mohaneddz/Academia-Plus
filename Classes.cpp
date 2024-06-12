#include "Classes.h"

// Static Counters

int Teachers::totalteachers = 0;
int Students::totalstudents = 0;
int Courses::totalcourses = 0;
int Exams::totalexams = 0;
int Members::totalmembers = 0;

// Forward Declaration

School ENSIA;

// Courses Class --------------------------------------------

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
void Courses::setSchedule(const string schedule[7])
{
    for (int i = 0; i < 7; i++)
    {
        this->schedule[i] = schedule[i];
    }
}
void Courses::setId(const int id)
{
    this->id = id;
}
// nlohmann::json Courses::saveData()
// {
//     nlohmann::json j;
//     j["name"] = name;
//     j["schedule"] = std::vector<std::string>(std::begin(schedule), std::end(schedule));
//     j["groups"] = std::vector<bool>(std::begin(groups), std::end(groups));
//     j["id"] = id;
//     return j;
// };
// void Courses::readData(const nlohmann::json &j)
// {
//     name = j["name"];
//     std::vector<std::string> scheduleVec = j["schedule"];
//     std::copy(scheduleVec.begin(), scheduleVec.end(), schedule);
//     std::vector<bool> groupsVec = j["groups"];
//     std::copy(groupsVec.begin(), groupsVec.end(), groups);
//     id = j["id"];
// };

// Getters
string Courses::getName() const
{
    return name;
}
string *Courses::getSchedule()
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

// Constructors and Destructor

Courses::Courses()
{
    setName("Unknown");
    Courses::totalcourses++;

    for (int i = 1; i < 12; i++)
    {
        groups[i] = false;
    }
    // the schedule :
    schedule[0] = "";
    schedule[1] = "";
    schedule[2] = "";
    schedule[3] = "";
    schedule[4] = "";
    schedule[5] = "";
    schedule[6] = "";
}
Courses::Courses(const string &newName, string newSchedule[7], const bool newgroups[12])
{
    Courses::totalcourses++;
    schedule[1] = "";
    schedule[2] = "";
    schedule[3] = "";
    schedule[4] = "";
    schedule[5] = "";
    schedule[6] = "";

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

// Other methods

void Courses::printSchedule()
{
    for (int i = 0; i < 7; i++)
    {
        switch (i)
        {
        case 0:
            cout << "Sunday: " << schedule[i] << endl;
            break;
        case 1:
            cout << "Monday: " << schedule[i] << endl;
            break;
        case 2:
            cout << "Tuesday: " << schedule[i] << endl;
            break;
        case 3:
            cout << "Wednesday: " << schedule[i] << endl;
            break;
        case 4:
            cout << "Thursday: " << schedule[i] << endl;
            break;
        case 5:
            cout << "Friday: " << schedule[i] << endl;
            break;
        case 6:
            cout << "Saturday: " << schedule[i] << endl;
            break;
        }
    }
}

// Members Class --------------------------------------------

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

void Members::setSchedule(const string schedule[7])
{
    for (int i = 0; i < 7; i++)
    {
        this->schedule[i] = schedule[i];
    }
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

// Time Class --------------------------------------------

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

// Constructors and Destructor

Members::Members() : courses{}
{
    name = "Unknown";
    id = 0;
    password = "x";
    email = "email@ensia.edu.dz";
    phone = "0000000000";
    address = "Unknown";
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

    // Birth Date
    setBirthDate(day, month, year);
}

// Other methods

void Members::login()
{
    cout << "Welcome " << name << "!" << endl;
}
void Members::logout()
{
    cout << "Goodbye " << name << "!" << endl;
}
void Members::viewProfile()
{
    cout << "Name: " << name << endl;
    cout << "ID: " << id << endl;
    cout << "Email: " << email << endl;
    cout << "Phone: " << phone << endl;
    cout << "Address: " << address << endl;
    for (int i = 0; i < courses.size(); i++)
    {
        cout << "Course " << i + 1 << " : " << courses[i]->getName() << endl;
    }
}
void Members::editProfile()
{
    cout << "Enter New Name: ";
    cin >> name;
    cout << "Enter New Email: ";
    cin >> email;
    cout << "Enter New Phone: ";
    cin >> phone;
    cout << "Enter New Address: ";
    cin >> address;
}
void Members::changePassword()
{
    string oldPassword, newPassword;
    cout << "Enter Old Password: ";
    cin >> oldPassword;
    if (oldPassword == password)
    {
        cout << "Enter New Password: ";
        cin >> newPassword;
        password = newPassword;
    }
    else
    {
        cout << "Wrong Password!" << endl;
    }
}
void Members::viewCourses()
{
    for (int i = 0; i < courses.size(); i++)
    {
        cout << "Course " << i + 1 << " : " << courses[i]->getName() << endl;
    }
};
void Members::printSchedule()
{
    for (int i = 0; i < 7; i++)
    {
        switch (i)
        {
        case 0:
            cout << "Sunday: " << schedule[i] << endl;
            break;
        case 1:
            cout << "Monday: " << schedule[i] << endl;
            break;
        case 2:
            cout << "Tuesday: " << schedule[i] << endl;
            break;
        case 3:
            cout << "Wednesday: " << schedule[i] << endl;
            break;
        case 4:
            cout << "Thursday: " << schedule[i] << endl;
            break;
        case 5:
            cout << "Friday: " << schedule[i] << endl;
            break;
        case 6:
            cout << "Saturday: " << schedule[i] << endl;
            break;
        }
    }
}

// I will store the times in a vector, then sort them and store them in the schedule

void Members::SortSchedule()
{
    for (int i = 0; i < 7; i++)
    {
        std::vector<std::pair<int, std::string>> scheduleItems;

        for (int j = 0; j < courses.size(); j++)
        {
            std::string courseSchedule = courses[j]->getSchedule()[i];
            if (!courseSchedule.empty())
            {
                // Assuming the schedule string is in the format "HH:MM - HH:MM"
                int time = std::stoi(courseSchedule.substr(0, 2)) * 60 + std::stoi(courseSchedule.substr(3, 2));
                scheduleItems.push_back(std::make_pair(time, courseSchedule));
            }
        }

        // Sort scheduleItems by time
        std::sort(scheduleItems.begin(), scheduleItems.end());

        // Update the member's schedule
        std::stringstream daySchedule;
        for (const auto &item : scheduleItems)
        {
            if (!daySchedule.str().empty())
                daySchedule << " | ";
            daySchedule << item.second;
        }
        schedule[i] = daySchedule.str();
    }
}

// Members Class --------------------------------------------

// Constructors and Destructor

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

    cout << "Teacher " << name << " with ID " << id << " has been added." << endl;
};
Teachers::Teachers(string name, string password, string email, string phone, string address, std::vector<Courses *> course, bool groups[12], int day, int month, int year, int type[12])
    : Members{name, password, email, phone, address, course, day, month, year}
{
    totalteachers++;
    setId(ENSIA.getTeachers().size());
    ENSIA.addTeacher(this);
    schedule[0] = "";
    schedule[1] = "";
    schedule[2] = "";
    schedule[3] = "";
    schedule[4] = "";
    schedule[5] = "";
    schedule[6] = "";

    for (int i = 0; i < 12; i++)
    {
        setType(i, type[i]);
    }

    for (int i = 0; i < 12; i++)
    {
        this->groups[i] = groups[i];
    }

    cout << "Teacher " << name << " with ID " << id << " has been added." << endl;
};
Teachers::~Teachers(){
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

// methods

void Teachers::modifyschedule(const string schedule[7])
{

    for (int i = 0; i < 7; i++)
    {
        this->schedule[i] = schedule[i];
    }
};

//   -------------------------------------------- School - Class --------------------------------------------

// Constructors and Destructor

School::School() : teachers{}, courses{}, students{}, exams{}
{
    cout << "School has been created." << endl;
};
School::School(const std::vector<Students *> &students, const std::vector<Teachers *> &teachers, const std::vector<Courses *> &courses, const std::vector<Exams *> &exams)
{
    this->students = students;
    this->teachers = teachers;
    this->courses = courses;
    this->exams = exams;

    cout << "School has been created." << endl;
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
        g1.erase(std::remove(g1.begin(), g1.end(), s), g1.end());
        break;
    case 2:
        g2.erase(std::remove(g2.begin(), g2.end(), s), g2.end());
        break;
    case 3:
        g3.erase(std::remove(g3.begin(), g3.end(), s), g3.end());
        break;
    case 4:
        g4.erase(std::remove(g4.begin(), g4.end(), s), g4.end());
        break;
    case 5:
        g5.erase(std::remove(g5.begin(), g5.end(), s), g5.end());
        break;
    case 6:
        g6.erase(std::remove(g6.begin(), g6.end(), s), g6.end());
        break;
    case 7:
        g7.erase(std::remove(g7.begin(), g7.end(), s), g7.end());
        break;
    case 8:
        g8.erase(std::remove(g8.begin(), g8.end(), s), g8.end());
        break;
    case 9:
        g9.erase(std::remove(g9.begin(), g9.end(), s), g9.end());
        break;
    case 10:
        g10.erase(std::remove(g10.begin(), g10.end(), s), g10.end());
        break;
    case 11:
        g11.erase(std::remove(g11.begin(), g11.end(), s), g11.end());
        break;
    case 12:
        g12.erase(std::remove(g12.begin(), g12.end(), s), g12.end());
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
        cout << "Course " << course->getName() << " with ID : " << course->getId() << " has been added." << endl;
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

// Removing Objects From the Lists

void School::removeStudent(int index)
{
    students.erase(students.begin() + index);

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

    // Reduce the id of exams after the specified index
    for (int i = index; i < exams.size(); i++)
    {
        exams[i]->setId(exams[i]->getid() - 1);
    }
    Exams::totalexams--;
}

// Getters

std::vector<Courses *> School::getCourses()
{
    return courses;
}
std::vector<Students *> School::getStudents()
{
    return students;
}
std::vector<Teachers *> School::getTeachers()
{
    return teachers;
}
std::vector<Exams *> School::getExams()
{
    return exams;
}

// Constructors and Destructor

Students::Students(string name, string password, string email, string phone, string address, std::vector<Courses *> course, int Group, int schoolYear, int section, int day, int month, int year)
    : Members(name, password, email, phone, address, course, day, month, year), group(Group), schoolYear(schoolYear), section(section)
{
    // const string &name, const string &password, const string &email, const string &phone, const string &address, const vector<Courses *> &courses, const Date &birthDate
    totalstudents++;
    setId(ENSIA.getStudents().size());

    cout << "Student " << name << " with ID " << id << " has been added." << endl;
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
    cout << "Student " << name << " with ID " << id << " has been added." << endl;
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

void pushExam(Exams *exam) {

};
void pushExamResult(double value) {

};

// Methods

void Students::viewResults() {

};
string *Members::getAttendance()
{
    return Attendance;
};
void Students::viewSchedule() {

};
void Students::getAverage() {
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
        if (Results[i]->getid() == exam->getid() )
        {
            Results.erase(Results.begin() + i);
            ResultsValue.erase(ResultsValue.begin() + i);
        }
        
    }
    
}

void Students::pushExamResult(double value)
{
    ResultsValue.push_back(value);
}

// Exams --------------------------------------------

// Constructors and Destructor

Exams::Exams() : Module{}, Marks{}, start{}, end{}, groups{0}
{
    cout << "Exam has been created." << endl;
};
Exams::Exams(Courses *Module, float Marks[7], const Time *start, const Time *end, bool groups[12]) : Module{Module}, start{*start}, end{*end}, groups{static_cast<bool>(groups)}
{
    Exams::totalexams++;
    setId(ENSIA.getExams().size());
    ENSIA.addExam(this);
    for (int i = 0; i < 7; i++)
    {
        this->Marks[i] = Marks[i];
    }
    cout << "Exam has been created." << endl;
};
Exams::~Exams()
{
    cout << "Exam has been removed." << endl;
}

// Getters and Setters

void Exams::setModule(Courses *Module)
{
    this->Module = Module;
};
Courses *Exams::getModule()
{
    return Module;
};

void Exams::setMarks(const float Marks[7])
{
    for (int i = 0; i < 7; i++)
    {
        this->Marks[i] = Marks[i];
    }
};
float *Exams::getMarks()
{
    return Marks;
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

//  methods

void Exams::printMarks()
{
    for (int i = 0; i < 7; i++)
    {
        cout << "Marks " << i + 1 << " : " << Marks[i] << endl;
    }
};
void Exams::printDate() {
};
void Exams::printModule()
{
    cout << "Module: " << Module->getName() << endl;
};

// Date --------------------------------------------

Date::Date() : day(0), month(0), year(0) {}
Date::Date(int day, int month, int year) : day(day), month(month), year(year) {}
Date::~Date(){};

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
