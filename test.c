#include<stdio.h>
#include<string.h>
int counter = 0;
struct customer
{
    char customerName[100];
    int occupiedRoomN;
    int numOfDays;
};
struct customer arr[30];
void search(char cname1[100]);
int checkOut(int id, int rooms[][5], int n);
int book(int type, int view, int rooms[][5], int n, struct customer c1);
void displayCustomers();
void displayRooms(int rooms[][5]);

int main() {
    struct customer c1;
    int n = 100;
    //scanf("%d",&n);
    int rooms[100][5];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 5; j++)
            rooms[i][j] = 0;
    for (int i = 0; i < n; i++)
    {
        rooms[i][4] = (i + 1) * 1000;
        rooms[i][0] = i + 1;
    }
    for (int i = 0; i < 100; i++)
    {
        c1.customerName[i] = "";
    }
    c1.numOfDays = 0;
    c1.occupiedRoomN = 0;
    int x;
    char cname1[100];
    while (1)
    {
        printf("**********Welcome To Al Baron Hotel Sharm El Sheikh***********\n");
        printf("[1] Book a room\n[2] Check out\n[3] Search For Customer\n[4] Display Customers\n[5] Display Rooms\nYour choice: ");
        scanf("%d", &x);
        switch (x)
        {
        case 1:
            printf("Enter the room's type:\n[0] Single\n[1] Double\n[2] Suite\nYour choice: ");
            int type;
            scanf("%d", &type);
            
            printf("Enter the room's view:\n[0] Sea\n[1] Pool\nYour choice: ");
            int view;
            scanf("%d", &view);
            
            if (book(type, view, rooms, n, c1))
                printf("**********Enjoy Your Holiday***********\n");
            else
                printf("No room with your specification found :(\n");
            break;

        case 2:
            printf("Enter your id: ");
            int id;
            scanf("%d", &id);
            int ret = checkOut(id, rooms, n);
            if (ret < 0)
                printf("No customer with this id\n");
            else
                printf("Customer should pay: %d\n", ret);
            break;
        case 3:
            printf("Enter Customer Name Seprated by '_':", cname1);
            scanf("%s", &cname1);
            search(cname1);
            break;
        case 4:
            displayCustomers();
            break;
        case 5:
            displayRooms(rooms);
            break;
        default:
            return 0;
        }
    }
}
int book(int type, int view, int rooms[][5], int n, struct customer c1)
{
    int i;
    for (i = 0; i < n; i++)
        if (rooms[i][3] == 1)
            continue;
        else if (rooms[i][1] == type && rooms[i][2] == view)
            goto el;
    return 0;
el:
    printf("Enter the number of days: ");
    int days;
    scanf("%d", &days);
    
    char cname[100];
    printf("Enter Customer Name Seprated by '_':");
    scanf("%s", &cname);
    for (int k = 0; k < 100; k++)
    {
        c1.customerName[k] = cname[k];
    }

    rooms[i][3] = 1;
    for (int j = 0; j < 10; j++)
        if (c1.occupiedRoomN == 0)
        {
            c1.occupiedRoomN = rooms[i][0];
            c1.numOfDays= days;
            break;
        }
   
    arr[counter] = c1;
    counter++;
    return 1;
}

int checkOut(int id, int rooms[][5], int n)
{
    int p;
    if (id >= counter ||arr[id].occupiedRoomN == 0)
        return -1;
    for (int i = 0; i < n; i++)
        if (arr[id].occupiedRoomN == rooms[i][0])
        {
            rooms[i][3] = 0;
            p = rooms[i][4] * arr[id].numOfDays;
            break;
        }
    arr[id].occupiedRoomN = arr[id].occupiedRoomN = 0;
    for (int i = 0; i < 100; i++)
    {
        arr[id].customerName[i] = "";
    }
    if (id < 0 || id > counter)
    {
        printf("Invalid ID To Delete");
    }
    else
    {
        /* Copy next element value to current element */
        for (int i = id - 1; i < counter - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        counter--;
    }
    return p;
}
void search(char cname1[100])
{
    for (int i = 0; i < counter; i++)
    {
        if (strcmp(arr[i].customerName, cname1) == 0)
        {
            printf("The Customer Exists In The Hotel\n");
        }
        else
        {
            printf("The Customer Doesnot Exist In The Hotel\n");
        }
    }
}
void displayCustomers()
{
    for (int k = 0; k < counter; k++)
    {
        printf("Customer Number[%d]\n", k);
        printf("Customer Name: ");
        printf("%s\n", arr[k].customerName);
        printf("Days Reserved By the Customer: ");
        printf("%d\n", arr[k].numOfDays);
        printf("Customer Room Number: ");
        printf("%d\n", arr[k].occupiedRoomN);
        printf("****************************\n");
    }
}
void displayRooms(int rooms[][5])
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("%d ", rooms[i][j]);
        }
        printf("\n");
    }
}