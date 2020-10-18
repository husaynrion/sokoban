#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
//use NUMPAD for direction;
int main()
{
    int x = 2, y = 7, t1 = 1, xx, yy,bxx, byy, tx, ty, cou1 = 0, cou2 = 0,th1,th2,th3,t3,t5;
    char a[9][9] = {" #####   "," #OOO####"," # $## A#"," #    $ #"," #  ## ##"," #$#   # "," #   ### "," #####   ","         "};
    int sizj = sizeof(a[0]);
    int sizi = sizeof(a) / sizj;
    int b1[sizi * sizj];
    int b2[sizi * sizj];
    int bb1[sizj];
    int bb2[sizj];
    for (int i1 = 0; i1 < sizi; i1++)
    {
        for (int j1 = 0; j1 < sizj; j1++)
        {
            if (a[i1][j1]=='#')
            {
                b1[cou1] = i1;
                b2[cou1] = j1;
                cou1++;
            }
        }
    }
    for (int i2 = 0; i2 < sizi; i2++)
    {
        for (int j2 = 0; j2 < sizj; j2++)
        {
            if (a[i2][j2]=='O')
            {
                bb1[cou2] = i2;
                bb2[cou2] = j2;
                cou2++;
            }
        }
    }

    while (t1 == 1)
    {
        printf("A = Man,\n");
        printf("$ = Box,\n");
        printf("O = Goal,\n");
        printf("# = Wall.\n");
        printf("\n");
        printf("+-----------------------------------+\n");
        printf("| %c | %c | %c | %c | %c | %c | %c | %c | %c |\n", a[0][8], a[1][8], a[2][8], a[3][8], a[4][8], a[5][8], a[6][8], a[7][8], a[8][8]);
        printf("|-----------------------------------|\n");
        printf("| %c | %c | %c | %c | %c | %c | %c | %c | %c |\n", a[0][7], a[1][7], a[2][7], a[3][7], a[4][7], a[5][7], a[6][7], a[7][7], a[8][7]);
        printf("|-----------------------------------|\n");
        printf("| %c | %c | %c | %c | %c | %c | %c | %c | %c |\n", a[0][6], a[1][6], a[2][6], a[3][6], a[4][6], a[5][6], a[6][6], a[7][6], a[8][6]);
        printf("|-----------------------------------|\n");
        printf("| %c | %c | %c | %c | %c | %c | %c | %c | %c |\n", a[0][5], a[1][5], a[2][5], a[3][5], a[4][5], a[5][5], a[6][5], a[7][5], a[8][5]);
        printf("|-----------------------------------|\n");
        printf("| %c | %c | %c | %c | %c | %c | %c | %c | %c |\n", a[0][4], a[1][4], a[2][4], a[3][4], a[4][4], a[5][4], a[6][4], a[7][4], a[8][4]);
        printf("|-----------------------------------|\n");
        printf("| %c | %c | %c | %c | %c | %c | %c | %c | %c |\n", a[0][3], a[1][3], a[2][3], a[3][3], a[4][3], a[5][3], a[6][3], a[7][3], a[8][3]);
        printf("|-----------------------------------|\n");
        printf("| %c | %c | %c | %c | %c | %c | %c | %c | %c |\n", a[0][2], a[1][2], a[2][2], a[3][2], a[4][2], a[5][2], a[6][2], a[7][2], a[8][2]);
        printf("|-----------------------------------|\n");
        printf("| %c | %c | %c | %c | %c | %c | %c | %c | %c |\n", a[0][1], a[1][1], a[2][1], a[3][1], a[4][1], a[5][1], a[6][1], a[7][1], a[8][1]);
        printf("|-----------------------------------|\n");
        printf("| %c | %c | %c | %c | %c | %c | %c | %c | %c |\n", a[0][0], a[1][0], a[2][0], a[3][0], a[4][0], a[5][0], a[6][0], a[7][0], a[8][0]);
        printf("+-----------------------------------+\n");
        xx = x;
        yy = y;

        /*where is B*/
        int coub = 0;
        int bbx[sizj];
        int bby[sizj];
        for (int ib = 0; ib < sizi; ib++)
        {
            for (int jb = 0; jb < sizj; jb++)
            {
                if ((a[ib][jb]=='$')||(a[ib][jb]=='S'))
                {
                    bbx[coub] = ib;
                    bby[coub] = jb;
                    coub++;
                }
            }
        }
        /**/

        t3=0;
        for(int i3=0;i3<cou2;i3++){
            if(a[bb1[i3]][bb2[i3]]!='S'){
                t3=1;
            }
        }
        if(t3==0){
            printf(".\n");
            printf(".\n");
            printf(".\n");
            printf(".\n");
            printf("You Win...!congrats.");
            printf(".\n");
            printf(".\n");
            printf(".\n");
            printf(".\n");
            break;
        }
        char key = getch();
        system("cls");
        switch (key)
        {
        case '8':
            ty = y + 1;
            tx=x;
            break;
        case '2':
            ty = y - 1;
            tx=x;
            break;
        case '6':
            tx = x + 1;
            ty=y;
            break;
        case '4':
            tx = x - 1;
            ty=y;
            break;
        }
        t5=0;
        int sbx,sby;
        for(int i4=0;i4<coub;i4++){
            if ((tx == bbx[i4]) && (ty == bby[i4])){
                sbx=bbx[i4];
                sby=bby[i4];
                t5=1;
            }
        }
        int tbx, tby;
        if (t5==1)
        {
            switch (key)
            {
            case '8':
                tby = sby + (sby - yy);
                tbx=sbx;
                break;
            case '2':
                tby = sby + (sby - yy);
                tbx=sbx;
                break;
            case '6':
                tbx = sbx + (sbx - xx);
                tby=sby;
                break;
            case '4':
                tbx = sbx + (sbx - xx);
                tby=sby;
                break;
            }
        }
        th1=0;
        for(int ih1=0;ih1<cou1;ih1++){
            if((b1[ih1]==tx)&&(b2[ih1]==ty)){
                th1=1;
            }
        }
        th2=0;
        for(int ih2=0;ih2<cou1;ih2++){
            if(  ((b1[ih2]==tbx)&&(b2[ih2]==tby))&&((tx==sbx)&&(ty==sby))  ){
                th2=1;
            }
        }
        th3=0;
        for(int ih3=0;ih3<coub;ih3++){
            if(  ((bbx[ih3]==tbx)&&(bby[ih3]==tby))&&((tx==sbx)&&(ty==sby))  ){
                th3=1;
            }
        }

        if ((th1 == 1)||(th2 == 1)||(th3 == 1))
        {
            printf("Ouch...!\n");
        }else{
               switch (key)
            {
            case '8':
                y += 1;
                break;
            case '2':
                y -= 1;
                break;
            case '6':
                x += 1;
                break;
            case '4':
                x -= 1;
                break;
            }
            a[x][y] += 33;
            if ((x == sbx) && (y == sby))
            {
                bxx = sbx;
                byy = sby;
                switch (key)
                {
                case '8':
                    sby = sby + (sby - yy);
                    break;
                case '2':
                    sby = sby + (sby - yy);
                    break;
                case '6':
                    sbx = sbx + (sbx - xx);
                    break;
                case '4':
                    sbx = sbx + (sbx - xx);
                    break;
                }
                a[sbx][sby] += 4;
                a[bxx][byy] -= 4;
            }
            a[xx][yy] -= 33;
        }
        
        if (key == 'f')
        {
            t1 = 0;
        }
    }
    return 0;
}
