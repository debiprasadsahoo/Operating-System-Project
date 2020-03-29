#include <stdio.h> 
 struct stud 
 { 
     int sId,fttime,wtime,tatime; 
     char sname[10];
 }; 
  
 void acpt(struct stud list[], int x);  
 void schl(struct stud list[], int x); 
 void disp(struct stud list[], int x);
 void wtime(struct stud list[], int v); 
 void tatime(struct stud list[], int v); 
  
 int main() 
 { 
     struct stud data[20]; 
     int n,i;
	 char c='n'; 
     do 
 	{ 
     printf("enter the number of students to eat : "); 
     scanf("%d", &n); 
     acpt(data, n); 
     schl(data, n); 
     wtime(data,n); 
     tatime(data,n); 
     disp(data, n); 
     printf("do you want to continue ? press 'y' :");
     scanf("%s",&c);
     }
     while(c=='y');
     return 0;
 }  
  
 void acpt(struct stud list[80], int x) 
 { 
     int i; 
     for (i = 0; i < x; i++) 
     { 
         printf("\n\nEnter student%d name : ",i+1); 
         scanf("%s",&list[i].sname);
          
         printf("\nEnter Student id number : "); 
         scanf("%d", &list[i].sId); 
  
         printf("Enter the time taken for food : "); 
         scanf("%d", &list[i].fttime); 
     }  
 } 
  
 void disp(struct stud list[80], int x) 
 { 
     int i;
 	 int TWTime=0,TTATime=0; 
 	 float AVWTime,AVTATime;
     printf("\n\n\t\t\tAccording to LRTF\n"); 
     printf("\n\t\t\t|-------------------------------------------------------------------------------|"); 
     printf("\n\t\t\t|Student name\tStudent id\tFoodtakenTime\tWaitingTime\tTurnaroundTime  |"); 
     printf("\n\t\t\t|-------------------------------------------------------------------------------|");     
     for (i = 0; i < x; i++) 
     { 
         printf("\n\t\t\t|%s\t\t%d\t\t%d\t\t%d\t\t%d\t\t|",list[i].sname,list[i].sId, list[i].fttime,list[i].wtime,list[i].tatime); 
         printf("\a\n\t\t\t|-------------------------------------------------------------------------------|"); 
 		TWTime= TWTime+list[i].wtime; 
 		TTATime= TTATime+list[i].tatime; 
 		AVWTime=TWTime/x;
 		AVTATime=TTATime/x;
 		
 	}  
 	printf("\n\n\t\t\tTotal Waiting Time is: = %d",TWTime); 
 	printf("\n\t\t\tTotal Turn around Time is: = %d\n\n",TTATime); 
 	printf("\n\n\t\t\tAverage Waiting Time is: = %f",AVWTime); 
 	printf("\n\t\t\tAverage Turn around Time is: = %f\n\n",AVTATime); 
 } 
  
 void schl(struct stud list[80], int x) 
 { 
     int a, b; 
     struct stud key; 
      
     for (a = 0; a < x - 1; a++) 
     { 
         for (b = 0; b < (x - 1-a); b++) 
         { 
             if (list[b].fttime < list[b + 1].fttime) 
             { 
                 key = list[b]; 
                 list[b] = list[b + 1]; 
                 list[b + 1] = key; 
             }  
             else 
			 if(list[b].fttime == list[b + 1].fttime) 
             { 
             	if(list[b].sId > list[b + 1].sId) 
             	{ 
             	 key = list[b]; 
                 list[b] = list[b + 1]; 
                 list[b + 1] = key; 
                 } 
 			} 
         } 
     } 
 } 
  
  
 void wtime(struct stud list[80], int v) 
 { 
 	int b; 
     list[0].wtime=0; 
     for(b=1;b<v;b++) 
     { 
         list[b].wtime=list[b-1].wtime+list[b-1].fttime; 
     } 
 } 
  
  
 void tatime(struct stud list[80], int v) 
 { 
 	int b; 
      
     for(b=0;b<v;b++) 
     { 
         list[b].tatime=list[b].wtime+list[b].fttime; 
     } 
 } 

