//
// Created by xiaoyu ren on 2022/11/21.
//

#ifndef COMPILER_PARSER_H
#define COMPILER_PARSER_H
#include "Lexer.h"
#include "AstNode.h"

namespace compiler {
    class Parser {
    private:
        Lexer &lexer;
        std::shared_ptr<AstNode> ParseExpr();
        std::shared_ptr<AstNode> ParseAddExpr();
        std::shared_ptr<AstNode> ParseMulExpr();
        std::shared_ptr<AstNode> ParsePrimaryExpr();
    public:
        Parser(Lexer &lexer):lexer(lexer){}
        std::shared_ptr<ProgramNode> Parse();
    };
}


#endif //COMPILER_PARSER_H
