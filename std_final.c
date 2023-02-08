#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct std
{
    int rollno;
    char name[50];
    char phone[20];
    float per;
    struct std *next;
};

struct std *head = NULL, *p1, *p2, *temp;
int r;
// function to avoid repeatation of roll number.
int roll()
{

    temp = head;
    printf("\n Enter Roll Number: ");
    scanf("%d", &r);
    while (temp != NULL)
    {
        if (r == temp->rollno)
        {
            printf("\n Student Record with Roll number %d already exists, Please use distinct Roll Number for distinct Student!!!\n", r);
            roll();
        }
        else
            temp = temp->next;
    }
    return r;
}

// funtion to insert student record.
void insert()
{
    int a;
    float d;
    char b[50], c[20];
    char another;
    do
    {
        struct std *student;
        student = (struct std *)malloc(sizeof(struct std));
        printf("\n_____________________________________");
        printf("\n-------ADD STUDENT INFORMATION-------");
        printf("\n_____________________________________");
        roll();
        student->rollno = r;
        printf("\n Enter the Name: ");
        scanf("%s", student->name);

        printf("\n Enter Phone Number: ");
        scanf("%s", student->phone);
        printf("\n Enter Percentage: ");
        scanf("%f", &student->per);
        if (head == NULL)
        {
            student->next = NULL;
            head = student;
        }
        else
        {
            student->next = head;
            head = student;
        }

        for (p1 = head; p1 != NULL; p1 = p1->next)
        {
            for (p2 = p1->next; p2 != NULL; p2 = p2->next)
            {
                if (p2->rollno < p1->rollno)
                {
                    a = p1->rollno;
                    p1->rollno = p2->rollno;
                    p2->rollno = a;

                    strcpy(b, p1->name);
                    strcpy(p1->name, p2->name);
                    strcpy(p2->name, b);

                    strcpy(c, p1->phone);
                    strcpy(p1->phone, p2->phone);
                    strcpy(p2->phone, c);

                    d = p1->per;
                    p1->per = p2->per;
                    p2->per = d;
                }
            }
        }
        printf("\n Record added successfully!");
         printf("\n____________________________________\n");
        printf("\n Do you want to add another record?(y/n): ");
        scanf("%s", &another);
    } while (another == 'y' || another == 'Y');
}

// function to search student data.
void search()
{
    int rollnum;
    printf("\n Enter the roll number of the student to be searched: ");
    scanf("%d", &rollnum);
    printf("\n\n ----------STUDENT DETAILS---------\n\n");
    p1 = head;
    while (p1 != NULL)
    {
        if (p1->rollno == rollnum)
        {
            printf("\n Roll Number: %d", p1->rollno);
            printf("\n Name: %s", p1->name);
            printf("\n Phone number: %s", p1->phone);
            printf("\n Percentage: %0.2f\n\n", p1->per);
            return;
        }
        p1 = p1->next;
    }
    printf("\n student with roll number %d not found!\n\n", rollnum);
}

// funtion to update the record.
void update()
{
    int rollnum;
    printf("\n Enter the roll number of student whose data is to be updated: ");
    scanf("%d", &rollnum);
    p1 = head;
    while (p1 != NULL)
    {
        if (p1->rollno == rollnum)
        {
            printf("\n Record found!");
            printf("\n Enter the new name: ");
            scanf("%s", p1->name);
            printf("\n Enter new phone number:");
            scanf("%s", p1->phone);
            printf("\n Enter new percentage:");
            scanf("%f", &p1->per);
            printf("\n data updated successfully!\n\n");
            return;
        }
        else
            p1 = p1->next;
    }
    printf("\n student with Roll number %d not found!\n\n", rollnum);
}

// funtion to display the record.
void display()
{
    int i;
    char a;
    p1 = head;
    printf("________________________________________________________________");
    printf("\n ----STUDENT DATABASE----\n");
    printf("________________________________________________________________");
    while (p1 != NULL)
    {
        printf("\n Roll Number: %d", p1->rollno);
        printf("\n Name: %s", p1->name);
        printf("\n Phone number: %s", p1->phone);
        printf("\n Percentage: %0.2f\n\n", p1->per);
        p1 = p1->next;
    }
    printf("\n Press any key to Exit:");
            scanf("%s",&a);
}

// function to delete the record.
void delete()
{
    p1 = head;
    p2 = head;
    int rollnum;
    printf("\n enter the roll number of the student whose record is to be deleted: ");
    scanf("%d", &rollnum);
    while (p2 != NULL)
    {
        if (p2->rollno == rollnum)
        {
            printf("\n Record found!");
            if (p2 == p1)
            {
                head = head->next;
                free(p2);
            }
            else
            {
                p1->next = p2->next;
                free(p2);
            }
            printf("\n Record deleted!\n\n");
            return;
        }
        p1 = p2;
        p2 = p2->next;
    }
    printf("\n Student with roll number %d not found!!\n\n", rollnum);
}

// main function
int main()
{
    int ch;
    char a;
    printf("\n-----------------------------------------------------\n");
    printf("          STUDENT DATA MANAGEMENT      ");
    printf("\n-----------------------------------------------------\n");
    printf("\n 1.Insert Student\n 2.Search for Student Details\n 3.Update Student Details\n");
    printf(" 4.Delete Student Details\n 5.Display Student Data\n 6.EXIT\n");
    while (1)
    {
        printf("___________________________***__________________________________");
        printf("\n Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insert();
            printf("\n Press any key to Exit:");
            scanf("%s",&a);
            break;
        case 2:
            search();
            printf("\n Press any key to Exit:");
            scanf("%s",&a);
            break;
        case 3:
            update();
            printf("\n Press any key to Exit:");
            scanf("%s",&a);
            break;
        case 4:
            delete ();
            printf("\n Press any key to Exit:");
            scanf("%s",&a);
            break;
        case 5:
            display();
            break;
        case 6:
            printf("\n WELCOME AGAIN \n");
            exit(0);
        default:
            printf("\n Invalid choice!\n\n");
        }
    }
}