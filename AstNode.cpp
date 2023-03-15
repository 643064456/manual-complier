//
// Created by xiaoyu ren on 2022/11/21.
//

#include "AstNode.h"

void compiler::BinaryNode::Accept(compiler::AstVisitor *visitor) {
    visitor->VisitorBinaryNode(this);
}

void compiler::ConstantNode::Accept(compiler::AstVisitor *visitor) {
    visitor->VisitorConstantNode(this);
}

void compiler::ProgramNode::Accept(compiler::AstVisitor *visitor) {
    visitor->VisitorProgramNode(this);
}
