// #include <cs50.h>
#include <stdio.h>

int get_int(char *);

int main(void)
{
    // Will Grab number from user as long as its greater than 1
    int n;
    do
    {
        n = get_int("Height (Between 1  to 8): ");
    }
    while (n < 1 || n > 8);
    
    int w = n * 2;

    /*
    each row is w wide
    n is halfway
    top row = " "
    */
    //Increases height
    for (int height = 0; height < n; height++)
    {   //increases width
        for (int width = 1; width < n+1; width++)
        {
            if (width <= w)
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }
         }
        printf("\n");
     }
     //Decreases height
    for (int height = n; height > 0; height--)
    {   //decreases width
        for (int width = n ; width > 0; width--)
        {
            if (width <= w)
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }
         }
        printf("\n");
     }
}
// #include <cs50.h>
// #include <stdio.h>

// //int get_int(char *);

// int main(void)
// {
//     // Will Grab number from user as long as its greater than 1
//     int n;
//     do
//     {
//         n = get_int("Height (Between 1  to 8): ");
//     }
//     while (n < 1 || n > 8);
//     // loop until n * 2
//     // height++ until n = n
//     // if n > n height --
//     int height = 0, width = 1;
//     //height = width = 0;

//     // for (int i = 0; i < n * 2; i++)
//     // {
//     //     if (i < n)
//     //     {
//     //         height++;
//     //         width++;
//     //     }
//     //     else
//     //     {
//     //         height--;
//     //         width--;
//     //     }

//     //     if (width <= n - height - 1)
//     //         {
//     //             printf(" ");
//     //         }
//     //         else
//     //         {
//     //             printf("#");
//     //         }
//     // }
//     // printf("\n");

//     // //Increases height
//     for (height = 0; height < (n * 1);)
//     {   //increases width
//         for (width = 1; width < (n * 1) +1;)
//         {
//             if (width <= n - height - 1)
//             {
//                 printf(" ");
//             }
//             else
//             {
//                 printf("#");
//             }
//          }
//         printf("\n");
//         // if (n < n + 1)
//         // {
//         //     height++;
//         //     width++;
//         // }
//         // else
//         // {
//         //     height--;
//         //     width--;
//         // }
//      }
// }

int get_int(char * message)
{
    int number;
    printf("%s", message);
    scanf("%d", &number);
    return number;
}