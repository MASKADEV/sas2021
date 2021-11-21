#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Global Variable
int clientsIndex = 0;

typedef struct clients
{
    char cin[40];
    char nom[40];
    char prenom[40];
    int montant;
} clients;

clients client[];

//Main Screen
void menuList()
{
    printf("\n\n\t--------------- Menu ---------------");
    printf("\n\n\n1. Introduire un compte bancaire");
    printf("\n2. Introduire plusieurs comptes bancaires");
    printf("\n3. Operations");
    printf("\n4. Affichage");
    printf("\n5. Fidélisation");
    printf("\n6. Quitter l’application");
}

//add clients Screen
void addClients(int option)
{

    int clientsNumber;
    switch (option)
    {
    case 1:
        printf("\nplease enter client name:\t");
        scanf("%s", client[clientsIndex].nom);
        printf("\nplease enter client prenom:\t");
        scanf("%s", client[clientsIndex].prenom);
        printf("\nplease enter client ID:\t");
        scanf("%s", client[clientsIndex].cin);
        printf("\nplease enter client montant:\t");
        scanf("%d", &client[clientsIndex].montant);
        clientsIndex++;
        for (int i = 0; i < clientsIndex; i++)
        {
            printf("\nnom:\t%s", client[i].nom);
        }
        break;
    case 2:
        printf("how much clients you want to add:\t");
        scanf("%d", &clientsNumber);
        for (int i = 0; i < clientsNumber; i++)
        {
            printf("\nplease enter client name:\t");
            scanf("%s", client[clientsIndex].nom);
            printf("\nplease enter client prenom:\t");
            scanf("%s", client[clientsIndex].prenom);
            printf("\nplease enter client ID:\t");
            scanf("%s", client[clientsIndex].cin);
            printf("\nplease enter client montant:\t");
            scanf("%d", &client[clientsIndex].montant);
            clientsIndex++;
        }
        for (int i = 0; i < clientsIndex; i++)
        {
            printf("\nnom:\t%s", client[i].nom);
        }
    default:
        break;
    }
}

//Operations Screen
void operations()
{
    int currentIndex, choice, retraitmonant;
    char currentID[40];

    // system("clear");
    printf("\n\n\t-------- Operations ----------");
    printf("\n\n1. Retrait");
    printf("\n2. Deposer");
    printf("\n\nplease select your preffered option:\t");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        // system("clear");
        printf("\n\n\t-------- Retrait operation ----------");
        printf("\n\n\n\nplease enter client id:\t");
        scanf("%s", currentID);
        for (int i = 0; i <= clientsIndex; i++)
        {
            if (strcmp(client[i].cin, currentID) == 0)
            {
                currentIndex = i;
                printf("\ncurrent balnce:%d", client[currentIndex].montant);
                printf("\nplease enter the amount you want to widthraw:\t");
                scanf("%d", &retraitmonant);
                if (retraitmonant <= client[currentIndex].montant)
                {
                    client[currentIndex].montant -= retraitmonant;
                }
                return;
            }
        }
        printf("id not found please try anothe one!");
        break;
    case 2:
        // system("clear");
        printf("\n\n\t-------- Deposer operation ----------");
        printf("\n\n\n\nplease enter client id:\t");
        scanf("%s", currentID);
        for (int i = 0; i <= clientsIndex; i++)
        {
            if (strcmp(client[i].cin, currentID) == 0)
            {
                currentIndex = i;
                printf("\ncurrent balnce:%d", client[currentIndex].montant);
                printf("\nplease enter the amount you want to Deposer:\t");
                scanf("%d", &retraitmonant);
                client[currentIndex].montant += retraitmonant;
                return;
            }
        }
        printf("id not found please try anothe one!");
        break;
    default:
        break;
    }
}

