///Hangman(final project) created by mohamad hasan taghadosi

#include<stdio.h>    /*Header file declaration*/

#include<string.h>   /*<string.h> for strcmp();,strlen(); functions use*/
#include<time.h>
#include<stdlib.h>
#include<windows.h>
#include<mmsystem.h>
int i, tedad ;

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
    int i = strlen(from), j ;
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
    current = head ;
    while(current->next->next!=NULL)
        current=current->next ;
    free(current->next) ;
    current->next = NULL ;

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
    tmp = head ;
   // printf("toolelist = %d\n",toolelist(head));

    int kodom = random(toolelist(head)) ;
    //printf("adade entekhabi = %d\n",kodom) ;
    if(kodom==0)
    {
        strcpy(word,tmp->kalame) ;
        head=head->next ;
        free(tmp) ;
        //printf("word is %s\n",word) ;
        return word ;
    }

    //printf("%d\n",random(toolelist(head))) ;

    //printf("%d\n",kodom);
    //printf("%s\n",tmp->kalame) ;
    //if(kodom==1)



    for(i=0; i<kodom; i++)
    {
        if(i==kodom-1)
        {
            cur=tmp ;
        }
        tmp = tmp ->next ;

    }
    strcpy(word, tmp->kalame);
    cur->next=tmp->next ;
    //printf("kalame pak shode :%s\n",tmp->kalame) ;
    free(tmp) ;

    //printf("%s\n",word) ;
    //printf("word is %s\n",word) ;

    return word ;
}
int bazi(char *word)
{
    int tool = strlen(word), i , q;
    char hads,wordcopy[51] ;
    for(i = 0; i<tool; i++)
        wordcopy[i]='-';
    wordcopy[i]='\0';
    int dorost = 0, ghalat=0,bord=0 ;
    while(1)
    {
        printf("tedad dafehaii ke mitooni eshtebah koni = %d\nhadsto bzan dg ah\n",5-ghalat);
        scanf("%c",&hads);
        fflush(stdin);
        if(hads == 'Q')
        {
            printf("mikhay edame bedi?1ro vared kon na 2 ro vared kon\n") ;
            scanf("%d",&q) ;
            fflush(stdin) ;
            if(q==2)
                exit(0) ;
            else
            {
                printf("hadseto bzan dg ah\n") ;
                scanf("%c",&hads) ;
                fflush(stdin) ;
            }
        }
        for(i=0; i<tool; i++)
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
            ghalat++;
            if(ghalat==1)
                system("part1.mp4");
            if(ghalat==2)
                system("part2.mp4");
            if(ghalat==3)
                system("part3.mp4");
            if(ghalat==4)
                system("part4.mp4");
            if(ghalat==5)
                system("part5.mp4");





        }
        dorost=0 ;
        if(ghalat==5)
        {
            printf("%s\nto bakhT :(\n",word);

            return 0;
        }
        for(i=0; i<tool; i++)
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

        strcpy(word, entekhabe_kalame(head)) ;


        emtiaz += bazi(word);
        tool--;
    }
    return emtiaz;
}
struct afrad   /*baraye estefade dar filebinary */
{
    char nam[51] ;
    char topic[51] ;
    double emtiaz ;






};
struct afrad t;
int searchb(FILE *fp,char *name)
{
    struct afrad *gogo = (struct afrad *)malloc(sizeof(struct afrad)) ;
    while(!feof(fp))
    {

        fread(gogo,sizeof(struct afrad),1,fp) ;

        if(strcmpi(gogo->nam,name)==0)
        {
            fseek(fp,-sizeof(struct afrad),SEEK_CUR) ;
            return 1;
        }

    }
    return 0 ;


}




