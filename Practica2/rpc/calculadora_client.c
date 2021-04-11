/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

/**
 *	Autor: Raquel Molina Reche
 * 
 *	Compilación:  gcc calculadora_client.c calculadora_clnt.c calculadora_xdr.c -o cliente -lnsl
 */

#include "calculadora.h"
#include <stdio.h>

#define RESET_COLOR	"\x1b[0m"
#define NEGRO_T		"\x1b[30m"
#define NEGRO_F		"\x1b[40m"
#define ROJO_T		"\x1b[31m"
#define ROJO_F		"\x1b[41m"
#define VERDE_T		"\x1b[32m"
#define VERDE_F 	"\x1b[42m"
#define AMARILLO_T	"\x1b[33m"
#define AMARILLO_F	"\x1b[43m"
#define AZUL_T		"\x1b[34m"
#define AZUL_F		"\x1b[44m"
#define MAGENTA_T	"\x1b[35m"
#define MAGENTA_F	"\x1b[45m"
#define CYAN_T		"\x1b[36m"
#define CYAN_F		"\x1b[46m"
#define BLANCO_T	"\x1b[37m"
#define BLANCO_F	"\x1b[47m"

void
calculadoraprog_basicas(char *host, double a, char operation, double b)
{
	CLIENT *clnt;
	responseBasic  *result;

	//Se define la estructura operation que contiene los operandos a y b 
	// que será el argumento de las operaciones
	struct operationBasic operands;
	operands.first = a;
	operands.second = b;


	#ifndef	DEBUG
		clnt = clnt_create (host, CALCULADORAPROG, CALCULADORAVERS, "udp");
		if (clnt == NULL) {
			clnt_pcreateerror (host);
			exit (1);
		}
	#endif	/* DEBUG */

	//Se realiza la operacion según el tipo de operando
	switch (operation)
    {
        case '+': //Suma
            result = suma_1(operands, clnt);
			if (result == (responseBasic *) NULL) {
				clnt_perror (clnt, "call failed");
			}
            break;

        case '-'://Resta
           	result = resta_1(operands, clnt);
			if (result == (responseBasic *) NULL) {
				clnt_perror (clnt, "call failed");
			}
            break;

        case '*': //Multiplicacion
            result = multiplicacion_1(operands, clnt);
			if (result == (responseBasic *) NULL) {
				clnt_perror (clnt, "call failed");
			}
            break;

        case '/':  //Division
            result = division_1(operands, clnt);
			if (result == (responseBasic *) NULL) {
				clnt_perror (clnt, "call failed");
			}
            break;
		case 'l':
			result = logaritmo_1(operands, clnt);
			if (result == (responseBasic *) NULL) {
				clnt_perror (clnt, "call failed");
			}
			break;
		case '^':
			result = potencia_1(operands, clnt);
			if (result == (responseBasic *) NULL) {
				clnt_perror (clnt, "call failed");
			}
			break;
        
        default:
            break;
    }

	//Se muestra el resultado
	//printf("El resultado de la operación %f %c %f = %f\n", a, operation, b, result->responseBasic_u.result);
	printf(MAGENTA_T"%f"RESET_COLOR, result->responseBasic_u.result);
	

	//Se libera la memoria asignada por la llamada RPC
	xdr_free (xdr_responseBasic, result);

	#ifndef	DEBUG
		clnt_destroy (clnt);
	#endif	 /* DEBUG */
}

void
calculadoraprog_vectores(char *host, vectorData v1, char operation, vectorData v2)
{
	CLIENT *clnt;
	responseVectores  *result;
	responseBasic  *resultProdEscalar;

	//Se define la estructura operation que contiene los operandos v1 y v2 
	// que será el argumento de las operaciones
	struct operationVectores operands;
	operands.first = v1;
	operands.second = v2;

	#ifndef	DEBUG
		clnt = clnt_create (host, CALCULADORAPROG, CALCULADORAVERS, "udp");
		if (clnt == NULL) {
			clnt_pcreateerror (host);
			exit (1);
		}
	#endif	/* DEBUG */

	switch (operation)
    {
        case '+': //Suma
            result = sumavectores_1(operands, clnt);
			if (result == (responseVectores *) NULL) {
				clnt_perror (clnt, "call failed");
			}

            break;

        case '-'://Resta
           	result = restavectores_1(operands, clnt);
			if (result == (responseVectores *) NULL) {
				clnt_perror (clnt, "call failed");
			}
            break;
		default:
            break;
    }
	
	//Se muestra el resultado
	switch (operation)
    {
        case '+': //Suma
            //printf("El resultado de sumar los vectores es: ");
			for(int i = 0; i < result->responseVectores_u.vResult.vectorData_len; i++){
				printf(MAGENTA_T"%f  "RESET_COLOR, result->responseVectores_u.vResult.vectorData_val[i]);
			}
            break;

        case '-'://Resta
           	//printf("El resultado de restar los vectores es: ");
			for(int i = 0; i < result->responseVectores_u.vResult.vectorData_len; i++){
				printf(MAGENTA_T"%f  "RESET_COLOR, result->responseVectores_u.vResult.vectorData_val[i]);
			}
            break;
		default:
            break;
    }
		
	printf("\n");

	//Se libera la memoria asignada por la llamada RPC
	xdr_free (xdr_responseVectores, result);

	#ifndef	DEBUG
		clnt_destroy (clnt);
	#endif	 /* DEBUG */
}

