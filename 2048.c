#include <stdio.h>
#include <stdlib.h>
static int tabela[4][4];
static int poeni=0;
int stepen(int);
void nacrtaj(),promeni(char);
int main()
{
    int i,j,brojPoteza;
    int pobeda=0,nijePoraz=0;
    char potez;
    time_t t;
    srand((unsigned) time(&t));
    int x,y,p;
    x=rand()%4;
    y=rand()%4;
    p=rand()%100+1;
    if(p<91)
        tabela[x][y]=1;
    else
        tabela[x][y]=2;
drugiBroj:
    x=rand()%4;
    y=rand()%4;
    if(tabela[x][y]==0)
    {
        p=rand()%100+1;
        if(p<91)
            tabela[x][y]=1;
        else
            tabela[x][y]=2;
    }
    else
        goto drugiBroj;
    printf("2 0 4 8\n~Tutkamon inc.\n\n");
    getchar();
pocetak:
    for(i=0;i<4;i++)
    {
        for (j=0;j<4;j++)
        {
            tabela[i][j]=0;
        }
    }
    brojPoteza=0;poeni=0;
    while(1)
    {
        nacrtaj();
        while(1)
        {
            printf("Unesite potez: ");
            potez=getchar();
            getchar();
            potez=tolower(potez);
            if(potez=='w'||potez=='a'||potez=='s'||potez=='d')
                break;
            else
                printf("Unesite W, A, S ili D.\n");
        }
        promeni(potez);
        brojPoteza++;
        pobeda=0;nijePoraz=0;
        for(i=0;i<4;i++)
        {
            for (j=0;j<4;j++)
            {
                if(tabela[i][j]==11)
                {
                    pobeda++;
                }
                if(tabela[i][j]==0)
                {
                    nijePoraz++;
                }
            }
        }
        if(pobeda)
        {
            printf("Cestitam, pobedili ste!\n\nBroj poteza:%8d\n\nPoeni:      %8d\n",brojPoteza,poeni);
            break;
        }
        else if(!nijePoraz)
        {
            printf("Izgubili ste...\n\nBroj poteza:%8d\n\nPoeni:      %8d\n",brojPoteza,poeni);
            break;
        }
    }
    printf("Da li biste zeleli da igrate ponovo? (Y/N)");
    char izbor=getchar();
    getchar();
    izbor=tolower(izbor);
    if(izbor=='y')
        goto pocetak;
    getchar();getchar();
    return 0;
}

void nacrtaj()
{
    int i,j;
    printf("_____________________\n");
    for(i=0;i<4;i++)
    {
        printf("|    |    |    |    |\n|");
        for (j=0;j<4;j++) {
            if(tabela[i][j]==0)
                printf("____|");
            else
            {
                if(tabela[i][j]<4)
                    printf("_%d__|",stepen(tabela[i][j]));
                else if(tabela[i][j]<7)
                    printf("_%d_|",stepen(tabela[i][j]));
                else if(tabela[i][j]<10)
                    printf("%d_|",stepen(tabela[i][j]));
                else
                    printf("%d|",stepen(tabela[i][j]));
            }
        }
        printf("\n");
    }
    printf("\n\n");
}

int stepen(int a)
{
    int i,toReturn=1;
    for (i=0;i<a;i++) {
        toReturn*=2;
    }
    return toReturn;
}

void promeni(char c)
{
    int i,j,k,chk=0;
    switch(c)
    {
        case 'a':
            for(i=0;i<4;i++)
            {
                for(j=1;j<4;j++)
                {
                    if(tabela[i][j]!=0)
                    {
                        for(k=j;k>0&&tabela[i][k-1]==0;k--)
                        {
                            tabela[i][k-1]=tabela[i][k];
                            tabela[i][k]=0;
                        }
                        if(tabela[i][k-1]==tabela[i][k]&&!chk)
                        {
                            chk=1;
                            tabela[i][k-1]++;
                            poeni+=tabela[i][k-1];
                            tabela[i][k]=0;
                        }
                        else
                            chk=0;
                    }
                }
                chk=0;
            }
        break;
        case 'd':
            for(i=0;i<4;i++)
            {
                for(j=2;j>=0;j--)
                {
                    if(tabela[i][j]!=0)
                    {
                        for(k=j;k<3&&tabela[i][k+1]==0;k++)
                        {
                            tabela[i][k+1]=tabela[i][k];
                            tabela[i][k]=0;
                        }
                        if(tabela[i][k+1]==tabela[i][k]&&!chk)
                        {
                            chk=1;
                            tabela[i][k+1]++;
                            poeni+=tabela[i][k-1];
                            tabela[i][k]=0;
                        }
                        else
                            chk=0;
                    }
                }
                chk=0;
            }
        break;
        case 'w':
            for(i=0;i<4;i++)
            {
                for(j=1;j<4;j++)
                {
                    if(tabela[j][i]!=0)
                    {
                        for(k=j;k>0&&tabela[k-1][i]==0;k--)
                        {
                            tabela[k-1][i]=tabela[k][i];
                            tabela[k][i]=0;
                        }
                        if(tabela[k-1][i]==tabela[k][i]&&!chk)
                        {
                            chk=1;
                            tabela[k-1][i]++;
                            poeni+=tabela[i][k-1];
                            tabela[k][i]=0;
                        }
                        else
                            chk=0;
                    }
                }
                chk=0;
            }
        break;
        case 's':
            for(i=0;i<4;i++)
            {
                for(j=2;j>=0;j--)
                {
                    if(tabela[j][i]!=0)
                    {
                        for(k=j;k<3&&tabela[k+1][i]==0;k++)
                        {
                            tabela[k+1][i]=tabela[k][i];
                            tabela[k][i]=0;
                        }
                        if(tabela[k+1][i]==tabela[k][i]&&!chk)
                        {
                            chk=1;
                            tabela[k+1][i]++;
                            poeni+=tabela[i][k-1];
                            tabela[k][i]=0;
                        }
                        else
                            chk=0;
                    }
                }
                chk=0;
            }
        break;
    }
    time_t t;
    srand((unsigned) time(&t));
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if(tabela[i][j]==0)
                chk++;
        }
    }
    if(!chk)
        return;
    while(1)
    {
        int x,y,p;
        x=rand()%4;
        y=rand()%4;
        if(tabela[x][y]==0)
        {
            p=rand()%100+1;
            if(p<91)
                tabela[x][y]=1;
            else
                tabela[x][y]=2;
            break;
        }
    }
}
