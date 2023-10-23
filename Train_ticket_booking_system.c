#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>


char origin[20], destination[20], class_type[30], train[20], start_date[20], end_date[20],payment[5];
int class_price, train_price, train_number,c_type,t_type;
float total_price;
char user_type[100], user_first_name[100], user_last_name[100], user_email[100], password[100];

#define total_number_of_records 10
#define length_of_string 100

//function to print user details
void show_user_details(char f[length_of_string], char l[length_of_string], char e[length_of_string], char at[length_of_string],char pass[length_of_string]){
   printf("\n===================================== Your Account Details ==================================================\n\n");
   printf("First Name : %s\n\n",f);
   printf("Last Name : %s\n\n",l);
   printf("Email ID: %s\n\n",e);
   printf("Password: %s\n\n",pass);
   printf("Account Type: %s\n\n",at);
   printf("===============================================================================================================\n");
   printf("\n\nExiting This Module .....\n\n");
}

//main function to register the user
void user_register(){

int choice;

printf("\nEnter your First Name :\n");
scanf("%s",user_first_name);

printf("\nEnter your Last Name :\n");
scanf("%s",user_last_name);

printf("\nEnter your Email ID :\n");
scanf("%s",user_email);

printf("\nEnter your Password :\n");
scanf("%s",password);

printf("\nSelect your account type (Enter 1 or 2):\n1. Personal Account - (Maximum 10 tickets can be purchased)\n2. Travel Agency Account (Maximum 100 tickets can be purchased)\n");
scanf("%d",&choice);
(choice==1)?strcpy(user_type,"Personal"):strcpy(user_type,"Travel Agency");
show_user_details(user_first_name,user_last_name,user_email,user_type,password);
printf("\n\nYour Account Registred sucessfully!!! :)\n\n");
}

char available_class[10][50] = {
                                  "1st-Tier AC",
                                  "2nd-Tier AC",
                                  "3rd-Tier AC",
                                  "2nd Class (With Berth)",
                                  "2nd Class(Without Berth)",
                                  "Unreserved" }, tclass[10];
char available_seats[10][50] = {
                                  "68",
                                  "52",
                                  "35",
                                  "29",
                                  "41",
                                  "39" }, aseats[10]; 

//structure to store all passengers details
struct passengers_details {
    char name[50];
    int age;
    char gender[10];
    int seat_number;
} p_details[100];

//function to check user account type
bool checkType(char acc_type[20], char total_tickets[5]){
  
  int total = atoi(total_tickets);
  
  if(strcmp(acc_type, "Personal") == 0 && total > 10){
    return false;
  }
  else { return true;}
}

//function to get ticket details from user
void get_ticket_details(){
    int c_type,t_type;
    printf("\n\nPlease enter your origin : ");
    scanf("%s",origin);
    printf("\nPlease enter your destination : ");
    scanf("%s",destination);
    printf("\nPlease enter start date of Travel : ");
    scanf("%s",start_date);
    printf("\nPlease enter end date of Travel : ");
    scanf("%s",end_date);
    selectTrain:
    printf("\nPlease Select from the below Train Available for this Route:-\n1. Rajdhani Express\n2. Shatabdi Express\n3. Toofan Express\n4. Gareeb Rath Express\n\n");
    scanf("%d",&t_type);
    switch (t_type)
    {
    case 1:
        strcpy(train,"Rajdhani Express");
        train_price=1000;
        train_number=072231;
        break;
    case 2:
        strcpy(train,"Shatabdi Express");
        train_price=800;
        train_number=14560;
        break;
    case 3:
        strcpy(train,"Toofan Express");
        train_price=600;
        train_number=24589;
        break;
    case 4:
        strcpy(train,"Gareeb Rath Express");
        train_price=200;
        train_number=51267;
        break;
    default:
        printf("Oops! Please Select from the one of the options provided!\n");
        goto selectTrain;
    }
    selectClass:
    printf("\nPlease Select the Class from Below Options :-\n1. 1st-Tier AC\n2. 2nd-Tier AC\n3. 3rd-Tier AC\n4. 2nd Class (With Berth)\n5. 2nd Class(Without Berth)\n6. Unreserved\n");
    scanf("%d",&c_type);

    switch (c_type)
    {
    case 1:
        strcpy(class_type,"1st-Tier AC");
        class_price=3000;
        break;
    case 2:
        strcpy(class_type,"2nd-Tier AC");
        class_price=2000;
        break;
    case 3:
        strcpy(class_type,"3rd-Tier AC");
        class_price=1000;
        break;
    case 4:
        strcpy(class_type,"2nd Class (With Berth)");
        class_price=700;
        break;
    case 5:
        strcpy(class_type,"2nd Class(Without Berth)");
        class_price=400;
        break;
    case 6:
        strcpy(class_type,"Unreserved");
        class_price=200;
        break;
    default:
        printf("Oops! Please Select from the one of the options provided!\n");
        goto selectClass;
    }

}

