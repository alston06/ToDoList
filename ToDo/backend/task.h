#ifndef TASK_H
#define TASK_H
#include <stdbool.h>

typedef struct Task {
    char name[50];
    char description[256];
    char deadline[10];
    int priority;
    char category[20];
    bool completed;
    struct Task* next;
} Task;

Task* addTask(Task* head, char* name, char* description, char* deadline, int priority, char* category);
void displayTasks(Task* head);
void markTaskComplete(Task* head, char* name);
Task* deleteTask(Task* head, char* name);

#endif
