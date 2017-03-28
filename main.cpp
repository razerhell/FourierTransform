#include <iostream>
#include <complex>
#include <vector>

#define pi		3.1415926535897932384626433832795
#define vcSize	9

using namespace std;

void dft(const vector<complex<double> > &in, vector<complex<double > > &out, int flag = -1);
void printComplexVector(const vector<complex<double> > &in);

int main(int argc, char *argv[])
{
	vector<complex<double> > in;
	vector<complex<double> > out;
	vector<complex<double > >out2;
	in.resize(vcSize);

	for (int i = 0; i < vcSize; ++i)
		in[i] = complex<double>(i, 0);

	dft(in, out);
	printComplexVector(out);

	dft(out, out2, 1);
	printComplexVector(out2);

	system("pause");
	return 0;
}

// 傅里叶变换
void dft(const vector<complex<double>>& in, vector<complex<double>>& out, int flag)
{
	int vectorCount = in.size();
	out.clear();
	out.resize(vectorCount);

	for (int i = 0; i < vectorCount; ++i)
	{
		complex<double> stepR(0, 0);
		complex<double> dj(0, 1);
		for (int j = 0; j < vectorCount; ++j)
			stepR += in[j] * exp((double)flag * dj * 2.0 * pi * (double)i * (double)j / (double)vectorCount);
		flag > 0 ? stepR /= vectorCount : NULL ;
		out[i] = stepR;
	}
}

void printComplexVector(const vector<complex<double> > &in)
{
	printf("------------------------------------------\n");
	for (size_t i = 0; i < in.size(); ++i)
		printf("%d\t\t%f\t%f\n", i, in[i].real(), in[i].imag());
}
