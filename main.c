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
    float montant;
} clients;

clients client[];

//Main Screen
void menuList()
{
    system("cls");
    char title[]= "\n\n\t--------------- Menu ---------------";
    char choice1[] = "\n\n\n1. Introduire un compte bancaire";
    char choice2[] = "\n2. Introduire plusieurs comptes bancaires";
    char choice3[] = "\n3. Operations";
    char choice4[] = "\n4. Affichage";
    char choice5[] = "\n5. Fidelisation";
    char choice6[] = "\n6. Quitter lapplication";
    printf("\n\n");
    for(int x=0; title[x]!='\0'; x++)
   {
     printf("%c",title[x]);
      for(double y = 0; y <= 8000000; y++)
      {
      }
   }
    for(int x=0; choice1[x]!='\0'; x++)
   {
     printf("%c",choice1[x]);
      for(double y = 0; y<=4500000; y++)
      {
      }
   }
    for(int x=0; choice2[x]!='\0'; x++)
   {
     printf("%c",choice2[x]);
      for(double y = 0; y<=4500000; y++)
      {
      }
   }
    for(int x=0; choice3[x]!='\0'; x++)
   {
     printf("%c",choice3[x]);
      for(double y = 0; y<=4500000; y++)
      {
      }
   }
    for(int x=0; choice4[x]!='\0'; x++)
   {
     printf("%c",choice4[x]);
      for(double y = 0; y<=4500000; y++)
      {
      }
   }
    for(int x=0; choice5[x]!='\0'; x++)
   {
     printf("%c",choice5[x]);
      for(double y = 0; y<=4500000; y++)
      {
      }
   }
    for(int x=0; choice6[x]!='\0'; x++)
   {
     printf("%c",choice6[x]);
      for(double y = 0; y<=4500000; y++)
      {
      }
   }

}

