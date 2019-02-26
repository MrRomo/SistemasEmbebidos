#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct nodo
 {
   char nombre[40];
   
   struct nodo *siguiente;
   
   struct nodo *anterior;
 };
 
struct nodo *primero, *ultimo;

int numNodos;

int pos;

void inicializar();
void insertar_ultimo();
void insertar_primero();
void insertar_intermedio();
void visualizar_inicio_final();
void visualizar_final_inicio();
void visualizar_posicion_final();
void visualizar_posicion_inicio();
void visualizar_primero_y_ultimo();
void visualizar_posicion_final_posicion();
void visualizar_posicion_inicio_posicion(); 
void buscar();
void eliminar();                                                                                                           
                                                                                                                                

                                                                                                                                                                                                                                                                                                                                                                                                                                                                          
main()
{
   int opcion;
   
   do
   {
     system("cls");
     printf("\n");
     printf("\n****************************************************");
     printf("\n1.  Inicializar                                    *");
     printf("\n2.  Insertar ultimo                                *");
     printf("\n3.  Insertar primero                               *");
     printf("\n4.  Insertar intermedio                            *");
     printf("\n5.  Visualizar inicio-final                        *");
     printf("\n6.  Visualizar final-inicio                        *");
     printf("\n7.  Visualizar posicion-final                      *");
     printf("\n8.  Visualizar posicion-inicio                     *");
     printf("\n9.  Visualizar primero y ultimo                    *");
     printf("\n10. Visualizar posicion_final_posicion             *");
     printf("\n11. Visualizar posicion_inicio_posicion            *");      
     printf("\n12. Buscar                                         *");
     printf("\n13. Eliminar                                       *");
     printf("\n14. Salir                                          *");  
     printf("\n****************************************************");                                                                                                             
     printf("\n\n\n");
     
     printf("\n Elija opcion    ");
     
     scanf("%d",&opcion);  
     
                                                                                                                                                                                                                                               
                                                                                                                                                                                                                                                          
                                                                                                                             
     
     
     switch (opcion)
         {
                case 1:  inicializar();
                          break;
                case 2:  insertar_ultimo();
                          break;
                case 3:  insertar_primero();
                          break;
                case 4:  insertar_intermedio();
                          break;          
                case 5:  visualizar_inicio_final();
                          break;
                case 6:  visualizar_final_inicio();
                          break;
                case 7:  visualizar_posicion_final();
                          break;
                case 8:  visualizar_posicion_inicio();
                          break;
                case 9:  visualizar_primero_y_ultimo();
                          break;
                case 10: visualizar_posicion_final_posicion(); 
                           break;
                case 11: visualizar_posicion_inicio_posicion(); 
                           break;
                case 12:  buscar();
                          break;
                case 13: eliminar();
                          break;
                case 14: printf("SALIR");
                          break;
                default:  system("cls");
                          break;
        }                                                                                                                                            
     } while (opcion!=14);                                                                                                                         
 }
 
 void inicializar(){
      system("cls");
      primero=NULL;
      ultimo=NULL;
      numNodos=0;
      printf("\n LISTA INICIALIZADA\n");
      printf("\n\n\n\n\n\n\n");
      system("pause");}
      
