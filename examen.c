#include <examen.h>
char caracter[25];
#INT_TIMER0 
void TIMER0(){

set_timer0(15536);
}

int i=0,calculo=0;
void main()
{
   setup_timer_0(RTCC_INTERNAL | RTCC_DIV_8 );
   enable_interrupts(INT_TIMER0);
   enable_interrupts(GLOBAL);
   set_timer0(15536); 
   while(TRUE)
   {
      if(kbhit()){
         caracter[i]=getch();
      if(caracter[i]>=65 && caracter[i]<=90 || caracter[i]>=97&&caracter[i]<=122|| caracter[i]==32){
            printf("%c",caracter[i]);
       if(caracter[i]==32){
            calculo=1;
             }
        }
       }
   if(calculo==2){
      if(kbhit()){
         caracter[i]=getch();
      if(caracter[i]>=65 && caracter[i]<=90 || caracter[i]>=97&&caracter[i]<=122|| caracter[i]==13){
            printf("%c",caracter[i]);}
      }
   }
   }
}
