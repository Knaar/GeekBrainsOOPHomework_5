#include <iostream>
#include <string>
#include <vector>
using namespace std;

//	1 Task

template <class T>
class Pair1
{
public:
	Pair1(T first, T second) :One(first), Two(second) {};
	T first()  const { return One; }
	T second() const { return Two; }
protected:
	T One, Two;
};

// 2 Task

template<class T1, class T2>
class Pair
{
public:
	Pair(T1 first, T2 second) :One(first), Two(second) {};
	T1 first()  const { return One; }
	T2 second() const { return Two; }
private:
	T1 One;
	T2 Two;
};

// 3 Task

template<class T3>
class Pair<string, T3>
{
public:
	Pair(string first, T3 second) :One(first), Two(second) {};
	string first()  const { return One; }
	T3 second() const { return Two; }
protected:
	string One;
	T3 Two;
};

template<class T3>
class StringValuePair :public Pair<string, T3> {
public:
	StringValuePair(string word, T3 num) :Pair<string, T3>(word, num) {
	};
};

//	4 Task

enum ERank { Ace = 1, Two = 2, Tree = 3, Four = 4, Six = 6, Seven = 7, Eigh = 8, Nine = 9, Ten = 10, Jack = 10, Queen = 10, King = 10 };
enum ESuit { Hearts, Diamonds, Clubs, Spades };

class Card {
public:
	Card(ERank r, ESuit s) :Rank(r), Suit(s) { FrontSide = true; }
	void Flip();
	int GetValue() const;
private:
	ERank Rank;
	ESuit Suit;
	bool FrontSide;
};
int Card::GetValue()const {
	int temp;
	if (FrontSide) {
		temp = Rank;
	}
	return temp;
}
void Card::Flip() { FrontSide = !FrontSide; }

//Now the Class Hand

class Hand
{
public:
	vector<Card*>CardVector;
	void Add(Card* someCard) { CardVector.push_back(someCard); }
	void Dell() { CardVector.clear(); }

	int Points;
	int GetValue() {
		auto it = CardVector.begin();
		for (it = CardVector.begin(); it != CardVector.end(); ++it)
		{
			Points += (*it)->GetValue();
			cout << "Points :";
		}
		for (it = CardVector.begin(); it != CardVector.end(); ++it) {
			if ((*it)->GetValue() == Ace && Points <= 11) {
				Points += 10;
			}
		}
		return Points;
	}
};

// Generic Player

class GenericPlayer :public Hand
{
public:
	GenericPlayer(string name) :playerName(name) { };

	virtual void IsHitting() = 0;
	bool IsBoosted() {
		return(GetValue() > 21);
	}
	void Bust() {
		cout << playerName << IsBoosted() ? "Busted" : "Not busted";
	}

protected:
	string playerName;
};


int main()
{

	Pair1<int> p1(6, 9);
	cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';
	const Pair1<double> p2(3.4, 7.8);
	cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';

	Pair<int, double> p3(6, 7.8);
	cout << "Pair: " << p3.first() << ' ' << p3.second() << '\n';
	const Pair<double, int> p4(3.4, 5);
	cout << "Pair: " << p4.first() << ' ' << p4.second() << '\n';

	Pair<string, int> A("aaa", 7);
	cout << "Pair: " << A.first() << ' ' << A.second() << '\n';


	StringValuePair<int> SVP("Amazing", 7);
	StringValuePair<float> SVP2("Amazing2", 7.2);
	cout << "Pair: " << SVP.first() << ' ' << SVP.second() << '\n';
	cout << "Pair: " << SVP2.first() << ' ' << SVP2.second() << '\n';


	return 0;
}