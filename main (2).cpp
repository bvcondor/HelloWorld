#include<stdio.h>
#include <conio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define numopciones 8
#define cedula 10
int count_ci=0;
long int recedu[20];
int semana [8][5];
char fecha_cita[12];
FILE *archivo;

struct datos_familiar{
    char Nombre[20];
    long int Telefono;
    char parentezco[15];
};

struct datos_medicos{
    int talla;
    int peso;
    char E[50];
    char ALERGIAS[25];
};

struct datos_paciente{
    char Nombre[20];
    long int CI;
    char Genero[7];
    int Edad;
    long int Telefono;
    char Ciudad[10];
    char codigo[10];
    datos_medicos D;
    datos_familiar familiar;
};

struct historia_clinica{
    datos_medicos D ;
    datos_familiar F;
    datos_paciente P;
};


//funciones cualquiera
int desicion_dicoto( char A[],char B[]){//devuelve o si escojes la primera o 1 si la segunda
    char opc1[2],opc2[2];
    strcpy(opc1,A);
    strcpy(opc1,B);

    int a;
    char X[2];

    do{
        printf("[%s]/[%s]",A,B);
        fflush(stdin);
        gets(X);
        if(stricmp(X,A)==0){
            a=0;}
        else if(stricmp(X,B)==0){
            a=1;}
        else {
            printf("Error,ingrese una letra valida\n");
            a=2;}
  }while(a==2);
   return a;}


int asegurar_entero(){

int a;
char x[15];

   do{
        fflush(stdin);
		scanf("%s",x);
        for(int i=0; i<strlen(x); i++)
    {
            if(!(isdigit(x[i])))
        {
                printf("INGRESE SOLO NUMEROS\n");
                a=0;
        }
            else if((isdigit(x[i]))){
            if (atoi(x)<0){
                    printf("INGRESE SOLO POSITIVOS\n");
                    a=0;}
            else

                a=1;}}

   }while(a!=1);
   a=atoi(x);
return a;
}


long int ingresar_validar_ci( ){

    long int CI,CI2;
    char y[cedula];
    long int coc,res,x[cedula];
    int bit_final,acum,aux[10]{2,1,2,1,2,1,2,1,2,1},repetida;
        printf("\nINGRESE LA CEDULA:\t");
    //validar que no sea negativa ni mayor a 10 digitos
    do{

        fflush(stdin);
        scanf("%s",y);
        CI=atoi(y);
        CI2=atoi(y);

        if ((CI<9999999)||(CI>9999999999))
            printf("error,cedula incorrecta,por favor reingrese");
        else {acum=0;bit_final=0;//validar que sea cedula real
            for(int i=cedula;i!=0;i--){
            coc=CI/10;
            res=CI%10;
            CI=coc;
            x[i-1]=res;
            y[i-1]=res;
  }
        for(int i=0;i<cedula;i++){
            x[i]*=aux[i];
            if(x[i]>9)x[i]-=9;
            acum+=x[i];
              }
            acum-=x[9];
            while(acum%10!=0){
            acum++;
            bit_final++;
            }
            if(x[9]!=bit_final)
                printf("error,cedula incorrecta,por favor reingrese");
            }
    repetida=0;

        for(int u=0;u<20;u++){
                       if (CI2==recedu[u]){
                        printf("ERROR, LA CEDULA YA FUE INGRESADA\n");
                        repetida++;



        }}

    }while((x[9]!=bit_final)||(repetida!=0));

    recedu[count_ci]=CI2;
    count_ci++;

    return CI2;
}


void generar_codigo(char *Paciente,char *codigo){

    int num_ale;
    char auxN[10]="";
    char aux1[10];

//tomar primer caracter nombre
    strncpy(auxN,Paciente,1);
    srand(time(NULL));

    for(int i=0;i<4;i++){
        num_ale=0+rand()%10;
        itoa(num_ale,aux1,10);
        strcat(auxN,aux1);
    }

    strcpy(codigo,auxN);
    printf("\n CODIGO GENERADO:\t ");
    puts(codigo);
}



