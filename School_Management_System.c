//   PROGRAM FOR SCHOOL SYSTEM MANAGEMENT.

// HEADER FILES==>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>


// Function Declaration.
void input();
void display();
void search();
void del();
void sort();

// Structure Declaration.
struct Student
{
    char name[30];
    char class[20];
    int roll_number;
    char date[12];
}S;


// File Pointer Declaration.
FILE *fp;

// SIZE Of Structure.
long sz=sizeof(S);


// MAIN Program.
int main()
{
    int ch;
    
    // This Will Create A Infinite Loop.
    while(1)
    {
           // Clearing SCREEN.
            system("cls");

            // INTERFACE.
            printf("                                                     <== SCHOOL MANAGEMENT ==>\n\n\n\n");

            // Displaying CHOICE.
            printf("1.Take Admission\n");
            printf("2.Student Info\n");
            printf("3.Search\n");
            printf("4.Modify\n");
            printf("5.Delete\n");
            printf("6.Sort\n");
            printf("0.Exit!\n\n");

            // Taking  Choice.
            printf("Enter Your choice : \n");
            scanf("%d",&ch);

            // Running Program Based On Various INPUT.
            switch(ch)
            {
                case 0:
                  printf("\n     EXITING!.....");
                  exit(0);

                case 1:
                  input();
                  break;
                
                case 2:
                  display();
                  break;

                case 3:
                  search();
                  break;

                case 4:
                 modify();
                 break;

                case 5:
                 del();
                 break;

                case 6:
                 sort();
                 break;
            }

            // INTERFACE>
            printf("\n\n                 Press any key to continue........\n");

            // Wait Till ENTERING A Character.
            getch();


    }

    return 0;
}

// Function For INPUT.
void input()
{
  // Clear SCREEN.
  system("cls");

  // INTERFACE.
  printf("                                      <== Student Info ==>\n\n");
      // This Is The Code To Take Real Time Date From SYSTEM.
      char mydate[12];
      time_t t=time(NULL);
      struct tm tm=*localtime(&t);
      sprintf(mydate,"%02d/%02d/%d",tm.tm_mday,tm.tm_mon+1,tm.tm_year+1900);
    //   printf("%s",mydate);

      strcpy(S.date,mydate);

    // Opening A File.
      fp=fopen("Student.txt","ab");

    // Entering Detail.
      printf("Enter student name: ");
      fflush(stdin);
      gets(S.name);
      printf("Enter class : ");
      gets(S.class);
      printf("Enter roll number : ");
      scanf("%d",&S.roll_number);

    // WRITING Info Into The FILE.
      fwrite(&S,sz,1,fp);

      printf("\n\n\n              Record Saved Successfully.......\n");

      // Closing FILE.
      fclose(fp);
}

// Function For DISPLAY.
void display()
{
    // Clear SCREEN.
    system("cls");

    // INTERFACE.
    printf("                                      <== Student Info ==>\n\n");
    printf("%-25s %-20s %-15s %5s\n","Name","Class","Roll Number","Date");

    // OPENING FILE.
    fp=fopen("Student.txt","rb");

    // READING Student Info.
    while(fread(&S,sz,1,fp)==1)
    {
        // DISPLAYING Student Info.
        printf("%-25s %-20s %-15d %5s\n",S.name,S.class,S.roll_number,S.date);
    }

    // CLOSING FILE.
    fclose(fp);
}

// Function For SEARCHING.
void search()
{
  int ch;

  // CREATING A Infinite Loop.
  while(1)
  {
    // Clearing SCREEN.
    system("cls");

    // INTERFACE.
    printf("                                      <== Search Info ==>\n\n");
    printf("1.Search by Roll_No\n");
    printf("2.Search by Name\n");
    printf("0.Back To Main Menu.\n");

    // Entering CHOICE.
    printf("\nEnter your Choice...\n");
    scanf("%d",&ch);

    // Applying CHOICE.
    switch(ch)
    {
      case 0:
       main();
       break;

      case 1:
       search_by_roll();
       break;

      case 2:
       search_by_name();
       break;

      default:
       printf("Invalid choice\n");
       break;
    }

    // Waiting Till Pressing Any KEY.
    getch();
  }
}

// SEARCHING By ROLL_NUMBER.
void search_by_roll()
{
  // Clearing SCREEN.
  system("cls");

  // INTERFACE.
  printf("                                      <== Enter Information ==>\n\n");
  int r_n;
  printf("\nEnter Roll Number to Search\n");
  scanf("%d",&r_n);
  int f=0;

  // OPENING A FILE.
  fp=fopen("Student.txt","rb");

  // INTERFACE.
  printf("%-25s %-20s %-15s %5s\n","Name","Class","Roll Number","Date");


  // READING From A FILE.
  while(fread(&S,sz,1,fp)==1)
    {
      // SEARCHING.
      if(S.roll_number==r_n)
      {
        f=1;

        // DISPLAYING.
        printf("%-25s %-20s %-15d %5s\n",S.name,S.class,S.roll_number,S.date);

        // BREAKING When Condition Is TRUE.
        break;
      }
    }

    // CLOSING FILE.
    fclose(fp);

    // INTERFACE.
    if(f==0)
    {
           printf("\n\n\nRecord Not Found\n");
    }
    else{
             printf("\n\n\nRecord Found Successfully\n");
    }

    printf("\n\n\nPress Any Key To Continue......\n");


}