void
calculadoraprog_vectores3D(char *host, vector3D v1,  char operation, vector3D v2)
{
	CLIENT *clnt;
	responseVectores  *resultProdVectorial;
	responseBasic  *resultProdEscalar;


	//Se define la estructura operation que contiene los operandos v1, v2 y v3 
	// que será el argumento de las operaciones
	struct operationVectores3D operands;
	operands.first = v1;
	operands.second = v2;

	#ifndef	DEBUG
		clnt = clnt_create (host, CALCULADORAPROG, CALCULADORAVERS, "udp");
		if (clnt == NULL) {
			clnt_pcreateerror (host);
			exit (1);
		}
	#endif	/* DEBUG */

	switch (operation)
    {
        case '*': //Producto escalar
            resultProdEscalar = prodescalar3d_1(operands, clnt);
			if (resultProdEscalar == (responseBasic *) NULL) {
				clnt_perror (clnt, "call failed");
			}

            break;

        case 'x': //Producto vectorial
           	resultProdVectorial = prodvectorial3d_1(operands, clnt);
			if (resultProdVectorial == (responseVectores *) NULL) {
				clnt_perror (clnt, "call failed");
			}
            break;
		default:
            break;
    }
	
	//Se muestra el resultado
	switch (operation)
    {
        case '*': //Producto escalar
            //printf("El resultado del producto escalar es %f",resultProdEscalar->responseBasic_u.result);
			printf(MAGENTA_T"%f"RESET_COLOR, resultProdEscalar->responseBasic_u.result);
            break;

        case 'x': //Producto vectorial
           	//printf("El resultado de restar los vectores es: ");
			for(int i = 0; i < resultProdVectorial->responseVectores_u.vResult.vectorData_len; i++){
				printf(MAGENTA_T"%f  "RESET_COLOR, resultProdVectorial->responseVectores_u.vResult.vectorData_val[i]);
			}
            break;
		default:
            break;
    }
		
	printf("\n");

	//Se libera la memoria asignada por la llamada RPC
	xdr_free (xdr_responseVectores, resultProdEscalar);
	xdr_free (xdr_responseVectores, resultProdVectorial);

	#ifndef	DEBUG
		clnt_destroy (clnt);
	#endif	 /* DEBUG */
}


void
calculadoraprog_matrices(char *host, matrizData a, char operation, matrizData b)
{
	CLIENT *clnt;
	responseMatrices  *result;

	struct operationMatrices operands;
	operands.first = a;
	operands.second = b;

	#ifndef	DEBUG
		clnt = clnt_create (host, CALCULADORAPROG, CALCULADORAVERS, "udp");
		if (clnt == NULL) {
			clnt_pcreateerror (host);
			exit (1);
		}
	#endif	/* DEBUG */

	//Se realiza la operacion según el tipo de operando
	switch (operation)
    {
        case '+': //Suma
            result = sumamatrices_1(operands, clnt);
			if (result == (responseMatrices *) NULL) {
				clnt_perror (clnt, "call failed");
			}
            break;

        case '-'://Resta
           	
            break;

        default:
            break;
    }

	//Se muestra el resultado
	//printf("El resultado de la operación %f %c %f = %f\n", a, operation, b, result->responseMatrices_u.mResult.c);
	

	//Se libera la memoria asignada por la llamada RPC
	xdr_free (xdr_responseMatrices, result);
	
	
	#ifndef	DEBUG
		clnt_destroy (clnt);
	#endif	 /* DEBUG */
}

#define MAXIMA_LONGITUD_PETICION 50

