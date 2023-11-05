#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct pt
{
    char username[50];
    int pin;
    int typ;

};
struct pt e;

long int size = sizeof(e);

FILE *myfp, *myft;

void accaddrecord()
{

    fseek(myfp, 0, SEEK_END);

    printf("\nEnter USERNAME : ");
    scanf("%s", e.username);

    printf("\nEnter PIN : ");
    scanf("%d", &e.pin);

    printf("\nEnter ACCT NO : ");
    scanf("%d", &e.typ);

    fwrite(&e, size, 1, myfp);
}

void accdeleterecord()
{

    char usname[50];
    printf("\nEnter USERNAME to delete : ");
    scanf("%s", usname);

    myft = fopen("temp.txt", "wb");
    rewind(myfp);

    while (fread(&e, size, 1, myfp) == 1)
    {
        if (strcmp(e.username, usname) != 0)
            fwrite(&e, size, 1, myft);
    }

    fclose(myfp);
    fclose(myft);
    remove("data.txt");
    rename("temp.txt", "data.txt");
    myfp = fopen("data.txt", "rb+");
}

void accdisplayrecord()
{
    rewind(myfp);

    while (fread(&e, size, 1, myfp) == 1)
        printf("\n%s\t%d\t%d",
               e.username, e.pin, e.typ);

    printf("\n\n\n\t");
}

void accmodifyrecord()
{

    char usname[50];

    printf("\nEnter USERNAME to modify : ");
    scanf("%s", usname);

    rewind(myfp);
    while (fread(&e, size, 1, myfp) == 1)
    {
        if (strcmp(e.username, usname) == 0)
        {
            printf("\nEnter New USERNAME : ");
            scanf("%s", e.username);

            printf("\nEnter New PIN : ");
            scanf("%d", &e.pin);

            printf("\nEnter New ACCT NO : ");
            scanf("%d", &e.typ);

            fseek(myfp, -size, SEEK_CUR);
            fwrite(&e, size, 1, myfp);
            break;
        }
    }
}

struct re
{
    char name[50];
    int age;
    char time[6];
};
struct re f;

long int size1 = sizeof(f);

FILE *myfp1, *myft1;

void recepaddrecord()
{

    fseek(myfp1, 0, SEEK_END);

    printf("\nEnter Patient Name : ");
    scanf("%s", f.name);

    printf("\nEnter Patient Age : ");
    scanf("%d", &f.age);

    printf("\nEnter Appointment Time : ");
    scanf("%s", f.time);

    fwrite(&f, size1, 1, myfp1);
}

void recepdeleterecord()
{

    char ptname[50];
    printf("\nEnter patient name to delete : ");
    scanf("%s", ptname);

    myft1 = fopen("temp1.txt", "wb");
    rewind(myfp1);

    while (fread(&f, size1, 1, myfp1) == 1)
    {
        if (strcmp(f.name, ptname) != 0)
            fwrite(&f, size1, 1, myft1);
    }

    fclose(myfp1);
    fclose(myft1);
    remove("data1.txt");
    rename("temp1.txt", "data1.txt");
    myfp1 = fopen("data1.txt", "rb+");
}

void recepdisplayrecord()
{
    rewind(myfp1);

    while (fread(&f, size1, 1, myfp1) == 1)
        printf("\n%s\t%d\t%s",
               f.name, f.age, f.time);

    printf("\n\n\n\t");
}

void recepmodifyrecord()
{

    char ptname[50];

    printf("\nEnter employee name"
           " to modify : ");
    scanf("%s", ptname);

    rewind(myfp1);
    while (fread(&f, size1, 1, myfp1) == 1)
    {
        if (strcmp(f.name, ptname) == 0)
        {
            printf("\nEnter New Appointment Time : ");
            scanf("%s", f.time);

            fseek(myfp1, -size1, SEEK_CUR);
            fwrite(&f, size1, 1, myfp1);
            break;
        }
    }
}

void receptionist()
{
    int choice;
    myfp1 = fopen("data1.txt", "rb+");
    if (myfp1 == NULL)
    {
        myfp1 = fopen("data1.txt", "wb+");
        if (myfp1 == NULL)
        {
            printf("\nCannot open file...");
            exit(1);
        }
    }
    while (1)
    {

        printf("\n1. ADD RECORD\n");

        printf("\n2. DELETE RECORD\n");

        printf("\n3. DISPLAY RECORDS\n");

        printf("\n4. MODIFY RECORD\n");

        printf("\n5. EXIT\n");

        printf("\nENTER YOUR CHOICE...\n");

        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            recepaddrecord();
            break;

        case 2:
            recepdeleterecord();
            break;

        case 3:
            recepdisplayrecord();
            break;

        case 4:
            recepmodifyrecord();
            break;

        case 5:
            fclose(myfp1);
            exit(0);
            break;

        default:
            printf("\nINVALID CHOICE...\n");
        }
    }
}