// SEARCHING By NAME.
void search_by_name()
{
  // Clear SCREEN.
  system("cls");

  // INTERFACE.
  printf("                                      <== Enter Information ==>\n\n");
  int name1[30];

  // Entering NAME To SEARCH.
  printf("\nEnter Name to Search\n");
  fflush(stdin);
  gets(name1);
  int f=0;

  // OPENING FILE.
  fp=fopen("Student.txt","rb");

  // INTERFACE.
  printf("%-25s %-20s %-15s %5s\n","Name","Class","Roll Number","Date");

  // READING From FILE.
  while(fread(&S,sz,1,fp)==1)
    {
      // CHECKING Condition.
      if(strcmpi(S.name,name1)==0)
      {
        f=1;

        // DISPLAYING RESULT.
        printf("%-25s %-20s %-15d %5s\n",S.name,S.class,S.roll_number,S.date);

        // EXETING Loop When Condition Matched.
        break;
      }
    }

    // CLOSING FILE.
    fclose(fp);

    // INTERFACE.
    if(f==0)
    {
           printf("\n\n\nRecord Not Found\n");
    }
    else{
             printf("\n\n\nRecord Found Successfully\n");
    }

    printf("\n\n\nPress Any Key To Continue.......\n");


}

//  FUNCTION For MODIFICATION.
void modify()
{
  // CLEAR SCREEN.
  system("cls");

  // INTERFACE.
  printf("                                      <== Enter Information ==>\n\n");
  int r_n;

  // INPUTING NAME To SEARCH.
  printf("\nEnter Roll Number to Modify\n");
  scanf("%d",&r_n);
  int f=0;

  // OPENING FILE.
  fp=fopen("Student.txt","rb+");
  
  // READIN From FILE,
  while(fread(&S,sz,1,fp)==1)
    {
      // CHECKING Condition.
      if(S.roll_number==r_n)
      {
        f=1;
        // Entering Detail.
      printf("Enter student name: ");
      fflush(stdin);
      gets(S.name);
      printf("Enter class : ");
      gets(S.class);
      printf("Enter roll number : ");
      scanf("%d",&S.roll_number);

      
      fseek(fp,-sz,1);
    // Writing Info Into The File.
      fwrite(&S,sz,1,fp);
      fclose(fp);

        break;
      }
    }

    
   // INTERFACE.
    if(f==0)
    {
           printf("\nRecord Not Found\n");
    }
    else{
             printf("\nRecord Modified Successfully\n");
    }
}

// FUNCTION For DELETION.
void del()
{
  // Clear SCREEN.
  system("cls");

  // INTERFACE.
  printf("                                      <== Enter Information ==>\n\n");
  int r_n;

  // ENTERING ROLL_NUMBER To DELETE.
  printf("\nEnter Roll Number to Delete\n");
  scanf("%d",&r_n);
  int f=0;


  // CREATING A NEW FILE.
  FILE *ptr;
  ptr=fopen("temp.txt","ab");

  // OPEING EXISTING FILE.
  fp=fopen("Student.txt","rb");
  
 // SEARCHING For STUDENT.
  while(fread(&S,sz,1,fp)==1)
    {
      if(S.roll_number==r_n)
      {
             f=1;
      }
      else
      {
        // WRITING Matched STUDENT Into FILE.
        fwrite(&S,sz,1,ptr);
      }
    }

   // CLOSING FILE.
    fclose(fp);
    fclose(ptr);

    // REMOVING And CHANGING FILE NAME.
    remove("Student.txt");
    rename("temp.txt","Student.txt");

   // INTERFACE.
    if(f==0)
    {
           printf("\nRecord Not Found\n");
    }
    else{
             printf("\nRecord Deleted Successfully\n");
    }
}

// FUNCTION For SORTING.
void sort()
{
  // Clear Screen.
    system("cls");

      int c=0,i,j;
      struct Student s1[50],t;
    // INTERFACE.
    printf("                                      <== Student Info IN sorted  ==>\n\n");
    printf("%-25s %-20s %-15s %5s\n","Name","Class","Roll Number","Date");

    // OPENING FILE.
    fp=fopen("Student.txt","rb");

    // DISPLAYING Student Info.
    while(fread(&S,sz,1,fp)==1)
    {
        s1[c++]=S;
    }
  

    // SWAPPING.
    for(int i=0;i<c;i++)
    {
      for(int j=0;j<=c-2-i;j++)
      {
        if(s1[j].roll_number>s1[j+1].roll_number)
        {
          t=s1[j];
          s1[j]=s1[j+1];
          s1[j+1]=t;
        }
      }
    }

   // DISPLAYING.
    for(int i=0;i<c;i++)
    {
      printf("%-25s %-20s %-15d %5s\n",s1[i].name,s1[i].class,s1[i].roll_number,s1[i].date);
    }

    // Closing FILE.
    fclose(fp);
}