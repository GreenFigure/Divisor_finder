// 2-as praktinis darbas. Variantas nr. 9
// Darba atliko Norbert Zardin 1311008 VU MIF INFO 2 grupe
// 2013/2014 m. antrasis (pavasario) semestras

// This program counts the divisors of all the numbers you enter, finds the number with the most divisors and prints it.
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>  // getch();
#include <string.h> // strcmp();
#define size 40000  // use this to change the max value allowed to enter
#define size1 500
#define PICK_SIZE 6
int GetChoice ();
void Get_Size(int* total_numbers, int max);
void Create_arrays(int* *numbers, int* *div_num, int total_numbers);
void Get_Numbers(int* numbers, int total_numbers, int max_fixed_size);
void Count_divisors(int* numbers, int* div_num, int total_numbers);
void Find_Maxindexsize(int total_numbers, int* max_size, int* max_index, int* div_num, int* numbers);
void print(int* numbers, int* div_num, int total_numbers);
void Print_result(int* numbers, int* div_num, int max_index);

int main(int argc, const char* argv[]) {
    int *numbers;                // number array
    int *div_num;                // divisor count array
	int total_numbers,           // total numbers entered
        max, max_fixed_size,     // max - max size for an array, max_fixed_size - max size of an integer
        max_size=0,              // biggest integer in array div_num
        max_index=0,             // array index for the max_size
        choice,                  // used to identify our selection
        done=0,                  // we use this to identify if we have done some of the previouse steps
        delarr=0;                // delarr - delete array, used to know if we need to delete arrays

/*----------------------- Parameter part ---------------------------*/
if (argc==1) {   //dodge <null> compare to string fault
        argv[1]="";
        }

if (strcmp("-h",argv[1])==0){
            printf("\n>Enter the the max size of numbers you are going to enter and the \nmax value of a number. \n\nEtc: main.exe 50 1500\n\n");
    } else {
        if ((argc >= 2)&&(atoi(argv[1])>0)){   ///max total_numbers value
             max = atoi(argv[1]);
       } else {
             max=size1;
        }


        if ((argc >= 3)&&(atoi(argv[2])>2)){ /// max value of a number
            max_fixed_size = atoi(argv[2]);
        } else {
            max_fixed_size = size;
        }

/*------------------------- End of params -----------------*/
        printf("> In this simple divisor finding program you are allowed to enter numbers only.\n");
        printf("> With current settings you can enter up to %d numbers.\n",max);
        printf("> The numbers are required to be [1..%d].\n",max_fixed_size);
        printf("> In order to successfully complete the calculations you need to enter data!\n\n");
        printf("Press Any Key to Continue\n");
        getch();
        system("cls");


        do {
	choice = GetChoice();
	switch (choice) {
		case 1 : { //Enter the amount of numbers
		    system("cls");
		    Get_Size(&total_numbers, max);
		    Create_arrays(&numbers, &div_num, total_numbers);
		    done=1;
			break;
		}
		case 2 :{ //Enter numbers
		    if(done>=1){
                system("cls");
                Get_Numbers(numbers, total_numbers, max_fixed_size);
                done=2;
		    } else {
                printf("> You have to enter the amount of numbers first!\n\n");
                printf("> Press Any Key to enter the Data\n");
                getch();
                system("cls");
                Get_Size(&total_numbers, max);

                Create_arrays(&numbers, &div_num, total_numbers);

                Get_Numbers(numbers, total_numbers, max_fixed_size);
                done=2;
                delarr=1;
		    }
			break;
		}
		case 3 : { // print numbers
		    if(done >= 2){
                system("cls");
                print(numbers, div_num, total_numbers);
		    } else {
                printf("> You have to enter data first!\n\n");
		    }
                printf("> Press Any Key to Continue\n");
                getch();
                system("cls");
			break;
		}
		case 4 : { // start calculation
		     if(done >= 2){

                Count_divisors(numbers, div_num, total_numbers);

                Find_Maxindexsize(total_numbers, &max_size, &max_index, div_num, numbers);

                system("cls");
                printf("> Calculations are done!\n");
                done=4;

		     } else {

                printf("> You have to enter data first!\n\n");
		     }

                printf("> Press Any Key to Continue\n");
                getch();
                system("cls");
			break;
		}
		case 5 : { // Print result
		    if(done >= 4){
              system("cls");
              print(numbers, div_num, total_numbers);//prints numbers
              Print_result(numbers, div_num, max_index);//prints results

		    } else {
		    printf("> You have to enter the data first and calculate it!\n\n");
		    }
		    printf("> Press Any Key to Continue\n");
		    getch();
		    system("cls");
		    break;
		}
		case 6 : { // run full program
		    Get_Size(&total_numbers, max);

            Create_arrays(&numbers, &div_num, total_numbers);

            Get_Numbers(numbers, total_numbers, max_fixed_size);

            Count_divisors(numbers, div_num, total_numbers);

            Find_Maxindexsize(total_numbers, &max_size, &max_index, div_num, numbers);

            print(numbers, div_num, total_numbers);

            Print_result(numbers, div_num, max_index);


            printf("> Press Any Key to continue.\n");
            getch();
            system("cls");

			break;
		}
		case 0 : {
                if(delarr==1){
                    numbers=(int*)realloc(numbers,0); //free number array memory
                    div_num=(int*)realloc(div_num,0); // free divisor array memory
                }
                system("cls");
		        printf ("> You've successfully quit the program.\n\n\n\n\n\n");
                }
	}
} while (choice != 0);

    }
    return 0;
}
//Choice function
int GetChoice () {

	int pick = 0;	// our selection
	while (1) {
		system ("cls");
		printf("> What are you going to do?\n");
		printf("> 1) Enter the amount of numbers.\n");
		printf("> 2) Enter the numbers.\n");
		printf("> 3) Print the numbers.\n");
		printf("> 4) Start calculating.\n");
        printf("> 5) Print results.\n\n");
		printf("> 6) Run full program.\n\n\n\n");
		printf("----------------------------\n");
		printf("> 0) Exit.\n\n\n");
		printf("> Selection number: ");

          if ( (scanf("%1d", &pick)==1) && (getchar() == '\n')){
				if ( (pick >= 0 ) && ( pick <= PICK_SIZE ) ){  // if the number is valid, it is accepted
			    break;
				}
			  else {
		      	printf("\nTry again.\n\n");
			 	system("PAUSE");
	     	  }
          }
		  else {
		      while (getchar() != '\n');
			  printf("\nTry again\n\n");
			  system("PAUSE");
		  }

	}
	return pick;
}


