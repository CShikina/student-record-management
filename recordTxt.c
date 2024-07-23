#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

struct record {
    int sno;
    char name[50];
    float grade;
}*student;

typedef struct record record;

void createFile(){
    FILE *fp = fopen("record.txt", "w");
    system("cls");

    int n;
    printf("How many: ");
    scanf("%d", &n);
    student = malloc(n*sizeof(record));

    fprintf(fp, "Sno.    Name                Grade\n");
    for (int i=0; i<n; i++){
        printf("\nStudent number: ");
        scanf("%d", &student[i].sno);
        while (getchar() != '\n');

        printf("Name: ");
        fgets(student[i].name, sizeof(student[i].name), stdin);
        student[i].name[strcspn(student[i].name, "\n")] = '\0';

        printf("Grade: ");
        scanf("%f", &student[i].grade);
        while (getchar() != '\n');
        fprintf(fp, "%-8d%-20s%.2f\n", student[i].sno, student[i].name, student[i].grade);
    }
    fclose(fp);
    free(student);
    getch();

}

void addRecord(){
    FILE *fp = fopen("record.txt", "a");
    system("cls");

    int n;
    printf("How many: ");
    scanf("%d", &n);
    student = malloc(n*sizeof(record));

    for (int i=0; i<n; i++){
        printf("\nStudent number: ");
        scanf("%d", &student[i].sno);
        while (getchar() != '\n');

        printf("Name: ");
        fgets(student[i].name, sizeof(student[i].name), stdin);
        student[i].name[strcspn(student[i].name, "\n")] = '\0';

        printf("Grade: ");
        scanf("%f", &student[i].grade);
        while (getchar() != '\n');
        fprintf(fp, "%-8d%-20s%.2f\n", student[i].sno, student[i].name, student[i].grade);
    }

    fclose(fp);
    free(student);
    getch();
}

void viewRecord(){
    FILE *fp = fopen("record.txt", "r");

    char line[200];
    while (fgets(line, sizeof(line), fp)){
        printf("%s", line);
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