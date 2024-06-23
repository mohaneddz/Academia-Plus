#ifndef CLASSES_H
#define CLASSES_H

// #include <nlohmann/json.hpp>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>

// for the QDate class
#include <QDateTime>
#include <QTime>
#include <map>

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

    void setDate(int day, int month, int year);
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

    void setTime(int hour, int minute, int day, int month, int year);
};

// Courses ---------------------------------------------------------------------------------------------------

class Courses
{
private:
    string name;
    string schedule[7][2];
    bool groups[12];
    int id;

public:
    static int totalcourses;

    // Getters and Setters :{name, schedule, groups} --------------------------------------------
    void setName(const string &name);
    string getName() const;

    void setSchedule(const string schedule[7][2]);
    string (*getSchedule())[2];

    int getId();
    void setId(const int newId);

    // Constructors and Destructor
    Courses();
    Courses(const string &newName, string newSchedule[7][2], const bool newgroups[12]);
    ~Courses();

    // Other methods
    void setGroups(const bool newgroups[12]);
    bool *getGroups();

    // DATA :
    // Save function to serialize Courses objects to a file
    static void save(const vector<Courses *> &coursesList);
    // Load function to deserialize Courses objects from a file
    static vector<Courses *> load();
};

// Exams ---------------------------------------------------------------------------------------------------

class Exams
{
private:
    Courses *Module;
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

    void setGroups(const bool groups[12]);
    bool *getGroups();

    Time &getTimeStart();
    Time &getTimeEnd();
    void setDate(const Time &start, const Time &end);

    void setId(int id);
    int getid();

    Time getStartDate();
    Time getEndDate();

    string getResponsible();
    void setResponsible(const string &newResponsible);
    bool fixschedule();

    // DATA Section :
    static void save(const vector<Exams *> &examsList);
    static vector<Exams *> load();
};

// Members ---------------------------------------------------------------------------------------------------
// forward declarations
class Students;
class Teachers;

class Members
{
protected:
    long int id;
    string name;
    string password;
    string email;
    string phone;
    string address;
    string Attendance[3];
    string schedule[7][2];
    Date BD;
    vector<Courses *> courses;
    int static totalmembers;
    vector<string> performance;
    vector<QDateTime> dates;

public:
    // Getters and Setters for  name, id, password, email, phone, address, courses, and schedule
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
    void setBirthDate(int day, int month, int year);
    Date &getBirthDate();
    void setevent(const string &event, QDateTime &time, int index);
    string getevent(int index);
    QDateTime &geteventtime(int index);

    vector<string> *getevents();
    vector<QDateTime> *geteventstime();

    string (*getSchedule())[2];
    virtual bool fixschedule();
    void setSchedule(int a, int b, string newSchedule);
    string *getAttendance();

    // Constructors and Destructor
    Members();
    Members(const string &name, const string &password, const string &email, const string &phone, const string &address, const vector<Courses *> &courses, int day, int month, int year);
    virtual ~Members() = default;

    // DATA :
    // we will make freind functions to save and load data from files for both Students and Teachers
    friend class Students;
    friend class Teachers;
    // friend void Teachers::save(const vector<Teachers *> &teachersList);
    // friend vector<Teachers *> Teachers::load();
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
    void setResultvalue(Exams *exam, double value = 10);
    void pushExam(Exams *exam);
    void pushExamResult(double value);
    void removeExam(Exams *exam);
    void addCourse(Courses *course);
    void removeCourse(Courses *course);
    virtual bool fixschedule();
    static void save(const vector<Students *> &studentsList);
    static vector<Students *> load();
};

// Teachers ---------------------------------------------------------------------------------------------------

class Teachers : public Members
{
private:
    int type[12];
    bool groups[12];

public:
    static int totalteachers;
    Teachers();
    Teachers(string name, string password, string email, string phone, string address, vector<Courses *> course, bool groups[12], int day, int month, int year, int type[12]);
    ~Teachers();
    void setGroups(const bool newgroups[12]);
    bool *getGroups();
    void addCourse(Courses *course);
    void removeCourse(int index);
    int *getType();
    void setType(int group, int type);
    bool fixschedule();
    static void save(const vector<Teachers *> &teachersList);
    static vector<Teachers *> load();
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

    void pushexam(Exams *e, int group);

    vector<Students *> getGroup(int index);
    vector<Courses *> getCourses();
    vector<Students *> getStudents();
    vector<Teachers *> getTeachers();
    vector<Exams *> getExams();

    void setCourses(const vector<Courses *> &courses);
    void setTeachers(const vector<Teachers *> &teachers);
    void setStudents(const vector<Students *> &students);
    void setExams(const vector<Exams *> &exams);

    Students *getStudents(string name);
};

extern School ENSIA;

#endif
