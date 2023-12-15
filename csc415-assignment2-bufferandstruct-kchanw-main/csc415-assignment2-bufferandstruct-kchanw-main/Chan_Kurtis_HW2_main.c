/**************************************************************
* Class:  CSC-415-01 Fall 2022
* Name:Kurtis Chan
* Student ID: 918139175
* GitHub UserID: kchanw
* Project: Assignment 2 – Stucture in Memory and Buffering
*
* File: Chan_Kurtis_HW2_main.c
*
* Description: Part1: we are to store data into a struct using malloc to allocate memory,
* then store data from the command line to the instantiated struct personalInfo
* Part 2: we are to write code that will use a buffer to temporarily store chars from a line of text,
* that will be later be committed. Repeat till there are no more lines of text.
*
**************************************************************/
#include <stdlib.h>
#include <assignment2.h>
#include <string.h>
#include <stdio.h>
int main(int argc,char *argv[]){
    personalInfo *myInfo = malloc(sizeof(personalInfo));
    myInfo->firstName = argv[1];
    myInfo->lastName = argv[2];
    myInfo->studentID = 918139175;
    myInfo->level = SENIOR;
    myInfo->languages = KNOWLEDGE_OF_C + KNOWLEDGE_OF_JAVA + KNOWLEDGE_OF_PYTHON + KNOWLEDGE_OF_CPLUSPLUS 
    + KNOWLEDGE_OF_HTML + KNOWLEDGE_OF_C_SHARP + KNOWLEDGE_OF_MIPS_ASSEMBLER + KNOWLEDGE_OF_PHP;
    memcpy(myInfo->message, argv[3], 100);

    writePersonalInfo(myInfo);
    
    free(myInfo);

    //initalizing buffer, line and the indeces for both
    int bufferIndex = 0;
    char *buffer = malloc(BLOCK_SIZE);
    char *line = getNext();
    int i = 0;


    //by using getNext() we get a char* that is stored into the pointer line, ends when the next line is empty(NULL)
    //
    while(line != NULL){ //runs till getNext() is a NULL and when the buffer is full, commit it and free up space
        while(line[i] != NULL){//runs till null from line
        if(bufferIndex == BLOCK_SIZE){
            //printf(buffer);
            commitBlock(buffer);//commit the full buffer
            bufferIndex = 0;
        }
        else{//store getNext() into current index and increment index
            buffer[bufferIndex] = line[i];
            bufferIndex++;
            i++;
        }
    }
    i = 0;//reset increment for line
    line = getNext();//getting the next line of text of type char *

}
    //printf(buffer);
    commitBlock(buffer);//commit whatever is left in buffer


    free(buffer);//free memory

    checkIt();

}
