#pragma once
#include <unordered_map>
#include "mygrammarBaseVisitor.h"

class mVisitor : public mygrammarBaseVisitor 
{
public:
    std::unordered_map<std::string, double> data;
private:

    bool isCyfra(char symbol) 
    {
        if (((int)symbol - 48) < 0 || (((int)symbol - 48)) > 9)
            return false;
        else
            return true;
    }

    double stod(const char* str, int n) 
    {
        double res = 0;
        double power = 1;              
        int i = 0;
        bool flag = false;

        if (str[0] == '-') 
        {
            flag = true;
            i++;
        }

        while (str[i] != '.')
        {
            if (i == n) 
            {
                if (flag)
                    return -res;
                else
                    return res;
            }
            res *= 10.0;

            if (!isCyfra(str[i]))
                throw std::exception("invalid input");

            res += (double)((int)str[i] - 48);
            i++;
        }
        i++;

        while (i < n)
        {
            power /= 10.0;

            if (!isCyfra(str[i]))
                throw std::exception("invalid input");

            res += power * ((double)((int)str[i] - 48));
            i++;
        }

        if (flag)
            return -res;
        else
            return res;
    }

    std::any visitLexprR(mygrammarParser::LexprRContext* context) 
    {
        std::cout << "Working in LexprR" << std::endl;
        return visit(context->expr());
    }

    std::any visitExprADDexpr(mygrammarParser::ExprADDexprContext* context) 
    {
        std::cout << "Working in ExprADDexpr" << std::endl;
        double first = std::any_cast<double>(visit(context->expr(0)));
        double second = std::any_cast<double>(visit(context->expr(1)));
        if (context->ADD())
            return first + second;
        return first - second;
    }

    std::any visitExprMULexpr(mygrammarParser::ExprMULexprContext* context) 
    {
        std::cout << "Working in ExprMULexpr" << std::endl;
        double first = std::any_cast<double>(visit(context->expr(0)));
        double second = std::any_cast<double>(visit(context->expr(1)));
        if (context->DIV())
            return first / second;
        return first * second;
    }

    std::any visitNUMBER(mygrammarParser::NUMBERContext* context) 
    {
        std::cout << "Working in NUMBER:\t";
        double first = stod(context->DOUBLE()->getText().c_str(), context->DOUBLE()->getText().size());
        std::cout << context->DOUBLE()->getText() << std::endl;
        std::cout << first << std::endl;
        return first;
    }

    std::any visitProg_row(mygrammarParser::Prog_rowContext* context) 
    {
        std::cout << "Working in Prog_row" << std::endl;
        double first = std::any_cast<double>(visit(context->row()));
        data.insert(std::make_pair("result", first));
        return visit(context->prog());
    }

    std::any visitOneLineProg(mygrammarParser::OneLineProgContext* context) 
    {
        std::cout << "Working in OneLineProg" << std::endl;
        double val = std::any_cast<double>(visit(context->row()));
        data.insert(std::make_pair("result", val));
        return val;
    }

    std::any visitNAMEING(mygrammarParser::NAMEINGContext* ctx) 
    {
        std::cout << "Working in NAMEING:\t";
        std::cout << ctx->NAME()->getText() << std::endl;
        return data.find(ctx->NAME()->getText())->second;
    }

    std::any visitName_eq_expr_sep(mygrammarParser::Name_eq_expr_sepContext* ctx) 
    {
        std::cout << "Working in Name_eq_expr_sep" << std::endl;
        double tmp = std::any_cast<double>(visit(ctx->expr()));
        data.insert(std::make_pair(ctx->NAME()->getText(), tmp));
        return tmp;
    }

    std::any visitPrint_expr_sep(mygrammarParser::Print_expr_sepContext* ctx) 
    {
        std::cout << "Working in Print_expr_sep" << std::endl;
        double tmp = std::any_cast<double>(visit(ctx->expr()));
        std::cout << "PRINT:" << tmp << std::endl;
        return tmp;
    }
};