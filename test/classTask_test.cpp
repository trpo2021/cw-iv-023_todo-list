#include "../src/Task.h"
#include "../thirdparty/ctest.h"

CTEST(findIndex, correctFind)
{
    std::vector<Task> taskVector;
    setTaskForDate(taskVector, "21.21.2021", 4, "Поспать");
    setTaskForDate(taskVector, "07.07.2007", 3, "Вернуть мой 2007");

    int expect = 0;
    int result = findIndex(taskVector, "21.21.2021", 4, "Поспать");

    ASSERT_EQUAL(expect, result);
}

CTEST(findIndex, uncorrectFind)
{
    std::vector<Task> taskVector;
    setTaskForDate(taskVector, "21.21.2021", 4, "Поспать");
    setTaskForDate(taskVector, "07.07.2007", 3, "Вернуть мой 2007");

    int expect = 2147483647;
    int result = findIndex(taskVector, "21.21.2022", 4, "Поспать");

    ASSERT_EQUAL(expect, result);
}

CTEST(changeTaskDate, correctChange)
{
    std::vector<Task> taskVector;
    setTaskForDate(taskVector, "21.21.2021", 4, "Поспать");
    setTaskForDate(taskVector, "07.07.2007", 3, "Вернуть мой 2007");

    int expect = 0;
    int result = changeTaskDate(taskVector, "07.07.2007", 3, "Вернуть мой 2007", "08.07.2005");

    ASSERT_EQUAL(expect, result);
}

CTEST(changeTaskDate, uncorrectChange)
{
    std::vector<Task> taskVector;
    setTaskForDate(taskVector, "21.21.2021", 4, "Поспать");
    setTaskForDate(taskVector, "07.07.2007", 3, "Вернуть мой 2007");

    int expect = 1;
    int result = changeTaskDate(taskVector, "07.07.2007", 4, "Вернуть мой 2007", "08.07.2007");

    ASSERT_EQUAL(expect, result);
}

CTEST(changeTaskText, correctChange)
{
    std::vector<Task> taskVector;
    setTaskForDate(taskVector, "21.21.2021", 5, "Поспать");
    setTaskForDate(taskVector, "07.07.2007", 3, "Вернуть мой 2007");

    int expect = 0;
    int result = changeTaskText(taskVector, "21.21.2021", 5, "Поспать", "Поесть");

    ASSERT_EQUAL(expect, result);
}

CTEST(changeTaskText, uncorrectChange)
{
    std::vector<Task> taskVector;
    setTaskForDate(taskVector, "21.21.2021", 5, "Поспать");
    setTaskForDate(taskVector, "07.07.2007", 3, "Вернуть мой 2007");

    int expect = 1;
    int result = changeTaskText(taskVector, "21.21.2021", 1, "Поспать", "Поесть");

    ASSERT_EQUAL(expect, result);
}

CTEST(changeTaskPriority, correctChange)
{
    std::vector<Task> taskVector;
    setTaskForDate(taskVector, "21.21.2021", 5, "Поспать");
    setTaskForDate(taskVector, "07.07.2007", 3, "Вернуть мой 2007");

    int expect = 0;
    int result = changeTaskPriority(taskVector, "21.21.2021", 5, "Поспать", 4);

    ASSERT_EQUAL(expect, result);
}

CTEST(changeTaskPriority, uncorrectChange)
{
    std::vector<Task> taskVector;
    setTaskForDate(taskVector, "21.21.2021", 5, "Поспать");
    setTaskForDate(taskVector, "07.07.2007", 3, "Вернуть мой 2007");

    int expect = 1;
    int result = changeTaskPriority(taskVector, "21.21.2021", 1, "Поспать", 5);

    ASSERT_EQUAL(expect, result);
}

CTEST(deleteTaskFromVector, correctDelete)
{
    std::vector<Task> taskVector;
    setTaskForDate(taskVector, "21.21.2021", 5, "Поспать");
    setTaskForDate(taskVector, "07.07.2007", 3, "Вернуть мой 2007");

    int expect = 0;
    int result = deleteTaskFromVector(taskVector, "21.21.2021", 5, "Поспать");

    ASSERT_EQUAL(expect, result);
}

CTEST(deleteTaskFromVector, uncorrectDelete)
{
    std::vector<Task> taskVector;
    setTaskForDate(taskVector, "21.21.2021", 5, "Поспать");
    setTaskForDate(taskVector, "07.07.2007", 3, "Вернуть мой 2007");

    int expect = 1;
    int result = deleteTaskFromVector(taskVector, "21.21.2021", 1, "Поспать");

    ASSERT_EQUAL(expect, result);
}
