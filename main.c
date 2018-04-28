/*
Copyright [2013] [Marllon Jos� Frizzo & Paulo Batista da Costa]

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* FUN��O FINALIZA
** Esta fun��o realiza a finaliza��o do programa .
** @param Esta fun��o n�o possui par�metros .
** @return Esta fun��o � desprovida de retorno .
*/
void finaliza(){
    printf("\tFinalizando caluladora RPN.\n");
    exit(0);
}

/* FUN��O ERRO
** Esta fun��o realiza a impress�o de mensagem de erro, e consecutivamente a finaliza��o do programa .
** @param Esta fun��o n�o possui  par�metros .
** @return Esta fun��o � desprovida de retorno .
*/
void erro(){
    printf("\tErr\n");
    exit(0);
}

/* FUN��O SOMA
** A fun��o realiza a soma de dois valores inteiros .
** @param par�metro p_num1 recebe o valor correspondente de NUM1; O par�metro p_num2 recebe  o valor correspondente de NUM2 .
** @return A fun��o retorna a soma dos dois par�metros, sendo que este resultado � um n�mero inteiro .
*/
int soma (int p_num1, int p_num2) {
    return p_num1 + p_num2;
}

/* FUN��O DIFERENCA
** A fun��o realiza a diferen�a entre dois n�meros inteiros .
** @param par�metro p_num1 recebe o valor correspondente de NUM1; O par�metro p_num2 recebe o valor correspondente de NUM2 .
** @return A fun��o retorna a diferen�a entre os dois par�metros, sendo que este resultado � um n�mero inteiro .
*/
int diferenca(int p_num1, int p_num2) {
    return p_num1 - p_num2;
}

/* FUN��O MULTIPLICA
** A fun��o realiza a multiplica��o entre dois n�meros inteiros .
** @param par�metro p_num1 recebe o valor correspondente de NUM1; O par�metro p_num2 recebe o valor correspondente de NUM2 .
** @return A fun��o retorna a multiplica��o entre dois par�metros, sendo que este resultado � um n�mero inteiro .
*/
int multiplica(int p_num1, int p_num2) {
	int recebe_p_num2 = 0, cont = 0, result_mult = 0;
	if (p_num1 < 0 && p_num2 < 0) {
		p_num1 = -p_num1;
		p_num2 = -p_num2;
	}
	if (p_num1 < 0 && p_num2 > 0) {
		recebe_p_num2 = p_num2;
		p_num2 = p_num1;
		p_num1 = recebe_p_num2;
	}
	for (cont = 0; cont < p_num1 ; cont++) {
		result_mult += p_num2;
	}
	return result_mult;
}

/* FUN��O RAIZ
** A fun��o determina a raiz quadrada de um n�mero inteiro .
** @param O par�metro p_num  recebe o valor de NUM1 ; A fun��o trabalha apenas com um par�metro .
** @return a fun��o retorna a raiz quadrada do par�metro, sendo esta um n�mero inteiro .
*/
int raiz(int p_num) {
	int contador, dentro_raiz = 0;
	if (p_num < 0) {
		printf ("\tErr \n");
		getchar();
		exit(0);
	}
	if (p_num == 1) {
		return 1;
	}
	for (contador = 0; contador < p_num; contador++) {
		dentro_raiz = multiplica(contador,contador);
		if (dentro_raiz == p_num) {
			return contador;
		}
		if (contador == p_num && dentro_raiz != p_num) {
			printf("\tErr \n");
			getchar();
			exit(0);
		}
	}
	return 0;
}

/* FUN��O DIVIDIR
** A fun��o divide  dois n�meros inteiros entre si.
** @param O par�metro p_num1 recebe o valor de NUM1; O par�mtro p_num2 recebe o valor de NUM2;
** @return A fun��o retorna o resultado da divis�o entre o par�metro p_num1 pelo par�metro p_num2, esse resultado  � inteiro.
*/
int dividir(int p_num1, int p_num2) {
	int contador, conta = 0, indicador_negativo = 0;
	if (p_num2 == 0) {
		printf ("\tErr \n");
		exit(0);
	}
	if (p_num1 < p_num2) {
		printf ("\tErr \n");
		exit(0);
	}
	if (p_num1 < 0 && p_num2 < 0) {
		p_num1 = - p_num1;
		p_num2 = - p_num2;
	}
	if (p_num1 < 0 && p_num2 > 0) {
		indicador_negativo = -1;
		p_num1 = - p_num1;
	}
	if (p_num1 > 0 && p_num2 < 0) {
		indicador_negativo = -1;
		p_num2 = - p_num2;
	}
	for (contador = 0; contador < p_num1; contador++) {
		conta = multiplica(contador,p_num2);
		if (conta == p_num1 && indicador_negativo == 0) {
			return contador;
		}
		if (conta == p_num1 && indicador_negativo == - 1) {
			return - contador;
		}
	}
	return contador;
}

