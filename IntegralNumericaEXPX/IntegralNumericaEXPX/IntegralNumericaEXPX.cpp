// calcula aproximacoes da integral de e^x no intervalo de 0 a 1.

#include <iostream>
using namespace std;

float Funcao(float x) //calcula o valor da funcao no ponto x
{
	return exp(x);
}

float Derivada2(float x) //calcula o valor da segunda derivada da funcao no ponto x
{
	return exp(x);
}

float Derivada4(float x) //calcula o valor da quarta derivada da funcao no ponto x
{
	return exp(x);
}

float Retangular(float a, float b) //aproximacao pelo metodo retangular (ponto médio)
{
	return (b - a) * Funcao((a + b) / 2);
}

float RetangularErro(float a, float b) //erro estimado da aproximacao pelo metodo retangular (ponto médio)
{
	return -((pow((b - a), 3) / 24) * Derivada2(a + ((b - a) / 2)));
}

float Trapezio(float a, float b) //aproximacao pelo metodo dos trapezios
{
	return (b - a) * ((Funcao(a) + Funcao(b)) / 2);
}

float TrapezioErro(float a, float b) //erro estimado da aproximacao pelo metodo dos trapezios
{
	return -((pow((b - a), 3) / 12) * Derivada2(a + ((b - a) / 2)));
}

float Simpson(float a, float b) //aproximacao pelo metodo de Simpson
{
	return (b - a) * ((Funcao(a) + (4 * Funcao((a + b) / 2)) + Funcao(b)) / 6);
}

float SimpsonErro(float a, float b) //erro estimado da aproximacao pelo metodo de Simpson
{
	return -((pow((b - a), 5) / 2880) * Derivada4(a + ((b - a) / 2)));
}

float QuadraturaAdaptativa(float a, float b, float erro) { //aproximacao pelo metodo da quadratura adaptativa
	float Q = Simpson(a, b); //calcula a aproximacao pelo metodo de Simpson
	float erroQ = SimpsonErro(a, b); //calcula o erro da aproximacao

	if (abs(erroQ) > erro) //Verifica se o erro atual da aproximacao é menor que o erro desejado, se for maior executa
	{
		float pm = (a + b) / 2; //encontra ponto medio entre os dois intervalos de integracao
		float Q1 = QuadraturaAdaptativa(a, pm, erro); //calcula aproximacao do primeiro intervalor até o ponto medio
		float Q2 = QuadraturaAdaptativa(pm, b, erro); //calcula aproximacao do ponto medio até o segundo intervalo
		Q = Q1 + Q2; //soma aproximacoes parciais
	}
	return Q; //retorna valor da aproximacao
}

int main()
{
	float a = 0; //delimita o intervalo
	float b = 1;

	float erro = 0.00000001; //determina o erro de aproximacao desejado para uso na quadratura adaptativa

	float metodo1 = Retangular(a, b); //realiza calculo das aproximacoes
	float metodo2 = Trapezio(a, b);
	float metodo3 = Simpson(a, b);

	float erro1 = RetangularErro(a, b); //realiza calculo dos erros aproxiamdos
	float erro2 = TrapezioErro(a, b);
	float erro3 = SimpsonErro(a, b);

	float QA = QuadraturaAdaptativa(a, b, erro); //calcula integral pelo metodo da quadratura adaptativa

	//mostra valores no prompt

	cout << "Para a funcao e^x o calculos resultam em: " << endl;

	cout << "Metodo 1(retangular): " << metodo1 << endl;
	cout << "Erro 1: " << erro1 << endl;
	cout << "Metodo 2(trapezios): " << metodo2 << endl;
	cout << "Erro 2: " << erro2 << endl;
	cout << "Metodo 3(Simpson): " << metodo3 << endl;
	cout << "Erro 3: " << erro3 << endl;

	cout << "Metodo 4(quadratura adaptativa) :" << QA << endl;

	cin.get();
}