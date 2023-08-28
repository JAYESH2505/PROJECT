// THIS IS A C PROGRAM TO CREATE A CLOCK


// Header FILE.
#include<stdio.h>
#include<windows.h>

// MAIN Program.
int main()
{
    int h,m,s;

    // This will create a delay of 1s which makes our clock realsitic.
    int d=1;


    // Taking input from user
    printf("Set time :\n");
    scanf("%d%d%d",&h,&m,&s);


    // Checking ERROR!
    if(h>24 || m>60 || s>60)
    {
        printf("ERROR!");
        exit(0);
    }

    // This will create a infinite loop.
    while(1)
    { 
         // UPDATION.
         if(s>59)
         {
            s=0;
            m++;
         }
         if(m>59)
         {
            m=0;
            h++;
         }
         if(h>=24)
         {
            h=0;
         }
        
        
         printf("\nClock:");
         

         // This will display time in the format 00:00:00
         printf("\n %02d:%02d:%02d",h,m,s);

         s++;

         // This will create delay which makes it look like a real clock
         sleep(d);

         // This will clear the screen.
         system("cls");
    }
}