struct bi
{
    char name[50];
    char medname[50];
    int quantity;
    int amount;
};
struct bi g;

long int size2 = sizeof(g);

FILE *myfp3;

void supplier()
{

    fseek(myfp3, 0, SEEK_END);

    printf("Name : ");
    scanf("%s", g.name);

    printf("\nEnter Medicine Name : ");
    scanf("%s", g.medname);

    printf("\nEnter quantity : ");
    scanf("%d", &g.quantity);

    printf("\nEnter M.R.P. of medicine : ");
    scanf("%d", &g.amount);

    fwrite(&g, size2, 1, myfp3);
}

void printstock()
{
    rewind(myfp3);

    while (fread(&g, size2, 1, myfp3) == 1)
        printf("\n%s\t%s\t%d\t%d", g.name, g.medname, g.quantity, g.amount);
    printf("\n\n\n\t");
}

void costumer()
{

    char mname[50], cname[50];
    int q;
    int tamount;
    printf("\nName : ");
    scanf("%s", cname);
    printf("\nMedicine name : ");
    scanf("%s", mname);
    rewind(myfp3);
    while (fread(&g, size2, 1, myfp3) == 1)
    {
        if (strcmp(g.medname, mname) == 0)
        {
            printf("\nEnter Quantity : ");
            scanf("%d", &q);
            if (q > g.quantity)
            {
                printf("\nQuantity not available.");
            }
            else
            {
                g.quantity = g.quantity - q;
                tamount = q * g.amount;
            }
            printf("\n\nAMOUNT TO BE PAID = %d", tamount);
            fseek(myfp3, -size2, SEEK_CUR);
            fwrite(&g, size2, 1, myfp3);
            break;
        }
    }
}

void billing()
{

    int amount;
    int choice;
    myfp3 = fopen("data3.txt", "rb+");

    if (myfp3 == NULL)
    {
        myfp3 = fopen("data3.txt", "wb+");
        if (myfp3 == NULL)
        {
            printf("\nCannot open file...");
            exit(1);
        }
    }

    while (1)
    {

        printf("\nEnter 1 for supplier , 2 for customer , 3 to display record and 4 for EXIT.\n");

        printf("\nENTER YOUR CHOICE...\n");

        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            supplier();
            break;

        case 2:
            costumer();
            break;

        case 3:
            printstock();
            break;

        case 4:
            fclose(myfp3);
            exit(0);
            break;

        default:
            printf("\nINVALID CHOICE...\n");
        }
    }
}

int main()
{
    char mainacc[]="Mainuser",askus[50];
    int mainpin=16,askpin,typ;
    int choice;
    myfp = fopen("data.txt", "rb+");
    if (myfp == NULL)
    {
        myfp = fopen("data.txt", "wb+");
        if (myfp == NULL)
        {
            printf("\nCannot open file...");
            exit(1);
        }
    }
    printf("\n ENTER USERNAME = ");
    scanf("%s",askus);
    printf("\n ENTER PIN = ");
    scanf("%d",&askpin);
    if (strcmp(askus,mainacc)==0){
    while (1)
    {

        printf("\n1. ADD ACCOUT\n");

        printf("\n2. DELETE ACCOUNT\n");

        printf("\n3. DISPLAY ACCOUNT\n");

        printf("\n4. MODIFY ACCOUNT\n");

        printf("\n5. EXIT\n");

        printf("\nENTER YOUR CHOICE...\n");

        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            accaddrecord();
            break;

        case 2:
            accdeleterecord();
            break;

        case 3:
            accdisplayrecord();
            break;

        case 4:
            accmodifyrecord();
            break;

        case 5:
            fclose(myfp);
            exit(0);
            break;

        default:
            printf("\nINVALID CHOICE...\n");
        }
    }
    }
    else{
        rewind(myfp);

        while (fread(&e, size, 1, myfp) == 1)
        {
            if (strcmp(e.username, askus) == 0 && askpin==e.pin){
                typ=e.typ;
                printf("%d",typ);
                switch (typ){
                    case 1:
                        receptionist();
                        break;
                    case 2:
                        billing();
                        break;

                }

                break;
        }

    }
    return 0;
}
}