/* FUN��O EXPONENCIAL
** A fun��o realiza o c�lculo de elevar um determinado n�mero a um expoente, obtendo um resultado inteiro.
** @param O par�metro p_num1 recebe o valor de NUM1; O par�metro p_num2 recebe o valor de NUM2 .
** @return A fun��o retorna o valor de p_num1 elevado a p_num2, sendo que este resultado � inteiro.
*/
int exponencial(int p_num1, int p_num2) {
	int result = 0, contador, resultado_parcial = 0;
		if  ( p_num2 == 0 || p_num1 == 1) {
			return 1;
		}
		else if (p_num2 == 2) {
			return multiplica(p_num1,p_num1);
		}
		else if (p_num2 == 1) {
			return p_num1;
		}
		else if (p_num2 < 0 ) {
			printf ("\tErr \n");
			getchar();
			exit(0);
		}
		else {
			resultado_parcial = multiplica(p_num1,p_num1);
			for (contador = 0; contador < p_num2 - 2; contador++) {
				result = multiplica(resultado_parcial,p_num1);
				resultado_parcial = result;
				}
		}
	return result;
}

/* FUN��O FATORIAL
** A fun��o fatorial realiza o calculo fatorial de um determinado n�mero .
** @param O par�metro p_num  recebe o valor de NUM1 .
** @return A fun��o retorna o calculo fatorial do par�metro p_num, sendo que este resultado � um valor inteiro.
*/
int fatorial (int p_num) {
	int contador, resultado = 0, variavel_auxiliar2 = 0, variavel_auxiliar_R = 0;
	if (p_num == 0 || p_num == 1) {
		return 1;
	}
	else if (p_num < 0) {
		printf("\tErr \n");
		exit(0);
	}
	else {
		variavel_auxiliar_R = p_num;
		variavel_auxiliar2 = p_num;
		for (contador = 0; contador < p_num - 1; contador++) {
			variavel_auxiliar2 --;
			resultado = multiplica(variavel_auxiliar_R,variavel_auxiliar2);
			variavel_auxiliar_R = resultado;
		}
	}
	return resultado;
}

/* FUN��O RESTO
** A fun��o resto realiza os c�lculos necess�rios para se obter o resto de uma divis�o .
** @param O par�metro p_num1 recebe o valor de NUM1; O par�metro p_num2 recebe o valor de NUM2 .
** @return A fun��o retorna o resto de p_num1 divido por p_num2, sendo que este resultado � inteiro .
*/
int resto(int p_num1,int p_num2) {
	int multiplica_quociente = 0, var_auxiliar1 = - p_num1, var_auxiliar2 = - p_num2;
	if (p_num1 == 0) {
		return 0;
	}
	if (p_num2 == 0) {
		printf ("\tErr \n");
		getchar();
		exit(0);
	}
	if (p_num1 == p_num2) {
		return 0;
	}
	if (p_num2 == 1) {
		return 0;
	}
	if (p_num1 == - p_num2) {
		return 0;
	}
	if ((p_num1 < 0 && p_num2 < 0) && (var_auxiliar1 > var_auxiliar2)) {
		p_num1 = - p_num1;
		p_num2 = - p_num2;
	}
	if (p_num1 < 0 && p_num2 > 0) {
		do {
			multiplica_quociente += p_num2;
		} while (multiplica_quociente < var_auxiliar1);
		if (multiplica_quociente == var_auxiliar1) {
			return 0;
		}
		else {
		return ((multiplica_quociente + p_num1) + var_auxiliar2);
		}
	}
	if (p_num1 > 0 && p_num2 < 0) {
		do {
			multiplica_quociente += p_num2;
		} while (multiplica_quociente > - p_num1);
		if (multiplica_quociente == - p_num1) {
			return 0;
		}
		else {
			return (p_num1 + (multiplica_quociente + var_auxiliar2));
		}
	}
	do {
		multiplica_quociente += p_num2;
	} while (multiplica_quociente < p_num1);
	if (multiplica_quociente == p_num1) {
		return 0;
	}
	else {
		return (p_num1 - (multiplica_quociente - p_num2));
	}
	exit(0);
}