//add clients Screen
void addClients(int option)
{

    int clientsNumber;
    switch (option)
    {
    case 1:
        system("cls");
        printf("\nveuillez entrer le nom du client:\t");
        scanf("%s", client[clientsIndex].nom);
        printf("\nveuillez saisir le prenom du client:\t");
        scanf("%s", client[clientsIndex].prenom);
        printf("\nveuillez saisir votre identifiant client:\t");
        scanf("%s", client[clientsIndex].cin);
        printf("\nveuillez entrer le montant du client (DH):\t");
        scanf("%f", &client[clientsIndex].montant);
        clientsIndex++;
        break;
    case 2:
        system("cls");
        printf("combien de clients vous voulez ajouter:\t");
        scanf("%d", &clientsNumber);
        for (int i = 0; i < clientsNumber; i++)
        {
            printf("\nveuillez entrer le nom du client:\t");
            scanf("%s", client[clientsIndex].nom);
            printf("\nveuillez saisir le prenom du client:\t");
            scanf("%s", client[clientsIndex].prenom);
            printf("\nveuillez saisir votre identifiant client:\t");
            scanf("%s", client[clientsIndex].cin);
            printf("\nveuillez entrer le montant du client (DH):\t");
            scanf("%f", &client[clientsIndex].montant);
            clientsIndex++;
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

    system("cls");
    printf("\n\n\t-------- Operations ----------");
    printf("\n\n1. Retrait");
    printf("\n2. Deposer");
    printf("\n\nveuillez selectionner votre option preferee:\t");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        system("cls");
        printf("\n\n\t-------- Retrait operation ----------");
        printf("\n\n\n\nVeuillez saisir CIN du client:\t");
        scanf("%s", currentID);
        for (int i = 0; i <= clientsIndex; i++)
        {
            if (strcmp(client[i].cin, currentID) == 0)
            {
                currentIndex = i;
                printf("\nSolde actuel:%.2f DH", client[currentIndex].montant);
                printf("\nveuillez saisir le montant que vous souhaitez retirer:\t");
                scanf("%d", &retraitmonant);
                if (retraitmonant <= client[currentIndex].montant)
                {
                    client[currentIndex].montant -= retraitmonant;
                }
                return;
            }
        }
        printf("CIN introuvable s'il vous plaît essayez-en un autre!");
        getch();
        break;
    case 2:
        system("cls");
        printf("\n\n\t-------- Deposer operation ----------");
        printf("\n\n\n\nsil vous plaît entrer CIN du client:\t");
        scanf("%s", currentID);
        for (int i = 0; i <= clientsIndex; i++)
        {
            if (strcmp(client[i].cin, currentID) == 0)
            {
                currentIndex = i;
                printf("\nSolde actuel:%.2f DH", client[currentIndex].montant);
                printf("\nveuillez saisir le montant que vous souhaitez deposer:\t");
                scanf("%d", &retraitmonant);
                client[currentIndex].montant += retraitmonant;
                return;
            }
        }
        printf("CIN introuvable s'il vous plaît essayez-en un autre!");
        getch();
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
    char minstr[50];

    system("cls");
    printf("\n\n\t-------- Operations ----------");
    printf("\n\n1. Par Ordre Ascendant");
    printf("\n2. Par Ordre Descendant");
    printf("\n3. Par Ordre Ascendant (par montant)");
    printf("\n4. Par Ordre Descendant (par montant)");
    printf("\n5. Recherche par CIN");

    printf("\n\nveuillez selectionner votre choix prefere:\t");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        for(int i = 0; i < clientsIndex; i++)
        {
            int index = i;
            strcpy(minstr, client[i].nom);
            for(j = i + 1; j < clientsIndex; j++)
            {
                if(strcmp(minstr, client[j].nom) < 0)
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
            printf("\n\ncliente %d infos:", k + 1);
            printf("\nnom: %s", client[k].nom);
            printf("\tprenom: %s", client[k].prenom);
            printf("\tCIN: %s", client[k].cin);
            printf("\tmontant: %.2f DH", client[k].montant);
        }
        getch();
        break;
    case 2:
        for(int i = 0; i < clientsIndex; i++)
        {
            int index = i;
            strcpy(minstr, client[i].nom);
            for(j = i + 1; j < clientsIndex; j++)
            {
                if(strcmp(minstr, client[j].nom) > 0)
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
            printf("\n\ncliente %d infos:", k + 1);
            printf("\nnom: %s", client[k].nom);
            printf("\tprenom: %s", client[k].prenom);
            printf("\tCIN: %s", client[k].cin);
            printf("\tmontant: %.2f DH", client[k].montant);
        }
        getch();
        break;
    case 3:
        for (int i = 0; i <= clientsIndex; i++)
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
            
            printf("\n\ncliente %d infos:", k + 1);
            printf("\nnom: %s", client[k].nom);
            printf("\tprenom: %s", client[k].prenom);
            printf("\tCIN: %s", client[k].cin);
            printf("\tmontant: %.2f DH", client[k].montant);
        }
        getch();
        break;
    case 4:
        for (int i = 0; i < clientsIndex; i++)
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
            printf("\n\ncliente %d infos:", k + 1);
            printf("\nnom: %s", client[k].nom);
            printf("\tprenom: %s", client[k].prenom);
            printf("\tCIN: %s", client[k].cin);
            printf("\tmontant: %.2f DH", client[k].montant);
        }
        getch();
        break;
    case 5:
        printf("\n\n\tsil vous plait entrer CIN:\t");
        scanf("%s", cin);
        for (int i = 0; i < clientsIndex; i++)
        {
            if (strcmp(client[i].cin, cin) == 0)
            {
                system("cls");
                printf("\n\ncliente info:");
                printf("\nnom:\t%s", client[i].nom);
                printf("\nprenom:\t%s", client[i].prenom);
                printf("\nCIN:\t%s", client[i].cin);
                printf("\nmontant:\t%.2f DH", client[i].montant);
                getch();
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
        if (k < 3)
        {
            printf("\n\ncliente %d infos:", k + 1);
            printf("\nnom: %s", client[k].nom);
            printf("\tprenom: %s", client[k].prenom);
            printf("\tCIN: %s", client[k].cin);
            printf("\tmontant: %.2f DH", client[k].montant);
        }
    }
}

int main()
{
    system("cls");
    while (1)
    {
        int choice;
        menuList();
        printf("\n\nveuillez selectionner votre option preferee:\t");
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
                printf("\ncliente nom:\t%s", client[i].nom);
                printf("\n%d", client[i].montant);
            }
        default:
            break;
        }
    }

    return 0;
}