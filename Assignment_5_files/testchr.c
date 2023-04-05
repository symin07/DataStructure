#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
void clearInputBuffer()
{
  while (getchar() != '\n');
}

int parseInt(char *chNum)
{
  int num = 0; 
  
  for(int i = 0; chNum[i]; i++)
  {
    chNum[i] = chNum[i] - 48;
    num = num * 10;
    num = num + chNum[i];
  }
  
  return num;
}
int main()
{
    char* test;
  /*  char* resfget = fgets(test, 10, stdin);
    int strl = strlen(resfget);
    while(strl != 2){  
      printf("You can only input one letter \n");
       
       printf("str of fgets: %s", resfget); 
       printf("   test? : %s", test);   
       printf("   \\ strlen of resfgets: %d \n", (strlen(resfget)));
       clearInputBuffer();
       strl = strlen(fgets(test, 10, stdin));
    }*/
    char testString[] = "how old are you, ?";
    char testString2[] = "how old are you?";

    char* numComma = strstr(testString, ",");
    char* numComma2 = strstr(testString2, ",");
    printf("numcomma: %s, numcomma2: %s \n", numComma, numComma2);          
          
          printf("\n Restart? y/n: ");
          char in;
          scanf("%c", &in);
          clearInputBuffer();
          if (in == 'y')
            printf("** Run the progream again... ** \n\n");
          else if(in == 'n'){  
            printf("Bye! \n\n\n\n");
            exit(1); 
          }
    char input[5] = "";
    int count = 0;
    printf("enter command:");
    while(count != 1)
    {
      count = 0;
      scanf("%s", input);
      count = strlen(input);
      if(count != 1) 
        printf("Enter only one character on the menu");
    }   

    char *desc = malloc(sizeof(char));
    char *priori;
    char str[100] = "kin min ho good,35\n";
    desc = strtok(str, ",");
    priori = strtok(NULL, "\n");
    printf("priori: %s \n", priori);
    int priority = parseInt(priori);
    printf("this:  %s \n",desc);
    
    printf("this:  %d \n",priority);
    return 0;
}