#include "../src/DataInput.h"
#include "../src/Task.h"
#include "../thirdparty/ctest.h"

CTEST(changeStringInFile, addTaskToFile)
{
    std::fstream storage;
    storage.open("storage.txt", std::ios::out);
    storage.close();

    const char *expect, *result;
    std::string strRes;
    std::string strExp = "10.06.2021 1 сдать экзамен\n11.06.2021 3 выспаться\n";

    std::vector<Task> taskVector;
    setTaskForDate(taskVector, "10.06.2021", 1, "сдать экзамен");
    setTaskForDate(taskVector, "11.06.2021", 3, "выспаться");
    changeStringInFile(taskVector, 0, operation::Add);
    changeStringInFile(taskVector, 1, operation::Add);

    storage.open("storage.txt", std::ios::in);
    if (storage.is_open()) {
        getline(storage, strRes, '\0');
        storage.close();
    }

    expect = strExp.c_str();
    result = strRes.c_str();
    ASSERT_STR(expect, result);
}

CTEST(changeStringInFile, readTaskFromFile)
{
    const char *expect, *result;
    std::string strRes;
    std::string strExp = "\n10.06.2021 1 сдать экзамен\n11.06.2021 3 выспаться";

    std::vector<Task> taskVector;
    changeStringInFile(taskVector, 0, operation::Read);

    for (int i = 0; i < 2; i++) {
        strRes = strRes + "\n" + taskVector[i].getDate() + " " + std::to_string(taskVector[i].getPriority()) + " "
                + taskVector[i].getText();
    }

    expect = strExp.c_str();
    result = strRes.c_str();
    ASSERT_STR(expect, result);
}

CTEST(changeStringInFile, editTaskInFile)
{
    const char *expect, *result;
    std::string strRes;
    std::string strExp = "10.06.2021 1 сдать экзамен\n20.06.2025 3 выспаться\n";

    std::vector<Task> taskVector;
    changeStringInFile(taskVector, 0, operation::Read);
    changeTaskDate(taskVector, "11.06.2021", 3, "выспаться", "20.06.2025");
    changeStringInFile(taskVector, 1, operation::Edit);

    std::fstream storage("storage.txt", std::ios::in);
    if (storage.is_open()) {
        getline(storage, strRes, '\0');
        storage.close();
    }

    expect = strExp.c_str();
    result = strRes.c_str();
    ASSERT_STR(expect, result);
}

CTEST(changeStringInFile, replaceTaskInFile)
{
    const char *expect, *result;
    std::string strRes;
    std::string strExp = "19.04.1984 1 починить машину времени\n20.06.2025 3 выспаться\n";

    std::vector<Task> taskVector;
    setTaskForDate(taskVector, "19.04.1984", 1, "починить машину времени");
    setTaskForDate(taskVector, "20.06.2025", 3, "выспаться");
    changeStringInFile(taskVector, 0, operation::Edit);

    std::fstream storage("storage.txt", std::ios::in);
    if (storage.is_open()) {
        getline(storage, strRes, '\0');
        storage.close();
    }

    expect = strExp.c_str();
    result = strRes.c_str();
    ASSERT_STR(expect, result);
}

CTEST(changeStringInFile, deleteTaskFromFile)
{
    const char *expect, *result;
    std::string strRes;
    std::string strExp = "20.06.2025 3 выспаться\n";

    std::vector<Task> taskVector;
    changeStringInFile(taskVector, 0, operation::Delete);

    std::fstream storage("storage.txt", std::ios::in);
    if (storage.is_open()) {
        getline(storage, strRes, '\0');
        storage.close();
    }

    expect = strExp.c_str();
    result = strRes.c_str();
    ASSERT_STR(expect, result);

    storage.open("storage.txt", std::ios::out);
    storage.close();
}
