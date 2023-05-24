#include <stdio.h>
#include <conio.h>
#define ENTER 13
#define TAB 9
#define BCKSPC 8
#define BOLD_ON "\e[1m"
#define BOLD_OFF "\e[m"
#define FADE_ON "\e[2m"
#define FADE_OFF "\e[m"
#define ITALIC_ON "\e[3m"
#define ITALIC_OFF "\e[m"
#define LINE_ON "\e[4m"
#define LINE_OFF "\e[m"

struct StudentRecord{
    char fname[100];
    char lname[100];
    long long int contact;
    char course[10];
    char branch[10];
    long long int roll;
    int sem;
    float cpi;
}st[500];

void Add_Detail(int a) {
    printf("Enter First Name : ");
    scanf("%s", &st[a].fname);
    printf("Enter Last Name : ");
    scanf("%s", &st[a].lname);
    printf("Enter Contact no. : ");
    scanf("%lld", &st[a].contact);
    printf("Enter the Course : ");
    scanf("%s", &st[a].course);
    printf("Enter the Branch : ");
    scanf("%s", &st[a].branch);
    printf("Enter University Rollno. : ");
    scanf("%lld", &st[a].roll);
    for (int i = 0; i < a; i++) {
            if (st[i].roll == st[a].roll) {
                i = 0;
                i--;
                printf("\033[31mThe Other Student have same University Rollno.!\n\033[0m");
                printf("\033[33mEnter Official Rollno. \n\033[0m");
                printf("=> ");
                scanf("%lld", &st[a].roll);
        }
    }
    printf("Enter the Semester : ");
    scanf("%d", &st[a].sem);
    printf("Enter the CPI : ");
    scanf("%f", &st[a].cpi);
}

void Edit_Detail(int r1, int n1){
    switch(n1){
        case 1:
            printf("First Name : ");
            scanf("%s", &st[r1].fname);
            printf("Last Name : ");
            scanf("%s", &st[r1].lname);
            break;
        case 2:
            printf("Contact no. : ");
            scanf("%lld", &st[r1].contact);
            break;
        case 3:
            printf("University Rollno. : ");
            scanf("%lld", &st[r1].roll);
            break;
        case 4:
            printf("Course : ");
            scanf("%s", &st[r1].course);
            printf("Branch : ");
            scanf("%s", &st[r1].branch);
            break;
        case 5:
            printf("Semester : ");
            scanf("%d", &st[r1].sem);
            break;
        case 6:
            printf("CPI : ");
            scanf("%d", &st[r1].cpi);
            break;
    }
}

void View_Detail(int r) {
    printf("Name : %s %s\nContact no. : %lld\nCourse : %s %s\nSemester : %d\nCPI : %0.01f",st[r].fname, st[r].lname, st[r].contact, st[r].course, st[r].branch, st[r].sem, st[r].cpi);
}

void Delete_Detail(int r2, int a1) {
    for (int i = r2; i < a1 - 1; i++) {
        st[i] = st[i+1];
    }
}

int main() {

    printf(BOLD_ON"Enter the Password to Access : "BOLD_OFF);
    int cons = 0;
    char Password[] = {"OmegaBlestar"};
    char Enter[20];
    char ch;
    int i = 0;
    while (1) {
        ch = getch();
        if (ch == ENTER || ch == TAB) {
            Enter[i] = '\0';
            break;
        } else if (ch == BCKSPC) {
            if (i > 0) {
                i--;
                printf("\b \b");
            }
        } else {
            Enter[i] = ch;
            printf("* \b");
        }
        if (Enter[i] != Password[i]) {
            cons = 1;
        }
        i++;
    }
    if (cons == 0 && i == sizeof(Password) - 1) {
        printf("\n\033[36mAccess successfully!\033[0m\n");
    int Bool = 1;
    int a = 0;
    printf(LINE_ON"\nStudent Record Management System\n"LINE_OFF);
    for (int i = 1; Bool == 1; i++) {
        int n;
        printf("\n1)- Add Student Detail\n2)- Edit Student Detail\n3)- View Student Detail\n4)- Delete Student Detail\n=> ");
        scanf("%d", &n);
        printf("\n");
        switch(n) {
            case 1:
                printf("Enter Student Details - \n");
                Add_Detail(a);
                printf(FADE_ON"Student Details Added Successfully!\n\n"FADE_OFF);
                a++;
                break;
            case 2:
                printf("Enter Student University Rollno. : ");
                long long int r1, temp = 0;
                scanf("%lld", &r1);
                for (int i = 0; i < a; i++) {
                    if (st[i].roll == r1) {
                        temp = 1;
                        printf(BOLD_ON"Edit - \n"BOLD_OFF);
                        printf("1)- Name\n2)- Contact no.\n3)- University Rollno.\n4)- Course\n5)- Semester\n6)- CPI\n=> ");
                        int n1;
                        scanf("%d", &n1);
                        if (n1 < 1 || n1 > 6) {
                            printf("\033[31mGiven Value is inappropriate!\033[0m");
                            break;
                        }
                        Edit_Detail(i, n1);
                        printf(FADE_ON"UPDATED!"FADE_OFF);
                        break;
                    }
                }
                if (temp == 0) {
                    printf("\033[31mNo Student of this Rollno.!\033[0m");
                }
                printf("\n\n");
                break;
            case 3:
                printf("Enter Student University Rollno. : ");
                long long int r, temp1 = 0;
                scanf("%lld", &r);
                for (int i = 0; i < a; i++) {
                    if (st[i].roll == r) {
                        temp1 = 1;
                        printf(BOLD_ON"\nStudent Details- \n"BOLD_OFF);
                        View_Detail(i);
                        break;
                    }
                }
                if (temp1 == 0) {
                    printf("\033[31mNo Student of this Rollno.!\033[0m");
                }
                printf("\n\n");
                break;
            case 4:
                printf("Enter Student University Rollno. : ");
                int temp2 = 0;
                long long int r2;
                scanf("%lld", &r2);
                for (int i = 0; i < a; i++) {
                    if (st[i].roll == r2) {
                        temp2 = 1;
                        r2 = i;
                        break;
                    }
                }
                if (temp2 = 0) {
                    printf("\033[31mNo Student of this Rollno.!\033[0m");
                } else {
                    Delete_Detail(r2, a);
                    a--;
                    printf(FADE_ON"Deleted!"FADE_OFF);
                }
                printf("\n\n");
                break;
            default:
                printf("\033[31mGiven Value is inappropriate!\n\n\033[0m");
        }

        printf(ITALIC_ON"Enter 1 to Continue!\n=> "ITALIC_OFF);
        scanf("%d", &Bool);
    }
    } else {
        printf("\033[31m\nINCORRECT PASSWORD\nACCESS DENIED!\033[0m");
        getch();
    }

    printf("\n");
    return 0;
}