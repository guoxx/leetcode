#pragma once

enum class Sex
{
    UNKNOW,
    FEMALE,
    MALE,
};


class Identifier
{
public:
    Sex _sex : 2;
    int32_t _id : 30;

    Identifier(Sex s, int32_t i)
    : _sex(s)
    , _id (i)
    { };

    Identifier() = default;

    operator int32_t();
    operator int32_t() const;
    bool operator == (const Identifier& ident)
    bool operator != (const Identifier& ident)
};

class Student
{
public:
    std::shared_ptr<std::string> _name;
    Identifier _ident;
    int32_t _age;
};


class Teacher
{
public:
    std::shared_ptr<std::string> _name;
    std::shared_ptr<std::string> _speciality;
    Identifier _ident;
};


class Course
{
public:
    std::shared_ptr<Teacher> _teacher;
    std::map<Identifier, std::shared_ptr<Student>> _students;
};

class University
{
public:
    static University& sharedInstance();

    int32_t getTeachersCount();

    int32_t getStudentsCount();

    int32_t getStudentsCountBySex(Sex sex);

    int32_t getStudentsCountForTeacher(const Teacher& teacher);

    bool canAddToCourse(const Course& course, const Student& student);

private:
    University();
    ~University();
    University(const University&) = delete;
    University& operator=(const University&) = delete;
    University(const University&&) = delete;
    University& operator=(const University&&) = delete;

private:
    static Identifier _incrementId;
    static University* _instance;
    static std::mutex _lock;

private:
    std::array<std::shared_ptr<Course>, 10> _courses;
    std::map<Identifier, std::shared_ptr<Teacher>> _teachers;
    std::map<Identifier, std::shared_ptr<Student>> _students;
    std::vector<std::shared_ptr<std::string>> _symbols;
};
