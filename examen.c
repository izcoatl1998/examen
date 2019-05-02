#include <examen.h>
char caracter[25];
int global0=0;
void clean(void);
#INT_TIMER0 
void TIMER0(){
global0=1;
set_timer0(15536);
}

int i=0,calculo=0,calculo2=0,separador=0,puntero=-1;
int c2=0;
void main()
{
   setup_timer_0(RTCC_INTERNAL | RTCC_DIV_8 );
   enable_interrupts(INT_TIMER0);
   enable_interrupts(GLOBAL);
   set_timer0(15536); 
   set_tris_d(0x0);
   while(TRUE)
   {
      if(kbhit()){
         caracter[i]=getch();
      if(caracter[i]>=97 && caracter[i]<=122 || caracter[i]==32){
            printf("%c",caracter[i]);
       if(caracter[i]==32){
            calculo=1;
             }
           i++;
        }
       }
     if(calculo==1){
       separador=i;
        do{
      if(kbhit()){
         caracter[i]=getch();
      if(caracter[i]>=97 && caracter[i]<=122 || caracter[i]==13){
            printf("%c",caracter[i]);
            if(caracter[i]==13){
            calculo2=1;
            }
         i++;
      }
     }
        }while(calculo2!=1);
      if(calculo2==1){
      switch(caracter[separador]){
          case 'u':
           do{
           if(global0==1){
             puntero++;
             printf("%c",caracter[puntero]);
             output_High(pin_D4);
             global0=0;}
             if(caracter[puntero]==32){
             puntero=-1;
             c2++;}
             }while(c2!=1);
            clean();
          break;
          case 't':
             do{
           if(global0==1){
             puntero++;
             printf("%c",caracter[puntero]);
             output_High(pin_D4);
             global0=0;}
             if(caracter[puntero]==32){
             puntero=-1;
             c2++;}
             }while(c2!=3);
              clean();
            break;
            case 'n':
            do{
               if(global0==1){
                puntero++;
                printf("%c",caracter[puntero]);
                output_High(pin_D4);
                global0=0;}
                if(caracter[puntero]==32){
                puntero=-1;
                c2++;}
             }while(c2!=9);
             clean();
             break;
          }
          getch();
          printf("\f");
       }
      }
   }
}
 void clean(void){
        for(int clear=0; clear<26;clear++){
          if(caracter[clear]!=NULL){
              caracter[clear]=NULL;
          }}
       i=0;
       c2=0;
      calculo=0;
      calculo=0;
      puntero=0;
        }
