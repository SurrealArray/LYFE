#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void clrScr(); //function that clears screen when called
void item(int userItem); //function that prints message when purchasing item
void calcHSH(int* totHealth, int* hunger, int* mentality, int dailyFood, int fitness); ////Function that calculates health, hunger, and happiness after a day
void calcBills(int* interest, int* money, int food, int fit); //Function that calculates amount of money player has after a day
void calcDay(int* timeDay, int* timeYear, int* numOfDays, int* year); //Function that calculates current day, current year, and number of days in simulation

int main(){
    int health = 100, stomach = 100, happiness = 100; //the three main factors a player has to maintain
    int currentYear = 0, currentDay = 1; //current year and day that the player simulated
    int playerMoney = 1000; //money for player at start
    int playerAge = 18, calcYear = 0; //player begins game at the age of 18
    int userInput, userInput2, userInput3, userInput4, loanAmount, payLoan; //user inputs
    int day = 0;    //number of days
    int mileage = 0, mileageSuperCar = 0, mileageSedan = 0, mileageCheapCar = 0; //mileage for each car and overall mileage
    int currentDebt = 0; //current debt the player owes the bank
    int skillGuitar = 0, skillSinging = 0, skillDrums = 0, skillAthleticism = 0; //skills
    int expGig = 0, expOffice = 0, expMedia = 0, expPolitics = 0; //experience from gigs, office work, media coverage, and politics
    int govClear = 0; //determines whether the player has gained government clearance to access higher-up jobs
    int maxLoan = 25000; //max loan the player can take out of the bank
    int realEstate = 0; //tent = 1, trailer = 2, apartment = 3, house = 4, luxHouse = 5, mansion = 6, luxMansion = 7
    int gun = 0, rifle = 0, crateOfWeapons = 0; //black market items
    int guitar = 0, drum = 0, microphone = 0, computer = 0; //store items
    int items = 0; //number of items player has in inventory
    int popularity = 0; //popularity a player has achieved
    int playerFitness = 0, chef = 0;
    int degAssociate = 0, degBachelor = 0, degMaster = 0, degDoctor = 0; //degrees the player can get
    int i; //test value
    int shoes = 0, bike = 0, car = 0, television = 0; //cheapCar = 1, sedan = 2 superCar = 3;
    int sold = 3, purchase = 2, own = 1, none = 0; //prints statement saying item was sold, purchased, already owned, or insufficient funds to purchase
    int gamNum, gamGuess, gamMoney, randNum; //variables used for gambling
    char strCar[20]= "None", strRealEstate[20] = "None"; //strings for car and real estate
    char strTV[15], strDrums[15], strGuitar[15], strMic[15], strComputer[15], strBike[15], strShoes[15]; //store string items
    char strGun[15], strRifle[15], strCrateOfWeapons[15]; //black market string items
    int aB = 177, aL = 216; //ascii variables

    while(health > 0) {    //Runs the program as long as user maintains health about 0
        //main menu displayed with options for player to choose
        printf("\n");
        printf(" -----------------------------------------------------------------------\n |");
        for(i = 0; i <= 46; i++){
            printf("%c", aB);
        }
        printf("|  Year: %d   Day: %d \n", currentYear, currentDay);
        printf(" |%c%c|-----------------------------------------|%c%c|----------------------\n", aB, aB, aB, aB);
        printf(" |%c%c| %c%c       %c%c       %c%c %c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c |%c%c| Health    (%d)\n", aB, aB, aL, aL, aL, aL, aL, aL, aL, aL, aL, aL, aL, aL, aL, aL, aL, aL, aL, aL, aL, aL, aL, aL, aL, aB, aB, health);
        printf(" |%c%c| %c%c        %c%c     %c%c  %c%c       %c%c        |%c%c| Stomach    (%d)\n", aB, aB, aL, aL, aL, aL, aL, aL, aL, aL, aL, aL, aB, aB, stomach);
        printf(" |%c%c| %c%c         %c%c   %c%c   %c%c       %c%c        |%c%c| Happiness    (%d)\n", aB, aB, aL, aL, aL, aL, aL, aL, aL, aL, aL, aL, aB, aB, happiness);
        printf(" |%c%c| %c%c          %c%c %c%c    %c%c%c%c%c%c%c  %c%c%c%c%c%c%c%c%c |%c%c| Current Car: %s\n", aB, aB, aL, aL, aL, aL, aL, aL, aL, aL, aL, aL, aL, aL, aL, aL, aL, aL, aL, aL, aL, aL, aL, aL, aB, aB, strCar);
        printf(" |%c%c| %c%c           %c%c%c     %c%c       %c%c        |%c%c| Debt: $%d\n", aB, aB, aL, aL, aL, aL, aL, aL, aL, aL, aL, aB, aB, currentDebt);
        printf(" |%c%c| %c%c           %c%c%c     %c%c       %c%c        |%c%c| Age: %d\n", aB, aB, aL, aL, aL, aL, aL, aL, aL, aL, aL, aB, aB, playerAge);
        printf(" |%c%c| %c%c%c%c%c%c%c%c%c    %c%c%c     %c%c       %c%c%c%c%c%c%c%c%c |%c%c| Real Estate: %s\n", aB, aB, aL, aL, aL, aL, aL, aL, aL, aL, aL, aL, aL, aL, aL, aL, aL, aL, aL, aL, aL, aL, aL, aL, aL, aB, aB, strRealEstate);
        printf(" |%c%c|-----------------------------------------|%c%c|----------------------\n |", aB, aB, aB, aB);
        for(i = 0; i <= 46; i++){
            printf("%c", aB);
        }
        printf("| Money: $%d\n", playerMoney);
        printf(" -----------------------------------------------------------------------\n");
        printf(" | #| Main Menu    | #|                  | #|                          |\n");
        printf(" -----------------------------------------------------------------------\n");
        printf(" |10| Player Info  |11| Store            |12| Inventory                |  \n");
        printf(" | 7| Job          | 8| Bank             | 9| Food                     |  \n");
        printf(" | 4| Real Estate  | 5| Web              | 6| Practice/Fitness         |  \n");
        printf(" | 1| Education    | 2| Gov't/Hospital   | 3| Miscellaneous Activities |  \n");
        printf(" | 0| Quit         |  |                  |  |                          |\n");
        printf(" -----------------------------------------------------------------------\n\n");
        printf(" Enter number: ");
        scanf("%d", &userInput);
        system("clear");

        //Option Invalid
        if(userInput > 12 || userInput < 0){  //Give the user an error when an option not available is selected
            printf("Invalid #: Please enter a number between 0 and 12\n");
            printf("Press enter to continue");
            clrScr(); //calls function that clears screen
        }
        //Option 12
        if(userInput == 12){ //Inventory
            //display each item a player owns, including car and real estate
            if(items >= 1 || realEstate >= 1 || car >= 1){
                printf("\n");
                printf("|   Inventory   |\n");
                printf("=================\n");
                if(shoes == 1){
                    printf("| %s\n", strShoes);
                }
                if(bike == 1){
                    printf("| %s\n", strBike);
                }
                if(microphone == 1){
                    printf("| %s\n", strMic);
                }
                if(guitar == 1){
                    printf("| %s\n", strGuitar);
                }
                if(computer == 1){
                    printf("| %s\n", strComputer);
                }
                if(drum == 1){
                    printf("| %s\n", strDrums);
                }
                if(television == 1){
                    printf("| %s\n", strTV);
                }
                if(gun == 1){
                    printf("| %s\n", strGun);
                }
                if(rifle == 1){
                    printf("| %s\n", strRifle);
                }
                if(crateOfWeapons == 1){
                    printf("| %s\n", strCrateOfWeapons);
                }
                printf("------------------\n");
                printf("|\n");
                printf("|  Real Estate  |\n");
                printf("=================\n");
                printf("| %s\n", strRealEstate);
                printf("-----------------\n");
                printf("|\n");
                printf("|    Vehicles   |\n");
                printf("=================\n");
                printf("| %s\n", strCar);
                printf("-----------------\n\n");
                printf("Press enter to continue");
                clrScr();
            }
            else{
                printf("You do not have any items!\n");
                printf("Buy some in the store!\n");
                printf("Press enter to continue");
                clrScr();
            }
        }
        //Option 11
        if(userInput == 11){//Store
            printf("\n");
            printf("Note: \n");
            printf("  Purchasing a new car will\n");
            printf("  replace your older car\n\n");
            printf(" | #| Store        |$$$$$$$|\n");
            printf(" ---------------------------\n");
            printf(" |10| Super-Car    |$500000|\n");
            printf(" | 9| Sedan        | $20000|\n");
            printf(" | 8| Television   |  $2500|\n");
            printf(" | 7| Cheap Car    |  $1000|\n");
            printf(" | 6| Drums        |   $850|\n");
            printf(" | 5| Computer     |   $700|\n");
            printf(" | 4| Guitar       |   $500|\n");
            printf(" | 3| Bike         |   $300|\n");
            printf(" | 2| Shoes        |   $120|\n");
            printf(" | 1| Microphone   |    $80|\n");
            printf(" | 0| Back         |       |\n");
            printf(" ---------------------------\n\n");
            printf(" Enter Number: ");
            scanf("%d", &userInput2);
            system("clear");
            if(userInput2 == 10){ //super-car
                if(playerMoney >= 500000){ //player can purchase only if he has sufficient funds
                    if(car != 3){   //runs if the player does not already have this item
                        playerMoney = playerMoney - 500000; //deducts the cost of the item from player's money
                        strcpy(strCar, "Super-Car"); //type of car is placed in the strCar
                        car = 3;
                        ++items;
                        mileageSuperCar = 0; //mileage that the car comes upon first purchase
                        item(purchase); //prints statement confirming player has purchased this item
                    }
                    else{
                        item(own); //prints statement showing player already has this item
                    }
                }
                else{
                    item(none); //prints statement showing player does not have enough money to purchase this item
                }
            }
            if(userInput2 == 9){  //sedan
               if(playerMoney >= 20000){
                    if(car != 2){
                        playerMoney = playerMoney - 20000;
                        car = 2;
                        ++items;
                        strcpy(strCar, "Sedan");
                        mileageSedan = 15000;
                        item(purchase);
                    }
                    else{
                        item(own);
                    }
                }
                else{
                    item(none);
                }
            }
            if(userInput2 == 8){ //television
                if(playerMoney >= 2500){
                    if(television == 0){
                    playerMoney = playerMoney - 2500;
                    television = 1;
                    ++items;
                    strcpy(strTV, "Television");
                    item(purchase);
                    }
                    else{
                        item(none);
                    }
                }
                else{
                    item(none);
                }
            }
            if(userInput2 == 7){ //cheap car
                if(playerMoney >= 1000){
                    if(car != 1){
                        playerMoney = playerMoney - 1000;
                        car = 1;
                        ++items;
                        strcpy(strCar, "Cheap Car");
                        mileageCheapCar = 250000;
                        item(purchase);
                    }
                    else{
                        item(own);
                    }
                }
                else{
                    item(none);
                }
            }
            if(userInput2 == 6){ //drums
                if(playerMoney >= 850){
                    if(drum == 0){
                        playerMoney = playerMoney - 850;
                        drum = 1;
                        ++items;
                        strcpy(strDrums, "Drums");
                        item(purchase);
                    }
                    else{
                        item(own);
                    }
                }
                else{
                    item(none);
                }
            }
            if(userInput2 == 5){ //computer
                if(playerMoney >= 700){
                    if(computer == 0){
                        playerMoney = playerMoney - 700;
                        computer = 1;
                        ++items;
                        strcpy(strComputer, "Computer");
                        item(purchase);
                    }
                    else{
                        item(own);
                    }
                }
                else{
                    item(none);
                }
            }
            if(userInput2 == 4){ //guitar
                if(playerMoney >= 500){
                    if(guitar == 0){
                        playerMoney = playerMoney - 500;
                        guitar = 1;
                        ++items;
                        strcpy(strGuitar, "Guitar");
                        item(purchase);
                    }
                    else{
                        item(own);

                    }
                }
                else{
                    item(none);
                }
            }
            if(userInput2 == 3){ //bike
                if(playerMoney >= 300){
                    if(bike == 0){
                        playerMoney = playerMoney - 300;
                        bike = 1;
                        ++items;
                        strcpy(strBike, "Bike");
                        item(purchase);
                    }
                    else{
                        item(own);
                    }
                }
                else{
                    item(none);
                }
            }
            if(userInput2 == 2){ //shoes
                if(playerMoney >= 120){
                    if(shoes == 0){
                        playerMoney = playerMoney - 120;
                        shoes = 1;
                        strcpy(strShoes, "Shoes");
                        item(purchase);
                    }
                    else{
                        item(own);
                    }
                }
                else{
                    item(none);
                }
            }
            if(userInput2 == 1){ //microphone
                if(playerMoney >= 80){
                    if(microphone == 0){
                        playerMoney = playerMoney - 80;
                        microphone = 1;
                        strcpy(strMic, "Microphone");
                        item(purchase);
                    }
                    else{
                        item(own);
                    }
                }
                else{
                    item(none);
                }
            }
            if(userInput2 == 0){ //back to main menu
                continue;
            }
        }
        //Option 10
        if(userInput == 10){//Player Information
            //displays skills player's has earned in their progression
            printf("\n| |Player Information\n");
            printf("| |------------------------------------------------------\n");
            printf("| |  Stats         |Current Debt:       |$%d\n", currentDebt);
            printf("| |                |Days Past           | %d days\n", day);
            printf("| |                |Popularity          | %d\n", popularity);
            printf("| |------------------------------------------------------\n");
            printf("| |  Skills        |Guitar              | %d\n", skillGuitar);
            printf("| |                |Singing             | %d\n", skillSinging);
            printf("| |                |Drums               | %d\n", skillDrums);
            printf("| |                |Athleticism         | %d\n", skillAthleticism);
            printf("| |------------------------------------------------------\n");
            printf("| | Job Experience |Gig Experience      | %d\n", expGig);
            printf("| |                |Office Experience   | %d\n", expOffice);
            printf("| |                |Media Experience    | %d\n", expMedia);
            printf("| |                |Political Experience| %d\n", expPolitics);
            printf("| |------------------------------------------------------\n");
            printf("| | Car Mileages   |Total Mileage       | %d miles\n", mileage);
            printf("| |                |Super-Car Mileage   | %d miles\n", mileageSuperCar);
            printf("| |                |Sedan Mileage       | %d miles\n", mileageSedan);
            printf("| |                |Cheap Car Mileage   | %d miles\n", mileageCheapCar);
            printf("| |------------------------------------------------------\n\n");
            printf("Enter enter to continue");
            clrScr();
        }
        //Option 9
        if(userInput == 9){ //Food
            printf("| | Health (%d)\n", health);
            printf("| | Stomach (%d)\n", stomach);
            printf("| | Happiness (%d)\n", happiness);
            printf("| | Year: %d   Day: %d\n", currentYear, currentDay);
            printf("| | Money: $%d\n", playerMoney);
            printf("---------------------------------\n");
            printf("|#| Food                   |$$$$|\n");
            printf("---------------------------------\n");
            printf("|5| Personal Chef(per day) |$500|\n");
            printf("|4| Healthy Meal           | $80|\n");
            printf("|3| Fast Food              | $50|\n");
            printf("|2| Meal                   | $30|\n");
            printf("|1| Sandwich               | $15|\n");
            printf("|0| Back                   |    |\n");
            printf("---------------------------------\n\n");
            printf("Enter number: ");
            scanf("%d", &userInput2);
            system("clear");
            if(userInput2 < 0 || userInput2 > 5){
                printf("Invalid #: Enter a number between 0 and 5\n");
                printf("Press enter to continue");
                clrScr();
            }
            if(userInput2 == 5){ //personal chef
                if(playerMoney >= 1000){
                    if(chef == 0){
                        chef = 1; //player now has a personal chef
                        calcBills(&currentDebt, &playerMoney, chef, playerFitness); //calculates bills from debt and expense daily
                        calcDay(&currentDay, &currentYear, &day, &calcYear); //calculates day and year
                        calcHSH(&health, &stomach, &happiness, chef, playerFitness); //calculates health, hunger, and mentality player has daily
                        item(purchase);
                        happiness = 100;
                    }
                    else{
                        item(own);
                    }
                }
                else{
                    item(none);
                }
            }
            if(userInput2 == 4){ //healthy meal
                if(playerMoney >= 80){
                    playerMoney = playerMoney - 80;
                    stomach = stomach + 60;
                    calcBills(&currentDebt, &playerMoney, chef, playerFitness);
                    calcDay(&currentDay, &currentYear, &day, &calcYear);
                    calcHSH(&health, &stomach, &happiness, chef, playerFitness);
                    item(purchase);
                    happiness = happiness + 90;
                }
                else{
                    item(none);
                }
            }
            if(userInput2 == 3){ //fast food
                if(playerMoney >= 50){
                    playerMoney = playerMoney - 50;
                    stomach = stomach + 45;
                    skillAthleticism = skillAthleticism - 1;
                    calcBills(&currentDebt, &playerMoney, chef, playerFitness);
                    calcDay(&currentDay, &currentYear, &day, &calcYear);
                    calcHSH(&health, &stomach, &happiness, chef, playerFitness);
                    item(purchase);
                    happiness = happiness + 10;
                }
                else{
                    item(none);
                }
            }
            if(userInput2 == 2){ //meal
                if(playerMoney >= 30){
                    playerMoney = playerMoney - 30;
                    stomach = stomach + 20;
                    calcBills(&currentDebt, &playerMoney, chef, playerFitness);
                    calcDay(&currentDay, &currentYear, &day, &calcYear);
                    calcHSH(&health, &stomach, &happiness, chef, playerFitness);
                    item(purchase);
                    happiness = happiness + 20;
                }
                else{
                    item(none);
                }
            }
            if(userInput2 == 1){ //sandwich
                if(playerMoney >= 15){
                    playerMoney = playerMoney - 15;
                    stomach = stomach + 10;
                    calcBills(&currentDebt, &playerMoney, chef, playerFitness);
                    calcDay(&currentDay, &currentYear, &day, &calcYear);
                    calcHSH(&health, &stomach, &happiness, chef, playerFitness);
                    item(purchase);
                    happiness = happiness + 10;
                }
                else{
                    item(none);
                }
            }
            if(userInput2 == 0){ //back
                continue;
            }
        }
        //Option 8
        if(userInput == 8){ //Bank
            printf("Year: %d   Day: %d\n\n", currentYear, currentDay);
            printf("Money: $%d\n\n", playerMoney);
            printf("=====================\n\n");
            printf("\n");
            printf("[#] Bank    \n");
            printf("---------------------\n");
            printf("|2| Take out loan\n");
            printf("|1| Pay Loan\n");
            printf("|0| Go back\n\n");
            printf("---------------------\n\n");
            printf("Enter number: ");
            scanf("%d", &userInput2);
            system("clear");
            if(userInput2 == 0){
                continue;
            }
            if(userInput2 == 1) {
                printf("[Pay Loan]\n\n");
                printf("Money: $%d\n\n", playerMoney);
                printf("Current Debt: $%d\n", currentDebt);
                printf("How much would you like to pay?\n");
                printf("Enter amount: ");
                scanf("%d", &payLoan);
                system("clear");
                if(payLoan <= currentDebt && payLoan > 0 && payLoan <= playerMoney){ //player can pay loan as long as they have the required funds
                    currentDebt = currentDebt - payLoan;
                    playerMoney = playerMoney - payLoan;
                    maxLoan = maxLoan + payLoan;
                }
                else{
                    printf("Enter an amount between 0 and %d\n", currentDebt);
                    printf("Press enter to continue");
                    clrScr();
                }
            }
            if(userInput2 == 2){
                printf("[Take out loan]\n\n");
                printf("Max bank loan: $%d\n", maxLoan);
                printf("How much would you like to take out?\n");
                printf("Enter amount: ");
                scanf("%d", &loanAmount);
                system("clear");
                if(loanAmount > 1000 && loanAmount <= maxLoan){  //player can take out loan as long as it is greater than 1000 and less than the max loan
                    currentDebt = currentDebt + loanAmount;
                    maxLoan = maxLoan - loanAmount;
                    playerMoney = playerMoney + loanAmount;
                }
                else{
                    printf("You need to enter a value between 1000 and %d\n", maxLoan);
                    printf("Press enter to continue");
                    clrScr();
                }
            }
        }
        //Option 7
        if(userInput == 7){ //Job
            printf("Health (%d)\n", health);
            printf("Stomach (%d)\n", stomach);
            printf("Happiness (%d)\n\n", happiness);
            printf("Year: %d   Day: %d\n\n", currentYear, currentDay);
            printf("Money: $%d\n", playerMoney);
            printf("=====================================================================\n");
            printf("\n");
            printf("| #| Job                       | #|\n");
            printf("---------------------------------------------------------------------\n");
            printf("|23| Board Member of Corporate |24| President of the Nation\n");
            printf("|21| CEO of Corporate          |22| Main Act Big Stage Gig\n");
            printf("|19| President of Corporate    |20| Nationwide Broadcast Reporter\n");
            printf("|17| VP of Corporate           |18| Congress Senator\n");
            printf("|15| State Senator             |16| Beginning Act Gig\n");
            printf("|13| Professor                 |14| Doctor\n");
            printf("|11| News Reporter             |12| Lawyer\n");
            printf("| 9| Office Job                |10| Manager\n");
            printf("| 7| Athlete                   | 8| Teacher\n");
            printf("| 5| Weather Reporter          | 6| Bank Teller\n");
            printf("| 3| Deliver Pizzas            | 4| Local Band Gig\n");
            printf("| 1| Newspaper Delivery        | 2| Fast Food\n");
            printf("| 0| Back                      |  |\n");
            printf("---------------------------------------------------------------------\n\n");
            printf("Enter number: ");
            scanf("%d", &userInput2);
            system("clear");
            if(userInput2 == 0){  //back to Main Menu
                continue;
            }
            /*each job gives out money, some give out certain skills that can be used to get better jobs.
            some jobs require car or bike for travel purposes*/
            if(userInput2 == 1){  //Newspaper Delivery
                if(bike == 1) {    //Requires bike
                playerMoney = playerMoney + 35;
                calcBills(&currentDebt, &playerMoney, chef, playerFitness);
                calcDay(&currentDay, &currentYear, &day, &calcYear);
                calcHSH(&health, &stomach, &happiness, chef, playerFitness);
                }
                else{
                    printf("You need a bike before you can deliver newspapers!\n");
                    printf("Press enter to continue");
                    clrScr();
                }
            }
            if(userInput2 == 2){  //Fast Food
                playerMoney = playerMoney + 35;
                calcBills(&currentDebt, &playerMoney, chef, playerFitness);
                calcDay(&currentDay, &currentYear, &day, &calcYear);
                calcHSH(&health, &stomach, &happiness, chef, playerFitness);
            }
            if(userInput2 == 3){  //Deliver Pizzas
                if(car >= 1){
                    if(car == 1){
                        mileageCheapCar = mileageCheapCar + 100;
                    }
                    if(car == 2){
                        mileageSedan = mileageSedan + 100;
                    }
                    if(car == 3){
                        mileageSuperCar = mileageSuperCar + 100;
                    }
                    playerMoney = playerMoney + 70;
                    calcBills(&currentDebt, &playerMoney, chef, playerFitness);
                    calcDay(&currentDay, &currentYear, &day, &calcYear);
                    calcHSH(&health, &stomach, &happiness, chef, playerFitness);
                    mileage = mileage + 100;
                }
                else{
                    printf("You need a car before you can deliver pizzas!\n");
                    printf("Press enter to continue");
                    clrScr();
                }
            }
            if(userInput2 == 4){  //Local Band Gig
                if(skillGuitar > 99 || skillDrums > 99 || skillSinging > 99){
                    if(guitar == 1 || drum == 1 || microphone == 1){
                        playerMoney = playerMoney + 80;
                        expGig = expGig + 1;
                        popularity = popularity + 1;
                        calcBills(&currentDebt, &playerMoney, chef, playerFitness);
                        calcDay(&currentDay, &currentYear, &day, &calcYear);
                        calcHSH(&health, &stomach, &happiness, chef, playerFitness);
                    }
                    else{
                        printf("You need a guitar to do this gig!\n");
                        printf("Press enter to continue");
                        clrScr();
                    }
                }
                else{
                    printf("You need at least 100 skill points in guitar, singing, or drums to do this gig!\n");
                    printf("Press enter to continue");
                    clrScr();
                }
            }
            if(userInput2 == 5){  //Weather Reporter
                if(degAssociate == 1) {
                    playerMoney = playerMoney + 70;
                    popularity = popularity + 1;
                    expMedia = expMedia + 1;
                    calcBills(&currentDebt, &playerMoney, chef, playerFitness);
                    calcDay(&currentDay, &currentYear, &day, &calcYear);
                    calcHSH(&health, &stomach, &happiness, chef, playerFitness);
                }
                else{
                    printf("You must have an associate's degree or better to do this job!\n");
                    printf("Press enter to continue");
                    clrScr();
                }
            }
            if(userInput2 == 6){  //Bank Teller
                if(degAssociate == 1) {
                    playerMoney = playerMoney + 85;
                    expOffice = expOffice + 1;
                    calcBills(&currentDebt, &playerMoney, chef, playerFitness);
                    calcDay(&currentDay, &currentYear, &day, &calcYear);
                    calcHSH(&health, &stomach, &happiness, chef, playerFitness);
                }
                else{
                    printf("You must have an associate's degree or better to do this job!\n");
                    printf("Press enter to continue");
                    clrScr();
                }
            }
            if(userInput2 == 7){  //Athlete
                if(skillAthleticism > 99){
                    playerMoney = playerMoney + 100;
                    skillAthleticism = skillAthleticism + 1;
                    calcBills(&currentDebt, &playerMoney, chef, playerFitness);
                    calcDay(&currentDay, &currentYear, &day, &calcYear);
                    calcHSH(&health, &stomach, &happiness, chef, playerFitness);
                }
                else{
                    printf("You must have enough athleticism to do this job!\n");
                    printf("Press enter to continue");
                    clrScr();
                }
            }
            if(userInput2 == 8){  //Teacher
                if(degBachelor == 1 && car >= 1){
                    if(car == 1){
                        mileageCheapCar = mileageCheapCar + 30;
                    }
                    if(car == 2){
                        mileageSedan = mileageSedan + 30;
                    }
                    if(car == 3){
                        mileageSuperCar = mileageSuperCar + 30;
                    }
                    mileage = mileage + 30;
                    playerMoney = playerMoney + 120;
                    calcBills(&currentDebt, &playerMoney, chef, playerFitness);
                    calcDay(&currentDay, &currentYear, &day, &calcYear);
                    calcHSH(&health, &stomach, &happiness, chef, playerFitness);

                }
                else{
                    printf("You must have a bachelor's degree and own a car!\n");
                    printf("Press enter to continue");
                    clrScr();
                }
            }
            if(userInput2 == 9){  //Office Job
                if(degBachelor == 1 && car >= 1){
                    if(car == 1){
                        mileageCheapCar = mileageCheapCar + 30;
                    }
                    if(car == 2){
                        mileageSedan = mileageSedan + 30;
                    }
                    if(car == 3){
                        mileageSuperCar = mileageSuperCar + 30;
                    }
                    mileage = mileage + 30;
                    playerMoney = playerMoney + 150;
                    expOffice = expOffice + 5;
                    calcBills(&currentDebt, &playerMoney, chef, playerFitness);
                    calcDay(&currentDay, &currentYear, &day, &calcYear);
                    calcHSH(&health, &stomach, &happiness, chef, playerFitness);

                }
                else{
                    printf("You must have a bachelor's degree and a car!\n");
                    printf("Press enter to continue");
                    clrScr();
                }
            }
            if(userInput2 == 10){ //Manager
                if(degBachelor == 1 && expOffice > 365 && car >= 1){
                    if(car == 1){
                        mileageCheapCar = mileageCheapCar + 30;
                    }
                    if(car == 2){
                        mileageSedan = mileageSedan + 30;
                    }
                    if(car == 3){
                        mileageSuperCar = mileageSuperCar + 30;
                    }
                    mileage = mileage + 30;
                    playerMoney = playerMoney + 250;
                    expOffice = expOffice + 10;
                    calcBills(&currentDebt, &playerMoney, chef, playerFitness);
                    calcDay(&currentDay, &currentYear, &day, &calcYear);
                    calcHSH(&health, &stomach, &happiness, chef, playerFitness);
                }
                else{
                    printf("You must have a bachelor's degree, a car and you must have enough office experience!\n");
                    printf("Press enter to continue");
                    clrScr();
                }
            }
            if(userInput2 == 11){ //News Reporter
                if(expMedia > 99 && degBachelor == 1 && car >= 1){
                    if(car == 1){
                        mileageCheapCar = mileageCheapCar + 30;
                    }
                    if(car == 2){
                        mileageSedan = mileageSedan + 30;
                    }
                    if(car == 3){
                        mileageSuperCar = mileageSuperCar + 30;
                    }
                    mileage = mileage + 30;
                    playerMoney = playerMoney + 350;
                    expMedia = expMedia + 10;
                    calcBills(&currentDebt, &playerMoney, chef, playerFitness);
                    calcDay(&currentDay, &currentYear, &day, &calcYear);
                    calcHSH(&health, &stomach, &happiness, chef, playerFitness);
                }
                else{
                    printf("You must have a bachelor's degree, a car and you must have enough media experience!\n");
                    printf("Press enter to continue");
                    clrScr();
                }
            }
            if(userInput2 == 12){ //Lawyer
                if(degMaster == 1 && car >= 1){
                    if(car == 1){
                        mileageCheapCar = mileageCheapCar + 50;
                    }
                    if(car == 2){
                        mileageSedan = mileageSedan + 50;
                    }
                    if(car == 3){
                        mileageSuperCar = mileageSuperCar + 50;
                    }
                    mileage = mileage + 50;
                    playerMoney = playerMoney + 500;
                    calcBills(&currentDebt, &playerMoney, chef, playerFitness);
                    calcDay(&currentDay, &currentYear, &day, &calcYear);
                    calcHSH(&health, &stomach, &happiness, chef, playerFitness);
                }
                else{
                    printf("You must have a master's degree and a car!\n");
                    printf("Press enter to continue");
                    clrScr();
                }
            }
            if(userInput2 == 13){ //Professor
                if(degMaster == 1 && car >= 1){
                    if(car == 1){
                        mileageCheapCar = mileageCheapCar + 50;
                    }
                    if(car == 2){
                        mileageSedan = mileageSedan + 50;
                    }
                    if(car == 3){
                        mileageSuperCar = mileageSuperCar + 50;
                    }
                    mileage = mileage + 50;
                    playerMoney = playerMoney + 600;
                    calcBills(&currentDebt, &playerMoney, chef, playerFitness);
                    calcDay(&currentDay, &currentYear, &day, &calcYear);
                    calcHSH(&health, &stomach, &happiness, chef, playerFitness);
                }
                else{
                    printf("You must have a doctor's degree and a car!\n");
                    printf("Press enter to continue");
                    clrScr();
                }
            }
            if(userInput2 == 14){ //Doctor
                if(degDoctor == 1 && car >= 1){
                    if(car == 1){
                        mileageCheapCar = mileageCheapCar + 60;
                    }
                    if(car == 2){
                        mileageSedan = mileageSedan + 60;
                    }
                    if(car == 3){
                        mileageSuperCar = mileageSuperCar + 60;
                    }
                    mileage = mileage + 60;
                    playerMoney = playerMoney + 750;
                    calcBills(&currentDebt, &playerMoney, chef, playerFitness);
                    calcDay(&currentDay, &currentYear, &day, &calcYear);
                    calcHSH(&health, &stomach, &happiness, chef, playerFitness);
                }
                else{
                    printf("You must have a doctor's degree and a car!\n");
                    printf("Press enter to continue");
                    clrScr();
                }
            }
            if(userInput2 == 15){ //State Senator
                if(degMaster == 1 && popularity >= 100){
                    if(car == 1){
                        mileageCheapCar = mileageCheapCar + 75;
                    }
                    if(car == 2){
                        mileageSedan = mileageSedan + 75;
                    }
                    if(car == 3){
                        mileageSuperCar = mileageSuperCar + 75;
                    }
                    mileage = mileage + 75;
                    playerMoney = playerMoney + 1000;
                    expPolitics = expPolitics + 5;
                    popularity = popularity + 2;
                    calcBills(&currentDebt, &playerMoney, chef, playerFitness);
                    calcDay(&currentDay, &currentYear, &day, &calcYear);
                    calcHSH(&health, &stomach, &happiness, chef, playerFitness);
                }
                else{
                    printf("You must have a master's degree and at least 100 popularity!\n");
                    printf("Press enter to continue");
                    clrScr();
                }
            }
            if(userInput2 == 16){ //Beginning Act Gig
                if(skillGuitar > 500 || skillDrums > 500 || skillSinging > 500){
                    if((guitar == 1 || drum == 1 || microphone == 1)&& expGig >= 100 && car >= 1){
                        if(car == 1){
                            mileageCheapCar = mileageCheapCar + 100;
                        }
                        if(car == 2){
                            mileageSedan = mileageSedan + 100;
                        }
                        if(car == 3){
                            mileageSuperCar = mileageSuperCar + 100;
                        }
                        mileage = mileage + 100;
                        playerMoney = playerMoney + 1500;
                        expGig = expGig + 10;
                        popularity = popularity + 200;
                        calcBills(&currentDebt, &playerMoney, chef, playerFitness);
                        calcDay(&currentDay, &currentYear, &day, &calcYear);
                        calcHSH(&health, &stomach, &happiness, chef, playerFitness);
                    }
                    else{
                        printf("You must have a guitar/drum/microphone, a car, and have 100 gig experience\n");
                        printf("Press enter to continue");
                        clrScr();
                    }
                }
                else{
                    printf("You must have over 500 guitar/drum/microphone experience!\n");
                    printf("Press enter to continue");
                    clrScr();
                }
            }
            if(userInput2 == 17){ //VP of Corporate
                if(expOffice >= 300 && degMaster == 1){
                    if(car == 1){
                        mileageCheapCar = mileageCheapCar + 100;
                        mileage = mileage + 100;
                    }
                    if(car == 2){
                        mileageSedan = mileageSedan + 100;
                        mileage = mileage + 100;
                    }
                    if(car == 3){
                        mileageSuperCar = mileageSuperCar + 100;
                        mileage = mileage + 100;
                    }
                    mileage = mileage + 100;
                    playerMoney = playerMoney + 2500;
                    expOffice = expOffice + 10;
                    calcBills(&currentDebt, &playerMoney, chef, playerFitness);
                    calcDay(&currentDay, &currentYear, &day, &calcYear);
                    calcHSH(&health, &stomach, &happiness, chef, playerFitness);
                }
                else{
                    printf("You must have a master's degree and at least 300 office experience to do this job");
                    printf("Press enter to continue");
                    clrScr();
                }
            }
            if(userInput2 == 18){ //Congress Senator
                if(degMaster == 1 && expPolitics > 499 && govClear == 1){
                    if(car == 1){
                        mileageCheapCar = mileageCheapCar + 100;
                        mileage = mileage + 100;
                    }
                    if(car == 2){
                        mileageSedan = mileageSedan + 100;
                        mileage = mileage + 100;
                    }
                    if(car == 3){
                        mileageSuperCar = mileageSuperCar + 100;
                        mileage = mileage + 100;
                    }
                    playerMoney = playerMoney + 3500;
                    expPolitics = expPolitics + 10;
                    popularity = popularity + 2;
                    calcBills(&currentDebt, &playerMoney, chef, playerFitness);
                    calcDay(&currentDay, &currentYear, &day, &calcYear);
                    calcHSH(&health, &stomach, &happiness, chef, playerFitness);
                }
                else{
                    printf("You must have a master's degree, government clearance and 500 political experience!\n");
                    printf("Press enter to continue");
                    clrScr();
                }
            }
            if(userInput2 == 19){ //President of Corporate
                if(expOffice >= 500 && degMaster == 1){
                    if(car == 1){
                        mileageCheapCar = mileageCheapCar + 100;
                        mileage = mileage + 100;
                    }
                    if(car == 2){
                        mileageSedan = mileageSedan + 100;
                        mileage = mileage + 100;
                    }
                    if(car == 3){
                        mileageSuperCar = mileageSuperCar + 100;
                        mileage = mileage + 100;
                    }
                    playerMoney = playerMoney + 4000;
                    expOffice = expOffice + 20;
                    calcBills(&currentDebt, &playerMoney, chef, playerFitness);
                    calcDay(&currentDay, &currentYear, &day, &calcYear);
                    calcHSH(&health, &stomach, &happiness, chef, playerFitness);
                }
                else{
                    printf("You must have at least 500 office experience to do this job\n");
                    printf("Press enter to continue");
                    clrScr();
                }
            }
            if(userInput2 == 20){ //Nationwide Broadcast Reporter
                if(expMedia >= 500 && degBachelor == 1){
                    if(car == 1){
                        mileageCheapCar = mileageCheapCar + 100;
                        mileage = mileage + 100;
                    }
                    if(car == 2){
                        mileageSedan = mileageSedan + 100;
                        mileage = mileage + 100;
                    }
                    if(car == 3){
                        mileageSuperCar = mileageSuperCar + 100;
                        mileage = mileage + 100;
                    }
                    playerMoney = playerMoney + 5000;
                    expMedia = expMedia + 20;
                    calcBills(&currentDebt, &playerMoney, chef, playerFitness);
                    calcDay(&currentDay, &currentYear, &day, &calcYear);
                    calcHSH(&health, &stomach, &happiness, chef, playerFitness);
                }
                else{
                    printf("You must have at least 500 media experience to do this job\n");
                    printf("Press enter to continue");
                    clrScr();
                }
            }
            if(userInput2 == 21){ //CEO of Corporate
                if(expOffice >= 1500 && degMaster == 1){
                    if(car == 1){
                        mileageCheapCar = mileageCheapCar + 100;
                        mileage = mileage + 100;
                    }
                    if(car == 2){
                        mileageSedan = mileageSedan + 100;
                        mileage = mileage + 100;
                    }
                    if(car == 3){
                        mileageSuperCar = mileageSuperCar + 100;
                        mileage = mileage + 100;
                    }
                    playerMoney = playerMoney + 7500;
                    expMedia = expMedia + 20;
                    calcBills(&currentDebt, &playerMoney, chef, playerFitness);
                    calcDay(&currentDay, &currentYear, &day, &calcYear);
                    calcHSH(&health, &stomach, &happiness, chef, playerFitness);
                }
                else{
                    printf("You must have a master degree and at least 1500 office experience to do this job\n");
                    printf("Press enter to continue");
                    clrScr();
                }
            }
            if(userInput2 == 22){ //Main Act Big Stage Gig
                if(skillGuitar >= 1000 || skillSinging >= 1000 || skillDrums >= 1000){
                    if(expGig >= 500 && popularity >= 10000){
                        playerMoney = playerMoney + 10000;
                        expGig = expGig + 20;
                        popularity = popularity + 1000;
                        calcBills(&currentDebt, &playerMoney, chef, playerFitness);
                        calcDay(&currentDay, &currentYear, &day, &calcYear);
                        calcHSH(&health, &stomach, &happiness, chef, playerFitness);
                    }
                    else{
                        printf("You must have a guitar/microphone/drums and a 10,000 popularity\n");
                        printf("Press enter to continue");
                        clrScr();
                    }
                }
                else{
                    printf("You must have 1,000 guitar, drums, or singing skill\n");
                    printf("Press enter to continue");
                    clrScr();
                }
            }
            if(userInput2 == 23){ //Board Member of Corporate
                if(expOffice >= 5000 && degMaster == 1){
                    if(car == 1){
                        mileageCheapCar = mileageCheapCar + 100;
                        mileage = mileage + 100;
                    }
                    if(car == 2){
                        mileageSedan = mileageSedan + 100;
                        mileage = mileage + 100;
                    }
                    if(car == 3){
                        mileageSuperCar = mileageSuperCar + 100;
                        mileage = mileage + 100;
                    }
                    playerMoney = playerMoney + 12500;
                    expOffice = expOffice + 50;
                    calcBills(&currentDebt, &playerMoney, chef, playerFitness);
                    calcDay(&currentDay, &currentYear, &day, &calcYear);
                    calcHSH(&health, &stomach, &happiness, chef, playerFitness);
                }
                else{
                    printf("You must have a master degree and at least 5000 office experience to do this job");
                    printf("Press enter to continue");
                    clrScr();
                }
            }
            if(userInput2 == 24){ //President of the Nation
                if(expPolitics >= 1000 && popularity >= 1000000 && govClear == 1){
                    playerMoney = playerMoney + 15000;
                    expPolitics = expPolitics + 1000;
                    popularity = popularity + 1000;
                    calcBills(&currentDebt, &playerMoney, chef, playerFitness);
                    calcDay(&currentDay, &currentYear, &day, &calcYear);
                    calcHSH(&health, &stomach, &happiness, chef, playerFitness);
                }
                else{
                    printf("You must have a master's degree, government clearance and 1000 political experience!\n");
                    printf("Press enter to continue");
                    clrScr();
                }
            }
        }
        //Option 6
        if(userInput == 6){ //Practice/Fitness
            printf("\n");
            printf("|#| Practice / Fitness     |$$$$$|\n");
            printf("----------------------------------\n");
            printf("|8| Practice Guitar        |     |\n");
            printf("|7| Practice Singing       |     |\n");
            printf("|6| Practice Drums         |     |\n");
            printf("|5| Go Jogging             |     |\n");
            printf("|4| Go Biking              |     |\n");
            printf("|3| Fitness Gym Membership | $500|\n");
            printf("|2| Personal Trainer       |$1500|\n");
            printf("|1| Work Out               |     |\n");
            printf("|0| Back to Main Menu      |     |\n");
            printf("----------------------------------\n\n");
            printf("Enter number: ");
            scanf("%d", &userInput2);
            system("clear");
            /*player can practice certain skills which can help them get better jobs in the future
            player can also do fitness activities to increase health, happiness, and athleticism skill*/
            if(userInput2 == 8){ //practice guitar
                if(guitar == 1){
                    skillGuitar = skillGuitar + 3;
                    calcBills(&currentDebt, &playerMoney, chef, playerFitness);
                    calcDay(&currentDay, &currentYear, &day, &calcYear);
                    calcHSH(&health, &stomach, &happiness, chef, playerFitness);
                }
                else{
                    printf("You need a guitar to practice this skill\n");
                    printf("Press enter to continue");
                    clrScr();
                }
            }
            if(userInput2 == 7){ //practice singing
                if(microphone == 1){
                    skillSinging = skillSinging + 3;
                    calcBills(&currentDebt, &playerMoney, chef, playerFitness);
                    calcDay(&currentDay, &currentYear, &day, &calcYear);
                    calcHSH(&health, &stomach, &happiness, chef, playerFitness);
                }
                else{
                    printf("You need a microphone to practice this skill\n");
                    printf("Press enter to continue");
                    clrScr();
                }
            }
            if(userInput2 == 6){ //practice drums
                if(drum == 1){
                    skillDrums = skillDrums + 3;
                    calcBills(&currentDebt, &playerMoney, chef, playerFitness);
                    calcDay(&currentDay, &currentYear, &day, &calcYear);
                    calcHSH(&health, &stomach, &happiness, chef, playerFitness);
                }
                else{
                    printf("You need drums to practice this skill\n");
                    printf("Press enter to continue");
                    clrScr();
                }
            }
            if(userInput2 == 5){ //go jogging
                if(shoes == 1){
                    health = health + 10;
                    happiness = happiness + 15;
                    calcBills(&currentDebt, &playerMoney, chef, playerFitness);
                    calcDay(&currentDay, &currentYear, &day, &calcYear);
                    calcHSH(&health, &stomach, &happiness, chef, playerFitness);
                }
                else{
                    printf("You need shoes to do this\n");
                    printf("Press to continue");
                    clrScr();
                }
            }
            if(userInput2 == 4){ //go biking
                if(bike == 1){
                    health = health + 15;
                    happiness = happiness + 25;
                    calcBills(&currentDebt, &playerMoney, chef, playerFitness);
                    calcDay(&currentDay, &currentYear, &day, &calcYear);
                    calcHSH(&health, &stomach, &happiness, chef, playerFitness);
                }
                else{
                    printf("You need a bike to do this\n");
                    printf("Press to continue");
                    clrScr();
                }
            }
            if(userInput2 == 3){ //fitness membership
                if(playerMoney >= 500){
                    playerFitness = 1;
                    calcBills(&currentDebt, &playerMoney, chef, playerFitness);
                    calcDay(&currentDay, &currentYear, &day, &calcYear);
                    calcHSH(&health, &stomach, &happiness, chef, playerFitness);
                }
                else{
                    item(none);
                }
            }
            if(userInput2 == 2){ //personal trainer
                if(playerMoney >= 1500){
                    playerFitness = 2;
                    happiness = 100;
                    calcBills(&currentDebt, &playerMoney, chef, playerFitness);
                    calcDay(&currentDay, &currentYear, &day, &calcYear);
                    calcHSH(&health, &stomach, &happiness, chef, playerFitness);
                }
                else{
                    item(none);
                }
            }
            if(userInput2 == 1){ //work out
                skillAthleticism = skillAthleticism + 3;
                happiness = happiness + 15;
                health = health + 5;
                calcBills(&currentDebt, &playerMoney, chef, playerFitness);
                calcDay(&currentDay, &currentYear, &day, &calcYear);
                calcHSH(&health, &stomach, &happiness, chef, playerFitness);
            }
            if(userInput2 == 0){ //back to main menu
                continue;
            }
        }
        //Option 5
        if(userInput == 5){ //Web
            if(computer == 1){
                printf("\n");
                printf("|#| Web\n");
                printf("-------------------------------\n");
                printf("|4| Watch Entertaining Videos\n");
                printf("|3| Buy Black Market Items\n");
                printf("|2| Gamble\n");
                printf("|1| Sell items\n");
                printf("|0| Back to Main Menu\n");
                printf("-------------------------------\n\n");
                printf("Enter Number: ");
                scanf("%d", &userInput2);
                system("clear");
                if(userInput2 == 4){ //watch entertaining videos
                    //increases happiness of player
                    happiness = happiness + 35;
                    calcBills(&currentDebt, &playerMoney, chef, playerFitness);
                    calcDay(&currentDay, &currentYear, &day, &calcYear);
                    calcHSH(&health, &stomach, &happiness, chef, playerFitness);
                }
                if(userInput2 == 3){ //buy black market items
                    //black market items purpose are only for illegal activities that the player may do
                    printf("[The Black Market]\n\n");
                    printf("|#| Purchase         |$$$$$$|\n");
                    printf("-----------------------------\n");
                    printf("|3| Crate of Weapons |$10000|\n");
                    printf("|2| Rifle            | $2000|\n");
                    printf("|1| Gun              |  $300|\n");
                    printf("|0| Back to Main Menu|      |\n");
                    printf("-----------------------------\n\n");
                    printf("Enter number: ");
                    scanf("%d", &userInput3);
                    system("clear");
                    if(userInput3 == 1){ //buy gun
                        if(playerMoney >= 300){
                            if(gun == 0){
                                playerMoney = playerMoney - 300;
                                gun = 1;
                                ++items;
                                strcpy(strGun, "Gun");
                                item(purchase);
                            }
                            else{
                                item(own);
                            }
                        }
                        else{
                            item(none);
                        }
                    }
                    if(userInput3 == 2){ //buy rifle
                        if(playerMoney >= 2000){
                            if(rifle == 0){
                                playerMoney = playerMoney - 2000;
                                rifle = 1;
                                ++items;
                                strcpy(strRifle, "Rifle");
                                item(purchase);
                            }
                            else{
                                item(own);
                            }
                        }
                        else{
                            item(none);
                        }
                    }
                    if(userInput3 == 3){ //buy crate of weapons
                        if(playerMoney >= 10000){
                            if(crateOfWeapons == 0){
                                crateOfWeapons = 1;
                                ++items;
                                strcpy(strCrateOfWeapons, "Crate of Weapons");
                                playerMoney = playerMoney - 10000;
                                item(purchase);
                            }
                            else{
                                item(own);
                            }
                        }
                        else{
                            item(none);
                        }
                    }
                    if(userInput3 == 0){ //buy back to main menu
                        continue;
                    }
                }
                if(userInput2 == 2){ //gamble
                srand(time(NULL));
                printf("\n[Gamble]\n\n");
                printf("\tWin to gain 10x your bet!\n");
                printf("\tWin by guessing the right number between 1 and 10\n\n");
                printf("How much money would you like to gamble?\n");
                printf("Enter amount: ");
                scanf("%d", &gamMoney);
                system("clear");
                if(playerMoney >= gamMoney){
                    printf("Guess a number between 1 and 10\n\n");
                    printf("Enter number: ");
                    scanf("%d", &gamGuess);
                    system("clear");
                    gamNum = rand() % 10 + 1; //makes the gamNum a number between 1 and 10.
                    if(gamGuess <= 10 && gamGuess >= 1){ //player must make a guess between 1 and 10
                        if(gamGuess == gamNum){ //player wins 10x if number guess is correct
                            printf("Congratulations! You won $%d\n", gamMoney * 10);
                            printf("Number was %d\n", gamNum);
                            playerMoney = playerMoney + (gamMoney * 10);
                            printf("Press enter to continue");
                            clrScr();
                        }
                        else{
                            playerMoney = playerMoney - gamMoney;
                            printf("Sorry! You lost!\n");
                            printf("Your guess was %d\n", gamGuess);
                            printf("The number was %d\n", gamNum);
                            printf("Press enter to continue");
                            clrScr();
                        }
                    }
                    else{
                        printf("Invalid #: Enter a number between 1 and 10\n");
                        printf("Press enter to continue");
                        clrScr();
                    }
                }
                else{
                    printf("Invalid $$: Enter amount between 0 and %d\n", playerMoney);
                    printf("Press enter to continue");
                    clrScr();
                }
            }
                if(userInput2 == 1){ //sell items
                    if(items > 0){   //strings for items owned
                        printf("====================\n");
                        printf("|  | Sell Items |  |\n");
                        printf("====================\n");
                        //displays items owned and it's resell value
                        if(gun == 1 || rifle == 1 || crateOfWeapons == 1){
                            printf("|10| ");
                            if(gun == 1){
                                printf("%s - $150", strGun);
                            }
                            if(rifle == 1){
                                printf("%s - $1000", strRifle);
                            }
                            if(crateOfWeapons == 1){
                                printf("%s - $5000", strCrateOfWeapons);
                            }
                        }
                        if(microphone == 1){
                            printf("| 9| %s - $40\n", strMic);
                        }
                        if(shoes == 1){
                            printf("| 8| %s - $60\n", strShoes);
                        }
                        if(bike == 1){
                            printf("| 7| %s - $150\n", strBike);
                        }
                        if(guitar == 1){
                            printf("| 6| %s - $250\n", strGuitar);
                        }
                        if(computer == 1){
                            printf("| 5| %s - $350\n", strComputer);
                        }
                        if(drum == 1){
                            printf("| 4| %s - $425\n", strDrums);
                        }
                        if(car >= 1){
                            printf("| 3| %s - $", strCar);
                            if(car == 1){
                                printf("500\n");
                            }
                            if(car == 2){
                                printf("10000\n");
                            }
                            if(car == 3){
                                printf("250000\n");
                            }
                        }
                        if(television == 1){
                            printf("| 2| %s - $1250\n", strTV);
                        }
                        if(realEstate >= 1){
                            printf("| 1| %s - $", strRealEstate);
                            //prints cost of real estate, depending on current real estate owned
                            if(realEstate == 1){
                                printf("250\n");
                            }
                            if(realEstate == 2){
                                printf("2500\n");
                            }
                            if(realEstate == 3){
                                printf("35000\n");
                            }
                            if(realEstate == 4){
                                printf("50000\n");
                            }
                            if(realEstate == 5){
                                printf("200000\n");
                            }
                            if(realEstate == 6){
                                printf("1000000\n");
                            }
                            if(realEstate == 7){
                                printf("7500000\n");
                            }
                        }
                        printf("| 0| Back\n\n");
                        printf("Enter number: ");
                        scanf("%d", &userInput3);
                        system("clear");
                        if(userInput3 == 10){
                            printf("\n");
                            printf("| Black Market Items |\n");
                            if(gun == 1){
                                printf("| %s - $150\n", strGun);
                            }
                            if(rifle == 1){
                                printf("| %s - $1000\n", strRifle);
                            }
                            if(crateOfWeapons == 1){
                                printf("| %s - $5000\n", strCrateOfWeapons);
                            }
                            printf("\nEnter number: ");
                            scanf("%d", &userInput4);
                            if(userInput4 == 1 && gun == 1){
                                gun = 0;
                                playerMoney = playerMoney + 150;
                                strcpy(strGun, ""); //erases string of item when item is sold
                                --items; //decreases number of items in inventory by 1
                                item(sold); //displays message confirming player has sold item
                            }
                            if(userInput4 == 2 && rifle == 1){
                                rifle = 0;
                                playerMoney = playerMoney + 1000;
                                strcpy(strRifle, "");
                                --items;
                                item(sold);
                            }
                            if(userInput4 == 3 && crateOfWeapons == 1){
                                crateOfWeapons = 0;
                                playerMoney = playerMoney + 5000;
                                strcpy(strCrateOfWeapons, "");
                                --items;
                                item(sold);
                            }
                        }
                        if(userInput3 == 9 && microphone == 1){
                        microphone = 0;
                        playerMoney = playerMoney + 40;
                        strcpy(strMic, "");
                        --items;
                        item(sold);
                        }
                        if(userInput3 == 8 && shoes == 1){
                            shoes = 1;
                            playerMoney = playerMoney + 60;
                            strcpy(strShoes, "");
                            --items;
                            item(sold);
                        }
                        if(userInput3 == 7 && bike == 1){
                            bike = 0;
                            playerMoney = playerMoney + 150;
                            strcpy(strBike, "");
                            --items;
                            item(sold);
                        }
                        if(userInput3 == 6 && guitar == 1){
                            guitar = 0;
                            playerMoney = playerMoney + 250;
                            strcpy(strGuitar, "");
                            --items;
                            item(sold);
                        }
                        if(userInput3 == 5 && computer == 1){
                            computer = 0;
                            playerMoney = playerMoney + 350;
                            strcpy(strComputer, "");
                            --items;
                            item(sold);
                        }
                        if(userInput3 == 4 && drum == 1){
                            drum = 0;
                            playerMoney = playerMoney + 425;
                            strcpy(strDrums, "");
                            --items;
                            item(sold);
                        }
                        if(userInput3 == 3 && car >= 1){
                            if(car == 3){
                                playerMoney = playerMoney + 250000;
                            }
                            if(car == 2){
                                playerMoney = playerMoney + 10000;
                            }
                            if(car == 1){
                                playerMoney = playerMoney + 500;
                            }
                            car = 0;
                            strcpy(strCar, "");
                            --items;
                            item(sold);
                        }
                        if(userInput3 == 2 && television == 1){
                            television = 0;
                            playerMoney = playerMoney + 1250;
                            strcpy(strTV, "");
                            --items;
                            item(sold);
                        }
                        if(userInput3 == 1 && realEstate >= 1){
                            if(realEstate == 7){
                                playerMoney = playerMoney + 3750000;
                            }
                            if(realEstate == 6){
                                playerMoney = playerMoney + 500000;
                            }
                            if(realEstate == 5){
                                playerMoney = playerMoney + 200000;
                            }
                            if(realEstate == 4){
                                playerMoney = playerMoney + 25000;
                            }
                            if(realEstate == 3){
                                playerMoney = playerMoney + 17500;
                            }
                            if(realEstate == 2){
                                playerMoney = playerMoney + 2500;
                            }
                            if(realEstate == 1){
                                playerMoney = playerMoney + 250;
                            }
                            realEstate = 0;
                            strcpy(strRealEstate, "");
                            --items;
                            item(sold);
                        }
                        if(userInput3 == 0){
                            continue;
                        }
                        if(userInput3 < 0 || userInput3 > 9){
                            printf("Invalid #: Enter a number between 0 and 9");
                            printf("Press enter to continue");
                            clrScr();
                        }
                    }
                    else{
                        printf("You don't have any items to sell\n");
                        printf("Press enter to continue");
                        clrScr();
                    }
                }
                if(userInput2 == 0){ //back to main menu
                    continue;
                }
            }
            else{
                printf("You must purchase a computer before accessing the web!\n");
                printf("Press enter to continue");
                clrScr();
            }
        }
        //Option 4
        if(userInput == 4){ //Real Estate
            printf("Note: \n");
            printf("  Buying a new Real Estate will\n");
            printf("  replace his previous Real Estate\n\n");
            printf("Money: %d\n\n", playerMoney);
            printf("|#| Real Estate     |$$$$$$$$$|\n");
            printf("-------------------------------\n");
            printf("|7| Tent            |     $500|\n");
            printf("|6| Trailer         |    $5000|\n");
            printf("|5| Apartment       |   $70000|\n");
            printf("|4| House           |  $100000|\n");
            printf("|3| Luxury House    |  $400000|\n");
            printf("|2| Mansion         | $2000000|\n");
            printf("|1| Luxury Mansion  |$15000000|\n");
            printf("|0| Back            |         |\n");
            printf("-------------------------------\n\n");
            printf("Enter number: ");
            scanf("%d", &userInput2);
            system("clear");
            if(userInput2 < 0 || userInput2 > 7){
                printf("Invalid: Enter a number between 0 and 7\n");
                printf("Press enter to continue");
                clrScr();
            }
            if(userInput2 == 7){ //buy tent
                if(playerMoney >= 500){
                    if(realEstate == 1){
                        realEstate = 1;
                        ++items;
                        strcpy(strRealEstate, "Tent");
                        playerMoney = playerMoney - 500;
                        calcBills(&currentDebt, &playerMoney, chef,playerFitness);
                        calcDay(&currentDay, &currentYear, &day, &calcYear);
                        calcHSH(&health, &stomach, &happiness, chef, playerFitness);
                    }
                    else{
                        item(own);
                    }
                }
                else{
                    item(none);
                }
            }
            if(userInput2 == 6){ //buy trailer
                if(playerMoney >= 5000){
                    if(realEstate != 2){
                        realEstate = 2;
                        ++items;
                        strcpy(strRealEstate, "Trailer");
                        playerMoney = playerMoney - 5000;
                        calcBills(&currentDebt, &playerMoney, chef, playerFitness);
                        calcDay(&currentDay, &currentYear, &day, &calcYear);
                        calcHSH(&health, &stomach, &happiness, chef, playerFitness);
                    }
                    else{
                        item(own);
                    }
                }
                else{
                    item(none);
                }
            }
            if(userInput2 == 5){ //buy apartment
                if(playerMoney >= 70000){
                    if(realEstate != 3){
                        realEstate = 3;
                        ++items;
                        strcpy(strRealEstate, "Apartment");
                        playerMoney = playerMoney - 70000;
                        calcBills(&currentDebt, &playerMoney, chef, playerFitness);
                        calcDay(&currentDay, &currentYear, &day, &calcYear);
                        calcHSH(&health, &stomach, &happiness, chef, playerFitness);
                    }
                    else{
                        item(own);
                    }
                }
                else{
                    item(none);
                }
            }
            if(userInput2 == 4){ //buy house
                if(playerMoney >= 100000){
                    if(realEstate != 4){
                        realEstate = 4;
                        ++items;
                        strcpy(strRealEstate, "House");
                        playerMoney = playerMoney - 100000;
                        calcBills(&currentDebt, &playerMoney, chef, playerFitness);
                        calcDay(&currentDay, &currentYear, &day, &calcYear);
                        calcHSH(&health, &stomach, &happiness, chef, playerFitness);
                    }
                    else{
                        item(own);
                    }
                }
                else{
                    item(none);
                }
            }
            if(userInput2 == 3){ //buy luxury house
                if(playerMoney >= 400000){
                    if(realEstate != 5){
                        realEstate = 5;
                        ++items;
                        strcpy(strRealEstate, "Luxury House");
                        playerMoney = playerMoney - 400000;
                        calcBills(&currentDebt, &playerMoney, chef, playerFitness);
                        calcDay(&currentDay, &currentYear, &day, &calcYear);
                        calcHSH(&health, &stomach, &happiness, chef, playerFitness);
                    }
                    else{
                        item(own);
                    }
                }
                else{
                    item(none);
                }
            }
            if(userInput2 == 2){ //buy mansion
                if(playerMoney >= 2000000){
                    if(realEstate != 6){
                        realEstate = 6;
                        ++items;
                        strcpy(strRealEstate, "Mansion");
                        playerMoney = playerMoney - 2000000;
                        calcBills(&currentDebt, &playerMoney, chef, playerFitness);
                        calcDay(&currentDay, &currentYear, &day, &calcYear);
                        calcHSH(&health, &stomach, &happiness, chef, playerFitness);
                    }
                    else{
                        item(own);
                    }
                }
                else{
                    item(none);
                }
            }
            if(userInput2 == 1){ //buy luxury mansion
                if(playerMoney >= 15000000){
                    if(realEstate != 7){
                        realEstate = 7;
                        ++items;
                        strcpy(strRealEstate, "Luxury Mansion");
                        playerMoney = playerMoney - 15000000;
                        calcBills(&currentDebt, &playerMoney, chef, playerFitness);
                        calcDay(&currentDay, &currentYear, &day, &calcYear);
                        calcHSH(&health, &stomach, &happiness, chef, playerFitness);
                    }
                    else{
                        item(own);
                    }
                }
                else{
                    item(none);
                }
            }
            if(userInput2 == 0){
                continue;
            }
        }
        //Option 3
        if(userInput == 3){ //Miscellaneous Activities
            printf("\n");
            printf("|#| Miscellaneous Activities\n");
            printf("-----------------------------\n");
            printf("|4| Beg for Money\n");
            printf("|3| Rob stranger\n");
            printf("|2| Rob house\n");
            printf("|1| Rob bank\n");
            printf("|0| Back\n");
            printf("-----------------------------\n\n");
            printf("Enter number: ");
            scanf("%d", &userInput2);
            system("clear");
            //when robbing, player has a chance of getting caught, causing player to go to jail for certain amount of years
            if(userInput2 == 4){ //Beg for Money
                playerMoney = playerMoney + 40;
                calcBills(&currentDebt, &playerMoney, chef, playerFitness);
                calcDay(&currentDay, &currentYear, &day, &calcYear);
                calcHSH(&health, &stomach, &happiness, chef, playerFitness);
            }
            if(userInput2 == 3){ //Rob stranger
                if(gun == 1){
                    srand(time(NULL));
                    randNum = rand() % 1000 + 1;
                    if(randNum == 1){
                        currentDebt = currentDebt + 2000;
                        printf("You have been caught!\n");
                        printf("$2000 added to current debt");
                        printf("Jail time for robbing stranger: 1 year\n");
                        for(i = 0; i >= 365; ++i){ //for loop that calculates the amount bills and days for number of days player goes to jail for
                            calcBills(&currentDebt, &playerMoney, chef, playerFitness);
                            calcDay(&currentDay, &currentYear, &day, &calcYear);
                        }
                        printf("Press enter to continue");
                        clrScr();
                    }
                    else{
                        playerMoney = playerMoney + 70;
                        calcBills(&currentDebt, &playerMoney, chef, playerFitness);
                        calcDay(&currentDay, &currentYear, &day, &calcYear);
                        calcHSH(&health, &stomach, &happiness, chef, playerFitness);
                        printf("You successfully robbed the stranger\n");
                        printf("Press enter to continue");
                        clrScr();
                    }
                }
                else{
                    printf("You need a gun to do this activity\n");
                    printf("Press enter to continue");
                    clrScr();
                }
            }
            if(userInput2 == 2){ //Rob house
                if(rifle == 1){
                    srand(time(NULL));
                    randNum = rand() % 100 + 1;
                    if(randNum == 1){
                        ++day;
                        currentDebt = currentDebt + 10000;
                        printf("You have been caught!\n");
                        printf("$10000 added to current debt");
                        printf("Jail time for robbing a house: 5 years\n");
                        for(i = 0; i >= 1825; ++i){
                            calcBills(&currentDebt, &playerMoney, chef, playerFitness);
                            calcDay(&currentDay, &currentYear, &day, &calcYear);
                        }
                        printf("Press enter to continue");
                        clrScr();
                    }
                    else{
                        playerMoney = playerMoney + 500;
                        calcBills(&currentDebt, &playerMoney, chef, playerFitness);
                        calcDay(&currentDay, &currentYear, &day, &calcYear);
                        calcHSH(&health, &stomach, &happiness, chef, playerFitness);
                        printf("You successfully robbed a house\n");
                        printf("Press enter to continue");
                        clrScr();
                    }
                }
                else{
                    printf("You need a rifle to do this activity\n");
                    printf("Press enter to continue");
                    clrScr();
                }
            }
            if(userInput2 == 1){ //Rob bank
                if(crateOfWeapons == 1){
                    srand(time(NULL));
                    randNum = rand() % 20 + 1;
                    if(randNum == 1){
                        currentDebt = currentDebt + 25000;
                        printf("You have been caught!\n");
                        printf("$25000 added to current debt");
                        printf("Jail time for robbing a bank: 20 years\n");
                        for(i = 0; i >= 7300; ++i){
                            calcBills(&currentDebt, &playerMoney, chef, playerFitness);
                            calcDay(&currentDay, &currentYear, &day, &calcYear);
                        }
                        printf("Press enter to continue");
                        clrScr();
                    }
                        else{
                        playerMoney = playerMoney + 6000;
                        calcBills(&currentDebt, &playerMoney, chef, playerFitness);
                        calcDay(&currentDay, &currentYear, &day, &calcYear);
                        calcHSH(&health, &stomach, &happiness, chef, playerFitness);
                        printf("You successfully robbed a bank\n");
                        printf("Press enter to continue");
                        clrScr();
                    }
                }
                    else{
                    printf("You need a crate of weapons to do this activity\n");
                    printf("Press enter to continue");
                    clrScr();
                    }
                }
                if(userInput2 == 0){ //Help
                continue;
            }
        }
        //Option 2
        if(userInput == 2){ //Government/Hospital
            printf("\n");
            printf("|#| Government / Hospital                   |              |\n");
            printf("------------------------------------------------------------\n");
            printf("|2| Apply for Government Security Clearance |       $100000|\n");
            printf("|1| Regenerate Health                       |$25 Per Health|\n");
            printf("|0| Back                                    |              |\n");
            printf("------------------------------------------------------------\n\n");
            printf("Enter number: ");
            scanf("%d", &userInput2);
            system("clear");
            if(userInput2 == 2){ //Gov't Security Clearance
                if(popularity >= 200000){
                    govClear = 1;
                    printf("You now have Government Security Clearance\n");
                    printf("Press enter to continue");
                    clrScr();
                }
                else{
                    printf("You don't have enough popularity\n");
                    printf("Press enter to continue");
                    clrScr();
                }
            }
            if(userInput2 == 1){ //Regenerates Player Health
                if(playerMoney >= ((100 - health) * 25)){
                    playerMoney = playerMoney - ((100 - health) * 25);
                    health = 100;
                    stomach = 100;
                    happiness = 100;
                    calcBills(&currentDebt, &playerMoney, chef, playerFitness);
                    calcDay(&currentDay, &currentYear, &day, &calcYear);
                    calcHSH(&health, &stomach, &happiness, chef, playerFitness);
                    printf("Your health has now been regenerated\n");
                    printf("Press enter to continue");
                    clrScr();
                }
                else{
                    item(none);
                }
            }
            if(userInput2 == 0){ //back to main menu
                continue;
            }
        }
        //Option 1
        if(userInput == 1){ //Education
            printf("\n");
            printf("|#| Education          |$$$$$$|\n");
            printf("-------------------------------\n");
            printf("|4| Doctor's Degree    |$25000|\n");
            printf("|3| Master's Degree    |$20000|\n");
            printf("|2| Bachelor's Degree  |$40000|\n");
            printf("|1| Associate's Degree |$10000|\n");
            printf("|0| Back               |      |\n");
            printf("-------------------------------\n\n");
            printf("Enter number: ");
            scanf("%d", &userInput2);
            system("clear");
            //purchasing degree will allow the player to do certain jobs that require a certain degree
            if(userInput2 == 4){ //Doctor's degree
                if(degMaster == 1){
                    if(playerMoney >= 25000){
                        if(degDoctor == 0){
                            degDoctor = 1;
                            playerMoney = playerMoney - 25000;
                            for(i = 1; i <= 730; ++i){ //calculates bills and days for however long it takes to achieve this degree
                                health = 100;
                                stomach = 100;
                                happiness = 100;
                                calcBills(&currentDebt, &playerMoney, chef, playerFitness);
                                calcDay(&currentDay, &currentYear, &day, &calcYear);
                            }
                            printf("You now have a doctor's degree!\n");
                            printf("Press enter to continue");
                            clrScr();
                        }
                        else{
                            item(own);
                        }
                    }
                    else{
                        item(none);
                    }
                }
                else{
                    printf("You must own a master's degree before you can get this!\n");
                    printf("Press enter to continue");
                    clrScr();
                }
            }
            if(userInput2 == 3){ //Master's degree
                if(degBachelor == 1){
                    if(playerMoney >= 20000){
                        if(degMaster == 0){
                            degMaster = 1;
                            playerMoney = playerMoney - 20000;
                            for(i = 1; i <= 730; ++i){
                                health = 100;
                                stomach = 100;
                                happiness = 100;
                                calcBills(&currentDebt, &playerMoney, chef, playerFitness);
                                calcDay(&currentDay, &currentYear, &day, &calcYear);
                            }
                            printf("You now have a master's degree!\n");
                            printf("Press enter to continue");
                            clrScr();
                        }
                        else{
                            item(own);
                        }
                    }
                    else{
                        item(none);
                    }
                }
                else{
                    printf("You must own a bachelor's degree before you can get this!\n");
                    printf("Press enter to continue");
                    clrScr();
                }
            }
            if(userInput2 == 2){ //Bachelor's degree
                if(playerMoney >= 40000){
                    if(degBachelor == 0){
                        degBachelor = 1;
                        playerMoney = playerMoney - 40000;
                        for(i = 1; i <= 1460; ++i){
                            health = 100;
                            stomach = 100;
                            happiness = 100;
                            calcBills(&currentDebt, &playerMoney, chef, playerFitness);
                            calcDay(&currentDay, &currentYear, &day, &calcYear);
                        }
                        printf("You now have a bachelor's degree!\n");
                        printf("Press enter to continue");
                        clrScr();
                    }
                    else{
                        item(own);
                    }
                }
                else{
                    item(none);
                }
            }
            if(userInput2 == 1){ //Associate's degree
                if(playerMoney >= 10000){
                    if(degAssociate == 0){
                        degAssociate = 1;
                        playerMoney = playerMoney - 10000;
                        for(i = 1; i <= 730; ++i){
                            health = 100;
                            stomach = 100;
                            happiness = 100;
                            calcBills(&currentDebt, &playerMoney, chef, playerFitness);
                            calcDay(&currentDay, &currentYear, &day, &calcYear);
                            calcHSH(&health, &stomach, &happiness, chef, playerFitness);
                        }
                        printf("You now have an associate's degree!\n");
                        printf("Press enter to continue");
                        clrScr();
                    }
                    else{
                        item(own);
                    }
                }
                else{
                    item(none);
                }
            }
            if(userInput2 == 0){ //back to menu
                continue;
            }
        }
        //Option 0
        if(userInput == 0){ //Quit
            health = 0;
            // printf("Are you sure you would like to quit?\n");
            // printf("(Note: Quitting will automatically kill your player!)\n");
            // printf("    Yes (1)            No(0)\n\n");
            // scanf("%d", &userInput2);
            // if(userInput2 == 1){
            //     health = 0;
            //     system("clear");
            // }
            // else if(userInput2 == 0){
            //     system("clear");
            // }
            // else{
            //     system("clear");
            // }
        }
        if(mileageSedan >= 300000 || mileageCheapCar >= 300000 || mileageSuperCar >= 300000){ //car will stop running at 300000 miles
            if(mileageCheapCar >= 300000){
                car = 0;
                mileageCheapCar = 0;
            }
            if(mileageSedan >= 300000){
                car = 0;
                mileageSedan = 0;
            }
            if(mileageSedan >= 300000){
                car = 0;
                mileageSuperCar = 0;
            }
            printf("Your car has broken down and can no longer be fixed\n");
            printf(":( \n");
            printf("Press enter to continue");
            clrScr();
        }
        if(playerAge >= 118){ //will automatically kill the player at age 118
            health = 0;
        }
        for(i = 0; i < calcYear; ++i){ //increases the player age by 1 after 365 days
            playerAge = playerAge + 1;
            calcYear = calcYear - 1;
            maxLoan = maxLoan + 2000;  //the max loan increases every year
        }
        if(playerMoney > 2100000000){ //to prevent user money going int max value
            playerMoney = 2100000000;
        }
    }
    playerMoney = playerMoney - currentDebt; //calculates money player has upon death
    printf("You DIED\n");
    printf("Game Over!\n");
    printf("You died at %d years old\n", playerAge);
    printf("You lived for %d days\n", day);
    printf("Your bank account was $%d\n\n", playerMoney);
    return 0;
}

