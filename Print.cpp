//
// Created by xiaoyu ren on 2022/11/22.
//

#include <cassert>
#include "Print.h"

void compiler::Print::VisitorProgramNode(compiler::ProgramNode *node) {
    node->Lhs->Accept(this);
    printf("\n");
}

void compiler::Print::VisitorBinaryNode(compiler::BinaryNode *node) {
    node->Rhs->Accept(this);
    node->Lhs->Accept(this);
    switch (node->binaryOperator) {
        case BinaryOperator::Add:
            printf("+ ");
            break;
        case BinaryOperator::Sub:
            printf("- ");
            break;
        case BinaryOperator::Mul:
            printf("* ");
            break;
        case BinaryOperator::Div:
            printf("/ ");
            break;
        default:
            assert(0);
    }
}

void compiler::Print::VisitorConstantNode(compiler::ConstantNode *node) {
    printf("%d ", node->value);
}