//function to take all passengers details from user
void take_passengers_details(int total){
for (int i = 0; i < total; i++)
{
 printf("\n\nPlease Enter the details for Passenger %d\n",i+1);
 printf("Name :");
 scanf("%s", p_details[i].name);
 printf("\nAge :");
 scanf("%d",&p_details[i].age);
 printf("\nGender :");
 scanf("%s",p_details[i].gender);
}
printf("\n\n---------------------------------Printing All Passengers Details---------------------------------\n\n");
for (int i = 0; i < total; i++)
{
 printf("Passenger #%d\n",i+1);
 printf("\nName : %s",p_details[i].name);
 printf("\nAge : %d",p_details[i].age);
 printf("\nGender : %s\n\n",p_details[i].gender);
 p_details[i].seat_number=25 + i;
}
printf("\n--------------------------------------------------------------------------------------------------\n\n");

}

//function to print the final ticket booked by user
void print_all_details(int total){

printf("\n\n=====================================Your Ticket Bookings Details====================================\n");
 printf("\nOrigin : %s\n",origin);
 printf("\nDestination : %s\n",destination);
 printf("\nStarting Date of Travel : %s\n",start_date);
 printf("\nEnding Date of Travel : %s\n",start_date);
 printf("\nTrain Name : %s\n",train);
 printf("\nTrain Number : %d\n",train_number);
 printf("\nCoach Class : %s\n",class_type);
 printf("\nTotal Passengers : %d\n",total);
 printf("\nTotal Amount Paid : %.2f Rupees\n\n",total_price);

 printf("******************************************All Passengers details****************************************\n\n");
for (int i = 0; i < total; i++)
{
 printf("Passenger #%d------------------------------------\n",i+1);
 printf("\nName : %s",p_details[i].name);
 printf("\nAge : %d",p_details[i].age);
 printf("\nGender : %s",p_details[i].gender);
 printf("\nSeat Number : %d\n\n",p_details[i].seat_number);
}
 printf("********************************************************************************************************\n");

printf("\n========================================================================================================\n\n");    
}

