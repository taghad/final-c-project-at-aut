///Hangman(final project) created by mohamad hasan taghadosi
#include<stdio.h>    /*Header file declaration*/

#include<string.h>   /*<string.h> for strcmp();,strlen(); functions use*/

#include<stdlib.h>
#include<windows.h>
int i;

struct node
{
    char kalame[51] ;
    struct node * next ;

};
void printlist( struct node * head )
{
    while( ( head ) != NULL )
    {
        printf("%s\n",head -> kalame) ;
        head = head -> next;
    }
}
void copy(char * from,char * to)   /*copy kalame az array to array ddigar*/
{
    int i = strlen(from) , j ;
    for( j = 0 ; j < i ; j++ )
        to [ j ] = from [ j ] ;
}
struct node * create_node()   /*create new node*/
{
    struct node *gogo ;
    gogo = ( struct node * ) malloc ( sizeof ( struct node ) ) ;
    gogo -> next = NULL ;
    return gogo ;


}
struct node *head ;

struct node * usefile(FILE * fp)   /*use one topic and create linklist*/
{
    head = (struct node *) malloc ( sizeof ( struct node ) ) ;
    struct node *current ;
    current = head ;


    fscanf(fp,"%s",current -> kalame) ;

    while( !feof ( fp ) )
    {
        current -> next = create_node() ;

        current -> next -> next = NULL ;
        current = current -> next ;

        fscanf(fp,"%s",current -> kalame);
        i++ ;
    }

    return head;

}
int toolelist(struct node *head)
{
    int i=1;
    while(1)
    {

        if(head->next==NULL)
            break;
        head=head->next;
        i++ ;
        //printf("%d\n",i);
    }
    return i;


}

int random(int a)
{

    int p,o,shomare;
    p = rand() ;
    o = RAND_MAX ;
    shomare = (int)( ( p * a / o ) ) ;
    return shomare ;

}
char *entekhabe_kalame(struct node * tmp   )
{
    //printlist(head) ;
    //printf("%d\n",toolelist(head)) ;
    struct node *cur ;
    char static word[51];
    //printf("%d\n",toolelist(head));

    int kodom = random(toolelist(head)) ;
    if(kodom==0)
    {
        cur = tmp ;
        strcpy(word,tmp->kalame) ;
        head=head->next ;
        free(tmp) ;
        return word ;
    }

    //printf("%d\n",random(toolelist(head))) ;

    //printf("%d\n",kodom);
    //printf("%s\n",tmp->kalame) ;
    //if(kodom==1)
    printf("adade entekhabi = %d\n",kodom) ;

    for(i=0;i<kodom;i++)
    {
        if(i==kodom-1)
        {
            cur=tmp ;
        }
        tmp = tmp ->next ;

    }
    strcpy(word , tmp->kalame);
    cur->next=tmp->next ;
    printf("kalame pak shode :%s\n",tmp->kalame) ;
    free(tmp) ;

    //printf("%s\n",word) ;
    printf("word is %s\n",word) ;

    return word ;
}
int bazi(char *word)
{
    int tool = strlen(word) , i ;
    char hads,wordcopy[51] ;
    for(i = 0;i<tool;i++)
        wordcopy[i]='-';
    wordcopy[i]='\0';
    int dorost = 0 , ghalat=0,bord=0 ;
    while(1)
    {
        printf("hadseto bzan dg ah\n");
        scanf("%c",&hads);
        fflush(stdin);
        for(i=0;i<tool;i++)
        {
            if(word[i]==hads)
            {
                wordcopy[i]=hads ;
                dorost++;
            }
        }
        printf("%s\n",wordcopy);

        if(dorost==0)
        {
            ///code ghargh shodan

       // system("C:\ProgramData\Microsoft\Windows\Start Menu\Programs\VideoLAN\VLC.exe" baoon.mp4) ;


            ghalat++;
        }
        dorost=0 ;
        if(ghalat==5)
        {
            printf("%s\nto bakhT :(\n",word);

            return 0;
        }
        for(i=0;i<tool;i++)
            if(wordcopy[i]=='-')
                bord++;
        if(bord==0)
        {
            printf("to borD  :)\n");
            return (3*tool-ghalat) ;
        }
        bord=0;
        }
        printf("%s\n",wordcopy);

}
int  play_game(FILE *fp)
{
    struct node * head = usefile(fp) ;
    int emtiaz=0;
    int tool=toolelist(head);

    char word[51];
    while(tool!=0)
    {

    strcpy(word , entekhabe_kalame(head)) ;


    emtiaz += bazi(word);
    tool--;
    }
    return emtiaz;
}



int main()
{

    srand (time(NULL));
    int g=random(19);
    FILE *fp ;
    fp = fopen("gogo.txt","r") ;
    if( fp == NULL )
        return -1 ;

    printf("emtiaze in dast = %d\n",play_game(fp));
    printf("%s\n",head->kalame);
}





