//affichage Screen
void affichage()
{
    int choice;
    int index, j;
    char cin[40];
    clients clientTemp;
    // system("clear");
    printf("\n\n\t-------- Operations ----------");
    printf("\n\n1. Par Ordre Ascendant");
    printf("\n2. Par Ordre Descendant");
    printf("\n3. Par Ordre Ascendant (montant superieur)");
    printf("\n4. Par Ordre Descendant (montant superieur)");
    printf("\n5. Recherche par CIN");

    printf("\n\nplease select your preffered choice:\t");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        for (int i = 0; i < 255; i++)
        {
            for (int j = 0; j < clientsIndex; j++)
            {
                if (client[j].nom[0] == i)
                {
                    printf("\n%s", client[j].nom);
                }
            }
        }
        break;
    case 2:
        for (int i = 254; i >= 0; i--)
        {
            for (int j = 0; j < clientsIndex; j++)
            {
                if (client[j].nom[0] == i)
                {
                    printf("\n%s", client[j].nom);
                }
            }
        }
        break;
    case 3:
        for (int i = 0; i <= clientsIndex; i++)
        {
            index = i;
            for (j = i + 1; j < clientsIndex; j++)
            {
                if (client[index].montant < client[j].montant)
                {
                    index = j;
                }
            }
            if (index != i)
            {
                clientTemp = client[i];
                client[i] = client[index];
                client[index] = clientTemp;
            }
        }
        for (int k = 0; k < clientsIndex; k++)
        {
            printf("\n\nclient %d infos:", k + 1);
            printf("\nnom:\t%s", client[k].nom);
            printf("\nprenom:\t%s", client[k].prenom);
            printf("\nCIN:\t%s", client[k].cin);
            printf("\nmontant:\t%d", client[k].montant);
        }
        break;
    case 4:
        for (int i = 0; i < clientsIndex; i++)
        {
            index = i;
            for (j = i + 1; j < clientsIndex; j++)
            {
                if (client[index].montant > client[j].montant)
                {
                    index = j;
                }
            }
            if (index != i)
            {
                clientTemp = client[i];
                client[i] = client[index];
                client[index] = clientTemp;
            }
        }
        for (int k = 0; k < clientsIndex; k++)
        {
            printf("\n\nclient %d infos:", k + 1);
            printf("\nnom:\t%s", client[k].nom);
            printf("\nprenom:\t%s", client[k].prenom);
            printf("\nCIN:\t%s", client[k].cin);
            printf("\nmontant:\t%d", client[k].montant);
        }
        break;
    case 5:
        printf("\n\n\tplease enter CIN:\t");
        scanf("%s", cin);
        for (int i = 0; i < clientsIndex; i++)
        {
            if (strcmp(client[i].cin, cin) == 0)
            {
                system("clear");
                printf("\n\nclient info:");
                printf("\nnom:\t%s", client[i].nom);
                printf("\nprenom:\t%s", client[i].prenom);
                printf("\nCIN:\t%s", client[i].cin);
                printf("\nmontant:\t%d", client[i].montant);
            }
        }
    default:
        break;
    }
}

//Fideliation
void fedilisation()
{
    int index, j;
    clients clientTemp;
    for (int i = 0; i <= clientsIndex; i++)
    {
        index = i;
        for (j = i + 1; j < clientsIndex; j++)
        {
            if (client[index].montant < client[j].montant)
            {
                index = j;
            }
        }
        if (index != i)
        {
            clientTemp = client[i];
            client[i] = client[index];
            client[index] = clientTemp;
        }
    }
    for (int k = 0; k < 3; k++)
    {
        client[k].montant = client[k].montant + (client[k].montant * 0.013);
    }
    for (int k = 0; k < clientsIndex; k++)
    {
        if (k == 0 || k == 1 || k == 2)
        {
            printf("\n\nclient %d infos:", k + 1);
            printf("\nnom:\t%s", client[k].nom);
            printf("\nprenom:\t%s", client[k].prenom);
            printf("\nCIN:\t%s", client[k].cin);
            printf("\nmontant:\t%d", client[k].montant);
        }
        if (k >= 3)
        {
            return;
        }
    }
}

int main()
{
    system("clear");
    while (1)
    {
        int choice;
        menuList();
        printf("\n\nplease select your preffered option:\t");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            addClients(1);
            break;
        case 2:
            addClients(2);
            break;
        case 3:
            operations();
            break;
        case 4:
            affichage();
            break;
        case 5:
            fedilisation();
            break;
        case 6:
            exit(0);
        case 7:
            for (int i = 0; i < clientsIndex; i++)
            {
                printf("\nclients nom:\t%s", client[i].nom);
                printf("\n%d", client[i].montant);
            }
        default:
            break;
        }
    }

    return 0;
}