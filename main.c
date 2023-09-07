#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 5
#define MAX_SIZE 150

//defining passenger details
struct Passenger {
    char name[50];
    char gender;
    char travel_class[50];
    int age;
    char mobile_number[15];
};

//contains all passenger details in an array
struct Queue {
    struct Passenger* passenger_array[MAX_SIZE];
    int front;
    int rear;
};

//creates a queue
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*) malloc(sizeof(struct Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

//store all the passenger details in pointer p
void initialize(char name[50],char gender,char travel[50], int age, char mobile_number[15], struct Passenger *p){
    int name_len = strlen(name);
    int travel_len = strlen(travel);
    int mob_size = strlen(mobile_number);
    for(int i=0;i<name_len;i++){
        p->name[i] = name[i];
    }
    for(int i=0;i<travel_len;i++){
        p->travel_class[i] = travel[i];
    }
    for(int i=0;i<mob_size;i++){
        p->mobile_number[i] = mobile_number[i];
    }
    p->age = age;
    p->gender = gender;


}

//adds details in queue
void enqueue(struct Queue* q, struct Passenger* p1) {
    if (q->rear == MAX_SIZE - 1) {
        printf("Queue is full\n");
    } else {
        if (q->front == -1) {
            q->front = 0;
        }
        q->rear++;
        q->passenger_array[q->rear] = p1;
    }
}

//returns passenger pointer containing details
struct Passenger* dequeue(struct Queue* q) {
    if (q->front == -1 || q->front > q->rear) {
        printf("Queue is empty\n");
        return NULL;
    } else {
        struct Passenger* p1 = q->passenger_array[q->front];
        q->front++;
        return p1;
    }
}

//linked list
struct node1 {
    struct Passenger *passenger;

    struct node1 *next;
};

struct node1 *newnode1;


struct node1 *temp1;
struct node1 *head1 = NULL;

//stores all details in passenger pointer p1 and returns p1
struct Passenger* book1() {
    struct Passenger* p1;
    int age;
    char name[50];
    char phone_number[50];
    char travelling_class[50];
    char gender;

    printf("Enter name of passenger:\n");
    scanf(" %s", name);
    printf("Enter gender:\n");
    scanf(" %c",&gender);
    printf("Enter traveling class:\n");
    scanf(" %s", travelling_class);
    printf("Enter passenger age:\n");
    scanf(" %d", &age);
    printf("Enter mobile number:\n");
    scanf(" %s",phone_number);
    p1 = (struct Passenger* )malloc(sizeof(struct Passenger));
    initialize(name,gender,travelling_class,age,phone_number,p1);
    return p1;
}


void display(int pos) {
    struct node1 *curr = head1;
    int i = 0;
    while (curr != NULL && i < pos) {
        curr = curr->next;
        i++;
    }
    if (curr == NULL) {
        printf("Position not found in linked list.\n");
    } else {
        struct Passenger *p = curr->passenger;
        printf("Name: %s\n", p->name);
        printf("Gender: %c\n", p->gender);
        printf("Traveling class: %s\n", p->travel_class);
        printf("Age: %d\n", p->age);
        printf("Mobile number: %s\n", p->mobile_number);
    }
}

//
void cancel1(struct Queue* q) {
    struct node1 *prevnode1;
    struct node1 *temp1;
    int pos, len = 0;
    temp1 = head1;

    if (temp1 == NULL) {
        printf("No bookings to cancel\n");
        return;
    }

    while (temp1 != NULL) {
        len++;
        temp1 = temp1->next;
    }

    printf("Enter the position of the booking to cancel (1 to %d): ", len);
    scanf("%d", &pos);

    if (pos == 1) {
    if (q->front <= q->rear) {
        struct Passenger* p1 = dequeue(q);   //dequeued details
        temp1 = head1;
       struct node1 * head_temp = (struct node1*)malloc(sizeof(struct node1));  //new node to store details of queue
        head_temp->passenger = p1;
        head_temp->next = temp1->next;   //first position of ll
        head1 = head_temp;
        free(temp1);
    } else {
        temp1 = head1;
        head1 = head1->next;
        free(temp1);
    }
}
     else {    //for all other positions in ll
        temp1 = head1;
        for (int i = 1; i < pos; i++) {
            prevnode1 = temp1;
            temp1 = temp1->next;
        }
        if(q->front<=q->rear){
        struct Passenger* p1 = dequeue(q);
        struct node1* n1 = (struct node1*) malloc(sizeof(struct node1));    //new node with queue details
        n1->passenger = p1;
        prevnode1->next = n1;
        n1->next = temp1->next;   //puts n1 between prev and temp and frees temp
        free(temp1);
        }
        else{
            prevnode1->next = temp1->next;
            free(temp1);
        }
    }
}

int length1(struct node1 *head1) {
    int length = 0;
    while (head1 != NULL) {
        head1 = head1->next;
        length++;
    }
     return length;
}

int main()
{
    int choice, tno,x;
    struct Queue* q = createQueue();
    do
    {
        printf("-----------------------------MAIN MENU-----------------------------\n");
        printf("1.View Trains\n2.View number of available seats\n3.Book Ticket\n4.Display passenger details\n5.Cancel Booking\n6.Exit\n");
        printf("Enter your choice:\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            printf("TRAIN NO.    TRAIN NAME.       FROM          TO           1AC(Rs)  2AC(Rs) DEPARTURE TIME     ARRIVAL TIME\n");
            printf("----------------------------------------------------------------------------------------------------------\n");
            printf("12129       AZAD HIND EXP    PUNE JNC       KOLKATA        2690     720        18:35              03:55   \n");
            printf("22150      PUNE ERS SF EXP   PUNE JNC    MUMBAI CENTRAL    695      165        18:35              03:55   \n");
            printf("17614       NED PNVL EXP     PUNE JNC    MUMBAI CENTRAL    1065     645        11:10              14:20   \n");
            printf("12124       DECCAN QUEEN     PUNE JNC    MUMBAI CENTRAL    355      100        07:15              10:25   \n");
            printf("11019      KONARK EXPRESS    PUNE JNC    VISAKHAPATNAM     1970     1365       10:25              15:40   \n");
            printf("16210       AJMER EXPRESS    PUNE JNC        SURAT         1460     875        11:10              16:50   \n");
            printf("\n");
            break;
        }

        case 2:
        {
            printf("Which trains seat capacity do you want to check?\nEnter the tno:\n");
            scanf("%d",&tno);
            if(tno==12129 || tno==22150 || tno==17614 ||tno==12124 || tno==11019 || tno==16210){

                x=2-length1(head1);
                if(x>=0) printf("%d seats are available\n",x);
                else printf("no seats are left\n");
            }

            break;
        }

        case 3:
        {
            printf("Enter train number:\n");
            scanf("%d", &tno);
            if(tno==12129 || tno==22150 || tno==17614 ||tno==12124 || tno==11019 || tno==16210)
            {
            if(length1(head1)<2){
               struct  Passenger * p1 = book1();
                newnode1 = (struct node1*) malloc(sizeof(struct node1));
                newnode1->passenger = p1;
                newnode1->next = NULL;

                if (head1 == NULL) {
            head1 = newnode1;
            temp1 = newnode1;
            } else {

                temp1->next = newnode1;
                temp1 = newnode1;
            }
            }
            else{
                printf("No seats available in the train. Enter details in waiting list\n");
               struct  Passenger * p1 = book1();
                enqueue(q,p1);
            }
            }
            break;
        }

        case 4:
        {   int pos;
            printf("Which tno passenger details do you want?\nEnter the tno:\n");
            scanf("%d",&tno);
            printf("enter the position of passenger with 0 based indexing \n");
            scanf("%d",&pos);

            if(tno==12129 || tno==22150 || tno==17614 ||tno==12124 || tno==11019 || tno==16210)
            {
            display(pos);
            }

            break;
        }

        case 5:
        {
        printf("Which train number do you want to cancel seat in?\nEnter the tno:\n");
        scanf("%d",&tno);
        if(tno==12129 || tno==22150 || tno==17614 ||tno==12124 || tno==11019 || tno==16210){
            cancel1(q);
        }
            break;
        }

        case 6:
            exit(0);
            break;
        }

    } while (choice != 0);
    return 0;
}