void insertar_ultimo()
  {
     system("cls");
     struct nodo *nuevo;
     nuevo=( struct nodo*)malloc(sizeof( struct nodo));
     if(nuevo==NULL)
       printf("\n MEMORIA INSUFICIENTE\n");
     else
         {
         printf("\n Nombre:  ");
         fflush(stdin);
         gets(nuevo->nombre);
         nuevo->siguiente=primero;
         if(primero==NULL)
          {
            primero=nuevo;
            ultimo=nuevo;
            nuevo->siguiente=primero;
            nuevo->anterior= ultimo;
         }else{
                nuevo->siguiente= primero;
                
                nuevo->anterior=ultimo; 
                
                ultimo->siguiente=nuevo;
                
                ultimo=nuevo;
                
                primero->anterior= ultimo; 
              }
       }
       numNodos++;                                                                                                                                                                                                                                                                                                                                                                                                             
 }                                                                                                                                                                                                                                                                                                                                                                                                                   
                                                                                                                                                                                                                                                                          
 void insertar_primero()
   {
      system("cls");
      struct nodo *nuevo;
      nuevo=( struct nodo*)malloc(sizeof( struct nodo));
      if(nuevo==NULL)
        printf(" MEMORIA INSUFICIENTE\n");
      else
        {
           printf("\n Nombre:   ");
           fflush(stdin);
           gets(nuevo->nombre);
           ultimo->siguiente= nuevo;
           nuevo->anterior=ultimo;
           nuevo->siguiente= primero;
           primero->anterior = nuevo;
           primero= nuevo;
           numNodos++;  
       }                                                                                                           
  }
                                                                                                                              
 void insertar_intermedio()
     {
        system("cls");
        struct nodo *actual;
        struct nodo *nuevo;
        nuevo=( struct nodo*)malloc(sizeof( struct nodo));
        if(nuevo==NULL)
           printf("\n MEMORIA INSUFICIENTE\n");
        if (numNodos < 2)
           printf("\n Número de nodos insuficiente");
        else{
             int pos_insertar; 
             printf("\n Nombre:   ");
             fflush(stdin);
             gets(nuevo->nombre);
             printf("\n Posición:   ");
             scanf(" %d", &pos_insertar);
             if((pos_insertar > 1) &&(pos_insertar <= numNodos))
                 {
                   actual=primero;
                   for (pos = 2; pos <pos_insertar; ++pos)
                     actual= actual->siguiente;
                   nuevo->siguiente= actual->siguiente;
                   nuevo->anterior = actual;
                   actual->siguiente->anterior = nuevo;
                   actual->siguiente = nuevo;
                   numNodos++;                                                                         
                 } 
             }
   printf("\n\n\n\n\n\n\n"); 
    system("pause");                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            
 }                                                                                                                                                                                                                                                                                                                                                        
                                                                                                                                                                                                                                                                                               
 void visualizar_inicio_final()
   {
     system("cls");
     
     struct nodo *actual;
     
     pos=1;
     
     actual=primero;
     
     while(pos<=numNodos)
       {
          printf(" %d.- ", pos);
          
          printf(" %s\n", actual->nombre);
          
          actual= actual->siguiente;
          
          pos++;
       }
       if(numNodos==0)
       
           printf("\n LISTA VACIA");
           
       printf("\n\n\n\n\n\n\n");
       
       system("pause");
       
  }  
  
                                                                                                      
  void visualizar_final_inicio()
  {
     system("cls");
     
     struct nodo *actual;
     
     actual=ultimo;
     
     pos= numNodos;
     
     while(pos >0)
     {
       printf(" %d.- ", pos);  
                  
       printf("%s\n",actual->nombre);
       
       actual = actual->anterior;
       
       pos--;
     }                                                                                                                    
   if(numNodos==0)
   
       printf("\n LISTA VACIA");
       
   printf("\n\n\n\n\n\n\n");
   
   system("pause");                                                                                               
  }     
  
  
