#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>


// Functions To Create 
// introductionn 
// menu
// age calculator - 1
// discount calculator -2
// is prime number - 3
// is even or odd - 4
// total grade calculaator - 5
// rock paper scissors game - 6
// area calculator - 7
// Famous Quotes -8
// Total price calculator - 9
// swap numbers - 10
// get a random number -11
// Calculator - 12
// Decimal To Binary - 13
// Decimal To Octal - 14
// Decimal To Hex - 15
// Guess a number -  16
// Eqution Calculator -17
// distance between two points - 18
// password generoator - 19
// current time - 20

void calculate_age();
void age_calculator();
void calculate_discount();
void is_prime();
void even_or_odd();
void grade_calculate();
int get_random();
void play_rock_paper_scissors();
int game_logic();
void area_calculate();
void show_quotes();
void total_price_calculate();
void swap_numbers();
void menu();
void calculator();
void introduction();
int convert();
void decimal_to_bin();
void decimal_to_oct();
void decimal_to_hex();
void guess_a_number();
void quadratic_formula();
void distance();
void passsword_genarator();
void show_ascii_number();


//get a random number
int get_random(int min,int max){
    srand(time(NULL));
    int n = rand() % (max - min + 1) + min;
    return n;
}



void introduction(){
    printf("Name: Shafayet Hossain Shifat\n");
    printf("ID: CSE2201025060\n");
    printf("Section: 25A1\n");
    printf("Number: 01724792124");
    printf("===========================================\n");
}

void menu(){
    printf("\n===========================================\n");
    printf("Select An Option:\n");
    printf("1.  Age Calculator\n");
    printf("2.  Discount Calculator\n");
    printf("3.  Check A Number is Prime or Not\n");
    printf("4.  Check A Number is Even or Odd\n");
    printf("5.  Calculate Total GPA\n");
    printf("6.  Rock Paper Scissors Game\n");
    printf("7.  Calculate Area Of a Circle\n");
    printf("8.  Show a Famous Quote\n");
    printf("9.  Total Price Calculator\n");
    printf("10. Swap Two Numbers\n");
    printf("11. Get A Random Number Between Two Numbers\n");
    printf("12. Calculator\n");
    printf("13. Decimal To Binary Converter\n");
    printf("14. Decimal To Octal Converter\n");
    printf("15. Decimal To Hex Converter\n");
    printf("16. Play 'Guess A Number'\n");
    printf("17. Calculate x if equation look like this ' ax^2 + bx + c = 0' \n");
    printf("18. Distance between two points\n");
    printf("19. Password Generator\n");
    printf("20. Show Characters ASCII Number\n");

    printf("0.  Exit\n");
    printf("===========================================\n");

}

int main()
{   

    
    introduction();
    menu();
    while (1){

    
    int n,a,b,min,max;
    printf("\nEnter Your Choice:");
    scanf("%d",&n);

    switch(n){
        case 0:
            exit(0);
        case 1:
            calculate_age();
            break;
        case 2:
            calculate_discount();
            break;
        case 3:
            is_prime();
            break;
        case 4:
            even_or_odd();
            break;
        case 5:
            grade_calculate();
            break;
        case 6:
            play_rock_paper_scissors();
            break;
        case 7:
            area_calculate();
            break;
        case 8:
            show_quotes();
            break;
        case 9:
            total_price_calculate();
            break;
        case 10:
            printf("Enter Two Number:");
            scanf("%d %d",&a,&b);
            swap_numbers(a,b);
            break;
        case 11:
            printf("Enter min max(ex. 1 10):");
            scanf("%d %d",&min,&max);
            printf("A Random Number Between %d-%d:%d\n",min,max,get_random(min,max));
            break;
        case 12:
            calculator();
            break;
        case 13:
            decimal_to_bin();
            break;
        case 14:
            decimal_to_oct();
            break;
        case 15:
            decimal_to_hex();
            break;
        case 16:
            guess_a_number();
            break;
        case 17:
            quadratic_formula();
            break;
        case 18:
            distance();
            break;
        case 19:
            passsword_genarator();
            break;
        case 20:
            show_ascii_number();
            break;
        default:
            printf("Invalid Choice.\n");
        }

    }

    return 0;
}


void show_ascii_number(){
    char c;
    printf("Enter A Character:");
    scanf(" %c",&c);
    printf("ASCII Number: %d",c);
}

void passsword_genarator(){
    int len;
    printf("Password Length:");
    scanf("%d",&len);
    printf("Password:\t");
    for (int i = 0; i < len; ++i)
    {   
        printf("%c",get_random(i,128));
    }
    printf("\n");

}