int Crear_base(){
    historia_clinica H;
    int repetir;
    char x[13];
    printf("______________________________________________________________________________________________________________________\n\n");
    printf("\t\t HISTORIA CLINICA DE PACIENTE DE CONSULTORIO MEDICO\n DR. PEPITO GONZALES\n TELEFONO:3203354 \n DIRECCION: avenida siempre viva - 123\n ");
    printf("______________________________________________________________________________________________________________________\n\n");


    printf("INGRESE EL NOMBRE DEL PACIENTE:\t");

            fflush(stdin);
            gets(H.P.Nombre);
            strupr(H.P.Nombre);
            generar_codigo(H.P.Nombre,H.P.codigo);
            strcpy(x,H.P.codigo);
            strcat(x,".txt");
            fflush(stdin);
            archivo = fopen(x,"w");

    if (archivo== NULL){
        printf("ERROR EN LA CREACION DEL ARCHIVO");
        return 1;
    }

        printf("______________________________________________________________________________________________________________________\n\n");
        printf("\n\t\t\t==> INGRESO DE DATOS DEL PACIENTE <==\n");
        printf("______________________________________________________________________________________________________________________\n\n");

                fflush(stdin);
                fflush(stdin);
                H.P.CI=ingresar_validar_ci();
        printf("\nINGRESE EL GENERO DEL PACIENTE:\t");
                fflush(stdin);
            if((desicion_dicoto("H","M"))==0){
                strcpy(H.P.Genero,"HOMBRE");              }
            else strcpy(H.P.Genero,"MUJER");
        printf("\nINGRESE LA EDAD DEL PACIENTE:\t");
        H.P.Edad=asegurar_entero();
        printf("\nINGRESE EL NUMERO DE TELEFONO:\t");
        H.P.Telefono=asegurar_entero();
        printf("\nINGRESE LA CIUDAD DE RESIDENCIA:\t");
                fflush(stdin);
        gets(strcat(H.P.Ciudad,";"));
        strupr(H.P.Ciudad);
        getch();
        system("cls");
        printf("______________________________________________________________________________________________________________________\n\n");

        printf("\n\t\t\t==> INGRESO DE DATOS MEDICOS DEL PACIENTE <==\n");
        printf("______________________________________________________________________________________________________________________\n\n");

        printf("\nINGRESE LA TALLA DEL PACIENTE(cm):\t");
        H.D.talla=asegurar_entero()	;
        printf("\nINGRESE EL PESO DEL PACIENTE(kg):\t");
        H.D.peso=asegurar_entero();
        printf("\nINGRESE LAS ENFERMEDADES DEL PACIENTE:\t");
                fflush(stdin);
        gets(H.D.E);
        strupr(H.D.E);

        printf("\nINGRESE LAS ALERGIAS DEL PACIENTE:\t");
                fflush(stdin);
        gets(H.D.ALERGIAS);
        strupr(H.D.ALERGIAS);
        printf("______________________________________________________________________________________________________________________\n\n");
        printf("\n\t\t\t==> INGRESO DE DATOS DE UN FAMILIAR EN CASO DE EMEGENCIA <==\n");
        printf("______________________________________________________________________________________________________________________\n\n");

        printf("\nINGRESE EL NOMBRE:\t");
            fflush(stdin);
                    gets(H.F.Nombre);
                    strupr(H.F.Nombre);

                printf("\nINGRESE EL TELEFONO\t");
                H.F.Telefono=asegurar_entero();

                printf("\nINGRESE EL PARENTEZCO:\t");
                    fflush(stdin);
                    gets(H.F.parentezco);
                    strupr(H.F.parentezco);

                    system("cls");
                    printf("\n\n HISTORIA CLINICA GUARDADA CORRECTAMENTE :) \n");
                    getch();
                    system("cls");

char AUX[30];

//escritura del archivo
        fprintf(archivo,"______________________________________________________________________________________________________________________\n\n");
        fprintf(archivo,"\t\t HISTORIA CLINICA DE PACIENTE DE CONSULTORIO MEDICO\n DR. PEPITO GONZALES\n TELEFONO:3203354 \n DIRECCION: avenida siempre viva - 123\n ");
        fprintf(archivo,"______________________________________________________________________________________________________________________\n");
        fprintf(archivo,"______________________________________________________________________________________________________________________\n\n");
        fprintf(archivo,"\n\t\t\t\t==> DATOS GENERALES DEL PACIENTE: <==\n");
        fprintf(archivo,"______________________________________________________________________________________________________________________\n\n");
        fprintf(archivo,"\n\n NOMBRE DEL PACIENTE:");
            fwrite(H.P.Nombre,1,strlen(H.P.Nombre),archivo);
        fprintf(archivo,"\n\n CODIGO DEL PACIENTE: ");
            fwrite(H.P.codigo,1,strlen(H.P.codigo),archivo);
        fprintf(archivo,"\n\n CI: ");
            fwrite(itoa(H.P.CI,AUX,10),1,strlen(itoa(H.P.CI,AUX,10)),archivo);
        fprintf(archivo,"\n\n GENERO DEL PACIENTE: ");
            fwrite(H.P.Genero,1,strlen(H.P.Genero),archivo);
        fprintf(archivo,"\n\n EDAD PACIENTE:");
            fwrite(itoa(H.P.Edad,AUX,10),1,strlen(itoa(H.P.Edad,AUX,10)),archivo);
        fprintf(archivo,"\n\n TELEFONO DEL PACIENTE:");
            fwrite(itoa(H.P.Telefono,AUX,10),1,strlen(itoa(H.P.Telefono,AUX,10)),archivo);
        fprintf(archivo,"\n\n CIUDAD DE RESIDENCIA:");
            fwrite(H.P.Ciudad,1,strlen(H.P.Ciudad),archivo);
    //IMPRIMO DATOS MEDICOS
         fprintf(archivo,"#\n______________________________________________________________________________________________________________________\n\n");
        fprintf(archivo,"\n\t\t\t\t==> DATOS MEDICOS DEL PACIENTE: <==\n");
        fprintf(archivo,"______________________________________________________________________________________________________________________\n\n");
        fprintf(archivo,"\n\nTALLA DEL PACIENTE(cm):");
            fwrite(itoa(H.D.talla,AUX,10),1,strlen(itoa(H.D.talla,AUX,10)),archivo);
            fprintf(archivo,"\n\n PESO DEL PACIENTE(kg):");
            fwrite(itoa(H.D.peso,AUX,10),1,strlen(itoa(H.D.peso,AUX,10)),archivo);
            fprintf(archivo,"\n\n ENFERMEDADES DEL PACIENTE:");
                        fwrite(H.D.E,1,strlen(H.D.E),archivo);
            fprintf(archivo,"\n\n ALERGIAS DEL PACIENTE:");
                        fwrite(H.D.ALERGIAS,1,strlen(H.D.ALERGIAS),archivo);
            //archivo de datos familiares del paciente

         fprintf(archivo,"\n ______________________________________________________________________________________________________________________\n\n");
        fprintf(archivo,"\n\t\t\t\t==> DATOS FAMILIAR EN CASO DE EMERGENCIA <==\n");
        fprintf(archivo,"______________________________________________________________________________________________________________________\n\n");
        fprintf(archivo,"\n\n NOMBRE :");
                    fwrite(H.F.Nombre,1,strlen(H.F.Nombre),archivo);
        fprintf(archivo,"\n\nTELEFONO :");
                            fwrite(itoa(H.F.Telefono,AUX,10),1,strlen(itoa(H.F.Telefono,AUX,10)),archivo);
         fprintf(archivo,"\n\nPARENTEZCO CON EL PACIENTE :");
                                    fwrite(H.F.parentezco,1,strlen(H.F.parentezco),archivo);

        fclose(archivo);



}

