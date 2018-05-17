#include <iostream>
using namespace std;

const int M = 5;    // Change this to n+1 for a square board of nXn.
static int counter = 0;
int victory(char b[M][M],char c[M][M],int m,int e)
{
    if(m==0)
        return 0;
    else
    {
        int f,g,h,i,j,k,p,q,r,s,t,u,v,w,x,y,z,flag=0,ans,ref,dest,init,motion;
        char btemp[M][M],ctemp[M][M],opp,me;

        if(e%2==0)  //white's turn
        {
            ans=1;
            ref=1;
            opp='B';
            me='W';
            t=0;
            dest=4;
            init=1;
            motion=1;
        }
        else
        {
            ans=0;
            ref=0;
            opp='W';
            me='B';
            t=1;
            dest=1;
            init=4;
            motion=-1;
        }
        for(i=1;i<M;i++)    //checking if opponent's queen can be taken!
        {
            for(j=1;j<M;j++)
            {
                if(c[i][j]==opp && b[i][j]=='Q')
                {
                    /*
                        can this be killed by any of the opponent's pieces if yes return 1
                        */
                    if(i+1<M && j+2<M && c[i+1][j+2]==me && b[i+1][j+2]=='N')
                    {
                        return ans;
                    }
                    if(i+1<M && j-2>0 && c[i+1][j-2]==me && b[i+1][j-2]=='N')
                    {
                        return ans;
                    }
                    if(i+2<M && j+1<M && c[i+2][j+1]==me && b[i+2][j+1]=='N')
                    {
                        return ans;
                    }
                    if(i+2<M && j-1>0 && c[i+2][j-1]==me && b[i+2][j-1]=='N')
                    {
                        return ans;
                    }
                    if(i-2>0 && j+1<M && c[i-2][j+1]==me && b[i-2][j+1]=='N')
                    {
                        return ans;
                    }
                    if(i-2>0 && j-1>0 && c[i-2][j-1]==me && b[i-2][j-1]=='N')
                    {
                        return ans;
                    }
                    if(i-1>0 && j+2<M && c[i-1][j+2]==me && b[i-1][j+2]=='N')
                    {
                        return ans;
                    }
                    if(i-1>0 && j-2>0 && c[i-1][j-2]==me && b[i-1][j-2]=='N')
                    {
                        return ans;
                    }
                    // settled attacks by knight
                    for(x=i+1;x<M;x++)
                    {
                        if(c[x][j]==me)
                        {
                            if(b[x][j]=='R' || b[x][j]=='Q')
                                return ans;
                            else
                                break;
                        }
                        if(c[x][j]==opp)
                            break;
                    }
                    for(x=i-1;x>0;x--)
                    {
                        if(c[x][j]==me)
                        {
                            if(b[x][j]=='R' || b[x][j]=='Q')
                                return ans;
                            else
                                break;
                        }
                        if(c[x][j]==opp)
                            break;
                    }
                    for(y=j+1;y<M;y++)
                    {
                        if(c[i][y]==me)
                        {
                            if(b[i][y]=='R' || b[i][y]=='Q')
                                return ans;
                            else
                                break;
                        }
                        if(c[i][y]==opp)
                            break;
                    }
                    for(y=j-1;y>0;y--)
                    {
                        if(c[i][y]==me)
                        {
                            if(b[i][y]=='R' || b[i][y]=='Q')
                                return ans;
                            else
                                break;
                        }
                        if(c[i][y]==opp)
                            break;
                    }
                    //settled rooks and rook part of the queen

                    for(x=1;x<M;x++)
                    {
                        if(i+x<M && j+x<M)
                        {
                            if(c[i+x][j+x]==me)
                            {
                                if(b[i+x][j+x]=='B' || b[i+x][j+x]=='Q')
                                    return ans;
                                else
                                    break;
                            }
                            if(c[i+x][j+x]==opp)
                                break;
                        }
                    }
                    for(x=1;x<M;x++)
                    {
                        if(i+x<M && j-x>0)
                        {
                            if(c[i+x][j-x]==me)
                            {
                                if(b[i+x][j-x]=='B' || b[i+x][j-x]=='Q')
                                    return ans;
                                else
                                    break;
                            }
                            if(c[i+x][j-x]==opp)
                                break;
                        }
                    }
                    for(x=1;x<M;x++)
                    {
                        if(i-x>0 && j+x<M)
                        {
                            if(c[i-x][j+x]==me)
                            {
                                if(b[i-x][j+x]=='B' || b[i-x][j+x]=='Q')
                                    return ans;
                                else
                                    break;
                            }
                            if(c[i-x][j+x]==opp)
                                break;
                        }
                    }
                    for(x=1;x<M;x++)
                    {
                        if(i-x>0 && j-x>0)
                        {
                            if(c[i-x][j-x]==me)
                            {
                                if(b[i-x][j-x]=='B' || b[i-x][j-x]=='Q')
                                    return ans;
                                else
                                    break;
                            }
                            if(c[i-x][j-x]==opp)
                                break;
                        }
                    }
                    // Settled Bishops and bishop part of queen

                    if(i!=init)
                    {
                        if(j+1<M && c[i-motion][j+1]==me && b[i-motion][j+1]=='P')
                        {
                            return ans;
                        }
                        if(j-1>0 && c[i-motion][j-1]==me && b[i-motion][j-1]=='P')
                        {
                            return ans;
                        }
                    }
                    // Settled Pawns thing


                    //Settled All pieces attacking queen in present position!!
                    flag=1;
                    break;     // as there is only one queen on either side
                }
            }
            if(flag==1)
                break;
        }
        /* recursive stuff from now on*/

        for(i=1;i<M;i++)       // Trying all possibilities
        {
            for(j=1;j<M;j++)
            {
                if(c[i][j]==me)
                {
                    if(b[i][j]=='P')   // All possibilities of pawn
                    {
                        if(i+motion<M && i+motion>0)   //place is inside the board
                        {
                            if(j+1<M)
                            {
                                if(c[i+motion][j+1]==opp)
                                {
                                    if(i+motion!=dest)
                                    {
                                        for(p=1;p<M;p++)    //duplicating current position to use while making various tries!
                                        {
                                            for(q=1;q<M;q++)
                                            {
                                                btemp[p][q]=b[p][q];
                                                ctemp[p][q]=c[p][q];
                                            }
                                        }
                                        btemp[i][j]='-';
                                        ctemp[i][j]='-';
                                        ctemp[i+motion][j+1]=me;

                                        btemp[i+motion][j+1]='P';
                                        t=victory(btemp,ctemp,m-1,e+1);

                                        if(t==ref)
                                            return ans;
                                    }
                                    else
                                    {
                                        for(u=1;u<4;u++)
                                        {
                                            for(p=1;p<M;p++)    //duplicating current position to use while making various tries!
                                            {
                                                for(q=1;q<M;q++)
                                                {
                                                    btemp[p][q]=b[p][q];
                                                    ctemp[p][q]=c[p][q];
                                                }
                                            }
                                            btemp[i][j]='-';
                                            ctemp[i][j]='-';
                                            ctemp[i+motion][j+1]=me;

                                            if(u==1)
                                                btemp[i+motion][j+1]='R';
                                            if(u==2)
                                                btemp[i+motion][j+1]='B';
                                            if(u==3)
                                                btemp[i+motion][j+1]='N';
                                            
                                            t=victory(btemp,ctemp,m-1,e+1);

                                            if(t==ref)
                                                return ans;
                                        }
                                    }
                                }
                            }
                            if(j-1>0)   //place i am going to is not me
                            {
                                if(c[i+motion][j-1]==opp)
                                {
                                    if(i+motion!=dest)
                                    {
                                        for(p=1;p<M;p++)    //duplicating current position to use while making various tries!
                                        {
                                            for(q=1;q<M;q++)
                                            {
                                                btemp[p][q]=b[p][q];
                                                ctemp[p][q]=c[p][q];
                                            }
                                        }
                                        btemp[i][j]='-';
                                        ctemp[i][j]='-';
                                        ctemp[i+motion][j-1]=me;

                                        btemp[i+motion][j-1]='P';
                                        t=victory(btemp,ctemp,m-1,e+1);

                                        if(t==ref)
                                            return ans;
                                    }
                                    else
                                    {
                                        for(u=1;u<4;u++)
                                        {
                                            for(p=1;p<M;p++)    //duplicating current position to use while making various tries!
                                            {
                                                for(q=1;q<M;q++)
                                                {
                                                    btemp[p][q]=b[p][q];
                                                    ctemp[p][q]=c[p][q];
                                                }
                                            }
                                            btemp[i][j]='-';
                                            ctemp[i][j]='-';
                                            ctemp[i+motion][j-1]=me;

                                            if(u==1)
                                                btemp[i+motion][j-1]='R';
                                            if(u==2)
                                                btemp[i+motion][j-1]='B';
                                            if(u==3)
                                                btemp[i+motion][j-1]='N';
                                            
                                            t=victory(btemp,ctemp,m-1,e+1);

                                            if(t==ref)
                                                return ans;
                                        }
                                    }
                                }
                            }
                            if(j>0 && j<M)
                            {
                                if(c[i+motion][j]=='-')
                                {
                                    if(i+motion!=dest)
                                    {
                                        for(p=1;p<M;p++)    //duplicating current position to use while making various tries!
                                        {
                                            for(q=1;q<M;q++)
                                            {
                                                btemp[p][q]=b[p][q];
                                                ctemp[p][q]=c[p][q];
                                            }
                                        }
                                        btemp[i][j]='-';
                                        ctemp[i][j]='-';
                                        ctemp[i+motion][j]=me;

                                        btemp[i+motion][j]='P';
                                        t=victory(btemp,ctemp,m-1,e+1);

                                        if(t==ref)
                                            return ans;
                                    }
                                    else
                                    {
                                        for(u=1;u<4;u++)
                                        {
                                            for(p=1;p<M;p++)    //duplicating current position to use while making various tries!
                                            {
                                                for(q=1;q<M;q++)
                                                {
                                                    btemp[p][q]=b[p][q];
                                                    ctemp[p][q]=c[p][q];
                                                }
                                            }
                                            btemp[i][j]='-';
                                            ctemp[i][j]='-';
                                            ctemp[i+motion][j]=me;

                                            if(u==1)
                                                btemp[i+motion][j]='R';
                                            if(u==2)
                                                btemp[i+motion][j]='B';
                                            if(u==3)
                                                btemp[i+motion][j]='N';
                                            
                                            t=victory(btemp,ctemp,m-1,e+1);

                                            if(t==ref)
                                                return ans;
                                        }
                                    }
                                }
                            }
                        }
                    }
                    if(b[i][j]=='R')   // All possible moves of rook
                    {
                        for(x=i+1;x<M;x++)
                        {
                            if(c[x][j]==me)    // don't go
                                break;
                            else   // go as much as u want
                            {
                                for(p=1;p<M;p++)    //duplicating current position to use while making various tries!
                                {
                                    for(q=1;q<M;q++)
                                    {
                                        btemp[p][q]=b[p][q];
                                        ctemp[p][q]=c[p][q];
                                    }
                                }
                                btemp[i][j]='-';
                                ctemp[i][j]='-';
                                btemp[x][j]='R';
                                ctemp[x][j]=me;

                                t=victory(btemp,ctemp,m-1,e+1);

                                if(t==ref)
                                    return ans;
                                if(c[x][j]==opp)
                                    break;
                            }
                        }
                        for(x=i-1;x>0;x--)
                        {
                            if(c[x][j]==me)    // don't go
                                break;
                            else   // go as much as u want
                            {
                                for(p=1;p<M;p++)    //duplicating current position to use while making various tries!
                                {
                                    for(q=1;q<M;q++)
                                    {
                                        btemp[p][q]=b[p][q];
                                        ctemp[p][q]=c[p][q];
                                    }
                                }
                                btemp[i][j]='-';
                                ctemp[i][j]='-';
                                btemp[x][j]='R';
                                ctemp[x][j]=me;

                                t=victory(btemp,ctemp,m-1,e+1);

                                if(t==ref)
                                    return ans;
                                if(c[x][j]==opp)
                                    break;
                            }
                        }
                        for(y=j+1;y<M;y++)
                        {
                            if(c[i][y]==me)    // don't go
                                break;
                            else   // go as much as u want
                            {
                                for(p=1;p<M;p++)    //duplicating current position to use while making various tries!
                                {
                                    for(q=1;q<M;q++)
                                    {
                                        btemp[p][q]=b[p][q];
                                        ctemp[p][q]=c[p][q];
                                    }
                                }
                                btemp[i][j]='-';
                                ctemp[i][j]='-';
                                btemp[i][y]='R';
                                ctemp[i][y]=me;

                                t=victory(btemp,ctemp,m-1,e+1);

                                if(t==ref)
                                    return ans;
                                if(c[i][y]==opp)
                                    break;
                            }
                        }
                        for(y=j-1;y>0;y--)
                        {
                            if(c[i][y]==me)    // don't go
                                break;
                            else   // go as much as u want
                            {
                                for(p=1;p<M;p++)    //duplicating current position to use while making various tries!
                                {
                                    for(q=1;q<M;q++)
                                    {
                                        btemp[p][q]=b[p][q];
                                        ctemp[p][q]=c[p][q];
                                    }
                                }
                                btemp[i][j]='-';
                                ctemp[i][j]='-';
                                btemp[i][y]='R';
                                ctemp[i][y]=me;

                                t=victory(btemp,ctemp,m-1,e+1);

                                if(t==ref)
                                    return ans;
                                if(c[i][y]==opp)
                                    break;
                            }
                        }
                    }
                    if(b[i][j]=='B')    //all possible moves of bishop
                    {
                        for(x=1;x<M;x++)
                        {
                            if(i+x<M && j+x<M)
                            {
                                if(c[i+x][j+x]==me)
                                    break;
                                else
                                {
                                    for(p=1;p<M;p++)    //duplicating current position to use while making various tries!
                                    {
                                        for(q=1;q<M;q++)
                                        {
                                            btemp[p][q]=b[p][q];
                                            ctemp[p][q]=c[p][q];
                                        }
                                    }
                                    btemp[i][j]='-';
                                    ctemp[i][j]='-';
                                    btemp[i+x][j+x]='B';
                                    ctemp[i+x][j+x]=me;

                                    t=victory(btemp,ctemp,m-1,e+1);

                                    if(t==ref)
                                        return ans;
                                    if(c[i+x][j+x]==opp)
                                        break;
                                }
                            }
                        }

                        for(x=1;x<M;x++)
                        {
                            if(i+x<M && j-x>0)
                            {
                                if(c[i+x][j-x]==me)
                                    break;
                                else
                                {
                                    for(p=1;p<M;p++)    //duplicating current position to use while making various tries!
                                    {
                                        for(q=1;q<M;q++)
                                        {
                                            btemp[p][q]=b[p][q];
                                            ctemp[p][q]=c[p][q];
                                        }
                                    }
                                    btemp[i][j]='-';
                                    ctemp[i][j]='-';
                                    btemp[i+x][j-x]='B';
                                    ctemp[i+x][j-x]=me;

                                    t=victory(btemp,ctemp,m-1,e+1);

                                    if(t==ref)
                                        return ans;
                                    if(c[i+x][j-x]==opp)
                                        break;
                                }
                            }
                        }

                        for(x=1;x<M;x++)
                        {
                            if(i-x>0 && j+x<M)
                            {
                                if(c[i-x][j+x]==me)
                                    break;
                                else
                                {
                                    for(p=1;p<M;p++)    //duplicating current position to use while making various tries!
                                    {
                                        for(q=1;q<M;q++)
                                        {
                                            btemp[p][q]=b[p][q];
                                            ctemp[p][q]=c[p][q];
                                        }
                                    }
                                    btemp[i][j]='-';
                                    ctemp[i][j]='-';
                                    btemp[i-x][j+x]='B';
                                    ctemp[i-x][j+x]=me;

                                    t=victory(btemp,ctemp,m-1,e+1);

                                    if(t==ref)
                                        return ans;
                                    if(c[i-x][j+x]==opp)
                                        break;
                                }
                            }
                        }
                        for(x=1;x<M;x++)
                        {
                            if(i-x>0 && j-x>0)
                            {
                                if(c[i-x][j-x]==me)
                                    break;
                                else
                                {
                                    for(p=1;p<M;p++)    //duplicating current position to use while making various tries!
                                    {
                                        for(q=1;q<M;q++)
                                        {
                                            btemp[p][q]=b[p][q];
                                            ctemp[p][q]=c[p][q];
                                        }
                                    }
                                    btemp[i][j]='-';
                                    ctemp[i][j]='-';
                                    btemp[i-x][j-x]='B';
                                    ctemp[i-x][j-x]=me;

                                    t=victory(btemp,ctemp,m-1,e+1);

                                    if(t==ref)
                                        return ans;
                                    if(c[i-x][j-x]==opp)
                                        break;
                                }
                            }
                        }
                    }
                    if(b[i][j]=='Q')   //all tries of queen
                    {
                        for(x=i+1;x<M;x++)
                        {
                            if(c[x][j]==me)    // don't go
                                break;
                            else   // go as much as u want
                            {
                                for(p=1;p<M;p++)    //duplicating current position to use while making various tries!
                                {
                                    for(q=1;q<M;q++)
                                    {
                                        btemp[p][q]=b[p][q];
                                        ctemp[p][q]=c[p][q];
                                    }
                                }
                                btemp[i][j]='-';
                                ctemp[i][j]='-';
                                btemp[x][j]='Q';
                                ctemp[x][j]=me;

                                t=victory(btemp,ctemp,m-1,e+1);

                                if(t==ref)
                                    return ans;
                                if(c[x][j]==opp)
                                    break;
                            }
                        }
                        for(x=i-1;x>0;x--)
                        {
                            if(c[x][j]==me)    // don't go
                                break;
                            else   // go as much as u want
                            {
                                for(p=1;p<M;p++)    //duplicating current position to use while making various tries!
                                {
                                    for(q=1;q<M;q++)
                                    {
                                        btemp[p][q]=b[p][q];
                                        ctemp[p][q]=c[p][q];
                                    }
                                }
                                btemp[i][j]='-';
                                ctemp[i][j]='-';
                                btemp[x][j]='Q';
                                ctemp[x][j]=me;

                                t=victory(btemp,ctemp,m-1,e+1);

                                if(t==ref)
                                    return ans;
                                if(c[x][j]==opp)
                                    break;
                            }
                        }
                        for(y=j+1;y<M;y++)
                        {
                            if(c[i][y]==me)    // don't go
                                break;
                            else   // go as much as u want
                            {
                                for(p=1;p<M;p++)    //duplicating current position to use while making various tries!
                                {
                                    for(q=1;q<M;q++)
                                    {
                                        btemp[p][q]=b[p][q];
                                        ctemp[p][q]=c[p][q];
                                    }
                                }
                                btemp[i][j]='-';
                                ctemp[i][j]='-';
                                btemp[i][y]='Q';
                                ctemp[i][y]=me;

                                t=victory(btemp,ctemp,m-1,e+1);

                                if(t==ref)
                                    return ans;
                                if(c[i][y]==opp)
                                    break;
                            }
                        }
                        for(y=j-1;y>0;y--)
                        {
                            if(c[i][y]==me)    // don't go
                                break;
                            else   // go as much as u want
                            {
                                for(p=1;p<M;p++)    //duplicating current position to use while making various tries!
                                {
                                    for(q=1;q<M;q++)
                                    {
                                        btemp[p][q]=b[p][q];
                                        ctemp[p][q]=c[p][q];
                                    }
                                }
                                btemp[i][j]='-';
                                ctemp[i][j]='-';
                                btemp[i][y]='Q';
                                ctemp[i][y]=me;

                                t=victory(btemp,ctemp,m-1,e+1);

                                if(t==ref)
                                    return ans;
                                if(c[i][y]==opp)
                                    break;
                            }
                        }
                        for(x=1;x<M;x++)
                        {
                            if(i+x<M && j+x<M)
                            {
                                if(c[i+x][j+x]==me)
                                    break;
                                else
                                {
                                    for(p=1;p<M;p++)    //duplicating current position to use while making various tries!
                                    {
                                        for(q=1;q<M;q++)
                                        {
                                            btemp[p][q]=b[p][q];
                                            ctemp[p][q]=c[p][q];
                                        }
                                    }
                                    btemp[i][j]='-';
                                    ctemp[i][j]='-';
                                    btemp[i+x][j+x]='Q';
                                    ctemp[i+x][j+x]=me;

                                    t=victory(btemp,ctemp,m-1,e+1);

                                    if(t==ref)
                                        return ans;
                                    if(c[i+x][j+x]==opp)
                                        break;
                                }
                            }
                        }

                        for(x=1;x<M;x++)
                        {
                            if(i+x<M && j-x>0)
                            {
                                if(c[i+x][j-x]==me)
                                    break;
                                else
                                {
                                    for(p=1;p<M;p++)    //duplicating current position to use while making various tries!
                                    {
                                        for(q=1;q<M;q++)
                                        {
                                            btemp[p][q]=b[p][q];
                                            ctemp[p][q]=c[p][q];
                                        }
                                    }
                                    btemp[i][j]='-';
                                    ctemp[i][j]='-';
                                    btemp[i+x][j-x]='Q';
                                    ctemp[i+x][j-x]=me;

                                    t=victory(btemp,ctemp,m-1,e+1);

                                    if(t==ref)
                                        return ans;
                                    if(c[i+x][j-x]==opp)
                                        break;
                                }
                            }
                        }

                        for(x=1;x<M;x++)
                        {
                            if(i-x>0 && j+x<M)
                            {
                                if(c[i-x][j+x]==me)
                                    break;
                                else
                                {
                                    for(p=1;p<M;p++)    //duplicating current position to use while making various tries!
                                    {
                                        for(q=1;q<M;q++)
                                        {
                                            btemp[p][q]=b[p][q];
                                            ctemp[p][q]=c[p][q];
                                        }
                                    }
                                    btemp[i][j]='-';
                                    ctemp[i][j]='-';
                                    btemp[i-x][j+x]='Q';
                                    ctemp[i-x][j+x]=me;

                                    t=victory(btemp,ctemp,m-1,e+1);

                                    if(t==ref)
                                        return ans;
                                    if(c[i-x][j+x]==opp)
                                        break;
                                }
                            }
                        }
                        for(x=1;x<M;x++)
                        {
                            if(i-x>0 && j-x>0)
                            {
                                if(c[i-x][j-x]==me)
                                    break;
                                else
                                {
                                    for(p=1;p<M;p++)    //duplicating current position to use while making various tries!
                                    {
                                        for(q=1;q<M;q++)
                                        {
                                            btemp[p][q]=b[p][q];
                                            ctemp[p][q]=c[p][q];
                                        }
                                    }
                                    btemp[i][j]='-';
                                    ctemp[i][j]='-';
                                    btemp[i-x][j-x]='Q';
                                    ctemp[i-x][j-x]=me;

                                    t=victory(btemp,ctemp,m-1,e+1);

                                    if(t==ref)
                                        return ans;
                                    if(c[i-x][j-x]==opp)
                                        break;
                                }
                            }
                        }
                    }
                    if(b[i][j]=='N')   //all tries of knight
                    {
                        if(i+1<M && j+2<M)
                        {
                            if(c[i+1][j+2]!=me)
                            {
                                for(p=1;p<M;p++)    //duplicating current position to use while making various tries!
                                {
                                    for(q=1;q<M;q++)
                                    {
                                        btemp[p][q]=b[p][q];
                                        ctemp[p][q]=c[p][q];
                                    }
                                }
                                btemp[i][j]='-';
                                ctemp[i][j]='-';
                                btemp[i+1][j+2]='N';
                                ctemp[i+1][j+2]=me;

                                t=victory(btemp,ctemp,m-1,e+1);

                                if(t==ref)
                                    return ans;
                            }
                        }
                        if(i+1<M && j-2>0)
                        {
                            if(c[i+1][j-2]!=me)
                            {
                                for(p=1;p<M;p++)    //duplicating current position to use while making various tries!
                                {
                                    for(q=1;q<M;q++)
                                    {
                                        btemp[p][q]=b[p][q];
                                        ctemp[p][q]=c[p][q];
                                    }
                                }
                                btemp[i][j]='-';
                                ctemp[i][j]='-';
                                btemp[i+1][j-2]='N';
                                ctemp[i+1][j-2]=me;

                                t=victory(btemp,ctemp,m-1,e+1);

                                if(t==ref)
                                    return ans;
                            }
                        }
                        if(i+2<M && j+1<M)
                        {
                            if(c[i+2][j+1]!=me)
                            {
                                for(p=1;p<M;p++)    //duplicating current position to use while making various tries!
                                {
                                    for(q=1;q<M;q++)
                                    {
                                        btemp[p][q]=b[p][q];
                                        ctemp[p][q]=c[p][q];
                                    }
                                }
                                btemp[i][j]='-';
                                ctemp[i][j]='-';
                                btemp[i+2][j+1]='N';
                                ctemp[i+2][j+1]=me;

                                t=victory(btemp,ctemp,m-1,e+1);

                                if(t==ref)
                                    return ans;
                            }
                        }
                        if(i+2<M && j-1>0)
                        {
                            if(c[i+2][j-1]!=me)
                            {
                                for(p=1;p<M;p++)    //duplicating current position to use while making various tries!
                                {
                                    for(q=1;q<M;q++)
                                    {
                                        btemp[p][q]=b[p][q];
                                        ctemp[p][q]=c[p][q];
                                    }
                                }
                                btemp[i][j]='-';
                                ctemp[i][j]='-';
                                btemp[i+2][j-1]='N';
                                ctemp[i+2][j-1]=me;

                                t=victory(btemp,ctemp,m-1,e+1);

                                if(t==ref)
                                    return ans;
                            }
                        }
                        if(i-2>0 && j+1<M)
                        {
                            if(c[i-2][j+1]!=me)
                            {
                                for(p=1;p<M;p++)    //duplicating current position to use while making various tries!
                                {
                                    for(q=1;q<M;q++)
                                    {
                                        btemp[p][q]=b[p][q];
                                        ctemp[p][q]=c[p][q];
                                    }
                                }
                                btemp[i][j]='-';
                                ctemp[i][j]='-';
                                btemp[i-2][j+1]='N';
                                ctemp[i-2][j+1]=me;

                                t=victory(btemp,ctemp,m-1,e+1);

                                if(t==ref)
                                    return ans;
                            }
                        }
                        if(i-2>0 && j-1>0)
                        {
                            if(c[i-2][j-1]!=me)
                            {
                                for(p=1;p<M;p++)    //duplicating current position to use while making various tries!
                                {
                                    for(q=1;q<M;q++)
                                    {
                                        btemp[p][q]=b[p][q];
                                        ctemp[p][q]=c[p][q];
                                    }
                                }
                                btemp[i][j]='-';
                                ctemp[i][j]='-';
                                btemp[i-2][j-1]='N';
                                ctemp[i-2][j-1]=me;

                                t=victory(btemp,ctemp,m-1,e+1);

                                if(t==ref)
                                    return ans;
                            }
                        }
                        if(i-1>0 && j+2<M)
                        {
                            if(c[i-1][j+2]!=me)
                            {
                                for(p=1;p<M;p++)    //duplicating current position to use while making various tries!
                                {
                                    for(q=1;q<M;q++)
                                    {
                                        btemp[p][q]=b[p][q];
                                        ctemp[p][q]=c[p][q];
                                    }
                                }
                                btemp[i][j]='-';
                                ctemp[i][j]='-';
                                btemp[i-1][j+2]='N';
                                ctemp[i-1][j+2]=me;

                                t=victory(btemp,ctemp,m-1,e+1);

                                if(t==ref)
                                    return ans;
                            }
                        }
                        if(i-1>0 && j-2>0)
                        {
                            if(c[i-1][j-2]!=me)
                            {
                                for(p=1;p<M;p++)    //duplicating current position to use while making various tries!
                                {
                                    for(q=1;q<M;q++)
                                    {
                                        btemp[p][q]=b[p][q];
                                        ctemp[p][q]=c[p][q];
                                    }
                                }
                                btemp[i][j]='-';
                                ctemp[i][j]='-';
                                btemp[i-1][j-2]='N';
                                ctemp[i-1][j-2]=me;

                                t=victory(btemp,ctemp,m-1,e+1);

                                if(t==ref)
                                    return ans;
                            }
                        }
                    }
                }
            }
        }
        return t;
    }
}
int main() 
{
    int h,t;
    cin>>t;
    for(h=0;h<t;h++)
    {
        char board[M][M],color[M][M];
        int w,b,m,i,j,k,ans;

        cin>>w>>b>>m;   //taking input

        char Wp[w+1],Bp[b+1],WC[w+1],BC[b+1];
        int Wr[w+1],Wc[w+1],Br[b+1],Bc[b+1];

        for(i=0;i<M;i++)    // setting up initial values
        {
            for(j=0;j<M;j++)
            {
                board[i][j]='-';
                color[i][j]='-';
            }
        }

        for(i=1;i<w+1;i++)  //taking input
        {
            cin>>Wp[i]>>WC[i]>>Wr[i];
            for(j=1;j<M;j++)
            {
                char ch = 64+j;
                if(WC[i]==ch)
                    Wc[i]=j;
            }
            board[Wr[i]][Wc[i]]=Wp[i];
            color[Wr[i]][Wc[i]]='W';
        }
        for(i=1;i<b+1;i++)   //taking input
        {
            cin>>Bp[i]>>BC[i]>>Br[i];
            for(j=1;j<M;j++)
            {
                char ch = 64+j;
                if(BC[i]==ch)
                    Bc[i]=j;
            }
            board[Br[i]][Bc[i]]=Bp[i];
            color[Br[i]][Bc[i]]='B';
        }
        ans=victory(board,color,m,0);
        if(ans==1)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
