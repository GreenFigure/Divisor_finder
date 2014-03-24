#include <stdio.h>
#include <stdlib.h>
#define size 40000     // use this to change the max value allowed to enter
#define size1 500
#include <conio.h> //getch();
#include <string.h> //strcmp();
void Get_Size(int* total_numbers, int max);
void Create_arrays(int* *numbers, int* *div_num, int total_numbers);
void Get_Numbers(int* numbers, int total_numbers, int max_fixed_size);
void Count_divisors(int* numbers, int* div_num, int total_numbers);
void Find_Maxindexsize(int total_numbers, int* max_size, int* max_index, int* div_num, int* numbers);
void print(int* numbers, int* div_num, int total_numbers);
void Print_result(int* numbers, int* div_num, int max_index);

int main(int argc, const char* argv[]) {
    int *numbers;   //numbers
    int *div_num; // divisors
	int total_numbers,
        max, max_fixed_size,
        max_size=0,
        total,
        max_index=0; //variables for the arrays and to set sizes
/*-------------------------------------------------------*/
printf("argc %d \n argv[argc] %s \n", argc-1, argv[argc-1]);
        if (strcmp((argv[1]),"-h")==0){
            printf("Enter the the max size of numbers you are going to enter and the max value of a number. Etc: main.exe 50 1500");
            printf("\n\n");
        }
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

        printf("Max %d\n",max);
        printf(">In this simple divisor finding program you are allowed to enter numbers only.\n");
        printf(">The numbers are required to be [1..infinity].\n");
        printf("\n");
        printf("Press Any Key to Continue\n");
        getch();
        system("cls");
		printf(">How many numbers are you going to enter?\n");

        Get_Size(&total_numbers, max);

        Create_arrays(&numbers, &div_num, total_numbers);

        Get_Numbers(numbers, total_numbers, max_fixed_size);

        Count_divisors(numbers, div_num, total_numbers);

        Find_Maxindexsize(total_numbers, &max_size, &max_index, div_num, numbers);

        //print(numbers, div_num, total_numbers);

        Print_result(numbers, div_num, max_index);

        numbers=(int*)realloc(numbers,0); //free number array memory
        div_num=(int*)realloc(div_num,0); // free divisor array memory



    return 0;
}


void Get_Size(int* total_numbers, int max){
    int error=1;
    int compare;
    printf("max %d\n",max);
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

void Create_arrays(int* *numbers,
                   int* *div_num,
                   int total_numbers){
*numbers=(int*)malloc(total_numbers*sizeof(int));
*div_num=(int*)malloc(total_numbers*sizeof(int));
}
void Get_Numbers(int* numbers, int total_numbers, int max_fixed_size){
    int error=1,
        i;
		while(error==1){
                    for(i=0; i<total_numbers; i++){
                            printf("Enter your %d number\n",i+1);
                            if((scanf("%d",&numbers[i])==1)&&
                               (numbers[i]>1)&&
                               (numbers[i]<=max_fixed_size)&&
                               (getchar()=='\n')) {// protection from entering symbols and letters
                               // total=0;
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
    int n, i, total;
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
    int i;

    for(i=0; i<total_numbers; i++){ // searching for the most divisors
        if(div_num[i]>= *max_size){
        *max_size=div_num[i];
        *max_index=i;
        }
            }

}

// ----- PRINT ----
void print(int *numbers, int* div_num, int total_numbers){
int i;
for (i=0;i<total_numbers;i++){
    printf("Number %d has %d divisors counted\n",numbers[i], div_num[i]);
}
}
void Print_result(int* numbers, int* div_num, int max_index){
    int n;
        printf(">Number with the most divisors: %d\n>This number has %d divisors\n",numbers[max_index],div_num[max_index]);
        printf("----------\n|Divisors|\n----------\n");
        printf(" %d\n",numbers[max_index]);
        for(n=numbers[max_index]/2;n>0; n--){
            if(numbers[max_index]%n==0){
            printf(" %d\n",n);
            }
        }
}
