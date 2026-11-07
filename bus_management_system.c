/* 
 * Project Name: Bus Management System
 * Language: C Language
 * Updated Version: Cleaned, Modernized, and Bug-Fixed
 */

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#include <conio.h>
#include <stdlib.h>

// Global variables for login credentials
char user[20] = "admin";
char pass[20] = "12345678";

// Global arrays for bus system
char ch[10][130] = {"Hanif", "Shyamoli", "Green Line", "Ena", "Asia Line"};
char name[32][100] = {'\0'};
char number[32][2] = {'\0'};
int num1[32] = {0};
int trno;

// Function declarations
void login();
void bus();
void name_number(int booking, char numstr[100]);
void booking();
int read_number(int trno);
void read_name(int trno);
void status();
void status_1(int trno);
void cancle();
void reset_password();

int main()
{
    // Terminal appearance: Green text on Black background
    system("color 0A");

    // Call login screen before opening main application
    login();

    int num;
    do {
        system("cls");
        printf("\n\n   ==================================================\n");
        printf("                  BUS RESERVATION SYSTEM             \n");
        printf("   ==================================================\n\n");
        printf("   ------------------ MAIN MENU ---------------------\n\n");
        printf("   [1] View Bus List\n\n");
        printf("   [2] Book Tickets\n\n");
        printf("   [3] Cancel Booking\n\n");
        printf("   [4] Bus Status Board\n\n");
        printf("   [5] Exit\n\n");
        printf("   ==================================================\n");
        printf("   ENTER YOUR CHOICE: ");
        scanf("%d", &num);

        switch(num)
        {
            case 1:
                bus();
                break;
            case 2:
                booking();
                break;
            case 3:
                cancle();
                break;
            case 4:
                status();
                break;
            case 5:
                break;
            default:
                printf("\n   Invalid choice! Please try again.");
        }
        if(num != 5) {
            getch();
        }
    } while(num != 5);

    system("cls");
    printf("\n\n   ==================================================\n");
    printf("     THANK YOU FOR USING THIS BUS RESERVATION SYSTEM  \n");
    printf("   ==================================================\n");
    getch();
    return 0;
}

// Function to display the list of available buses
void bus()
{
    system("cls");
    printf("\n\n   ==================================================\n");
    printf("                  BUS RESERVATION SYSTEM             \n");
    printf("   ==================================================\n\n");
    printf("   -------------------- BUS LIST --------------------\n\n");
    printf("   [1]  =>  %s\n\n", ch[0]);
    printf("   [2]  =>  %s\n\n", ch[1]);
    printf("   [3]  =>  %s\n\n", ch[2]);
    printf("   [4]  =>  %s\n\n", ch[3]);
    printf("   [5]  =>  %s\n\n", ch[4]);
}

// Function to handle booking process
void booking()
{
    char numstr[100];
    system("cls");
    bus(); // Display bus list to choose from
    printf("   ENTER THE BUS NUMBER: ");
    scanf("%d", &trno);

    if(trno < 1 || trno > 5) {
        printf("\n   Invalid Bus Number!");
        return;
    }

    system("cls");
    printf("\n\n   ==================================================\n");
    printf("                  BUS RESERVATION SYSTEM             \n");
    printf("   ==================================================\n\n");
    printf("   Selected Bus: %d ********** %s\n\n", trno, ch[trno-1]);
    
    status_1(trno);

    FILE *f1;
    char str1[80] = "32";
    int seat1, booking = 0;

    // Read remaining seats from bus text file
    if(trno == 1) f1 = fopen("tr1.txt", "r+");
    else if(trno == 2) f1 = fopen("tr2.txt", "r+");
    else if(trno == 3) f1 = fopen("tr3.txt", "r+");
    else if(trno == 4) f1 = fopen("tr4.txt", "r+");
    else if(trno == 5) f1 = fopen("tr5.txt", "r+");

    if(f1 != NULL) {
        fgets(str1, 80, f1);
        fclose(f1);
    }

    seat1 = atoi(str1); // Convert string count to integer

    if(seat1 <= 0) {
        printf("\n   Sorry, there are no available seats in this bus!");
    } else {
        printf("\n   ==================================================\n");
        printf("\n   AVAILABLE SEATS: %d\n", seat1);
        printf("\n   NUMBER OF TICKETS TO BOOK: ");
        scanf("%d", &booking);

        if(booking > seat1 || booking <= 0) {
            printf("\n   Invalid ticket quantity or seats not available!\n");
        } else {
            seat1 = seat1 - booking;
            itoa(trno, numstr, 10);
            name_number(booking, numstr);
            
            printf("   --------------------------------------------------\n");
            printf("   Total Booking Amount: %d BDT\n", 200 * booking);
            printf("   --------------------------------------------------\n");
            
            itoa(seat1, str1, 10);

            // Update remaining seats in the file
            if(trno == 1) f1 = fopen("tr1.txt", "w");
            else if(trno == 2) f1 = fopen("tr2.txt", "w");
            else if(trno == 3) f1 = fopen("tr3.txt", "w");
            else if(trno == 4) f1 = fopen("tr4.txt", "w");
            else if(trno == 5) f1 = fopen("tr5.txt", "w");

            if(f1 != NULL) {
                fputs(str1, f1);
                fclose(f1);
            }
        }
    }
}

