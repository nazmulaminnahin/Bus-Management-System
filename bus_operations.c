#include "bus.h"

// Global array definitions for buses and bookings
char ch[10][130] = {"Hanif", "Shyamoli", "Green Line", "Ena", "Asia Line"};
char name[32][100] = {'\0'};
char number[32][2] = {'\0'};
int num1[32] = {0};
int trno;

// Function to view bus list
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

// Function to book tickets
void booking()
{
    char numstr[100];
    system("cls");
    bus();
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

    FILE *f1 = NULL;
    char str1[80] = "32";
    int seat1, booking_count = 0;

    if(trno == 1) f1 = fopen("tr1.txt", "r+");
    else if(trno == 2) f1 = fopen("tr2.txt", "r+");
    else if(trno == 3) f1 = fopen("tr3.txt", "r+");
    else if(trno == 4) f1 = fopen("tr4.txt", "r+");
    else if(trno == 5) f1 = fopen("tr5.txt", "r+");

    if(f1 != NULL) {
        fgets(str1, 80, f1);
        fclose(f1);
    }

    seat1 = atoi(str1);

    if(seat1 <= 0) {
        printf("\n   Sorry, there are no available seats in this bus!");
    } else {
        printf("\n   ==================================================\n");
        printf("\n   AVAILABLE SEATS: %d\n", seat1);
        printf("\n   NUMBER OF TICKETS TO BOOK: ");
        scanf("%d", &booking_count);

        if(booking_count > seat1 || booking_count <= 0) {
            printf("\n   Invalid ticket quantity or seats not available!\n");
        } else {
            seat1 = seat1 - booking_count;
            itoa(trno, numstr, 10);
            name_number(booking_count, numstr);
            
            printf("   --------------------------------------------------\n");
            printf("   Total Booking Amount: %d BDT\n", 200 * booking_count);
            printf("   --------------------------------------------------\n");
            
            itoa(seat1, str1, 10);

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

// Save passenger name and seat number to file
void name_number(int booking_count, char numstr[100])
{
    char tempstr[100], tempstr1[15] = "status", tempstr2[15] = "number";
    int seat_num;
    FILE *a, *b;
    int i = 0;

    strcat(numstr, ".txt");
    strcat(tempstr1, numstr);
    strcat(tempstr2, numstr);

    a = fopen(tempstr1, "a");
    b = fopen(tempstr2, "a");

    for(i = 0; i < booking_count; i++) {
        printf("\n   --- Details for Ticket No: %d ---\n", i + 1);
        printf("   ENTER SEAT NUMBER (1-32): ");
        scanf("%d", &seat_num);
        printf("   ENTER PASSENGER NAME: ");
        scanf("%s", name[seat_num-1]);
        printf("   --------------------------------------------------\n");

        itoa(seat_num, tempstr, 10);
        if(a != NULL) fprintf(a, "%s ", name[seat_num-1]);
        if(b != NULL) fprintf(b, "%s ", tempstr);
    }

    if(a != NULL) fclose(a);
    if(b != NULL) fclose(b);
}

// Read seat numbers from file
int read_number(int bus_no)
{
    char tempstr2[15] = "number";
    FILE *a;
    char numstr[100];
    int i = 0, j = 0, k;

    itoa(bus_no, numstr, 10);
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
void read_name(int bus_no)
{
    char tempstr1[15] = "status";
    FILE *b;
    char numstr[100];
    int i = 0, j = 0;

    itoa(bus_no, numstr, 10);
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

// Display seat layout status board
void status()
{
    system("cls");
    printf("\n\n   ==================================================\n");
    printf("                  BUS RESERVATION SYSTEM             \n");
    printf("   ==================================================\n\n");
    
    int i, bus_no, index = 0, j;
    printf("   ENTER THE BUS NUMBER: ");
    scanf("%d", &bus_no);

    if(bus_no < 1 || bus_no > 5) {
        printf("\n   Invalid Bus Number!");
        return;
    }

    j = read_number(bus_no);
    read_name(bus_no);

    printf("\n   ==================================================\n");
    printf("                     Bus No.%d: %s\n", bus_no, ch[bus_no-1]);
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

// Helper status display
void status_1(int bus_no)
{
    int i, index = 0, j;
    j = read_number(bus_no);
    read_name(bus_no);

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

// Cancel ticket booking
void cancle()
{
    int seat_no, i, j, bus_no;
    char numstr[100], tempstr2[15] = "number", tempstr1[15] = "status";
    
    printf("\n   ENTER THE BUS NUMBER: ");
    scanf("%d", &bus_no);

    if(bus_no < 1 || bus_no > 5) {
        printf("\n   Invalid Bus Number!");
        return;
    }

    itoa(bus_no, numstr, 10);
    strcat(numstr, ".txt");
    strcat(tempstr1, numstr);
    strcat(tempstr2, numstr);

    read_number(bus_no);
    read_name(bus_no);
    status_1(bus_no);

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