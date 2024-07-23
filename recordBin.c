#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

struct record {
    int sno;
    char name[50];
    float grade;
    int mark;
}*student;

typedef struct record record;

void createFile(){
    FILE *fp = fopen("record.bin", "w");
    system("cls");

    printf("How many: ");
    int n;
    scanf("%d", &n);
    while(getchar()!= '\n');

    student = malloc(n*sizeof(record));
    for(int i=0; i<n; i++){
        printf("\nStudent number: ");
        scanf("%d", &student[i].sno);
        while (getchar() != '\n');

        printf("Name: ");
        fgets(student[i].name, sizeof(student[i].name), stdin);
        student[i].name[strcspn(student[i].name, "\n")] = '\0';

        printf("Grade: ");
        scanf("%f", &student[i].grade);
        while (getchar() != '\n');

        student[i].mark = (student[i].grade <= 3.00)? 1:0;
        fwrite(&student[i], sizeof(record), 1, fp);
    }

    fclose(fp);
    free(student);
    printf("\n\nComplete.");
    getch();
}

void addRecord(){
    FILE *fp = fopen("record.bin", "ab");
    system("cls");

    printf("How many: ");
    int n;
    scanf("%d", &n);
    while(getchar()!= '\n');


    student = malloc(n*sizeof(record));
    for(int i=0; i<n; i++){
        printf("\nStudent number: ");
        scanf("%d", &student[i].sno);
        while (getchar() != '\n');

        printf("Name: ");
        fgets(student[i].name, sizeof(student[i].name), stdin);
        student[i].name[strcspn(student[i].name, "\n")] = '\0';

        printf("Grade: ");
        scanf("%f", &student[i].grade);
        while (getchar() != '\n');

        student[i].mark = (student[i].grade <= 3.00)? 1:0;
        fwrite(&student[i], sizeof(record), 1, fp);
    }

    fclose(fp);
    free(student);
    printf("\n\nComplete.");
    getch();
}

void viewRecord(){
    FILE *fp = fopen("record.bin", "rb");
    system("cls");

    record s;
    printf("Sno.    Name                Grade       Remark\n");
    while (fread(&s, sizeof(s), 1, fp)){
        printf("%-8d%-20s%-12.2f%s\n", s.sno, s.name, s.grade, (s.mark == 1)? "Passed":"Failed");
    }

    fclose(fp);
    getch();
}

int main(){
    int choice;
    do{
        system("cls");
        printf("1. Create a file\n");
        printf("2. Add a record\n");
        printf("3. View record\n");
        printf("4. Quit program\n");
        printf(">> ");
        scanf("%d", &choice);
    
        switch (choice){
            case 1:
                createFile();
                break;
            case 2:
                addRecord();
                break;
            case 3:
                viewRecord();
                break;
            case 4:
                break;
            default:
                printf("\nInvalid");
                getch();
        }
    }while(choice !=4);
    printf("\nExited");
}