int horario(){
    //cita_medica a;
    int opcion;
    do{
        printf("______________________________________________________________________________________________________________________\n\n");
        printf("\n\t\t\t==> ESCOJA EL HORARIO EN EL QUE DESEA AGREGAR SU CITA MEDICA <==\n");
        printf("______________________________________________________________________________________________________________________\n\n");

            printf("\n\n\t 1. 9:00 AM \n\n\t 2. 10:00 AM \n\n\t 3. 11:00 AM \n\n\t 4. 12:00 AM \n\n\t 5. 1:00 PM \n\n\t 6.2:00 PM  \n\n\t 5. 3:00 PM \n\n ");
             printf("\n opcion:");
            opcion=asegurar_entero();
            system("cls");
            if((opcion<1)||(opcion>7))printf("ESCOJA UN HORARIO VALIDO\n");
            }while((opcion<1)||(opcion>7));

        switch (opcion)
        {
        case 1:
            strcpy(fecha_cita,"9:00 AM");
            return 0;
            break;
       case 2:
           strcpy(fecha_cita,"10:00 AM");
           return 1;
            break;
        case 3:
            strcpy(fecha_cita,"11:00 AM");
           return 2;
            break;
        case 4:
            strcpy(fecha_cita,"12:00 AM");
            return 3;
            break;
        case 5:
            strcpy(fecha_cita,"1:00 PM");
            return 4;
            break;
        case 6:
            strcpy(fecha_cita,"2:00 PM");
            return 5;
            break;
        case 7:
            strcpy(fecha_cita,"3.00 PM");
            return 6;
            break;
        default:
         return -1;
}


}