void clrScr(){  //function that clears screen when called
    fflush(stdin);
    getchar();
    system("clear");
}

void item(int userItem){  //function that prints message when purchasing item
    if(userItem == 3){
        printf("You have sold this item!");
        printf("Press enter to continue");
        fflush(stdin);
        getchar();
        system("clear");
    }
    if(userItem == 2){     //prints when user has successfully purchased item
        printf("You have purchased this item!\n");
        printf("Press enter to continue");
        fflush(stdin);
        getchar();
        system("clear");
    }
    if(userItem == 1){     //prints when user already owns item
        printf("You already own this item!\n");
        printf("Press enter to continue");
        fflush(stdin);
        getchar();
        system("clear");
    }
    if(userItem == 0){     //prints when user does not have enough money to purchase item
        printf("You don't have enough money for this!\n");
        printf("Press enter to continue");
        fflush(stdin);
        getchar();
        system("clear");
    }
    return;
}

void calcHSH(int* totHealth, int* hunger, int* mentality, int dailyFood, int fitness){ //Function that calculates health, hunger, and happiness after a day
    *totHealth =  *totHealth - 1;  //health decreases by 1 daily
    *hunger = *hunger - 10;        //hunger decreases by 10 daily
    *mentality = *mentality - 5;   //mentality decreased by 5 daily
    if(*mentality < 1){            //health will diminish if mental health is less than 1
        *totHealth = *totHealth - (*totHealth / 5);
        *mentality = 0;      //keeps mentality from going negative
    }
    if(*hunger < 1){         //health will decrease when hunger is less than 1
        *totHealth = *totHealth - (*totHealth / 2);
        *hunger = 0;         //keeps hunger from going negative
    }
    if(dailyFood == 1){      //gives players +80 hunger if player owns a chef
        *hunger = *hunger + 80;
    }
    if(*mentality > 100){  //ensures mentality does not go above 100
        *mentality = 100;
    }
    if(*hunger > 100){    //ensures hunger does not go above 100
        *hunger = 100;
    }
    if(fitness == 1){   //gives player +5 health if they own a gym membership
        *totHealth = *totHealth + 5;
    }
    if(fitness == 2){   //gives player +70 health if they have personal trainer
        *totHealth = *totHealth + 70;
    }
    if(*totHealth > 100){ //ensures health does not go above 100
        *totHealth = 100;
    }
    return;
}

void calcBills(int* interest, int* money, int food, int fit){  //Function that calculates amount of money player has after a day
    *interest = *interest + (*interest * 0.0001);
    *money = *money - (food * 500);
    if(fit == 1){
        *money = *money - 20;
    }
    if(fit == 2){
        *money = *money - 500;
    }
    return;
}

void calcDay(int* timeDay, int* timeYear, int* numOfDays, int* year){ //Function that counts current day, current year, and number of days in simulation
    *numOfDays = *numOfDays + 1;
    *timeDay = *timeDay + 1;
    if(*timeDay % 365 == 0){ //year will increase by 1 if the current day is 365
        ++*timeYear;
        ++*year;
        *timeDay = *timeDay - 365; //current day will recount back to 0
    }
    return;
}
    
                
    
