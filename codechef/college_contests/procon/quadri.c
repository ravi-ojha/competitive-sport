#include<stdio.h>
int main()
{
    int t;
    scanf(" %d",&t);
    while(t--)
    {
        double ax,ay,bx,by,cx,cy,dx,dy;
        double ac,bd;
        double ab, bc, cd, da;
        scanf(" %lf %lf",&ax,&ay);
        scanf(" %lf %lf",&bx,&by);
        scanf(" %lf %lf",&cx,&cy);
        scanf(" %lf %lf",&dx,&dy);

        ab = (ax-bx)*(ax-bx) + (ay-by)*(ay-by);
        bc = (bx-cx)*(bx-cx) + (by-cy)*(by-cy);
        cd = (cx-dx)*(cx-dx) + (cy-dy)*(cy-dy);
        da = (dx-ax)*(dx-ax) + (dy-ay)*(dy-ay);
        ac = (ax-cx)*(ax-cx) + (ay-cy)*(ay-cy);
        bd = (bx-dx)*(bx-dx) + (by-dy)*(by-dy);
        if(ab == 0 || bc == 0 || cd == 0 || da == 0)
        {
            printf("NONE\n");
        }
        else if(ab == bc && bc == cd && cd == da && da == ab)      //for rhombus and square
        {
            if(ac == bd)
            {
                printf("SQUARE\n");
            }
            else
            {
                printf("RHOMBUS\n");
            }
        }
        else if(ab == cd && da == bc)                      //for parallelogram and rectangle
        {
            if(ac == bd)
            {
                printf("RECTANGLE\n");
            }
            else
            {
                printf("PARALLELOGRAM\n");
            }
        }
        else
        {
            printf("QUADRILATERAL\n");
        }
    }
    return 0;
}
