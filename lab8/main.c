#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_PEOPLE 100

typedef struct{
	char name[50];
	int year;
	char sex[50];
	double height;
}humen;
int main(int argc, char *argv[]) {
	
	humen people[MAX_PEOPLE];
	int i, j, k;
    int count = 0;
	
	FILE* file=fopen("people.txt", "r");
	if(file==NULL){
		printf("file=null");	
	};
	char name[50];
	int year;
	char sex[50];
	double height;
	while (fscanf(file, "%s %d %s %lf\n", people[count].name, &people[count].year, people[count].sex, &people[count].height)==4){
	printf("%s %d %s %lf\n", people[count].name, people[count].year, people[count].sex, people[count].height);
	count++;
	
}
    if(count==0){
    	printf("the file is empty");
    	return 1;
	}
    
    fclose(file);
    
    printf("kriteri ocenivaniya");
    char input[100];
    fgets(input, sizeof(input), stdin);
    char *criteria[4];
    int num_criteria = 0;

    char *token = strtok(input, " \n");
    while (token != NULL && num_criteria < 4) {
        criteria[num_criteria++] = token;
        token = strtok(NULL, " \n");
    }

    for ( i = 0; i < count - 1; i++) {
        for (j = 0; j < count - i - 1; j++) {
            int need_swap = 0;

            for (k = 0; k < num_criteria; k++) {
                int cmp = 0;

                if (strcmp(criteria[k], "name") == 0) {
                    cmp = strcmp(people[j].name, people[j+1].name);
                } 
                else if (strcmp(criteria[k], "year") == 0) {
                    cmp = people[j].year - people[j+1].year;
                } 
                else if (strcmp(criteria[k], "sex") == 0) {
                    cmp = strcmp(people[j].sex, people[j+1].sex);
                } 
                else if (strcmp(criteria[k], "height") == 0) {
                    cmp = (people[j].height > people[j+1].height) ? 1 : -1;
                }

                if (cmp > 0) {
                    need_swap = 1;
                    break;
                } else if (cmp < 0) {
                    break;
                }
            }

            if (need_swap) { 
                humen temp = people[j];
                people[j] = people[j+1];
                people[j+1] = temp;
            }
        }
    }

    printf("\nSorted List:\n");
    for (i = 0; i < count; i++) {
        printf("%s %d %s %.2f\n", 
               people[i].name, 
               people[i].year, 
               people[i].sex, 
               people[i].height);
    }
	return 0;
}
