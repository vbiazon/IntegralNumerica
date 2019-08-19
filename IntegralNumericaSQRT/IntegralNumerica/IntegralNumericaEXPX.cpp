#include <iostream>
using namespace std;

float Funcao(float x)
{
	return sqrt(1 - pow(x, 2));
}

float Derivada2(float x)
{
	return -1 / pow((1 - pow(x, 2)), 3 / 2);
}

float Derivada4(float x)
{
	return -(12 * pow(x, 2)) + 3 / pow((1 - pow(x, 2)), 7 / 2);
}

float Retangular(float a, float b)
{
	return (b - a) * Funcao((a + b) / 2);
}

float RetangularErro(float a, float b)
{
	return -((pow((b - a), 3) / 24) * Derivada2(a + ((b - a) / 2)));
}

float Trapezio(float a, float b)
{
	return (b - a) * ((Funcao(a) + Funcao(b)) / 2);
}

float TrapezioErro(float a, float b)
{
	return -((pow((b - a), 3) / 12) * Derivada2(a + ((b - a) / 2)));
}

float Simpson(float a, float b)
{
	return (b - a) * ((Funcao(a) + (4 * Funcao((a + b) / 2)) + Funcao(b)) / 6);
}

float SimpsonErro(float a, float b)
{
	return -((pow((b - a), 5) / 2880) * Derivada4(a + ((b - a) / 2)));
}

float QuadraturaAdaptativa(float a, float b) {
	return a + b;
}

int main()
{
	float a = 0;
	float b = 1;

	float metodo1 = Retangular(a, b);
	float metodo2 = Trapezio(a, b);
	float metodo3 = Simpson(a, b);

	float erro1 = RetangularErro(a, b);
	float erro2 = TrapezioErro(a, b);
	float erro3 = SimpsonErro(a, b);

	cout << "Para a funcao sqrt(1-x^2) o calculos resultam em: " << endl;

	cout << "Metodo 1(retangular): " << metodo1 << endl;
	cout << "Erro 1: " << erro1 << endl;
	cout << "Metodo 2(trapezios): " << metodo2 << endl;
	cout << "Erro 2: " << erro2 << endl;
	cout << "Metodo 3(Simpson): " << metodo3 << endl;
	cout << "Erro 3: " << erro3 << endl;


	cin.get();
}