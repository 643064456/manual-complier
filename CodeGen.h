//
// Created by xiaoyu ren on 2022/11/21.
//

#ifndef COMPILER_CODEGEN_H
#define COMPILER_CODEGEN_H
#include "AstNode.h"

namespace compiler {
    class CodeGen : public AstVisitor {
    private:
        int top{0};
        void VisitorBinaryNode(BinaryNode *node) override;
        void VisitorConstantNode(ConstantNode *node) override;
        void Push();
        void Pop(const char *reg);
    public:
        CodeGen(){}
        void VisitorProgramNode(ProgramNode *node) override;
    };
}


#endif //COMPILER_CODEGEN_H
