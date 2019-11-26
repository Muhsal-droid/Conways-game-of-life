#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


int main ( int argc, char *argv[] ) {



   int row = 20;
   int column = 40;
  int neighbour = 0;
   int currentgrid[row][column];
   int futuregrid[row][column];
   int displaygrid[row][column];
   FILE *f1;
   int i,j,a,b,c,r,s,x,t,k;
   int alltick = 50;
   int tick=0;
   char y[1];
   char p[1];
if (argc != 5){
 printf("Usage: ./cgol1 Name.seed alltick (if left empty then tick is 50)\n");
 return(-1);
}

alltick = atoi(argv[2]);
row = atoi(argv[3]);
column = atoi(argv[4]);



  if ( (f1 = fopen(argv[1], "r")) != NULL ) {

 	for ( i = 0 ; i < row ; i ++ ) {
 		for ( j = 0 ; j < column ; j ++ ) {
       fscanf(f1, "%d", &currentgrid[i][j]);
     }
   }

     }else {
       printf("cannot open file");
     }
     fclose(f1);

     memcpy(futuregrid,currentgrid,sizeof(currentgrid));

     system("clear");


     for (i = 0; i < row; i++) {
       for ( j = 0; j < column; j++) {
         if (currentgrid[i][j] == 1 ) {
           (displaygrid[i][j] = 'X');
         }
         if (currentgrid[i][j] == 0) {
           (displaygrid[i][j] = ' ');
         }
       }
     }
     printf(" ");
     for ( t = 0; t < column; t++) {
      printf("-" );
    } printf("\n");

       for (a = 0; a < row; a++) {
         printf("|");

           for ( b = 0; b < column; b++) {
           printf("%c",displaygrid[a][b] );
           }
           printf("|\n" );
       }
       printf(" ");
       for ( t = 0; t < column; t++) {
        printf("-" );
      } printf("%d\n", tick);


         printf("Start?(y or n)\n");
         scanf("%s",y );

         if (strcmp("y",y)==0){
          do{
             for ( i = 0; i < alltick; i++) {
    memcpy(currentgrid, futuregrid, sizeof(futuregrid));


                for (b = 0; b < row; b++) {
                  for (c = 0; c < column; c++) {
                      neighbour = 0;
                  /*add up all the neighbour in the 3 by 3 surrounding grid*/

                      for (r = -1; r < 2; r++) {
                        for ( s = -1; s < 2; s++) {

                          if (((b+r) > -1 && (c+s) > -1)  && ((b+r) < row && (c+s) <column) && (r != 0 || s != 0)){
                              neighbour += currentgrid[b+r][c+s];
                          }
                        }
                      }



                        if ((currentgrid[b][c] == 1) && ( neighbour < 2)) {
                        futuregrid[b][c]= 0;
                      }else if ((currentgrid[b][c] == 1) && ( neighbour > 3)) {
                           futuregrid[b][c]= 0;
                        }else if (((currentgrid[b][c] == 0) && ( neighbour == 3))) {
                           futuregrid[b][c]= 1;
                        }
                      /* else if ((currentgrid[b][c] == 1) && ( neighbour == 3|| neighbour ==2)) {
                        futuregrid[b][c]= 1 ;
                      } */ else{
                        futuregrid[b][c] = currentgrid[b][c];
                      }




                    }
                  }


                  if(memcmp(currentgrid, futuregrid,sizeof(futuregrid))==0){
                    exit(0);
                  }




                      for (x = 0; x < row; x++) {
                        for ( j = 0; j < column; j++) {
                          if (futuregrid[x][j] == 1 ) {
                            (displaygrid[x][j] = 'X');
                          }
                          if (futuregrid[x][j] == 0) {
                            (displaygrid[x][j] = ' ');
                          }
                        }
                      }
                      tick++;

                          system("clear");
                          printf(" ");
                          for ( t = 0; t < column; t++) {
                           printf("-" );
                         } printf("\n");

                            for (a = 0; a < row; a++) {
                              printf("|");

                                for ( b = 0; b < column; b++) {
                                printf("%c",displaygrid[a][b] );
                                }
                                printf("|\n" );
                            }
                            printf(" ");
                            for ( t = 0; t < column; t++) {
                             printf("-" );
                           } printf("%d\n", tick);

                          system("sleep 0.25");





}
printf("Continue?(y or n)\n");
    scanf("%s", p);
    if (strcmp("n",p)==0){
      return 0;

    }
}
  while (strcmp("y",p)==0);

}
else if
  (strcmp("n",p)==0){
    return 0;
}
  return 0;
}
