#include "Classes.h"    

void testingcourses(Courses *module1, Courses *module2);
void testingteachers(Teachers *teacher1, Teachers *teacher2);
void testingstudents(Students *student1, Students *student2);

// creating courses : oop, linux, analysis, linear_algebra, english, statistics
int main()
{
    School ENSIA;

    bool OOPGroups[13] = {1, 1, 1};
    string OOPschedule[7] = {
        "08:00-10:00",
        "08:00-10:00",
        "14:00-16:00",
        "14:00-16:00",
        "08:00-10:00",
        "", // Friday is a free day
        ""  // Saturday is a free day
    };

    bool LinuxGroups[13] = {1, 0, 1, 0, 1};
    string Linuxschedule[7] = {
        "10:00-12:00",
        "10:00-12:00",
        "08:00-10:00",
        "08:00-10:00",
        "14:00-16:00",
        "", // Friday is a free day
        ""  // Saturday is a free day
    };

    bool AnalysisGroups[13] = {1, 1};
    string Analysisschedule[7] = {
        "14:00-16:00",
        "14:00-16:00",
        "10:00-12:00",
        "10:00-12:00",
        "08:00-10:00",
        "", // Friday is a free day
        ""  // Saturday is a free day
    };

    bool LinearAlgebraGroups[13] = {1, 1, 1, 1};
    string LinearAlgebraschedule[7] = {
        "08:00-10:00",
        "08:00-10:00",
        "14:00-16:00",
        "14:00-16:00",
        "10:00-12:00",
        "", // Friday is a free day
        ""  // Saturday is a free day
    };

    bool EnglishGroups[13] = {1, 1, 1};
    string Englishschedule[7] = {
        "14:00-16:00",
        "14:00-16:00",
        "08:00-10:00",
        "08:00-10:00",
        "10:00-12:00",
        "", // Friday is a free day
        ""  // Saturday is a free day
    };

    bool StatisticsGroups[13] = {1, 1};
    string Statisticsschedule[7] = {
        "10:00-12:00",
        "10:00-12:00",
        "14:00-16:00",
        "14:00-16:00",
        "08:00-10:00",
        "", // Friday is a free day
        ""  // Saturday is a free day
    };

    Courses OOP("OOP", OOPschedule, OOPGroups);
    Courses Linux("Linux", Linuxschedule, LinuxGroups);
    Courses Analysis("Analysis", Analysisschedule, AnalysisGroups);
    Courses LinearAlgebra("Linear Algebra", LinearAlgebraschedule, LinearAlgebraGroups);
    Courses English("English", Englishschedule, EnglishGroups);
    Courses Statistics("Statistics", Statisticsschedule, StatisticsGroups);

    Courses *MohanedCourses[MAX_Courses] = {&Linux, &OOP};
    Courses *AhmedCourses[MAX_Courses] = {&Analysis, &LinearAlgebra, &Statistics};

    Students Mohaned("Mohaned", 00001, "moh", "mohaned@ensia.edu.dz", "0666666666", "Constantine ", MohanedCourses, 3);
    Students Ahmed("Ahmed", 00002, "ahm", "ahmed@ensia.edu.dz", "0555555555", "Constantine ", AhmedCourses, 3);


    Courses *KacimiCourses[MAX_Courses] = {&Analysis, &LinearAlgebra, &Statistics};
    Courses *SamiCourses[MAX_Courses] = {&Linux, &OOP};

    bool KacimiGroups[13] = {1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0};
    bool SamiGroups[13] = {0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0};

    Teachers Kacimi("Kacimi", 0001, "kac", "Kacimi@ensia.edu.dz", "0999999999", "Constantine ", KacimiCourses, KacimiGroups);
    Teachers Sami("Sami", 0002, "che", "Sami@ensia.edu.dz", "0888888888", "Constantine ", SamiCourses, SamiGroups);

    testingcourses(&OOP, &Linux);
    testingteachers(&Kacimi, &Sami);
    testingstudents(&Mohaned, &Ahmed);

}

void testingcourses(Courses *module1, Courses *module2)
{
    // testing saveData and loadData functions

    module1->saveData();
    module2->readData();

    // // show Linux data

    cout << "Linux data :" << endl;
    cout << "Name : " << module2->getName() << endl;
    cout << "ID : " << module2->getId() << endl;
    cout << "Schedule : " << endl;
    for (int i = 0; i < 7; i++)
    {
        if (module2->getSchedule()[i] == "")
        {
            cout << "empty" << endl;
        }
        else
            cout << module2->getSchedule()[i] << endl;
    }

    cout << "Groups : " << endl;
    for (int i = 0; i < 13; i++)
    {
        if (module2->getGroups()[i] == 1)
        {
            cout << "Group " << i + 1 << endl;
        }
    }
    cout << "---------------------------------" << endl;
};
void testingteachers(Teachers *teacher1, Teachers *teacher2)
{

    // testing the teacher saveData and readData functions

    cout << "teacher2->data :" << endl;
    cout << "Name : " << teacher2->getName() << endl;
    cout << "ID : " << teacher2->getId() << endl;
    teacher2->SortSchedul();
    cout << "Schedule : " << endl;
    teacher2->printSchedule();
    cout << "Groups : " << endl;
    for (int i = 0; i < 13; i++)
    {
        if (teacher2->getGroups()[i] == 1)
        {
            cout << "Group " << i + 1 << endl;
        }
    }
    cout << "---------------------------------" << endl;
};
void testingstudents(Students *student1, Students *student2)
{
    // testing the student saveData and readData functions

    cout << "student2->data :" << endl;
    cout << "Name : " << student2->getName() << endl;
    cout << "ID : " << student2->getId() << endl;
    student2->SortSchedul();
    cout << "Schedule : " << endl;
    student2->printSchedule();
    
    cout << "Group " << student2->getGroup() << endl;

    cout << "---------------------------------" << endl;
};