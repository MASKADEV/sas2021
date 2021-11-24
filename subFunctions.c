#include <stdio.h>


void generateInvoice (char option[40], char nom[50], char prenom[50], char cin[50], float montant){
    printf("\n\n\n");
    printf("\n\n==================================");
    printf("\n\tFacture de %s",option);
    printf("\n==================================");
    printf("\n\nNom: %s",nom);
    printf("\nPrenom: %s",prenom);
    printf("\nCarte Identification: %s",cin);
    printf("\n\n==================================");
    printf("\n\tMontant: %.2f DH",montant);
    printf("\n==================================");
}