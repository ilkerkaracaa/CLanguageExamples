#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#define numberOfRooms 100

typedef struct {
   char *customerName;
   char *customerSurname;
}customerInformation;

typedef struct {
    int day;
    int mounth;
    int year;
}dateInformation;

typedef struct {
    int numberOfPeople;
    int roomCondition;
    int roomNumber;
    double priceInformation;
    customerInformation customer;
    dateInformation dateOfEntry;
    dateInformation releaseDate;
}roomInformation;

typedef enum {
    customer=0,employee=1
}authorizationLevels;

int calculateDayDifference(dateInformation dateOfEntry, dateInformation releaseDate){
    if(dateOfEntry.day>releaseDate.day){
        releaseDate.mounth-=1;
        releaseDate.day+=30;
    }
    if(dateOfEntry.mounth>releaseDate.mounth){
        releaseDate.year-=1;
        releaseDate.mounth+=12;
    }
    dateInformation dateDifference;
    dateDifference.day=releaseDate.day-dateOfEntry.day;
    dateDifference.mounth=releaseDate.mounth-dateOfEntry.mounth;
    dateDifference.year=releaseDate.year-dateOfEntry.year;

    int daydifference=dateDifference.year*365+dateDifference.mounth*30+dateDifference.day;
    return daydifference;

}


double priceCalculation(roomInformation *rooms,int roomNumber){
    int daydifference=calculateDayDifference(rooms[roomNumber-1].dateOfEntry,rooms[roomNumber-1].releaseDate);
    printf("Number of days you will stay:%d\n",daydifference);
    return daydifference*150*rooms[roomNumber-1].numberOfPeople;
}


void reservationClear(roomInformation *rooms,int roomNumber){
    rooms[roomNumber-1].roomCondition=0;// we emptied the room
    free(rooms[roomNumber-1].customer.customerName);//The fields reserved for customer name and surname are empty.
    free(rooms[roomNumber-1].customer.customerSurname);
    printf("%d The exit/cancellation process of room numbered is completed.\n",roomNumber);
}

void occupiedRoomInformationPrint(roomInformation *rooms){
    int i;
    for(i=0;i<numberOfRooms;i++){
        if(rooms[i].roomCondition!=0){// if the room is full, if 0 is empty.
            printf("-------------------------------------------------------------------------\n");
            printf("Room number:%d\n",rooms[i].roomNumber);
            printf("Customer Name-Surname:%s %s\n",rooms[i].customer.customerName,rooms[i].customer.customerSurname);
            printf("Number of People:%d\n",rooms[i].numberOfPeople);
            printf("Price information:%.2lf\n",rooms[i].priceInformation);
            printf("Date of entry:%d:%d:%d\n",rooms[i].dateOfEntry.day,rooms[i].dateOfEntry.mounth,rooms[i].dateOfEntry.year);
            printf("Release date:%d:%d:%d\n",rooms[i].releaseDate.day,rooms[i].releaseDate.mounth,rooms[i].releaseDate.year);
        }
    }
}

void addNewCustomer(roomInformation *rooms){

    int roomToBeQuestioned;
    char customerName[20],customerSurname[20],character;

    printf("Please enter the room you want to register:");
    scanf("%d",&roomToBeQuestioned);

    if(rooms[roomToBeQuestioned-1].roomCondition!=0){
        printf("Sorry. The room you want to register is occupied until %d:%d:%d.",rooms[roomToBeQuestioned-1].releaseDate.day,rooms[roomToBeQuestioned-1].releaseDate.mounth,rooms[roomToBeQuestioned-1].releaseDate.year);
        return;
    }

    rooms[roomToBeQuestioned-1].roomNumber=roomToBeQuestioned;//Room number assigned

    printf("Please enter your name and surname, respectively:");
    scanf("%s%s",&customerName,&customerSurname);

    rooms[roomToBeQuestioned-1].customer.customerName=(char*)malloc(sizeof(char)*strlen(customerName)+1);
    rooms[roomToBeQuestioned-1].customer.customerSurname=(char*)malloc(sizeof(char)*strlen(customerSurname)+1);
    strcpy(rooms[roomToBeQuestioned-1].customer.customerName,customerName);
    strcpy(rooms[roomToBeQuestioned-1].customer.customerSurname,customerSurname);

    printf("Please enter how many people you will be:");
    scanf("%d",&rooms[roomToBeQuestioned-1].numberOfPeople);

    printf("Please enter the entry date as (day:month:year):");
    scanf("%d:%d:%d",&rooms[roomToBeQuestioned-1].dateOfEntry.day,&rooms[roomToBeQuestioned-1].dateOfEntry.mounth,&rooms[roomToBeQuestioned-1].dateOfEntry.year);

    printf("Please enter the date of departure (day:month:year):");
    scanf("%d:%d:%d",&rooms[roomToBeQuestioned-1].releaseDate.day,&rooms[roomToBeQuestioned-1].releaseDate.mounth,&rooms[roomToBeQuestioned-1].releaseDate.year);

    rooms[roomToBeQuestioned-1].priceInformation=priceCalculation(rooms,roomToBeQuestioned);
    printf("Total amount you have to pay:%.2lfTL\n",rooms[roomToBeQuestioned-1].priceInformation);
    printf("Do you approve(Y-N):");
    fflush(stdin);
    character=getchar();
    if(character=='H'){
        reservationClear(rooms,roomToBeQuestioned);
        return;
    }
    rooms[roomToBeQuestioned-1].roomCondition=1;//so our room is full.
}
void roomInfoInquiry(roomInformation *rooms,int roomNumber){
    if(rooms[roomNumber-1].roomCondition!=0){// so if full 0 empty 1 full
        printf("%d Room numbered is occupied until %d:%d:%d.\n",roomNumber,rooms[roomNumber-1].releaseDate.day,rooms[roomNumber-1].releaseDate.mounth,rooms[roomNumber-1].releaseDate.year);
    }
    else{
        printf("%d room number is currently vacant.\n",roomNumber);
    }
}
void priceInformationPrint(){
    int numberOfPeople;
    double totalAmount=0.0;
    dateInformation dateOfEntry,releaseDate;

    printf("Please enter how many people you will be:");
    scanf("%d",&numberOfPeople);
    printf("Please enter the entry date as (day:month:year):");
    scanf("%d:%d:%d",&dateOfEntry.day,&dateOfEntry.mounth,&dateOfEntry.year);

    printf("Please enter the date of departure (day:month:year):");
    scanf("%d:%d:%d",&releaseDate.day,&releaseDate.mounth,&releaseDate.year);

    totalAmount=calculateDayDifference(dateOfEntry,releaseDate)*numberOfPeople*150;//150->Fees for 1 person for 1 day.
    printf("Total amount you have to pay:%.2lf",totalAmount);
}

