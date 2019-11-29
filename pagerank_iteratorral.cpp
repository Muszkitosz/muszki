#include <iostream>
#include <math.h>
#include <vector>
#include <iterator>

using namespace std;

void ki (vector<double> tomb)
{
	vector<double>::iterator it;
	for (it = tomb.begin(); it != tomb.end(); it++)
	{
		cout<<"PageRank ["<< distance(tomb.begin(),it)<<"] : " << *it << endl;
	}
}

double
tavolsag(vector<double> PR,vector<double> PR_v)
{
	vector<double>::iterator pri = PR.begin();
	vector<double>::iterator prvi = PR_v.begin();

	double tav = 0.0;
	for(pri = PR.begin();pri != PR.end();pri++)
	{
		tav += abs((*pri) - (*prvi));
		prvi++;
	}
	return tav;
}

int main(void){

vector<vector<double>> L= {
	{0.0, 0.0, 1.0 / 3.0, 0.0},
	{1.0, 1.0 / 2.0, 1.0 / 3.0, 1.0},
	{0.0, 1.0 / 2.0, 0.0, 0.0},
	{0.0, 0.0, 1.0 / 3.0, 0.0}
};

vector<vector<double>>::iterator sor;
vector<double>::iterator oszlop;
vector<double>::iterator Pi;
vector<double>::iterator PvI;


vector<double> PR;
	for(int i = 0;i < 4;i++)
		PR.push_back(0.0);
vector<double> PRv;
	for(int i = 0;i < 4;i++)
		PRv.push_back(1.0 / 4.0);


	// vector<double> PR = {0.0, 0.0, 0.0, 0.0};
	// vector<double> PRv = {1.0 / 4.0, 1.0 / 4.0, 1.0 / 4.0, 1.0 / 4.0};

	for (;;)
	{
		PR = PRv;

	for(int i=0; i<PR.size(); i++)
	{
			double temp = 0.0;

			for(int j=0; j<PRv.size(); j++)
			{
				temp += L[i][j] * PR[j];
				PRv[i] = temp;
			}
	}

	if (tavolsag(PR,PRv) < 0.000001)
		break;
	}

	ki(PR);
	return 0;
}
