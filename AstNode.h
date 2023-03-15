//
// Created by xiaoyu ren on 2022/11/21.
//

#ifndef COMPILER_ASTNODE_H
#define COMPILER_ASTNODE_H
#include <memory>

namespace compiler {
    class AstVisitor;

    class AstNode {
    public:
        virtual ~AstNode(){};
        virtual void Accept(AstVisitor *visitor) {};
    };

    class ProgramNode : public AstNode{
    public:
        std::shared_ptr<AstNode> Lhs;
        void Accept(AstVisitor *visitor) override;
    };

    enum class BinaryOperator{
        Add,
        Sub,
        Mul,
        Div
    };

    class BinaryNode : public AstNode{
    public:
        BinaryOperator binaryOperator;
        std::shared_ptr<AstNode> Lhs;
        std::shared_ptr<AstNode> Rhs;
        void Accept(AstVisitor *visitor) override;
    };

    class ConstantNode : public AstNode{
    public:
        int value;
        void Accept(AstVisitor *visitor) override;
    };

    class AstVisitor{
    public:
        virtual void VisitorProgramNode(ProgramNode *node) {};
        virtual void VisitorBinaryNode(BinaryNode *node) {};
        virtual void VisitorConstantNode(ConstantNode *node) {};
    };
}


#endif //COMPILER_ASTNODE_H
