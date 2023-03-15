//
// Created by xiaoyu ren on 2022/11/21.
//

#include "CodeGen.h"
#include <cassert>

void compiler::CodeGen::VisitorProgramNode(compiler::ProgramNode *node) {
    printf("\t.text\n");
#ifdef __linux__
    printf("\t.global prog\n");
    printf("_prog\n");
#endif
    printf("\tpush %%rbp\n");
    printf("\tmove %%rsp, %%rbp\n");
    printf("\tsub $32, %%rsp\n");

    node->Lhs->Accept(this);
    assert(top == 0);

    printf("\tmove %%rbp, %%rsp\n");
    printf("\tpop %%rbp\n");
    printf("\tret\n");
}

void compiler::CodeGen::VisitorBinaryNode(compiler::BinaryNode *node) {
    node->Rhs->Accept(this);
    Push();
    node->Lhs->Accept(this);
    Pop("%rdi");
    switch (node->binaryOperator) {
        case BinaryOperator::Add:
            printf("\tadd %%rdi, %%rax\n");
            break;
        case BinaryOperator::Sub:
            printf("\tsub %%rdi, %%rax\n");
            break;
        case BinaryOperator::Mul:
            printf("\timul %%rdi, %%rax\n");
            break;
        case BinaryOperator::Div:
            printf("\tcqo\n");
            printf("\tdiv %%rdi\n");
            break;
        default:
            assert(0);
    }
}

void compiler::CodeGen::VisitorConstantNode(compiler::ConstantNode *node) {
    printf("\tmove $%d, %%rax\n", node->value);
}

void compiler::CodeGen::Push() {
    printf("\tpush %%rax\n");
    top++;
}

void compiler::CodeGen::Pop(const char *reg) {
    printf("\tpop %s\n", reg);
    top--;
}