int main(){
    system("clear"); // Compilar para GNU/Linux
    //system("cls"); // Compilar para Windows
    int numero_inteiro = 0, numero2_inteiro = 0, flag_raiz = 0, flag_fatorial = 0, flag_finaliza1 = 0, flag_finaliza2 = 0, valida_operacao = 0;
    int resultado = 0;
    char operador, numero[8], numero2[8];

    while(flag_finaliza1 == 0 && flag_finaliza2 == 0){
        resultado = 0;
        if (valida_operacao == 0){
            printf("\t");
            scanf("%s", numero);
            getchar();
            if (strcmp(numero, "t") == 0 || strcmp(numero, "T") == 0){
                flag_finaliza1++;
                finaliza();
            }
            else if (strcmp(numero, "r") == 0 || strcmp(numero, "R") == 0){
                erro();
            }
            else if (strcmp(numero, "c") == 0 ||strcmp(numero, "C") == 0){
                main();
            }
            else if (strcmp(numero, "!") == 0){
                erro();
            }
            else if (strcmp(numero, "%") == 0){
                erro();
            }
            else{
                numero_inteiro = atoi(numero);
            }
        }
        printf("\t");
        scanf("%s", numero2);
        getchar();
        if (strcmp(numero2, "t") == 0 || strcmp(numero2, "T") == 0) {
            flag_finaliza2++;
            finaliza();
        }
        else if (strcmp(numero2, "r") == 0 || strcmp(numero2, "R") == 0){
            flag_raiz++;
            operador = 'r';
        }
        else if (strcmp(numero2, "c") == 0 ||strcmp(numero2, "C") == 0){
                main();
            }
        else if (strcmp(numero2, "!") == 0){
            flag_fatorial++;
            operador = '!';
        }
        else if (strcmp(numero2, "^") == 0){
            erro();
        }
        else if (strcmp(numero2, "%") == 0){
            erro();
        }
        else{
            numero2_inteiro = atoi(numero2);
        }
        if (flag_fatorial == 0 && flag_raiz == 0){
            printf("\t");
            scanf("%c", &operador);
            getchar();
        }
        switch(operador){
            case '+':
                resultado = soma(numero_inteiro, numero2_inteiro);
                printf("\t(%d)\n", resultado);
                break;
            case '-':
                resultado = diferenca(numero_inteiro, numero2_inteiro);
                printf("\t(%d)\n", resultado);
                break;
            case 'r':
                if (flag_raiz == 1){
                    resultado = raiz(numero_inteiro);
                    printf("\t(%d)\n", resultado);
                }
                else{
                    resultado = raiz(numero2_inteiro);
                    printf("\t(%d)\n", resultado);
                }
                break;
            case '*':
                resultado = multiplica(numero_inteiro, numero2_inteiro);
                printf("\t(%d)\n", resultado);
                break;
            case '/':
                resultado = dividir(numero_inteiro, numero2_inteiro);
                printf("\t(%d)\n", resultado);
                break;
            case '^':
                resultado = exponencial(numero_inteiro, numero2_inteiro);
                printf("\t(%d)\n", resultado);
                break;
            case '!':
                if (flag_fatorial == 1){
                    resultado = fatorial(numero_inteiro);
                    printf("\t(%d)\n", resultado);
                }
                else{
                    resultado = fatorial(numero2_inteiro);
                    printf("\t(%d)\n", resultado);
                }
                break;
            case '%':
                resultado = resto(numero_inteiro, numero2_inteiro);
                printf("\t(%d)\n", resultado);
                break;
            case 'c':
                main();
                break;
            case 'C':
                main();
                break;
            default:
                erro();
        }

        flag_fatorial = 0;
        flag_raiz = 0;

        numero_inteiro = resultado;
        valida_operacao++;
    }
    return 0;
}
