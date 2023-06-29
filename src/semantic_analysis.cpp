#include "semantic_analysis.h"

SemanticAnalyzer::SemanticAnalyzer() {}

void SemanticAnalyzer::analyze(Node& rootNode) {
    rootNode.accept(*this);
}

void SemanticAnalyzer::visit(PrintStatementNode& node) {
    // Perform semantic analysis for the PrintStatementNode
    // Example: Check if the expression is valid, perform type checking, symbol table management, etc.
    node.expression_->accept(*this);
}

void SemanticAnalyzer::visit(IntegerLiteralNode& node) {
    // Perform semantic analysis for the IntegerLiteralNode
    // Here, we print the value of the integer literal for demonstration purposes
    std::cout << "Integer Literal Value: " << node.value_ << std::endl;
}
