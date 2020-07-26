/* Tarefa de decifrar uma cifra
 *
 * Dica: veja em referencia/cifrador.c o codigo-fonte do programa
 * que gerou as cifras que voce precisa decifrar!
 */

#include <stdio.h>

#define TAM_BUFFER 60
char buffer_entrada[TAM_BUFFER];
char buffer_saida[TAM_BUFFER];

const char senha[] = "SENHASECRETA";

char contrasenha(char a, char b){
	if(a < 'A')
		return a;
	
	a = a - 'A';
	char i;
	char k, c;	
	for(i = 'A', k = 'Z'-'A'+1; (i+b+2*'A')%k != a; i++);
	
	return i; 
}

int main() {
	/* Leitura da entrada */
	fgets(buffer_entrada, TAM_BUFFER, stdin);

	int i, j;
	for (i=0; (i<TAM_BUFFER) && (buffer_entrada[i]!='\0') && (buffer_entrada[i]!='\n'); i++) {
		buffer_saida[i] = contrasenha(buffer_entrada[i], senha[j]);
		j++;
		if (senha[j]=='\0') j=0;
	}
	buffer_saida[i]='\0';

	/* Escrever saida na tela */
	printf("%s\n", buffer_saida);

	return 0;
}
