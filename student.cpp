#include "student.h"

#include <iostream>

/* StudentRecord */

StudentRecord::StudentRecord(float midterm, float final) : midterm(midterm), final(final)
/* TODO: Initializer list 사용해 초기화 해보기 */
{
}

float StudentRecord::getTotal() const
{
    /* TODO */
    float result = midterm + final;
    return result;
}

void StudentRecord::updateScores(float midterm, float final)
{
    /* TODO: this keyword 사용해 보기 */
    this->midterm = midterm;
    this->final = final;
}

/* Student */

Student::Student() : name(""), id(0)
/* TODO: Initializer list 사용해 초기화 해보기 */
{
}

Student::Student(const char *name, int id, float midterm, float final) : name(name), id(id), record(midterm, final)
/* TODO: Initializer list 사용해 초기화 해보기 */
{
}

void Student::updateRecord(const char *name, float midterm, float final)
{
    /* TODO */
    this->name = name;
    this->id = id;
    this->record.updateScores(midterm, final);
}
