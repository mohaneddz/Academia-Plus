#ifndef CLASSES_H
#define CLASSES_H

// #include <nlohmann/json.hpp>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

const int MAX_Courses = 10;
const int MAX_Members = 10;
const int MAX_Students = 10;
const int MAX_Teachers = 10;

// Date ---------------------------------------------------------------------------------------------------

class Date
{
protected:
    int day;
    int month;
    int year;

public:
    // Setters and Getters for day, month, and year

    Date();
    Date(int day, int month, int year);
    ~Date();

    void setDay(int day);
    int getDay() const;

    void setMonth(int month);
    int getMonth() const;

    void setYear(int year);
    int getYear() const;
};

class Time : public Date
{
protected:
    int hour;
    int minute;

public:
    Time();
    Time(const int hour, const int minute, const int day, const int month, const int year);
    ~Time();

    void setHour(int hour);
    int getHour() const;

    void setMinute(int minute);
    int getMinute() const;
};

// Courses ---------------------------------------------------------------------------------------------------

class Courses
{
private:
    string name;
    string schedule[7];
    bool groups[12];
    int id; // Unique identifier for each course

public:
    static int totalcourses; // Static member to keep track of the next id
    // Getters and Setters :{name, schedule, groups} --------------------------------------------
    // Name
    void setName(const string &name);
    string getName() const;

    void setSchedule(const string schedule[7]);
    string *getSchedule();

    int getId();
    void setId(const int newId);
    // Constructors and Destructor
    Courses();
    Courses(const string &newName, string newSchedule[7], const bool newgroups[12]);
    ~Courses();
    // Other methods

    void setGroups(const bool newgroups[12]);
    bool *getGroups();

    void printSchedule();

    // DATA :

    // nlohmann::json saveData();
    // void readData(const nlohmann::json &j);
};

// Exams ---------------------------------------------------------------------------------------------------

class Exams
{
private:
    Courses *Module;
    float Marks[7];
    Time start;
    Time end;
    bool groups[12];
    int id;
    string responsible;

public:
    int static totalexams;
    ~Exams();
    Exams();
    Exams(Courses *Module, float Marks[7], const Time *start, const Time *end, bool groups[12]);

    void setModule(Courses *Module);
    Courses *getModule();

    void setMarks(const float Marks[7]);
    float *getMarks();

    void setGroups(const bool groups[12]);
    bool *getGroups();

    Time &getTimeStart();
    Time &getTimeEnd();
    void setDate(const Time &start, const Time &end);

    void printMarks();
    void printDate();
    void printModule();

    void setId(int id);
    int getid();

    Time getStartDate();
    Time getEndtDate();

    string getResponsible();
    void setResponsible(const string &newResponsible);

    // nlohmann::json saveData();
    // void readData(const nlohmann::json &j);
};

// Members ---------------------------------------------------------------------------------------------------

class Members
{
protected:
    string name;
    long int id;
    string password;
    string email;
    string phone;
    string address;
    vector<Courses *> courses;
    string schedule[7];
    int static totalmembers;
    Date BD;
    string Attendance[3];

public:
    // Getters and Setters for name, id, password, email, phone, address, courses, and schedule
    void setName(const string &name);
    string getName() const;

    void setId(const long int &id);
    long int getId() const;

    void setPassword(const string &password);
    string getPassword() const;

    void setEmail(const string &email);
    string getEmail() const;

    void setPhone(const string &phone);
    string getPhone() const;

    void setAddress(const string &address);
    string getAddress() const;

    void setCourses(const vector<Courses *> &courses);
    vector<Courses *> getCourses() const;

    void setSchedule(const string schedule[7]);
    string *getSchedule();

    void setBirthDate(int day, int month, int year);
    Date &getBirthDate();

    // Constructors and Destructor
    Members();
    Members(const string &name, const string &password, const string &email, const string &phone, const string &address, const vector<Courses *> &courses, int day, int month, int year);
    virtual ~Members() = default;

    // Methods
    void login();
    void logout();
    void viewProfile();
    void editProfile();
    void changePassword();
    void viewCourses();
    void printSchedule();
    void SortSchedule();
    string *getAttendance();
};

// Students ---------------------------------------------------------------------------------------------------

class Students : public Members
{
private:
    vector<Exams *> Results;
    vector<double> ResultsValue;
    int group;
    int schoolYear;
    int section;

public:
    Students();
    Students(string name, string password, string email, string phone, string address, vector<Courses *> course, int Group, int schoolYear, int section, int day, int month, int year);
    virtual ~Students();
    static int totalstudents;
    void viewResults();
    void viewSchedule();
    void getAverage();
    int getGroup();
    void setGroup(const int newGroup);
    void setYear(const int newYear);
    int getYear();
    void setSection(const int newSection);
    int getSection();
    vector<Exams *> getResults();
    vector<double> getResultsValue();
    void setResult(int index, Exams *exam);
    void setResultvalue(int index, double value);
    void pushExam(Exams *exam);
    void pushExamResult(double value);
    void removeExam(Exams *exam);
};

// Teachers ---------------------------------------------------------------------------------------------------

class Teachers : public Members
{
public:
    static int totalteachers;
    void modifyschedule(const string schedule[7]);
    Teachers();
    Teachers(string name, string password, string email, string phone, string address, vector<Courses *> course, bool groups[12], int day, int month, int year, int type[12]);
    ~Teachers();
    void setGroups(const bool newgroups[12]);
    bool *getGroups();
    void addCourse(Courses *course);
    void removeCourse(int index);
    int *getType();
    void setType(int group, int type);

private:
    int type[12];
    bool groups[12];
};

// School ---------------------------------------------------------------------------------------------------

class School
{
private:
    vector<Courses *> courses;
    vector<Teachers *> teachers;
    vector<Students *> students;
    vector<Exams *> exams;

    vector<Students *> g1;
    vector<Students *> g2;
    vector<Students *> g3;
    vector<Students *> g4;
    vector<Students *> g5;
    vector<Students *> g6;
    vector<Students *> g7;
    vector<Students *> g8;
    vector<Students *> g9;
    vector<Students *> g10;
    vector<Students *> g11;
    vector<Students *> g12;

public:
    static int totalmembers;
    static int totalcourses;

    void addCourse(Courses *course);
    void addTeacher(Teachers *teacher);
    void addStudent(Students *student);
    void addExam(Exams *exam);

    void removeStudent(int index);
    void removeTeacher(int index);
    void removeCourse(int index);
    void removeExam(int index);

    School(const vector<Students *> &students, const vector<Teachers *> &teachers, const vector<Courses *> &courses, const vector<Exams *> &exams);
    School();
    ~School();

    void pushstudent(Students *s, int group);
    void popstudent(Students *s, int group);

    vector<Students *> getGroup(int index);
    vector<Courses *> getCourses();
    vector<Students *> getStudents();
    vector<Teachers *> getTeachers();
    vector<Exams *> getExams();
};

extern School ENSIA;

#endif
