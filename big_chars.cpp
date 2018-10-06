#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Letter {
	vector<string> char_tab;
public:
	Letter(vector<string> tab);
	int get_width();
	int get_height();
	char get_char_at(int, int);
};

Letter::Letter(vector<string> tab) {
	char_tab = tab;
}

int Letter::get_width() {
	return char_tab.at(0).length();
}

int Letter::get_height() {
	return char_tab.size();
}

char Letter::get_char_at(int i, int j) {
	return (char_tab.at(i))[j];
}



vector<Letter> load_letters(string filename) {
	ifstream input("big_chars.txt");

	vector<Letter> letters;
	vector<string> letter_read;

	for(string line; getline(input, line); ) {
		letter_read.push_back(line);
		if(letter_read.size() == 8) {
			letters.push_back(Letter(letter_read));
			letter_read.clear();
		}
	}

	return letters;
}

void print_text(vector<Letter> letters, string text) {
	vector<string> result;

	string s = "";
	for(int height=0; height<8; ++height) {
		for(int i=0; i<text.length(); ++i) {
			Letter l = letters.at((int)text[i]);
			for(int width=0; width<l.get_width(); ++width) {
				s += l.get_char_at(height, width);
			}
			s += " ";
		}
		result.push_back(s);
		s = "";
	}
	
	for(vector<string>::iterator it = result.begin(); it != result.end(); ++it) {
		cout << *it << endl;
	}
}

int main(int argc, char* argv[]) 
{
	if(argc < 2) 
	{
		cout << "Usage : " << argv[0] << " text" << endl;
		exit(1);
	}

	print_text(load_letters("big_chars.txt"), argv[1]);

	exit(0);
}