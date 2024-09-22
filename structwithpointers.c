#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main (){
    typedef struct studentinfo{
        char *name;
        int age;
        struct studentinfo *next;
    }studemt;
    studemt s1,*sp;
    sp=&s1;
    sp->name=malloc(sizeof(char)*20);
    strcpy(sp->name,"Mandy muse");
    sp->age=31;
    sp->next=malloc(sizeof(studemt));
    sp->next->name=malloc(sizeof(char)*20);
    strcpy(sp->next->name,"Jessa rhodes");
    sp->next->age=37;
    printf("%s\t%d\t%s\t%d",sp->name,sp->age,sp->next->name,sp->next->age);
    free(sp->name);
    free(sp->next->name);
    return 0;
}