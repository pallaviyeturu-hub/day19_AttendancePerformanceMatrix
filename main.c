#include <stdio.h>

int main() {
    char names[5][20];
    int attendance[5][5];
    int marks[5][5];
    int i, j;

    // Input Phase
    for (i = 0; i < 5; i++) {
        printf("Enter name of student %d: ", i + 1);
        scanf("%s", names[i]);

        printf("Enter attendance (5 values 0/1): ");
        for (j = 0; j < 5; j++) {
            scanf("%d", &attendance[i][j]);
        }

        printf("Enter marks for 5 subjects: ");
        for (j = 0; j < 5; j++) {
            scanf("%d", &marks[i][j]);
        }
    }

    int choice = 0;

    while (choice != 6) {
        printf("\n========== MENU ==========\n");
        printf("1. Display Attendance Matrix\n");
        printf("2. Display Marks Matrix\n");
        printf("3. Attendance Report\n");
        printf("4. Performance Report\n");
        printf("5. Grade Report\n");
        printf("6. Exit\n");
        printf("==========================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("\nAttendance Matrix:\n");
            for (i = 0; i < 5; i++) {
                printf("%s: ", names[i]);
                for (j = 0; j < 5; j++) {
                    printf("%d ", attendance[i][j]);
                }
                printf("\n");
            }
        }

        else if (choice == 2) {
            printf("\nMarks Matrix:\n");
            for (i = 0; i < 5; i++) {
                printf("%s: ", names[i]);
                for (j = 0; j < 5; j++) {
                    printf("%d ", marks[i][j]);
                }
                printf("\n");
            }
        }

        else if (choice == 3) {
            int totalAtt[5], absences[5];
            int highest = -1, lowest = 10;
            int hiIndex = 0, loIndex = 0;

            for (i = 0; i < 5; i++) {
                totalAtt[i] = 0;
                for (j = 0; j < 5; j++) {
                    totalAtt[i] += attendance[i][j];
                }
                absences[i] = 5 - totalAtt[i];

                if (totalAtt[i] > highest) {
                    highest = totalAtt[i];
                    hiIndex = i;
                }

                if (totalAtt[i] < lowest) {
                    lowest = totalAtt[i];
                    loIndex = i;
                }
            }

            printf("\nAttendance Report:\n");
            for (i = 0; i < 5; i++) {
                printf("%s - Present: %d, Absent: %d\n",
                       names[i], totalAtt[i], absences[i]);
            }

            printf("\nHighest Attendance: %s (%d)\n", names[hiIndex], highest);
            printf("Lowest Attendance: %s (%d)\n", names[loIndex], lowest);
        }

        else if (choice == 4) {
            int total[5], highest = -1, lowest = 10000;
            int hiIndex = 0, loIndex = 0;

            for (i = 0; i < 5; i++) {
                total[i] = 0;
                for (j = 0; j < 5; j++) {
                    total[i] += marks[i][j];
                }

                if (total[i] > highest) {
                    highest = total[i];
                    hiIndex = i;
                }
                if (total[i] < lowest) {
                    lowest = total[i];
                    loIndex = i;
                }
            }

            printf("\nPerformance Report:\n");
            for (i = 0; i < 5; i++) {
                printf("%s - Total Marks: %d, Average: %d\n",
                       names[i], total[i], total[i] / 5);
            }

            printf("\nClass Topper: %s (%d marks)\n", names[hiIndex], highest);
            printf("Lowest Scorer: %s (%d marks)\n", names[loIndex], lowest);
        }

        else if (choice == 5) {
            printf("\nGrade Report:\n");
            for (i = 0; i < 5; i++) {
                int sum = 0;
                for (j = 0; j < 5; j++) {
                    sum += marks[i][j];
                }
                int avg = sum / 5;
                char grade;

                if (avg >= 90) grade = 'A';
                else if (avg >= 80) grade = 'A';
                else if (avg >= 70) grade = 'B';
                else if (avg >= 60) grade = 'C';
                else if (avg >= 50) grade = 'D';
                else grade = 'F';

                printf("%s - Average: %d Grade: %c\n", names[i], avg, grade);
            }
        }
    }

    return 0;
}