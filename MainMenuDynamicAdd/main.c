#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#define numberOfLines 5


struct employee // Done
{
    int ID;
    char name[30];
    int Age;
};

void gotoxy(int column , int line); //Done

void textattr(int i ); //Done

void startSys(int *ptr); //Done

void employeeListInitialization(struct employee *employeePtr , int size); //Done

void displayList(struct employee *employeePtr , int size); //Done

void newEmployee(struct employee *employeePtr , int _size);//Done

void displayByName(struct employee *employeePtr, int size); //Done

void displayByID(struct employee *employeePtr , int size); //Done

void displayAll(struct employee *employeePtr , int size);

void Exit(char ch);

int isNumeric(char str[]); // Done

void capitalizeFirstLetter(char name[]); // Done

int main()
{
    int size;
    int *ptr_size = &size;

    startSys(&ptr_size);

    struct employee *employeePtr = (struct employee*)malloc(size * sizeof(struct employee));
    if (employeePtr == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    employeeListInitialization(&employeePtr , size);

    _getch();
    char ch;
    char menu[numberOfLines][20] = { "New" ,  "Display by name ", "Display by ID " , "Display All " , "Exit" };

    int diserdLine=0;

    do{
        system("cls");


    //============================Draw The Menu ======================================//
        for(int stageLine =0 ; stageLine < numberOfLines; stageLine++)
        {
            gotoxy( 20 , 10+stageLine );
            if ( stageLine == diserdLine )
                textattr(0x74);
            _cprintf("%s", menu[stageLine]);
            textattr(0x07);
        }

        ch = _getch(); // wait

    //==================== check if extended or normal key =============================//

        switch(ch)
        {
            case -32:
                ch = _getch();
                switch (ch)
                {
                    case 72: //up
                        diserdLine --;
                        if (diserdLine<0)
                            diserdLine=numberOfLines-1 ;
                        break;

                    case 80: //down
                        diserdLine ++;
                        if (diserdLine>(numberOfLines-1))
                            diserdLine=0 ;
                        break;

                }

                break;

            case 13: //Enter

                system("cls");
                if(diserdLine == 0) newEmployee(&employeePtr , size);
                else if(diserdLine == 1) displayByName(&employeePtr , size);
                else if(diserdLine == 2) displayByID(&employeePtr ,size);
                else if(diserdLine == 3) displayAll(&employeePtr ,size);
                else if(diserdLine == 4) ch = 'e'; //printf("Exit Selected --");
                _getch();
                break;

            case 'n':
                system("cls");
                printf("New Selected ....\n");
                _getch();
                break;

            case 'd':
                system("cls");
                printf("Display Selected ....\n");
                _getch();
                break;

            case 'e':
                system("cls");
                printf("Exit Selected ....\n");
                _getch();
                break;

            default:
                system("cls");
                printf("invalid char");
                _getch();
                break;

        }



    }while(ch != 'e' && ch != 27);



    return 0;
}

void Exit(char ch)
{
     printf("Exit Selected --");
     ch = 'e';
}

void displayAll(struct employee *employeePtr , int size)
{
    int displayed = 0;
    for (int i = 0; i < size; i++) {
        if (employeePtr[i].ID != -1 && strcmp(employeePtr[i].name, "0") != 0 && employeePtr[i].Age != -1) {
            printf("Employee's ID is %d ,", employeePtr[i].ID);
            printf("The name is %s ,", employeePtr[i].name);
            printf("The Age is %d\n", employeePtr[i].Age);
            displayed++;
        }
    }
    if (displayed == 0) {
        printf("No valid employees to display.\n");
    }
    _getch();

}

void displayByID(struct employee *employeePtr , int size)
{
    printf("Display by ID Selected --\n");
    printf("What is the ID you want to search about ?");

    int found = 0;
    int IdToSearch;
    scanf("%d",&IdToSearch);

    for (int i =0 ; i< size ; i++)
    {
        if(IdToSearch==employeePtr[i].ID)
        {
            printf("Employee's ID is %d\n",employeePtr[i].ID);
            printf("The name is %s\n",employeePtr[i].name);
            printf("The Age is %d\n",employeePtr[i].Age);
            found = 1;
            break;
        }
    }
    if (!found)
        printf("The ID you are searching for is not found >_<");
}


void displayByName(struct employee *employeePtr , int size)
{
    char nameToSearch[30];
    int found = 0;

    printf("Display by name Selected --\n");
    printf("What is the name you want to search about ?");
    scanf("%s",nameToSearch);

    for (int i =0 ; i< size ; i++)
    {
        if(strcmpi(nameToSearch , employeePtr[i].name) == 0)
        {
            printf("Employee's ID is %d\n",employeePtr[i].ID);
            printf("The name is %s\n",employeePtr[i].name);
            printf("The Age is %d\n",employeePtr[i].Age);
            found = 1;
            break;
        }
    }
    if (!found)
    {
        printf("Sorry the name you are searching for is not found\n");
    }

}

void newEmployee(struct employee *employeePtr , int _size)
{
    printf("New Selected --\n");
    int dieserdIndex ;

    // Validate index input
    while (1) {
        printf("What is the index you want for this employee? ");
        scanf("%d", &dieserdIndex);
        if (dieserdIndex >= 0 && dieserdIndex < _size)
        {

            break;
        }
        else
        {
            printf("Invalid index. Please enter a valid index between 0 and %d.\n", _size - 1);
        }
    }

    // Validate ID input
    while (1)
    {
        printf("Please Enter the ID: ");
        if (scanf("%d", &employeePtr[dieserdIndex].ID) != 1)
        {
            printf("Invalid ID. Please enter a numeric value.\n");
            while (getchar() != '\n'); // Clear the buffer
        }
        else
        {
            break;
        }
    }

    // Validate Name input (alphabetical characters only)
    while (1) {
        printf("Please Enter the name: ");
        scanf("%s", employeePtr[dieserdIndex].name);
        if (isalpha(employeePtr[dieserdIndex].name[0])) {
            capitalizeFirstLetter(employeePtr[dieserdIndex].name);
            break;
        } else {
            printf("Name should only contain alphabetic characters. Please try again.\n");
        }
    }
    // Validate Age input
    while (1) {
        printf("Please Enter the Age: ");
        if (scanf("%d", &employeePtr[dieserdIndex].Age) != 1) {
            printf("Invalid Age. Please enter a numeric value.\n");
            while (getchar() != '\n'); // Clear the buffer
        } else {
            break;
        }
    }
}


void employeeListInitialization(struct employee *employeePtr , int size)
{
    if (employeePtr != NULL)
    {
        for (int i = 0 ; i< size ; i++)
        {
            employeePtr[i].Age= -1;
            strcpy(employeePtr[i].name, "0");
            employeePtr[i].ID= -1;
        }

    }
    else
        printf("no enough space\n");

}

void displayList(struct employee *employeePtr , int size)
{
    for (int i = 0 ; i< size ; i++)
        {
            printf("The ID is %d ",employeePtr[i].ID);
            printf("The name is %s ",employeePtr[i].name);
            printf("The Age is %d\n",employeePtr[i].Age);
        }
    _getch();

}

void startSys(int *sizeptr)
{
    printf("Wlcome to our Employee Mangement System :\n");
    printf("PLease enter How many Employees do you want in your system ? ");
    scanf ("%d", *sizeptr );
}


void gotoxy(int column , int line)
{
    COORD coord;
    coord.X = column;
    coord.Y = line;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);

}


void textattr(int i )
{
    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE) , i );
}

int isNumeric(char str[]) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}

void capitalizeFirstLetter(char name[]) {
    if (name[0] >= 'a' && name[0] <= 'z') {
        name[0] = name[0] - 32;
    }
}


