#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int largest(int arr[], int n);

int main(void)
{

	FILE *stream;
	FILE *stream_2;
	FILE *stream_3;

	char str[60];
	char TailleFichier[60];

	int Height = 0;
	int Length = 0;
	int ArrayLength[30];
	long BeginArray[8]={0};


// first loop to get the correct size of each sokoban and write it in a file.
	int NumberSokoban = 0;

	stream = fopen("soloban01.txt", "r+");
	stream_2 = fopen("Level.txt", "w+");
	stream_3 = fopen("Taille.txt", "w+");

	if (stream == NULL || stream_2 == NULL || stream_3 == NULL)
	{
		printf("Problem with Files\n");
		exit(1);
	}
	else
	{

		printf("The files  were  opened\n");

		Length = largest(ArrayLength, Height);

		while (fgets(str, 60, stream) != NULL)
		{
			if (strlen(str) < 2)
			{
				NumberSokoban++;
				BeginArray[NumberSokoban]=ftell(stream);
				fputc('\n', stream_2);
				Length = largest(ArrayLength, Height)-1;
				fprintf(stream_3, "%d", Length);
				fputc(' ', stream_3);
				fprintf(stream_3, "%d", Height);
				fputc('\n', stream_3);
				printf("Sokoban Numero %d, longueur %d, hauteur %d, seek %ld\n", NumberSokoban, Length, Height,BeginArray[NumberSokoban-1]);
				Height = 0;
				Length = 0;
			}
		//	printf("longueur de ligne identique?%d\n",strlen(str));
			ArrayLength[Height] = strlen(str);
			Height++;
		}

		fseek(stream, 2005, SEEK_SET);
		fgets(str, 60, stream);
		printf(str);


		int err_1 = fclose(stream);
		int err_2 = fclose(stream_2);
		int err_3 = fclose(stream_3);

		if (err_1 == 0 && err_2 == 0 && err_3 == 0)
		{
			printf("Files closed");
		}

		else
		{
			printf("problem closing files");
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