#include <stdio.h>

int cut(int cost[], int n){
    int highprofit[n + 1]; //keep the max proft for every rod length
    for(int i = 0; i <= n; i = i + 1){
        highprofit[i] = 0;

        for(int k = 1; k <= i; k = k + 1){
            if(highprofit[i] < cost[k - 1] + highprofit[i - k]){
                highprofit[i] = cost[k - 1] + highprofit[i - k];//lowest profit gets overwrritten to max profit
            }
        }
    }
    return highprofit[n]; // returns the max proft for orginal length back to cut(cost,i)
}

int main() {
   
    int rod_lgth;

    int cost[rod_lgth];//stores the cost of each rod length

    printf("Enter the length of the rod: ");
    scanf_s("%d", &rod_lgth);

   

    //Line 13-15 reads the prices for each rod length from the users input
    printf("Enter prices of each rod length: ");
    for(int i = 0; i < rod_lgth; i = i +1){
        scanf_s("%d", &cost[i]); 
        //reads each rods length cost
    }

    //Array to hold max proft+ for every rod length to cal the max profit
    int maxworth[rod_lgth + 1];
    maxworth[0] = 0;
    for(int i = 1; i <= rod_lgth; i = i + 1) {
        maxworth[i] = cut(cost,i); //cut function to find the ma profit
    }

    //outputs cuts produced and their own value
    int length = rod_lgth;
    while(length > 0) {
        for(int i = 1; i <= length; i++){
            if(maxworth[length] == cost[i-1]+ maxworth[length-i]){
                printf("1 @ %d = %d\n",i, cost[i-1]);
                length = length - i;// subtratcs new cut length from the original length
                break;//stop unneeded forloops
            }
        }
    }
    // Prints out rod length remainder and max value for every cut
    printf(" Test1: The remainder is %d\n", length);
    printf("Max value: %d\n", maxworth[rod_lgth]);

    return 0;
   
}
