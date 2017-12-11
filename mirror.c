
//Coded by Isuru Nanayakkara for CS 100 Project 4. CWID 11743717

//This program reads user input into a string, breaks words into indivdual tokens, reverses the tokens and then prints them in reverse according to arguments.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//Holds the reversed word and length.
typedef struct reversedWordsStruct
{
	char word[50];
	int lengthOfWord;
	
}reversedWordsStruct;

void removeNewLineFromString(char* stringToFix)
{
	int i =0;
	
	for(i = 0; (stringToFix[i] != '\n' || stringToFix[i] != '\0'); i++)
	{
		if(stringToFix[i] == '\n')
		{
			stringToFix[i] = '\0';
		}
	}
}

void reverse_string(char *str)
{
    /* skip null */
    if (str == 0)
    {
    	return;
    }

    /* skip empty string */
    if (*str == 0)
    {
    	return;
    }

    /* get range */
    char *start = str;
    char *end = start + strlen(str) - 1; /* -1 for \0 */
    char temp;

    /* reverse */
    while (end > start)
    {
    	/* swap */
    	temp = *start;
    	*start = *end;
    	*end = temp;

    	/* move */
    	++start;
    	--end;
    }
}

void formatRight(reversedWordsStruct* stringToPrint, int lengthOfStruct, int numberOfColumns)
{
	int i = 0;
	int wordsUsed = 0;
	int columnsUsed = 0;
	reversedWordsStruct currentWord;
	
	char lineToPrint[numberOfColumns+10];
	char lineToPrintReversed[numberOfColumns+10];
	
	while(wordsUsed < lengthOfStruct)
	{
		columnsUsed = 0;
		
		while(columnsUsed <= numberOfColumns)
		{
			if(columnsUsed == 0)
			{
				currentWord = stringToPrint[wordsUsed];
				
				strcpy(lineToPrint, currentWord.word);
				columnsUsed = columnsUsed + currentWord.lengthOfWord;
				//strcat(lineToPrint, "-");
				columnsUsed++;
				wordsUsed++;
				
				currentWord = stringToPrint[wordsUsed];
			}
			
			else if(columnsUsed + (currentWord.lengthOfWord) <= numberOfColumns && (wordsUsed < lengthOfStruct) )
			{
				if(strcmp(currentWord.word, "\0") != 0)
				{
					strcpy(lineToPrintReversed, currentWord.word);
					strcat(lineToPrintReversed, " ");
					strcat(lineToPrintReversed, lineToPrint);
					strcpy(lineToPrint, lineToPrintReversed);
					
					columnsUsed = columnsUsed + currentWord.lengthOfWord;
					
					columnsUsed++;
					wordsUsed++;
					
					currentWord = stringToPrint[wordsUsed];
				}
			}
			
			else
			{
				strcpy(lineToPrintReversed, " ");
				strcat(lineToPrintReversed, lineToPrint);
				strcpy(lineToPrint, lineToPrintReversed);
				columnsUsed++;
			}
		}
		
		printf("%s\n", lineToPrintReversed);
	}
}

