#include<stdio.h>

typedef struct vehicle
{
    double truck;
    char car[50];
    float bike;
}transport_t;

int main()
{
    transport_t bmw ;//= {500,"350d",2.30};
    bmw.truck;
    bmw.car[50];
    bmw.bike;

    printf("Enter Truck: ");
    scanf("%le",&bmw.truck);
    printf("\nEnter Car: ");
    scanf("%s",bmw.car);
    printf("\nBike: ");
    scanf("%f",&bmw.bike);

    printf("\nTRUCK: %f\nCAR: %s\nBIKE: %f\n",bmw.truck,bmw.car, bmw.bike);

    return 0;
}