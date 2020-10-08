#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NumberRowSokobanLevel  8
#define NumberColSokobanLevel  4

void GetMainInfoSokobanFile(int ArrayLevelSokoban[NumberRowSokobanLevel][NumberColSokobanLevel]);

int main()
{
int ArrayLevelSokoban[NumberRowSokobanLevel][NumberColSokobanLevel]={0};

GetMainInfoSokobanFile(ArrayLevelSokoban);

GetMapInfo();


return 0;
}

// cart à rajouter dans les arguments. colonne et fenetre change à chaque event. Compatible SDL?
void GetMapInfo(int Level, int ArrayLevelSokoban[NumberRowSokobanLevel][NumberColSokobanLevel])
{
FILE *stream;
char str[60];
stream = fopen("soloban01.txt", "r+");

	if (stream == NULL)
	{
		printf("Problem with Files\n");
		exit(1);
	}
	else
	{

		printf("The file  was opened\n");
		fseek(stream,ArrayLevelSokoban[Level-1][3] , SEEK_SET );
		while (fgets(str, 60, stream) != NULL)
		{
			if (strlen(str) < 2)
				break;

			else
			{
				for (i = 0; i < row; i++)

			switch (str[i])
			{
			case '0':
				carte[i][j] = 0;
				break;
			case '1':
				carte[i][j] = 1;
				break;
			case '2':
				carte[i][j] = 2;
				break;
			case '3':
				carte[i][j] = 3;
				break;
			case '4':
				carte[i][j] = 4;
				break;
			}
		}
	}
			}
			
		}


}



void GetMainInfoSokobanFile(int ArrayLevelSokoban[NumberRowSokobanLevel][NumberColSokobanLevel])
{
	FILE *stream;

	char str[60];
	int Height = 0;
	int Length = 0;
	long BeginArray[8]={0};

// first loop to get the correct size of each sokoban and write it in a file.
	int NumberSokoban = 0;
	int Compteur=0;

	stream = fopen("soloban01.txt", "r+");

	if (stream == NULL)
	{
		printf("Problem with Files\n");
		exit(1);
	}
	else
	{

		printf("The file  was opened\n");

		while (fgets(str, 60, stream) != NULL)
		{
			if (strlen(str) < 2)
			{
				NumberSokoban++;
				BeginArray[NumberSokoban]=ftell(stream);
				printf("Sokoban Numero %d, longueur %d, hauteur %d, seek %ld\n", NumberSokoban, Length, Height,BeginArray[NumberSokoban-1]);
				
				ArrayLevelSokoban[Compteur][0]=NumberSokoban;
				ArrayLevelSokoban[Compteur][1]=Length;
				ArrayLevelSokoban[Compteur][2]=Height;
				ArrayLevelSokoban[Compteur][3]=BeginArray[NumberSokoban-1];ArrayLevelSokoban[1][Compteur];
				
				Height = 0;
				Length = 0;
				Compteur++;
			}
		//	printf("longueur de ligne identique?%d\n",strlen(str));
			Length = strlen(str)-1;
			Height++;
		}

		// fseek(stream, 2005, SEEK_SET);
		// fgets(str, 60, stream);
		// printf(str);

		int err_1 = fclose(stream);


		if (err_1 == 0 )
		{
			printf("File closed");
		}

		else
		{
			printf("problem closing file");
		}

	}
}



// int NumberSokoban = 0;
// int Curseur=0;

// stream = fopen("soloban01.txt", "r+");
// stream_2 = fopen("Level.txt", "w+");
// stream_3 = fopen("Taille.txt", "r+");

// 	if (stream == NULL || stream_2 == NULL || stream_3 == NULL)
// 	{
// 		printf("Problem with Files\n");
// 		exit(1);
// 	}
// 	else
// 	{

// 		printf("The files  were  opened\n");

// 		while (fgets(str, 60, stream) != NULL)
// 		{
// 			if (strlen(str) < 2)
// 			{
// 				NumberSokoban++;
// 				fputc('\n', stream_2);
// 			}
// 			else
// 			{
// 				fseek(stream_3, Curseur, SEEK_SET );
// 				fgets(TailleFichier, 3, stream_3);
// 				int Longueur = atoi(TailleFichier);
// 				int LongueurChaine=strlen(str);
// 				if (LongueurChaine<Longueur)
// 				{
// 					int Difference=Longueur-LongueurChaine;

