#include "Tokenizer.h"

const string Tokenizer::Delimiters = " \t()[]{};<>=+-*&";
const string Tokenizer::OperatorsArr[] = { "++", "--", "==", "->", "=", "+", "-", "*", "&", "<<", ">>" };
const int Tokenizer::OperatorsNum = 11;
const string Tokenizer::DelimiterWhiteSpaces = " \t";
const string Tokenizer::PredefinedTypesArr[] = { "char", "short", "int", "long", "float", "double", "void", "function" };
const int Tokenizer::PredefinedTypesNum = 8;
const string Tokenizer::KeywordsGroup1Arr[] = { "if", "else", "for", "while" };
const int Tokenizer::KeywordsGroup1Num = 4;
const string Tokenizer::KeywordsGroup2Arr[] = { "class", "private", "public", "const", "virtual" };
const int Tokenizer::KeywordsGroup2Num = 5;