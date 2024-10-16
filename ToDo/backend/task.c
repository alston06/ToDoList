#include "task.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Task* addTask(Task* head, char* name, char* description, char* deadline, int priority, char* category) {
    Task* newTask = (Task*)malloc(sizeof(Task));
    if (newTask == NULL) {
        printf("Memory allocation failed!\n");
        return head;
    }

    strcpy_s(newTask->name, sizeof(newTask->name), name);
    strcpy_s(newTask->description, sizeof(newTask->description), description);
    strcpy_s(newTask->deadline, sizeof(newTask->deadline), deadline);
    newTask->priority = priority;
    strcpy_s(newTask->category, sizeof(newTask->category), category);
    newTask->completed = false;
    newTask->next = head;

    return newTask;
}


void displayTasks(Task* head) {
    Task* current = head;

    while (current != NULL) {
        printf("Task: %s\n", current->name);
        printf("Description: %s\n", current->description);
        printf("Deadline: %s\n", current->deadline);
        printf("Priority: %d\n", current->priority);
        printf("Category: %s\n", current->category);
        printf("Completed: %s\n", current->completed ? "Yes" : "No");
        printf("\n");
        current = current->next;
    }
}

void markTaskComplete(Task* head, char* name) {
    Task* current = head;

    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            current->completed = true;
            printf("Task %s is marked as completed\n", current->name);
            return;
        }
        current = current->next;
    }
    printf("Task %s not found\n", name);
}

Task* deleteTask(Task* head, char* name) {
    Task* current = head;
    Task* previous = NULL;

    if (head == NULL) {
        printf("Task list is empty.\n");
        return NULL;
    }

    if (strcmp(head->name, name) == 0) {
        Task* temp = head;
        head = head->next;
        free(temp);
        printf("Task '%s' has been deleted.\n", name);
        return head;
    }

    while (current != NULL && strcmp(current->name, name) != 0) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Task '%s' not found.\n", name);
        return head;
    }

    previous->next = current->next;
    free(current);
    printf("Task '%s' has been deleted.\n", name);

    return head;
}

void saveTasksToFile(Task* head, const char* filename) {
    FILE* file = fopen(filename, "w+");
    if (file == NULL) {
        printf("Error storing Tasks\n");
        return;
    }

    Task* current = head;

    while (current != NULL) {
        fprintf(file, "%s\n%s\n%s\n%d\n%s\n%d\n",
            current->name,
            current->description,
            current->deadline,
            current->priority,
            current->category,
            current->completed ? 1: 0);
        current = current->next;
    }

    fclose(file);
    printf("Tasks saved\n");
}

Task* loadTasksFromFile(const char* filename) {
    FILE* file = fopen(filename, "r");

    if (file == NULL) {
        printf("No Tasks found\n");
        return NULL;
    }

    Task* head = NULL;
    while (!feof(file)) {
        Task* newTask = (Task*)malloc(sizeof(Task));
        if (fscanf_s(file, "%[^\n]\n%[^\n]\n%[^\n]\n%d\n%[^\n]\n%d\n",
            newTask->name, (unsigned)_countof(newTask->name),
            newTask->description, (unsigned)_countof(newTask->description),
            newTask->deadline, (unsigned)_countof(newTask->deadline),
            &newTask->priority,
            newTask->category, (unsigned)_countof(newTask->category),
            (int*)&newTask->completed) != 6) {
            free(newTask);
            break;
        }
        newTask->completed = (newTask->completed != 0);
        newTask->next = head;
        head = newTask;
    }

    fclose(file);
    printf("Tasks Loaded\n");
    return head;
}

void freeTasks(Task* head) {
    Task* current = head;
    while (current != NULL) {
        Task* next = current->next;
        free(current);
        current = next;
    }
}