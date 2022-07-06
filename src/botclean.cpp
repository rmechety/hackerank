#include "botclean.hpp"

double dst(int ax, int ay, int bx, int by)
{

	return (abs(ax - bx) + abs(ay - by));
}

pair<int, int> get_closer(int r, int c, vector<string> board)
{

	pair<int, int> closer = make_pair(-1, -1);
	double min = DBL_MAX;
	int i = 0;
	int s = board.size();

	while (i < s)
	{
		int pos = board[i].find("d");
		if (pos != string::npos && dst(pos, i, c, r) < min)
		{
			closer = make_pair(pos, i);
			board[i][pos] = '-';
			min = dst(pos, i, c, r);
			if (board[i].find("d") != string::npos)
				i--;
		}
		i++;
	}
	return closer;
}

bool is_dirty(const vector<string> &board)
{
	// si board contient un 'd' return true
	int i = 0;
	int s = board.size();
	while (i < s)
	{
		if (board[i].find("d") != string::npos)
			return true;
		i++;
	}
	return false;
}

matrix_pos get_dirty(const vector<string> &board)
{
	vector<pair<int, int>> dirty;
	int i = 0;
	int s = board.size();
	while (i < s)
	{
		int pos = board[i].find("d");
		if (pos != string::npos)
		{
			dirty.push_back(make_pair(pos, i));
		}
		i++;
	}
	return dirty;
}

string get_move(int const &bot_c, int const &bot_r, int const &dirt_c, int const &dirt_r)
{
	// retourne le move à faire pour aller vers le dirty soit UP, DOWN, LEFT, RIGHT
	vector<string> instruction = {"UP", "DOWN", "LEFT", "RIGHT"};

	int move;
	if (bot_c == dirt_c)
		(bot_r > dirt_r) ? move = 0 : move = 1;
	else
		(bot_c > dirt_c) ? move = 2 : move = 3;
	return instruction[move];
};





// void change_pos(string &move, int &c, int &r)
// {
// 	(move == "LEFT") ? c-- : 0;
// }

vector<string> get_min_move(const vector<vector<string>> &next_move)
{
	// retourne le move qui a la plus petite size
	vector<string> min_move;
	int min = INT_MAX;
	int i = 0;
	int s = next_move.size();
	while (i < s)
	{
		if (next_move[i].size() < min)
		{
			min = next_move[i].size();
			min_move = next_move[i];
		}
		i++;
	}
	return min_move;
}

void print_board(const vector<string> &board)
{
	int i = 0;
	int s = board.size();
	cout << "------BOARD------" << endl;
	while (i < s)
	{
		cout << board[i] << endl;
		i++;
	}
	cout << "-----------------" << endl;
}
// fonction print_move
void print_move(const vector<string> &move)
{
	int i = 0;
	int s = move.size();
	cout << "------MOVE------" << endl;
	while (i < s)
	{
		cout << move[i] << endl;
		i++;
	}
	cout << "-----------------" << endl;
}

class possibility
{
  private:
	char move;
	possibility *prev;
	vector<possibility *>next;

  public:
	possibility(char move, possibility *prev, possibility *next)
		: move(move), prev(prev), next(next){};
	~possibility();
	char get_move()
	{
		return move;
	};
	vector<char> get_insts()
	{
		vector<char> ret;
		possibility *tmp = this;
		while (tmp != nullptr)
		{
			ret.push_back(tmp->get_move());
			tmp = tmp->prev;
		}
		return ret;
	};
	t_board get_board(t_board &board)
	{
		t_board ret = board;
		vector<char> inst = get_insts();
		for (int i = 0; i < inst.size(); i++)
		{
			change_pos(inst[i], ret.c, ret.r);
		}
	};
	possibility *create_possibility(char move)
	{(
		possibility * created = new possibility(move,this,nullptr); 
		return created;
	}
	possibility *add_possibilty(possibility * to_add)
	{
		next.push_back(to_add);
		return to_add;
	};
	possibility *create_add_possibilty(char move)
	{
		possibility * c = create_possibility();

		add_possibilty(c);

		return c;	
		
	};
	void remove_possibility(possibility *to_remove)
	{
		vector<possibility *>::iterator it_erase = std::find(next.begin(),next.end(),to_remove);
		if(it_erase != next.end())
			next.erase(it_erase);		
		return;
	}

};

// generation par etage
vector<string> generate_next_move(t_board &board)
{
	while (is_solution)
	{
		// vecteur de vecteur de string
		// chaque string est un move
		// boucler sur
	}
}

// vector<string> generate_next_move(int &posr, int &posc, vector<string> &board, int deep)
// {
// 	// 	SI il y a des dirty
// 	// Regarder tout les moves possibles
// 	//     repeter pour tout les moves
// 	// Renvoyer la suite de move la plus petite
// 	if (deep > 30)
// 	{
// 		vector<string> next_moves;
// 		next_moves.push_back("END");
// 		return next_moves;
// 	}

// 	// parcourir la sortie avec rev iterator
// 	cerr << __FUNCTION__ << " | deep : " << deep << endl;
// 	// print_board(board);
// 	deep += 1;
// 	if (is_dirty(board))
// 	{
// 		matrix_moves next_moves;
// 		matrix_pos dirty_pos = get_dirty(board);
// 		for (matrix_pos::iterator it = dirty_pos.begin(); it != dirty_pos.end(); it++)
// 		{
// 			int new_r = posr, new_c = posc;
// 			t_board tested_board = board;

// 			tested_board[new_r][new_c] = '-';
// 			string move = get_move(posc, posr, it->first, it->second);
// 			change_pos(move, new_c, new_r);
// 			tested_board[new_r][new_c] = 'b';
// 			vector<string> nxt = generate_next_move(new_r, new_c, tested_board, deep);
// 			nxt.push_back(move);
// 			next_moves.push_back(nxt);
// 			// print_move(nxt);
// 		}
// 		return get_min_move(next_moves);
// 	}
// 	vector<string> next_moves;
// 	next_moves.push_back("END");
// 	cerr << "END RECURSION" << endl;
// 	return next_moves;
// };

void next_move(int posr, int posc, vector<string> board)
{

	vector<string> moves = generate_next_move(posr, posc, board, 0);

	// iterrer sur les moves et afficher le move
	for (vector<string>::iterator it = moves.begin(); it != moves.end(); it++)
	{
		if (*it == "END")
			break;
		cout << *it << endl;
	}
}
void outOfMemHandler()
{
	std::cerr << "Unable to satisfy request for memory\n";
	sleep(5);
	std::abort();
}

int main(void)
{

	std::set_new_handler(outOfMemHandler);

	int pos[2];
	vector<string> board;
	cin >> pos[0] >> pos[1];
	for (int i = 0; i < 5; i++)
	{
		string s;
		cin >> s;
		board.push_back(s);
	}
	next_move(pos[0], pos[1], board);
	return 0;
}