//main function to book tickets based on the details provided by user
void ticket_booking(){

int exists=0,more_tic=0,Total_tickets=0;
char email_id[30], user_type[20], user_name[30], total_no_of_tickets[5], password[20];
char registered_user_emails[10][50] = {
                                  "test1@test.com",
                                  "test2@test.com",
                                  "test3@test.com" }, emails[10];
char registered_user_name[10][50] = {
                                  "Teeone Agarwal"
                                  "Titu Singh",
                                  "Tethree Gupta" }, name[10];
char registered_user_account_type[10][50] = {
                                  "Personal",
                                  "Travel",
                                  "Personal" }, accounttype[10];
char registered_user_password[10][50] = {
                                  "test1",
                                  "test2",
                                  "test3" }, pword[10];                                
                                  
login:
printf("Please Enter Your Registered Email ID: ");
scanf("%s",email_id);
printf("Please Enter Your Password: ");
scanf("%s",password);

for(int i = 0; i < 5; i++)
    {
        if(strcmp(email_id, registered_user_emails[i]) == 0 )
        {
            if (strcmp(password, registered_user_password[i]) == 0 )
            {
            strcpy(user_type, registered_user_account_type[i]);
            strcpy(user_name, registered_user_name[i]);
            exists = 1;
            break;
            }

            else
            {
            exists=2;
            break;
            }
        }
    }

    if(exists==1)
    {
        booktics:
        printf("\n########################################### Welcome To Our Ticket Booking Module ###########################################!\n");
        printf("Please Fill out the below Fields to Book a ticket :-");
        get_ticket_details();
        printf("\nPlease Enter number of tickets to book :\n");
        scanf("%s",total_no_of_tickets);
        Total_tickets=atoi(total_no_of_tickets);
        if(checkType(user_type,total_no_of_tickets)){
        take_passengers_details(Total_tickets);
        total_price= train_price + class_price*Total_tickets; 
        printf("Total amount to pe paid for all tickets : %.2f\n Do you confirm this payment will all these ticket booking details?(Type Yes or No)\n",total_price);
        scanf("%s",payment);
        if (strcmp(payment, "yes") == 0 || strcmp(payment, "Yes") == 0  || strcmp(payment, "YES") == 0 )
        {print_all_details(Total_tickets);
        printf("\n************************* Congratulations!!! Your Tickets have been booked succesfully!!! ************************************\n");
        } else{printf("\nCancelling this booking session......\n");}
        printf("\n############################################################################################################################!\n");
        }
        else{
        printf("\n\nAlert: Your account type is personal which doesn't allow more than 10 tickets booking at a time\n\nPlease Create a Travel Agency type account to book more than 10 tickets !!!\n");
        printf("\nHence ending this booking session......\n");
        }
        printf("\nWants to book more tickets? (Type 1 for Yes and 2 for No) : -\n");
        scanf("%d",&more_tic);
        if(more_tic==1) {goto booktics;} 
        else{ 
        printf("Exiting this Module....."); }
    }
    else if(exists==2){
    printf("\nOops! You entered the wrong password for your registered email id!, Please Try again!\n\n");
    goto login;
    }
    else
    {
        printf("\nApologies for the inconvenience! \n\nThis email id is currently not registered with us.\n\nPlease create a new account with this email id i.e. %s", email_id);
    }

}

void get_inputs_from_user(){
    printf("\nPlease Enter Your Origin :");
    scanf("%s",origin);
    printf("\nPlease Enter Your Destination : ");
    scanf("%s",destination);
    selectTrain:
    printf("\nPlease Select from the below Trains Available for this Route:-\n1. Rajdhani Express\n2. Shatabdi Express\n3. Toofan Express\n4. Gareeb Rath Express\n\n");
    scanf("%d",&t_type);
    switch (t_type)
    {
    case 1:
        strcpy(train,"Rajdhani Express");
        train_price=1000;
        train_number=072231;
        break;
    case 2:
        strcpy(train,"Shatabdi Express");
        train_price=800;
        train_number=14560;
        break;
    case 3:
        strcpy(train,"Toofan Express");
        train_price=600;
        train_number=24589;
        break;
    case 4:
        strcpy(train,"Gareeb Rath Express");
        train_price=200;
        train_number=51267;
        break;
    default:
        printf("Oops! Please Select from the one of the options provided!\n");
        goto selectTrain;
    }
    printf("\nPlease Enter your Travel Start Date : ");
    scanf("%s",start_date);
    printf("\nPlease Enter your Travel End Date : ");
    scanf("%s",end_date);
    selectClass:
    printf("\nPlease Select your Preferred Coach Class from Below Options :-\n1. 1st-Tier AC\n2. 2nd-Tier AC\n3. 3rd-Tier AC\n4. 2nd Class (With Berth)\n5. 2nd Class(Without Berth)\n6. Unreserved\n");
    scanf("%d",&c_type);

    switch (c_type)
    {
    case 1:
        strcpy(class_type,"1st-Tier AC");
        class_price=3000;
        break;
    case 2:
        strcpy(class_type,"2nd-Tier AC");
        class_price=2000;
        break;
    case 3:
        strcpy(class_type,"3rd-Tier AC");
        class_price=1000;
        break;
    case 4:
        strcpy(class_type,"2nd Class (With Berth)");
        class_price=700;
        break;
    case 5:
        strcpy(class_type,"2nd Class(Without Berth)");
        class_price=400;
        break;
    case 6:
        strcpy(class_type,"Unreserved");
        class_price=200;
        break;
    default:
        printf("Oops! Please Select from the one of the options provided!\n");
        goto selectClass;
    }
}

