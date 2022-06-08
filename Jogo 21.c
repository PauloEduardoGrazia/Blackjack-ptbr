#include <stdio.h>
#include <time.h>
#include <locale.h>


int Embaralhar(int cartas[]) // Função para embaralhar as cartas
{
	
	int i2, i;
	int baralho[52]; // Array dos Baralhos, responsavel pelos seus valores
		
		for (i=0;i<52;i++){
			baralho[i] = ( i / 13 + 3)* 100 + i % 13 + 1; // Como o Baralho possui 52 cartas, 13 cartas e 4 naipes, 
														  //esse calculo fará que os valores das cartas maiores que 14 não aparecão, ou seja
														  //o array baralho[52], terá valor 13 ou K, o baralho[14] tera valor 1 ou A.
														  //Mudando o naipe cada vez que passar de 13
		}
		

	srand(time(NULL)); // Randomiza os numeros
	
		for (i = 0; i < 52; i++)
		{
			do{
				i2 = rand() % 52; //Randomiza a posição das cartas
				
			}while (baralho[i2] == 0);
			
			cartas[i] = baralho[i2]; //Passa o valor das cartas e a posição
			baralho[i2] = 0; //pra randomizar todas as cartas
		}

}

int ConversorJQK(int a) //Função para converter as cartas 11, 12 e 13 para J Q e K
{
		if ((a % 100 == 11) ||(a % 100 == 12) ||(a % 100 == 13)){
			return (a / 100)* 100 + 10;
			
		} 
		
		else{
			return a; // Continua se não for as cartas J Q K
			
		} 
}

void DesenhoCartas(int num) // Função para os desenhos das cartas
{
	char Naipe;
	int NumCarta;
	
		Naipe = num / 100; // Responsavel pelo Naipe, como ele é char, ele pega o num e converte para char usando a tabela ascii
		NumCarta = num % 100; // Responsavel de mostrar o numero da carta
		
		switch (NumCarta) //Switch para mostrar os desenhos das cartas, AJQK são cartas diferentes, especiais
		{
			default:
			{
				printf("\t\t\t\t\t\t _____________\n");          
				printf("\t\t\t\t\t\t|             |\n");         
				printf("\t\t\t\t\t\t|  %c          |\n", Naipe); // Mostra o Naipe
				printf("\t\t\t\t\t\t|             |\n");
				printf("\t\t\t\t\t\t|             |\n");
				printf("\t\t\t\t\t\t|     %2d      |\n", NumCarta); // Mostra o numero da Carta
				printf("\t\t\t\t\t\t|             |\n");			
				printf("\t\t\t\t\t\t|             |\n");    
				printf("\t\t\t\t\t\t|         %c   |\n", Naipe);	
				printf("\t\t\t\t\t\t|_____________|\n");
				break;
			}
			
			case 1: 
			{
				printf("\t\t\t\t\t\t _____________\n");          
				printf("\t\t\t\t\t\t|             |\n");         
				printf("\t\t\t\t\t\t|  %c          |\n", Naipe);
				printf("\t\t\t\t\t\t|             |\n");
				printf("\t\t\t\t\t\t|             |\n");
				printf("\t\t\t\t\t\t|      A      |\n", NumCarta);
				printf("\t\t\t\t\t\t|             |\n");			
				printf("\t\t\t\t\t\t|             |\n");    
				printf("\t\t\t\t\t\t|         %c   |\n", Naipe);	
				printf("\t\t\t\t\t\t|_____________|\n");
				break;
			}
			
			case 11:
			{
				printf("\t\t\t\t\t\t _____________\n");          
				printf("\t\t\t\t\t\t|             |\n");         
				printf("\t\t\t\t\t\t|  %c          |\n", Naipe);
				printf("\t\t\t\t\t\t|             |\n");
				printf("\t\t\t\t\t\t|             |\n");
				printf("\t\t\t\t\t\t|      J      |\n", NumCarta);
				printf("\t\t\t\t\t\t|             |\n");			
				printf("\t\t\t\t\t\t|             |\n");    
				printf("\t\t\t\t\t\t|         %c   |\n", Naipe);	
				printf("\t\t\t\t\t\t|_____________|\n");
				break;
			}
			case 12:
			{
				printf("\t\t\t\t\t\t _____________\n");          
				printf("\t\t\t\t\t\t|             |\n");         
				printf("\t\t\t\t\t\t|  %c          |\n", Naipe);
				printf("\t\t\t\t\t\t|             |\n");
				printf("\t\t\t\t\t\t|             |\n");
				printf("\t\t\t\t\t\t|      Q      |\n", NumCarta);
				printf("\t\t\t\t\t\t|             |\n");			
				printf("\t\t\t\t\t\t|             |\n");    
				printf("\t\t\t\t\t\t|         %c   |\n", Naipe);	
				printf("\t\t\t\t\t\t|_____________|\n");
				break;
			}
			case 13:
			{
				printf("\t\t\t\t\t\t _____________\n");          
				printf("\t\t\t\t\t\t|             |\n");         
				printf("\t\t\t\t\t\t|  %c          |\n", Naipe);
				printf("\t\t\t\t\t\t|             |\n");
				printf("\t\t\t\t\t\t|             |\n");
				printf("\t\t\t\t\t\t|      K      |\n", NumCarta);
				printf("\t\t\t\t\t\t|             |\n");			
				printf("\t\t\t\t\t\t|             |\n");    
				printf("\t\t\t\t\t\t|         %c   |\n", Naipe);	
				printf("\t\t\t\t\t\t|_____________|\n");
				break;
			}
	
		}
}

