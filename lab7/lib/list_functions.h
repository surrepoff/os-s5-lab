#ifndef LIST_FUNCTIONS
#define LIST_FUNCTIONS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Student {
  char name[50];
  int grades[4];
  struct Student *next;
  struct Student *prev;
} Student;

#define SERIALIZED_FILE_NAME "file.bin"

Student *new_student();
int length(Student *);
void insert(Student *, Student **);
void print(Student *);
void delete_element(int position, Student **);
void clear_list(Student **);
void serialize(Student *);
Student *clone(Student *);
void deserialize(Student **);

#endif