#include <cstdio>
#include <iostream>
using namespace std;

int main ()
{
    /* [subjects] [students] */
    int grades[4][5] = {
        {75, 80, 82, 84, 91},
        {82, 99, 90, 78, 90},
        {82, 93, 76, 83, 96},
        {90, 89, 82, 84, 97}
    };

    const int student = 5, subject = 4;
    int sum_stu = 0, sum_sub = 0;
    float average_stu, average_sub;

    // Header for grades
    printf("+-------------------------------+\n");
    printf("| Grades per student            |\n");
    // Grade per student and draw table hehe
    for (int st = 0; st < student; st++) 
    {
        printf("+-------------------------------+\n");
        printf("| Student %d |", st);

        for (int sub = 0; sub < subject; sub++) 
        {
            printf(" %d |", grades[sub][st]);
        }

        printf("\n");
    }
    printf("+-------------------------------+\n");

    // Average grade per subject
    printf("\n< -- Subject average -- >\n");
    for (int sub = 0; sub < subject; sub++)
    {
        sum_sub = 0;
        for (int st = 0; st < student; st++){
            sum_sub += grades[sub][st];
        }

        //printf("\ntotaltest: %d \n", sum_sub);
        average_sub = (float)sum_sub / (float)student;
        printf("Subject %d: [ %.2f ]\n", sub, average_sub);
    }

    // Average grade per student
    printf("\n< -- Student average -- >\n");
    for (int st = 0; st < student; st++)
    {
        sum_stu = 0;
        for (int sub = 0; sub < subject; sub++){
            sum_stu += grades[sub][st];
        }

        //printf("\ntotaltest: %d \n", sum_sub);
        average_stu = (float)sum_stu / (float)subject;
        printf("Student %d: [ %.2f ]\n", st, average_stu);
    }

    cout << "\n";
    return 0;
}
