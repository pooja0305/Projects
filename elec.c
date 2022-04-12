include<stdio.h>
#include<stdlib.h>
float calc_elec(float units);
int main()
{
  float units=0;
  printf("enter units\n");
  scanf("%f",&units);
  calc_elec(units);
  return 0;
 }
  float calc_elec(float units)
{
  double charge=100;
  if(units<=200)
     charge+=units*0.8;
  else if(charge<=300)
     charge+=(200*0.8)+((units-200)*0.9);
  else
  {
    charge+=(200*0.8)+(100*0.9)+((units-300)*1);
    if (charge>400)
      charge+=charge*0.15;
  }
 printf("price to be paid=%.2f\n",charge);
}
