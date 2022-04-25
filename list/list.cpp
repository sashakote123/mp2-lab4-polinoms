#include "list.h"
using namespace std;



void Polinoms::setPolinom(int k) {
	Monom m;
	PolinomSize = k;
	for (int i = 0; i < k; i++) {
		cin >> m.Value;
		cin >> m.degree;
		if (m.Value == 0)
			throw "value cannot be zero!";
		if (m.degree > 1000)
			throw "degree is too high!";
		if (m.degree < 0)
			throw "degree cannot be negative!";
		if (m.degree < 100)
			throw "too low degree!";
		polinom.push_back(m);
	}
	for (int i = 0; i < PolinomSize; i++)
		for (int j = i + 1; j < PolinomSize; j++) {
			if (polinom[i].degree == polinom[j].degree) {
				polinom[i].Value += polinom[j].Value;
				polinom.removeAt(j);
				PolinomSize--;
				j--;
			}
		}
}

void Polinoms::setTestPolinom(double value1, int degree1, double value2, int degree2){
	Monom m;
	PolinomSize = 2;
	m.degree = degree1;
	m.Value = value1;
	if (m.Value == 0)
		throw "value cannot be zero!";
	if (m.degree > 1000)
		throw "degree is too high!";
	if (m.degree < 0)
		throw "degree cannot be negative!";
	if (m.degree < 100)
		throw "too low degree!";
	polinom.push_back(m);
	m.degree = degree2;
	m.Value = value2;
	if (m.Value == 0)
		throw "value cannot be zero!";
	if (m.degree > 1000)
		throw "degree is too high!";
	if (m.degree < 0)
		throw "degree cannot be negative!";
	if (m.degree < 100)
		throw "too low degree!";
	polinom.push_back(m);

	for (int i = 0; i < PolinomSize; i++)
		for (int j = i + 1; j < PolinomSize; j++) {
			if (polinom[i].degree == polinom[j].degree) {
				polinom[i].Value += polinom[j].Value;
				polinom.removeAt(j);
				PolinomSize--;
				j--;
			}
		}
}

void Polinoms::printPolinom() {
	for (int i = 0; i < PolinomSize; i++) {
		cout << polinom[i].Value << "*X^" << polinom[i].degree / 100 << "*Y^" << (polinom[i].degree / 10) - (polinom[i].degree / 100) * 10 << "*Z^" << polinom[i].degree % 10;
		if (i != PolinomSize - 1)
			cout << "+";
	}
}

Polinoms Polinoms::operator + (Polinoms v) {
	Polinoms result;
	result.PolinomSize = PolinomSize + v.PolinomSize;
	Monom m;
	for (int i = 0; i < PolinomSize; i++) {
		m.Value = polinom[i].Value;
		m.degree = polinom[i].degree;
		result.polinom.push_back(m);
	}
	for (int i = 0; i < v.PolinomSize; i++) {
		m.Value = v.polinom[i].Value;
		m.degree = v.polinom[i].degree;
		result.polinom.push_back(m);
	}
	for (int i = 0; i < result.PolinomSize; i++)
		for (int j = i + 1; j < result.PolinomSize; j++) {
			if (result.polinom[i].degree == result.polinom[j].degree) {
				result.polinom[i].Value += result.polinom[j].Value;
				result.polinom.removeAt(j);
				result.PolinomSize--;
				j--;
			}
			//если степень итого монома равна степени житого монома, сложить сзачени€ коэфициентов и записать как новый моном, понизить размер монома на 1
		}
	for (int i = 0; i < result.PolinomSize; i++)
		if (result.polinom[i].Value == 0) {
			result.polinom.removeAt(i);
			result.PolinomSize--;
			i--;
		}


	return result;
}

Polinoms Polinoms::operator * (Polinoms v) {
	Polinoms result;
	result.PolinomSize = PolinomSize * v.PolinomSize;
	Monom m;

	for (int i = 0; i < PolinomSize; i++)
		for (int j = 0; j < v.PolinomSize; j++) {
			m.Value = polinom[i].Value * v.polinom[j].Value;
			m.degree = polinom[i].degree + v.polinom[j].degree;
			if (m.degree > 1000)
				throw("degree is too high!");
			result.polinom.push_back(m);
		}

	return result;

}

Polinoms Polinoms::operator*(double v) {
	Polinoms result;
	result.PolinomSize = PolinomSize;
	Monom m;
	for (int i = 0; i < PolinomSize; i++) {
		m.Value = polinom[i].Value * v;
		m.degree = polinom[i].degree;
		result.polinom.push_back(m);
	}
	return result;
}

bool Polinoms::operator==(Polinoms v) {
	int a = 0;
	if (polinom.GetSize() != v.polinom.GetSize())
		return false;
	else {
		for (size_t i = 0; i < polinom.GetSize(); i++) {
			if (polinom[i].degree == v.polinom[i].degree && polinom[i].Value == v.polinom[i].Value)
				a++;
		}
		if (a == polinom.GetSize())
			return true;
		else
			return false;
	}
}