void formatLeft(reversedWordsStruct* stringToPrint, int lengthOfStruct, int numberOfColumns)
{
	int i = 0;
	int wordsUsed = 0;
	int columnsUsed = 0;
	reversedWordsStruct currentWord;
	
	char lineToPrint[numberOfColumns+10];
	char lineToPrintReversed[numberOfColumns+10];
	
	while(wordsUsed < lengthOfStruct)
	{
		columnsUsed = 0;
		
		while(columnsUsed < numberOfColumns)
		{
			if(columnsUsed == 0)
			{
				if(wordsUsed == lengthOfStruct - 1)  //Last word
				{
					currentWord = stringToPrint[wordsUsed];
					
					strcpy(lineToPrintReversed, currentWord.word);
					columnsUsed = columnsUsed + currentWord.lengthOfWord;
					wordsUsed++;
					
					currentWord = stringToPrint[wordsUsed];
				}
				
				else
				{
					currentWord = stringToPrint[wordsUsed];
					
					strcpy(lineToPrint, currentWord.word);
					columnsUsed = columnsUsed + currentWord.lengthOfWord;
					wordsUsed++;
					
					currentWord = stringToPrint[wordsUsed];
				}
			}
			
			else if(columnsUsed + (currentWord.lengthOfWord + 1) <= numberOfColumns && (wordsUsed != lengthOfStruct) )
			{
				
				strcpy(lineToPrintReversed, currentWord.word);
				strcat(lineToPrintReversed, " ");
				strcat(lineToPrintReversed, lineToPrint);
				strcpy(lineToPrint, lineToPrintReversed);
				
				columnsUsed = columnsUsed + currentWord.lengthOfWord;
				
				columnsUsed++;
				wordsUsed++;
				
				currentWord = stringToPrint[wordsUsed];
				
			}
			
			else
			{
				if(wordsUsed != lengthOfStruct)
				{
					strcpy(lineToPrintReversed, lineToPrint);
				}
				
				i = columnsUsed;
				while(i < numberOfColumns)
				{
					strcat(lineToPrintReversed, " ");
					i++;
					columnsUsed++;
				}
				
				if(i == numberOfColumns)
				{
					columnsUsed++;
				}
			}
		}
		
		printf("%s\n", lineToPrintReversed);
	}
}

void formatCentre(reversedWordsStruct* stringToPrint, int lengthOfStruct, int numberOfColumns)
{
	int i = 0;
	int wordsUsed = 0;
	int columnsUsed = 0;
	reversedWordsStruct currentWord;
	bool doOnce = true;
	
	char lineToPrint[numberOfColumns+10];
	char lineToPrintReversed[numberOfColumns+10];
	
	while(wordsUsed < lengthOfStruct)
	{
		columnsUsed = 0;
		doOnce = true;
		
		while(columnsUsed < numberOfColumns)
		{
			if(columnsUsed == 0)
			{
				if(wordsUsed == lengthOfStruct - 1)
				{
					currentWord = stringToPrint[wordsUsed];
					strcpy(lineToPrint, currentWord.word);
					columnsUsed = columnsUsed + currentWord.lengthOfWord;
					wordsUsed++;
					//printf("%s\n", lineToPrintReversed);
					//printf("Words Used: %d\n", wordsUsed);
					//printf("Words Used: %d\n", lengthOfStruct);
				}
				
				else
				{
					currentWord = stringToPrint[wordsUsed];
					
					strcpy(lineToPrint, currentWord.word);
					columnsUsed = columnsUsed + currentWord.lengthOfWord;
					//strcat(lineToPrint, "-");
					//columnsUsed++;
					wordsUsed++;
					
					currentWord = stringToPrint[wordsUsed];
				}
			}
			
			else if(columnsUsed + (currentWord.lengthOfWord + 1) <= numberOfColumns && (wordsUsed != lengthOfStruct) )
			{
				if(strcmp(currentWord.word, "\0") != 0)
				{
					strcpy(lineToPrintReversed, currentWord.word);
					strcat(lineToPrintReversed, " ");
					strcat(lineToPrintReversed, lineToPrint);
					strcpy(lineToPrint, lineToPrintReversed);
					
					columnsUsed = columnsUsed + currentWord.lengthOfWord;
					
					columnsUsed++;
					wordsUsed++;
					
					currentWord = stringToPrint[wordsUsed];
				}
			}
			
			else
			{
				int columnsLeft = numberOfColumns - columnsUsed;
				
				if(columnsLeft != 1)// && doOnce == true)
				{
				
					int spacesOnLeft = columnsLeft/2;
					int spacesOnRight = columnsLeft - spacesOnLeft;
					
					while(spacesOnLeft > 0)
					{
						strcpy(lineToPrintReversed, " ");
						strcat(lineToPrintReversed, lineToPrint);
						strcpy(lineToPrint, lineToPrintReversed);
						//printf("%s\n", lineToPrintReversed);
						columnsUsed++;
						spacesOnLeft--;
					}
	
					while(spacesOnRight > 0)
					{
						strcat(lineToPrintReversed, " ");
						//printf("%s\n", lineToPrintReversed);
						columnsUsed++;
						spacesOnRight--;
					}
					
					//doOnce == false;
					//columnsUsed++;
				}
				
				else
				{
					strcat(lineToPrintReversed, " ");
					//printf("%s\n", lineToPrintReversed);	
					columnsUsed++;
				}
				
			}
		}
		
		printf("%s\n", lineToPrintReversed);
	}
}

