#include<conio.h>
#include<stdio.h>

//funções protótipo      //ele= elemento //rear(A) inicio a esquerda e front(B) inicio a direita
int isfull();            //inserir A; eject(deletar em A); Push(inserir em B); Pop(delete em B); 
int isempty();           
void inject(int);
void push(int);
int eject();
int pop();
void display();

//variaveis globais
int dq[5]={0};
int rear=-1;
int front=-1;

int main(){
    int ch, ele;//ch é escolha  //ele é elemento
    do{
        printf("\n1.Inserir em PilhaA\n2.Deletar em PilhaA\n3.Inserir em PilhaB\n4.Remover em PilhaB\n5.Mostrar o deque\n6.Verificar se eh simetrico\n7.Sair");
        printf("\n Selecione uma opcao\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:
              if(isfull())                                            
                printf("\nO Deque está cheio");
              else{
                printf("\nInsira um valor para PilhaA:");
                scanf("%d",&ele);
                inject(ele);
            }
            break;
            case 2:
              if(isempty())
                printf("\nO Deque esta vazio");
              else{
                ele=eject();
                printf("\n %d O valor foi deletado",ele);
            }   
            break;
            case 3:
              if(isfull())
                printf("\nO Deque está cheio");
              else{
                printf("\nInsira um valor para PilhaB:");
                scanf("%d",&ele);
                push(ele);
            }
            break;
            case 4:
              if(isempty())
                printf("\nO Deque esta vazio");
              else{
                ele=pop();
                printf("\n %d O valor foi deletado",ele);
            }
            break;
            case 5:
              if(isempty())
                printf("\nO Deque esta vazio");
              else{
                display();
            }
            case 6:
              if((dq[0]==dq[4])&&(dq[1]==dq[3])){
               printf("\nEsse Deque eh simetrico");
            }
             else                                            //verificação de simetria, eu pensei que se as extremidades forem iguais, e as adjacentes das mesmas são iguais então é simetrico, ja que o vetor tem 5 elementos
               printf("\nO deque nao eh simetrico");
            break;
            case 7:
              printf("\nTchau! Ate a proxima\n");
            break;
    }
   }while(ch!=7);
}

int isfull()
{                                               //verificação se esta cheia   no empty isfull o 0= falso e 1= verdade       
    if(((front==0)&&(rear==4))||(front==rear+1))    //aqui ele compara se falta algo para preencher os valores do vetor, e caso todos estejam ocupados vai estar cheia
      return 1;                                      //no meu código o 0 representa vazio, caso se pergunte o motivo dele estar no vetor imprimido, ele apenas oculpa um espaço temporário
    else
      return 0;
}
int isempty()
{                                //verificação se esta vazia
    if(front==-1)                             
      return 1;
    else
      return 0;
}
void inject(int ele)                           //inserir elemento no inicio Pilha A, verifica a posição inicial do rear(A) e front(B)  caso não tenha nada vai adicionar um valor que digitar no enunciado
{
    if(front==-1) 
    {
        front=0;
        rear=0;
    }
    else if(rear=0)              
      rear=4; 
    else
      rear=rear+1;
    dq[rear]=ele;
}
int eject()
{                        //remover elemento no inicio Pilha A, vai verificar se algum valor foi digitado no lado A do deque e se sim, apaga uma posição
       int ele;
       ele=dq[rear];
       dq[rear]=0;
       if(front==rear){        
        front=-1;
        rear=-1;
       }
       else if(rear==0)
         rear=4;
       else
         rear=rear-1;
       return ele;
}
void push(int ele)      //insirir elemento no final PilhaB , verifica a posição inicial do front(B) e rear(A) caso não tenha nada vai adicionar um valor que digitar no enunciado
{                  
    if(front==-1){
        front=0;
        rear=0;
    }
    else if(front==0)
      front=4;
    else
      front=front-1;
    dq[front]=ele;
}
int pop()
{                          //remover elemento na PilhaB, vai verificar se algum valor foi digitado no lado B do deque e se sim, apaga uma posição
    int ele;
    ele=dq[front];
    dq[front]=0;
    if(front==rear){
        front=-1;
        rear=-1;
    }
    else if(front==4)
      front=0;
    else
      front=front+1;
    return ele;
} 
void display()
{                                              //mostra  os dados armazenados no vetor, ou seja, o deque
    int i;   
    printf("\n front = %d e rear = %d", front,rear);
    printf("\n Este eh o Deque que foi montado com os valores dados :-");
    for(i=0;i<5;i++)
      printf("| %d |", dq[i]);
}

