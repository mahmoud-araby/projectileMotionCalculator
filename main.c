#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI  3.14159265359
#define G  9.8

 /*this function scans the object initial velocity in m/s and the angle of elevation from the horizontal in degree from the screen and print it to the
  *  screen in a new foramt
  * input :takes the adreeses of the variable storages
  * output: the scaned values to the parsed variable storage adresses given as parameters to the function
  *          no return value*/
void input_values (double *intial_Velocity , double *Angle_degree);

/*this function converts the the angle of elevation from the horizontal from degree to radian so it can be calculated further in sin() func.
 *input :  the angle of elevation from the horizontal in degree
 *output : the angle of elevation from the horizontal in radian */
double Degree_to_Radian (double Angle_degree);

/* this function calculates the travel distance throw the equation
 * inputs :the object initial velocity in m/s
 *         the angle of elevation from the horizontal in radian
 * outputs:the travel distance */
double Get_Travel_Distance (double intial_Velocity , double Angle_radian);

/* this function calculatesthe object travel time throw the equation
 * inputs :the object initial velocity in m/s
 *         the angle of elevation from the horizontal in radian
 * outputs:the object travel time */
double Get_Travel_Time (double intial_Velocity , double Angle_radian);

/* this function calculatesthe object  maximum height throw the equation
 * inputs :the object initial velocity in m/s
 *         the angle of elevation from the horizontal in radian
 * outputs:the object  maximum height */
double Get_Max_Height (double intial_Velocity , double Angle_radian);

/* this function prints all values (object Travel_Distance ,object Travel_Time ,object Max_Height) to the screen
 * inputs :object Travel_Distance
 *         object Travel_Time
 *         object Max_Height
 * output : print all values to the screen
 *          no return value */
void Print_Values (double Travel_Distance , double Travel_Time , double Max_Height);

/* this function creates a excel file and puts all values (intial_Velocity ,Angle_radian, object Travel_Distance ,object Travel_Time ,object Max_Height)
 * in this file
 * inputs :the object initial velocity in m/s
 *           the angle of elevation from the horizontal in radian
 *           object Travel_Distance
 *           object Travel_Time
 *           object Max_Height
 * output : print all values to the excel file
 *          no return value */
void Produce_Excel (double intial_Velocity , double Angle_degree , double Travel_Distance , double Travel_Time , double Max_Height);

double intial_Velocity = 0 ;  //the object initial velocity in m/s
double Angle_degree = 0 ;     //the angle of elevation from the horizontal in degree
double Angle_radian = 0 ;     //the angle of elevation from the horizontal in radian
double Travel_Distance =0 ;   //the object travel distance
double Travel_Time =0 ;       //the object travel time
double Max_Height = 0 ;       //the object maximum height


int main(int argc, char **argv)
{
    /*scan the the object initial velocity in m/s and the angle of elevation from the horizontal in degree from the screen*/
    input_values (&intial_Velocity , &Angle_degree);
    /* convert the the angle of elevation from the horizontal from degree to radian */
    Angle_radian = Degree_to_Radian (Angle_degree);
    /*calculate the object travel distance */
    Travel_Distance = Get_Travel_Distance ( intial_Velocity ,  Angle_radian);
    /*calculate the object travel time */
    Travel_Time = Get_Travel_Time ( intial_Velocity ,  Angle_radian);
    /*calculate the object  maximum height */
    Max_Height = Get_Max_Height ( intial_Velocity , Angle_radian);
    /* print the calulated values to the screen */
    Print_Values ( Travel_Distance ,  Travel_Time ,  Max_Height);
    /*save the calcualted values to a new excel sheet */
    Produce_Excel (intial_Velocity , Angle_degree , Travel_Distance ,Travel_Time , Max_Height);
	return 0;
}



double Degree_to_Radian (double Angle_degree){
    double ret ;   // return value
    ret = ( Angle_degree * (PI/180.0) );   // equation to convert degree value to radian value
    return ret;}

double Get_Travel_Distance (double intial_Velocity , double Angle_radian){
    double ret;  // return value
    ret=((intial_Velocity * intial_Velocity)* sin(2.0 * Angle_radian))/G;  // equation to calculate the object travel distance
    return ret;}

double Get_Travel_Time (double intial_Velocity , double Angle_radian){
    double ret;  // return value
    ret =((2.0 * intial_Velocity *  sin(Angle_radian))/G);   // equation to calculate the object travel time
    return ret;}

double Get_Max_Height (double intial_Velocity , double Angle_radian){
    double ret;   // return value
    ret = ((intial_Velocity*sin(Angle_radian))*(intial_Velocity*sin(Angle_radian))/(2.0*G));    //equation to calculate the object maximum height
    return ret;}

void Print_Values (double Travel_Distance , double Travel_Time , double Max_Height){
    printf("**************************OUTPUTS*************************\n");
    printf("The object travel distance is %.6lf m\n",Travel_Distance);  // print the object travel distance
    printf("The object travel time is %.6lf s\n",Travel_Time);          // print the object travel time
    printf("The object maximum height is %.6lf m\n",Max_Height);        // print the object maximum height
    printf("\n");
}

void input_values (double *intial_Velocity , double *Angle_radian){
    printf ("Enter the object velocity in m/s \n");
    scanf("%lf",intial_Velocity);                                                       // scan the object initial velocity in m/s
    printf ("Enter the angle of elevation from the horizontal in degree \n");
    scanf("%lf",Angle_radian);                                                           //  scan the angle of elevation from the horizontal in degree
    printf("\n");
    printf("**************************INTPUTS*************************\n");
    printf ("initial velocity of the object is %0.6f m/s\n", *intial_Velocity);            // print the object initial velocity in m/s
    printf ("angle of elevation from the horizontal is %0.6f degree\n \n", *Angle_radian); // print the angle of elevation from the horizontal in degree
}



void Produce_Excel (double intial_Velocity , double Angle_degree , double Travel_Distance , double Travel_Time , double Max_Height){
FILE *fp;

fp= fopen("projectileMotionCalculator.csv", "w");                                          // creates the excel sheet in the same folder as the project exists
if(fp==NULL)exit(1);                                                                       // checks if the program created the file correctly

fprintf(fp, "%.6lf ; %s \n" , intial_Velocity ,"initial velocity of the object");           // save the object initial velocity in m/s to excel sheet
fprintf(fp, "%.6lf ; %s \n" , Angle_degree ,"angle of elevation from the horizontal");      // save the angle of elevation from the horizontal in degree to excel sheet
fprintf(fp, "%.6lf ; %s \n" , Travel_Distance ,"The object travel distance" );              // save the object travel distance to excel sheet
fprintf(fp, "%.6lf ; %s \n" , Travel_Time ,"The object travel time" );                      // save the object travel time to excel sheet
fprintf(fp, "%.6lf ; %s \n" , Max_Height ,"The object maximum height" );                    // save the object maximum height to excel sheet
}
