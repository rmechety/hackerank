/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmechety <rmechety@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 12:52:24 by rmechety          #+#    #+#             */
/*   Updated: 2022/07/05 19:16:32 by rmechety         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// clang-format off
#ifndef PROTOTYPES_H
# define PROTOTYPES_H

#include <climits>
#include <cmath>
#include <float.h>
#include <iostream>
#include <unistd.h>
#include <vector>
using namespace std;

typedef vector<vector<int> > matrix;
typedef vector<vector<string> > matrix_moves;
typedef vector<string > t_board;
typedef vector<pair<int, int> > matrix_pos;
// clang-format on
/* -------------------------------------------------------------------------- */
/*                          FILE = src/botclean.cpp                           */
/* -------------------------------------------------------------------------- */
double dst(int ax, int ay, int bx, int by);
pair<int, int> get_closer(int r, int c, vector<string> board);
bool is_dirty(const vector<string> &board);
matrix_pos get_dirty(const vector<string> &board);
string get_move(int const &bot_c, int const &bot_r, int const &dirt_c, int const &dirt_r);
void change_pos(string &move, int &c, int &r);
vector<string> get_min_move(const vector<vector<string>> &next_move);
void print_board(const vector<string> &board);
vector<string> generate_next_move(int &posr, int &posc, vector<string> &board, int deep);
void next_move(int posr, int posc, vector<string> board);
void outOfMemHandler();
int main(void);

#endif