// distance between two points
void distance(){
    int x1,y1,x2,y2;
    printf("Enter Point1(ex. 5 10) :");
    scanf("%d %d",&x1,&y1);
    printf("Enter Point2(ex. 4 -1) :");
    scanf("%d %d",&x2,&y2);

    int eq = pow( ( pow((x2-x1),2) + pow((y2-y1),2) ), 0.5 );
    int m = abs(x1-x2) + abs(y1-y2);
    printf("Euclidean Distance : %d\n",eq);
    printf("Manhattan Distance : %d\n",m);
}

void quadratic_formula(){
    int a,b,c;

    printf("Enter a,b,c(ex 3 5 10):");
    scanf("%d %d %d",&a,&b,&c);

    int discriminant = (b*b - 4*a*c);
    int x1,x2;

    if (discriminant<0){
        printf("'%dx^2 +  %dx + %d = 0 'has no real number solutions\n",a,b,c);
    }
    else{
        x1 = ( -b + pow(pow(b,2) - 4*a*c,0.5) ) / (2*a);
        x2 = ( -b - pow(pow(b,2) - 4*a*c,0.5) ) / (2*a);
 

        printf("x=%d or x=%d\n",x1,x2);
    }

}

// game guess a number
void guess_a_number(){
    int min = get_random(1,100);
    int max = get_random(min+10,100+10);
    int number = get_random(min,max);
    int guess;

    int try = 5;
    int is_guessed = 0;
    printf("Guess Number Between %d-%d\n",min,max);
    for (int i = 1; i <= try; ++i)
    {
        printf("Try Left: %d\n",try-i+1);
        printf("Enter Yor Guess:");
        scanf("%d",&guess);

        if (number==guess)
        {
            printf("You Guessed Correctly\n");
            is_guessed = 1;
            break;
        }
        else if(number>guess){
            printf("Number is larger\n");
        }
        else if(number<guess){
            printf("Number is smaller\n");
        }

    }

    if (is_guessed==0)
    {
        printf("Your Try Ended.\nThe Number Was %d",number);
    }

}


// number conberter
int convert(int number,int base){
    long long bin = 0;
    int j,rem, i = 1;

    for(j=number;j!=0;j)
    {
        rem = j % base;
        j /= base;
        bin += rem * i;
        i *= 10;
    }
    return bin;
}




void decimal_to_bin(){
    int a;
    printf("Enter A Number:");
    scanf("%d",&a);
    printf("%d is %d in Binary\n",a,convert(a,2));
}

void decimal_to_oct(){
    int a;
    printf("Enter A Number:");
    scanf("%d",&a);
    printf("%d is %d in Octal\n",a,convert(a,8));
}

void decimal_to_hex(){
    int a;
    printf("Enter A Number:");
    scanf("%d",&a);
    printf("%d is %X in Hex\n",a,a);
}


// caculator
void calculator(){
    int a,b;
    int o;
    printf("Enter Two Number(ex. 45 10):");
    scanf("%d %d",&a,&b);
    printf("Enter Oparation '+'=1 '-'=2, '*'=3 '/'=4 (ex. 4):");
    scanf("%d",&o);

    if(o==1){
        printf("%d + %d = %d\n",a,b,a+b);
    }
    else if(o==2){
        printf("%d - %d = %d\n",a,b,a-b);
    }
    else if(o==3){
        printf("%d * %d = %d\n",a,b,a*b);
    }
    else if(o==4){
        printf("%d - %d = %d\n",a,b,a/b);
    }

}


//item price calculator
void total_price_calculate(){
    int items_price = 0;
    int items;

    printf("How may items do you have?\n");
    scanf("%d",&items);

    for (int i = 1; i <= items; i++)
    {   
        int n;
        printf("Enter Item %d price:\n",i);
        scanf("%d",&n);
        items_price = items_price + n;
    }

    printf("Total Price :%d BDT",items_price);

}


//swap numbers
void swap_numbers(int a,int b){

    printf("Before Swaping: X= %d Y= %d\n",a,b);
    int temp;
    temp = a;
    a = b;
    b = temp;
    printf("After Swaping: X= %d Y= %d\n",a,b);

}


