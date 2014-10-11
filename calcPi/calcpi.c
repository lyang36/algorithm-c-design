#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, const char* argv[]){
    if(argc != 3){
        printf("Usage: %s <delta> <eps>\n", argv[0]);
        printf("Calculate Pi within (1+delta) error with prob less than eps\n");
        exit(0);
    }
    double delta = atof(argv[1]);
    double eps = atof(argv[2]);
    int n = log(1.0 / eps) * 3.0 / delta / delta * 4.0 / 3.0;
    printf("Number of iterations: %d\n", n);

    double counts = 0;

    /* initialize the random seed */
    srand(time(NULL));

    for(int i = 0; i < n; i ++){
       double x = (double) rand() / ((double) RAND_MAX);
       double y = (double) rand() / ((double) RAND_MAX);
       if((x-0.5) * (x-0.5) + (y-0.5)*(y-0.5) < 0.5*0.5){
            counts ++;
       }
    }

    double pi = counts / n * 4.0;
    printf("Gets: %f with error %f\n", 
                    pi, 
                    (pi - 3.1415926535897932384626333)/3.1415926535897932384626333);
}
