#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include<cstdlib>
int main()
{
	system("clear");
	char *dato;
	dato=(char *)calloc(100,sizeof(char));
	char *cifrado;
	cifrado=(char *)calloc(100,sizeof(char));
	char *descifrado;
	descifrado=(char *)calloc(100,sizeof(char));
	char clave='K';
	printf("Ingrese algo...\n");
	fgets(dato,100,stdin);
	int i;
	for( i=0;dato[i]!='\0';i++)
	{
		cifrado[i]=dato[i]^clave;
	}
	printf("%s\n",cifrado);
	for(i=0;cifrado[i]!='\0';i++)
	{
		descifrado[i]=cifrado[i]^clave;
	}
	descifrado[i+1]='\0';
	printf("\n%s\n",descifrado);
	int longitud = strlen(dato);
	free(dato);
	free(cifrado);
	free(descifrado);
	return 0;
}