int agendar_cita(){

    int opcion;
    char codigo[13];
    int dicotomica;

        do{
        printf("INGRESE EL CODIGO DE LA HISTORIA CLINICA PACIENTE: \t");
        fflush(stdin);
        gets(codigo);
        strcat(codigo,".txt");

        system("cls");
        archivo=fopen(codigo,"r+");
        if (archivo== NULL) {
                printf("\n \n \tNO SE ENCONTRO CODIGO DE PACIENTE\n\n\t VERIFIQUE EL CODIGO DEL PACIENTE\n\n\t O REGISTRE DATOS DEL PACIENTE");
        fclose(archivo);}
        else{
        do {

        printf("______________________________________________________________________________________________________________________\n\n");
        printf("\n\t\t\t==> ESCOJA EL DIA DE LA SEMANA EN EL QUE QUIERE AGENDAR LA CITA <==\n");
        printf("______________________________________________________________________________________________________________________\n\n");

            printf("\n\n\n\t1.LUNES\n\n\t 2.MARTES\n\n\t 3.MIERCOLES\n\n\t 4.JUEVES\n\n\t 5.VIERNES\n ");
             printf("\n opcion:");
            opcion=asegurar_entero();
            system("cls");
            if ((opcion<1)||(opcion>6)){
                    printf("ESCOJA UN DIA VALIDO\n");

            }}while((opcion<1)||(opcion>5));

        switch (opcion)
        {
        case 1:
            if (semana[horario()][opcion-1]!=1){
                semana[0][opcion-1]=1;
                archivo=fopen(codigo,"a+");
                printf("CITA MEDICA AGENDADA EXITOSAMENTE");
                printf("\n\n CITA AGENDADA PARA EL DIA LUNES: ");
                puts(fecha_cita);
                fprintf(archivo,"\n\n CITA AGENDADA PARA EL DIA LUNES: ");
                fputs(fecha_cita,archivo);
                fclose(archivo);

                }
            else{
                printf("\n\t\tHORARIO YA ESCOGIDO\n POR FAVOR ESCOJA OTRO HORARIO DISPONIBLE\n\n");

            }
            break;
       case 2:
           if (semana[horario()][opcion-1]!=1){
                semana[1][opcion-1]=1;
                archivo=fopen(codigo,"a+");
                printf("CITA MEDICA AGENDADA EXITOSAMENTE");
                printf("\n\n CITA AGENDADA PARA EL DIA MARTES: ");
                puts(fecha_cita);
                fprintf(archivo,"\n\nCITA AGENDADA PARA EL DIA MARTES: ");
                fputs(fecha_cita,archivo);
                fclose(archivo);
           }
            else{
               printf("\n\t\tHORARIO YA ESCOGIDO\n POR FAVOR ESCOJA OTRO HORARIO DISPONIBLE\n\n");
            }
            break;
        case 3:
            if (semana[horario()][opcion-1]!=1){
            semana[2][opcion-1]=1;
            archivo=fopen(codigo,"a+");
                printf("CITA MEDICA AGENDADA EXITOSAMENTE");
                printf("\n\n CITA AGENDADA PARA EL DIA MIERCOLES: ");
                puts(fecha_cita);
                fprintf(archivo,"\n\n CITA AGENDADA PARA EL DIA MIERCOLES: ");
                fputs(fecha_cita,archivo);
                fclose(archivo);
           } else
               printf("\n\t\tHORARIO YA ESCOGIDO\n POR FAVOR ESCOJA OTRO HORARIO DISPONIBLE\n\n");
            break;
        case 4:
            if (semana[horario()][opcion-1]!=1){
                semana[3][opcion-1]=1;
                archivo=fopen(codigo,"a+");
                printf("CITA MEDICA AGENDADA EXITOSAMENTE");
                printf("\n\n CITA AGENDADA PARA EL DIA JUEVES: ");
                puts(fecha_cita);
                fprintf(archivo,"\n\n CITA AGENDADA PARA EL DIA JUEVES: ");
                fputs(fecha_cita,archivo);
                fclose(archivo);
                }else
               printf("\n\t\tHORARIO YA ESCOGIDO\n POR FAVOR ESCOJA OTRO HORARIO DISPONIBLE\n\n");

            break;
        case 5:
            if (semana[horario()][opcion-1]!=1){
                semana[4][opcion-1]=1;

              archivo=fopen(codigo,"a+");
                printf("CITA MEDICA AGENDADA EXITOSAMENTE");
                printf("\n\n CITA AGENDADA PARA EL DIA VIERNES: ");
                puts(fecha_cita);
                fprintf(archivo,"\n\nCITA AGENDADA PARA EL DIA VIERNES: ");
                fputs(fecha_cita,archivo);
                fclose(archivo);
            }else
                printf("\n\t\tHORARIO YA ESCOGIDO\n POR FAVOR ESCOJA OTRO HORARIO DISPONIBLE\n\n");

            break;
        default:
            fclose(archivo);
            return 0;

fclose(archivo);}}
printf("\n ______________________________________________________________________________________________________________________\n\n");
        printf("\n DESEA AGENDAR OTRA CITA?");
        dicotomica=desicion_dicoto("S","N");
        system("cls");

        }while(dicotomica==0);
}

