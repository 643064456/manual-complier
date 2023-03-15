//
// Created by xiaoyu ren on 2022/11/21.
//

#include "Parser.h"

std::shared_ptr<compiler::ProgramNode> compiler::Parser::Parse() {
    auto node = std::make_shared<ProgramNode>();
    node->Lhs = ParseExpr();
    return node;
}

std::shared_ptr<compiler::AstNode> compiler::Parser::ParseExpr() {
    return ParseAddExpr();
}

std::shared_ptr<compiler::AstNode> compiler::Parser::ParseAddExpr() {
    std::shared_ptr<AstNode> left = ParseMulExpr();
    while (lexer.GetCurrentToken()->kind == TokenKind::Add || lexer.GetCurrentToken()->kind == TokenKind::Sub) {
        BinaryOperator binaryOperator = BinaryOperator::Add;
        if (lexer.GetCurrentToken()->kind == TokenKind::Sub){
            binaryOperator = BinaryOperator::Sub;
        }
        lexer.GetNextToken();
        auto node = std::make_shared<BinaryNode>();
        node->binaryOperator = binaryOperator;
        node->Lhs = left;
        node->Rhs = ParseMulExpr();
        left = node;
    }
    return left;
}

std::shared_ptr<compiler::AstNode> compiler::Parser::ParseMulExpr() {
    std::shared_ptr<AstNode> left = ParsePrimaryExpr();
    while (lexer.GetCurrentToken()->kind == TokenKind::Mul || lexer.GetCurrentToken()->kind == TokenKind::Div) {
        BinaryOperator binaryOperator = BinaryOperator::Mul;
        if (lexer.GetCurrentToken()->kind == TokenKind::Div){
            binaryOperator = BinaryOperator::Div;
        }
        lexer.GetNextToken();
        auto node = std::make_shared<BinaryNode>();
        node->binaryOperator = binaryOperator;
        node->Lhs = left;
        node->Rhs = ParsePrimaryExpr();
        left = node;
    }
    return left;
}

std::shared_ptr<compiler::AstNode> compiler::Parser::ParsePrimaryExpr() {
    auto node = std::make_shared<ConstantNode>();
    node->value = lexer.GetCurrentToken()->value;
    lexer.GetNextToken();
    return node;
}
