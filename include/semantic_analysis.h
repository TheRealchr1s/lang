#ifndef SEMANTIC_ANALYSIS_H
#define SEMANTIC_ANALYSIS_H

#include "ast.h"

class SemanticAnalyzer : public Visitor {
public:
    SemanticAnalyzer();

    void analyze(Node& rootNode);

    void visit(PrintStatementNode& node);
    void visit(IntegerLiteralNode& node);
};

#endif  // SEMANTIC_ANALYSIS_H
