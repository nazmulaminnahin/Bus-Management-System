#include "bus.h"

// Actual definition of login credentials
char user[20] = "admin";
char pass[20] = "12345678";

// Function to reset password after 3 failed attempts
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

// Secure Login Function with masking and attempt limits
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
            if(c == 13) { // Enter key
                break;
            } else if(c == 8) { // Backspace
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

        // Check credentials
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

        // Trigger forgot password after 3 incorrect attempts
        if(attempts >= 3) {
            system("cls");
            printf("\n\n   ==================================================\n");
            printf("   You have entered wrong password 3 times continuously!\n");
            printf("   Do you want to reset password? (Y/N): ");
            scanf(" %c", &choice);

            if(choice == 'Y' || choice == 'y') {
                reset_password();
                attempts = 0;
            } else {
                printf("\n   Exiting application due to invalid login...\n");
                getch();
                exit(0);
            }
        }
    } while(1);
}