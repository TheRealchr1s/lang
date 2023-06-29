#ifndef AST_H
#define AST_H

#include <iostream>
#include <string>

enum class NodeType {
    // todo
};

class Node {
public:
    Node(NodeType type);

    virtual void accept(class Visitor& visitor) = 0;

    NodeType type_;
};

class StatementNode : public Node {
public:
    StatementNode(NodeType type);
};

class PrintStatementNode : public StatementNode {
public:
    PrintStatementNode(class ExpressionNode* expression);

    void accept(Visitor& visitor);

    class ExpressionNode* expression_;
};

class ExpressionNode : public Node {
public:
    ExpressionNode(NodeType type);
};

class IntegerLiteralNode : public ExpressionNode {
public:
    IntegerLiteralNode(int value);

    void accept(Visitor& visitor);

    int value_;
};

class Visitor {
public:
    Visitor();

    virtual void visit(class PrintStatementNode& node);
    virtual void visit(class IntegerLiteralNode& node);
};

#endif  // AST_H