int
main (int argc, char *argv[])
{
	if (argc  != 2) {
		printf ("usage: %s server_host\n", argv[0]);
		exit (1);
	}

	//Declaracion de variables
	char *host;
	host = argv[1];

	char peticion[MAXIMA_LONGITUD_PETICION];
	char operation;
	
	//Operaciones basicas
	double a, b;

	//Operaciones con Vectores
	vectorData v1, v2;

	//Operaciones con Vectores3D
	vector3D v3D1, v3D2;

	//Operaciones con Matrices
	matrizData m1, m2;
	
	//a = atof(argv[2]);
	//b = atof(argv[4]);
	//operation = *argv[3];

	//-------------------MENU---------------

	//calculadoraprog_basicas (host,a,operation,b);

	//Vectores

	/*printf("	1: adios\n");

	v1.vectorData_len = 5;
	v1.vectorData_val = malloc(5*sizeof(double));

	for(int i = 0; i < v1.vectorData_len; i++){
		v1.vectorData_val[i] = 1.0;
		//scanf("%lf",&v1.vectorData_val[i]);
	}

	printf("	2: adios\n");


	v2.vectorData_len = 5;
	v2.vectorData_val = malloc(5*sizeof(double));
	
	for(int i = 0; i < v2.vectorData_len; i++){
		v2.vectorData_val[i] = 5.0;
	}

	printf("	3: adios\n");*/


	//calculadoraprog_vectores(host, v1, operation, v2);

	//Vectores3D
	v3D1.x = 3.0;
	v3D1.y = 2.0;
	v3D1.z = 1.0;

	v3D2.x = 1.0;
	v3D2.y = 20.0;
	v3D1.z = 3.0;

	//calculadoraprog_vectores3D(host, v3D1, operation, v3D2);
	
	//Matrices
	//calculadoraprog_matrices(host, m1, operation, m2);

	int peticionValida=1;

	int menuPrincipal=0;
	while( menuPrincipal != 5){
		printf("\nOpciones disponibles:\n");
		printf("  1: Operaciones Básicas\n");
		printf("  2: Operaciones con vectores\n");
		printf("  3: Operaciones con vectores 3D\n");
		printf("  4: Operaciones con matrices\n");
		printf("  5: Salir \n");

		printf("\n--Introducce una opción: ");
		scanf("%d",&menuPrincipal);

		switch(menuPrincipal){
			case 1: //Menu Operaciones basicas
				printf("   ----OPERACIÓN BÁSICA----\n");
				//printf("   Introduce una operacion <operando> '+' '-' '*' '/' 'log' '^' <operabdo>: (ej: 5 + 5)\n");

				//Obtener los operandos y la operacion
				printf("   Introduce la operacion '+' '-' '*' '/' 'log' '^': ");
				scanf("%s",peticion);

				if( strcmp(peticion, "+") == 0 ){
					//printf("\n(es suma)\n");
					operation='+';
					peticionValida=1;
				}
				else if(strcmp(peticion, "-") == 0){
					//printf("\n(es resta)\n");
					operation='-';
					peticionValida=1;
				}
				else if(strcmp(peticion, "*") == 0){
					//printf("\n(es mult)\n");
					operation='*';
					peticionValida=1;
				}
				else if(strcmp(peticion, "/") == 0){
					//printf("\n(es div)\n");
					operation='/';
					peticionValida=1;
				}
				else if(strcmp(peticion, "log") == 0){
					//printf("\n(es log)\n");
					operation='l';
					peticionValida=1;
				}
				else if(strcmp(peticion, "^") == 0){
					//printf("\n(es pot)\n");
					operation='^';
					peticionValida=1;
				}
				else{
					peticionValida=0;
				}

				//Si la peticon es valida entonces se obtienen los operandos
				if(peticionValida){

					if( operation != 'l' && operation != '^'){
						printf("   Introduce el primer operando: ");
						scanf("%lf",&a);

						printf("   Introduce el segundo operando: ");
						scanf("%lf",&b);
					}
					else if(operation == 'l')  {
						printf("   Introduce el argumento: ");
						scanf("%lf",&a);

						printf("   Introduce la base: ");
						scanf("%lf",&b);
					}
					else if(operation == '^')  {
						printf("   Introduce la base: ");
						scanf("%lf",&a);

						printf("   Introduce el exponente: ");
						scanf("%lf",&b);
					}

					printf("\n"AZUL_T"--------------------------------------------------------------------"RESET_COLOR"\n");
					printf( AZUL_T"  El resultado de la operación "AMARILLO_T"%f %s %f"AZUL_T" = "RESET_COLOR, a , peticion, b);
					//Realizar peticion al servidor y Mostrar resultado
					calculadoraprog_basicas (host,a,operation,b);
					printf("\n"AZUL_T"--------------------------------------------------------------------"RESET_COLOR"\n");


				}
				else{
					printf(" NO ES CORRECTA LA PETICION\n");
				}	

				break;
				
			case 2: //Menu vectores
				printf("   ----OPERACIÓN CON VECTORES----\n");

				//Obtener los operandos y la operacion
				printf("   Introduce el tamaño de los vectores: ");
				int tam;
				do{
					scanf("%d",&tam);
				}while(tam <= 0);

				printf("   Contenido del primer vector:\n");
				v1.vectorData_len = tam;
				v1.vectorData_val = malloc(tam*sizeof(double));

				for(int i = 0; i < v1.vectorData_len; i++){
					scanf("%lf",&v1.vectorData_val[i]);
				}

				printf("   Contenido del segundo vector:\n");
				v2.vectorData_len = tam;
				v2.vectorData_val = malloc(tam*sizeof(double));
				
				for(int i = 0; i < v2.vectorData_len; i++){
					scanf("%lf",&v2.vectorData_val[i]);
				}

				//Se pide la operacion
				peticionValida=0;
				do{
					printf("   Introduce la operacion '+' o '-': ");
					scanf("%s",peticion);

					if( strcmp(peticion, "+") == 0 ){
						//printf("\n(es suma)\n");
						operation='+';
						peticionValida=1;
					}
					else if(strcmp(peticion, "-") == 0){
						//printf("\n(es resta)\n");
						operation='-';
						peticionValida=1;
					}
					else{
						peticionValida=0;
						printf(" NO ES CORRECTA LA OPERACION\n");
					}

				}while(peticionValida == 0);

				//Resultado
				printf(AZUL_T"--------------------------------------------------------------------"RESET_COLOR"\n");
				printf( ""AZUL_T" El resultado de la operación:\n\t"AMARILLO_T);
				for(int i = 0; i < v1.vectorData_len; i++){
					printf("%lf ",v1.vectorData_val[i]);
				}
				printf("\n\t%c\n\t",operation);
				for(int i = 0; i < v2.vectorData_len; i++){
					printf("%lf ",v2.vectorData_val[i]);
				}
				printf( "\n\t"AZUL_T"= "RESET_COLOR);
							
				//Realizar peticion al servidor y Mostrar resultado
				calculadoraprog_vectores(host, v1, operation, v2);

				printf(AZUL_T"--------------------------------------------------------------------"RESET_COLOR"\n");

				break;

			break;

			case 3: //Menu Vectores3D
				printf("   ----OPERACIÓN CON VECTORES 3D----\n");

				//Obtener los operandos y la operacion

				printf("   Contenido del primer vector:\n");
				printf("      x:");
				scanf("%lf",&v3D1.x);
				printf("      y:");
				scanf("%lf",&v3D1.y);
				printf("      z:");
				scanf("%lf",&v3D1.z);
				
				printf("   Contenido del segundo vector:\n");
				printf("      x:");
				scanf("%lf",&v3D2.x);
				printf("      y:");
				scanf("%lf",&v3D2.y);
				printf("      z:");
				scanf("%lf",&v3D2.z);

				//Se pide la operacion
				peticionValida=0;
				do{
					printf("   Introduce la operacion ( '*' -> producto escalar) ('x' -> producto vectorial): ");
					scanf("%s",peticion);

					if( strcmp(peticion, "*") == 0 ){
						printf("\n(es producto escalar)\n");
						operation='*';
						peticionValida=1;
					}
					else if(strcmp(peticion, "x") == 0){
						printf("\n(es producto vectorial)\n");
						operation='x';
						peticionValida=1;
					}
					else{
						peticionValida=0;
						printf(" NO ES CORRECTA LA OPERACION\n");
					}

				}while(peticionValida == 0);

				//Resultado
				printf("\n"AZUL_T"--------------------------------------------------------------------"RESET_COLOR"\n");
				printf(AZUL_T" El resultado de la operación "AMARILLO_T);

				printf("\n\t(%f, %f, %f,) %c (%f, %f, %f,)",v3D1.x,v3D1.y,v3D1.z,operation,v3D2.x,v3D2.y,v3D2.z);
				printf( AZUL_T" = "RESET_COLOR);
				
				//Realizar peticion al servidor y Mostrar resultado
				calculadoraprog_vectores3D(host, v3D1, operation, v3D2);
				printf("\n"AZUL_T"--------------------------------------------------------------------"RESET_COLOR"\n");
				
			break;

			case 4: //Menu Matrices
			break;

			case 5:
				printf("Saliendo...\n");
				// Exit
			break;

			default:
				printf("ERROR: Opcion no valida\n");
		}
	}
	
exit (0);
}