// Get size functoin
void Get_Size(int* total_numbers, int max){
    int error=1; // used to repeat the cycle while something was wrong
    printf("max %d\n",max);
    system("cls");
printf(">How many numbers are you going to enter?\n");
while(error==1){
    if((scanf("%d",total_numbers)==1)&&
       (*total_numbers>0)&&
       (*total_numbers<=max)&&
       (getchar()=='\n')){ //protection from entering symbols, letters and numbers below 1
        system("cls");
        error=0;
        } else {
            printf(">ERROR# Bad input, try again. \n>You cannot input numbers that are below 1 and characters\n");
            while (getchar()!='\n');
        }
}//while.end
}//get_size.end


//Array creation function
void Create_arrays(int* *numbers,
                   int* *div_num,
                   int total_numbers){
*numbers=(int*)malloc(total_numbers*sizeof(int));
*div_num=(int*)malloc(total_numbers*sizeof(int));
}
void Get_Numbers(int* numbers, int total_numbers, int max_fixed_size){
    int error=1, // used to repeat the cycle while something was wrong
        i;
		while(error==1){
                    for(i=0; i<total_numbers; i++){
                            printf("Enter your %d number\n",i+1);
                            if((scanf("%d",&numbers[i])==1)&&
                               (numbers[i]>1)&&
                               (numbers[i]<=max_fixed_size)&&
                               (getchar()=='\n')) {// protection from entering symbols and letters
                                error=0;

                            system("cls");
                            } else {
                                printf(">ERROR_2# Bad input, try again. \n>You cannot input numbers that are below 1 and characters\n");
                                i--;
                                while (getchar()!='\n');
                                }


                    }
            }
}
// ---- Divisor count  ----
void Count_divisors(int* numbers, int* div_num, int total_numbers){
    int n, i, total; // n,i - for cycles, total -  to identify how many divisors do we have in total for that number
    for (i=0; i<total_numbers;i++){
    total=0;
    for(n=1; n<=numbers[i]/2; n++){ //dalikliai nuo 1 iki pat skacius/2, kadangi daliklis mazesnis uz pati skaiciu yra nedidesnis uz to skaiciaus puse
        if(numbers[i]%n==0){
            total++;
        }
       // printf("total %d",total);
    div_num[i]=total+1; //simetriskam skaiciu masyvui, dalikliu masyvui priskiriam daliklius - kiek 'i' langelyje skaicius turi dalikliu
    }}
}
// ---- Max size and index ----
void Find_Maxindexsize(int total_numbers, int* max_size, int* max_index, int* div_num, int* numbers){
    int i; // used in cycle

    for(i=0; i<total_numbers; i++){ // searching for the most divisors
        if(div_num[i]>= *max_size){
        *max_size=div_num[i];
        *max_index=i;
        }
            }

}

// ----- PRINT ----
void print(int *numbers, int* div_num, int total_numbers){
int i; // used in cycle
printf("> You've entered:\n");
for (i=0;i<total_numbers;i++){
    printf(" %d\n",numbers[i]);
}
}
void Print_result(int* numbers, int* div_num, int max_index){
    int n; // used in cycle
        printf(">Number with the most divisors: %d\n>This number has %d divisors\n",numbers[max_index],div_num[max_index]);
        printf("----------\n|Divisors|\n----------\n");
        printf(" %d\n",numbers[max_index]);
        for(n=numbers[max_index]/2;n>0; n--){
            if(numbers[max_index]%n==0){
            printf(" %d\n",n);
            }
        }
}
