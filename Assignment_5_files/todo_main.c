/*
 * This is where you will develop your to-do list application using your priority queue
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "pq.h"
#include "structs.h"

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


void _addPq(pq* myPq)
{
  printf("\nPlease enter the task description: ");
  //char desc[50];  Q: I don't know why this is not working
  //                A: 

  char* desc = malloc(sizeof(char)*1000);
  fgets(desc, 1000, stdin);
  desc[strlen(desc) - 1] = '\0';
  printf("Pleas enter the task priority (0-999): ");
  
  int inputNumber;
  scanf(" %d", &inputNumber);
  clearInputBuffer();
  
  addPq(myPq, desc, inputNumber);
  printf("The task '%s' has been added to your to-do list\n", desc);
  //free(desc);
}

task* loadFile(char* readLine)
{
  task* loadedTask  = (task*)malloc(sizeof(task));
  char *desc;
  desc = strtok(readLine,",");
  desc[strlen(desc)] = '\0';
  char* priority = strtok(NULL,"\n");

  //value->name = malloc((strlen(name) + 1) * sizeof(char));
  //strcpy(value->name, name);

  loadedTask->toDo =  malloc((strlen(desc) + 1) * sizeof(char));
  strncpy(loadedTask->toDo, desc, strlen(desc)+1);
  loadedTask->priority = parseInt(priority);
  return loadedTask;   
}

int main(int argc, char** argv)
{
  struct pq* myPq = createPq();
  // FIXME
  printf("*** WELCOME TO THE TO-DO LIST APPLICATIO *** \n");
  printf("---- DEVELOPED BY THE MYSTERIOUS DEVELOPER ----\n");

  FILE *readCommandDisplay = fopen("command_display.txt", "r");
  
  assert(readCommandDisplay != NULL);
  char line[100];
  char input[5] = "";
  
  while(1)
  {
    int count = 0;
    while(fgets(line, sizeof(line), readCommandDisplay) != NULL)
      printf("%s", line);
    
     
    while(count != 1)
    {
      printf("\n Enter Command: ");
      count = 0;
      scanf("%s", input);
      count = strlen(input);
      if(count != 1)
      { 
        printf("Enter only one character on the menu. \n");
        for(int i = 0; i < count; i++)
          input[i] = '\0';
      }
      clearInputBuffer();
    }    
   
  
    
    switch(input[0])
    {
      case 'l':
        printf("Please enter the filename to load the list form: ");
        char* filename = malloc(sizeof(char)*50);
        fgets(filename, 50, stdin);
        filename[strlen(filename) - 1] = '\0';
        task* loadTask; //= (task*)malloc(sizeof(task));
        FILE *reader = fopen(filename, "r");
        
        assert(reader != NULL);
        char readLine[100];
        while(fgets(readLine, sizeof(readLine), reader)!=NULL)
        {
          loadTask = loadFile(readLine);
          addPq(myPq, loadTask->toDo, loadTask->priority);
        }
        fclose(reader);
        printf("The list has been loaded!\n");
        break;
      case 's': 
        FILE *writer = fopen("todo.txt", "w");
        assert(writer != NULL);
        while(!isemptyPq(myPq))
        { 
          task* getTask = (task*)getPq(myPq);
          fprintf(writer, "%s,%d\n",getTask->toDo, getTask->priority);
          removePq(myPq);
        }
        fclose(writer); 
        printf("The list has been saved!\n");     
        break;
      case 'g':
        task* getTask = (task*)getPq(myPq);
        if(isemptyPq(myPq))
          printf("\nYour to-do list is empty!\n");
        else
          printf("\nYour first task is: %s \n", getTask->toDo);
      break;
      case 'a':
        _addPq(myPq);
        break;
      case 'r':
        getTask = (task*)getPq(myPq);
        printf("\nThe task: '%s' is going to be erased. \n", getTask->toDo);
        removePq(myPq);
        break;
      case 'p':
        if(isemptyPq(myPq))
          printf("\nYour to-do list is empty!\n");
        printf("\n");
        printPq(myPq);
        break;
      case 'e':
          printf("\n Restart? y/n: ");
          char in;
          scanf("%c", &in);
          clearInputBuffer();
          if (in == 'y')
            printf("** Run the progream again... ** \n\n");
          else if(in == 'n'){  
            printf("Bye! \n\n\n\n");
            freePq(myPq);
            exit(1); 
          }    
        break;
      default:
        printf("Enter one character on the menu \n");
        break; 
    }
    fseek(readCommandDisplay,0,SEEK_SET);
  }
  fclose(readCommandDisplay);
  freePq(myPq);
  return 0;

}