#include <stdio.h>
#include<stdlib.h>
#include<time.h>
int main() {
int player,count=0,mode,secret,won=0;
printf("guess a number\n");
printf("you have 7 chances\n");
srand(time(0));
printf("Enter the mode you want(Easy(1):1–50,Medium(2):1–100,Hard(3):1–500\n");
scanf("%d",&mode);
switch(mode){
case 1:  secret = rand() % 50+1;
break;
case 2:   secret = rand() % 100 + 1;
break;
case 3: secret = rand() % 500 + 1;
break;
default:
printf("invalid mode selected\n");
return 0;
}

printf("Enter your guessed number:\n");  
while(count<7){  
    scanf("%d",&player);  
    count++;  
     if(player>secret){  
    printf("it's high\n");  
         printf("try again\n");  
}else if(player<secret){  
         printf("it's low\n");  
         printf("try again\n");  
     }else{  
         printf("you won!\n");  
         printf("you guessed the number in %d attempts\n",count);  
         printf("game over!\n");  
         won=1;  
         break;  
     }  
}  
if(won==0){  
      printf("Game over! You used all 7 attempts.\n");  
       printf("The secret number was %d\n",secret);  
}  
return 0;

}