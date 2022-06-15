#include<stdio.h>
#include<conio.h>

typedef struct{
	int id;
	char name[30];
	char gender;
	float income;
	
	}WORKERS;
	
	
void read(WORKERS data[5]);
void write(WORKERS data[5], char fileName[30]);
void writeByGender(WORKERS data[5], char fileName[30]);
float adIncome(WORKERS data[5], char fileName[30]);
	
int main(){
	FILE *file;
	WORKERS data[5];
	char fileName[30];
	int d;
	printf("File name:\n");
	fflush(stdin);
		gets(fileName);
	file=fopen(fileName, "a");

	read(data);
	
	printf("What you want to do?\n(1-write file 2-write file by gender 3-Adjust income)\n");	
		scanf("%d", &d);
	switch(d){
		case 1:write(data, fileName); break;
		case 2:writeByGender(data, fileName); break;
		case 3: adIncome(data, fileName);break;
		default: return 0;
	}
	
		
	

}

void read(WORKERS data[5]){
		for(int i=0;i<5;i++){
		printf("\nWorker %d\n", i+1);
		data[i].id=i;
		printf("Insert worker name: ");
			fflush(stdin);
			gets(data[i].name);
		printf("Insert worker gender (m or f): ");
			fflush(stdin);
			scanf("%c", &data[i].gender);
		printf("Insert worker income: ");
			scanf("%f", &data[i].income);
	}
}

void write(WORKERS data[5], char fileName[30]){
FILE *file, *fileR;
char c;
file=fopen(fileName, "a");
	fprintf(file, "ID\tNAME\tGENDER\tINCOME\n");
	for(int i=0;i<5;i++){
		fprintf(file, "%d\t%s\t%c\t$%.2f\n", data[i].id, data[i].name, data[i].gender, data[i].income);
	}
fclose(file);	
fileR=fopen(fileName, "r");


do{
	c=getc(fileR);
	printf("%c", c);
	}while(c != EOF);
getch();
fclose(fileR);
	
}

void writeByGender(WORKERS data[5], char fileName[30]){
FILE *file;
file=fopen(fileName, "a");
char gender;

printf("\n\nWhich gender do you want to write the data? (m or f)\n");
fflush(stdin);
	scanf("%c", &gender);

	fprintf(file, "ID\tNAME\tGENDER\tINCOME\n");
	for(int i=0;i<5;i++){
		if(data[i].gender==gender){
			fprintf(file, "%d\t%s\t%c\t$%.2f\n", data[i].id, data[i].name, data[i].gender, data[i].income);
	}
		
	}
}

float adIncome(WORKERS data[5], char fileName[30]){
FILE *file;
file=fopen(fileName, "a");
	float adjust;
	printf("\nInsert the income adjust in %%");
		scanf("%f", &adjust);
	for(int i=0;i<5;i++){
		data[i].income=((adjust*data[i].income)/100)+data[i].income;
	}
	write(data, fileName);
}


