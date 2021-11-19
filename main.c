#include <stdio.h>
#include <stdlib.h>
#include <string.h>




int main()
{
    int i;
    int choice;
    load();

    do
    {
        printf(" \n\n Phone-book menu:\n\n");
        printf("\t(1) Add contact\n");
        printf("\t(2) Search for Phone number\n");
        printf("\t(3) Delete contact\n");
        printf("\t(4) Modify\n");
        printf("\t(5) Print the Phone-book\n");
        printf("\t(6) Save\n");
        printf("\t(7) Exit\n");
        scanf("%d",&i);
        if(i>7||i<=0)
            printf("   * please enter a valid number   *");


        if (i == 1)
        {
            Add();
        }

        if (i == 2)
        {
            search();
        }

        if (i == 3)
        {
            del();
        }

        if (i == 4)
        {
            Modify();
        }


        if (i == 5)
        {
            prnt();
        }

        if (i == 6)
        {
            save();
        }

        if (i == 7)
        {
            printf("Warning your changes will be discarded. If yes press (1) if no press (0)\n");
            scanf("%d",&choice);
            if(choice==1)

                return 0;

            else if(choice==0);

        }
    }

    while (i>=0||i<0);

}

