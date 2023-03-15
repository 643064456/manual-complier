//
// Created by xiaoyu ren on 2022/11/22.
//

#ifndef COMPILER_PRINT_H
#define COMPILER_PRINT_H
#include "AstNode.h"

namespace compiler {
    class Print : public AstVisitor {
    private:
        void VisitorBinaryNode(BinaryNode *node) override;
        void VisitorConstantNode(ConstantNode *node) override;
    public:
        void VisitorProgramNode(ProgramNode *node) override;
    };
}


#endif //COMPILER_PRINT_H
