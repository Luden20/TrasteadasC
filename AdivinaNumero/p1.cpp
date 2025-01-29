#include  <stdio.h>
#include <cstdio>
#include <random>
int main()
{
	std::random_device random;
	std::mt19937 motor(random());
	std::uniform_int_distribution<int>  aleatorios(-100,100);
	int buscado=aleatorios(motor);

	printf("Adivina el numero");
	for(int x=0;x<10;x++)
	{
		int aux;
		printf("Intento n %d\n",x+1);
		scanf("%d",&aux);
		if(aux>buscado)
		{
			printf("El numero buscado es mas peque\n");
		}
		else if(aux<buscado)
		{
			printf("EL numero buscado es mas mayor xd\n");
		}
		else
		{
			printf("Acertaste");
			return 0;
		}
	}
	printf("El numero era %d\n",buscado);
	return 0;
}