int visualizar(){
int c,dicotomica;
char codigo[13];
do{
    printf("______________________________________________________________________________________________________________________\n\n");
    printf("\n\t\t\t==> BIENVENIDO AL SISTEMA DE BUSQUEDA DE PACIENTES <==\n");
    printf("______________________________________________________________________________________________________________________\n\n");

    printf("INGRESE EL CODIGO DE LA HISTORIA CLINICA PACIENTE: \t");
    fflush(stdin);
    gets(codigo);
    strcat(codigo,".txt");
    system("cls");



archivo=fopen(codigo,"r");

if (archivo == NULL){
        printf("\nERROR EN LA LECTURA DEL ARCHIVO\n");
        printf("\n \n NO SE ENCONTRO CODIGO DE PACIENTE\n");
        }
else{

c= fgetc(archivo);

 while(c!= EOF){

    c= fgetc(archivo);


    if(c=='\n')
        printf("\n");
    else putchar(c);
 }}
 printf("\n ______________________________________________________________________________________________________________________\n\n");
 fclose(archivo);
 printf("\n DESEA INGRESAR OTRO CODIGO?");
dicotomica=desicion_dicoto("S","N");
system("cls");

}while(dicotomica==0);
}

int actualizar(){
    historia_clinica H;
    int c,dicotomica;
    char codigo[13];
    do{

        printf("______________________________________________________________________________________________________________________\n\n");
        printf("\n\t\t\t==> BIENVENIDO AL SISTEMA DE ACTUALIZACION DE DATOS DE PACIENTE  <==\n");
        printf("______________________________________________________________________________________________________________________\n\n");

        printf("INGRESE EL CODIGO DE LA HISTORIA CLINICA PACIENTE:\t");
        fflush(stdin);
        gets(codigo);
        strcat(codigo,".txt");

        archivo=fopen(codigo,"r+");

        strcpy(H.P.codigo,codigo);
        if (archivo== NULL){
        printf("\n \n NO SE ENCONTRO CODIGO DE PACIENTE");
        }
        else{

        printf("\n\n\t\t PACIENTE ENCONTRADO EXITOSAMENTE\n\n\t\t EMPIEZE LOS CAMBIOS DEL PACIENTE CON UN ENTER:");
        getch();
        system("cls");
        printf("\n ______________________________________________________________________________________________________________________\n\n");
        printf("\n\t\t\t==> INGRESO DE DATOS DEL PACIENTE <==\n");
        printf("______________________________________________________________________________________________________________________\n\n");

                printf("INGRESE EL NOMBRE DEL PACIENTE:\t");

                fflush(stdin);
                gets(H.P.Nombre);
                strupr(H.P.Nombre);
                fflush(stdin);
                H.P.CI=ingresar_validar_ci();
        printf("\nINGRESE EL GENERO DEL PACIENTE:\t");
                fflush(stdin);
            if((desicion_dicoto("H","M"))==0){
                strcpy(H.P.Genero,"HOMBRE");              }
            else strcpy(H.P.Genero,"MUJER");
        printf("\nINGRESE LA EDAD DEL PACIENTE:\t");
        H.P.Edad=asegurar_entero();
        printf("\nINGRESE EL NUMERO DE TELEFONO:\t");
        H.P.Telefono=asegurar_entero();
        printf("\nINGRESE LA CIUDAD DE RESIDENCIA:\t");
                fflush(stdin);
        gets(H.P.Ciudad);
        strupr(H.P.Ciudad);
        getch();
        system("cls");
        printf("______________________________________________________________________________________________________________________\n\n");

        printf("\n\t\t\t==> INGRESO DE DATOS MEDICOS DEL PACIENTE <==\n");
        printf("______________________________________________________________________________________________________________________\n\n");

        printf("\nINGRESE LA TALLA DEL PACIENTE(cm):\t");
        H.D.talla=asegurar_entero()	;
        printf("\nINGRESE EL PESO DEL PACIENTE(kg):\t");
        H.D.peso=asegurar_entero();
        printf("\nINGRESE LAS ENFERMEDADES DEL PACIENTE:\t");
                fflush(stdin);
        gets(H.D.E);
        strupr(H.D.E);

        printf("\nINGRESE LAS ALERGIAS DEL PACIENTE:\t");
                fflush(stdin);
        gets(H.D.ALERGIAS);
        strupr(H.D.ALERGIAS);
        printf("______________________________________________________________________________________________________________________\n\n");


        printf("\n\t\t\t==> INGRESO DE DATOS DE UN FAMILIAR EN CASO DE EMEGENCIA <==\n");
        printf("______________________________________________________________________________________________________________________\n\n");

        printf("\nINGRESE EL NOMBRE:\t");
            fflush(stdin);
                    gets(H.F.Nombre);
                    strupr(H.F.Nombre);

                printf("\nINGRESE EL TELEFONO\t");
                H.F.Telefono=asegurar_entero();

                printf("\nINGRESE EL PARENTEZCO:\t");
                    fflush(stdin);
                    gets(H.F.parentezco);
                    strupr(H.F.parentezco);

        char AUX[30];

//escritura del archivo
        fprintf(archivo,"______________________________________________________________________________________________________________________\n\n");
        fprintf(archivo,"\t\t HISTORIA CLINICA DE PACIENTE DE CONSULTORIO MEDICO\n DR. PEPITO GONZALES\n TELEFONO:3203354 \n DIRECCION: avenida siempre viva - 123\n ");
        fprintf(archivo,"______________________________________________________________________________________________________________________\n");
        fprintf(archivo,"______________________________________________________________________________________________________________________\n\n");
        fprintf(archivo,"\n\t\t\t\t==> DATOS GENERALES DEL PACIENTE: <==\n");
        fprintf(archivo,"______________________________________________________________________________________________________________________\n\n");
        fprintf(archivo,"\n\n NOMBRE DEL PACIENTE:");
            fwrite(H.P.Nombre,1,strlen(H.P.Nombre),archivo);
        fprintf(archivo,"\n\n CODIGO DEL PACIENTE: ");
            fwrite(H.P.codigo,1,strlen(H.P.codigo),archivo);
        fprintf(archivo,"\n\n CI: ");
            fwrite(itoa(H.P.CI,AUX,10),1,strlen(itoa(H.P.CI,AUX,10)),archivo);
        fprintf(archivo,"\n\n GENERO DEL PACIENTE: ");
            fwrite(H.P.Genero,1,strlen(H.P.Genero),archivo);
        fprintf(archivo,"\n\n EDAD PACIENTE:");
            fwrite(itoa(H.P.Edad,AUX,10),1,strlen(itoa(H.P.Edad,AUX,10)),archivo);
        fprintf(archivo,"\n\n TELEFONO DEL PACIENTE:");
            fwrite(itoa(H.P.Telefono,AUX,10),1,strlen(itoa(H.P.Telefono,AUX,10)),archivo);
        fprintf(archivo,"\n\n CIUDAD DE RESIDENCIA:");
            fwrite(H.P.Ciudad,1,strlen(H.P.Ciudad),archivo);
            fprintf(archivo,";");
    //IMPRIMO DATOS MEDICOS
         fprintf(archivo,"#\n______________________________________________________________________________________________________________________\n\n");
        fprintf(archivo,"\n\t\t\t\t==> DATOS MEDICOS DEL PACIENTE: <==\n");
        fprintf(archivo,"______________________________________________________________________________________________________________________\n\n");
        fprintf(archivo,"\n\nTALLA DEL PACIENTE(cm):");
            fwrite(itoa(H.D.talla,AUX,10),1,strlen(itoa(H.D.talla,AUX,10)),archivo);
            fprintf(archivo,"\n\n PESO DEL PACIENTE:");
            fwrite(itoa(H.D.peso,AUX,10),1,strlen(itoa(H.D.peso,AUX,10)),archivo);
            fprintf(archivo,"\n\n ENFERMEDADES DEL PACIENTE:");
                        fwrite(H.D.E,1,strlen(H.D.E),archivo);
            fprintf(archivo,"\n\n ALERGIAS DEL PACIENTE:");
                        fwrite(H.D.ALERGIAS,1,strlen(H.D.ALERGIAS),archivo);
            //archivo de datos familiares del paciente

         fprintf(archivo,"\n ______________________________________________________________________________________________________________________\n\n");
        fprintf(archivo,"\n\t\t\t\t==> DATOS FAMILIAR EN CASO DE EMERGENCIA <==\n");
        fprintf(archivo,"______________________________________________________________________________________________________________________\n\n");
        fprintf(archivo,"\n\n NOMBRE :");
                    fwrite(H.F.Nombre,1,strlen(H.F.Nombre),archivo);
        fprintf(archivo,"\n\nTELEFONO :");
                            fwrite(itoa(H.F.Telefono,AUX,10),1,strlen(itoa(H.F.Telefono,AUX,10)),archivo);
         fprintf(archivo,"\n\nPARENTEZCO CON EL PACIENTE :");
                                    fwrite(H.F.parentezco,1,strlen(H.F.parentezco),archivo);

        }
        fclose(archivo);
        system("cls");
        printf("\n ______________________________________________________________________________________________________________________\n\n");
        printf("HISTORIA CLINICA DEL PACIENTE ACTUALIZADA CORRECTAMENTE :) \n");
        printf("\n DESEA INGRESAR OTRO CODIGO?");
        dicotomica=desicion_dicoto("S","N");
        system("cls");

        }while(dicotomica==0);
        }

