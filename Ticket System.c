/* Name: TING CHUNG HIENG Student ID: 20410848 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 40

struct visitData{
char *SrNo;
char *ticketNo;
char *Name;
char *ID;
};

struct ticket{
    struct visitData visitor;
    struct ticket *nextPtr;
};

char *name[30], *id[20];
char choice, local, idnum[20], fullname[30], ticketno[50];
int srno, s;
struct ticket* head=0;

void addnew(struct ticket **head, char *name, char local, char *id){
    FILE *out = 0;
    out = fopen("output.txt","a");


    struct ticket *newnode=(struct ticket*)malloc(sizeof(struct ticket));
    struct ticket *last = head;
    //struct ticket **head;

    char *id1, *temp, *tct;
    int a,length,i=0,j=0,n[30];
    char *convert={0};
    char no[50]={0};
    srno++;
    if(local=='Y'||local=='y')
    {
        id1=(char*)malloc(20);
        strcpy(id1,"IC");
        id1=(char*)realloc(id1,20);
        strcat(id1,id);
    }
    else
    {
        id1=(char*)malloc(20);
        strcpy(id1,"PASS");
        id1=(char*)realloc(id1,20);
        strcat(id1,id);
    }
    id1[strcspn(id1,"\r\n")]='\0';
    tct=(char*)malloc(100);
    temp=(char*)malloc(30);
    strcpy(temp,name);
    convert=(char*)malloc(30);
    if(strlen(temp)>=6)
    {
        for(i=0; i<6; i++)
        {
            convert[i]=temp[i];
        }
    }
    else
    {
        while(i<6-strlen(temp))
        {
            convert[i]=' ';
            i++;
        }
        while(j<strlen(temp))
        {
            convert[i]=temp[j];
            i++;
            j++;
        }
    }
    for(i=0; i<30; i++)
    {
        if(temp[i]==' ')
            temp[i]='_';
        if(temp[i]=='\n')
            temp[i]='\0';
    }
    int k=0;
    for(k=0; k<6; k++)
    {
        a=(int)*convert;
        convert++;
        n[k]=a;
    }
    if(srno<=9)
    {
        n[k]=0;
        n[k+1]=srno;
        k++;
    }
    else
    {
        n[k]=srno;
    }
    for(j=0; j<=k; j++)
    {
        sprintf(&no[strlen(no)],"%d", n[j]);
    }
    strcpy(tct, no);
    tct[strcspn(tct, "\r\n")]='\0';



    printf("\nThe information of the visitor %s is recorded.\n", temp);
    fprintf(out, "The information of the visitor %s is recorded.\n\n",temp);

    newnode -> visitor.SrNo = srno;
    newnode -> visitor.ticketNo = tct;
    newnode -> visitor.Name = temp;
    newnode -> visitor.ID = id1;
    newnode -> nextPtr = 0;
    printf("\n%02d %s %s %s\n", newnode -> visitor.SrNo, newnode -> visitor.ticketNo, newnode -> visitor.Name, newnode -> visitor.ID);



    if(*head == 0)
    {
        *head = newnode;
        fclose(out);
    }
    else {
    last=*head;
    while(last -> nextPtr!= 0)
    {
        last = last -> nextPtr;
    }
    last -> nextPtr = newnode;}

    Tickets(*head);

    fclose(out);
    return;


}

void searchTicketNo(struct ticket *head, char *data){
    struct ticket* find = head;
    int i, ticketno;
    FILE *out = 0;
    out = fopen("output.txt","a");

        while(find!= 0){

        ticketno = strcmp(find -> visitor.ticketNo, data);

        if(ticketno == 0)
            {
            printf("\nThe following record of the visitor is found:\n");
            fprintf(out, "The following record of the visitor is found:\n");
            printf("\n%02d %s %s %s\n", find -> visitor.SrNo, find -> visitor.ticketNo, find -> visitor.Name, find -> visitor.ID);
            fprintf(out, "\n%02d %s %s %s\n", find -> visitor.SrNo, find -> visitor.ticketNo, find -> visitor.Name, find -> visitor.ID);
            i++;
            }
        find = find -> nextPtr;
        }
        if(i == 0){
            printf("\nTicket number %s not found\n",data);
            fprintf(out, "Ticket number %s not found\n",data);
        }
    fclose(out);

}

void searchFullName(struct ticket *head, char *data){
    struct ticket* find = head;
    int i=0, fullname;
    FILE *out = 0;
    out = fopen("output.txt","a");

        while(find!= 0){

        fullname = strcasecmp(find -> visitor.Name, data);

        if(fullname == 0)
            {
                if(i == 0){
                    printf("\nThe following record of the visitor is found:\n");
                    fprintf(out, "\nThe following record of the visitor is found:\n\n");
                    i++;
                }

            printf("%02d %s %s %s\n", find -> visitor.SrNo, find -> visitor.ticketNo, find -> visitor.Name, find -> visitor.ID);
            fprintf(out, "%02d %s %s %s\n", find -> visitor.SrNo, find -> visitor.ticketNo, find -> visitor.Name, find -> visitor.ID);
            i++;
            }
        find = find -> nextPtr;
        }
        if(i == 0){
            printf("\nName %s not found\n", data);
            fprintf(out, "Name %s not found\n", data);
        }
    fclose(out);
}


void searchID(struct ticket *head, char *data){
    struct ticket* find = head;
    int i, idnum;
    FILE *out = 0;
    out = fopen("output.txt","a");

    while(find!= 0){

        idnum = strcmp(find -> visitor.ID, data);

        if(idnum == 0)
            {
            printf("\nThe following record of the visitor is found:\n");
            fprintf(out, "\nThe following record of the visitor is found:\n");
            printf("\n%02d %s %s %s\n", find -> visitor.SrNo, find -> visitor.ticketNo, find-> visitor.Name, find -> visitor.ID);
            fprintf(out, "\n%02d %s %s %s\n", find -> visitor.SrNo, find -> visitor.ticketNo, find -> visitor.Name, find -> visitor.ID);
            i++;
            }
        find = find -> nextPtr;
        }
        if(i == 0)
        {
            printf("\nID %s not found\n", data);
            fprintf(out, "ID %s not found\n", data);
        }
    fclose(out);
}

void deleteTicketNo(char *data)
{
    int ticketno;
    struct ticket *find = head;
    struct ticket *newnode = head;
    FILE *out = 0;
    out = fopen("output.txt","a");

    while(find!= 0){
        ticketno = strcmp(find -> visitor.ticketNo, data);

        if(ticketno == 0){
            if(find!= newnode)
            {
                newnode -> nextPtr = find -> nextPtr;
                free(find);
                }
            else
            {
                head = head -> nextPtr;
                free(find);
            }

            printf("The visitor with Ticket No.: %s, information is deleted.\n", data);
            fprintf(out, "\nThe visitor with Ticket No.: %s, information is deleted.\n", data);
            fclose(out);

            return;

        }
        newnode = find;
        find = find -> nextPtr;

    }
    printf("Ticket No. %s not found.\n", data);
    fprintf(out, "Ticket No. %s not found.\n", data);
    Tickets(head);
    fclose(out);

}
void deleteFullName(char *data){
    int fullname, i=0;
    char idnum[20];
    struct ticket *find = head;
    struct ticket *newnode = head;
    struct ticket *temp = head;
    struct ticket *temp2 = head;
    FILE *out = 0;
    out = fopen("output.txt","a");
    for(i=0; i<30; i++)
    {
        if(data[i]==' ')
            data[i]='_';
        if(data[i]=='\n')
            data[i]='\0';
    }

        i=0;
        while(find!= 0){
        fullname = strcasecmp(find -> visitor.Name, data);

            if(fullname == 0){
                i++;
            }

                find = find -> nextPtr;
            }

        if(i<2){

        while(temp!= 0){
            fullname = strcasecmp(temp -> visitor.Name, data);
            if(fullname == 0){
                if(temp!= temp2){
                    temp2 -> nextPtr = temp -> nextPtr;
                    free(temp);

                }
                else{

                    head = head -> nextPtr;
                    free(temp);
                }
                printf("The visitor: %s information is deleted\n", data);
                fprintf(out, " The visitor: %s information is deleted\n",data);


                fclose(out);
                return;
            }
            }

            }


        else{
            find = head;
            printf("\nThe following visitors have same names, Please enter the ID to deleted:\n");
            fprintf(out, "\nThe following visitors have same names, Please enter the ID to deleted:\n\n");
            while(newnode!= 0){
                fullname = strcasecmp(newnode -> visitor.Name, data);
                if(fullname == 0){
                    printf("\n%02d %s %s %s\n", newnode -> visitor.SrNo, newnode -> visitor.ticketNo, newnode -> visitor.Name, newnode -> visitor.ID);
                    }
                newnode = newnode -> nextPtr;
                }
            printf("\nLocal visitor should enter IC--------\n");
            printf("International visitor should enter PASS--------\n");
            printf("Enter ID number: \n");
            fclose(out);
            scanf("%*c");
            scanf("%[^\n]", idnum);
            deleteID(idnum);
            Tickets(head);
            fclose(out);
            return;
            }

    Tickets(head);
    printf("Full name %s is not found !!!\n", data);
    fprintf(out,"Full name %s is not found !!!\n", data);
    fclose(out);

}

void deleteID(char *data){
    int idnum, i;
    struct ticket *find = head;
    struct ticket *newnode = head;
    FILE *out = 0;
    out = fopen("output.txt","a");
    while(find!= 0){
        idnum = strcmp(find -> visitor.ID, data);

        if(idnum == 0){
            i++;
            if(find != newnode){
                newnode -> nextPtr = find -> nextPtr;
                free(find);
            }
            else{
                head = head -> nextPtr;
                free(find);
            }
            printf("The visitor with ID: %s, information is deleted.\n", data);
            fprintf(out, "\nThe visitor with ID: %s, information is deleted.\n", data);
            fclose(out);



        }
        newnode = find;
        find = find -> nextPtr;

    }
    Tickets(head);
    if(i=0){

    printf("ID %s is not found !!!\n", data);
    fprintf(out, "ID %s is not found !!!\n", data);
    fclose(out);
}
}

void display()
{
    FILE *out = 0;
    out = fopen("output.txt","a");
    FILE *output = 0;
    output = fopen("Tickets.txt","w");
    struct ticket *find = head;
    int i;
    while(find!= 0)
    {
        find = find -> nextPtr;
        i++;
    }
    find = head;
    printf("Total visitors:%d\n", i);
    fprintf(out, "Total visitors:%d\n", i);
    while(find!= 0)
    {
        printf("0%d %s %s %s\n",find -> visitor.SrNo, find -> visitor.ticketNo, find -> visitor.Name,find -> visitor.ID);
        fprintf(out, "0%d %s %s %s\n",find -> visitor.SrNo, find -> visitor.ticketNo, find -> visitor.Name,find -> visitor.ID);
        fprintf(output, "\n%02d %s %s %s\n", find -> visitor.SrNo, find -> visitor.ticketNo, find -> visitor.Name, find -> visitor.ID);
        find = find -> nextPtr;
        i++;
    }
    fclose(out);
    fclose(output);
}

void original()
    {
    struct ticket *find = head;
    int i, j = 1;
    while(find -> nextPtr!= 0)
    {
        find = find -> nextPtr;
        j++;
    }


    for(i=0; i<j; i++)
    {
    swap2();

    }
}

void swap2()
{
struct ticket *find = head;
char *k;
while(find -> nextPtr!= 0)
        {

            if(find -> visitor.SrNo > find -> nextPtr -> visitor.SrNo)
            {
                k = find -> visitor.Name;
                find -> visitor.Name = find -> nextPtr -> visitor.Name;
                find -> nextPtr -> visitor.Name =k;

                k = find -> visitor.SrNo;
                find -> visitor.SrNo = find -> nextPtr -> visitor.SrNo;
                find -> nextPtr -> visitor.SrNo = k;


                k = find -> visitor.ID;
                find -> visitor.ID = find -> nextPtr -> visitor.ID;
                find -> nextPtr -> visitor.ID = k;


                k = find -> visitor.ticketNo;
                find -> visitor.ticketNo = find -> nextPtr -> visitor.ticketNo;
                find -> nextPtr -> visitor.ticketNo = k;

            }

            find = find -> nextPtr;
        }
}

void ascending()
{

    FILE *out= 0;
    out=fopen("output.txt","a");
    struct ticket *find = head;
    int i,j = 1;
    while(find -> nextPtr != 0)
    {
        find = find -> nextPtr;
        j++;
    }



    for(i=0; i<j; i++)
    {
        swap1();
    }
    find = head;
    //display the sorted linked list
    while(find!= 0)
    {
        printf("%02d %s %s %s\n", find -> visitor.SrNo, find -> visitor.ticketNo, find -> visitor.Name, find -> visitor.ID);
        fprintf(out, "%02d %s %s %s\n", find -> visitor.SrNo, find -> visitor.ticketNo, find -> visitor.Name, find -> visitor.ID);

        find = find -> nextPtr;
    }
    fclose(out);

}

void swap1()
{
    struct ticket *find = head;
    char *k;
    while(find -> nextPtr != 0)
        {

        if(strcmp(find -> visitor.Name, find -> nextPtr -> visitor.Name) > 0)
            {
                k = find -> visitor.Name;
                find -> visitor.Name = find -> nextPtr -> visitor.Name;
                find -> nextPtr -> visitor.Name =k;

                k = find -> visitor.SrNo;
                find -> visitor.SrNo = find -> nextPtr -> visitor.SrNo;
                find -> nextPtr -> visitor.SrNo = k;


                k = find -> visitor.ID;
                find -> visitor.ID = find -> nextPtr -> visitor.ID;
                find -> nextPtr -> visitor.ID = k;


                k = find -> visitor.ticketNo;
                find -> visitor.ticketNo = find -> nextPtr -> visitor.ticketNo;
                find -> nextPtr -> visitor.ticketNo = k;

            }
            //to next node
            find = find -> nextPtr;
        }

}


void Tickets(struct ticket *head)
{
    FILE *output = 0;
    output=fopen("Tickets.txt","w");
    struct ticket *find = head;

    find = head;
        do
        {
            fprintf(output, "%02d %s %s %s\n", head -> visitor.SrNo, head -> visitor.ticketNo, head -> visitor.Name, head -> visitor.ID);
            head = head -> nextPtr;
        }while(head!= 0);

    fclose(output);
}
int main(void){
    while(1)
    {
        printf("\n1. Add a new visitor information which must have the following: (Sr No., Full Name, ID (IC or passport), Ticket No)\n");
        printf("2. Search visitor information based on Ticket No, Name, or ID\n");
        printf("3. Delete the visitor information based on ticket number\n");
        printf("4. Delete the visitor information based on full name\n");
        printf("5. Delete the visitor information based on ID\n");
        printf("6. Display Total No of tickets sold\n");
        printf("7. Exit\n");
        printf("\nEnter 1-7 to continue your action:\n");
        scanf("%d", &choice);

    switch(choice)
{
    case 1:
        printf("\nEnter your name: \n");
        scanf("%*c");
        scanf("%[^\n]", name);
        printf("\nAre you a local visitor?(Y/y-yes others-no)\n");
        scanf(" %c", &local);
        printf("\nEnter your ID number:\n");
        scanf("%s", id);
        addnew(&head, name, local, id);
        break;

    case 2:
        printf("\n1.Search using Ticket No \n");
        printf("2.Search using Full Name      \n");
        printf("3.Search using IC or passport number       \n");
        printf("\nEnter 1-3 to continue: \n");
        scanf("%d", &s);

        switch(s)
        {
        case 1:
            printf("\nEnter Ticket No: ");
            scanf("%s", ticketno);
            searchTicketNo(head, ticketno);
            break;

        case 2:
            printf("\nEnter Full Name: ");
            scanf("%*c");
            scanf("%[^\n]", fullname);
            for(int i=0; i<30; i++)
            {
                char temp[30];
                if(fullname[i] == ' ')
                fullname[i] = '_';
                if(temp[i] == '\n')
                temp[i] = '\0';
                }
            searchFullName(head, fullname);
            break;

        case 3:
            printf("\nLocal visitor should enter IC--------\n");
            printf("International visitor should enter PASS--------\n");
            printf("Enter ID number: \n");
            scanf("%s", idnum);
            searchID(head, idnum);
            break;
        }
    break;

    case 3:
        printf("\nEnter ticket number for deleting information:\n");
        scanf("%*c");
        scanf("%[^\n]", ticketno);
        deleteTicketNo(ticketno);
    break;

    case 4:
        printf("\nEnter Full Name for deleting information:\n");
        scanf("%*c");
        scanf("%[^\n]", fullname);
        deleteFullName(fullname);
    break;

    case 5:
        printf("\nEnter ID for deleting information:\n");
        scanf("%*c");
        scanf("%[^\n]", idnum);
        deleteID(idnum);
    break;

    case 6:
        printf("Do you want to display in ascending order?(Y/y-yes others-no)\n");
        scanf(" %c", &choice);
        if(choice == 'Y'||choice=='y'){
            ascending();
            original();
        }
        else{
            display();
        }
    break;


    case 7:
        return 0;
    break;
}
}
}