// Save passenger names and seat numbers
void name_number(int booking, char numstr[100])
{
    char tempstr[100], tempstr1[15] = "status", tempstr2[15] = "number";
    int number;
    FILE *a, *b;
    int i = 0;

    strcat(numstr, ".txt");
    strcat(tempstr1, numstr);
    strcat(tempstr2, numstr);

    a = fopen(tempstr1, "a");
    b = fopen(tempstr2, "a");

    for(i = 0; i < booking; i++) {
        printf("\n   --- Details for Ticket No: %d ---\n", i + 1);
        printf("   ENTER SEAT NUMBER (1-32): ");
        scanf("%d", &number);
        printf("   ENTER PASSENGER NAME: ");
        scanf("%s", name[number-1]);
        printf("   --------------------------------------------------\n");

        itoa(number, tempstr, 10);
        if(a != NULL) fprintf(a, "%s ", name[number-1]);
        if(b != NULL) fprintf(b, "%s ", tempstr);
    }

    if(a != NULL) fclose(a);
    if(b != NULL) fclose(b);
}

// Read booked seat numbers from file
int read_number(int trno)
{
    char tempstr2[15] = "number";
    FILE *a;
    char numstr[100];
    int i = 0, j = 0, k;

    itoa(trno, numstr, 10);
    strcat(numstr, ".txt");
    strcat(tempstr2, numstr);

    a = fopen(tempstr2, "r+");
    if(a == NULL) return 0;

    while(!feof(a)) {
        number[i][j] = fgetc(a);
        if(number[i][j] == ' ') {
            j = 0;
            i++;
        } else {
            j++;
        }
    }
    k = i;
    for(i = 0; i < k; i++) {
        num1[i] = atoi(number[i]);
    }
    fclose(a);
    return k;
}

// Read passenger names from file
void read_name(int trno)
{
    char tempstr1[15] = "status";
    FILE *b;
    char numstr[100];
    int i = 0, j = 0;

    itoa(trno, numstr, 10);
    strcat(numstr, ".txt");
    strcat(tempstr1, numstr);

    b = fopen(tempstr1, "r+");
    if(b == NULL) return;

    while(!feof(b)) {
        name[i][j] = fgetc(b);
        if(name[i][j] == ' ') {
            j = 0;
            i++;
        } else {
            j++;
        }
    }
    name[i][j] = '\0';
    fclose(b);
}

// Display seat layout status
void status()
{
    system("cls");
    printf("\n\n   ==================================================\n");
    printf("                  BUS RESERVATION SYSTEM             \n");
    printf("   ==================================================\n\n");
    
    int i, trno, index = 0, j;
    printf("   ENTER THE BUS NUMBER: ");
    scanf("%d", &trno);

    if(trno < 1 || trno > 5) {
        printf("\n   Invalid Bus Number!");
        return;
    }

    j = read_number(trno);
    read_name(trno);

    printf("\n   ==================================================\n");
    printf("                     Bus No.%d: %s\n", trno, ch[trno-1]);
    printf("   ==================================================\n\n");

    char tempname[33][10] = {"Empty", "Empty", "Empty", "Empty", "Empty", "Empty", "Empty", "Empty", "Empty", "Empty", "Empty", "Empty", "Empty", "Empty", "Empty", "Empty", "Empty", "Empty", "Empty", "Empty", "Empty", "Empty", "Empty", "Empty", "Empty", "Empty", "Empty", "Empty", "Empty", "Empty", "Empty", "Empty", "Empty"};

    for(i = 0; i < j; i++) {
        if(num1[i] > 0 && num1[i] <= 32) {
            strcpy(tempname[num1[i]], name[i]);
        }
    }

    for(i = 0; i < 8; i++) {
        printf("   ");
        for(j = 0; j < 4; j++) {
            printf("%2d. %-10s\t", index + 1, tempname[index + 1]);
            index++;
        }
        printf("\n");
    }
}

