#include "bus.h"

int main()
{
    // Set terminal theme color (Green text on Black background)
    system("color 0A");

    // Call login screen first
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