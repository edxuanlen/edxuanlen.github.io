# include <stdio.h>

int a[4][4];

int main() {
    for(int i = 0; i < 3; i ++)
        for(int j = 0; j < 3; j ++)
            scanf ("%d", &a[i][j]);

    int Min = 0x3f3f3f;
    bool lesslevel = false;

    for(int i = 0; i < 3; i ++){
        int sum = 0;
        for(int j = 0; j < 3; j ++){
            // sum = a[0][i];
            // sum += a[1][j];
            for(int k = 0; k < 3; k ++){
                sum = a[0][i] + a[1][j] + a[2][k];
                // printf ("%d \n", sum);
                if( sum <= 0 ){
                    printf("The monster is too weak...");
                    return 0;
                } else if( sum <= 40 ){
                    lesslevel = true;
                } else if( sum < 100 ) {
                    if( Min > sum ) Min = sum;
                }
            }
        }
    }

    if(Min != 0x3f3f3f ) printf("The brave still has %dHP left to face the BOSS", 100 - Min);
    else if( lesslevel ) printf("why don't give the brave a chance to level up...");
    else printf("The brave died on the way to leveling...");

    return 0;
}