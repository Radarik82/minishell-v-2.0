#include <stdio.h>
#include <stdlib.h>

// Define AST node types
typedef enum {
	CMD_NODE,
	PIPE_NODE,
	AND_NODE
} NodeType;

// Define AST node structure
typedef struct ASTNode {
	NodeType type;
	char* value;  // For CMD_NODE, this will store the command
	struct ASTNode* left;
	struct ASTNode* right;
} ASTNode;

// Function to create a new command node
ASTNode* createCmdNode(char* cmd) {
	ASTNode* node = (ASTNode*)malloc(sizeof(ASTNode));
	node->type = CMD_NODE;
	node->value = cmd;
	node->left = NULL;
	node->right = NULL;
	return node;
}

// Function to create a new operator node
ASTNode* createOpNode(NodeType type, ASTNode* left, ASTNode* right) {
	ASTNode* node = (ASTNode*)malloc(sizeof(ASTNode));
	node->type = type;
	node->value = NULL;
	node->left = left;
	node->right = right;
	return node;
}

// Function to execute the AST
void executeAST(ASTNode* root) {
	if (root == NULL) {
		return;
	}

	if (root->type == CMD_NODE) {
		// Execute command
		printf("Executing command: %s\n", root->value);
	} else {
		// Execute operator
		executeAST(root->left);

		if (root->type == PIPE_NODE) {
			printf("Executing pipe\n");
		} else if (root->type == AND_NODE) {
			printf("Executing and\n");
		}

		executeAST(root->right);
	}
}

// Function to free the AST
void freeAST(ASTNode* root) {
	if (root == NULL) {
		return;
	}

	freeAST(root->left);
	freeAST(root->right);

	if (root->type == CMD_NODE) {
		free(root->value);
	}

	free(root);
}

int main() {
	// Create a sample AST for the expression: echo a | grep a && ls
	ASTNode* cmd1 = createCmdNode("echo a");
	ASTNode* cmd2 = createCmdNode("grep a");
	ASTNode* cmd3 = createCmdNode("ls");

	ASTNode* pipeNode = createOpNode(PIPE_NODE, cmd1, cmd2);
	ASTNode* andNode = createOpNode(AND_NODE, pipeNode, cmd3);

	// Execute the AST
	executeAST(andNode);

	// Free the AST
	// freeAST(andNode);

	return 0;
}