/*int Regras(void)
{
		system("cls");
		printf("\n\n\n\n\n\n\n\n\n\t - O jogador e o computador recebem inicialmente duas cartas cada.\n");	
		printf("\t - O jogador inicia a partida, decidindo entre permanecer com a mão que está, ou comprar mais cartas,"); 
		printf("\n\t  na tentativa de atingir o máximo de pontos, desde que seja menor ou igual a 21.");
		printf("\n\t - Quando o jogador passa a vez, o computador joga da mesma maneira, tentando atingir a melhor pontuação.");
		printf("\n\t - Cada jogador pode no máximo acumular 5 cartas na mão e sempre que alguém estoura o limite de 21 pontos,");
		printf("\n\t  o adversário vence.");
		printf("\n\n\n\t  Carregando....");
		sleep(3);
		system("cls");

}*/

int Menu(void)
{
	int i, c=0;
	int SomaJogador=0;
	int SomaBot=0;
	int CartasJogador[5]={0};
	int CartasBot[5]={0};
	int cartas[52];
	char iniciar;
	char regras;
			
		do{				
				printf("\n\n\n\n");  						
				printf("\t\t\t\t\t _____________________________________\n");          
				printf("\t\t\t\t\t|                                     |\n");
				printf("\t\t\t\t\t|            Bem Vindo ao,            |\n");         
				printf("\t\t\t\t\t|             Jogo do 21              |\n");		
				printf("\t\t\t\t\t|_____________________________________|\n");			
				printf("\t\t\t\t\t|                                     |\n");     			
				printf("\t\t\t\t\t|                                     |\n");
				printf("\t\t\t\t\t|     1.   Jogador vs Computador      |\n"); 	
				printf("\t\t\t\t\t|                                     |\n"); 							 						                                  				                
				printf("\t\t\t\t\t|                                     |\n"); 						
				printf("\t\t\t\t\t|                                     |\n"); 							   
				printf("\t\t\t\t\t|                                     |\n"); 
				printf("\t\t\t\t\t|                                     |\n"); 
				printf("\t\t\t\t\t| Pressione Enter para iniciar o jogo |\n"); 								
				printf("\t\t\t\t\t|                                     |\n"); 	
				printf("\t\t\t\t\t|                                     |\n");
				printf("\t\t\t\t\t|                                     |\n");   	
				printf("\t\t\t\t\t|_____________________________________|\n"); 
			
			printf("\n\t\t\t\t\t    Criado por: Paulo Eduardo Grazia\n"); 	
			
			iniciar = getchar();		
			
							
		}while (iniciar != '\n'); //Inicia usando o Enter
	
			

	system("cls");
	printf("\n");
	
	Embaralhar(cartas); // Chama o Embaralhar para embaralhar as cartas
	
	system("color 09"); // Cor azul

	CartasJogador[0]=cartas[0];// Dá a 1 carta, no slot 0
	CartasJogador[1]=cartas[1];// Dá a 2 carta, no slot 1
	CartasBot[0]=cartas[2];// Dá a 1 carta, no slot 2
	CartasBot[1]=cartas[3];// Dá a 2 carta, no slot 3
	

	printf("\n\t\tCartas do Oponente\n");
	DesenhoCartas(CartasBot[0]);//Mostra as Cartas
	DesenhoCartas(CartasBot[1]);
	
	printf("\n");
	
	printf("\n\t\tSuas Cartas são Essas\n");
	DesenhoCartas(CartasJogador[0]);
	DesenhoCartas(CartasJogador[1]);

	
		i=0;
		for (i=0; i<2; i++){
			
			if(ConversorJQK(CartasJogador[i]) % 100 == 10){ //Ve se o Jogador pegou JQK, e adiciona 10 na soma
				SomaJogador = SomaJogador + 10;
				
			} 
			
			else{
				SomaJogador = SomaJogador + CartasJogador[i]%100;// Adiciona o valor da carta na soma
				
			} 
					
		}
	
		printf("\n\t\tSuas Cartas Somam:%d\n\n",SomaJogador); // Mostra a Soma das Primeiras Cartas
	
		i=0;
		for (i=0; i<3; i++)
		{
			char j = 's';
			
			printf("\n\t\t\tVocê quer mais uma Carta? Pressione s para Sim ou n para Não: ");
			
			do{				
				j = getchar();
				
			}while (j!='s' && j!='n'); // Ve se a pessoa digitou s ou n
			
			if (j=='s') //Se digitou s
			{
				
				printf("\n\n\n\n\t\tVocê pegou uma Carta do Baralho, Agora você tem: %d Cartas\n", i+3); //Mostra o numero de cartas
				CartasJogador[i+2]=cartas[i+4];//Vai adcionando as cartas na verificação de se pegou até 5, e coloca os valores no slot
				
				printf("\n\t\tEssa é a carta que você Pegou: \n"); //Mostra a carta que pegou
				DesenhoCartas(CartasJogador[i+2]);		
				
				if (SomaJogador > 21){ // Passou de 21
				
					system("color 04"); // Muda a cor para vermelho
					
					printf("\n\t\tSuas Cartas Somam:%d\n\n",SomaJogador);
					printf("\n\t\tSeu Oponente Venceu, mais sorte na próxima vez!\n");
					return 1;
				}
							
				else if(ConversorJQK(CartasJogador[i+2]) %100 ==10){ //Ve se o Jogador pegou JQK, e adiciona 10 na soma
					SomaJogador = SomaJogador + 10;
					
					printf("\n\t\tSuas Cartas Somam:%d\n\n",SomaJogador);
					
					if (SomaJogador > 21){//Arruma o erro em que a ultima carta pega não seja contada levando a uma soma maior que 21, que levava a vitoria do jogador
					
						system("color 04");
						
						printf("\n\t\tSeu Oponente Venceu, mais sorte na próxima vez!\n");
						return 0;
					}
				} 
				
				if(SomaJogador < 21 && ConversorJQK(CartasJogador[i+2]) %100 !=10){// Adiciona o valor normal da carta
					
					SomaJogador = SomaJogador + CartasJogador[i+2]%100;	
					
					printf("\n\t\tSuas Cartas Somam:%d\n\n",SomaJogador);
				} 														
			}
			
			else // Se for digitado 'n'
			{
				if (SomaJogador > 21){// Verifica se as cartas pegadas passam de 21
					printf("\n\n\n\t\tSuas Cartas Somam:%d\n\n",SomaJogador);
					system("color 04");
					printf("\n\n\t\tSeu Oponente Venceu, mais sorte na próxima vez!\n");
					
					return 0;
				}
				
				break;
				
			}
			
		}
	
	printf("\n\n|--------- Turno do Oponente");
	
		i=0;
		for (i=0; i<2; i++)
		{	
		
			if (SomaJogador > 21){ //Verifica se o Jogador passou 21
				
					printf("\n\n\n\t\tSuas Cartas Somam:%d\n\n",SomaJogador);
					system("color 04");
					printf("\n\n\t\tSeu Oponente Venceu, mais sorte na próxima vez!\n");
					
					return 0;
			}
				
			if(SomaJogador == SomaBot){//Verifica se está empatado e que possivelmente o bot não arriscara a pegar outra carta
				system("color 07");
				printf("\n\t\tEmpate!\n");
				return 0;
			}
			
			if(ConversorJQK(CartasBot[i]) % 100 == 10){ // Mesmo esquema com as cartas dos players
					SomaBot = SomaBot + 10;
			} 
				
				else{
					SomaBot = SomaBot + CartasBot[i]%100;
				} 
				
			if (SomaJogador < SomaBot) // Se as cartas do player forem menores
			{
				system("color 04");
				printf("\n\n\t\tSeu Oponente Venceu, mais sorte na próxima vez!\n");
				return 0;
			}	
				
		}
		
			
		i=0;
		for (i=0; i<3 && SomaBot<19; i++)
		{
			printf("\n\n\n\n\t\tEle pegou uma Carta do Baralho, Agora ele tem: %d Cartas\n", i+3);
			CartasBot[i+2]=cartas[i+7];
			
			printf("\n\t\tEssa é a carta que Ele pegou no baralho: \n");
			DesenhoCartas(CartasBot[i+2]);
			
			//Ele já pega a carta
			SomaBot = SomaBot + ConversorJQK(CartasBot[i+2])%100;
			printf("\n\t\tAs cartas dele somam:%d\n\n", SomaBot);
	
			
			if (SomaBot>21){//Verifica se o bot passou de 21
			
				system("color 02");
				printf("\n\t\tSeu Oponente passou do valor de 21, Você Venceu!\n");
				return 0;
			}
			
			else if (SomaJogador == SomaBot){//Verifica se está empatado e que possivelmente o bot não arriscara a pegar outra carta
				system("color 07");
				printf("\n\t\tEmpate!\n");
				return 0;
			}
			
			else if (SomaJogador < SomaBot){//A soma do bot é maior que a do player
			
				system("color 04");
				printf("\n\t\tSeu Oponente Venceu, mais sorte na próxima vez!\n");
				return 0;
			}		
		}
				
}