void visualizar_primero_y_ultimo(){
    system("cls");
    if(numNodos==0)
       printf("\n LISTA VACIA");
    else
       printf("\n PRIMERO -------> %s", primero->nombre);
       printf("\n\n ULTIMO  -------> %s", ultimo->nombre);
       printf("\n\n\n\n\n\n\n");
       system("pause");
                                   } 
 void visualizar_posicion_final(){
      system("cls");
      int posicion;
      struct nodo *actual;
      
          actual = primero;
          printf("\n Indique posición    ");
          scanf("%d",&posicion);
          system("cls");
          for (pos = 2; pos <=posicion; pos++){
               actual = actual->siguiente;
                                              }
          while (posicion <= numNodos){   
            printf("%d.- ",posicion);
            printf("%s\n", actual->nombre);
            actual = actual->siguiente;
            posicion++;
                                      }
   
    printf("\n\n\n\n\n\n\n");                                                                               
    system("pause");                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
  }                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   
    
     
  
  void visualizar_posicion_inicio()
  {
      system("cls");
      int posicion;
      struct nodo *actual;
      
          actual = primero;
          printf("\n Indique posición    ");
          scanf("%d",&posicion);
          system("cls");
          for (pos = 2; pos <=posicion; pos++)
           {
            actual = actual->siguiente;
           }
           pos= posicion;
           
          while (pos!=0)
           { 
            printf(" %d.- ", pos);
            printf("%s\n", actual->nombre);
            actual = actual->anterior;
            pos--;
           }
   
    printf("\n\n\n\n\n\n\n");                                                                               
    system("pause");                                                                                                                                                                                                                                                                                                                                                                                                                                                     
 }                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            
                                                                                                 
  void visualizar_posicion_final_posicion()
    {
      system("cls");
      int p=1;
      int posicion;
      struct nodo *actual;
      
          actual = primero;
          printf("\n Indique posicion    ");
          scanf("%d",&posicion);
          system("cls");
          for (pos = 2; pos <=posicion; pos++)
           {
            actual = actual->siguiente;
           }
          while (p <= numNodos)
           {   
            printf("%s\n", actual->nombre);
            actual = actual->siguiente;
            p++;
           }
   
    printf("\n\n\n\n\n\n\n");                                                                               
    system("pause");                                                                                                                                                                                                                   
  }                           
  
                                                                                                  
  void visualizar_posicion_inicio_posicion()
    {
      system("cls");
      int p = 1;
      int posicion;
      struct nodo *actual;
      
          actual = primero;
          printf("\n Indique posicion    ");
          scanf("%d",&posicion);
          system("cls");
          for (pos = 2; pos <=posicion; pos++)
           {
            actual = actual->siguiente;
           }
          while (p <= numNodos)
           {   
            printf("%s\n", actual->nombre);
            actual = actual->anterior;
            p++;
           }
   
    printf("\n\n\n\n\n\n\n");  
    system("pause");                                                                                                                                                                                                                   
  }                                          
                                                                                                                                                                                                  
 void buscar()
   {
     system("cls");
     struct nodo *actual;
     char aux [40];
     int p = 1;
     int encontrado = 0; 
     
        actual = primero;
        system("cls");
        printf("\n Indique nombre a buscar    ");
        fflush(stdin);
        gets(aux);
        system("cls");
        while (p <= numNodos)
           {  
            if(strcmp(aux, actual->nombre)==0)
                    {
                      printf("\n %s  EXISTE", aux );
                      encontrado = 1;
                    }
                      p++;
                      actual = actual->siguiente;
           }                                                                                       
   if (encontrado==0)   
      printf("\n %s NO EXISTE", aux );
                                                                                                                                                                                                                                    
   printf("\n\n\n\n\n\n\n");                                                                      
   system("pause");                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 
  }                                                                                                                                                                                          
                                                                                          
 void eliminar(){
    system("cls");
    struct nodo  *aux;
    struct nodo  *actual;
    int nodo_eliminar;
    int x;
    printf("\n Indique la posición del nombre  a eliminar    ");
    scanf(" %d", &nodo_eliminar);
    if(nodo_eliminar > numNodos || nodo_eliminar < 1)
       printf("ELEMENTO INEXISTENTE");
    if(nodo_eliminar == 1)
      { 
       aux = primero;
       primero = primero->siguiente;
       if(primero == NULL)
          ultimo = NULL;
    else
      primero->anterior == ultimo;
       }
       else if(nodo_eliminar == numNodos)
       { 
          aux = ultimo;
          ultimo->anterior->siguiente = primero;
          ultimo = ultimo->anterior;
       }else {                                                                                                                                                                                                                     
             actual = primero;
             for(x=1; x<nodo_eliminar;++x)
               actual = actual->siguiente;
             aux = actual;
             actual->anterior->siguiente = actual->siguiente;
             actual->siguiente->anterior = actual->anterior;
   }
   free(aux);
   numNodos--;                                                                                              
 }                                                                                                                                                                                                                                                                                                                                                                                                                                    



 
  
