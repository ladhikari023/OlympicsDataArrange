/* Laxman Adhikari
   CS241L 004
   Project #5
   
   In this program, when we pass the data tdf20 or similar with similar entries,
   this program reads the data and store the value in respective array.
   When user specify how they want to format the data by giving input in command 
   line, the programs gives the required output. 

*/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_RIDER 146

char  rider[MAX_RIDER][20],country[MAX_RIDER][20],team[MAX_RIDER][4],time[MAX_RIDER][20];
int classification[MAX_RIDER],rider_nbr[MAX_RIDER];	
int i,j;

/* This function swaps the value of arrays of given indexes */
void swapAll(int i,int j)
{
char tempRider[20],tempCountry[20],tempTeam[4],tempTime[20];
        int tempClassification,tempRiderNumber;

                        strcpy(tempRider,rider[i]);
                        strcpy(tempCountry,country[i]);
                        strcpy(tempTeam,team[i]);
                        strcpy(tempTime,time[i]);
                        tempClassification=classification[i];
                        tempRiderNumber=rider_nbr[i];

                        strcpy(rider[i],rider[j]);
                        strcpy(country[i],country[j]);
                        strcpy(team[i],team[j]);
                        strcpy(time[i],time[j]);
                        classification[i]=classification[j];
                        rider_nbr[i]=rider_nbr[j];

                        strcpy(rider[j],tempRider);
                        strcpy(country[j],tempCountry);
                        strcpy(team[j],tempTeam);
                        strcpy(time[j],tempTime);
                        classification[j]=tempClassification;
                        rider_nbr[j]=tempRiderNumber;

}

/* This function formats the given data into readable data */
void format_function(){
printf("%-20s%-20s%-20s%-20s%-20s%-20s\n","Classification","Rider", "Rider No.", "Country","Team","Time (hh:mm:ss)");

for(i=0;i<MAX_RIDER;i++){
	printf("%-19d %-19s %-19d %-19s %-20s%s\n",classification[i],rider[i],rider_nbr[i],country[i],team[i],time[i]);
}	
}


/* This function formats the given data by sorting rider number */
void team_function(){
printf("%-20s%-20s%-20s%-20s\n","Team","Rider No.","Rider","Time (hh:mm:ss)");
for(i=0;i<MAX_RIDER;i++){
	for(j=i+1;j<MAX_RIDER;j++){
		if(rider_nbr[i]>rider_nbr[j]){
			swapAll(i,j);
		}
	}
}
for(i=0;i<MAX_RIDER;i++){
	printf("%-20s%-20d%-20s%s\n",team[i],rider_nbr[i],rider[i],time[i]);
}
}

/* This function formats the given data by sorting country, rider, and classification in respective order */
void country_function(){
	int i,j,comCountry,comRider;
	printf("%-20s%-20s%-20s%-20s\n", "Country","Rider","Classification","Time (hh:mm:ss)");
	
	for(i=0;i<MAX_RIDER;i++){
		for(j=i+1;j<MAX_RIDER;j++){
			comCountry = strcmp(country[i],country[j]);
			comRider = strcmp(rider[i],rider[j]);
			
			if((comCountry > 0) || (comCountry==0 && comRider > 0) || (comCountry ==0 && comRider==0 &&
					classification[i] > classification [j])){
			swapAll(i,j);
			}
		}
	}	
	for(i=0;i<MAX_RIDER;i++){
		printf("%-20s%-20s%-20d%s\n",country[i],rider[i],classification[i],time[i]);
	}
}

int main(int argc, char *argv[]){

if(argc == 1){
	printf("Not the correct command");
	exit(0);
}

/* The code segment below scans all the data from the file and save them into arrays */
for(i=0;i<MAX_RIDER;i++){
scanf("%d %s %d %s %s %s",&classification[i],rider[i],&rider_nbr[i],country[i],team[i],time[i]);
}

/* The code below determines the output of the program */
if(!strcmp(argv[1],"format")){
format_function();
}
if(!strcmp(argv[1],"team")){team_function();}
if(!strcmp(argv[1],"country")){country_function();}
return 0;
}