//get qoutes
void show_quotes(){
    int n = get_random(1,14);
    printf("\n");
    switch(n){
        case 1:
            printf("Spread love everywhere you go. Let no one ever come to you without leaving happier. -Mother Teresa \n");
            break;
        case 2:
            printf("When you reach the end of your rope, tie a knot in it and hang on. -Franklin D. Roosevelt \n");
            break;
        case 3:
            printf("Always remember that you are absolutely unique. Just like everyone else. -Margaret Mead \n");
            break;
        case 4:
            printf("Always remember that you are absolutely unique. Just like everyone else. -Margaret Mead \n");
            break;
        case 5:
            printf("Always remember that you are absolutely unique. Just like everyone else. -Margaret Mead \n");
            break;
        case 6:
            printf("Tell me and I forget. Teach me and I remember. Involve me and I learn. -Benjamin Franklin \n");
            break;
        case 7:
            printf("The best and most beautiful things in the world cannot be seen or even touched — they must be felt with the heart. -Helen Keller \n");
            break;
        case 8:
            printf("It is during our darkest moments that we must focus to see the light. -Aristotle \n");
            break;
        case 9:
            printf("Whoever is happy will make others happy too. -Anne Frank \n");
            break;
        case 10:
            printf("Do not go where the path may lead, go instead where there is no path and leave a trail. -Ralph Waldo Emerson \n");
            break;
        case 11:
            printf("Your time is limited, so don't waste it living someone else's life. Don't be trapped by dogma – which is living with the results of other people's thinking. -Steve Jobs \n");
            break;
        case 12:
            printf("The way to get started is to quit talking and begin doing. -Walt Disney\n");
            break;
        case 13:
            printf("The greatest glory in living lies not in never falling, but in rising every time we fall. -Nelson Mandela \n");
            break;
        case 14:
            printf("If you set your goals ridiculously high and it's a failure, you will fail above everyone else's success. -James Cameron \n");
            break;
    }

    printf("\n");

}


//area calculator
void area_calculate(){
    float r;
    printf("Enter Radius:\n");
    scanf("%f",&r);
    printf("Area Is: %.4f\n",3.1416*(r*r));
}


// rock paper scissors game logic
void play_rock_paper_scissors(){
    int count,val;
    printf("How may times you want to play?(ex. 5):\n");
    scanf("%d",&count);
    
    int user_score = 0;
    int computer_score = 0;

    for (int i = 1; i <= count;i++)
    {
        val = game_logic();
        if (val==1){
            user_score++;
        }
        else if(val==0){
            computer_score++;
        }

    }

    printf("\nFinal:\n");
    printf("Your Score:%d\t\tComputer Score:%d\n",user_score,computer_score);
    if (user_score>computer_score){
        printf("\n\n\t\tYou Win!!! Congratulation.\n");
    }
    else if(user_score<computer_score){
        printf("\n\n\t\tYou lose!!! Luck is not your side, Why not Try Again?\n");
    }
    else{
        printf("\n\n\t\tTie!!!\n");
    }

}


int game_logic(){
    printf("\n\nEnter Your Choice ('1' for rock; '2' for paper; '3' for scissors)\n");
    int choice;
    scanf("%d",&choice);
    int user_choice = choice;
    // if (choice == 'r'){
    //     user_choice = 1;
    // }
    // else if(choice == 'p'){
    //     user_choice = 2;
    // }
    // else if(choice == 's'){
    //     user_choice = 3;
    // }
    // else{
    //     user_choice = 0;
    // }

    int computer_choice= get_random(1,3);

    int iswin;

    if (user_choice==1 && computer_choice == 1){
        printf("\n\nYou Choice 'Rock'\t\t Computer Choice 'Rock'\n\n\t\t\t!!!Tie!!!\n");
        iswin = -1;
    }
    else if (user_choice==1 && computer_choice == 2){
        printf("\n\nYou Choice 'Rock'\t\t Computer Choice 'Paper'\n\n\t\t\t!!!Lose!!!\n");
        iswin = 0;
    }
    else if (user_choice==1 && computer_choice == 3){
        printf("\n\nYou Choice 'Rock'\t\t Computer Choice 'Scissors'\n\n\t\t\t!!!Win!!!\n");
        iswin = 1;
    }
    else if (user_choice==2 && computer_choice == 1){
        printf("\n\nYou Choice 'Paper'\t\t Computer Choice 'Rock'\n\n\t\t\t!!!Win!!!\n");
        iswin = 1;
    }
    else if (user_choice==2 && computer_choice == 2){
        printf("\n\nYou Choice 'Paper'\t\t Computer Choice 'Paper'\n\n\t\t\t!!!Tie!!!\n");
        iswin = -1;
    }
    else if (user_choice==2 && computer_choice == 3){
        printf("\n\nYou Choice 'Paper'\t\t Computer Choice 'Scissors'\n\n\t\t\t!!!Lose!!!\n");
        iswin = 0;
    }

     else if (user_choice==3 && computer_choice == 1){
        printf("\n\nYou Choice 'Scissors'\t\t Computer Choice 'Rock'\n\n\t\t\t!!!Lose!!!\n");
        iswin = 0;
    }
    else if (user_choice==3 && computer_choice == 2){
        printf("\n\nYou Choice 'Scissors'\t\t Computer Choice 'Paper'\n\n\t\t\t!!!Win!!!\n");
        iswin = 1;
    }
    else if (user_choice==3 && computer_choice == 3){
        printf("\n\nYou Choice 'Scissors'\t\t Computer Choice 'Scissors'\n\n\t\t\t!!!Tie!!!\n");
        iswin = 0;
    }
    else{
        printf("\n\nInvalid Choice %d %d\n\n",user_choice,computer_choice);
        main();
    }

    return iswin;

}


