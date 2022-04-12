
Pooja Harihar <hariharpooja2007@gmail.com>
09:02 (1 hour ago)
to me

/*program of electricity board*/
#include<stdio.h>
void main()
{
 char name [20];
 float units,charges =100;

   printf("enter name and units consumed\n");
   scanf("%s%f",name,&units);

  if(units<=200)
   {
     charges = charges+(units*0.8);
    }
   else if (units <=300)
   {
    charges = charges+(200*0.8)+(units-200)*0.9;
   }

  else
   {
    charges = charges +(200*0.8)+(100*0.9)+(units-300)*1;

   if (charges>400)
   charges = charges +(charges*0.15);
   }
 printf("name=%s\ncharges=%f\n",name,charges);
}
