// Problem: 10341 - Solve It
// Link: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1282
// Author: Pham Nguyen Quoc Hung

#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
#include <string>
#include <math.h>

using namespace std;

#define MAX 100000

double p, q, r, s, t, u, k;

//Equation: p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*pow(x, 2) + u;
double Equation(double x){
	return p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*pow(x, 2) + u;
}

int main()
{
	while (cin >> p >> q >> r >> s >> t >> u){
		if (Equation(1.0) > 0 || Equation(0.0) < 0){
			printf("No solution\n");
			continue;
		}
		double l = 0.0;
		double r = 1.0;
		double m;
		while (r - l > 1e-9){
			m = (l + r) / 2;
			if (Equation(m) > 0){
				l = m;
			}
			else r = m;
		}
		printf("%.4f\n", m);
	}

	return 0;
}