void eliminar(){


    int c,dicotomica;
    char codigo[19];
    do{

    printf("INGRESE EL CODIGO DE LA HISTORIA CLINICA PACIENTE:\t");
    fflush(stdin);
    gets(codigo);
    printf("\n");
    strcat(codigo,".txt");
    archivo = fopen( codigo, "r" );
   printf( "REGISTRO DEL PACIENTE: %s\n\n", codigo );
   if( archivo != NULL )
   {
      fclose( archivo );
      if( remove(codigo) == 0 )
        printf( "\LA HISROTIA CLINICA DEL PACIENTE FUE BORRADA CON EXITO\n" );
      else   printf( "\nNO PUDO SER BORRADO\n" );
   }
   else   printf( ", NO ENCONTRADO\n" );

printf("\n DESEA INGRESAR OTRO CODIGO");
dicotomica=desicion_dicoto("S","N");
system("cls");


}while(dicotomica==0);
}



void print_hasta(){

        int cargos;
         char mat1[8][35]={"CARGO POR HOSPITALIZACION",
                          "CARGO   POR   LABORATORIO",
                          "CARGO   POR  MEDICAMENETO",
                          "CARGO   POR  MATERIALES  ",
                          "SUBTOTAL             ",
                          "DESCUENTO POR SEGURO",
                          "IVA  12% ",
                          "VALOR A PAGAR  "};
        float A[8]={0,0,0,0,0,0,0,0},sub;
     int c,dicotomica;
char codigo[13];
do{
    printf("______________________________________________________________________________________________________________________\n\n");
    printf("\n\t\t\t==> BIENVENIDO AL SISTEMA DE FACTURACION DE PACIENTES <==\n");
    printf("______________________________________________________________________________________________________________________\n\n");

    printf("INGRESE EL CODIGO DE LA HISTORIA CLINICA DEL PACIENTE:\t");
    fflush(stdin);
    gets(codigo);
    strcat(codigo,".txt");

archivo=fopen(codigo,"r");

if (archivo == NULL){
        printf("\nERROR EN LA LECTURA DEL ARCHIVO\n");
        printf("\n \n NO SE ENCONTRO CODIGO DE PACIENTE\n");
        }
else{
printf("\nEL PACIENTE TUVO CARGOS POR HOSPITALIZACION:\t");
        cargos=desicion_dicoto("S","N");
        if(cargos==0)
            A[0]=30;
    printf("EL PACIENTE TUVO CARGOS POR LABORATORIO:\t");
        cargos=desicion_dicoto("S","N");
         if(cargos==0)
                    A[1]=20;
    printf("EL PACIENTE TUVO CARGOS POR MEDICAMENTO:\t");
        cargos=desicion_dicoto("S","N");
         if(cargos==0)
                    A[2]=10;
printf("EL PACIENTE TUVO CARGOS POR MATERIALES:\t\t");
        cargos=desicion_dicoto("S","N");
         if(cargos==0)
                    A[3]=5;
    A[4]=A[0]+A[1]+A[2]+A[3];
printf("EL PACIENTE CUENTA CON SEGURO MEDICO:\t");
        cargos=desicion_dicoto("S","N");
         if(cargos==0){
              printf("EL SEGURO ES PARCIAL O TOTAL:\t");
                cargos=desicion_dicoto("P","T");
                if(cargos==0)
                    A[5]=A[4]*0.40;
                else
                    A[5]=A[4]*0.80;}
        else A[5]=0;
//ivs
    A[6]=(A[4]-A[5])*0.12;
//total
    A[7]=A[4]-A[5]+A[6];

c= fgetc(archivo);
system("cls");

 while(c!= '#'){

    c= fgetc(archivo);


    if(c=='\n')
        printf("\n");
    else putchar(c);
 }

  printf("\n______________________________________________________________________________________________________________________\n\n");
 for(int i=0;i<8;i++){
            printf("\n%s \t [%.2f]\n",mat1[i],A[i]);
        }}

  fclose(archivo);
   printf("______________________________________________________________________________________________________________________\n\n");
  printf("DESEA GENERAR OTRA FACTURA:\n");
dicotomica=desicion_dicoto("S","N");
  system("cls");
}while(dicotomica==0);

}




