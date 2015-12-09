//RPG

#include <iostream>
#include <math.h>

using namespace std;

int bHealth = 20;
int bAtt = 5;
int bDef = 5;
int bSpeed = 5;
int bXP = 10; //you get like 2 per monster and more depending on the bosses?
int stats[10];
string name = "";

int main() {
	stats[0] = 1; //level
	stats[1] = bHealth; //current health
	stats[2] = bHealth; //total health
	stats[3] = bAtt;
	stats[4] = bDef;
	stats[5] = bSpeed;
	stats[8] = 0; //Start with 0 exp
	stats[9] = bXP; //xp required for level up


	cout << "You wake up surrounded by trees and blue skies as far as you can see..." << endl;
	cout << "You hear the bushes behind you rustling and turn around." << endl;
	cout << "???: WHOA! I didn't realize you "
	

	autoBattle();
	//bBattle();

	cout << "Game over" << endl;
	return 0;
}

void autoBattle() {
	int mHealth = 10 + (stats[0] * 3) + (rand() % 5 - 2); 
	int mSpeed = 2 + (stats[0] * 2) + (rand() % 5 - 2);
	int mAtt = (stats[0] / 2) +1;
	int mDef = (stats[0] / 2) +1;

	for (int i = stats[0]*3; i > 0; i--) {
		int x = rand() % 2;
		switch (x) {
		case 0: mAtt++;
			break;
		case 1: mDef++;
			break;
		}
	}
	int damage = 0;
	int move;
	cout << "\t****ENEMY MONSTER ENCOUNTER****" << endl << endl;
	while (mHealth > 0 && stats[1] > 0) {
		cout << "\tENEMY HP: " << mHealth;
		cout << "\tAttack: " << mAtt << "\tDefense: " << mDef << "\tSpeed: " << mSpeed << endl << endl;
		cout << "\t#1 Attack" << endl;
		cout << "\t#2 Defend" << endl;
		cout << "\t#3 Flee" << endl;
		cout << "Health: " << stats[2] << endl;
		switch (move) {
		case 1:
		if (mSpeed > stats[5]) {
			damage = mAtt - stats[4];
			if (damage > 0) {
				stats[2] -= damage;
				cout << "You take " << damage << " damage" << endl;
			}
			else {
				stats[2]--;
				cout << "You take 1 damage" << endl;
			}
			if (stats[2] > 0 && mHealth > 0) {
				damage = stats[3] - mDef;
				if (damage > 0) {
					mHealth -= damage;
					cout << "You deal " << damage << " damage" << endl;
				}
				else {
					mHealth--;
					cout << "You deal 1 damage" << endl;
				}
			}
		}
		else {
			damage = stats[3] - mDef;
			if (damage > 0) {
				mHealth -= damage;
				cout << "You deal " << damage << " damage" << endl;
			}
			else {
				mHealth--;
				cout << "You deal 1 damage" << endl;
			}
			if (stats[2] > 0 && mHealth > 0) {
				damage = mAtt - stats[4];
				if (damage > 0) {
					stats[2] -= damage;
					cout << "You take " << damage << " damage" << endl;
				}
				else {
					stats[2]--;
					cout << "You take 1 damage" << endl;
				}
			}
		}
	}



	testLevel();
	return;
}

void testLevel() {
	if (stats[8] >= stats[9]) {
		int skill = 0;
		stats[0]++;
		stats[8] = abs(stats[8] - stats[9]);
		stats[9]+= 2;
		cout << "LEVEL UP!" << endl;
		cout << "How would you like to spend your 5 skill points" << endl;
		cout << "Enter the corresponding number to add a point to that stat..." << endl;
		for (int i = 5; i > 0; i--) {
			cout << "\nPOINTS REMAINING: " << i << endl;
			cout << "\t#1 (+1)Attack: " << stats[3] << endl;
			cout << "\t#2 (+1)Defense: " << stats[4] << endl;
			cout << "\t#3 (+1)Speed: " << stats[5] << endl;
			cout << "\t#4 (+2)Health: " << stats[2] << endl;
			cin >> skill;
			switch(skill) {
			case 1: stats[3]++;
				break;
			case 2: stats[4]++;
				break;
			case 3: stats[5]++;
				break;
			case 4: stats[2] += 2;
				break;
			default: i++;
				cout << "Invalid input, try again" << endl;
				break;
			}
			stats[1] = stats[2];
		}
	}
	return;
}