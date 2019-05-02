#include <examen.h>
char caracter[25];
#INT_TIMER0 
void TIMER0(){

set_timer0(15536);
}

int i=0,calculo=0,calculo2=0,separador=0,puntero=-1;
int c2=0,acabar=0;
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
      if(caracter[i]>=65 && caracter[i]<=90 || caracter[i]==32){
            printf("%c",caracter[i]);
       if(caracter[i]==32){
            calculo=1;
             }
           i++;
        }
       }
    do{
      if(calculo==1){
         i++;
         separador=i;
      if(kbhit()){
         caracter[i]=getch();
      if(caracter[i]>=65 && caracter[i]<=90 || caracter[i]==13){
            printf("%c",caracter[i]);}
            if(caracter[i]==13){
            calculo2=1;}
            
      }
      if(calculo2==1){
      switch(caracter[separador]){
          case 't':
             do{
             puntero++;
             printf("%c",caracter[puntero]);
             if(caracter[puntero]==32){
             puntero=-1;
             c2++;}
             }while(c2==3);
             acabar=1;
            break;
          }
       }
      }
     }while(acabar=!1);
   }
}
