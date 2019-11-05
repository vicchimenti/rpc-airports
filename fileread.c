#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 167

FILE *in_file;
char line[MAX_SIZE];

//a struct that will contain our city, state, lat, long info
struct city {
    char state[3]; 
    char city[63]; 
    double lat, lon;
};

//Count the number of lines in the file
int countLinesInFile() {
    in_file = fopen("places2k.txt", "r");
    if(in_file == NULL){
        fprintf(stderr, "Unable to open file");
        exit(EXIT_FAILURE);
    }
    int counter = 0; 
    while(fgets(line, sizeof(line), in_file) != NULL){
        counter++;
    }
    return counter;
}

int main(void) {

    //get the number of lines in the file
    int numLines = countLinesInFile();
    printf("number of lines in file: %i\n", numLines);

    //initialize an array of city structs the size of the number of lines in file
    struct city cities[numLines];

    in_file = fopen("places2k.txt", "r");
    if(in_file == NULL){
        fprintf(stderr, "Unable to open file");
        exit(EXIT_FAILURE);
    }
    int counter = 0; 
    while(fgets(line, sizeof(line), in_file) != NULL) {
        char state[3];
        char city[64];
        char lat[10];
        char lon[10];
        memcpy(state, &line[0], 2);
        memcpy(city, &line[9], 72);
        memcpy(lat, &line[143], 9);
        memcpy(lon, &line[153], 9);
        state[2] = '\0';
        city[63] = '\0';
        lat[9] = '\0';
        lon[9] = '\0';
        double d_lon = atof(lon);
        double d_lat = atof(lat);
        strcpy(cities[counter].state, state);
        strcpy(cities[counter].city, city);
        cities[counter].lat = d_lat;
        cities[counter].lon = d_lon;

        counter++;
        //printf("%f ", atof(lat));
  
    }
    printf("first city is: %f\n", cities[10].lat);
    return 0;
}