#include "ast.h"

// AST Node Definitions

// Base Node
Node::Node(NodeType type) : type_(type) {}

// Statement Node
StatementNode::StatementNode(NodeType type) : Node(type) {}

PrintStatementNode::PrintStatementNode(ExpressionNode* expression) : StatementNode(NodeType::PrintStatement), expression_(expression) {}

void PrintStatementNode::accept(Visitor& visitor) {
    visitor.visit(*this);
}

// Expression Node
ExpressionNode::ExpressionNode(NodeType type) : Node(type) {}

IntegerLiteralNode::IntegerLiteralNode(int value) : ExpressionNode(NodeType::IntegerLiteral), value_(value) {}

void IntegerLiteralNode::accept(Visitor& visitor) {
    visitor.visit(*this);
}

// Visitor Base Class
Visitor::Visitor() {}

void Visitor::visit(PrintStatementNode& node) {
    // Override this method in subclasses to handle the PrintStatementNode
}

void Visitor::visit(IntegerLiteralNode& node) {
    // Override this method in subclasses to handle the IntegerLiteralNode
}