//calculate grade
void grade_calculate(){
    int subs,number;

    float a_plus = 5.0;
    float a = 4.0;
    float a_minus=3.5;
    float b=3.0;
    float c=2.0;
    float d=1.0;
    float f=0.0;

    float total_grade = 0;


    printf("How many Subjects do you want to calculate (ex. 8)\n");
    scanf("%d",&subs);

    for (int i=1; i<=subs; i++){
        printf("%d subject number:",i);
        scanf("%d",&number);

        if (number>=80 && number<=100){
            printf("You've got A+ in Subject %d\n",i);
            total_grade = total_grade+a_plus;
        }
        else if(number>=70 && number<=79){
           printf("You've got A in Subject %d\n",i);
            total_grade = total_grade+a ;
        }
        else if(number>=60 && number<=69){
           printf("You've got A- in Subject %d\n",i);
            total_grade = total_grade+a_minus;
        }
        else if(number>=50 && number<=59){
           printf("You've got B in Subject %d\n",i);
            total_grade = total_grade+b;
        }
        else if(number>=40 && number<=49){
           printf("You've got C in Subject %d\n",i);
            total_grade = total_grade+c;
        }
        else if(number>=33 && number<=39){
           printf("You've got D in Subject %d\n",i);
            total_grade = total_grade+d;
        }
        else if(number>=0 && number<=32){
           printf("You've failed in Subject %d\n",i);
            total_grade = total_grade+f;
        }
        else {
           printf("Invalid number in Subject %d\n",i);
            total_grade = total_grade ;
        }
    }

    total_grade = total_grade / subs;

    printf("Total Grade: %.2f\n",total_grade);

}



//even or odd check
void even_or_odd(){
    int n;
    printf("Enter a Number(ex. 3):\n");
    scanf("%d",&n);

    int remainder = n%2;

    if (remainder==1){
        printf("%d is an odd number.",n);
    }
    else {
        printf("%d is an even number.",n);
    }

}


//prime number checker function
void is_prime(){
    int n,count=0;
    printf("Enter a Number(ex. 3456):\n");
    scanf("%d",&n);

    for (int i=1; i<=n; i++){
        if(n%i==0){
            count++;
        }
    }
    if(count == 2){
            printf("%d is a prime number.\n",n);
        }
        
    else{
         printf("%d is not a prime number\n",n);
    }

}

//discount calculator
void calculate_discount(){
    int price,discount;

    printf("Enter Price (ex. 1200):\n");
    scanf("%d",&price);

    printf("Enter Discount (ex. 15):\n");
    scanf("%d",&discount);

    int total_discount = ((price*discount)/100);
    int final_price = price - total_discount;

    printf("You will get %d BDT discount and final price will be %d BDT.\n",total_discount,final_price);
}



//Calcuclate  Age Logic
void calculate_age(){
    int year,month,date;
    int c_year,c_month,c_date;
    printf("Enter Your Age(Year Month Day) ex. 2001 11 8\n");
    scanf("%d %d %d",&year,&month,&date);

    printf("Enter Current Date(Year Month Day) ex. 2022 3 30\n");
    scanf("%d %d %d",&c_year,&c_month,&c_date);

    age_calculator(year,month,date,c_year,c_month,c_date);
    
}

void age_calculator(int brith_year,int brith_month,int brith_date,int current_year,int current_month,int current_date){
    
    int age_year,age_month,age_date;

    age_year = current_year - brith_year;
    age_month = current_month - brith_month;
    age_date = current_date - brith_date;

    int month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (age_month<0){
        age_year = age_year - 1;
        age_month = 12 + age_month;
    }
    if (age_date<0){
        age_month = age_month - 1;
        age_date = month[brith_month] + age_date;
    }

    printf("Age: \n%d year(s) %d month(s) %d day(s) old.\n",age_year,age_month,age_date);

}