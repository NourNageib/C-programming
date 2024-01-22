#include<stdio.h>
#include <stdlib.h>
#include<string.h>

//used functions
void add(int I,char nam[],int ag,char gen[] );
void printList();
int searchID(int id);
void slot(int id,char slott[],int cancel_code);
void printnode(int ii);
void editnode(int id_edit);
void cancel_reservation(int id);
char slot1[]="1. 2pm to 2:30pm";
char slot2[]="2. 2:30pm to 3pm";
char slot3[]="3. 3pm to 3:30pm";
char slot4[]="4. 4pm to 4:30pm";
char slot5[]="5. 4:30pm to 5:00pm";
int slot_no;



typedef struct patient new_patient;

struct patient
	{
		char name_[50];
		int age_;
		char gender_[10];
		int ID_;
		int cancel_;
		char slot_[50];
		new_patient *next;
	};

new_patient* head = NULL;

int main(void)
{
	int input1;char ad_us;
	int y=0;
	int age;
	char gender[10];
	int ID=0;
	int arr[5];
	int check;
	
	
	while(1)
	{
	int wrong_pass_counter=0;
	printf("Admin mode press A :: User mode press B:\n");
	scanf("%c",&ad_us);
	
			if(wrong_pass_counter==3)
			{
			printf("ONLY 3 trials are vaild \n");
			break;
			}
		
		switch(ad_us)
		{
			case 'A':
			{
			int password_ad;
			printf("Please enter password:\n");
			scanf("%d",&password_ad);
		    if(password_ad==1234)
			{
			
			printf(" If you want to add a new record press :1\n If you want to edit your record press:2\n if you want to reserve a slot with DR. press:3\n if you want to cancel a reservation press:4\n To print the list press:5 \n");
			scanf("%d",&input1);
			
				switch (input1)
				{
					char name[50];
					
					case 1:
					{
					printf("\nYour ID:");
					scanf("%d",&ID);
					//int f =searchID(ID);
					if (searchID(ID)==4)
					{
						printf("Your request is rejected this ID already exists:\n");
					}
					while(searchID(ID)!=4)
					{
					 if (searchID(ID)==1)
					 {
						 printf("THIS IS THE FIRST REECORD:\n");
					 }
					printf("You want to a add a new record:)\n");
					printf("Enter name: ");
					scanf("%s", name);
					printf("\nYour age:");
					scanf("%d",&age);
					printf("Enter gender: ");
                    scanf("%s", gender);
					add(ID,name,age,gender);
					printf("Node added!\n");
					break;
					}
					break;
					}
					
					
					case 2:
					{
					printf("\nYour ID:");
					scanf("%d",&ID);
					while(searchID(ID)==4)
					{
					    editnode(ID);
						printf("EDIT COMPLETED THANK YOU!\n");
						break;
					}
					if(searchID(ID)==0)
					{
						printf("ID DOESNOT EXIST!!\n");
					}
					}
					break;   
					
					
					case 3:
					{
						
						printf("THE AVALIABLE SLOTS WITH DR :\n%s\n%s\n%s\n%s\n%s.\nEnter number of required slot:",slot1,slot2,slot3,slot4,slot5);
						scanf("%d",&slot_no);
						int cancel=0;
						printf("Please enter your ID:");
						scanf("%d",&check);
						
						if (slot_no==1)
						{
						     cancel=1;
							 slot(check,slot1,cancel);
							 strncpy(slot1," BOOKED ",sizeof(slot1)/sizeof(slot1[1]));
						}
						else if(slot_no==2)
						{
						    cancel=2;
						    slot(check,slot2,cancel);
							strncpy(slot2," BOOKED ",sizeof(slot2)/sizeof(slot2[1]));
						}
						else if(slot_no==3)
						{
						    cancel=3;
						    slot(check,slot3,cancel);
							strncpy(slot3," BOOKED ",sizeof(slot3)/sizeof(slot3[1]));
						}
						else if(slot_no==4)
						{
						    cancel=4;
						    slot(check,slot4,cancel);
							strncpy(slot4," BOOKED ",sizeof(slot3)/sizeof(slot3[1]));
						}
						else if(slot_no==5)
						{
						    cancel=5;
						    slot(check,slot5,cancel);
							strncpy(slot5," BOOKED ",sizeof(slot3)/sizeof(slot3[1]));
						}
						
					
						
				        printf("YOUR RESERVATION IS COMPLETED:)\n ");
				        printnode(check);
				    }
					break;
						
					case 4:
					{
					    printf("You want to cancel your reservation! \n");
					    printf("Please enter your ID :\n");
					    scanf("%d",&ID);
					    cancel_reservation(ID);
					    break;
					}
						
					case 5:
					{
						printList();
						
					}
					break;
					
			}
			}
			

		    else if (1234!=password_ad)
			{
			printf("Please try again passord is not correct:\n");
			wrong_pass_counter++;
		    }
			break;
		}
		
		case 'B':
		{
			printf("ENTER PATIENT ID:\n");
			scanf("%d",&ID);
			int t =searchID(ID);
			if (t==4)
			{
				printnode(ID);
			}
			else 
			{
				printf("ID DOESNOT EXIST!\n");
			}
			
		
			break;
			
		}
		default: printf("Wrong entery\n");break;
		}
	}
	return 0;
}


