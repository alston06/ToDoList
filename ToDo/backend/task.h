#ifndef TASK_H
#define TASK_H

#include <stdbool.h>

typedef struct Task {
    char name[50];
    char description[255];
    char deadline[11];
    int priority;
    char category[20];
    bool completed;
    struct Task* next;
} Task;

Task* addTask(Task* head, char* name, char* description, char* deadline, int priority, char* category);
void displayTasks(Task* head);
void markTaskComplete(Task* head, char* name);
Task* deleteTask(Task* head, char* name);
void saveTasksToFile(Task* head, const char* filename);
Task* loadTasksFromFile(const char* filename);

#endif
