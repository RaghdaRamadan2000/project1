#include<iostream>
#include<string>
using namespace std;
string mat[5][5] = { { "a", "b", "c", "d", "e" }, { "f", "g", "h", "i", "j" }, { "k", "l", "m", "n", "R" }, { "p", "q", "r", "s", "t" }, { "u", "v", "w", "z", "y" } };
string player = "x";

void printmat(){
	system("cls");
	for (int i = 0; i < 5; ++i){
		for (int j = 0; j < 5; ++j){
			cout << mat[i][j] << " ";
		}
		cout << endl;

	}


}
void play(){
	string pos;
	cout << "choose your position-player(" << player << "):";
	cin >> pos;
	if (pos == "a" || pos == "b" || pos == "c" || pos == "d" || pos == "e" || pos == "f" || pos == "g" || pos == "h" || pos == "i" || pos == "j" || pos == "k" || pos == "l" || pos == "m" || pos == "n" || pos == "R" || pos == "p" || pos == "q" || pos == "r" || pos == "s" || pos == "t" || pos == "u" || pos == "v" || pos == "w" || pos == "y" || pos == "z" || pos == "a")
	{

		for (int i = 0; i < 5; ++i){
			for (int j = 0; j < 5; ++j){
				if (mat[i][j] == pos){
					mat[i][j] = player;
				}
			}
		}
		if (player == "x")
			player = "o";
		else
			player = "x";
	}
	else cout << "please enter true postion\n";
}
string whowin(){
	int xc = 0, oc = 0;
	int counter = 0;
	for (int i = 0; i < 5; ++i){
		for (int j = 0; j < 5; ++j){
			if (mat[i][j] != "x" || mat[i][j] != "o"){
				counter++;
			}
			if (mat[i][j] != "x" && mat[i][j] != "o"){
				counter++;
				if (mat[i][j] == "x")xc++;
				else if (mat[i][j] == "o")oc++;
				if (xc == 5 || oc == 5){

					return xc>oc ? "x" : "o";
				}

			}
			xc = 0;
			oc = 0;
		}

		for (int i = 0; i < 5; ++i){
			for (int j = 0; j < 5; ++j){
				if (mat[j][i] == "x")xc++;
				else if (mat[j][i] == "o")oc++;
				if (xc == 5 || oc == 5){

					return xc>oc ? "x" : "o";
				}

			}
			xc = 0;
			oc = 0;
		}
		if (mat[0][0] == "x" && mat[1][1] == "x" && mat[2][2] == "x"&& mat[3][3] == "x" && mat[4][4] == "x")return "x";
		else if (mat[0][0] == "o" && mat[1][1] == "o" && mat[2][2] == "o"&& mat[3][3] == "o" && mat[4][4] == "o")return "o";
		else if (mat[0][4] == "x" && mat[1][3] == "x" && mat[2][2] == "x"&& mat[3][1] == "x" && mat[4][0] == "x")return "x";
		else if (mat[0][4] == "o" && mat[1][3] == "o" && mat[2][2] == "o"&& mat[3][1] == "o" && mat[4][0] == "o")return "o";
		else if (mat[0][0] == "x" && mat[0][1] == "x"&& mat[0][2] == "x"&& mat[0][3] == "x"&& mat[0][4] == "x")return "x";
		else if (mat[1][0] == "x" && mat[1][1] == "x"&& mat[1][2] == "x"&& mat[1][3] == "x"&& mat[1][4] == "x")return "x";
		else if (mat[2][0] == "x" && mat[2][1] == "x"&& mat[2][2] == "x"&& mat[2][3] == "x"&& mat[2][4] == "x")return "x";
		else if (mat[3][0] == "x" && mat[3][1] == "x"&& mat[3][2] == "x"&& mat[3][3] == "x"&& mat[3][4] == "x")return "x";
		else if (mat[4][0] == "x" && mat[4][1] == "x"&& mat[4][2] == "x"&& mat[4][3] == "x"&& mat[4][4] == "x")return "x";
		else if (mat[0][0] == "o" && mat[0][1] == "o"&& mat[0][2] == "o"&& mat[0][3] == "o"&& mat[0][4] == "o")return "o";
		else if (mat[1][0] == "o" && mat[1][1] == "o"&& mat[1][2] == "o"&& mat[1][3] == "o"&& mat[1][4] == "o")return "o";
		else if (mat[2][0] == "o" && mat[2][1] == "o"&& mat[2][2] == "o"&& mat[2][3] == "o"&& mat[2][4] == "o")return "o";
		else if (mat[3][0] == "o" && mat[3][1] == "o"&& mat[3][2] == "o"&& mat[3][3] == "o"&& mat[3][4] == "o")return "o";
		else if (mat[4][0] == "o" && mat[4][1] == "o"&& mat[4][2] == "o"&& mat[4][3] == "o"&& mat[4][4] == "o")return "o";
		if (counter == 0) return "z";
		return ".";
	}
}
int main(){
	while (whowin() == "."){
		printmat();
		play();
	}
	printmat();
	if (whowin() == "z")
		cout << "No winner " << endl;
	else
		cout << "winner is player(" << whowin() << "),congratulattion\n";
	return 0;
}