void show_available_seats(){
    char seats[10];
    for(int i = 0; i < 6; i++)
    {
        if(strcmp(class_type,available_class[i]) == 0 )
        {
          strcpy(seats,available_seats[i]);
        }
    }
    printf("\n#########################################################################################################################################################\n");
    printf("############################### Number of Seats Availble in %s of %s with Train Number %d are %s Seats. #########################",class_type,train,train_number,seats);
    printf("\n#########################################################################################################################################################\n"); 
}

void seat_availbility(){

int exists=0,checkagain=0;
char email_id[100], user_type[100], user_name[100], password[20];

char registered_user_emails[10][50] = {
                                  "test1@test.com",
                                  "test2@test.com",
                                  "test3@test.com" }, emails[10];
char registered_user_name[10][50] = {
                                  "Teeone Agarwal"
                                  "Titu Singh",
                                  "Tethree Gupta" }, name[10];
char registered_user_account_type[10][50] = {
                                  "Personal",
                                  "Travel",
                                  "Personal" }, accounttype[10];
char registered_user_password[10][50] = {
                                  "test1",
                                  "test2",
                                  "test3" }, pword[10];                                   
                                  
login:
printf("Please Enter Your Registered Email ID: ");
scanf("%s",email_id);
printf("Please Enter Your Password: ");
scanf("%s",password);

for(int i = 0; i < 5; i++)
    {
        if(strcmp(email_id, registered_user_emails[i]) == 0 )
        {
            if (strcmp(password, registered_user_password[i]) == 0 )
            {
            strcpy(user_type, registered_user_account_type[i]);
            strcpy(user_name, registered_user_name[i]);
            exists = 1;
            break;
            }

            else
            {
            exists=2;
            break;
            }
        }
    }
    if(exists==2){
    printf("\nOops! You entered the wrong password for your registered email id!, Please Try again!\n\n");
    exists=0;
    goto login;
    }
    else if(exists==1){
    checkTrains:
    get_inputs_from_user();
    show_available_seats();
    printf("\nWant to check available seats for other Trains? : (Type 1 for Yes or 2 for No)\n");
        scanf("%d",&checkagain);
        if(checkagain==1) {goto checkTrains;} 
        else{ 
        printf("Exiting this Module ..........."); }
    }
    else{
    printf("\nApologies for the inconvenience! \n\nThis email id is currently not registered with us.\n\nPlease create a new account with this email id i.e. %s", email_id);
    }

}

//main program
int main(){
    start: int choice,choice2;
    printf("\n\n################################# Welcome to Train Ticket Booking Application #################################\n\nDeveloped and Documented by Aayush Singh - BITS ID: 202117B3731\n\nPlease select from the below desired options to proceed :\n\n1. Create new user account\n2. Book Train Tickets\n3. Check Seat Availablity Status\n4. Exit this App\n\n");
    printf("###############################################################################################################\n\n");
    scanf("%d",&choice);

    switch (choice)//calling funtions based on the choice made by the user
    {
    case 1:
        user_register();
        printf("\n\nNow, Please select one of the below options to proceed: (Enter 1 or 2)\n\n1. Go back to Main Menu\n2.Exit this App\n");
        scanf("%d",&choice2);
        if(choice2==1){goto start;}
        else{break;}
        
    case 2:
        ticket_booking();
        printf("\n\nNow, Please select one of the below options to proceed: (Enter 1 or 2)\n\n1. Go back to Main Menu\n2.Exit this App\n");
        scanf("%d",&choice2);
        if(choice2==1){goto start;}
        else{break;}

    case 3:
        seat_availbility();
        printf("\n\nNow, Please select one of the below options to proceed: (Enter 1 or 2)\n\n1. Go back to Main Menu\n2.Exit this App\n");
        scanf("%d",&choice2);
        if(choice2==1){goto start;}
        else{break;}
        break;
        
    case 4: break;
    
    default:
    printf("!!!Invalid Choice!!!\n\nPlease enter a valid choice from displayed options!!\n\n");
        goto start;
    }

    printf("@@@@@@@@@@@@@@@@@ Exiting This Application!!! @@@@@@@@@@@@@@@@@@@@@@");
}