// Helper status display function
void status_1(int trno)
{
    int i, index = 0, j;
    j = read_number(trno);
    read_name(trno);

    char tempname[33][10] = {"Empty", "Empty", "Empty", "Empty", "Empty", "Empty", "Empty", "Empty", "Empty", "Empty", "Empty", "Empty", "Empty", "Empty", "Empty", "Empty", "Empty", "Empty", "Empty", "Empty", "Empty", "Empty", "Empty", "Empty", "Empty", "Empty", "Empty", "Empty", "Empty", "Empty", "Empty", "Empty", "Empty"};

    for(i = 0; i < j; i++) {
        if(num1[i] > 0 && num1[i] <= 32) {
            strcpy(tempname[num1[i]], name[i]);
        }
    }

    for(i = 0; i < 8; i++) {
        printf("   ");
        for(j = 0; j < 4; j++) {
            printf("%2d. %-10s\t", index + 1, tempname[index + 1]);
            index++;
        }
        printf("\n");
    }
}

// Ticket cancellation function
void cancle()
{
    int seat_no, i, j;
    char numstr[100], tempstr2[15] = "number", tempstr1[15] = "status";
    
    printf("\n   ENTER THE BUS NUMBER: ");
    scanf("%d", &trno);

    if(trno < 1 || trno > 5) {
        printf("\n   Invalid Bus Number!");
        return;
    }

    itoa(trno, numstr, 10);
    strcat(numstr, ".txt");
    strcat(tempstr1, numstr);
    strcat(tempstr2, numstr);

    read_number(trno);
    read_name(trno);
    status_1(trno);

    printf("\n\n   ==================================================\n");
    printf("   ENTER SEAT NUMBER TO CANCEL: ");
    scanf("%d", &seat_no);

    FILE *a, *b;
    a = fopen(tempstr1, "w+");
    b = fopen(tempstr2, "w+");

    for(i = 0; i < 32; i++) {
        if(num1[i] == seat_no) {
            for(j = 0; j < 32; j++) {
                if(num1[j] != seat_no && num1[j] != 0) {
                    if(b != NULL) fprintf(b, "%d ", num1[j]);
                    if(a != NULL) fprintf(a, "%s ", name[j]);
                }
            }
        }
    }

    if(a != NULL) fclose(a);
    if(b != NULL) fclose(b);

    printf("\n   ==================================================\n");
    printf("   Booking Cancelled Successfully! 200 BDT Refunded.\n");
    printf("   ==================================================\n");
}

// Forget Password Reset Option
void reset_password()
{
    char input_user[20];
    char new_pass[20];

    system("cls");
    printf("\n\n   ==================================================\n");
    printf("                FORGOT / RESET PASSWORD              \n");
    printf("   ==================================================\n\n");
    printf("   ENTER YOUR USERNAME TO VERIFY: ");
    scanf("%s", input_user);

    if(strcmp(input_user, user) == 0) {
        printf("\n   Username verified successfully!\n");
        printf("   ENTER NEW PASSWORD: ");
        scanf("%s", new_pass);
        strcpy(pass, new_pass);
        printf("\n   --------------------------------------------------\n");
        printf("   Password reset successfully! Please login again.\n");
        printf("   --------------------------------------------------\n");
    } else {
        printf("\n   Username not found! Cannot reset password.\n");
    }
    getch();
}

// Secure Login Function
void login()
{
    int attempts = 0, i = 0;
    char uname[20], pword[20];
    char c;
    char choice;

    do {
        system("cls");
        printf("\n\n   ==================================================\n");
        printf("                  BUS RESERVATION SYSTEM             \n");
        printf("   ==================================================\n\n");
        printf("   ------------------- LOGIN FORM -------------------\n\n");
        printf("   ENTER USERNAME: ");
        scanf("%s", uname);
        printf("   ENTER PASSWORD: ");

        i = 0;
        while(i < 19) {
            c = getch();
            if(c == 13) { // Enter key pressed
                break;
            } else if(c == 8) { // Backspace handling
                if(i > 0) {
                    i--;
                    printf("\b \b");
                }
            } else {
                pword[i] = c;
                printf("*");
                i++;
            }
        }
        pword[i] = '\0';

        // Checking login credentials
        if(strcmp(uname, user) == 0 && strcmp(pword, pass) == 0) {
            printf("\n\n   ==================================================\n");
            printf("   LOGIN SUCCESSFUL! WELCOME USER.\n");
            printf("   Press any key to continue to Main Menu...");
            getch();
            return;
        } else {
            attempts++;
            printf("\n\n   LOGIN UNSUCCESSFUL! Wrong Username or Password.\n");
            printf("   Remaining Attempts: %d\n", 3 - attempts);
            getch();
        }

        // Forgot password flow after 3 failed attempts
        if(attempts >= 3) {
            system("cls");
            printf("\n\n   ==================================================\n");
            printf("   You have entered wrong password 3 times continuously!\n");
            printf("   Do you want to reset password? (Y/N): ");
            scanf(" %c", &choice);

            if(choice == 'Y' || choice == 'y') {
                reset_password();
                attempts = 0; // Reset counter after attempt
            } else {
                printf("\n   Exiting application due to invalid login...\n");
                getch();
                exit(0);
            }
        }
    } while(1);
}