void formatString(reversedWordsStruct* stringToPrint, int lengthOfStruct, char orientation, int numberOfColumns)
{
	switch(orientation)
	{
		case 'L':	formatLeft(stringToPrint,  lengthOfStruct, numberOfColumns);
					break;
		case 'C':	formatCentre(stringToPrint,  lengthOfStruct, numberOfColumns);
					break;
		case 'R':	formatRight(stringToPrint,  lengthOfStruct, numberOfColumns);
					break;
	}
}

int main(int argc, char *argv[]) 
{	

	if(argc > 3)
	{
		printf("Error: Incorrect number of arguments. Enter only two");
		return -1;
	}
		
	FILE* fileToRead;
	
	char* fileString;
	char* fileStringCopy;
	
	char format[50];
	char LCR = ' ';
	char formatNum[45];
	
	reversedWordsStruct tokenizedWords[10000];
	
	char* token;
	const char delims[] = {'\n', ' ', '\0'};
	
	int formattedNum = 0;
	
	strcpy(format, argv[2]);
	
	int i = 0;
	int j = 0;
	int tokenizedWordCount = 0;
	
	{
		fileToRead = fopen(argv[1], "r");
		
		fseek(fileToRead, 0, SEEK_END);
		long numberOfBytes = ftell(fileToRead) + 1;
		fileString = (char*) malloc(numberOfBytes);
		fileStringCopy = (char*) malloc(numberOfBytes);
		fseek(fileToRead, 0, SEEK_SET);
		
		fgets(fileString, numberOfBytes, fileToRead);
		fclose(fileToRead);
	}
	
	//removeNewLineFromString(fileString);
	//printf("%s\n", fileString);	
	strcpy(fileStringCopy, fileString);	
	//printf("%s\n", fileStringCopy);
	//printf("%s", format);
	
	LCR = format[0];
	
	for(i = 1; i < strlen(format); i++)
	{
		formatNum[i-1] = format[i];
	}
		
	formattedNum = atoi(formatNum);
	
	
	if(formattedNum < 0)
	{
		printf("Error: Entered Format Number is negative.");
		return -1;
	}
		
	
	//wordSplitFunction(fileStringCopy, tokenizedWords);
	
	//printf("%c\n", LCR);
	//printf("%d", formattedNum);
	if(LCR == 'L' || LCR == 'C' || LCR == 'R')
	{
		
		token = strtok(fileStringCopy, delims);
		
		while( token != NULL ) 
	    { 
	      strcpy(tokenizedWords[tokenizedWordCount].word, token);
	      
	      tokenizedWords[tokenizedWordCount].lengthOfWord =  strlen(token);
	      
	      //printf( "%s is %d charachters long\n", tokenizedWords[tokenizedWordCount].word, tokenizedWords[tokenizedWordCount].lengthOfWord);
	    
	      token = strtok(NULL, delims);
	      
	      tokenizedWordCount++;
	    }
	    
	    //reversedWordsStruct backWords[tokenizedWordCount];
	    
	   for(i = 0; i < tokenizedWordCount+6; i++)
	   {
	   		reverse_string(tokenizedWords[i].word);
	   		//printf( "%s\n", tokenizedWords[i].word);
	   }
	   
	   //printf("Number of words = %d", tokenizedWordCount);
	   
	   formatString(tokenizedWords, tokenizedWordCount, LCR, formattedNum);
	}
	
	else
	{
		printf("Error: Format specifier is incorrect. Try L,C or R.");
		return -1;
	}
	
	return 0;
}
