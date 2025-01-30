#include<iostream>
#include<sstream>
#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include<cstdlib>
#include<sqlite3.h>
static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
   int i;
   for(i = 0; i<argc; i++) {
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   printf("\n");
   return 0;
}


int main()
{
	system("clear");
	sqlite3 *db;
	char  *zErrMsg=0;
	int rc;
	std::ostringstream sql;

	rc=sqlite3_open("pass.db",&db);

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
	sql<<"INSERT INTO pass(user,password,descripcion) VALUES('"<<cifrado<<"'"<<
		cifrado<<"'"<<cifrado<<"');";
	rc=sqlite3_exec(db,sql.str().c_str(),callback,0,&zErrMsg);
	return 0;
}
