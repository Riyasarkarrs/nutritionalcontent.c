#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct content
{
    int id;
    char name[100];
    int carbs;
    int transfat;
    int protein;
    int saturated_fat;
    struct content *next;
}* head;
void insert(int id, char* name, int carbs, int transfat, int protein, int saturated_fat)
{
    struct content * content= (struct content *) malloc(sizeof(struct content));
    content->id = id;
    strcpy(content->name, name);
    content->carbs = carbs;
    content->transfat = transfat;
    content->protein = protein;
    content->saturated_fat = saturated_fat;
    content->next = NULL;
    if(head==NULL)
    {
        head = content;
    }
    else
    {
        content->next = head;
        head = content;
    }
}
void search(int id)
{
    struct content * temp=head;
    while(temp!=NULL)
    {
        if(temp->id==id)
        {
            printf("id no.:%d\n", temp->id);
            printf("name: %s\n", temp->name);
            printf("carbs:%d\n", temp->carbs);
            printf("transfat:%d\n", temp->transfat);
            printf("protein;%d\n", temp->protein);
            printf("saturated fat:%d\n", temp->saturated_fat);
            return;
        }
        temp = temp->next;
    }
    printf("content with %d id has no records\n", id);
}
void update(int id)
{
    struct content * temp = head;
    while(temp!=NULL)
    {
        if(temp->id==id)
        {
            printf("record with %d id is there \n", id);
            printf("enter a new name:\n");
            scanf("%s", &temp->name);
            printf("enter carbs:\n");
            scanf("%d", &temp->carbs);
            printf("enter transfat: \n");
            scanf("%d", &temp->transfat);
            printf("enter protein: \n");
            scanf("%d", &temp->protein);
            printf("enter saturated fat: \n");
            scanf("%d", &temp->saturated_fat);
            return;

        }
        temp = temp->next;
    }
    printf("content with %d id has no records", id);
}
void Delete(int id)
{
    struct content*temp1=head;
    struct content*temp2=head;
    while(temp1!=NULL)
    {
        if(temp1->id==id){
        printf("content with id number %d is recorded\n", id);
            if(temp1==temp2)
            {
                head = head->next;
                free(temp1);
            }
            else
            {
                temp2->next = temp1->next;
                free(temp1);
            }
            printf("content is successfully deleted\n");
            return;
        }
        temp2=temp1;
        temp1=temp1->next;
    }
    printf("content with id no. %d has not been recorded yet \n");
}
void display()
{
    struct content * temp =  head;
    while(temp!=NULL)
    {
        printf("id no:%d \n", temp->id);
        printf("name: %s \n", temp->name);
        printf("carbs: %d \n", temp->carbs);
        printf("trans fat: %d \n", temp->transfat);
        printf("protein: %d \n", temp->protein);
        printf("saturated fat: %d \n", temp->saturated_fat);
        temp = temp->next;
    }
}
int main()
{
    head = NULL;
    int choice;
    int id;
    char name[100];
    int carbs;
    int transfat;
    int protein;
    int saturated_fat;

    printf("1.INSERT CONTENT\n2.SEARCH FOR ANY CONTENT\n3.DELETION OF ANY CONTENT\n4.UPDATION OF THE GIVEN CONTENT\n5.DISPLAY YOUR CONTENT");
    do
    {
        printf("\n ENTER YOU CHOICE(CONTENTS SHOULD BE RECORDED IN GRAMS): ");
        scanf("%d",&choice);
        switch(choice)
        {
                case 1:
                printf("enter id: \n");
                scanf("%d",&id);
                printf("enter name: \n");
                scanf("%s",&name);
                printf("enter carbs: \n");
                scanf("%d",&carbs);
                printf("enter transfat: \n");
                scanf("%d",&transfat);
                printf("enter protein: \n");
                scanf("%d",&protein);
                printf("enter saturated fat: \n");
                scanf("%d",&saturated_fat);
                insert(id,name,carbs,transfat,protein,saturated_fat);
                break;
            case 2:
                printf("enter the id: ");
                scanf("%d",&id);
                search(id);
                break;
            case 3:
                printf("enter the id: ");
                scanf("%d",&id);
                Delete(id);
                break;
            case 4:
                printf("enter the id: ");
                scanf("%d",&id);
                update(id);
                break;
            case 5:
                display();
                break;
        }

    }while(choice!=0);

}
