#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Customer {
    int account_number;
    char name[50];
    float balance;
};

int main() {
    FILE *inputfile;
    struct Customer user1;
    inputfile = fopen("personinfo.dat", "r");
    while(fread(&user1, sizeof(struct Customer), 1, inputfile)) {
        printf("%d & %s & %f", user1.account_number, user1.name, user1.balance);
    }
}