// 				}



// 			for (int i = 0; i < Longueur; i++)
// 			{
// 				switch (str[i])
// 				{
// 				case ' ':
// 					fputc('0', stream_2);
// 					break;
// 				case '#':
// 					fputc('1', stream_2);
// 					break;
// 				case '$':
// 					fputc('2', stream_2);
// 					break;
// 				case '.':
// 					fputc('3', stream_2);
// 					break;
// 				case '@':
// 					fputc('4', stream_2);
// 					break;
// 				case '*':
// 					fputc('5', stream_2);
// 					break;
// 				case '+':
// 					fputc('6', stream_2);
// 					break;
// 				}
// 			}





// 		Curseur=Curseur+7;/* code */
// 			}
			

// 		}


















// 	stream = fopen("soloban01.txt", "r+");
// 	stream_2 = fopen("Level.txt", "w+");
// 	stream_3 = fopen("Taille.txt", "r+");

// 	if (stream == NULL || stream_2 == NULL || stream_3 == NULL)
// 	{
// 		printf("Problem with Files\n");
// 		exit(1);
// 	}

// 	else

// 	{
// 		int Curseur=0;	
// 		// fseek(stream_3, Curseur, SEEK_SET );
// 		// fgets(TailleFichier, 3, stream_3);
// 		// printf("\n");
// 		// int Longueur = atoi(TailleFichier);
// 		// printf ("Longueur ligne=%d",Longueur);





// 		for (int i=0;i<8;i++)
// 		{
// 		fseek(stream_3, Curseur, SEEK_SET );
// 		fgets(TailleFichier, 3, stream_3);
// 		printf("\n");
// 		//printf(TailleFichier);
// 		int Longueur = atoi(TailleFichier);
// 		printf ("Longueur ligne=%d",Longueur);
// 		Curseur=Curseur+7;
// 		}


// 		while (fgets(TailleFichier, 60, stream_3) != NULL)	
// 		{
// 		printf(TailleFichier);
// 		}

// 		int err_1 = fclose(stream);
// 		int err_2 = fclose(stream_2);
// 		int err_3 = fclose(stream_3);

// 		if (err_1 == 0 && err_2 == 0 && err_3 == 0)
// 		{
// 			printf("Files closed");
// 		}

// 		else
// 		{
// 			printf("problem closing files");
// 		}

// 		return 0;
// 	}
// }

// 	}

// 			for (int i = 0; i < strlen(str); i++)
// 			{
// 				switch (str[i])
// 				{
// 				case ' ':
// 					fputc('0', stream_2);
// 					break;
// 				case '#':
// 					fputc('1', stream_2);
// 					break;
// 				case '$':
// 					fputc('2', stream_2);
// 					break;
// 				case '.':
// 					fputc('3', stream_2);
// 					break;
// 				case '@':
// 					fputc('4', stream_2);
// 					break;
// 				case '*':
// 					fputc('5', stream_2);
// 					break;
// 				case '+':
// 					fputc('6', stream_2);
// 					break;
// 				}
// 			}

// 			ArrayLength[Height] = strlen(str);
// 			//	printf("Longueur %d \n", ArrayLength[Height]);
// 			Height++;
// 		}

// 		int err_1 = fclose(stream);
// 		int err_2 = fclose(stream_2);
// 		int err_3 = fclose(stream_3);

// 		if (err_1 == 0 && err_2 == 0 && err_3 == 0)
// 		{
// 			printf("Files closed");
// 		}

// 		else
// 		{
// 			printf("problem closing files");
// 		}

// 		return 0;
// 	}
// }

int largest(int arr[], int n)
{
	int i;

	// Initialize maximum element
	int max = arr[0];

	// Traverse array elements from second and
	// compare every element with current max
	for (i = 1; i < n; i++)
		if (arr[i] > max)
			max = arr[i];

	return max;
}