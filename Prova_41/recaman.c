#include <stdio.h>
#include <stdlib.h>


unsigned long long Reca(int n,int dim,unsigned long long an) {
    if (dim == n) {
        return an;
    }
    if ((an % dim) == 0) {
        return Reca(n,dim+1,an/dim);
    }
    else {
        return Reca(n,dim+1,an*dim);
    }
}


int main(int argc, char *argv[]) {

    if (argc != 2) {
        fprintf(stdout,"%d\n",-1);
        return 1;
    }

    char *ptr;
    long num = strtol(argv[1],&ptr,10);
    if (num <1 || *ptr != '\0') {
        fprintf(stdout,"%d\n",-1);
        return 1;
    }

    num = (int)num;
    unsigned long long an = Reca(num,1,1);
    fprintf(stdout,"%llu\n",an);

    return 0;
}