void backupRecording(roomInformation *rooms){
    int i;
    FILE *hotelRecords=fopen("hotelRecords.txt","a");
    if(hotelRecords==NULL){
        fprintf(stderr,"An error occurred while retrieving the backup recording.");
        exit(1);
    }
    for(i=0;i<numberOfRooms;i++){
        if(rooms[i].roomCondition!=0){
            fprintf(hotelRecords,"-----------------------------------------------------------------------------\n");
            fprintf(hotelRecords,"Oda Numarasi:%d\n",rooms[i].roomNumber);
            fprintf(hotelRecords,"Musterinin Adi-Soyadi:%s %s\n",rooms[i].customer.customerName,rooms[i].customer.customerSurname);
            fprintf(hotelRecords,"Kisi Sayisi:%d\n",rooms[i].numberOfPeople);
            fprintf(hotelRecords,"Toplam Tutar:%.2lfTL\n",rooms[i].priceInformation);
            fprintf(hotelRecords,"Giris Tarihi:%d:%d:%d\n",rooms[i].dateOfEntry.day,rooms[i].dateOfEntry.mounth,rooms[i].dateOfEntry.year);
            fprintf(hotelRecords,"Cikis Tarihi:%d:%d:%d\n",rooms[i].releaseDate.day,rooms[i].releaseDate.mounth,rooms[i].releaseDate.year);
        }
    }
    fclose(hotelRecords);
}

int main(){
    int setPassword=123456,userEnteredPassword,roomNumber;
    authorizationLevels userAuthority;
    char character;
    roomInformation *roomArray;//all information will be kept here.
    roomArray=(roomInformation*)calloc(numberOfRooms,sizeof(roomInformation));//we were created dynamically.
    printf("\t\t\t\tWelcome to the Hotel Reservation system\n");
    printf("Please enter your password if you work here:");
    scanf("%d",&userEnteredPassword);
    if(setPassword==userEnteredPassword){//the user is an employee of the hotel, authorized personnel
        userAuthority=employee;
    }
    else{//authorized customer.
        userAuthority=customer;
    }
    do{
        printf("1. If you want to make a new customer entry, 'E'\n"
               "2. If you want to query room information, 'S'\n"
               "3. Click 'G' if you want to display occupied room information.\n"
               "4. 'F' if you want to inquire about price");
        printf("5. 'C' if you want to perform customer checkout\n"
               "6. If you want to log out of the system, press 'Q':");
        fflush(stdin);
        character=getchar();
        switch(character){
            case 'E':
            case 'e':
                if(userAuthority==employee){
                    addNewCustomer(roomArray);
                }
                else{
                    printf("This area can only be used by employees.");
                }
                break;
            case 'S':
            case 's':
                printf("Please enter the number of the room to be queried:");
                scanf("%d",&roomNumber);
                roomInfoInquiry(roomArray,roomNumber);
                break;
            case 'G':
            case 'g':
                if(userAuthority==employee){
                    occupiedRoomInformationPrint(roomArray);
                }
                else{
                    printf("This area can only be used by employees.");
                }
                break;
            case 'C':
            case 'c':
                if(userAuthority==employee){
                    printf("Enter the room number you want to check out:");
                    scanf("%d",&roomNumber);
                    reservationClear(roomArray,roomNumber);//the clear reservation function that we used before.
                }
                else{
                    printf("This area can only be used by employees.");
                }
                break;
            case 'F':
            case 'f':
                priceInformationPrint();
                break;
            case 'Q':
            case 'q':
                backupRecording(roomArray);
                break;
            default:
                break;
        }
    }while(character!='Q');
    return 0;
}