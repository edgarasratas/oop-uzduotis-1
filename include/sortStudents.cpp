#include "Funkcijos.h"

bool sortBadStudents(const Student& a, const Student& b) {
	return a.final < b.final;
}
bool isBad(const Student& a) {
	return a.final < 5;
}