﻿#include <iostream>

#include "mygrammarBaseVisitor.h"
#include "mygrammarLexer.h"
#include "mygrammarParser.h"
#include "mygrammarVisitor.h"
#include "mygrammarBaseVisitor.h"
#include "mVisitor.h"


int main()
{
    int main() {

        std::string exp = "a=7;b=6-a*5;<<b;";
        std::stringstream stream(exp);

        std::cout << "Создание входного потока выражений" << std::endl;
        antlr4::ANTLRInputStream input(stream);

        std::cout << "Создание лексера" << std::endl;
        mygrammarLexer lexer(&input);

        std::cout << "Создание потока токенов" << std::endl;
        antlr4::CommonTokenStream tokens(&lexer);

        std::cout << "Создание парсера" << std::endl;
        mygrammarParser parser(&tokens);

        std::cout << "Создание visitor" << std::endl;
        mVisitor visitor;

        std::cout << "Обход дерева" << std::endl;
        visitor.visit(parser.prog());
        std::cout << "Обход дерева закончен" << std::endl;

        return 0;
    }
}