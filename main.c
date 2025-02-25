#include <stdio.h>

#define Max_length 1000

void initialize_arrays(int Full_rod_length, int lengths[], int dynamic[], int cut[]){
    for(int i = 0; i <= Full_rod_length; i++){
        dynamic[i] = 0; // array with no value at the start of the program
        cut[i] = -1;    //array with not cuts
    }
}

void max_calculation(int Full_rod_length, int lengths[], int values_of_piece[], int dynamic[], int number_of_pieces, int cut[]){
    //loops all through to the full rod length from 1 to n(full rod length)
    //second loop goes to each piece from the input
    for(int i = 1; i <= Full_rod_length; i++){
        for(int j = 0; j < number_of_pieces; j++){
            if(lengths[j] <= i && dynamic[i] < values_of_piece [j] + dynamic[i - lengths[j]]) {
                dynamic[i] = values_of_piece[j] + dynamic[i - lengths[j]];   //store max value if the piece fits and has a high value
                cut[i] = j; //store the index of the max value cut
            }
        }
    }
}

void print_results(int Full_rod_length, int lengths[], int dynamic[], int values_of_piece[], int cut[]){
    int total_value = 0;
    printf("Results:\n");

    while(Full_rod_length > 0 && cut[Full_rod_length] != -1){
        int cut_index = cut[Full_rod_length];    //
        int cut_length = lengths[cut_index];    //recieve the length of the piece that was cut
        int cut_value = values_of_piece[cut_index];  //recieve the value that the piece was cut

        printf("%d @ %d = %d\n", cut_length, cut_value, total_value);
        total_value += cut_value;   //add cut to total
        Full_rod_length -= cut_length;   //subbract length of the cut piece from the reamining rod length
    }

    printf("Remainder: %d\n", Full_rod_length); 
    
    printf("Total value: %d\n", total_value);

    if(Full_rod_length >0){
        printf("Remaining rod length: %d\n", Full_rod_length);
    }
    else if(total_value == 0){
        printf("No cuts have been made");
    }

}

int main(){
    int Full_rod_length = 0; //store the rod length
    int lengths[Max_length]; //store pieces length in the array
    int values_of_piece[Max_length]; //store to the values_of_piece of the pieces
    int number_of_pieces = 0; //number of pieces entered

    printf("Enter the length of the rod: ");
    scanf("%d", &Full_rod_length);

    //pass or not pass rod length input to see if it's valid
    if(Full_rod_length <= 0){
        printf("Invalid Rod Length\n");
        return 0;
    }
    else if(Full_rod_length > Max_length){
        printf("Rod length passes max limit\n");
        return 0; 
    }

    printf("Enter rod length piece and each value such as num_num:\n");

    //ask input the lengths and values_of_piece of each piece
    while(scanf("%d %d", &lengths[number_of_pieces], &values_of_piece[number_of_pieces]) == 2){
        if(lengths[number_of_pieces] <= 0 || values_of_piece[number_of_pieces] <= 0){
            printf("Invalid input\n");
            return 0;
        }

        number_of_pieces++;

        //Pass or not pass the number of pieces pass the max limit
        if(number_of_pieces >= Max_length){
            printf("Maximum number of pieces exceeded\n");
            return 0;

        }
    }

    //Initialize dynamic and cut arrays
    int dynamic[Full_rod_length +1];
    int cut[Full_rod_length +1];

    initialize_arrays(Full_rod_length, lengths, dynamic, cut);
    max_calculation(Full_rod_length, lengths, values_of_piece, dynamic, number_of_pieces, cut);
    print_results(Full_rod_length, lengths, dynamic, values_of_piece, cut);

}