void add(int I,char nam[],int ag,char gen[] )
{
	
	new_patient *temp;
	
	temp=(new_patient*)malloc(sizeof(new_patient));
	temp->age_=ag;
	temp->ID_=I;
	strcpy(temp->name_, nam);
	strcpy(temp->gender_, gen);
	
	if (head==NULL)
	{
		head=temp;
	}
	else 
	{
		temp->next=head;
		head=temp;
	}
		
}
void editnode(int id_edit)
{
    new_patient * p = head;
    int edit_key;
    if(id_edit==p->ID_)
    {
        printf(" Patient name is:%s\n Patient age is:%d\n Patient Gender is:%s\n", p->name_,p->age_,p->gender_);
        printf("To edit name press \"1\" \nTo edit age press \"2\" \nTo edit gender press \"3\"\n");
        scanf("%d",&edit_key);
        if(edit_key==1)
        {
            char name[40];
            printf("Enter New name:\n");
            scanf("%s", name);
            strcpy(p->name_, name);
            printf("EDIT NAME IS COMPLETED :)\n");
        }
        else if(edit_key==2)
        {
          int age;
          printf("Edit age:\n");
          scanf("%d",&age);
          p->age_=age;
          printf("EDIT AGE IS COMPLETED :)\n");
        }
        else if(edit_key==3)
        {
            char gender[40];
            printf("Edit gender:\n");
            scanf("%s", gender);
            strcpy(p->gender_, gender);
            printf("EDIT GENDER IS COMPLETED :)\n");  
        }
    }
    else if(p==NULL)
    {
        printf("CAN\'T EDIT LIST IS EMPTY :(\n");
    }
    
}
void printList()
{
	new_patient * p = head;
	if(NULL == head)
	{
		printf("List is empty\n");
	}
	else
	{
		while(NULL != p)
		{
			printf("Patient name is:%s\n", p->name_);
			printf("Patient gender is:%s\n", p->gender_);
			printf("Patient age is:%d\n", p->age_);
			printf("Patient ID is:%d\n", p->ID_);
			printf("Patient reservation is:%s\n", p->slot_);
			p = p -> next;
		}
	}
}
int searchID(int id)
{
	new_patient * p = head;
	int x = 0;
	
	if (NULL==head)
	{
		x=1;
	}
	
	else 
	{
		while(NULL != p)
		{
			if(id==p->ID_)
			{	
				x=4;
				break;
			}
			else
			{
			p=p->next;
			}
		}
	}
	return x;
}



void slot(int id,char slott[],int cancel_code)
{
	new_patient *p=head;
	
	
	if (NULL==head)
	{
		printf("List is empty\n");
	}
	
	else 
	{
		while(NULL != p)
		{
			if(id==p->ID_)
			{
				printf("RESERVATION COMPLETED THANK YOU!");
				p->cancel_=cancel_code;
				strcpy(p->slot_, slott);
				
				break;
			
			}
			else
			{
			p=p->next;
			if(p==NULL)
			{
			    printf("ID DOESNOT EXIST!!\n");
			}
			}
			
		}
	}
	
}

void printnode(int ii)
{
	new_patient *p=head;
	
	if (NULL==head)
	{
		printf("List is empty\n");
	}
	else 
	{
		while(NULL != p)
		{
			if(ii==p->ID_)
			{
			printf("Patient name is:%s\n", p->name_);
			printf("Patient gender is:%s\n", p->gender_);
			printf("Patient age is:%d\n", p->age_);
			printf("Patient reservation :%s\n", p->slot_);
			
			}
			break;
		}
	}
}

void cancel_reservation(int id)
{
    new_patient *p=head;
    int x=0;
    if(NULL==head)
    {
        printf("List is empty\n");
    }
    while(NULL != p)
		{
			if(id==p->ID_)
			{	
				x=4;
				break;
			}
			else
			{
			p=p->next;
			}
		}
	if(x==0)
	{
	    printf("ID DOESNOT EXIST!!!\n");
	}
	if(p->cancel_==1)
	{
	    printf("YOUR RESERVATION HAS BEEN SUCCESSFULLY CANCELED\n");
	    strncpy(slot1,"1. 2pm to 2:30pm",sizeof(slot1)/sizeof(slot1[1]));
	}
	else if(p->cancel_==2)
	{
	   printf("YOUR RESERVATION HAS BEEN SUCCESSFULLY CANCELED\n");
	   strncpy(slot2,"2. 2:30pm to 3pm",sizeof(slot1)/sizeof(slot1[1])); 
	}
	else if(p->cancel_==3)
	{
	   printf("YOUR RESERVATION HAS BEEN SUCCESSFULLY CANCELED\n");
	   strncpy(slot3,"3. 3pm to 3:30pm",sizeof(slot1)/sizeof(slot1[1])); 
	}
	else if(p->cancel_==4)
	{
	   printf("YOUR RESERVATION HAS BEEN SUCCESSFULLY CANCELED\n");
	   strncpy(slot4,"4. 4:00pm to 4:30pm",sizeof(slot1)/sizeof(slot1[1])); 
	}
	else if(p->cancel_==5)
	{
	   printf("YOUR RESERVATION HAS BEEN SUCCESSFULLY CANCELED\n");
	   strncpy(slot5,"5. 4:30pm to 5:00pm",sizeof(slot1)/sizeof(slot1[1])); 
	}
}









