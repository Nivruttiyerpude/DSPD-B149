#include <stdio.h>
#include <string.h>

// struct
struct Student {
    int roll;
    char name[50];
    int age;
    float avgMarks;
};

int main() {
    int n, i, j;
    struct Student temp;

    printf("Enter number of students: ");
    scanf("%d", &n);

    struct Student s[n];

    // input student detaisl
    for (i = 0; i < n; i++) {
        printf("\nEnter details of student %d:\n", i + 1);
        printf("Roll No: ");
        scanf("%d", &s[i].roll);
        printf("Name: ");
        scanf("%s", s[i].name);
        printf("Age: ");
        scanf("%d", &s[i].age);
        printf("Average Marks: ");
        scanf("%f", &s[i].avgMarks);
    }

    // bubble ort
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (s[j].avgMarks < s[j + 1].avgMarks) {
                temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }

    printf("\nStudents sorted in descending order by average marks:\n");
    printf("Roll\tName\tAge\tAverage Marks\n");
 
    for (i = 0; i < n; i++) {
        printf("%d\t%s\t%d\t%.2f\n", s[i].roll, s[i].name, s[i].age, s[i].avgMarks);
    }

    return 0;
}
