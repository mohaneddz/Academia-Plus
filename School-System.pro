QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
DESTDIR = $$PWD/build
QMAKE_CXXFLAGS += -Wno-sign-compare

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Classes.cpp \
    Addings/add_courses.cpp \
    Addings/add_exams.cpp \
    Addings/add_students.cpp \
    Addings/add_teachers.cpp \
    Frames/courseframe.cpp \
    Frames/examframe.cpp \
    Editing/edit_courses.cpp \
    Editing/edit_exams.cpp \
    Editing/edit_students.cpp \
    Editing/edit_teachers.cpp \
    about.cpp \
    main.cpp \
    mainwindow.cpp \
    Frames/studentframe.cpp \
    Frames/teacherframe.cpp \
    Views/view_performance.cpp \
    Views/view_schedule.cpp \
    Views/view_student_results.cpp \
    Views/view_absences.cpp \
    Views/view_courses.cpp \
    Views/view_exam_results.cpp \
    Views/view_group.cpp \
    login.cpp \
    Views/view_teachers.cpp \
    Views/view_courses_frame.cpp \
    Views/performance_event.cpp \
    Views/teacher_list_frame.cpp \
    Views/view_result_single.cpp \
    Views/view_average_single.cpp \
    Views/view_exam_averages.cpp

HEADERS += \
    Classes.h \
    Addings/add_courses.h \
    Addings/add_exams.h \
    Addings/add_students.h \
    Addings/add_teachers.h \
    Frames/courseframe.h \
    Frames/examframe.h \
    Editing/edit_courses.h \
    Editing/edit_exams.h \
    Editing/edit_students.h \
    Editing/edit_teachers.h \
    about.h \
    mainwindow.h \
    Frames/studentframe.h \
    Frames/teacherframe.h \
    Views/view_performance.h \
    Views/view_schedule.h \
    Views/view_student_results.h \
    Views/view_absences.h \
    Views/view_courses.h \
    Views/view_exam_results.h \
    Views/view_group.h \
    login.h \
    Views/view_teachers.h \
    Views/view_courses_frame.h \
    Views/performance_event.h \
    Views/teacher_list_frame.h \
    Views/view_result_single.h \
    Views/view_average_single.h \
    Views/view_exam_averages.h

FORMS += \
    Addings/add_courses.ui \
    Addings/add_exams.ui \
    Addings/add_students.ui \
    Addings/add_teachers.ui \
    Frames/courseframe.ui \
    Frames/examframe.ui \
    Editing/edit_courses.ui \
    Editing/edit_exams.ui \
    Editing/edit_students.ui \
    Editing/edit_teachers.ui \
    Views/view_group.sui \
    about.ui \
    course.ui \
    mainwindow.ui \
    Frames/studentframe.ui \
    Frames/teacherframe.ui \
    Views/view_absences.ui \
    Views/view_courses.ui \
    Views/view_exam_results.ui \
    Views/view_performance.ui \
    Views/view_schedule.ui \
    Views/view_student_results.ui \
    login.ui \
    Views/view_teachers.ui \
    Views/view_courses_frame.ui \
    Views/performance_event.ui \
    Views/teacher_list_frame.ui \
    Views/view_result_single.ui \
    Views/view_average_single.ui \
    Views/view_exam_averages.ui
    
# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    style.qss

RESOURCES += \
    resources.qrc