int main()
{
    PlaySound(TEXT("FurElise.wav"),NULL,SND_ASYNC);
    system("color 02") ;
    printf("*be hangman khosh oomaD*\n**sakhte shode tavasote mohamad hasan taghadosi**\n") ;
    int shoro,shomare= 1,edame,save ,tedad , j, chekonim, kodomtopic , tamam ;
    double emtiaz ;
    char  name[50],topic[51],kalame[51];
    struct afrad nafar  ;
    struct afrad *gogo = (struct afrad *)malloc(sizeof(struct afrad)) ;
    //scanf("%s",gogo->nam) ;
    fflush(stdin) ;

    srand (time(NULL));
    FILE *fp ;
    FILE *newtopic ;

    if( fp == NULL )
        return -1 ;
    printf("esmeto bde khengool khan \n") ;
    scanf("%s",name) ;
    fflush(stdin) ;
    if(strcmp(name , "gogo")==0)
        printf("vay shomaeed arbab! merC ke mano sakhtid :)\n") ;
    printf("mikhay az aval bazi koni:1  ya edame midi: 2 \nfaghat age bgi edame midi va save nabashi partet mikonam Biroon :)\n") ;
    printf("age ham mikhay topic ezafe koni 3 ro vared kon\n") ;
    scanf("%d",&chekonim) ;
    fflush(stdin) ;
    if(chekonim==3)
    {
        fp = fopen("AVAILABLE_TOPICS.txt","r+") ;
        fseek(fp,0,SEEK_END) ;
        system("cls") ;
        printf("name topic jadid ro vared kon\n") ;
        scanf("%s",topic) ;
        fflush(stdin) ;
        fprintf(fp,"\n%s",topic) ;
        fclose(fp) ;
        newtopic = fopen(topic,"w") ;
        system("cls") ;
        printf("tedad kalamehaii ke wared mikoni ro bgo\n") ;
        scanf("%d",&tedad) ;
        fflush(stdin) ;
        for(j=0;j<tedad;j++)
        {
            system("cls") ;
            printf("kalame jadid ro vared kon\n") ;
            scanf("%s",kalame);
            fflush(stdin) ;
            fprintf(newtopic,"%s\n",kalame) ;

        }
        fclose(newtopic) ;
        printf("mikhay bazi koni 1 ro bzan na 2 ro bzan\n") ;
        scanf("%d",&chekonim) ;
        fflush(stdin) ;
        if(chekonim==2)
            return 0 ;
        printf("mikhay az aval bazi koni:1  ya edame midi: 2  \nfaghat age bgi edame midi va save nabashi partet mikonam Biroon :)\n") ;
        printf("age ham mikhay topic ezafe koni 3 ro vared kon\n") ;
        scanf("%d",&chekonim) ;
        fflush(stdin) ;


    }
    fp = fopen("AVAILABLE_TOPICS.txt","r") ;
    int tool = 0;
    while (!feof(fp))
    {
        fscanf(fp,"%s",topic) ;
        tool++;
    }
    int bazishode[tool] ;
    for(j = 0 ; j < tool ; j++)
        bazishode[j] = 0 ;
    fclose(fp) ;

    fp = fopen("AVAILABLE_TOPICS.txt","r") ;
    FILE *yarooha ;
    yarooha = fopen("afrad.bin","r+b") ;
    if(chekonim==1)
        if(searchb(yarooha,name)==1)
        {
            while(!feof(fp))
                {
                    fscanf(fp,"%s",topic);
                    fflush(stdin) ;
                    printf("%d . %s\n",shomare,topic) ;
                    shomare++ ;
                }
                fseek(fp, 0,SEEK_SET) ;
                scanf("%d",&kodomtopic) ;
                bazishode[kodomtopic-1] = 1 ;
                fflush(stdin) ;
                for(j=0; j<kodomtopic; j++)
                    fscanf(fp,"%s",topic);
                FILE *model ;
                model = fopen(topic,"r") ;
                system("cls") ;

                clock_t begin = clock();
                emtiaz = play_game(model);
                clock_t end = clock();
                double time_spent = (double)(end - begin) ;
                emtiaz =emtiaz/( time_spent/60000)  ;
                fread(gogo,sizeof(struct afrad),1,fp) ;


                Sleep(500) ;
                system("cls") ;
                printf("mikhay save koni?? 1 ro vared kon\nnmikhay 2 ro vared kon\n") ;
                scanf("%d",&save);
                if(save==1)
                {
                    strcpy(gogo->nam,name);
                    strcpy(gogo->topic,topic);
                    gogo->emtiaz=emtiaz ;
                    fseek(yarooha,-sizeof(struct afrad),SEEK_CUR) ;
                    fwrite(gogo,sizeof(struct afrad),1,yarooha) ;
                }
                else
                {
                    strcpy(gogo->nam,name);
                    strcpy(gogo->topic,topic);
                    gogo->emtiaz=0 ;
                    fseek(yarooha,-sizeof(struct afrad),SEEK_CUR) ;
                    fwrite(gogo,sizeof(struct afrad),1,yarooha) ;


                }



                printf("mikhay bazi koni?!\npas 1 ro bzan\nnmikhay 2 ro bzan\n");
                scanf("%d",&edame) ;
                fflush(stdin) ;
                if(edame==2)
                {

                    printf("bishtarin emtizet = %lf to %s\nkhodafez :)\n",gogo->emtiaz,gogo->topic) ;
                    return 0 ;
                }
                chekonim = 2 ;

        }
        else{
                while(!feof(yarooha))
                    fread(gogo,sizeof(struct afrad),1,yarooha) ;
                while(!feof(fp))
                {
                    fscanf(fp,"%s",topic);
                    fflush(stdin) ;
                    printf("%d . %s\n",shomare,topic) ;
                    shomare++ ;
                }
                fseek(fp, 0,SEEK_SET) ;
                scanf("%d",&kodomtopic) ;
                bazishode[kodomtopic-1] = 1 ;
                fflush(stdin) ;
                for(j=0; j<kodomtopic; j++)
                    fscanf(fp,"%s",topic);
                FILE *model ;
                model = fopen(topic,"r") ;
                system("cls") ;

                clock_t begin = clock();
                emtiaz = play_game(model);
                clock_t end = clock();
                double time_spent = (double)(end - begin) ;
                emtiaz =emtiaz/( time_spent/60000)  ;
                printf("emtiaze in bakhsh = %lf\n",emtiaz) ;
                Sleep(5000) ;
                system("cls") ;
                printf("mikhay save koni?? 1 ro vared kon\nnmikhay 2 ro vared kon\n") ;
                scanf("%d",&save);
                if(save==1)
                {
                    strcpy(gogo->nam,name);
                    strcpy(gogo->topic,topic);
                    gogo->emtiaz=emtiaz ;
                    fseek(yarooha,0,SEEK_END) ;
                    fwrite(gogo,sizeof(struct afrad),1,yarooha) ;
                }
                else
                {
                    strcpy(gogo->nam,name);
                    strcpy(gogo->topic,topic);
                    gogo->emtiaz = 0 ;
                    fseek(yarooha,0,SEEK_END) ;
                    fwrite(gogo,sizeof(struct afrad),1,yarooha) ;

                }

                chekonim = 2 ;
                fseek(yarooha,0,SEEK_SET) ;

        }
        fseek(yarooha,0,SEEK_SET) ;
        fseek(fp,0,SEEK_SET);

    if(chekonim==2)
    {






        if(searchb(yarooha,name)==1)
        {



            while(1)
            {
                shomare = 1 ;
                system("cls") ;
                for(j=0;j<tool;j++)
                {
                    if(bazishode[j]==0)
                    {

                        tamam=1 ;
                        break ;
                    }
                    else
                        tamam = 0 ;
                }
                if(tamam==0)
                {
                    printf("you played all the topic! goodbye :)\n") ;
                    Sleep(5000) ;
                    break ;
                }




                while(!feof(fp))
                {
                    fscanf(fp,"%s",topic);
                    fflush(stdin) ;
                    printf("%d . %s\n",shomare,topic) ;
                    shomare++ ;
                }
                fseek(fp, 0,SEEK_SET) ;
                scanf("%d",&kodomtopic) ;
                if(bazishode[kodomtopic-1]==1)
                {
                    Sleep(5000) ;
                    printf("you played this topic!\n please choose the other topic\n") ;
                    continue  ;





                }
                else
                    bazishode[kodomtopic-1] = 1 ;
                fflush(stdin) ;
                for(j=0; j<kodomtopic; j++)
                    fscanf(fp,"%s",topic);
                FILE *model ;
                model = fopen(topic,"r") ;
                system("cls") ;

                clock_t begin = clock();
                emtiaz = play_game(model);
                clock_t end = clock();
                double time_spent = (double)(end - begin) ;
                emtiaz =emtiaz/( time_spent/60000)  ;
                printf("emtiaze in bakhsh = %lf\n",emtiaz) ;
                Sleep(5000) ;
                fread(gogo,sizeof(struct afrad),1,fp) ;
                if(gogo->emtiaz<emtiaz)
                {
                    system("cls") ;
                    printf("mikhay save koni?? 1 ro vared kon\nnmikhay 2 ro vared kon\n") ;
                    scanf("%d",&save);
                    if(save==1)
                    {
                    strcpy(gogo->topic,topic);
                    gogo->emtiaz=emtiaz ;
                    fseek(fp,-sizeof(struct afrad),SEEK_CUR) ;
                    fwrite(gogo,sizeof(struct afrad),1,fp) ;
                    }

                }
                printf("mikhay bazi koni?!\npas 1 ro bzan\nnmikhay 2 ro bzan\n");
                scanf("%d",&edame) ;
                fflush(stdin) ;
                fseek(fp,0,SEEK_SET) ;
                if(edame==2)
                {

                    printf("bishtarin emtizet = %lf to %s\nkhodafez :)\n",gogo->emtiaz,gogo->topic) ;
                    return 0 ;
                }

            }

            }
            else{
                printf("az bazi man gomsho Biroon :-)\n");
                return -1 ;
        }




    }
    fclose(fp) ;
    fclose(yarooha) ;
    struct afrad x1,x2;
    if(chekonim==4)   /*show the ranking*/
    {
        yarooha = fopen("afrad.bin","rb") ;
        fread(&x1,sizeof(struct afrad),1,yarooha);
        for(j=0;j<10;j++)
        {
            while(!feof(yarooha))
            {

            }
        }



    }





}