int main(void)
{
	setlocale(LC_ALL, "Portuguese");
	
	char repetir;//Responsavel pelo looping
	
	
	Menu();//Abre o Menu
  	
	  	//Quando acaba a partida aparece esta mensagem
		printf("\n\n\n\n\t\tVocê vai querer Jogar De novo? Pressione s para Sim ou n para Não: ");
		
		do{
			repetir = getchar();
			
		} while (repetir!='s' && repetir!='n');
	   
	    //Reinicia
	   	if(repetir == 's'){
	   		
		   	system("cls");
			printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tCarregando...\n\n");		
			sleep(2);
			system("cls");
			main();		
		}
	   
	   	//Fecha o programa
		else if (repetir == 'n'){
			system("cls");
			printf("\n\n\n\n\t\tVocê Realmente quer fechar o jogo? Pressione s para Sim ou n para Não: ");
			
			do{
			repetir = getchar();
			
			} while (repetir!='s' && repetir!='n');
		
			if(repetir == 's'){
				system("cls");
				printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tObrigado por Jogar :)\n\n");
			
				sleep(2);
				system("cls");
			}
			
			else if (repetir == 'n'){
				
				//Quando acaba a partida aparece esta mensagem
				system("cls");
				printf("\n\n\n\n\t\tVocê vai querer Jogar De novo? Pressione s para Sim ou n para Não: ");
		
				do{
					repetir = getchar();
					
				} while (repetir!='s' && repetir!='n');
				
					if(repetir == 's'){
	   		
					   	system("cls");
						printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tCarregando...\n\n");		
						sleep(2);
						system("cls");
						main();		
					}
					
					if(repetir == 'n'){
						system("cls");
						printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tObrigado por Jogar :)\n\n");
			
						sleep(2);
						system("cls");
					}
			}
		}

	return 0;
}
