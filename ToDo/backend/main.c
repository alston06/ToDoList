#include "task.h"
#include <stdio.h>
#include <stdbool.h>

#define _countof(arr) (sizeof(arr) / sizeof((arr)[0]))


int main() {
    Task* taskList = NULL;
    int choice, priority;
    char name[50], description[255], deadline[11], category[20];

    while (1) {
        printf("1. Add Task\n2. View Tasks\n3. Mark Task Complete\n4. Delete Task\n5. Exit\nEnter your choice: ");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter task name: ");
            scanf_s(" %[^\n]%*c", name, (unsigned)_countof(name));
            printf("Enter description: ");
            scanf_s(" %[^\n]%*c", description, (unsigned)_countof(description));
            printf("Enter deadline (YYYY-MM-DD): ");
            scanf_s("%10s", deadline, (unsigned)_countof(deadline));
            printf("Enter priority (integer): ");
            scanf_s("%d", &priority);
            printf("Enter category: ");
            scanf_s("%19s", category, (unsigned)_countof(category));
            taskList = addTask(taskList, name, description, deadline, priority, category);
            break;
        case 2:
            displayTasks(taskList);
            break;
        case 3:
            printf("Enter task name to mark as complete: ");
            scanf_s(" %[^\n]%*c", name, (unsigned)_countof(name));
            markTaskComplete(taskList, name);
            break;
        case 4:
            printf("Enter task name to delete: ");
            scanf_s(" %[^\n]%*c", name, (unsigned)_countof(name));
            taskList = deleteTask(taskList, name);
            break;
        case 5:
            return 0;
        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}
