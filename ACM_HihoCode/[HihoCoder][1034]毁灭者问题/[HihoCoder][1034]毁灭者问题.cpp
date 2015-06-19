// [HihoCoder][1034]ªŸ√’ﬂŒ Ã‚.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
/*
Input:
5
0 10 1
0 12 1
0 20 1
0 12 1
0 10 1
3
5 1 5
19 1 5
19 1 5
Output:
83
*/
/*
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class MAGICUNIT{
public:
	int ManaDisappear(void){
		int m = Mana;
		Mana = 0;
		return m;
	}
	void ManaIncrease(int time){
		if (Mana + (time - Time)*ManaRecoverSpeed < MaxMana)
			Mana += (time - Time)*ManaRecoverSpeed;
		else
			Mana = MaxMana;
		Time = time;
	}
	MAGICUNIT(int im, int mm, int mrs) :InitialMana(im), Mana(InitialMana), MaxMana(mm), ManaRecoverSpeed(mrs), Time(0){}
	~MAGICUNIT(){}
private:
	int InitialMana;
	int Mana;
	int MaxMana;
	int ManaRecoverSpeed;
	int Time;
};

void DestroyerProblem(void){
	int magicUnitNum;
	cin >> magicUnitNum;
	vector<MAGICUNIT> MagicUnits;
	while (magicUnitNum--){
		int im, mm, mrs;
		cin >> im >> mm >> mrs;
		MAGICUNIT m(im,mm,mrs);
		MagicUnits.push_back(m);
	}
	int operateNum;
	cin >> operateNum;
	int ManaAbsorption = 0;
	while (operateNum--){
		int t, fm, lm;
		cin >> t >> fm >> lm;
		for (int i = fm - 1; i < lm; ++i){
			MagicUnits[i].ManaIncrease(t);
			ManaAbsorption += MagicUnits[i].ManaDisappear();
		}
	}
	cout << ManaAbsorption << endl;
}*/
#include <iostream>
#include <algorithm>
using namespace std;

int MagicUnits[500000][4] = { 0 };
void DestroyerProblem(void){
	int magicUnitNum;
	cin >> magicUnitNum;
	for (int i = 0; i < magicUnitNum; i++)
		cin >> MagicUnits[i][0] >> MagicUnits[i][1] >> MagicUnits[i][2];
	int operateNum;
	cin >> operateNum;
	int ManaAbsorption = 0;
	while (operateNum--){
		int t, fm, lm;
		cin >> t >> fm >> lm;
		for (int i = fm - 1; i < lm; ++i){
			ManaAbsorption += min(MagicUnits[i][0] + (t - MagicUnits[i][3])*MagicUnits[i][2], MagicUnits[i][1]);
			MagicUnits[i][0] = 0;
			MagicUnits[i][3] = t;
		}
	}
	cout << ManaAbsorption << endl;
}
int main(void){
	DestroyerProblem();
	system("Pause");
	return 0;
}