void menu(){
    int opcion,dicotomica;

do{         system("color 0A");
            printf("______________________________________________________________________________________________________________________\n\n");
            printf("\t\t CONSULTORIO MEDICO DEL DOCTOR HOUSE\n DR. PEPITO GONZALES\n TELEFONO:3203354 \n DIRECCION: avenida siempre viva - 123\n ");
            printf("______________________________________________________________________________________________________________________\n");
            printf("\nMENU DE OPCIONES:\n");
            printf("\n 1. CREAR HISTORIA CLINICA");
            printf("\n 2. BUSCAR PACIENTE POR CODIGO DE HISTORIA CLINICA");
            printf("\n 3. ACTUALIZAR DATOS DEL PACIENTE");
            printf("\n 4. AGENDAR UNA CITA MEDICA");
            printf("\n 5. ELIMINAR HISTORIA CLINICA");
            printf("\n 6. FACTURACION\n\n");
            printf("\n 7. SALIR\n\n");
            printf("opcion:");
            opcion=asegurar_entero();
            system("cls");
        switch (opcion)
        {
        case 1:
             system("color 1F");
             Crear_base();
            break;
       case 2:
           system("color 2F");
           visualizar();

            break;
        case 3:
            system("color 79");
           actualizar();
            break;
        case 4:
            system("color 0B");
            agendar_cita();
            fclose(archivo);
            break;
        case 5:
            system("color 0A");
            eliminar();
            break;
        case 6:
            system("color 0F");
            print_hasta();

            break;
        case 7:
            break;
        }
        } while (opcion!=7);

    }



int main(){
    menu();}
