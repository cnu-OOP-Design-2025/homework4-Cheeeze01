#include "student_manager.h"
#include "student.h"

/* StudentManager */
int StudentManager::last_student_id = 1000;

void StudentManager::addStudent(char const *name, float midterm, float final)
{
    int id = ++last_student_id;
    num_of_students++;
    int i = id - 1001;
    students[i] = Student(name, id, midterm, final);
}

void StudentManager::deleteStudent(int id)
{
    int idx;
    for (int i = 0; i < num_of_students; i++)
    {
        if (students[i].getID() == id)
        {
            idx = i;
            break;
        }
    }
    for (int i = idx; i < num_of_students - 1; i++)
    {
        students[i] = students[i + 1];
    }
    students[num_of_students] = Student();
    num_of_students--;
}

void StudentManager::modifyStudent(const Student &student)
{
    int idx = findStudentByID(student.getID());
    students[idx] = student;
}

int StudentManager::findStudentByID(int id) const
{
    for (int i = 0; i < num_of_students; i++)
    {
        if (students[i].getID() == id)
        {
            return i;
        }
    }
    return -1;
}

int StudentManager::findBestStudentInMidterm() const
{
    int id = 0;
    int bestMid = 0;
    for (int i = 0; i < num_of_students; i++)
    {
        int tempMid = students[i].getRecord().getMidterm();
        if (tempMid > bestMid)
        {
            bestMid = tempMid;
            id = students[i].getID();
        }
    }
    return id;
}

int StudentManager::findBestStudentInFinal() const
{
    int id = 0;
    int bestFnl = 0;
    for (int i = 0; i < num_of_students; i++)
    {
        int tempFnl = students[i].getRecord().getFinal();
        if (tempFnl > bestFnl)
        {
            bestFnl = tempFnl;
            id = students[i].getID();
        }
    }
    return id;
}

int StudentManager::findBestStudent() const
{
    int id = 0;
    int bestTot = 0;
    for (int i = 0; i < num_of_students; i++)
    {
        int tempTot = students[i].getRecord().getTotal();
        if (tempTot > bestTot)
        {
            bestTot = tempTot;
            id = students[i].getID();
        }
    }
    return id;
}

float StudentManager::getMidtermAverage() const
{
    float MidAvg = 0;
    for (int i = 0; i < num_of_students; i++)
    {
        MidAvg += students[i].getRecord().getMidterm();
    }
    MidAvg /= num_of_students;
    return MidAvg;
}

float StudentManager::getFinalAverage() const
{
    float FnlAvg = 0;
    for (int i = 0; i < num_of_students; i++)
    {
        FnlAvg += students[i].getRecord().getFinal();
    }
    FnlAvg /= num_of_students;
    return FnlAvg;
}

float StudentManager::getTotalAverage() const
{
    float TotAvg = 0;
    for (int i = 0; i < num_of_students; i++)
    {
        TotAvg += students[i].getRecord().getTotal();
    }
    TotAvg /= num_of_students;
    return TotAvg;
}
